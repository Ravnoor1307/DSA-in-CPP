#include <iostream>
using namespace std;

int main()
{

    // Arithemetic Operrators

    int a = 8, b = 3;

    // Addition
    cout << "a + b = " << (a + b) << endl;

    // Subtraction
    cout << "a - b = " << (a - b) << endl;

    // Multiplication
    cout << "a * b = " << (a * b) << endl;

    // Division
    cout << "a / b = " << (a / b) << endl;

    // Modulo
    cout << "a % b = " << (a % b) << endl;

    // Increament
    cout << "++a = " << ++a << endl;

    // Decrement
    cout << "b-- = " << b--;

    // Relational Operators

    // Equal operator
    cout << "a == b is " << (a == b) << endl;

    // Greater than operator
    cout << "a > b is " << (a > b) << endl;

    // Greater than Equal to operator
    cout << "a >= b is " << (a >= b) << endl;

    //  Lesser than operator
    cout << "a < b is " << (a < b) << endl;

    // Lesser than Equal to operator
    cout << "a <= b is " << (a <= b) << endl;

    // Not equal to operator
    cout << "a != b is " << (a != b);

    // Comarison Operators

    int a1 = 6, b1 = 4;

    // Logical AND operator
    cout << "a && b is " << (a1 && b1) << endl;

    // Logical OR operator
    cout << "a || b is " << (a1 || b1) << endl;

    // Logical NOT operator
    cout << "!b is " << (!b1);

    // Bitwise Operator

    // Binary AND operator
    cout << "a & b is " << (a & b) << endl;

    // Binary OR operator
    cout << "a | b is " << (a | b) << endl;

    // Binary XOR operator
    cout << "a ^ b is " << (a ^ b) << endl;

    // Left Shift operator
    cout << "a << 1 is " << (a << 1) << endl;

    // Right Shift operator
    cout << "a >> 1 is " << (a >> 1) << endl;

    // One’s Complement operator
    cout << "~(a) is " << ~(a);

    return 0;
}