/*
TOPIC: Pointer Arithmetic
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>
#include <cstddef>

using namespace std;


int main() {

    int values[5] = {
        5, 10, 15, 20, 25
    };


    // ========================================================
    // BASIC 1: OFFSET
    // ========================================================

    int* ptr =
        values;

    cout << "=== BASIC 1: Offsets ===\n";

    cout << *(ptr + 0) << '\n';
    cout << *(ptr + 1) << '\n';
    cout << *(ptr + 2) << "\n\n";


    // ========================================================
    // BASIC 2: INDEX EQUIVALENCE
    // ========================================================

    cout << "=== BASIC 2: Indexing ===\n";

    cout << values[3]
         << ' '
         << *(values + 3)
         << ' '
         << ptr[3]
         << "\n\n";


    // ========================================================
    // BASIC 3: MOVE POINTER
    // ========================================================

    cout << "=== BASIC 3: Move Pointer ===\n";

    ptr = values;

    for (int i = 0; i < 5; ++i) {

        cout << *ptr << ' ';

        ++ptr;
    }

    cout << "\n\n";


    // ptr is now one-past-end.
    //
    // Do NOT dereference it.


    // ========================================================
    // BASIC 4: DISTANCE
    // ========================================================

    int* begin =
        values;

    int* end =
        values + 5;

    ptrdiff_t count =
        end - begin;

    cout << "=== BASIC 4: Distance ===\n";

    cout << count
         << "\n\n";


    // ========================================================
    // BASIC 5: MODIFY THROUGH POINTER
    // ========================================================

    cout << "=== BASIC 5: Modify ===\n";

    ptr = values;

    while (ptr != end) {

        *ptr *= 2;

        ++ptr;
    }

    for (int value : values) {
        cout << value << ' ';
    }

    cout << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Offsets ===
5
10
15

=== BASIC 2: Indexing ===
20 20 20

=== BASIC 3: Move Pointer ===
5 10 15 20 25

=== BASIC 4: Distance ===
5

=== BASIC 5: Modify ===
10 20 30 40 50

WHAT'S NEXT:
01_C++__/16_DYNAMIC_MEMORY/
*/
