/*
=======================================================================
 THEORY : Pattern Printing using Nested Loops
=======================================================================
 All pattern problems use the same mental model:
   - OUTER loop  = number of ROWS
   - INNER loop  = number of COLUMNS printed in each row
   - The value you print comes from the loop variables i and j.

 General recipe:
 1) Decide the number of rows      -> outer loop.
 2) Decide the number of columns   -> inner loop.
 3) Decide WHICH value to print    -> i, j, or a counter.
 4) Move to the next line with cout << endl after the inner loop.

 PATTERN 01 (Square of numbers by column):
    for i in 1..n (rows)
        for j in 1..n (cols):  print j
    Every row is identical: 1 2 3 4 5
    Here n = 5.

 EXPECTED OUTPUT:
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}