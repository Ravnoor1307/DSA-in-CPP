/*
TOPIC: Dynamic Memory

Covers:
- Dynamic storage duration
- new / delete
- new[] / delete[]
- Initialization
- Dynamic arrays
- Memory leaks
- Dangling pointers
- Use-after-free
- Double delete
- Pointer aliasing and ownership
- Dynamic 2D arrays
- Flat matrices
- Shallow vs deep copy
- RAII motivation

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: DYNAMIC OBJECT ==========
//
//     int* ptr = new int(10);
//
// new creates a dynamically allocated int and returns a pointer.
//
// The pointer may be a local variable.
//
// The dynamic object's lifetime is independent of that local
// pointer's scope.


// ========== SECTION 2: DELETE ==========
//
// Scalar allocation:
//
//     int* ptr = new int(10);
//
// Scalar deallocation:
//
//     delete ptr;
//
// After delete, ptr must not be dereferenced.
//
// A common local defensive step:
//
//     ptr = nullptr;


// ========== SECTION 3: MATCHING RULE ==========
//
//     new      -> delete
//
//     new[]    -> delete[]
//
// Never mismatch them.


// ========== SECTION 4: MEMORY LEAK ==========
//
// Wrong:
//
//     int* ptr = new int(10);
//     ptr = nullptr;
//
// The allocation remains alive but its owning pointer was lost.


// ========== SECTION 5: DANGLING POINTER ==========
//
//     int* ptr = new int(10);
//     delete ptr;
//
// ptr now contains a stale pointer value.
//
// It is dangling until changed.
//
// Do not dereference it.


// ========== SECTION 6: DOUBLE DELETE ==========
//
// Wrong:
//
//     delete ptr;
//     delete ptr;
//
// Releasing the same allocation twice is undefined behavior.


// ========== SECTION 7: DYNAMIC ARRAY ==========
//
//     int* values = new int[n];
//
// fundamental elements are not automatically initialized.
//
// Zero initialization:
//
//     int* values = new int[n]{};
//
// Cleanup:
//
//     delete[] values;


// ========== SECTION 8: POINTER ARITHMETIC ==========
//
// A dynamically allocated array supports valid array pointer
// arithmetic:
//
//     values[i]
//     *(values + i)
//
// for valid i.


// ========== SECTION 9: OWNERSHIP ==========
//
// A raw pointer does not state whether it owns an allocation.
//
// Clear ownership answers:
//
//     Who is responsible for delete?
//
// Modern C++ usually represents ownership with RAII types.


// ========== SECTION 10: SHALLOW COPY ==========
//
//     int* first = new int[3];
//     int* second = first;
//
// Only the pointer is copied.
//
// Both point to the same allocation.
//
// They must NOT both independently delete it.


// ========== SECTION 11: DEEP COPY ==========
//
// Independent allocation:
//
//     int* second = new int[n];
//
// Copy each element.
//
// Now first and second own different arrays.


// ========== SECTION 12: FLAT 2D MEMORY ==========
//
//     int* matrix = new int[rows * cols]{};
//
// Element:
//
//     matrix[row * cols + col]
//
// Cleanup:
//
//     delete[] matrix;


// ========== SECTION 13: POINTER-TO-POINTER MATRIX ==========
//
//     int** matrix = new int*[rows];
//
// Allocate each row separately.
//
// Cleanup each row first, then the outer pointer array.


// ========== SECTION 14: MODERN C++ ==========
//
// Learn new/delete to understand memory.
//
// Prefer:
//
//     vector
//     string
//     unique_ptr
//
// when they correctly model ownership and storage.
//
// These automatically manage cleanup through RAII.


void scalarDemo();
void arrayDemo();
void deepCopyDemo();
void flatMatrixDemo();
void rowPointerMatrixDemo();


int main() {

    cout << "=== DEMO 1: Scalar Dynamic Object ===\n";
    scalarDemo();

    cout << '\n';


    cout << "=== DEMO 2: Dynamic Array ===\n";
    arrayDemo();

    cout << '\n';


    cout << "=== DEMO 3: Deep Copy ===\n";
    deepCopyDemo();

    cout << '\n';


    cout << "=== DEMO 4: Flat Dynamic Matrix ===\n";
    flatMatrixDemo();

    cout << '\n';


    cout << "=== DEMO 5: int** Matrix ===\n";
    rowPointerMatrixDemo();

    cout << '\n';


    cout << "=== DEMO 6: delete nullptr ===\n";

    int* empty = nullptr;

    delete empty;

    cout << "Deleting nullptr completed safely.\n";

    return 0;
}


void scalarDemo() {

    int* ptr =
        new int{10};

    cout << "initial = "
         << *ptr << '\n';

    *ptr = 50;

    cout << "modified = "
         << *ptr << '\n';

    delete ptr;

    ptr = nullptr;

    cout << boolalpha;

    cout << "pointer reset = "
         << (ptr == nullptr)
         << '\n';

    cout << noboolalpha;
}


void arrayDemo() {

    const int n = 5;

    int* values =
        new int[n]{};

    for (int i = 0; i < n; ++i) {
        values[i] =
            (i + 1) * 10;
    }

    for (int i = 0; i < n; ++i) {
        cout << values[i] << ' ';
    }

    cout << '\n';

    delete[] values;

    values = nullptr;
}


void deepCopyDemo() {

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

    second[0] = 99;

    cout << "first: ";

    for (int i = 0; i < n; ++i) {
        cout << first[i] << ' ';
    }

    cout << '\n';

    cout << "second: ";

    for (int i = 0; i < n; ++i) {
        cout << second[i] << ' ';
    }

    cout << '\n';

    delete[] first;
    delete[] second;
}


void flatMatrixDemo() {

    const int rows = 2;
    const int cols = 3;

    int* matrix =
        new int[rows * cols]{};

    int value = 1;

    for (int row = 0;
         row < rows;
         ++row) {

        for (int col = 0;
             col < cols;
             ++col) {

            matrix[row * cols + col] =
                value;

            ++value;
        }
    }

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
}


void rowPointerMatrixDemo() {

    const int rows = 2;
    const int cols = 3;

    int** matrix =
        new int*[rows];

    for (int row = 0;
         row < rows;
         ++row) {

        matrix[row] =
            new int[cols]{};
    }

    int value = 1;

    for (int row = 0;
         row < rows;
         ++row) {

        for (int col = 0;
             col < cols;
             ++col) {

            matrix[row][col] =
                value++;

            cout
                << matrix[row][col]
                << ' ';
        }

        cout << '\n';
    }

    // Each row owns a separate dynamic array.
    for (int row = 0;
         row < rows;
         ++row) {

        delete[] matrix[row];
    }

    delete[] matrix;
}


/*
EXPECTED OUTPUT

=== DEMO 1: Scalar Dynamic Object ===
initial = 10
modified = 50
pointer reset = true

=== DEMO 2: Dynamic Array ===
10 20 30 40 50

=== DEMO 3: Deep Copy ===
first: 1 2 3
second: 99 2 3

=== DEMO 4: Flat Dynamic Matrix ===
1 2 3
4 5 6

=== DEMO 5: int** Matrix ===
1 2 3
4 5 6

=== DEMO 6: delete nullptr ===
Deleting nullptr completed safely.

WHAT'S NEXT:
01_C++__/17_STRUCTURES_UNIONS_ENUMS/
*/
