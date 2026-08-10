#include <iostream>
using namespace std;
int main()
{

    int Marks[5] = {98, 90, 78, 79, 89};
    int length = sizeof(Marks) / sizeof(Marks[0]);

    // Linear Traversal Using For Loop
    for (int i = 0; i < length; i++)
    {
        cout << "Marks " << i << " : " << Marks[i] << endl;
    }
    cout << endl;

    // Linear Traversal Using While Loop
    int i = 0;
    while (i < length)
    {
        cout << "Marks " << i << " : " << Marks[i] << endl;
        i++;
    }
    cout << endl;

    // Linear Traversal Using For Each Loop
    for (int value : Marks)
    {
        cout << "Marks : " << value << endl;
    }
    cout << endl;

    // Reverse Traversal Using For Loop
    for (int i = length - 1; i >= 0; i--)
    {
        cout << "Marks " << i << " : " << Marks[i] << endl;
    }
    cout << endl;

    // Reverse Traversal Using While Loop
    int j = length - 1;
    while (j >= 0)
    {
        cout << "Marks " << j << " : " << Marks[j] << endl;
        j--;
    }
    cout << endl;

    // Reverse Traversal Using For Each Loop
    for (auto value = rbegin(Marks); value != rend(Marks); ++value)
    {
        cout << "Marks : " << *value << endl;
    } // Pointers are Used here
    cout << endl;

    return 0;
}