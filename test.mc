int main() {
// Comprehensive MiniC Test Program
// 1. Basic variable declarations and assignments
int x;
int y;
string message;
bool flag;
x = 10;
y = 5;
message = "Hello, MiniC!";
flag = true;
print "\n=== Basic Variables ===\n";
print x;
print y;
print message;
print flag;
print "";

// 2. Arithmetic and compound assignments
x += 5;
y *= 2;
x -= 3;
y /= 2;
print "\n=== Arithmetic & Compound Assignments ===\n";
print x;
print y;
print "";

// 3. Boolean operations
bool a;
bool b;
a = true;
b = false;
print "\n=== Boolean Operations ===\n";
if (x > 10 && y == 5) {
    print "x > 10 AND y == 5 is true";
}
if (x < 20 || y > 20) {
    print "x < 20 OR y > 20 is true";
}
if (!(x == y)) {
    print "x is not equal to y";
}
print "";

// 4. Arrays
int numbers[5];
string words[3];
numbers[0] = 100;
numbers[1] = 200;
numbers[2] = 300;
numbers[3] = 400;
numbers[4] = 500;
words[0] = "First";
words[1] = "Second";
words[2] = "Third";
print "\n=== Array Elements ===\n";
print numbers[0];
print numbers[1];
print numbers[2];
print numbers[3];
print numbers[4];
print words[0];
print words[1];
print words[2];
print "";

// 5. Array arithmetic and update
int sum;
sum = numbers[0] + numbers[1];
print "Sum of first two numbers:";
print sum;
numbers[4] = numbers[4] + 100;
print "Updated last number:";
print numbers[4];
words[1] = "Updated";
print "Updated second word:";
print words[1];
print "";

// 6. Control structures
print "\n=== While Loop ===\n";
int counter;
counter = 3;
while (counter > 0) {
    print counter;
    counter -= 1;
}
print "\n=== For Loop ===\n";
int i;
for (i = 0; i < 3; i += 1) {
    print words[i];
}
print "\n=== Do-While Loop ===\n";
int j;
j = 0;
do {
    print numbers[j];
    j += 1;
} while (j < 5);
print "";

// 7. If-Else
print "\n=== If-Else ===\n";
if (counter == 0 && x > y) {
    print "Counter is zero and x > y";
} else {
    print "Condition not met";
}
print "";

// 8. Switch-Case with break
print "\n=== Switch-Case ===\n";
int choice;
choice = 2;
switch (choice) {
    case 1:
        print "One";
        break;
    case 2:
        print "Two";
        break;
    case 3:
        print "Three";
        break;
    default:
        print "Other";
}
print "";

// 9. Input/Output
print "\n=== Input/Output ===\n";
print "Enter a number:";
int input_num;
read input_num;
print "You entered:";
print input_num;
print "Enter your name:";
string input_str;
read input_str;
print "Hello, ";
print input_str;
print "";

