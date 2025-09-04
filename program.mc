// Comprehensive MiniC Test Program
int main() {
    print "=== MiniC Feature Demo ===";
    print("");
    // 1. Basic variable declarations and assignments
    int x;
    int y;
    string message;
    
    x = 10;
    y = 5;
    message = "Hello, MiniC!";
    
    print "Initial values:";
    print message;
    print "x =";print x;
    print "y =";print y;
    
    print("");
    // 2. Compound assignments
    x += 5;    // x = 15
    y *= 2;    // y = 10
    print("");
    print "After compound assignments:";
    print "x += 5:";
    print x;
    print "y *= 2:";
    print y;
    print("");
    
    // 3. Boolean operations
    print "=== Boolean Operations ===";
    if (x > 10 && y == 10) {
        print "x > 10 AND y == 10 is true";
    }
    
    if (x < 20 || y > 20) {
        print "x < 20 OR y > 20 is true";
    }
    
    if (!(x == y)) {
        print "x is not equal to y";
    }
    print("");
    // 4. Array operations
    print "=== Array Operations ===";
    int numbers[5];
    string words[3];
    print("");
    // Initialize arrays
    numbers[0] = 100;
    numbers[1] = 200;
    numbers[2] = 300;
    numbers[3] = 400;
    numbers[4] = 500;
    
    words[0] = "First";
    words[1] = "Second";
    words[2] = "Third";
    
    print "Numbers array elements:";
    print numbers[0];
    print numbers[1];
    print numbers[2];
    print numbers[3];
    print numbers[4];
    
    print "Words array elements:";
    print words[0];
    print words[1];
    print words[2];
    print("");
    // Array with expressions
    int i;
    i = 2;
    print "Using variable as index:";
    print "numbers[i] where i = 2:";
    print numbers[i];
    print("");
    // Array arithmetic
    int sum;
    sum = numbers[0] + numbers[1];
    print "Sum of first two numbers:";
    print sum;
    print("");
    // Update array elements
    numbers[4] = numbers[4] + 100;
    print "Updated last number:";
    print numbers[4];
    
    words[1] = "Updated";
    print "Updated second word:";
    print words[1];
    print("");
    // 5. Control structures
    print "=== Control Structures ===";
    print "While loop counting down from 5:";
    int counter;
    counter = 5;
    while (counter > 0) {
        print counter;
        counter -= 1;
    }
    
    print "If-else with boolean operations:";
    if (counter == 0 && x > y) {
        print "Counter is zero and x > y";
    } else {
        print "Condition not met";
    }
    print("");
    // 6. String operations
    print "=== String Operations ===";
    string str1;
    string str2;
    str1 = "Hello";
    str2 = "World";
    print str1;
    print str2;
    print("");
    // 7. Input/Output
    print "=== Input/Output ===";
    print "Enter a number:";
    int input_num;
    read input_num;
    print "You entered:";
    print input_num;
    
    print "Enter your name:";
    string input_str;
    read input_str;
    print "Hello,";
    print input_str;
    
    return 0;
} 
