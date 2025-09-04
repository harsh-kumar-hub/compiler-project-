from flask import Flask, request, jsonify, send_from_directory, session
import subprocess
import os
import uuid
import threading
import queue
from typing import Optional
from pathlib import Path

app = Flask(__name__, static_folder='static')
app.secret_key = 'minic_secret_key'  # Needed for session

MINIC_EXEC = './minic'  # Path to your MiniC interpreter
UPLOAD_FOLDER = 'uploads'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

# Store running processes and queues per session
processes = {}

@app.route('/')
def index():
    if app.static_folder is None:
        return "Static folder not configured", 500
    return send_from_directory(app.static_folder, 'index.html')

@app.route('/run', methods=['POST'])
def run_code():
    if not request.is_json:
        return jsonify({'output': 'Invalid request format'}), 400
    
    code = request.json.get('code', '') if request.json else ''
    if not code:
        return jsonify({'output': 'No code provided.'})
    
    # Save code to a temp file
    filename = f'{UPLOAD_FOLDER}/temp_{uuid.uuid4().hex}.mc'
    with open(filename, 'w') as f:
        f.write(code)
    
    try:
        # Start the interpreter process
        proc = subprocess.Popen([MINIC_EXEC, filename], 
                              stdin=subprocess.PIPE, 
                              stdout=subprocess.PIPE, 
                              stderr=subprocess.PIPE, 
                              text=True, 
                              bufsize=1)
        
        if proc.stdout is None or proc.stderr is None or proc.stdin is None:
            raise Exception("Failed to create process pipes")

        q = queue.Queue()
        session_id = str(uuid.uuid4())
        session['minic_session'] = session_id
        processes[session_id] = {'proc': proc, 'queue': q, 'filename': filename, 'output': '', 'waiting_input': False}

        def read_output():
            if proc.stdout is None:
                return
                
            while True:
                try:
                    line = proc.stdout.readline()
                    if line == '' and proc.poll() is not None:
                        break
                    if line:
                        q.put(line)
                        # Detect if waiting for input
                        if line.strip().endswith('INPUT:') or line.strip().endswith('Enter a number:') or line.strip().endswith('Enter your name:'):
                            processes[session_id]['waiting_input'] = True
                            break
                except Exception as e:
                    q.put(f"Error reading output: {str(e)}")
                    break
                    
            # Also read stderr
            if proc.stderr is not None:
                try:
                    err = proc.stderr.read()
                    if err:
                        q.put(err)
                except Exception as e:
                    q.put(f"Error reading stderr: {str(e)}")

        threading.Thread(target=read_output, daemon=True).start()
        # Wait for some output or input prompt
        import time
        time.sleep(0.2)
        output = ''
        while not q.empty():
            output += q.get()
        processes[session_id]['output'] += output
        
        # If waiting for input, tell frontend
        if processes[session_id]['waiting_input']:
            return jsonify({'output': output, 'input_required': True})
        
        # If process finished
        if proc.poll() is not None:
            os.remove(filename)
            del processes[session_id]
            return jsonify({'output': output, 'done': True})
        
        return jsonify({'output': output, 'input_required': False})
    
    except Exception as e:
        if os.path.exists(filename):
            os.remove(filename)
        return jsonify({'output': f'Error: {str(e)}'}), 500

@app.route('/input', methods=['POST'])
def send_input():
    if not request.is_json:
        return jsonify({'output': 'Invalid request format', 'done': True}), 400
    
    user_input = request.json.get('input', '') if request.json else ''
    session_id = session.get('minic_session')
    
    if not session_id or session_id not in processes:
        return jsonify({'output': 'No running process.', 'done': True})
    
    proc_info = processes[session_id]
    proc = proc_info['proc']
    q = proc_info['queue']
    
    try:
        if proc.stdin:
            proc.stdin.write(user_input + '\n')
            proc.stdin.flush()
    except Exception as e:
        return jsonify({'output': f'Error sending input: {e}', 'done': True})
    
    proc_info['waiting_input'] = False
    
    def read_output():
        if proc.stdout is None or proc.stderr is None:
            return
            
        while True:
            line = proc.stdout.readline()
            if line == '' and proc.poll() is not None:
                break
            if line:
                q.put(line)
                if line.strip().endswith('INPUT:') or line.strip().endswith('Enter a number:') or line.strip().endswith('Enter your name:'):
                    proc_info['waiting_input'] = True
                    break
        err = proc.stderr.read()
        if err:
            q.put(err)
            
    threading.Thread(target=read_output, daemon=True).start()
    import time
    time.sleep(0.2)
    output = ''
    while not q.empty():
        output += q.get()
    proc_info['output'] += output
    
    if proc_info['waiting_input']:
        return jsonify({'output': output, 'input_required': True})
    
    if proc.poll() is not None:
        os.remove(proc_info['filename'])
        del processes[session_id]
        return jsonify({'output': output, 'done': True})
    
    return jsonify({'output': output, 'input_required': False})

@app.route('/save', methods=['POST'])
def save_code():
    if not request.is_json:
        return jsonify({'message': 'Invalid request format'}), 400
    
    code = request.json.get('code', '') if request.json else ''
    filename = request.json.get('filename', 'code.mc') if request.json else 'code.mc'
    
    try:
        filepath = os.path.join(UPLOAD_FOLDER, filename)
        with open(filepath, 'w') as f:
            f.write(code)
        return jsonify({'message': f'Saved as {filename}'})
    except Exception as e:
        return jsonify({'message': f'Error saving file: {str(e)}'}), 500

@app.route('/load', methods=['GET'])
def load_code():
    filename = request.args.get('filename', 'code.mc')
    filepath = os.path.join(UPLOAD_FOLDER, filename)
    
    try:
        if not os.path.exists(filepath):
            return jsonify({'code': '', 'message': 'File not found.'})
        with open(filepath, 'r') as f:
            code = f.read()
        return jsonify({'code': code, 'message': f'Loaded {filename}'})
    except Exception as e:
        return jsonify({'code': '', 'message': f'Error loading file: {str(e)}'}), 500

@app.route('/files', methods=['GET'])
def list_files():
    try:
        files = [f for f in os.listdir(UPLOAD_FOLDER) if os.path.isfile(os.path.join(UPLOAD_FOLDER, f))]
        return jsonify({'files': files})
    except Exception as e:
        return jsonify({'files': [], 'message': f'Error listing files: {str(e)}'}), 500

@app.route('/static/<path:path>')
def send_static(path):
    if app.static_folder is None:
        return "Static folder not configured", 500
    return send_from_directory(app.static_folder, path)

if __name__ == '__main__':
    app.run(debug=True) 