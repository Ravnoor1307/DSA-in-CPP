/*
TOPIC: Variables and Data Types

Covers:
- Variables
- Declaration
- Initialization
- Assignment
- Fundamental data types
- int and long long
- float and double
- char
- bool
- const
- auto
- sizeof
- signed/unsigned
- numeric limits
- value copying
- integer overflow awareness
- floating-point precision awareness

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdint>

using namespace std;


// ========== SECTION 1: VARIABLES ==========
//
// A variable is a named object that stores a value.
//
// Example:
//
//     int age = 20;
//
// int  -> type
// age  -> name
// 20   -> initial value
//
// Think of a variable as a labeled container.
//
//     +---------+
//     | age     |
//     |   20    |
//     +---------+
//
// We can later assign another value:
//
//     age = 21;


// ========== SECTION 2: DECLARATION, INITIALIZATION, ASSIGNMENT ==========
//
// Declaration:
//
//     int x;
//
// Initialization:
//
//     int x = 10;
//
// Assignment after creation:
//
//     x = 20;
//
// Initialization and assignment are different operations,
// even though both can result in an object containing a value.


// ========== SECTION 3: INITIALIZATION STYLES ==========
//
// Common forms:
//
//     int a = 10;
//     int b(20);
//     int c{30};
//
// Empty brace initialization:
//
//     int d{};
//
// gives d the value 0.
//
// Brace initialization also rejects many narrowing conversions.


// ========== SECTION 4: INT ==========
//
// int stores integer values:
//
//     -5
//      0
//     42
//
// On many current platforms, int is 32 bits, but the C++
// standard does not universally require sizeof(int) == 4.


// ========== SECTION 5: LONG LONG ==========
//
// long long provides at least 64 bits.
//
// It is commonly used in DSA when values may exceed int.
//
// Example:
//
//     long long population = 8'000'000'000LL;
//
// LL makes the literal a long long literal.


// ========== SECTION 6: SIGNED INTEGER OVERFLOW ==========
//
// If a signed integer computation produces a value outside
// the representable range, the program has undefined behavior.
//
// Do NOT rely on signed integers wrapping.
//
// A common DSA technique:
//
//     long long product = 1LL * a * b;
//
// The 1LL causes the arithmetic to proceed using long long
// before a potentially overflowing int multiplication.


// ========== SECTION 7: FLOAT AND DOUBLE ==========
//
// float and double represent floating-point values.
//
//     float  x = 3.5f;
//     double y = 3.5;
//
// The literal 3.5 is a double.
// The literal 3.5f is a float.
//
// double normally provides more precision than float.


// ========== SECTION 8: FLOATING-POINT APPROXIMATION ==========
//
// Many decimal fractions cannot be represented exactly in
// binary floating-point.
//
// For example, the stored representation of 0.1 is normally
// an approximation.
//
// Therefore floating-point equality requires care.
// We will study comparisons after learning operators.


// ========== SECTION 9: CHAR ==========
//
// char represents a character-sized integer type.
//
//     char grade = 'A';
//
// Single quotes create character literals:
//
//     'A'
//
// Double quotes create string literals:
//
//     "A"
//
// These are not the same type.


// ========== SECTION 10: BOOL ==========
//
// bool stores:
//
//     true
//     false
//
// By default, cout typically represents them as:
//
//     1
//     0
//
// boolalpha changes textual formatting:
//
//     true
//     false


// ========== SECTION 11: CONST ==========
//
// const prevents ordinary modification after initialization.
//
//     const int DAYS = 7;
//
// Later:
//
//     DAYS = 8;
//
// would be a compile-time error.


// ========== SECTION 12: AUTO ==========
//
// auto asks the compiler to deduce a type from the initializer.
//
//     auto x = 10;      // int
//     auto y = 2.5;     // double
//     auto c = 'A';     // char
//
// auto does not mean "no type."
// The type is still known at compile time.


// ========== SECTION 13: SIZEOF ==========
//
// sizeof reports storage size in bytes.
//
//     sizeof(int)
//
// Exact sizes can differ between implementations.
//
// Never assume that every platform has exactly the same layout.


// ========== SECTION 14: SIGNED AND UNSIGNED ==========
//
// signed integer types can represent negative values.
//
// unsigned integer types represent non-negative values and
// arithmetic follows modulo rules.
//
// Mixing signed and unsigned values can produce surprising
// conversions, so do it intentionally.


// ========== SECTION 15: COPYING VALUES ==========
//
// Fundamental scalar values are copied:
//
//     int a = 10;
//     int b = a;
//
// Changing a:
//
//     a = 50;
//
// does not change b.
//
// Final state:
//
//     a = 50
//     b = 10


int main() {

    cout << "=== DEMO 1: Variable ===\n";

    int age = 20;

    cout << "age = " << age << '\n';

    age = 21;

    cout << "after assignment, age = " << age << "\n\n";


    cout << "=== DEMO 2: Initialization Styles ===\n";

    int a = 10;
    int b(20);
    int c{30};
    int d{};

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "c = " << c << '\n';
    cout << "d = " << d << "\n\n";


    cout << "=== DEMO 3: Integer Types ===\n";

    int score = 95;
    long long worldPopulation = 8'000'000'000LL;

    cout << "score = " << score << '\n';
    cout << "worldPopulation = " << worldPopulation << "\n\n";


    cout << "=== DEMO 4: Safe Wider Multiplication ===\n";

    int x = 100'000;
    int y = 100'000;

    long long product = 1LL * x * y;

    cout << "100000 * 100000 = " << product << "\n\n";


    cout << "=== DEMO 5: Floating-Point Types ===\n";

    float temperature = 36.5f;
    double pi = 3.141592653589793;

    cout << "float temperature = " << temperature << '\n';

    cout << setprecision(17);
    cout << "double pi = " << pi << "\n\n";


    cout << "=== DEMO 6: Floating-Point Approximation ===\n";

    double decimal = 0.1;

    cout << setprecision(17);
    cout << "0.1 stored as double can display as: "
         << decimal << "\n\n";


    cout << "=== DEMO 7: char ===\n";

    char grade = 'A';
    char symbol = '#';

    cout << "grade = " << grade << '\n';
    cout << "symbol = " << symbol << "\n\n";


    cout << "=== DEMO 8: bool ===\n";

    bool learning = true;
    bool finished = false;

    cout << "Default formatting:\n";
    cout << "learning = " << learning << '\n';
    cout << "finished = " << finished << '\n';

    cout << boolalpha;

    cout << "boolalpha formatting:\n";
    cout << "learning = " << learning << '\n';
    cout << "finished = " << finished << "\n\n";

    // Restore normal formatting for completeness.
    cout << noboolalpha;


    cout << "=== DEMO 9: const ===\n";

    const int DAYS_IN_WEEK = 7;

    cout << "DAYS_IN_WEEK = " << DAYS_IN_WEEK << "\n\n";


    cout << "=== DEMO 10: auto ===\n";

    auto count = 10;
    auto price = 19.95;
    auto letter = 'Z';

    cout << "count = " << count << '\n';
    cout << "price = " << price << '\n';
    cout << "letter = " << letter << "\n\n";


    cout << "=== DEMO 11: sizeof ===\n";

    cout << "sizeof(char) = " << sizeof(char) << " byte(s)\n";
    cout << "sizeof(int) = " << sizeof(int) << " byte(s)\n";
    cout << "sizeof(long long) = " << sizeof(long long) << " byte(s)\n";
    cout << "sizeof(float) = " << sizeof(float) << " byte(s)\n";
    cout << "sizeof(double) = " << sizeof(double) << " byte(s)\n";
    cout << "sizeof(bool) = " << sizeof(bool) << " byte(s)\n\n";


    cout << "=== DEMO 12: Numeric Limits ===\n";

    cout << "int minimum = "
         << numeric_limits<int>::min() << '\n';

    cout << "int maximum = "
         << numeric_limits<int>::max() << '\n';

    cout << "long long maximum = "
         << numeric_limits<long long>::max() << "\n\n";


    cout << "=== DEMO 13: Copying Values ===\n";

    int original = 10;
    int copy = original;

    cout << "Before changing original:\n";
    cout << "original = " << original << '\n';
    cout << "copy = " << copy << '\n';

    original = 50;

    cout << "After changing original:\n";
    cout << "original = " << original << '\n';
    cout << "copy = " << copy << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

Exact sizeof values are implementation-dependent.
The following represents a common modern system:

=== DEMO 1: Variable ===
age = 20
after assignment, age = 21

=== DEMO 2: Initialization Styles ===
a = 10
b = 20
c = 30
d = 0

=== DEMO 3: Integer Types ===
score = 95
worldPopulation = 8000000000

=== DEMO 4: Safe Wider Multiplication ===
100000 * 100000 = 10000000000

=== DEMO 5: Floating-Point Types ===
float temperature = 36.5
double pi = 3.1415926535897931

=== DEMO 6: Floating-Point Approximation ===
0.1 stored as double can display as: 0.10000000000000001

=== DEMO 7: char ===
grade = A
symbol = #

=== DEMO 8: bool ===
Default formatting:
learning = 1
finished = 0
boolalpha formatting:
learning = true
finished = false

=== DEMO 9: const ===
DAYS_IN_WEEK = 7

=== DEMO 10: auto ===
count = 10
price = 19.949999999999999
letter = Z

=== DEMO 11: sizeof ===
sizeof(char) = 1 byte(s)
sizeof(int) = 4 byte(s)
sizeof(long long) = 8 byte(s)
sizeof(float) = 4 byte(s)
sizeof(double) = 8 byte(s)
sizeof(bool) = 1 byte(s)

=== DEMO 12: Numeric Limits ===
int minimum = -2147483648
int maximum = 2147483647
long long maximum = 9223372036854775807

=== DEMO 13: Copying Values ===
Before changing original:
original = 10
copy = 10
After changing original:
original = 50
copy = 10

Some floating-point text and type sizes can differ by implementation.

WHAT'S NEXT:
01_C++__/03_TYPE_CONVERSION_AND_CASTING/
*/
