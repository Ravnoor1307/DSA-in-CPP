/*
TOPIC: Function Overloading and Default Arguments
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;


// ============================================================
// PROBLEM 1: OVERLOAD MAXIMUM FOR INT AND DOUBLE
// ============================================================

int maximum(int a, int b) {

    return (a > b) ? a : b;
}


double maximum(
    double a,
    double b
) {
    return (a > b) ? a : b;
}


// ============================================================
// PROBLEM 2: TWO OR THREE INTEGER SUM
// ============================================================

int sum(int a, int b) {

    return a + b;
}


int sum(
    int a,
    int b,
    int c
) {
    return a + b + c;
}


// ============================================================
// PROBLEM 3: REPEAT WITH DEFAULT COUNT
// ============================================================

void repeat(
    char symbol,
    int count = 3
) {
    for (int i = 0; i < count; ++i) {
        cout << symbol;
    }

    cout << '\n';
}


// ============================================================
// PROBLEM 4: CALCULATE PRICE WITH DEFAULT QUANTITY
// ============================================================

double totalPrice(
    double unitPrice,
    int quantity = 1
) {
    return unitPrice * quantity;
}


// ============================================================
// PROBLEM 5: DEFAULT STARTING VALUE
// ============================================================

void countdown(
    int start = 5
) {
    for (int value = start;
         value >= 1;
         --value) {

        cout << value;

        if (value > 1) {
            cout << ' ';
        }
    }

    cout << '\n';
}


// ============================================================
// BONUS: OVERLOAD USING DELEGATION
// ============================================================

long long multiply(
    int a,
    int b
) {
    return 1LL * a * b;
}


long long multiply(
    int a,
    int b,
    int c
) {
    return multiply(a, b) * c;
}


int main() {

    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Maximum Overloads ===\n";

    cout << maximum(10, 20)
         << '\n';

    cout << maximum(4.5, 2.7)
         << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Sum Overloads ===\n";

    cout << sum(1, 2)
         << '\n';

    cout << sum(1, 2, 3)
         << "\n\n";


    // ========================================================
    // TEST 3
    // ========================================================

    cout << "=== PROBLEM 3: Default Repetition ===\n";

    repeat('*');
    repeat('#', 5);

    cout << '\n';


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Default Quantity ===\n";

    cout << totalPrice(10.5)
         << '\n';

    cout << totalPrice(10.5, 4)
         << "\n\n";


    // ========================================================
    // TEST 5
    // ========================================================

    cout << "=== PROBLEM 5: Countdown ===\n";

    countdown();
    countdown(3);

    cout << '\n';


    // ========================================================
    // BONUS
    // ========================================================

    cout << "=== BONUS: Multiply Overloads ===\n";

    cout << multiply(2, 3)
         << '\n';

    cout << multiply(2, 3, 4)
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Maximum Overloads ===
20
4.5

=== PROBLEM 2: Sum Overloads ===
3
6

=== PROBLEM 3: Default Repetition ===
***
#####

=== PROBLEM 4: Default Quantity ===
10.5
42

=== PROBLEM 5: Countdown ===
5 4 3 2 1
3 2 1

=== BONUS: Multiply Overloads ===
6
24


PRACTICE LINKS

1. GFG - Function Overloading
https://www.geeksforgeeks.org/function-overloading-c/

2. GFG - Default Arguments
https://www.geeksforgeeks.org/default-arguments-c/

3. HackerRank - Functions
https://www.hackerrank.com/challenges/c-tutorial-functions/problem

4. LeetCode 2235
https://leetcode.com/problems/add-two-integers/

5. LeetCode 2413
https://leetcode.com/problems/smallest-even-multiple/


WHAT'S NEXT:
01_C++__/12_ARRAYS_1D_2D/
*/
