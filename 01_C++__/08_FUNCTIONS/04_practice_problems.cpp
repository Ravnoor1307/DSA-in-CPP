/*
TOPIC: Functions
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


// ============================================================
// PROBLEM 1: ADD TWO INTEGERS
// ============================================================

int add(int a, int b) {

    return a + b;
}


// ============================================================
// PROBLEM 2: EVEN CHECK
// ============================================================

bool isEven(int number) {

    return number % 2 == 0;
}


// ============================================================
// PROBLEM 3: SUM 1..N
// ============================================================

long long sumToN(int n) {

    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    return sum;
}


// ============================================================
// PROBLEM 4: FACTORIAL
// ============================================================
//
// Intended for small non-negative inputs.
//
// Fixed-width integer overflow occurs quickly for factorials.

long long factorial(int n) {

    long long result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}


// ============================================================
// PROBLEM 5: SUM OF DIGITS
// ============================================================
//
// This implementation is intended for non-negative integers.

int digitSum(int number) {

    int sum = 0;

    while (number > 0) {

        sum += number % 10;

        number /= 10;
    }

    return sum;
}


// ============================================================
// BONUS: MAXIMUM OF THREE
// ============================================================

int maximumOfThree(int a, int b, int c) {

    int result = a;

    if (b > result) {
        result = b;
    }

    if (c > result) {
        result = c;
    }

    return result;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << boolalpha;

    int n{};
    int number{};

    cin >> n >> number;


    // ========================================================
    // TEST PROBLEM 1
    // ========================================================

    cout << "=== PROBLEM 1: Add ===\n";

    cout << "add(10, 20) = "
         << add(10, 20)
         << "\n\n";


    // ========================================================
    // TEST PROBLEM 2
    // ========================================================

    cout << "=== PROBLEM 2: Even Check ===\n";

    cout << n
         << " is even: "
         << isEven(n)
         << "\n\n";


    // ========================================================
    // TEST PROBLEM 3
    // ========================================================

    cout << "=== PROBLEM 3: Sum 1..N ===\n";

    cout << sumToN(n)
         << "\n\n";


    // ========================================================
    // TEST PROBLEM 4
    // ========================================================

    cout << "=== PROBLEM 4: Factorial ===\n";

    cout << factorial(n)
         << "\n\n";


    // ========================================================
    // TEST PROBLEM 5
    // ========================================================

    cout << "=== PROBLEM 5: Digit Sum ===\n";

    cout << digitSum(number)
         << "\n\n";


    // ========================================================
    // BONUS
    // ========================================================

    cout << "=== BONUS: Maximum of Three ===\n";

    cout << maximumOfThree(20, 50, 30)
         << '\n';

    return 0;
}


/*
SUGGESTED INPUT

5
482


EXPECTED OUTPUT

=== PROBLEM 1: Add ===
add(10, 20) = 30

=== PROBLEM 2: Even Check ===
5 is even: false

=== PROBLEM 3: Sum 1..N ===
15

=== PROBLEM 4: Factorial ===
120

=== PROBLEM 5: Digit Sum ===
14

=== BONUS: Maximum of Three ===
50


PRACTICE LINKS

1. HackerRank Functions
https://www.hackerrank.com/challenges/c-tutorial-functions/problem

2. GFG Functions in C++
https://www.geeksforgeeks.org/functions-in-cpp/

3. LeetCode 2235
https://leetcode.com/problems/add-two-integers/

4. LeetCode 2413
https://leetcode.com/problems/smallest-even-multiple/

5. LeetCode 1281
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/


WHAT'S NEXT:
01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/
*/
