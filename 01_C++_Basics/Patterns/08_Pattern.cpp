/*
=======================================================================
 THEORY : Pattern Printing - Triangle with Global Counter
=======================================================================
 A counter declared OUTSIDE both loops counts every printed number
 across the whole triangle (does not reset per row).

 PATTERN 08 (Triangle filling numbers 1..15):
    num = 1;
    for i in 0..n-1
        for j in 0..i : print num; num += 1;
    Row i prints i+1 numbers, so total printed = 1+2+3+4+5 = 15.

 EXPECTED OUTPUT:
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int n = 5;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << num << " ";
            num += 1;
        }
        cout << endl;
    }

    return 0;
}