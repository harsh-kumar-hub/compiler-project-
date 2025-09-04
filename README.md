MiniC Language and Interpreter
MiniC is a simple programming language that supports basic programming constructs and features. This interpreter allows you to write and execute MiniC programs.

Building the Interpreter
make clean && make
Running Programs
You can run MiniC programs in two modes:

File mode:
./minic program.mc
Interactive mode:
./minic
Language Features
1. Data Types
int: Integer numbers
string: Text strings
bool: Boolean values (true/false)
Arrays of int and string
2. Variables
int x;              // Declaration
x = 42;             // Assignment
int y = 10;         // Declaration with initialization
3. Arrays
int numbers[5];     // Array declaration
numbers[0] = 1;     // Array assignment
string words[3];
4. Arithmetic Operations
Addition: +
Subtraction: -
Multiplication: *
Division: /
Modulo: %
5. Compound Assignments
+=: Add and assign
-=: Subtract and assign
*=: Multiply and assign
/=: Divide and assign
%=: Modulo and assign
6. Increment/Decrement
++x: Pre-increment
--x: Pre-decrement
7. Boolean Operations
AND: &&
OR: ||
NOT: !
8. Comparison Operations
Equal: ==
Not equal: !=
Less than: <
Greater than: >
Less than or equal: <=
Greater than or equal: >=
9. Control Structures
If-Else
if (condition) {
    // code
} else {
    // code
}
While Loop
while (condition) {
    // code
}
Do-While Loop
do {
    // code
} while (condition);
For Loop
for (init; condition; update) {
    // code
}
Switch-Case
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
10. Functions
int add(int a, int b) {
    return a + b;
}

void printArray(int arr[]) {
    // code
}

string greet(string name) {
    return "Hello, " + name;
}
11. Input/Output
print expression;   // Output
read variable;      // Input
12. Comments
// Single line comment
Example Program
See examples.mc for a comprehensive example demonstrating all language features.

Limitations
Arrays must have fixed size at declaration
No multi-dimensional arrays
No string array operations (concatenation, etc.)
Case values in switch statements must be integers
No global variables
No pointer types
No structs or complex data types
No floating-point numbers
