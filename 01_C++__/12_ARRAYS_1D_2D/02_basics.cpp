/*
TOPIC: Arrays 1D and 2D
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;


void printArray(
    const int values[],
    int n
) {
    for (int i = 0; i < n; ++i) {
        cout << values[i] << ' ';
    }

    cout << '\n';
}


int main() {

    // ========================================================
    // BASIC 1: CREATE AN ARRAY
    // ========================================================

    int values[5] = {
        10, 20, 30, 40, 50
    };

    cout << "=== BASIC 1: Array ===\n";

    printArray(values, 5);

    cout << '\n';


    // ========================================================
    // BASIC 2: ACCESS ELEMENTS
    // ========================================================

    cout << "=== BASIC 2: Indexing ===\n";

    cout << "first = "
         << values[0] << '\n';

    cout << "last = "
         << values[4] << "\n\n";


    // ========================================================
    // BASIC 3: MODIFY
    // ========================================================

    values[1] = 99;

    cout << "=== BASIC 3: Modification ===\n";

    printArray(values, 5);

    cout << '\n';


    // ========================================================
    // BASIC 4: SUM
    // ========================================================

    long long sum = 0;

    for (int i = 0; i < 5; ++i) {
        sum += values[i];
    }

    cout << "=== BASIC 4: Sum ===\n";

    cout << sum << "\n\n";


    // ========================================================
    // BASIC 5: MINIMUM / MAXIMUM
    // ========================================================

    int minimum = values[0];
    int maximum = values[0];

    for (int i = 1; i < 5; ++i) {

        if (values[i] < minimum) {
            minimum = values[i];
        }

        if (values[i] > maximum) {
            maximum = values[i];
        }
    }

    cout << "=== BASIC 5: Min/Max ===\n";

    cout << "minimum = "
         << minimum << '\n';

    cout << "maximum = "
         << maximum << "\n\n";


    // ========================================================
    // BASIC 6: ZERO INITIALIZATION
    // ========================================================

    int zeros[5]{};

    cout << "=== BASIC 6: Zero Initialization ===\n";

    printArray(zeros, 5);

    cout << '\n';


    // ========================================================
    // BASIC 7: MATRIX
    // ========================================================

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "=== BASIC 7: Matrix ===\n";

    for (int row = 0; row < 2; ++row) {

        for (int col = 0; col < 3; ++col) {

            cout << matrix[row][col]
                 << ' ';
        }

        cout << '\n';
    }

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Array ===
10 20 30 40 50

=== BASIC 2: Indexing ===
first = 10
last = 50

=== BASIC 3: Modification ===
10 99 30 40 50

=== BASIC 4: Sum ===
229

=== BASIC 5: Min/Max ===
minimum = 10
maximum = 99

=== BASIC 6: Zero Initialization ===
0 0 0 0 0

=== BASIC 7: Matrix ===
1 2 3
4 5 6

WHAT'S NEXT:
01_C++__/13_STRINGS_AND_C_STRINGS/
*/
