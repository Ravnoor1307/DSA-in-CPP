/*
=======================================================================
 THEORY : Pattern Printing - Characters as Loop Variables
=======================================================================
 In C++, a char is a small integer. So we can use characters inside
 loops just like numbers, and ++ moves to the next alphabet letter.

 PATTERN 03 (Alphabet square):
    n = 'Z';  i from 'A' to 'Z'   (26 rows)
        j from 'A' to 'Z'        : print j  (same columns each row)

 What it prints with n='F' (for a small example):
    A B C D E F
    A B C D E F
    A B C D E F
    A B C D E F
    A B C D E F
    A B C D E F

 The file uses n = 'Z', so it prints 26 such rows (A..Z each row).
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    char n = 'Z';
    for (char i = 'A'; i <= n; i++)
    {
        for (char j = 'A'; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}