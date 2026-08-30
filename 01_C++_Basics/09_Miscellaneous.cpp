/*
=======================================================================
 THEORY : Miscellaneous - Bitwise Operators & Data Modifiers
=======================================================================
 1. BITWISE OPERATORS (again, practical examples)
    - a & b  : bitwise AND  -> bit is 1 only if both bits are 1
    - a | b  : bitwise OR   -> bit is 1 if either bit is 1
    - a ^ b  : bitwise XOR  -> bit is 1 if the two bits differ
    - a << 1 : left shift   -> shifts bits left, multiplies by 2
    - a >> 1 : right shift  -> shifts bits right, divides by 2

    Eg: a=4 (0100), b=8 (1000)
        a & b = 0000 = 0
        a | b = 1100 = 12
        a ^ b = 1100 = 12
        a << 1 = 1000 = 8
        a >> 1 = 0010 = 2

 2. DATA TYPE MODIFIERS change the size/range of a data type.
        int            -> 4 bytes
        long int       -> 4/8 bytes (>= int)
        short int      -> 2 bytes
        long long int  -> 8 bytes
        signed         -> can store negative and positive
        unsigned       -> ONLY non-negative (0 to 2^n - 1)
        sizeof() prints the size in bytes.

 3. UNSIGNED WRAP-AROUND
    - Assigning a negative value to an unsigned type does NOT error.
    - Value is converted using modulo (2^n) arithmetic.
        unsigned int c = -10;   // 32-bit unsigned int
        c = 2^32 - 10 = 4294967286
    - This is defined by the C++ standard, but such implicit
      conversions can silently wrap around and cause bugs.
    - Always pick the correct type when handling non-negative data.

 4. sizeof is an operator at compile time, not a runtime function.
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

     int a = 4;
     int b = 8;

     // Bitwise Operators

     cout << "Bitwise & of " << a << " and " << b << " : " << (a & b) << endl;
     cout << "Bitwise | of " << a << " and " << b << " : " << (a | b) << endl;
     cout << "Bitwise ^ of " << a << " and " << b << " : " << (a ^ b) << endl;
     cout << "Bitwise << of  (a<<1)" << " : " << (a << 1) << endl;
     cout << "Bitwise >> of  (a>>1)" << " : " << (a >> 1) << endl;

     // Data Modifiers
     cout << endl
          << sizeof(int) << endl;
     cout << endl
          << sizeof(long int) << endl;
     cout << endl
          << sizeof(short int) << endl;
     cout << endl
          << sizeof(long long int) << endl;

     unsigned int c = -10;
     cout << endl
          << c << endl;

     // NOTE:
     // Assigning a negative value to an unsigned type in C++ does not store a negative number.
     // Instead, the value is converted using modulo 2^n arithmetic, where n is the number of bits.
     // For a 32-bit unsigned int:
     //   -10 becomes: 2^32 - 10 = 4294967286
     // This is defined by the C++ standard (integer conversion rules) and is not an error.
     // Be careful: such implicit conversions can cause unexpected wrap-around results.

     return 0;
}