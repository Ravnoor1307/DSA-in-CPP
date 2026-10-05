/*
TOPIC: Loops
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

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

    int n{};
    cin >> n;


    // ========================================================
    // BASIC 1: PRINT 1 TO N
    // ========================================================

    cout << "=== BASIC 1: 1 to N ===\n";

    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 2: PRINT N TO 1
    // ========================================================

    cout << "=== BASIC 2: N to 1 ===\n";

    for (int i = n; i >= 1; --i) {
        cout << i << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 3: EVEN VALUES
    // ========================================================

    cout << "=== BASIC 3: Even Values ===\n";

    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 4: SUM 1 TO N
    // ========================================================

    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << "=== BASIC 4: Sum ===\n";

    cout << sum << "\n\n";


    // ========================================================
    // BASIC 5: FACTORIAL
    // ========================================================
    //
    // Intended for small non-negative n.
    // Factorials overflow fixed-width integer types quickly.

    long long factorial = 1;

    for (int i = 2; i <= n; ++i) {
        factorial *= i;
    }

    cout << "=== BASIC 5: Factorial ===\n";

    cout << factorial << "\n\n";


    // ========================================================
    // BASIC 6: WHILE VERSION
    // ========================================================

    cout << "=== BASIC 6: while ===\n";

    int i = 1;

    while (i <= n) {
        cout << i << ' ';
        ++i;
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 7: SIMPLE PATTERN
    // ========================================================

    cout << "=== BASIC 7: Pattern ===\n";

    for (int row = 1; row <= n; ++row) {

        for (int col = 1; col <= row; ++col) {
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}


/*
SUGGESTED INPUT

5


EXPECTED OUTPUT

=== BASIC 1: 1 to N ===
1 2 3 4 5

=== BASIC 2: N to 1 ===
5 4 3 2 1

=== BASIC 3: Even Values ===
2 4

=== BASIC 4: Sum ===
15

=== BASIC 5: Factorial ===
120

=== BASIC 6: while ===
1 2 3 4 5

=== BASIC 7: Pattern ===
*
**
***
****
*****

WHAT'S NEXT:
01_C++__/08_FUNCTIONS/
*/
