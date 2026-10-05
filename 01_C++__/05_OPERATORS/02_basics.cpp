/*
TOPIC: Operators
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << boolalpha;


    // ========================================================
    // BASIC 1: ARITHMETIC
    // ========================================================

    int a = 20;
    int b = 6;

    cout << "=== BASIC 1: Arithmetic ===\n";

    cout << "a + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';
    cout << "a / b = " << a / b << '\n';
    cout << "a % b = " << a % b << "\n\n";


    // ========================================================
    // BASIC 2: FLOATING DIVISION
    // ========================================================

    double quotient =
        static_cast<double>(a) / b;

    cout << "=== BASIC 2: Floating Division ===\n";

    cout << fixed << setprecision(3);
    cout << "20 / 6 = " << quotient << "\n\n";

    cout << defaultfloat;


    // ========================================================
    // BASIC 3: COMPOUND ASSIGNMENT
    // ========================================================

    int score = 10;

    score += 5;
    score *= 2;

    cout << "=== BASIC 3: Compound Assignment ===\n";
    cout << "score = " << score << "\n\n";


    // ========================================================
    // BASIC 4: INCREMENT / DECREMENT
    // ========================================================

    int count = 5;

    ++count;
    cout << "=== BASIC 4: Increment/Decrement ===\n";
    cout << "after ++count: " << count << '\n';

    --count;
    cout << "after --count: " << count << "\n\n";


    // ========================================================
    // BASIC 5: PREFIX VS POSTFIX
    // ========================================================

    int x = 10;
    int oldValue = x++;

    int y = 10;
    int newValue = ++y;

    cout << "=== BASIC 5: Prefix vs Postfix ===\n";

    cout << "x = " << x
         << ", oldValue = " << oldValue << '\n';

    cout << "y = " << y
         << ", newValue = " << newValue << "\n\n";


    // ========================================================
    // BASIC 6: COMPARISONS
    // ========================================================

    int first = 7;
    int second = 9;

    cout << "=== BASIC 6: Comparisons ===\n";

    cout << "7 == 9: " << (first == second) << '\n';
    cout << "7 != 9: " << (first != second) << '\n';
    cout << "7 < 9: " << (first < second) << '\n';
    cout << "7 >= 9: " << (first >= second) << "\n\n";


    // ========================================================
    // BASIC 7: LOGICAL OPERATORS
    // ========================================================

    bool hasID = true;
    bool hasTicket = false;

    cout << "=== BASIC 7: Logical Operators ===\n";

    cout << "Both: "
         << (hasID && hasTicket) << '\n';

    cout << "Either: "
         << (hasID || hasTicket) << '\n';

    cout << "Not hasID: "
         << (!hasID) << "\n\n";


    // ========================================================
    // BASIC 8: PRECEDENCE
    // ========================================================

    int withoutParentheses =
        10 + 2 * 3;

    int withParentheses =
        (10 + 2) * 3;

    cout << "=== BASIC 8: Precedence ===\n";

    cout << "10 + 2 * 3 = "
         << withoutParentheses << '\n';

    cout << "(10 + 2) * 3 = "
         << withParentheses << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Arithmetic ===
a + b = 26
a - b = 14
a * b = 120
a / b = 3
a % b = 2

=== BASIC 2: Floating Division ===
20 / 6 = 3.333

=== BASIC 3: Compound Assignment ===
score = 30

=== BASIC 4: Increment/Decrement ===
after ++count: 6
after --count: 5

=== BASIC 5: Prefix vs Postfix ===
x = 11, oldValue = 10
y = 11, newValue = 11

=== BASIC 6: Comparisons ===
7 == 9: false
7 != 9: true
7 < 9: true
7 >= 9: false

=== BASIC 7: Logical Operators ===
Both: false
Either: true
Not hasID: false

=== BASIC 8: Precedence ===
10 + 2 * 3 = 16
(10 + 2) * 3 = 36

WHAT'S NEXT:
01_C++__/06_CONDITIONALS/
*/
