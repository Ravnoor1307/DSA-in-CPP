/*
TOPIC: Loops
FILE: 03_variation.cpp

Purpose:
Study loop variations, edge cases, break/continue behavior,
nested loops, EOF input, and iteration-count patterns.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;

int main() {


    // ========================================================
    // VARIATION 1: ZERO ITERATIONS
    // ========================================================

    cout << "=== VARIATION 1: while Can Run Zero Times ===\n";

    int x = 10;

    while (x < 5) {
        cout << "This will not print\n";
    }

    cout << "Loop finished\n\n";


    // ========================================================
    // VARIATION 2: DO-WHILE RUNS AT LEAST ONCE
    // ========================================================

    cout << "=== VARIATION 2: do-while ===\n";

    do {
        cout << "Runs once even though x < 5 is false\n";
    } while (x < 5);

    cout << '\n';


    // ========================================================
    // VARIATION 3: MULTIPLE CONTROL VARIABLES
    // ========================================================

    cout << "=== VARIATION 3: Two Counters ===\n";

    for (int left = 0, right = 5;
         left < right;
         ++left, --right) {

        cout << left
             << ' '
             << right
             << '\n';
    }

    cout << '\n';


    // ========================================================
    // VARIATION 4: break ONLY LEAVES INNER LOOP
    // ========================================================

    cout << "=== VARIATION 4: Inner break ===\n";

    for (int row = 1; row <= 3; ++row) {

        for (int col = 1; col <= 3; ++col) {

            if (col == 2) {
                break;
            }

            cout << '('
                 << row
                 << ','
                 << col
                 << ") ";
        }

        cout << '\n';
    }

    cout << '\n';


    // ========================================================
    // VARIATION 5: CONTINUE
    // ========================================================

    cout << "=== VARIATION 5: Skip Multiples of 3 ===\n";

    for (int i = 1; i <= 10; ++i) {

        if (i % 3 == 0) {
            continue;
        }

        cout << i << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 6: TRIANGULAR LOOP
    // ========================================================

    cout << "=== VARIATION 6: Triangular Iterations ===\n";

    int executions = 0;

    for (int i = 1; i <= 4; ++i) {

        for (int j = 1; j <= i; ++j) {
            ++executions;
        }
    }

    cout << "body executions = "
         << executions
         << "\n\n";


    // ========================================================
    // VARIATION 7: LOGARITHMIC LOOP
    // ========================================================

    cout << "=== VARIATION 7: Doubling ===\n";

    int count = 0;

    for (int i = 1; i < 100; i *= 2) {
        cout << i << ' ';
        ++count;
    }

    cout << "\niterations = "
         << count
         << "\n\n";


    // ========================================================
    // VARIATION 8: DIGIT COUNT INCLUDING ZERO
    // ========================================================

    cout << "=== VARIATION 8: Digit Count ===\n";

    int number = 0;
    int digitCount = 0;

    if (number == 0) {
        digitCount = 1;
    } else {

        int temp = number;

        while (temp != 0) {
            ++digitCount;
            temp /= 10;
        }
    }

    cout << "digits in 0 = "
         << digitCount
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: while Can Run Zero Times ===
Loop finished

=== VARIATION 2: do-while ===
Runs once even though x < 5 is false

=== VARIATION 3: Two Counters ===
0 5
1 4
2 3

=== VARIATION 4: Inner break ===
(1,1)
(2,1)
(3,1)

=== VARIATION 5: Skip Multiples of 3 ===
1 2 4 5 7 8 10

=== VARIATION 6: Triangular Iterations ===
body executions = 10

=== VARIATION 7: Doubling ===
1 2 4 8 16 32 64
iterations = 7

=== VARIATION 8: Digit Count ===
digits in 0 = 1

WHAT'S NEXT:
01_C++__/08_FUNCTIONS/
*/
