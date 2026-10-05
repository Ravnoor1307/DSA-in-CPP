/*
TOPIC: Operators
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice

Suggested input:
17 5
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a{};
    int b{};

    cin >> a >> b;


    // ========================================================
    // PROBLEM 1: BASIC CALCULATOR
    // ========================================================
    //
    // Suggested:
    //
    // a = 17
    // b = 5
    //
    // Results:
    //
    // sum        = 22
    // difference = 12
    // product    = 85
    //
    // b is nonzero in the suggested input, so division and
    // remainder are safe here.

    cout << "=== PROBLEM 1: Arithmetic ===\n";

    cout << "sum = " << a + b << '\n';
    cout << "difference = " << a - b << '\n';
    cout << "product = " << a * b << '\n';
    cout << "quotient = " << a / b << '\n';
    cout << "remainder = " << a % b << "\n\n";


    // ========================================================
    // PROBLEM 2: PRECISE DIVISION
    // ========================================================
    //
    // Convert before dividing.

    double division =
        static_cast<double>(a) / b;

    cout << "=== PROBLEM 2: Floating Division ===\n";

    cout << fixed
         << setprecision(2)
         << division
         << "\n\n";

    cout << defaultfloat;


    // ========================================================
    // PROBLEM 3: DIVISIBILITY EXPRESSION
    // ========================================================
    //
    // A number is divisible by b when:
    //
    //     a % b == 0
    //
    // Again, b must not be zero.

    bool divisible =
        (a % b == 0);

    cout << "=== PROBLEM 3: Divisibility ===\n";

    cout << boolalpha
         << divisible
         << "\n\n";


    // ========================================================
    // PROBLEM 4: RANGE TEST
    // ========================================================
    //
    // Is a between 1 and 100 inclusive?

    bool inRange =
        a >= 1 && a <= 100;

    cout << "=== PROBLEM 4: Range ===\n";

    cout << inRange << "\n\n";


    // ========================================================
    // PROBLEM 5: MINIMUM USING ?:
    // ========================================================

    int minimum =
        (a < b) ? a : b;

    cout << "=== PROBLEM 5: Minimum ===\n";

    cout << minimum << "\n\n";


    // ========================================================
    // BONUS 1: PREFIX/POSTFIX DRY RUN
    // ========================================================
    //
    // Start:
    //
    // x = 4
    //
    // old = x++
    //
    // old = 4
    // x   = 5
    //
    // newer = ++x
    //
    // x     = 6
    // newer = 6

    int x = 4;

    int old = x++;
    int newer = ++x;

    cout << "=== BONUS 1: Increment ===\n";

    cout << "x = " << x << '\n';
    cout << "old = " << old << '\n';
    cout << "newer = " << newer << "\n\n";


    // ========================================================
    // BONUS 2: SAFE WIDE MULTIPLICATION
    // ========================================================

    int width = 100'000;
    int height = 100'000;

    long long area =
        1LL * width * height;

    cout << "=== BONUS 2: Wide Multiplication ===\n";

    cout << area << '\n';

    return 0;
}


/*
SUGGESTED INPUT

17 5


EXPECTED OUTPUT

=== PROBLEM 1: Arithmetic ===
sum = 22
difference = 12
product = 85
quotient = 3
remainder = 2

=== PROBLEM 2: Floating Division ===
3.40

=== PROBLEM 3: Divisibility ===
false

=== PROBLEM 4: Range ===
true

=== PROBLEM 5: Minimum ===
5

=== BONUS 1: Increment ===
x = 6
old = 4
newer = 6

=== BONUS 2: Wide Multiplication ===
10000000000


PRACTICE LINKS

1. LeetCode 2235:
https://leetcode.com/problems/add-two-integers/

2. LeetCode 2413:
https://leetcode.com/problems/smallest-even-multiple/

3. LeetCode 1281:
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

4. GFG Operators:
https://www.geeksforgeeks.org/operators-in-cpp/

5. HackerRank Operators:
https://www.hackerrank.com/challenges/30-operators/problem


WHAT'S NEXT:
01_C++__/06_CONDITIONALS/
*/
