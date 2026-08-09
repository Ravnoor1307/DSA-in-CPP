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