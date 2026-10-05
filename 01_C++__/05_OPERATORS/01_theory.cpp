/*
TOPIC: Operators

Covers:
- Arithmetic operators
- Integer vs floating division
- Remainder
- Assignment
- Compound assignment
- Prefix/postfix increment and decrement
- Comparison operators
- Logical operators
- Short-circuit evaluation
- Conditional operator
- Precedence
- Associativity
- sizeof
- Expression-type/overflow awareness

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>
#include <iomanip>

using namespace std;


// ========== SECTION 1: ARITHMETIC OPERATORS ==========
//
// + addition
// - subtraction
// * multiplication
// / division
// % integer remainder


// ========== SECTION 2: INTEGER DIVISION ==========
//
// int / int performs integer division.
//
//     7 / 2 -> 3
//
// Division truncates toward zero.
//
// To obtain 3.5:
//
//     static_cast<double>(7) / 2


// ========== SECTION 3: REMAINDER ==========
//
//     17 / 5 -> 3
//     17 % 5 -> 2
//
// Relationship:
//
//     17 = 3 * 5 + 2
//
// % is useful for divisibility, cycles, digits, and modular
// arithmetic.
//
// Integer division/remainder by zero is invalid.


// ========== SECTION 4: ASSIGNMENT ==========
//
// Assignment:
//
//     x = 10;
//
// Equality test:
//
//     x == 10
//
// They are different operators.


// ========== SECTION 5: COMPOUND ASSIGNMENT ==========
//
//     x += 5;
//     x -= 5;
//     x *= 5;
//     x /= 5;
//     x %= 5;


// ========== SECTION 6: PREFIX AND POSTFIX ==========
//
// Prefix:
//
//     ++x
//
// increments and yields the updated value.
//
// Postfix:
//
//     x++
//
// yields the old value while incrementing x as part of the
// expression.


// ========== SECTION 7: COMPARISONS ==========
//
// ==
// !=
// <
// >
// <=
// >=
//
// Comparison results are bool values.


// ========== SECTION 8: LOGICAL OPERATORS ==========
//
// && logical AND
// || logical OR
// !  logical NOT


// ========== SECTION 9: SHORT CIRCUITING ==========
//
// false && right
//
// does not evaluate right.
//
// true || right
//
// does not evaluate right.
//
// This becomes essential for safe boundary checks.


// ========== SECTION 10: CONDITIONAL OPERATOR ==========
//
// Syntax:
//
//     condition ? trueValue : falseValue
//
// Example:
//
//     int smaller = (a < b) ? a : b;


// ========== SECTION 11: PRECEDENCE ==========
//
// Multiplication binds more strongly than addition:
//
//     2 + 3 * 4
//
// groups as:
//
//     2 + (3 * 4)
//
// Parentheses explicitly change grouping.


// ========== SECTION 12: ASSOCIATIVITY ==========
//
// Subtraction associates left:
//
//     a - b - c
//
// means:
//
//     (a - b) - c
//
// Assignment associates right:
//
//     a = b = 5;
//
// roughly groups:
//
//     a = (b = 5);


// ========== SECTION 13: EVALUATION ORDER ==========
//
// Precedence and evaluation order are different concepts.
//
// Do not infer the exact runtime order of all operands merely
// from an operator precedence table.
//
// Prefer separate statements when side effects are involved.


// ========== SECTION 14: EXPRESSION TYPE MATTERS ==========
//
//     int a = 100000;
//     int b = 100000;
//
//     long long product = a * b;
//
// can overflow BEFORE assignment.
//
// Safer when wider arithmetic is required:
//
//     long long product = 1LL * a * b;


int main() {

    cout << boolalpha;


    cout << "=== DEMO 1: Arithmetic ===\n";

    int a = 17;
    int b = 5;

    cout << "17 + 5 = " << a + b << '\n';
    cout << "17 - 5 = " << a - b << '\n';
    cout << "17 * 5 = " << a * b << '\n';
    cout << "17 / 5 = " << a / b << '\n';
    cout << "17 % 5 = " << a % b << "\n\n";


    cout << "=== DEMO 2: Integer vs Floating Division ===\n";

    double integerFirst = 7 / 2;

    double floatingFirst =
        static_cast<double>(7) / 2;

    cout << fixed << setprecision(1);

    cout << "7 / 2 assigned to double = "
         << integerFirst << '\n';

    cout << "cast before division = "
         << floatingFirst << "\n\n";

    cout << defaultfloat;


    cout << "=== DEMO 3: Compound Assignment ===\n";

    int x = 10;

    cout << "start x = " << x << '\n';

    x += 5;
    cout << "after x += 5: " << x << '\n';

    x *= 2;
    cout << "after x *= 2: " << x << '\n';

    x -= 4;
    cout << "after x -= 4: " << x << "\n\n";


    cout << "=== DEMO 4: Prefix Increment ===\n";

    int prefixX = 5;
    int prefixResult = ++prefixX;

    cout << "x = " << prefixX << '\n';
    cout << "result = " << prefixResult << "\n\n";


    cout << "=== DEMO 5: Postfix Increment ===\n";

    int postfixX = 5;
    int postfixResult = postfixX++;

    cout << "x = " << postfixX << '\n';
    cout << "result = " << postfixResult << "\n\n";


    cout << "=== DEMO 6: Comparisons ===\n";

    int p = 5;
    int q = 10;

    cout << "5 == 10: " << (p == q) << '\n';
    cout << "5 != 10: " << (p != q) << '\n';
    cout << "5 < 10: " << (p < q) << '\n';
    cout << "5 > 10: " << (p > q) << '\n';
    cout << "5 <= 10: " << (p <= q) << '\n';
    cout << "5 >= 10: " << (p >= q) << "\n\n";


    cout << "=== DEMO 7: Logical Operators ===\n";

    bool first = true;
    bool second = false;

    cout << "true && false: "
         << (first && second) << '\n';

    cout << "true || false: "
         << (first || second) << '\n';

    cout << "!true: "
         << (!first) << "\n\n";


    cout << "=== DEMO 8: Short-Circuit AND ===\n";

    int andCounter = 0;

    bool andResult =
        false && (++andCounter > 0);

    cout << "result = " << andResult << '\n';
    cout << "counter = " << andCounter << "\n\n";


    cout << "=== DEMO 9: Short-Circuit OR ===\n";

    int orCounter = 0;

    bool orResult =
        true || (++orCounter > 0);

    cout << "result = " << orResult << '\n';
    cout << "counter = " << orCounter << "\n\n";


    cout << "=== DEMO 10: Conditional Operator ===\n";

    int left = 10;
    int right = 20;

    int smaller =
        (left < right) ? left : right;

    cout << "smaller = "
         << smaller << "\n\n";


    cout << "=== DEMO 11: Precedence ===\n";

    int normal = 2 + 3 * 4;
    int parenthesized = (2 + 3) * 4;

    cout << "2 + 3 * 4 = "
         << normal << '\n';

    cout << "(2 + 3) * 4 = "
         << parenthesized << "\n\n";


    cout << "=== DEMO 12: Assignment Associativity ===\n";

    int m = 0;
    int n = 0;

    m = n = 5;

    cout << "m = " << m << '\n';
    cout << "n = " << n << "\n\n";


    cout << "=== DEMO 13: Wide Arithmetic ===\n";

    int width = 100'000;
    int height = 100'000;

    long long area =
        1LL * width * height;

    cout << "area = "
         << area << "\n\n";


    cout << "=== DEMO 14: sizeof Unevaluated Operand ===\n";

    int value = 5;

    auto bytes = sizeof(value++);

    cout << "sizeof expression = "
         << bytes << '\n';

    cout << "value remains = "
         << value << '\n';

    return 0;
}


/*
EXPECTED OUTPUT ON A COMMON SYSTEM

=== DEMO 1: Arithmetic ===
17 + 5 = 22
17 - 5 = 12
17 * 5 = 85
17 / 5 = 3
17 % 5 = 2

=== DEMO 2: Integer vs Floating Division ===
7 / 2 assigned to double = 3.0
cast before division = 3.5

=== DEMO 3: Compound Assignment ===
start x = 10
after x += 5: 15
after x *= 2: 30
after x -= 4: 26

=== DEMO 4: Prefix Increment ===
x = 6
result = 6

=== DEMO 5: Postfix Increment ===
x = 6
result = 5

=== DEMO 6: Comparisons ===
5 == 10: false
5 != 10: true
5 < 10: true
5 > 10: false
5 <= 10: true
5 >= 10: false

=== DEMO 7: Logical Operators ===
true && false: false
true || false: true
!true: false

=== DEMO 8: Short-Circuit AND ===
result = false
counter = 0

=== DEMO 9: Short-Circuit OR ===
result = true
counter = 0

=== DEMO 10: Conditional Operator ===
smaller = 10

=== DEMO 11: Precedence ===
2 + 3 * 4 = 14
(2 + 3) * 4 = 20

=== DEMO 12: Assignment Associativity ===
m = 5
n = 5

=== DEMO 13: Wide Arithmetic ===
area = 10000000000

=== DEMO 14: sizeof Unevaluated Operand ===
sizeof expression = 4
value remains = 5

sizeof(int) is implementation-dependent, so DEMO 14 may report a
different byte count on another conforming implementation.

WHAT'S NEXT:
01_C++__/06_CONDITIONALS/
*/
