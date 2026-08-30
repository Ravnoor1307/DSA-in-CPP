/*
=======================================================================
 THEORY : Binary Number System & Conversions
=======================================================================
 Computers store everything as 0s and 1s (binary). Understanding
 binary is essential for bit-manipulation problems used in DSA.

 1. DECIMAL -> BINARY  (divide by 2, collect remainders)
    - Repeatedly divide the number by 2.
    - Record the remainder (0 or 1) at each step.
    - Reading remainders in order (last remainder first) gives the
      binary equivalent.

    Eg: 10 (decimal)
        10 / 2 = 5, rem 0
         5 / 2 = 2, rem 1
         2 / 2 = 1, rem 0
         1 / 2 = 0, rem 1
        -> reading upwards: 1010   So 10 = (1010)base2

    Implementation trick (decimal_to_binary):
        ans = 0; pow = 1;
        while (n != 0) {
            rem = n % 2;  n = n / 2;
            ans += rem * pow;   pow *= 10;   // builds digits as int
        }
        Eg: 10 -> ans = 1010 (as an integer)

 2. BINARY -> DECIMAL  (multiply by 2, add)
    - Take each digit from the RIGHT end (units place first).
    - Multiply it by increasing powers of 2: 2^0, 2^1, 2^2 ...
    - Sum everything.

    Eg: (1010)base2
        0*2^0 + 1*2^1 + 0*2^2 + 1*2^3 = 0 + 2 + 0 + 8 = 10

    Implementation trick (binary_to_decimal):
        ans = 0; pow = 1;      // 1 = 2^0
        while (n != 0) {
            rem = n % 10;  n = n / 10;      // takes one digit out
            ans += rem * pow;  pow *= 2;
        }

 3. Why both functions store the result as int?
    - Only for demonstration/printing simplicity; the real binary
      form on a computer uses individual bits in memory.
=======================================================================
*/
#include <iostream>
using namespace std;

// Decimal to Binary
int decimal_to_binary(int n)
{
    int pow = 1; // 10^0 -> 10^1 -> 10^2 ...
    int ans = 0;
    while (n != 0)
    {
        int remainder = n % 2;
        n /= 2;
        ans += (remainder * pow);
        pow *= 10;
    }
    return ans;
}

// Binary to Decimal
int binary_to_decimal(int n)
{
    int pow = 1; // 2^0 -> 2^1 -> 2^2 ...
    int ans = 0;
    while (n != 0)
    {
        int remainder = n % 10;
        n /= 10;
        ans += (remainder * pow);
        pow *= 2;
    }
    return ans;
}

int main()
{

    // Decimal to Binary
    int a = 10;
    cout << "Binary Representation of " << a << " is : " << decimal_to_binary(a);

    cout << endl
         << endl
         << endl;
    for (int i = 0; i <= a; i++)
    {
        cout << "Binary Representation of " << i << " is : " << decimal_to_binary(i) << endl;
    }

    // Binary to Decimal
    int b = 101010;
    cout << endl
         << endl
         << "Decimal Representation of " << b << " is : " << binary_to_decimal(b) << endl;

    return 0;
}