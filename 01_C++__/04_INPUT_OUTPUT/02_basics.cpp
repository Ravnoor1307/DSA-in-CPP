/*
TOPIC: Input and Output
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
    ./basics

Suggested input:
21
90.5
A
100 200
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Fast C++ stream setup commonly used in DSA.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // ========================================================
    // BASIC 1: READ INT
    // ========================================================

    int age{};

    cin >> age;

    cout << "=== BASIC 1: int Input ===\n";
    cout << "age = " << age << "\n\n";


    // ========================================================
    // BASIC 2: READ DOUBLE
    // ========================================================

    double score{};

    cin >> score;

    cout << "=== BASIC 2: double Input ===\n";
    cout << "score = " << score << "\n\n";


    // ========================================================
    // BASIC 3: READ CHAR
    // ========================================================

    char grade{};

    cin >> grade;

    cout << "=== BASIC 3: char Input ===\n";
    cout << "grade = " << grade << "\n\n";


    // ========================================================
    // BASIC 4: MULTIPLE VALUES
    // ========================================================

    int first{};
    int second{};

    cin >> first >> second;

    cout << "=== BASIC 4: Multiple Values ===\n";

    cout << "first = " << first << '\n';
    cout << "second = " << second << "\n\n";


    // ========================================================
    // BASIC 5: FORMATTED DECIMAL OUTPUT
    // ========================================================

    double pi = 3.141592653589793;

    cout << "=== BASIC 5: Decimal Formatting ===\n";

    cout << fixed
         << setprecision(3)
         << pi
         << "\n\n";


    // ========================================================
    // BASIC 6: FIELD WIDTH
    // ========================================================

    cout << "=== BASIC 6: Field Width ===\n";

    cout << right;

    cout << setw(6) << 1 << '\n';
    cout << setw(6) << 20 << '\n';
    cout << setw(6) << 300 << '\n';


    return 0;
}


/*
SUGGESTED INPUT

21
90.5
A
100 200


EXPECTED OUTPUT

=== BASIC 1: int Input ===
age = 21

=== BASIC 2: double Input ===
score = 90.5

=== BASIC 3: char Input ===
grade = A

=== BASIC 4: Multiple Values ===
first = 100
second = 200

=== BASIC 5: Decimal Formatting ===
3.142

=== BASIC 6: Field Width ===
     1
    20
   300


WHAT'S NEXT:
01_C++__/05_OPERATORS/
*/
