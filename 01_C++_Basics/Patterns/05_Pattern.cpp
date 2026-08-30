/*
=======================================================================
 THEORY : Pattern Printing - Triangle with Row Number
=======================================================================
 Key idea for TRIANGLES: the inner loop runs only `i+1` times, so
 row i prints i+1 items. When printing, we use the OUTER variable i.

 PATTERN 05 (Right-angle triangle of row numbers):
    for i in 0..n-1        (rows)
        for j in 0..i      (cols): print (i + 1)
    Row 0 prints 1 once; row 4 prints 5 five times.

 EXPECTED OUTPUT:
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}