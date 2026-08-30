/*
=======================================================================
 THEORY : Pattern Printing - Continuous Counter
=======================================================================
 Use a counter variable (num) OUTSIDE the inner loop so it keeps
 increasing across the whole grid instead of resetting each row.

 PATTERN 04 (Numbers 1..25 row-major):
    num = 1;
    for i in 1..n            (rows)
        for j in 1..n        (cols): print num; num++
    Since n = 5, a 5x5 grid fills numbers 1 to 25.

 EXPECTED OUTPUT:
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25

 This "row-major" ordering is exactly how 2-D arrays are stored!
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 5;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}