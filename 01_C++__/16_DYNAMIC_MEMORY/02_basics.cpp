/*
TOPIC: Dynamic Memory
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics

Suggested input:
5
*/

#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // ========================================================
    // BASIC 1: DYNAMIC INT
    // ========================================================

    int* value =
        new int{42};

    cout << "=== BASIC 1: Dynamic int ===\n";

    cout << *value
         << "\n\n";

    delete value;
    value = nullptr;


    // ========================================================
    // BASIC 2: RUNTIME ARRAY
    // ========================================================

    int n{};
    cin >> n;

    // This lesson assumes a non-negative input n.
    int* values =
        new int[n]{};

    for (int i = 0; i < n; ++i) {
        values[i] =
            i + 1;
    }

    cout << "=== BASIC 2: Dynamic Array ===\n";

    for (int i = 0; i < n; ++i) {
        cout << values[i]
             << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 3: SUM
    // ========================================================

    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += values[i];
    }

    cout << "=== BASIC 3: Sum ===\n";

    cout << sum
         << "\n\n";


    // ========================================================
    // BASIC 4: POINTER ARITHMETIC
    // ========================================================

    cout << "=== BASIC 4: Pointer Walk ===\n";

    const int* begin =
        values;

    const int* end =
        values + n;

    while (begin != end) {

        cout << *begin
             << ' ';

        ++begin;
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 5: CLEANUP
    // ========================================================

    delete[] values;
    values = nullptr;

    cout << "=== BASIC 5: Cleanup ===\n";

    cout << boolalpha
         << (values == nullptr)
         << '\n';

    return 0;
}


/*
SUGGESTED INPUT

5


EXPECTED OUTPUT

=== BASIC 1: Dynamic int ===
42

=== BASIC 2: Dynamic Array ===
1 2 3 4 5

=== BASIC 3: Sum ===
15

=== BASIC 4: Pointer Walk ===
1 2 3 4 5

=== BASIC 5: Cleanup ===
true

WHAT'S NEXT:
01_C++__/17_STRUCTURES_UNIONS_ENUMS/
*/
