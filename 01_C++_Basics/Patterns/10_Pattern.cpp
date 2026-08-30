/*
=======================================================================
 THEORY : Pattern Printing - Sequential Alphabet Triangle
=======================================================================
 A char counter (alpha) that increments after every print produces a
 continuously flowing alphabet triangle.

 PATTERN 10 (Alphabet triangle, sequential):
    alpha = 'A';
    for i in 'A' .. 'Z'-1              (25 rows)
        for j in 'A' .. i : print alpha; alpha++
    NOTE: loop condition is i < n (n = 'Z'), so 25 rows are printed.
    Each row i prints one letter more than the previous row:

 EXPECTED OUTPUT (first few rows):
    A
    B C
    D E F
    G H I J
    K L M N O
    ...
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    char n = 'Z';
    char alpha = 'A';
    for (char i = 'A'; i < n; i++)
    {
        for (char j = 'A'; j < i + 1; j++)
        {
            cout << alpha << " ";
            alpha += 1;
        }
        cout << endl;
    }

    return 0;
}