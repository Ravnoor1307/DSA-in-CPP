/*
=======================================================================
 THEORY : Arrays - Basics
=======================================================================
 1. WHAT IS AN ARRAY?
    - A collection of elements of the SAME data type stored in
      CONTIGUOUS (next-to-each-other) memory locations.
    - Every element is placed at                    base_address
      + index * size_of_one_element, so any element can be reached
      directly -> array access is O(1) constant time.

 2. DECLARATION        (allocates memory, values are garbage)
        int marks[5];

 3. INITIALIZATION     (list of values inside { })
        int Marks[5] = {98, 90, 78, 79, 89};
        double price[] = {34, 63, 67, 46};   // size auto = 4

 4. INDEXING
    - First element is at index 0, last at size-1.
        Marks[0] = 98,  Marks[1] = 90 ... Marks[4] = 89
    - Out-of-range index (e.g. Marks[5]) is undefined behaviour.

 5. ACCESS
    - Directly:      cout << Marks[0];
    - Using a loop:  for (int i = 0; i < size; i++) cout << Marks[i];

 6. Parsing size
    - int size = sizeof(arr) / sizeof(arr[0]);
      sizeof(arr)      -> total bytes of the whole array
      sizeof(arr[0])   -> bytes of one element
      ratio            -> number of elements

 COMPLEXITY:  access O(1) | full traversal O(n) | space O(n)

 EXPECTED OUTPUT:
    98
    90
    78
    79
    89
    Marks of Student 0 : 98
    ... (loop prints all 5 marks)
=======================================================================
*/
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