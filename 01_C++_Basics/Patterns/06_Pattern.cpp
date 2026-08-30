/*
=======================================================================
 THEORY : Pattern Printing - Triangle with Column Number
=======================================================================
 PATTERN 06 (Right-angle triangle of column numbers):
    for i in 0..n-1        (rows)
        for j in 0..i      (cols): print (j + 1)
    Row i prints: 1 2 3 ... i+1   (the value depends on inner var j)

 EXPECTED OUTPUT:
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5

 Compare with file 05:
    - 05 printed i+1 (same value every column of a row)
    - 06 prints j+1 (increasing inside each row)
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
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}