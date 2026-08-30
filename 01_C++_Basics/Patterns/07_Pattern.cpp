/*
=======================================================================
 THEORY : Pattern Printing - Reversed Inner Loop
=======================================================================
 We can run the INNER loop DOWNWARDS to get decreasing sequences.
    for (int j = i+1; j > 0; j--)   prints i+1, i, ..., 1

 PATTERN 07 (Triangle with numbers counting down):
    for i in 0..n-1
        for j in (i+1) down to 1 : print j

 EXPECTED OUTPUT:
    1
    2 1
    3 2 1
    4 3 2 1
    5 4 3 2 1
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}