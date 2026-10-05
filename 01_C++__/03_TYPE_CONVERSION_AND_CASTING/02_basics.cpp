/*
TOPIC: Type Conversion and Casting
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // ========================================================
    // BASIC 1: INT TO DOUBLE
    // ========================================================

    int number = 10;
    double decimal = number;

    cout << "=== BASIC 1: int -> double ===\n";

    cout << fixed << setprecision(1);
    cout << number << " -> " << decimal << "\n\n";


    // ========================================================
    // BASIC 2: DOUBLE TO INT
    // ========================================================
    //
    // This truncates toward zero.
    //
    // It does not round to the nearest integer.

    double price = 19.95;

    int wholePrice =
        static_cast<int>(price);

    cout << "=== BASIC 2: double -> int ===\n";

    cout << defaultfloat;
    cout << price << " -> " << wholePrice << "\n\n";


    // ========================================================
    // BASIC 3: NEGATIVE TRUNCATION
    // ========================================================

    double negative = -4.9;

    int truncated =
        static_cast<int>(negative);

    cout << "=== BASIC 3: Negative Conversion ===\n";

    cout << negative << " -> "
         << truncated << "\n\n";


    // ========================================================
    // BASIC 4: CHAR TO INTEGER CODE
    // ========================================================

    char letter = 'A';

    int code =
        static_cast<int>(letter);

    cout << "=== BASIC 4: char -> int ===\n";

    cout << "character = " << letter << '\n';
    cout << "code = " << code << "\n\n";


    // ========================================================
    // BASIC 5: CHARACTER DIGIT TO NUMBER
    // ========================================================
    //
    // Decimal digit characters are contiguous in the execution
    // character set, so this technique is portable for '0'..'9'.

    char digit = '8';

    int value =
        digit - '0';

    cout << "=== BASIC 5: '8' -> 8 ===\n";

    cout << "digit = " << digit << '\n';
    cout << "value = " << value << "\n\n";


    // ========================================================
    // BASIC 6: INTEGER TO BOOL
    // ========================================================

    bool zero = 0;
    bool one = 1;
    bool large = 100;

    cout << "=== BASIC 6: Numeric -> bool ===\n";

    cout << boolalpha;

    cout << "0 -> " << zero << '\n';
    cout << "1 -> " << one << '\n';
    cout << "100 -> " << large << "\n\n";

    cout << noboolalpha;


    // ========================================================
    // BASIC 7: INTEGER DIVISION
    // ========================================================

    int a = 5;
    int b = 2;

    double integerFirst = a / b;

    double floatingFirst =
        static_cast<double>(a) / b;

    cout << "=== BASIC 7: Division ===\n";

    cout << fixed << setprecision(1);

    cout << "5 / 2 then convert = "
         << integerFirst << '\n';

    cout << "cast then divide = "
         << floatingFirst << "\n\n";


    // ========================================================
    // BASIC 8: WIDEN BEFORE MULTIPLICATION
    // ========================================================

    int x = 100'000;
    int y = 100'000;

    long long product =
        1LL * x * y;

    cout << defaultfloat;

    cout << "=== BASIC 8: Wide Multiplication ===\n";

    cout << "product = "
         << product << '\n';

    return 0;
}


/*
EXPECTED OUTPUT ON AN ASCII-COMPATIBLE SYSTEM

=== BASIC 1: int -> double ===
10 -> 10.0

=== BASIC 2: double -> int ===
19.95 -> 19

=== BASIC 3: Negative Conversion ===
-4.9 -> -4

=== BASIC 4: char -> int ===
character = A
code = 65

=== BASIC 5: '8' -> 8 ===
digit = 8
value = 8

=== BASIC 6: Numeric -> bool ===
0 -> false
1 -> true
100 -> true

=== BASIC 7: Division ===
5 / 2 then convert = 2.0
cast then divide = 2.5

=== BASIC 8: Wide Multiplication ===
product = 10000000000

WHAT'S NEXT:
01_C++__/04_INPUT_OUTPUT/
*/
