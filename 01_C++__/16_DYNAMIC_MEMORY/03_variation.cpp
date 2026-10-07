/*
TOPIC: Dynamic Memory
FILE: 03_variation.cpp

Purpose:
Explore:
- scalar initialization forms
- array initialization
- aliasing
- shallow vs deep copies
- ownership transfer as a concept
- flat runtime matrices

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


int* createValue(
    int value
) {
    // Educational raw-owning return.
    //
    // The caller becomes responsible for delete.
    return new int{value};
}


int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: VALUE INITIALIZATION
    // ========================================================

    int* zero =
        new int{};

    cout << "=== VARIATION 1: Value Initialization ===\n";

    cout << *zero
         << "\n\n";

    delete zero;


    // ========================================================
    // VARIATION 2: PARTIAL ARRAY INITIALIZATION
    // ========================================================

    int* values =
        new int[5]{
            10,
            20
        };

    cout << "=== VARIATION 2: Array Initialization ===\n";

    for (int i = 0; i < 5; ++i) {
        cout << values[i]
             << ' ';
    }

    cout << "\n\n";

    delete[] values;


    // ========================================================
    // VARIATION 3: SHALLOW POINTER COPY
    // ========================================================

    int* owner =
        new int{50};

    int* alias =
        owner;

    cout << "=== VARIATION 3: Pointer Alias ===\n";

    *alias = 75;

    cout << "*owner = "
         << *owner << '\n';

    cout << "*alias = "
         << *alias << '\n';

    // Only one allocation exists.
    // Release it once.
    delete owner;

    owner = nullptr;
    alias = nullptr;

    cout << '\n';


    // ========================================================
    // VARIATION 4: DEEP COPY
    // ========================================================

    const int n = 3;

    int* first =
        new int[n]{
            1, 2, 3
        };

    int* second =
        new int[n];

    for (int i = 0; i < n; ++i) {
        second[i] =
            first[i];
    }

    second[1] = 99;

    cout << "=== VARIATION 4: Deep Copy ===\n";

    cout << "first[1] = "
         << first[1] << '\n';

    cout << "second[1] = "
         << second[1] << "\n\n";

    delete[] first;
    delete[] second;


    // ========================================================
    // VARIATION 5: RAW OWNING RETURN
    // ========================================================

    int* created =
        createValue(123);

    cout << "=== VARIATION 5: Owning Return ===\n";

    cout << *created
         << '\n';

    // The caller must know it owns the allocation.
    delete created;
    created = nullptr;

    cout << '\n';


    // ========================================================
    // VARIATION 6: FLAT MATRIX
    // ========================================================

    const int rows = 3;
    const int cols = 2;

    int* matrix =
        new int[rows * cols]{};

    for (int row = 0;
         row < rows;
         ++row) {

        for (int col = 0;
             col < cols;
             ++col) {

            matrix[row * cols + col] =
                row * 10 + col;
        }
    }

    cout << "=== VARIATION 6: Flat Matrix ===\n";

    for (int row = 0;
         row < rows;
         ++row) {

        for (int col = 0;
             col < cols;
             ++col) {

            cout
                << matrix[
                       row * cols + col
                   ]
                << ' ';
        }

        cout << '\n';
    }

    delete[] matrix;

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Value Initialization ===
0

=== VARIATION 2: Array Initialization ===
10 20 0 0 0

=== VARIATION 3: Pointer Alias ===
*owner = 75
*alias = 75

=== VARIATION 4: Deep Copy ===
first[1] = 2
second[1] = 99

=== VARIATION 5: Owning Return ===
123

=== VARIATION 6: Flat Matrix ===
0 1
10 11
20 21

WHAT'S NEXT:
01_C++__/17_STRUCTURES_UNIONS_ENUMS/
*/
