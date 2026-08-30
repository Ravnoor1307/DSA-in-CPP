/*
=======================================================================
 THEORY : Pattern Printing - Classic Star Triangle
=======================================================================
 PATTERN 09 (Right-angle star triangle):
    for i in 0..n-1
        for j in 0..i : print "*"
    Row i has i+1 stars. This is the most common starter pattern.

 EXPECTED OUTPUT:
    *
    * *
    * * *
    * * * *
    * * * * *

 On the "longest" row there are n stars; complexity of printing is
 O(n^2) because total prints = n*(n+1)/2.
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
            cout << "*" << " ";
        }
        cout << endl;
    }

    return 0;
}