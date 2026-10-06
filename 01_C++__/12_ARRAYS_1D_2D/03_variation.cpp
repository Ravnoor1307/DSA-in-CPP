/*
TOPIC: Arrays 1D and 2D
FILE: 03_variation.cpp

Purpose:
Explore:
- size deduction
- partial initialization
- array-to-pointer conversion
- mutation through function parameters
- array references
- reverse traversal
- matrix row/column sums

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


void mutate(
    int values[],
    int n
) {
    for (int i = 0; i < n; ++i) {
        values[i] *= 2;
    }
}


// A reference to the entire array.
// The extent 3 is preserved.
void printThree(
    const int (&values)[3]
) {
    for (int value : values) {
        cout << value << ' ';
    }

    cout << '\n';
}


int main() {

    // ========================================================
    // VARIATION 1: SIZE DEDUCTION
    // ========================================================

    int first[] = {
        5, 10, 15, 20
    };

    cout << "=== VARIATION 1: Deduction ===\n";

    cout << "elements = "
         << sizeof(first) / sizeof(first[0])
         << "\n\n";


    // ========================================================
    // VARIATION 2: PARTIAL INITIALIZATION
    // ========================================================

    int partial[5] = {
        7, 8
    };

    cout << "=== VARIATION 2: Partial Initialization ===\n";

    for (int value : partial) {
        cout << value << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 3: ARRAY DECAYS TO POINTER
    // ========================================================

    int values[3] = {
        10, 20, 30
    };

    int* pointer = values;

    cout << "=== VARIATION 3: First Element Pointer ===\n";

    cout << boolalpha;

    cout << "pointer == &values[0]: "
         << (pointer == &values[0])
         << '\n';

    cout << "*pointer = "
         << *pointer
         << "\n\n";


    // ========================================================
    // VARIATION 4: FUNCTION MUTATION
    // ========================================================

    mutate(values, 3);

    cout << "=== VARIATION 4: Mutation ===\n";

    for (int value : values) {
        cout << value << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 5: ARRAY REFERENCE
    // ========================================================

    cout << "=== VARIATION 5: Whole Array Reference ===\n";

    printThree(values);

    cout << '\n';


    // ========================================================
    // VARIATION 6: REVERSE TRAVERSAL
    // ========================================================

    cout << "=== VARIATION 6: Reverse Traversal ===\n";

    for (int i = 2; i >= 0; --i) {
        cout << values[i] << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 7: ROW AND COLUMN SUMS
    // ========================================================

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "=== VARIATION 7: Row Sums ===\n";

    for (int row = 0; row < 3; ++row) {

        int sum = 0;

        for (int col = 0; col < 3; ++col) {
            sum += matrix[row][col];
        }

        cout << sum << ' ';
    }

    cout << "\n\n";


    cout << "=== VARIATION 8: Column Sums ===\n";

    for (int col = 0; col < 3; ++col) {

        int sum = 0;

        for (int row = 0; row < 3; ++row) {
            sum += matrix[row][col];
        }

        cout << sum << ' ';
    }

    cout << "\n\n";


    cout << "=== VARIATION 9: Secondary Diagonal ===\n";

    for (int i = 0; i < 3; ++i) {
        cout << matrix[i][3 - 1 - i]
             << ' ';
    }

    cout << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Deduction ===
elements = 4

=== VARIATION 2: Partial Initialization ===
7 8 0 0 0

=== VARIATION 3: First Element Pointer ===
pointer == &values[0]: true
*pointer = 10

=== VARIATION 4: Mutation ===
20 40 60

=== VARIATION 5: Whole Array Reference ===
20 40 60

=== VARIATION 6: Reverse Traversal ===
60 40 20

=== VARIATION 7: Row Sums ===
6 15 24

=== VARIATION 8: Column Sums ===
12 15 18

=== VARIATION 9: Secondary Diagonal ===
3 5 7

WHAT'S NEXT:
01_C++__/13_STRINGS_AND_C_STRINGS/
*/
