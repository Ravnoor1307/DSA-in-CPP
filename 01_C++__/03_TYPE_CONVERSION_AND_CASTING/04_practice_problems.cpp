/*
TOPIC: Type Conversion and Casting
FILE: 04_practice_problems.cpp

These exercises stay within concepts learned so far.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // ========================================================
    // PROBLEM 1: TRUNCATE A DECIMAL
    // ========================================================
    //
    // Given:
    //
    //     27.95
    //
    // explicitly convert it to int.
    //
    // Expected:
    //
    //     27
    //
    // Remember:
    // floating -> integer truncates toward zero when the
    // converted value is representable.

    double amount = 27.95;

    int wholeAmount =
        static_cast<int>(amount);

    cout << "=== PROBLEM 1 ===\n";

    cout << "Original: " << amount << '\n';
    cout << "Integer: " << wholeAmount << "\n\n";


    // ========================================================
    // PROBLEM 2: CHARACTER DIGIT
    // ========================================================
    //
    // Convert character '9' into integer 9.
    //
    // Dry run on the character-code values:
    //
    // '9' - '0'
    //
    // Decimal digit codes are contiguous, therefore:
    //
    // -> 9

    char digit = '9';

    int digitValue =
        digit - '0';

    cout << "=== PROBLEM 2 ===\n";

    cout << "Character: " << digit << '\n';
    cout << "Integer: " << digitValue << "\n\n";


    // ========================================================
    // PROBLEM 3: FIX INTEGER DIVISION
    // ========================================================
    //
    // a = 7
    // b = 2
    //
    // Integer division gives:
    //
    // 3
    //
    // But we need:
    //
    // 3.5
    //
    // Convert BEFORE division.

    int a = 7;
    int b = 2;

    double result =
        static_cast<double>(a) / b;

    cout << "=== PROBLEM 3 ===\n";

    cout << fixed << setprecision(1);

    cout << "7 / 2 = "
         << result << "\n\n";


    // ========================================================
    // PROBLEM 4: LARGE MULTIPLICATION
    // ========================================================
    //
    // Both values are int:
    //
    // 100000 * 100000
    //
    // The mathematical answer is 10,000,000,000.
    //
    // Introduce long long BEFORE the multiplication grows large.

    int width = 100'000;
    int height = 100'000;

    long long area =
        1LL * width * height;

    cout << defaultfloat;

    cout << "=== PROBLEM 4 ===\n";

    cout << "Area = " << area << "\n\n";


    // ========================================================
    // PROBLEM 5: BOOL CONVERSION
    // ========================================================
    //
    // Convert:
    //
    // 0   -> false
    // -25 -> true

    int zero = 0;
    int negative = -25;

    bool zeroBool =
        static_cast<bool>(zero);

    bool negativeBool =
        static_cast<bool>(negative);

    cout << "=== PROBLEM 5 ===\n";

    cout << boolalpha;

    cout << "0 -> " << zeroBool << '\n';
    cout << "-25 -> " << negativeBool << "\n\n";

    cout << noboolalpha;


    // ========================================================
    // BONUS: PREDICT THE FINAL VALUES
    // ========================================================
    //
    // double x = 8.75;
    //
    // int y = static_cast<int>(x);
    //
    // double z = y;
    //
    // Dry run:
    //
    // x = 8.75
    //
    // y:
    // 8.75 -> 8
    //
    // z:
    // int 8 -> double 8.0
    //
    // Casting x did NOT change x.

    double x = 8.75;

    int y =
        static_cast<int>(x);

    double z = y;

    cout << "=== BONUS ===\n";

    cout << fixed << setprecision(2);

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    cout << "z = " << z << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1 ===
Original: 27.95
Integer: 27

=== PROBLEM 2 ===
Character: 9
Integer: 9

=== PROBLEM 3 ===
7 / 2 = 3.5

=== PROBLEM 4 ===
Area = 10000000000

=== PROBLEM 5 ===
0 -> false
-25 -> true

=== BONUS ===
x = 8.75
y = 8
z = 8.00


PRACTICE LINKS

1. HackerRank Basic Data Types:
https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

2. LeetCode 2469:
https://leetcode.com/problems/convert-the-temperature/

3. LeetCode 2235:
https://leetcode.com/problems/add-two-integers/

4. GFG Type Conversion:
https://www.geeksforgeeks.org/type-conversion-in-c/

5. GFG Type Casting:
https://www.geeksforgeeks.org/type-casting-in-c/


WHAT'S NEXT:
01_C++__/04_INPUT_OUTPUT/
*/
