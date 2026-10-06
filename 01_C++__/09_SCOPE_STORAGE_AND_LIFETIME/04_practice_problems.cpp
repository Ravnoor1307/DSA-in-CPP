/*
TOPIC: Scope, Storage Duration, and Lifetime
FILE: 04_practice_problems.cpp

These exercises focus on predicting state and visibility.

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;


// ============================================================
// GLOBAL STATE USED FOR DEMONSTRATION
// ============================================================

int globalCounter = 0;


// ============================================================
// PROBLEM 1 HELPER
// ============================================================

void automaticCounter() {

    int count = 0;

    ++count;

    cout << count;
}


// ============================================================
// PROBLEM 2 HELPER
// ============================================================

void staticCounter() {

    static int count = 0;

    ++count;

    cout << count;
}


// ============================================================
// PROBLEM 3 HELPER
// ============================================================

void incrementGlobal() {

    ++globalCounter;
}


// ============================================================
// MAIN
// ============================================================

int main() {


    // ========================================================
    // PROBLEM 1: AUTOMATIC LOCAL
    // ========================================================
    //
    // Predict:
    //
    // automaticCounter();
    // automaticCounter();
    //
    // Each call creates:
    //
    // count = 0
    //
    // Then increments it.
    //
    // Expected:
    //
    // 1 1

    cout << "=== PROBLEM 1: Automatic Local ===\n";

    automaticCounter();
    cout << ' ';
    automaticCounter();

    cout << "\n\n";


    // ========================================================
    // PROBLEM 2: STATIC LOCAL
    // ========================================================
    //
    // The same persistent object is reused.
    //
    // Expected:
    //
    // 1 2 3

    cout << "=== PROBLEM 2: Static Local ===\n";

    staticCounter();
    cout << ' ';

    staticCounter();
    cout << ' ';

    staticCounter();

    cout << "\n\n";


    // ========================================================
    // PROBLEM 3: GLOBAL STATE
    // ========================================================

    cout << "=== PROBLEM 3: Global State ===\n";

    cout << "before = "
         << globalCounter << '\n';

    incrementGlobal();
    incrementGlobal();

    cout << "after = "
         << globalCounter << "\n\n";


    // ========================================================
    // PROBLEM 4: SHADOWING
    // ========================================================
    //
    // Outer and inner x are separate objects.

    cout << "=== PROBLEM 4: Shadowing ===\n";

    int x = 10;

    cout << "outer before = "
         << x << '\n';

    {
        int x = 50;

        x += 10;

        cout << "inner = "
             << x << '\n';
    }

    cout << "outer after = "
         << x << "\n\n";


    // ========================================================
    // PROBLEM 5: NESTED SCOPE
    // ========================================================

    cout << "=== PROBLEM 5: Nested Scope ===\n";

    int a = 1;

    {
        int b = 2;

        {
            int c = 3;

            cout << "deep: "
                 << a << ' '
                 << b << ' '
                 << c << '\n';
        }

        cout << "middle: "
             << a << ' '
             << b << '\n';
    }

    cout << "outer: "
         << a << "\n\n";


    // ========================================================
    // BONUS: LOCAL OBJECT EACH ITERATION
    // ========================================================

    cout << "=== BONUS: Loop Lifetime ===\n";

    for (int i = 0; i < 3; ++i) {

        int local = 100 + i;

        cout << local << ' ';
    }

    cout << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Automatic Local ===
1 1

=== PROBLEM 2: Static Local ===
1 2 3

=== PROBLEM 3: Global State ===
before = 0
after = 2

=== PROBLEM 4: Shadowing ===
outer before = 10
inner = 60
outer after = 10

=== PROBLEM 5: Nested Scope ===
deep: 1 2 3
middle: 1 2
outer: 1

=== BONUS: Loop Lifetime ===
100 101 102


PRACTICE LINKS

1. GFG - Scope of Variables
https://www.geeksforgeeks.org/scope-of-variables-in-c/

2. cppreference - Scope
https://en.cppreference.com/w/cpp/language/scope

3. cppreference - Storage Duration
https://en.cppreference.com/w/cpp/language/storage_duration

4. HackerRank - Functions
https://www.hackerrank.com/challenges/c-tutorial-functions/problem

5. LeetCode 2235
https://leetcode.com/problems/add-two-integers/


WHAT'S NEXT:
01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/
*/
