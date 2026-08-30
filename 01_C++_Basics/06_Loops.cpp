/*
=======================================================================
 THEORY : Loops (Iteration) & Jump Statements
=======================================================================
 Loops repeat a block of code while (or for a fixed number of times)
 a condition is satisfied. Iteration is the core of DSA because it
 lets us process large data very quickly.

 1. for loop        - used when the number of iterations is known.
        for (initialisation; condition; updation) { body }
         Eg: for (int i = 0; i < 5; i++)

 2. while loop      - used when iterations depend on a condition.
        initialisation;
        while (condition) { body; updation; }

 3. do-while loop   - body runs AT LEAST ONCE, then condition checked.
        do { body; } while (condition);

 4. Range-based for (for-each) loop - iterates over every element.
        for (auto it : arr)             // by-value (copy)
        for (auto &it : arr)            // by-reference (no copy)
    - `auto` lets the compiler deduce the element type.

 5. Nested loops    - a loop inside another loop.
        Outer runs N times; for each outer iteration the INNER loop
        runs fully, giving N*M total inner executions.

 6. Jump statements
        continue : skips the CURRENT iteration, goes to next.
        break    : terminates the whole loop immediately.
        goto label : jumps to a labelled line in the function
                     (use sparingly - makes code hard to read).

 EXAMPLE - nested loop on i=0..2 and j=0..1 prints:
        i = 0, j = 0
        i = 0, j = 1
        i = 1, j = 0  ... and so on (6 lines total)
=======================================================================
*/
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