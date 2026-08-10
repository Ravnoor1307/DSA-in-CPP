#include <iostream>
using namespace std;
int main()
{

    // Declaration
    int marks[5];

    // Initializing
    int Marks[5] = {98, 90, 78, 79, 89};

    double price[] = {34, 63, 67, 46}; // 4

    cout << endl
         << Marks[0] << endl;
    cout << endl
         << Marks[1] << endl;
    cout << endl
         << Marks[2] << endl;
    cout << endl
         << Marks[3] << endl;
    cout << endl
         << Marks[4] << endl;

    // Using Loops
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        cout << "Marks of Student " << i << " : " << Marks[i] << endl;
    }
    return 0;
}