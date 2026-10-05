/*
TOPIC: Conditionals
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
    ./basics

Suggested input:
17
85
*/

#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int number{};
    int score{};

    cin >> number >> score;


    // ========================================================
    // BASIC 1: POSITIVE / NEGATIVE / ZERO
    // ========================================================

    cout << "=== BASIC 1: Sign ===\n";

    if (number > 0) {
        cout << "Positive\n";
    } else if (number < 0) {
        cout << "Negative\n";
    } else {
        cout << "Zero\n";
    }

    cout << '\n';


    // ========================================================
    // BASIC 2: EVEN / ODD
    // ========================================================

    cout << "=== BASIC 2: Even or Odd ===\n";

    if (number % 2 == 0) {
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }

    cout << '\n';


    // ========================================================
    // BASIC 3: RANGE CHECK
    // ========================================================

    cout << "=== BASIC 3: Score Validity ===\n";

    if (score >= 0 && score <= 100) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }

    cout << '\n';


    // ========================================================
    // BASIC 4: GRADE CLASSIFICATION
    // ========================================================

    cout << "=== BASIC 4: Grade ===\n";

    if (score >= 90) {
        cout << "A\n";
    } else if (score >= 80) {
        cout << "B\n";
    } else if (score >= 70) {
        cout << "C\n";
    } else if (score >= 60) {
        cout << "D\n";
    } else {
        cout << "F\n";
    }

    cout << '\n';


    // ========================================================
    // BASIC 5: MULTIPLE INDEPENDENT PROPERTIES
    // ========================================================

    cout << "=== BASIC 5: Independent if Statements ===\n";

    if (number > 0) {
        cout << "Number is positive\n";
    }

    if (number % 2 != 0) {
        cout << "Number is odd\n";
    }

    cout << '\n';


    // ========================================================
    // BASIC 6: CONDITIONAL OPERATOR
    // ========================================================

    int absoluteLike =
        (number >= 0)
            ? number
            : -number;

    // Note:
    // Negating the minimum representable signed int would overflow.
    // The suggested input is small and safe.

    cout << "=== BASIC 6: Conditional Operator ===\n";

    cout << "Magnitude for this safe input = "
         << absoluteLike
         << '\n';

    return 0;
}


/*
SUGGESTED INPUT

17
85


EXPECTED OUTPUT

=== BASIC 1: Sign ===
Positive

=== BASIC 2: Even or Odd ===
Odd

=== BASIC 3: Score Validity ===
Valid

=== BASIC 4: Grade ===
B

=== BASIC 5: Independent if Statements ===
Number is positive
Number is odd

=== BASIC 6: Conditional Operator ===
Magnitude for this safe input = 17

WHAT'S NEXT:
01_C++__/07_LOOPS/
*/
