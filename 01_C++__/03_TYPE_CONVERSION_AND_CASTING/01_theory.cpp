/*
TOPIC: Type Conversion and Casting

Covers:
- Implicit conversion
- Explicit conversion
- static_cast
- Numeric conversions
- Narrowing
- Integral promotions
- char/int conversions
- bool conversions
- Integer division conversion trap
- Arithmetic promotion
- long long promotion
- Overview of C++ named casts

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>
#include <iomanip>

using namespace std;


// ========== SECTION 1: TYPE CONVERSION ==========
//
// Type conversion changes a value from one type/representation
// to another.
//
// Example:
//
//     int x = 10;
//     double y = x;
//
// C++ automatically converts x to double for y.


// ========== SECTION 2: IMPLICIT CONVERSION ==========
//
// An implicit conversion happens automatically.
//
//     int x = 25;
//     double y = x;
//
// We do not explicitly write a cast.


// ========== SECTION 3: EXPLICIT CONVERSION ==========
//
// An explicit conversion is deliberately requested.
//
// Modern C++ example:
//
//     static_cast<int>(value)
//
// Example:
//
//     double x = 5.8;
//     int y = static_cast<int>(x);


// ========== SECTION 4: FLOATING TO INTEGER ==========
//
// For an in-range finite floating-point value:
//
//     5.9  -> 5
//    -5.9  -> -5
//
// The fractional portion is discarded.
//
// This means truncation toward zero, not ordinary rounding.
//
// If the truncated value cannot be represented by the target
// integer type, behavior is undefined.


// ========== SECTION 5: NARROWING ==========
//
// Some conversions can lose information.
//
// Examples:
//
//     double -> int
//     double -> float
//     long long -> int
//
// List initialization helps reject many narrowing conversions:
//
//     double d = 5.8;
//     int x{d};       // compile-time error


// ========== SECTION 6: INTEGRAL PROMOTIONS ==========
//
// Small integer types such as char and short are commonly promoted
// before arithmetic.
//
// char itself is an integer type.
//
//     char c = 'A';
//     int code = c;
//
// On an ASCII-compatible system, code is 65.


// ========== SECTION 7: BOOL CONVERSIONS ==========
//
// Numeric zero converts to false.
//
// Nonzero numeric values convert to true.
//
// false converts to integer 0.
// true converts to integer 1.


// ========== SECTION 8: INTEGER DIVISION TRAP ==========
//
// Consider:
//
//     int a = 5;
//     int b = 2;
//
//     double result = a / b;
//
// a / b is evaluated BEFORE assignment.
//
// Both operands are int.
//
// Therefore:
//
//     5 / 2 -> 2
//
// Only afterward:
//
//     2 -> 2.0
//
// result becomes 2.0, not 2.5.


// ========== SECTION 9: CAST BEFORE DIVISION ==========
//
// To perform floating-point division:
//
//     double result =
//         static_cast<double>(a) / b;
//
// Now one operand is double before the division.
//
// Conceptually:
//
//     5 -> 5.0
//
//     5.0 / 2.0
//
//     -> 2.5


// ========== SECTION 10: LONG LONG PROMOTION ==========
//
// This can be dangerous:
//
//     int a = 100000;
//     int b = 100000;
//
//     long long result = a * b;
//
// a*b is computed as int BEFORE conversion to long long.
//
// Better:
//
//     long long result = 1LL * a * b;
//
// 1LL introduces long long arithmetic before the large product.


// ========== SECTION 11: C++ CASTS ==========
//
// C++ has four named cast forms:
//
//     static_cast
//     dynamic_cast
//     const_cast
//     reinterpret_cast
//
// At our current level, static_cast is the important one.
//
// dynamic_cast:
//     Polymorphic class hierarchy conversions.
//
// const_cast:
//     Changes certain cv-qualifications.
//
// reinterpret_cast:
//     Low-level reinterpretation.
//
// They are not interchangeable.


// ========== SECTION 12: C-STYLE CAST ==========
//
// Older code may contain:
//
//     (int)value
//
// Modern C++ generally prefers:
//
//     static_cast<int>(value)
//
// because its intent is clearer.


int main() {

    cout << "=== DEMO 1: Implicit int -> double ===\n";

    int whole = 25;
    double decimal = whole;

    cout << fixed << setprecision(1);
    cout << "int value = " << whole << '\n';
    cout << "double value = " << decimal << "\n\n";


    cout << "=== DEMO 2: Explicit double -> int ===\n";

    double positive = 8.9;
    double negative = -8.9;

    int p = static_cast<int>(positive);
    int n = static_cast<int>(negative);

    cout << defaultfloat;
    cout << "8.9 -> " << p << '\n';
    cout << "-8.9 -> " << n << "\n\n";


    cout << "=== DEMO 3: char -> int ===\n";

    char letter = 'A';

    cout << "character = " << letter << '\n';

    cout << "numeric code on this implementation = "
         << static_cast<int>(letter)
         << "\n\n";


    cout << "=== DEMO 4: Character Digit -> Integer ===\n";

    char digit = '7';

    int digitValue = digit - '0';

    cout << "character = " << digit << '\n';
    cout << "numeric digit = " << digitValue << "\n\n";


    cout << "=== DEMO 5: bool Conversion ===\n";

    bool fromZero = 0;
    bool fromPositive = 42;
    bool fromNegative = -7;

    cout << boolalpha;

    cout << "0 -> " << fromZero << '\n';
    cout << "42 -> " << fromPositive << '\n';
    cout << "-7 -> " << fromNegative << "\n\n";

    cout << noboolalpha;


    cout << "=== DEMO 6: Integer Division Trap ===\n";

    int a = 7;
    int b = 2;

    double wrongForFraction = a / b;

    cout << fixed << setprecision(1);

    cout << "double result = 7 / 2 -> "
         << wrongForFraction
         << "\n\n";


    cout << "=== DEMO 7: Cast Before Division ===\n";

    double correct =
        static_cast<double>(a) / b;

    cout << "static_cast<double>(7) / 2 -> "
         << correct
         << "\n\n";


    cout << "=== DEMO 8: long long Arithmetic ===\n";

    int width = 100'000;
    int height = 100'000;

    // Do NOT demonstrate the overflowing int version because
    // signed overflow would itself be undefined behavior.
    //
    // Instead, widen the expression before multiplication.

    long long area =
        1LL * width * height;

    cout << defaultfloat;

    cout << "100000 * 100000 = "
         << area
         << "\n\n";


    cout << "=== DEMO 9: Cast Does Not Modify Original ===\n";

    double original = 5.9;

    int converted =
        static_cast<int>(original);

    cout << "original = " << original << '\n';
    cout << "converted = " << converted << "\n\n";


    cout << "=== DEMO 10: float -> double ===\n";

    float f = 0.1f;
    double widened = f;

    cout << setprecision(17);

    cout << "float value widened to double = "
         << widened
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

The character-code line assumes an ASCII-compatible implementation
for the shown value, which is typical on DSA systems.

=== DEMO 1: Implicit int -> double ===
int value = 25
double value = 25.0

=== DEMO 2: Explicit double -> int ===
8.9 -> 8
-8.9 -> -8

=== DEMO 3: char -> int ===
character = A
numeric code on this implementation = 65

=== DEMO 4: Character Digit -> Integer ===
character = 7
numeric digit = 7

=== DEMO 5: bool Conversion ===
0 -> false
42 -> true
-7 -> true

=== DEMO 6: Integer Division Trap ===
double result = 7 / 2 -> 3.0

=== DEMO 7: Cast Before Division ===
static_cast<double>(7) / 2 -> 3.5

=== DEMO 8: long long Arithmetic ===
100000 * 100000 = 10000000000

=== DEMO 9: Cast Does Not Modify Original ===
original = 5.9
converted = 5

=== DEMO 10: float -> double ===
float value widened to double = 0.10000000149011612

Some floating-point text can differ between implementations.

WHAT'S NEXT:
01_C++__/04_INPUT_OUTPUT/
*/
