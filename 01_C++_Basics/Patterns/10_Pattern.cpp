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