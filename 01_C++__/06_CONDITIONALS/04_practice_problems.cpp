/*
TOPIC: Conditionals
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice

Suggested input:
7
81
2024
25 40 15
2
*/

#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // ========================================================
    // PROBLEM 1: EVEN OR ODD
    // ========================================================

    int number{};
    cin >> number;

    cout << "=== PROBLEM 1: Even/Odd ===\n";

    if (number % 2 == 0) {
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }

    cout << '\n';


    // ========================================================
    // PROBLEM 2: GRADE
    // ========================================================

    int score{};
    cin >> score;

    cout << "=== PROBLEM 2: Grade ===\n";

    if (score < 0 || score > 100) {
        cout << "Invalid\n";
    } else if (score >= 90) {
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
    // PROBLEM 3: LEAP YEAR
    // ========================================================

    int year{};
    cin >> year;

    bool leap =
        year % 400 == 0 ||
        (year % 4 == 0 &&
         year % 100 != 0);

    cout << "=== PROBLEM 3: Leap Year ===\n";

    if (leap) {
        cout << "Leap\n";
    } else {
        cout << "Not Leap\n";
    }

    cout << '\n';


    // ========================================================
    // PROBLEM 4: MAXIMUM OF THREE
    // ========================================================

    int a{};
    int b{};
    int c{};

    cin >> a >> b >> c;

    cout << "=== PROBLEM 4: Maximum ===\n";

    if (a >= b && a >= c) {
        cout << a << '\n';
    } else if (b >= a && b >= c) {
        cout << b << '\n';
    } else {
        cout << c << '\n';
    }

    cout << '\n';


    // ========================================================
    // PROBLEM 5: SIMPLE MENU WITH SWITCH
    // ========================================================

    int option{};
    cin >> option;

    cout << "=== PROBLEM 5: Menu ===\n";

    switch (option) {
        case 1:
            cout << "Create\n";
            break;

        case 2:
            cout << "Read\n";
            break;

        case 3:
            cout << "Update\n";
            break;

        case 4:
            cout << "Delete\n";
            break;

        default:
            cout << "Invalid option\n";
            break;
    }

    cout << '\n';


    // ========================================================
    // BONUS: CLASSIFY THE FIRST NUMBER
    // ========================================================

    cout << "=== BONUS: Number Classification ===\n";

    if (number > 0) {
        cout << "Positive";
    } else if (number < 0) {
        cout << "Negative";
    } else {
        cout << "Zero";
    }

    if (number % 2 == 0) {
        cout << " and Even\n";
    } else {
        cout << " and Odd\n";
    }

    return 0;
}


/*
SUGGESTED INPUT

7
81
2024
25 40 15
2


EXPECTED OUTPUT

=== PROBLEM 1: Even/Odd ===
Odd

=== PROBLEM 2: Grade ===
B

=== PROBLEM 3: Leap Year ===
Leap

=== PROBLEM 4: Maximum ===
40

=== PROBLEM 5: Menu ===
Read

=== BONUS: Number Classification ===
Positive and Odd


PRACTICE LINKS

1. GFG Decision Making:
https://www.geeksforgeeks.org/decision-making-c-cpp/

2. HackerRank Conditional If-Else:
https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

3. HackerRank Day 3:
https://www.hackerrank.com/challenges/30-conditional-statements/problem

4. LeetCode 2413:
https://leetcode.com/problems/smallest-even-multiple/

5. LeetCode 2235:
https://leetcode.com/problems/add-two-integers/


WHAT'S NEXT:
01_C++__/07_LOOPS/
*/
