/*
TOPIC: Input and Output
FILE: 04_practice_problems.cpp

The exercises intentionally avoid conditionals and loops because
those topics appear later in the roadmap.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice

Suggested input:
25
95.5
A
10 20 30
Ada Lovelace
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // ========================================================
    // PROBLEM 1: READ AND ECHO INTEGER
    // ========================================================
    //
    // Input:
    //
    // 25
    //
    // Output:
    //
    // Value = 25

    int value{};

    cin >> value;

    cout << "=== PROBLEM 1 ===\n";
    cout << "Value = " << value << "\n\n";


    // ========================================================
    // PROBLEM 2: READ A DECIMAL
    // ========================================================
    //
    // Input:
    //
    // 95.5
    //
    // Print it with exactly two digits after the decimal point.

    double score{};

    cin >> score;

    cout << "=== PROBLEM 2 ===\n";

    cout << fixed
         << setprecision(2);

    cout << "Score = "
         << score
         << "\n\n";


    // ========================================================
    // PROBLEM 3: READ A CHARACTER
    // ========================================================

    char grade{};

    cin >> grade;

    cout << "=== PROBLEM 3 ===\n";
    cout << "Grade = " << grade << "\n\n";


    // ========================================================
    // PROBLEM 4: READ THREE VALUES
    // ========================================================
    //
    // Input:
    //
    // 10 20 30
    //
    // We haven't formally learned arithmetic operators yet,
    // so simply print each value.

    int a{};
    int b{};
    int c{};

    cin >> a >> b >> c;

    cout << "=== PROBLEM 4 ===\n";

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "c = " << c << "\n\n";


    // ========================================================
    // PROBLEM 5: READ A FULL NAME
    // ========================================================
    //
    // Input:
    //
    // Ada Lovelace
    //
    // Because previous input used >>, consume the remaining
    // newline before calling getline.

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    string name;

    getline(cin, name);

    cout << "=== PROBLEM 5 ===\n";
    cout << "Name = " << name << "\n\n";


    // ========================================================
    // BONUS: FORMAT A NUMBER WITH LEADING ZEROES
    // ========================================================
    //
    // Produce:
    //
    // 00042

    cout << "=== BONUS ===\n";

    cout << setfill('0')
         << setw(5)
         << 42
         << '\n';

    cout << setfill(' ');

    return 0;
}


/*
SUGGESTED INPUT

25
95.5
A
10 20 30
Ada Lovelace


EXPECTED OUTPUT

=== PROBLEM 1 ===
Value = 25

=== PROBLEM 2 ===
Score = 95.50

=== PROBLEM 3 ===
Grade = A

=== PROBLEM 4 ===
a = 10
b = 20
c = 30

=== PROBLEM 5 ===
Name = Ada Lovelace

=== BONUS ===
00042


PRACTICE LINKS

1. HackerRank Input and Output
https://www.hackerrank.com/challenges/cpp-input-and-output/problem

2. HackerRank Basic Data Types
https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

3. GFG Basic Input/Output
https://www.geeksforgeeks.org/basic-input-output-c/

4. LeetCode 2235
https://leetcode.com/problems/add-two-integers/

5. LeetCode 2469
https://leetcode.com/problems/convert-the-temperature/


WHAT'S NEXT:
01_C++__/05_OPERATORS/
*/
