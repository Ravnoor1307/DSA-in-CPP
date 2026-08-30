/*
=======================================================================
 THEORY : Pattern Printing - Number Pyramid
=======================================================================
 A PYRAMID needs three parts per row:
    1) leading spaces  (n - i - 1 of them)  -> centres the row
    2) increasing numbers  1 .. i+1
    3) decreasing numbers  i .. 1           (second half)

 PATTERN 13 (Pyramid of numbers):
    for i in 0..n-1
        print (n-i-1) sets of two spaces
        for k in 0..i   : print (k + 1)      // left half
        for l in 0..i-1 : print (l + 1)      // right half
    Row i is symmetric: 1 2 ... i+1 ... 2 1

 EXPECTED OUTPUT (n = 4):
       1
      1 2 1
     1 2 3 2 1
    1 2 3 4 3 2 1
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << k + 1 << " ";
        }
        for (int l = 0; l < i; l++)
        {
            cout << l + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}