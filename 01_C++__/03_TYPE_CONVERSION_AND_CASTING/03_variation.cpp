/*
TOPIC: Type Conversion and Casting
FILE: 03_variation.cpp

Purpose:
Study variations and common traps involving conversions.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // ========================================================
    // VARIATION 1: IMPLICIT VS EXPLICIT
    // ========================================================

    int integer = 42;

    double implicitValue = integer;

    double explicitValue =
        static_cast<double>(integer);

    cout << "=== VARIATION 1: Implicit vs Explicit ===\n";

    cout << fixed << setprecision(1);

    cout << "implicit = " << implicitValue << '\n';
    cout << "explicit = " << explicitValue << "\n\n";


    // ========================================================
    // VARIATION 2: ASSIGNMENT AFTER EXPRESSION
    // ========================================================
    //
    // The destination variable does NOT control earlier integer
    // division.

    int a = 9;
    int b = 4;

    double result = a / b;

    cout << "=== VARIATION 2: Destination Does Not Rewrite Expression ===\n";

    cout << "9 / 4 assigned to double = "
         << result << "\n\n";


    // ========================================================
    // VARIATION 3: CONVERT BEFORE EXPRESSION
    // ========================================================

    double accurate =
        static_cast<double>(a) / b;

    cout << "=== VARIATION 3: Convert First ===\n";

    cout << "cast before division = "
         << accurate << "\n\n";


    // ========================================================
    // VARIATION 4: CHAR ARITHMETIC
    // ========================================================

    char digit = '6';

    int number =
        digit - '0';

    cout << defaultfloat;

    cout << "=== VARIATION 4: Character Digit ===\n";

    cout << "'" << digit << "' -> "
         << number << "\n\n";


    // ========================================================
    // VARIATION 5: INTEGER DIGIT -> CHARACTER
    // ========================================================
    //
    // Valid here because numberToConvert is in [0, 9].

    int numberToConvert = 4;

    char character =
        static_cast<char>('0' + numberToConvert);

    cout << "=== VARIATION 5: Integer Digit -> Character ===\n";

    cout << numberToConvert
         << " -> '"
         << character
         << "'\n\n";


    // ========================================================
    // VARIATION 6: FLOAT TO DOUBLE DOES NOT RECOVER PRECISION
    // ========================================================

    float smallPrecision = 0.1f;
    double fromFloat = smallPrecision;
    double directDouble = 0.1;

    cout << "=== VARIATION 6: float -> double ===\n";

    cout << setprecision(17);

    cout << "float widened to double = "
         << fromFloat << '\n';

    cout << "direct double literal = "
         << directDouble << "\n\n";


    // ========================================================
    // VARIATION 7: BOOL CONVERSION
    // ========================================================

    int negative = -100;
    int zero = 0;

    bool first =
        static_cast<bool>(negative);

    bool second =
        static_cast<bool>(zero);

    cout << boolalpha;

    cout << "=== VARIATION 7: bool Conversion ===\n";

    cout << "-100 -> " << first << '\n';
    cout << "0 -> " << second << "\n\n";

    cout << noboolalpha;


    // ========================================================
    // VARIATION 8: LONG LONG PROMOTION
    // ========================================================
    //
    // We deliberately avoid evaluating x*y as int because doing
    // so could invoke signed overflow.
    //
    // 1LL changes the arithmetic type early enough.

    int x = 100'000;
    int y = 100'000;

    long long product =
        1LL * x * y;

    cout << "=== VARIATION 8: Expression Type Matters ===\n";

    cout << "product = "
         << product << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Implicit vs Explicit ===
implicit = 42.0
explicit = 42.0

=== VARIATION 2: Destination Does Not Rewrite Expression ===
9 / 4 assigned to double = 2.0

=== VARIATION 3: Convert First ===
cast before division = 2.2

=== VARIATION 4: Character Digit ===
'6' -> 6

=== VARIATION 5: Integer Digit -> Character ===
4 -> '4'

=== VARIATION 6: float -> double ===
float widened to double = 0.10000000149011612
direct double literal = 0.10000000000000001

=== VARIATION 7: bool Conversion ===
-100 -> true
0 -> false

=== VARIATION 8: Expression Type Matters ===
product = 10000000000

Floating-point text can vary slightly by implementation.

WHAT'S NEXT:
01_C++__/04_INPUT_OUTPUT/
*/
