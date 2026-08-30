/*
=======================================================================
 THEORY : Pattern Printing - Spaces + Reduced Rows
=======================================================================
 Many patterns are made by combining "spaces" and "characters":
    - print some spaces first (to push the row right)
    - then print the characters (n - i of them)

 PATTERN 12 (Decreasing bricks shifted right):
    for i in 0..n-1
        print i spaces
        print (n - i) copies of (i + 1)
    Row i: i leading spaces, then the digit i+1 repeated n-i times.

 EXPECTED OUTPUT (n = 4):
    1111
     222
      33
       4

 Related pattern for interviews: same logic but with the characters
 in a triangle instead of a square of digits.
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < n - i; k++)
        {
            cout << i + 1;
        }
        cout << endl;
    }

    return 0;
}