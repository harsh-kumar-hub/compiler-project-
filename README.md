# MiniC Language and Interpreter

MiniC is a simple programming language that supports basic programming constructs and features. This interpreter allows you to write and execute MiniC programs.

## Building the Interpreter

```bash
make clean && make
```

## Running Programs

You can run MiniC programs in two modes:

1. File mode:
```bash
./minic program.mc
```

2. Interactive mode:
```bash
./minic
```

## Language Features

### 1. Data Types
- `int`: Integer numbers
- `string`: Text strings
- `bool`: Boolean values (true/false)
- Arrays of int and string

### 2. Variables
```c
int x;              // Declaration
x = 42;             // Assignment
int y = 10;         // Declaration with initialization
```

### 3. Arrays
```c
int numbers[5];     // Array declaration
numbers[0] = 1;     // Array assignment
string words[3];
```

### 4. Arithmetic Operations
- Addition: `+`
- Subtraction: `-`
- Multiplication: `*`
- Division: `/`
- Modulo: `%`

### 5. Compound Assignments
- `+=`: Add and assign
- `-=`: Subtract and assign
- `*=`: Multiply and assign
- `/=`: Divide and assign
- `%=`: Modulo and assign

### 6. Increment/Decrement
- `++x`: Pre-increment
- `--x`: Pre-decrement

### 7. Boolean Operations
- AND: `&&`
- OR: `||`
- NOT: `!`

### 8. Comparison Operations
- Equal: `==`
- Not equal: `!=`
- Less than: `<`
- Greater than: `>`
- Less than or equal: `<=`
- Greater than or equal: `>=`

### 9. Control Structures

#### If-Else
```c
if (condition) {
    // code
} else {
    // code
}
```

#### While Loop
```c
while (condition) {
    // code
}
```

#### Do-While Loop
```c
do {
    // code
} while (condition);
```

#### For Loop
```c
for (init; condition; update) {
    // code
}
```

#### Switch-Case
```c
switch (expression) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // code
}
```

### 10. Functions
```c
int add(int a, int b) {
    return a + b;
}

void printArray(int arr[]) {
    // code
}

string greet(string name) {
    return "Hello, " + name;
}
```

### 11. Input/Output
```c
print expression;   // Output
read variable;      // Input
```

### 12. Comments
```c
// Single line comment
```

## Example Program

See `examples.mc` for a comprehensive example demonstrating all language features.

## Limitations

1. Arrays must have fixed size at declaration
2. No multi-dimensional arrays
3. No string array operations (concatenation, etc.)
4. Case values in switch statements must be integers
5. No global variables
6. No pointer types
7. No structs or complex data types
8. No floating-point numbers 