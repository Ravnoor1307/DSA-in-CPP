#include <iostream>
using namespace std;
int main()
{

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << k + 1 << " ";
        }
        for (int l = 0; l < i; l++)
        {
            cout << l + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}