#include <iostream>
using namespace std;
int main()
{

    //  For Loop
    for (int i = 0; i < 5; i++)
    {
        cout << "Hello World\n";
    }

    // For loop that starts with i = 1 and ends
    // when i is greater than 5.
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }

    // While Loop

    // Initialization
    int i = 1;

    // while loop that starts with i = 1 and ends
    // when i is greater than 5.
    while (i <= 5)
    {
        cout << i << " ";

        // Updation
        i++;
    }

    // Do While Loop

    // while loop that starts with i = 1 and ends
    // when i is greater than 5.
    do
    {
        cout << i << " ";

        // Updation
        i++;
    } while (i <= 5);

    // For Each Loop

    int arr[] = {1, 2, 3, 4, 5};

    // By value
    cout << "Iterating by value" << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    // By reference
    cout << "Iterating with reference" << endl;
    for (auto &it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    // Nested Loop

    for (int i = 0; i < 3; i++)
    {

        // Outer loop runs 3 times
        for (int j = 0; j < 2; j++)
        {

            // Inner loop runs 2 times for each
            // outer loop iteration
            cout << "i = " << i << ", j = " << j << endl;
        }
    }

    // Jump Statements

    for (int i = 1; i < 10; i++)
    {

        // Skip the execution for i = 5
        if (i == 5)
            continue;
        cout << i << " ";
    }

    // Loop to print digits from 1 to 4
    for (int i = 1; i < 10; i++)
    {

        // Breaking Condition
        if (i == 5)
            break;
        cout << i << " ";
    }

    // goto

    int n = 4;

    if (n % 2 == 0)
    {

        // Skipping to label1
        goto label1;
    }
    else
    {

        // Skipping to label2
        goto label2;
    }

label1:
    cout << "Even" << endl;
    return 0;

label2:
    cout << "Odd" << endl;
    return 0;
label3:
    cout << "Unspecified";

    return 0;
}