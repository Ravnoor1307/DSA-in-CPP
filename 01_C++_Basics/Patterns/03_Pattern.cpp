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