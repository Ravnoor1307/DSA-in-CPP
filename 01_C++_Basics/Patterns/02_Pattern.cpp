/*
=======================================================================
 THEORY : Pattern Printing using Nested Loops
=======================================================================
 Recipe:
 1) OUTER loop -> rows
 2) INNER loop -> columns in each row
 3) print the chosen character
 4) endl after inner loop

 PATTERN 02 (5 x 5 star rectangle):
    for i in 1..5            (rows)
        for j in 1..5        (cols): print " * "
    Note: the value printed is independent of i and j, so every row
    looks the same.

 EXPECTED OUTPUT:
     *  *  *  *  *
     *  *  *  *  *
     *  *  *  *  *
     *  *  *  *  *
     *  *  *  *  *
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
            cout << " * ";
        }
        cout << endl;
    }

    return 0;
}