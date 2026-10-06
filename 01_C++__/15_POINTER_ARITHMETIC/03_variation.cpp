/*
TOPIC: Pointer Arithmetic
FILE: 03_variation.cpp

Purpose:
Explore reverse ranges, midpoint calculations, two pointers,
2D-array pointers, and C-string pointer traversal.

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>
#include <cstddef>

using namespace std;


int pointerStringLength(
    const char* text
) {
    const char* begin =
        text;

    const char* end =
        text;

    while (*end != '\0') {
        ++end;
    }

    return static_cast<int>(
        end - begin
    );
}


int main() {

    // ========================================================
    // VARIATION 1: REVERSE FROM ONE-PAST
    // ========================================================

    int values[5] = {
        10, 20, 30, 40, 50
    };

    const int* begin =
        values;

    const int* current =
        values + 5;

    cout << "=== VARIATION 1: Reverse ===\n";

    while (current != begin) {

        --current;

        cout << *current
             << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 2: MIDPOINT
    // ========================================================

    const int* end =
        values + 5;

    const int* middle =
        begin + (end - begin) / 2;

    cout << "=== VARIATION 2: Midpoint ===\n";

    cout << "*middle = "
         << *middle
         << "\n\n";


    // ========================================================
    // VARIATION 3: TWO POINTERS
    // ========================================================

    int reverseValues[5] = {
        1, 2, 3, 4, 5
    };

    int* left =
        reverseValues;

    int* right =
        reverseValues + 4;

    while (left < right) {

        int temp = *left;

        *left = *right;
        *right = temp;

        ++left;
        --right;
    }

    cout << "=== VARIATION 3: Pointer Reverse ===\n";

    for (int value : reverseValues) {
        cout << value << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 4: POINTER TO ROW
    // ========================================================

    int matrix[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    int (*rowPointer)[2] =
        matrix;

    cout << "=== VARIATION 4: Row Pointer ===\n";

    cout << (*rowPointer)[0]
         << ' '
         << (*rowPointer)[1]
         << '\n';

    ++rowPointer;

    cout << (*rowPointer)[0]
         << ' '
         << (*rowPointer)[1]
         << "\n\n";


    // ========================================================
    // VARIATION 5: 2D POINTER EXPRESSION
    // ========================================================

    cout << "=== VARIATION 5: Matrix Expression ===\n";

    cout << *(*(matrix + 2) + 1)
         << "\n\n";


    // ========================================================
    // VARIATION 6: C-STRING LENGTH
    // ========================================================

    const char text[] =
        "pointer";

    cout << "=== VARIATION 6: Pointer String Length ===\n";

    cout << pointerStringLength(text)
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Reverse ===
50 40 30 20 10

=== VARIATION 2: Midpoint ===
*middle = 30

=== VARIATION 3: Pointer Reverse ===
5 4 3 2 1

=== VARIATION 4: Row Pointer ===
1 2
3 4

=== VARIATION 5: Matrix Expression ===
6

=== VARIATION 6: Pointer String Length ===
7

WHAT'S NEXT:
01_C++__/16_DYNAMIC_MEMORY/
*/
