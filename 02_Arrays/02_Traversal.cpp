/*
=======================================================================
 THEORY : Array Traversal
=======================================================================
 Traversal means VISITING every element of an array (usually to read
 or process it). This is the most common array operation.

 1. FORWARD (linear) traversal  - index 0 to length-1
        for (int i = 0; i < length; i++)
        while (i < length) { ... i++; }

 2. REVERSE traversal           - index length-1 down to 0
        for (int i = length - 1; i >= 0; i--)
        while (j >= 0) { ... j--; }

 3. RANGE-BASED for loop        - clean, no index needed
        for (int value : Marks)                 // copy of each value
        for (auto value = rbegin(Marks); value != rend(Marks); ++value)
    - rbegin()/rend() give REVERSE iterators, so the loop goes from
      the last element to the first. *value dereferences the iterator.
    - `auto` deduces the type automatically (here a pointer/iterator).

 4. WHY traversal matters
    - Most array algorithms (searching, finding max/min, sum,
      sorting, moving data) begin with a traversal.

 COMPLEXITY:
    Time  : O(n)  -> every traversal touches all n elements once
    Space : O(1)  -> uses only a loop counter (no extra arrays)
=======================================================================
*/
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