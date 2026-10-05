/*
TOPIC: Variables and Data Types
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;

int main() {

    // ========================================================
    // BASIC 1: INTEGER VARIABLE
    // ========================================================

    int age = 20;

    cout << "=== BASIC 1: int ===\n";
    cout << "age = " << age << "\n\n";


    // ========================================================
    // BASIC 2: CHANGING A VARIABLE
    // ========================================================

    int score = 50;

    cout << "=== BASIC 2: Assignment ===\n";

    cout << "before = " << score << '\n';

    score = 90;

    cout << "after = " << score << "\n\n";


    // ========================================================
    // BASIC 3: LONG LONG
    // ========================================================

    long long largeNumber = 5'000'000'000LL;

    cout << "=== BASIC 3: long long ===\n";

    cout << "largeNumber = "
         << largeNumber << "\n\n";


    // ========================================================
    // BASIC 4: FLOAT AND DOUBLE
    // ========================================================

    float height = 175.5f;
    double price = 49.99;

    cout << "=== BASIC 4: Floating Point ===\n";

    cout << "height = " << height << '\n';
    cout << "price = " << price << "\n\n";


    // ========================================================
    // BASIC 5: CHAR
    // ========================================================

    char grade = 'A';

    cout << "=== BASIC 5: char ===\n";

    cout << "grade = " << grade << "\n\n";


    // ========================================================
    // BASIC 6: BOOL
    // ========================================================

    bool passed = true;
    bool failed = false;

    cout << "=== BASIC 6: bool ===\n";

    cout << boolalpha;

    cout << "passed = " << passed << '\n';
    cout << "failed = " << failed << "\n\n";

    cout << noboolalpha;


    // ========================================================
    // BASIC 7: CONST
    // ========================================================

    const int MONTHS_IN_YEAR = 12;

    cout << "=== BASIC 7: const ===\n";

    cout << "MONTHS_IN_YEAR = "
         << MONTHS_IN_YEAR << "\n\n";


    // ========================================================
    // BASIC 8: COPY
    // ========================================================

    int first = 10;
    int second = first;

    first = 99;

    cout << "=== BASIC 8: Value Copy ===\n";

    cout << "first = " << first << '\n';
    cout << "second = " << second << "\n\n";


    // ========================================================
    // BASIC 9: EMPTY BRACE INITIALIZATION
    // ========================================================

    int zero{};

    cout << "=== BASIC 9: Value Initialization ===\n";

    cout << "zero = " << zero << "\n\n";


    // ========================================================
    // BASIC 10: AUTO
    // ========================================================

    auto number = 100;
    auto decimal = 2.5;
    auto character = 'X';

    cout << "=== BASIC 10: auto ===\n";

    cout << "number = " << number << '\n';
    cout << "decimal = " << decimal << '\n';
    cout << "character = " << character << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: int ===
age = 20

=== BASIC 2: Assignment ===
before = 50
after = 90

=== BASIC 3: long long ===
largeNumber = 5000000000

=== BASIC 4: Floating Point ===
height = 175.5
price = 49.99

=== BASIC 5: char ===
grade = A

=== BASIC 6: bool ===
passed = true
failed = false

=== BASIC 7: const ===
MONTHS_IN_YEAR = 12

=== BASIC 8: Value Copy ===
first = 99
second = 10

=== BASIC 9: Value Initialization ===
zero = 0

=== BASIC 10: auto ===
number = 100
decimal = 2.5
character = X

WHAT'S NEXT:
01_C++__/03_TYPE_CONVERSION_AND_CASTING/
*/
