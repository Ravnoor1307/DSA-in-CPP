/*
TOPIC: Conditionals
FILE: 03_variation.cpp

Purpose:
Important conditional variations and classic edge cases.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;

int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: ORDER OF CONDITIONS
    // ========================================================

    int score = 95;

    cout << "=== VARIATION 1: Correct Threshold Order ===\n";

    if (score >= 90) {
        cout << "Excellent\n";
    } else if (score >= 60) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }

    cout << '\n';


    // ========================================================
    // VARIATION 2: INDEPENDENT IF VS CHAIN
    // ========================================================

    int x = 10;

    cout << "=== VARIATION 2: Independent if ===\n";

    if (x > 0) {
        cout << "Positive\n";
    }

    if (x % 2 == 0) {
        cout << "Even\n";
    }

    cout << '\n';


    cout << "=== VARIATION 3: else-if Chain ===\n";

    if (x > 0) {
        cout << "Positive\n";
    } else if (x % 2 == 0) {
        cout << "Even\n";
    }

    cout << '\n';


    // ========================================================
    // VARIATION 4: CORRECT OR EXPRESSION
    // ========================================================

    char choice = 'Y';

    bool yes =
        choice == 'y' ||
        choice == 'Y';

    cout << "=== VARIATION 4: Multiple Accepted Values ===\n";
    cout << "accepted = " << yes << "\n\n";


    // ========================================================
    // VARIATION 5: MAXIMUM OF THREE
    // ========================================================

    int a = 20;
    int b = 50;
    int c = 30;

    cout << "=== VARIATION 5: Maximum of Three ===\n";

    if (a >= b && a >= c) {
        cout << a << '\n';
    } else if (b >= a && b >= c) {
        cout << b << '\n';
    } else {
        cout << c << '\n';
    }

    cout << '\n';


    // ========================================================
    // VARIATION 6: LEAP YEAR
    // ========================================================

    int year = 2000;

    bool leap =
        year % 400 == 0 ||
        (year % 4 == 0 &&
         year % 100 != 0);

    cout << "=== VARIATION 6: Leap Year ===\n";
    cout << leap << "\n\n";


    // ========================================================
    // VARIATION 7: SWITCH FALLTHROUGH
    // ========================================================

    int level = 1;

    cout << "=== VARIATION 7: Intentional Fallthrough ===\n";

    switch (level) {
        case 1:
            cout << "Level 1 reached\n";
            [[fallthrough]];

        case 2:
            cout << "Level 2 code reached\n";
            break;

        default:
            cout << "Other\n";
            break;
    }

    cout << '\n';


    // ========================================================
    // VARIATION 8: GROUPED SWITCH CASES
    // ========================================================

    char command = 'S';

    cout << "=== VARIATION 8: Grouped Cases ===\n";

    switch (command) {
        case 's':
        case 'S':
            cout << "Start\n";
            break;

        case 'q':
        case 'Q':
            cout << "Quit\n";
            break;

        default:
            cout << "Unknown\n";
            break;
    }

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Correct Threshold Order ===
Excellent

=== VARIATION 2: Independent if ===
Positive
Even

=== VARIATION 3: else-if Chain ===
Positive

=== VARIATION 4: Multiple Accepted Values ===
accepted = true

=== VARIATION 5: Maximum of Three ===
50

=== VARIATION 6: Leap Year ===
true

=== VARIATION 7: Intentional Fallthrough ===
Level 1 reached
Level 2 code reached

=== VARIATION 8: Grouped Cases ===
Start

WHAT'S NEXT:
01_C++__/07_LOOPS/
*/
