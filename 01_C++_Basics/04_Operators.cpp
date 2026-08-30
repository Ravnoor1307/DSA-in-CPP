/*
=======================================================================
 THEORY : Operators in C++
=======================================================================
 OPERATORS are symbols that perform operations on operands (values).

 1. ARITHMETIC OPERATORS  ( +  -  *  /  % )
    - a + b : addition
    - a - b : subtraction
    - a * b : multiplication
    - a / b : division
        * Integer/Integer  -> integer division (fraction dropped)
        * Eg: 8 / 3 = 2        (not 2.66)
    - a % b : modulo (remainder). Eg: 8 % 3 = 2
    - ++a / a++ : increment by 1 (pre/post)
    - --a / a-- : decrement by 1 (pre/post)
         Pre  (++a) -> increment first, then use the value
         Post (a++) -> use the value first, then increment

 2. RELATIONAL (Comparison) OPERATORS
    - == equal, != not equal, > greater, < lesser,
      >= greater-or-equal, <= lesser-or-equal
    - Result is always a bool: 1 (true) or 0 (false).

 3. LOGICAL OPERATORS
    - &&  AND : true only if BOTH operands are true
    - ||  OR  : true if AT LEAST ONE operand is true
    - !   NOT : flips true<->false
    - Note: any non-zero value is treated as true.

 4. BITWISE OPERATORS (work bit by bit on binary representation)
    - &  AND   : 1 only if both bits are 1
    - |  OR    : 1 if either bit is 1
    - ^  XOR   : 1 if bits differ
    - << left shift  : multiply by 2 each shift
                       a << 1  = a * 2
    - >> right shift : divide by 2 each shift
                       a >> 1  = a / 2
    - ~  one's complement : flips every bit
           Eg: ~5 = -(5+1) = -6

 EXAMPLE  (a=8=1000, b=3=0011):
    a & b = 0000 = 0
    a | b = 1011 = 11
    a ^ b = 1011 = 11
    a << 1 = 16 ;  a >> 1 = 4
=======================================================================
*/
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