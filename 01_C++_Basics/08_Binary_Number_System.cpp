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