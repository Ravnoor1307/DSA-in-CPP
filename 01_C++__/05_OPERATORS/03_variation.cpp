/*
TOPIC: Operators
FILE: 03_variation.cpp

Purpose:
Study important operator variations and common traps.

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
    // VARIATION 1: NEGATIVE INTEGER DIVISION
    // ========================================================

    cout << "=== VARIATION 1: Negative Division ===\n";

    cout << "-7 / 3 = " << (-7 / 3) << '\n';
    cout << "-7 % 3 = " << (-7 % 3) << '\n';

    cout << "7 / -3 = " << (7 / -3) << '\n';
    cout << "7 % -3 = " << (7 % -3) << "\n\n";


    // ========================================================
    // VARIATION 2: PREFIX / POSTFIX
    // ========================================================

    int x = 5;
    int a = x++;
    int b = ++x;

    cout << "=== VARIATION 2: Prefix/Postfix Dry Run ===\n";

    cout << "x = " << x << '\n';
    cout << "a = " << a << '\n';
    cout << "b = " << b << "\n\n";


    // ========================================================
    // VARIATION 3: ASSIGNMENT CHAIN
    // ========================================================

    int first = 0;
    int second = 0;
    int third = 0;

    first = second = third = 25;

    cout << "=== VARIATION 3: Assignment Chain ===\n";

    cout << first << ' '
         << second << ' '
         << third << "\n\n";


    // ========================================================
    // VARIATION 4: SHORT-CIRCUIT CAN PREVENT SIDE EFFECT
    // ========================================================

    int andValue = 0;

    bool result1 =
        false && (++andValue == 1);

    cout << "=== VARIATION 4: Short-Circuit AND ===\n";

    cout << "result = " << result1 << '\n';
    cout << "andValue = " << andValue << "\n\n";


    int orValue = 0;

    bool result2 =
        true || (++orValue == 1);

    cout << "=== VARIATION 5: Short-Circuit OR ===\n";

    cout << "result = " << result2 << '\n';
    cout << "orValue = " << orValue << "\n\n";


    // ========================================================
    // VARIATION 6: CHAINED COMPARISON TRAP
    // ========================================================
    //
    // Do NOT use:
    //
    //     0 < value < 10
    //
    // as mathematical chained-comparison syntax.
    //
    // Correct:
    //
    //     0 < value && value < 10

    int value = 7;

    bool correctRange =
        0 < value && value < 10;

    cout << "=== VARIATION 6: Range Check ===\n";

    cout << "0 < 7 && 7 < 10: "
         << correctRange << "\n\n";


    // ========================================================
    // VARIATION 7: CONDITIONAL OPERATOR
    // ========================================================

    int p = 30;
    int q = 12;

    int maximum =
        (p > q) ? p : q;

    cout << "=== VARIATION 7: Conditional Operator ===\n";

    cout << "maximum = " << maximum << "\n\n";


    // ========================================================
    // VARIATION 8: WIDE EXPRESSION
    // ========================================================

    int width = 100'000;
    int height = 100'000;

    long long area =
        1LL * width * height;

    cout << "=== VARIATION 8: Expression Type ===\n";

    cout << "area = " << area << "\n\n";


    // ========================================================
    // VARIATION 9: COMMA OPERATOR AWARENESS
    // ========================================================
    //
    // Parentheses force this to be the comma operator.
    //
    // The left expression is evaluated, followed by the right.
    // The overall value is the right operand's value.
    //
    // It is rarely needed in beginner DSA.

    int commaResult = (10, 20);

    cout << "=== VARIATION 9: Comma Operator ===\n";

    cout << "result = " << commaResult << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Negative Division ===
-7 / 3 = -2
-7 % 3 = -1
7 / -3 = -2
7 % -3 = 1

=== VARIATION 2: Prefix/Postfix Dry Run ===
x = 7
a = 5
b = 7

=== VARIATION 3: Assignment Chain ===
25 25 25

=== VARIATION 4: Short-Circuit AND ===
result = false
andValue = 0

=== VARIATION 5: Short-Circuit OR ===
result = true
orValue = 0

=== VARIATION 6: Range Check ===
0 < 7 && 7 < 10: true

=== VARIATION 7: Conditional Operator ===
maximum = 30

=== VARIATION 8: Expression Type ===
area = 10000000000

=== VARIATION 9: Comma Operator ===
result = 20

WHAT'S NEXT:
01_C++__/06_CONDITIONALS/
*/
