/*
TOPIC: Loops
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice

Suggested input:
5
482
*/

#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    int number{};

    cin >> n >> number;


    // ========================================================
    // PROBLEM 1: SUM 1 TO N
    // ========================================================
    //
    // n = 5
    //
    // 1 + 2 + 3 + 4 + 5 = 15

    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << "=== PROBLEM 1: Sum 1..N ===\n";
    cout << sum << "\n\n";


    // ========================================================
    // PROBLEM 2: FACTORIAL
    // ========================================================
    //
    // For n = 5:
    //
    // 5! = 120
    //
    // Intended only for small non-negative n because factorial
    // grows faster than fixed-width integer types can hold.

    long long factorial = 1;

    for (int i = 2; i <= n; ++i) {
        factorial *= i;
    }

    cout << "=== PROBLEM 2: Factorial ===\n";
    cout << factorial << "\n\n";


    // ========================================================
    // PROBLEM 3: SUM OF DIGITS
    // ========================================================
    //
    // number = 482
    //
    // digit = 2
    // sum = 2
    //
    // digit = 8
    // sum = 10
    //
    // digit = 4
    // sum = 14

    int temp = number;
    int digitSum = 0;

    // This also produces 0 correctly when number == 0.
    //
    // The example is intended for non-negative values.
    while (temp > 0) {

        int digit =
            temp % 10;

        digitSum += digit;
        temp /= 10;
    }

    cout << "=== PROBLEM 3: Sum of Digits ===\n";
    cout << digitSum << "\n\n";


    // ========================================================
    // PROBLEM 4: COUNT DIGITS
    // ========================================================

    temp = number;

    int digits = 0;

    if (temp == 0) {

        digits = 1;

    } else {

        while (temp > 0) {
            ++digits;
            temp /= 10;
        }
    }

    cout << "=== PROBLEM 4: Digit Count ===\n";
    cout << digits << "\n\n";


    // ========================================================
    // PROBLEM 5: MULTIPLICATION TABLE
    // ========================================================
    //
    // Print the first 10 multiples of n.

    cout << "=== PROBLEM 5: Multiplication Table ===\n";

    for (int i = 1; i <= 10; ++i) {

        cout << n
             << " * "
             << i
             << " = "
             << 1LL * n * i
             << '\n';
    }

    cout << '\n';


    // ========================================================
    // BONUS 1: REVERSE A POSITIVE INTEGER
    // ========================================================
    //
    // This simple version assumes the reversed value fits in
    // long long.

    temp = number;

    long long reversed = 0;

    while (temp > 0) {

        int digit =
            temp % 10;

        reversed =
            reversed * 10 + digit;

        temp /= 10;
    }

    cout << "=== BONUS 1: Reverse ===\n";
    cout << reversed << "\n\n";


    // ========================================================
    // BONUS 2: N x N PATTERN
    // ========================================================

    cout << "=== BONUS 2: Square Pattern ===\n";

    for (int row = 0; row < n; ++row) {

        for (int col = 0; col < n; ++col) {
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}


/*
SUGGESTED INPUT

5
482


EXPECTED OUTPUT

=== PROBLEM 1: Sum 1..N ===
15

=== PROBLEM 2: Factorial ===
120

=== PROBLEM 3: Sum of Digits ===
14

=== PROBLEM 4: Digit Count ===
3

=== PROBLEM 5: Multiplication Table ===
5 * 1 = 5
5 * 2 = 10
5 * 3 = 15
5 * 4 = 20
5 * 5 = 25
5 * 6 = 30
5 * 7 = 35
5 * 8 = 40
5 * 9 = 45
5 * 10 = 50

=== BONUS 1: Reverse ===
284

=== BONUS 2: Square Pattern ===
*****
*****
*****
*****
*****


PRACTICE LINKS

1. LeetCode 412 - Fizz Buzz
https://leetcode.com/problems/fizz-buzz/

2. LeetCode 1281 - Subtract Product and Sum
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

3. LeetCode 1342 - Number of Steps
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

4. GFG - Loops in C++
https://www.geeksforgeeks.org/cpp-loops/

5. HackerRank - For Loop
https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem


WHAT'S NEXT:
01_C++__/08_FUNCTIONS/
*/
