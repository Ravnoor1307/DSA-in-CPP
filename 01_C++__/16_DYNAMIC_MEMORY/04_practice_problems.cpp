/*
TOPIC: Dynamic Memory
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;


// ============================================================
// PROBLEM 1: CREATE FILLED ARRAY
// ============================================================
//
// Educational raw-owning function.
//
// Caller must release returned memory with delete[].

int* createFilledArray(
    int n,
    int value
) {
    if (n <= 0) {
        return nullptr;
    }

    int* array =
        new int[n];

    for (int i = 0; i < n; ++i) {
        array[i] = value;
    }

    return array;
}


// ============================================================
// PROBLEM 2: DEEP COPY
// ============================================================

int* copyArray(
    const int* source,
    int n
) {
    if (n <= 0) {
        return nullptr;
    }

    int* copy =
        new int[n];

    for (int i = 0; i < n; ++i) {
        copy[i] =
            source[i];
    }

    return copy;
}


// ============================================================
// PROBLEM 3: SUM DYNAMIC ARRAY
// ============================================================

long long sumArray(
    const int* values,
    int n
) {
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += values[i];
    }

    return sum;
}


// ============================================================
// PROBLEM 4: MANUAL RESIZE
// ============================================================
//
// Creates a new allocation and copies as many old elements as
// will fit. New positions are initialized to zero.
//
// The old allocation is deleted.
//
// Returns the new owning pointer.

int* resizeArray(
    int* oldArray,
    int oldSize,
    int newSize
) {
    if (newSize <= 0) {
        delete[] oldArray;
        return nullptr;
    }

    int* newArray =
        new int[newSize]{};

    int copyCount =
        (oldSize < newSize)
            ? oldSize
            : newSize;

    for (int i = 0;
         i < copyCount;
         ++i) {

        newArray[i] =
            oldArray[i];
    }

    delete[] oldArray;

    return newArray;
}


// ============================================================
// PROBLEM 5: FLAT MATRIX SUM
// ============================================================

long long matrixSum(
    const int* matrix,
    int rows,
    int cols
) {
    long long sum = 0;

    for (int row = 0;
         row < rows;
         ++row) {

        for (int col = 0;
             col < cols;
             ++col) {

            sum +=
                matrix[
                    row * cols + col
                ];
        }
    }

    return sum;
}


void printArray(
    const int* values,
    int n
) {
    for (int i = 0; i < n; ++i) {

        cout << values[i];

        if (i + 1 < n) {
            cout << ' ';
        }
    }

    cout << '\n';
}


int main() {

    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Filled Array ===\n";

    int n = 5;

    int* values =
        createFilledArray(
            n,
            7
        );

    printArray(values, n);

    cout << '\n';


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Deep Copy ===\n";

    int* copied =
        copyArray(
            values,
            n
        );

    copied[0] = 99;

    cout << "original: ";
    printArray(values, n);

    cout << "copy: ";
    printArray(copied, n);

    cout << '\n';


    // ========================================================
    // TEST 3
    // ========================================================

    cout << "=== PROBLEM 3: Sum ===\n";

    cout << sumArray(values, n)
         << "\n\n";


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Manual Resize ===\n";

    values =
        resizeArray(
            values,
            n,
            8
        );

    n = 8;

    printArray(values, n);

    cout << '\n';


    // ========================================================
    // TEST 5
    // ========================================================

    cout << "=== PROBLEM 5: Flat Matrix ===\n";

    const int rows = 2;
    const int cols = 3;

    int* matrix =
        new int[rows * cols]{
            1, 2, 3,
            4, 5, 6
        };

    cout << "sum = "
         << matrixSum(
                matrix,
                rows,
                cols
            )
         << '\n';


    // ========================================================
    // CLEANUP
    // ========================================================

    delete[] values;
    delete[] copied;
    delete[] matrix;

    values = nullptr;
    copied = nullptr;
    matrix = nullptr;

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Filled Array ===
7 7 7 7 7

=== PROBLEM 2: Deep Copy ===
original: 7 7 7 7 7
copy: 99 7 7 7 7

=== PROBLEM 3: Sum ===
35

=== PROBLEM 4: Manual Resize ===
7 7 7 7 7 0 0 0

=== PROBLEM 5: Flat Matrix ===
sum = 21


PRACTICE LINKS

1. GFG Dynamic Memory Allocation
https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

2. cppreference new
https://en.cppreference.com/w/cpp/language/new

3. cppreference delete
https://en.cppreference.com/w/cpp/language/delete

4. LeetCode 707
https://leetcode.com/problems/design-linked-list/

5. LeetCode 206
https://leetcode.com/problems/reverse-linked-list/


WHAT'S NEXT:
01_C++__/17_STRUCTURES_UNIONS_ENUMS/
*/
