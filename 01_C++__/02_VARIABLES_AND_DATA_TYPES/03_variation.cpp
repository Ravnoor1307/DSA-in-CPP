/*
TOPIC: Variables and Data Types
FILE: 03_variation.cpp

Purpose:
Explore important variations and edge cases involving scalar types.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdint>

using namespace std;

int main() {

    // ========================================================
    // VARIATION 1: INITIALIZATION STYLES
    // ========================================================

    int a = 10;
    int b(20);
    int c{30};
    int d{};

    cout << "=== VARIATION 1: Initialization ===\n";

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "c = " << c << '\n';
    cout << "d = " << d << "\n\n";


    // ========================================================
    // VARIATION 2: DIGIT SEPARATORS
    // ========================================================
    //
    // Apostrophes make large numbers easier to read.
    // They do not change the value.

    int oneMillion = 1'000'000;

    long long oneTrillion =
        1'000'000'000'000LL;

    cout << "=== VARIATION 2: Digit Separators ===\n";

    cout << oneMillion << '\n';
    cout << oneTrillion << "\n\n";


    // ========================================================
    // VARIATION 3: LITERAL TYPES
    // ========================================================

    float f = 2.5f;
    double dValue = 2.5;
    long long big = 10LL;

    cout << "=== VARIATION 3: Literal Suffixes ===\n";

    cout << "float = " << f << '\n';
    cout << "double = " << dValue << '\n';
    cout << "long long = " << big << "\n\n";


    // ========================================================
    // VARIATION 4: WIDEN ARITHMETIC BEFORE MULTIPLICATION
    // ========================================================
    //
    // a*b would be evaluated as int when both operands are int.
    //
    // Putting 1LL into the expression causes long long arithmetic
    // before the potentially large product is produced.

    int width = 100'000;
    int height = 100'000;

    long long area = 1LL * width * height;

    cout << "=== VARIATION 4: Wide Arithmetic ===\n";

    cout << "area = " << area << "\n\n";


    // ========================================================
    // VARIATION 5: FLOATING-POINT PRECISION
    // ========================================================

    double value = 0.1;

    cout << "=== VARIATION 5: Floating Point ===\n";

    cout << setprecision(17);
    cout << "0.1 -> " << value << "\n\n";


    // ========================================================
    // VARIATION 6: BOOL OUTPUT FORMATS
    // ========================================================

    bool answer = true;

    cout << "=== VARIATION 6: bool Formatting ===\n";

    cout << "normal = " << answer << '\n';

    cout << boolalpha;
    cout << "boolalpha = " << answer << '\n';

    cout << noboolalpha;

    cout << '\n';


    // ========================================================
    // VARIATION 7: TYPE SIZES
    // ========================================================

    cout << "=== VARIATION 7: sizeof ===\n";

    cout << "char: " << sizeof(char) << '\n';
    cout << "int: " << sizeof(int) << '\n';
    cout << "long long: " << sizeof(long long) << '\n';
    cout << "double: " << sizeof(double) << "\n\n";


    // ========================================================
    // VARIATION 8: IMPLEMENTATION LIMITS
    // ========================================================

    cout << "=== VARIATION 8: Limits ===\n";

    cout << "int min = "
         << numeric_limits<int>::min() << '\n';

    cout << "int max = "
         << numeric_limits<int>::max() << '\n';

    cout << "long long max = "
         << numeric_limits<long long>::max() << "\n\n";


    // ========================================================
    // VARIATION 9: FIXED-WIDTH INTEGER TYPES
    // ========================================================
    //
    // std::int32_t exists when the implementation provides an
    // integer type that is exactly 32 bits.
    //
    // Typical DSA code usually still uses int/long long.

    std::int32_t exact32 = 123;
    std::int64_t exact64 = 5'000'000'000LL;

    cout << "=== VARIATION 9: Fixed Width ===\n";

    cout << "int32_t value = " << exact32 << '\n';
    cout << "int64_t value = " << exact64 << '\n';

    return 0;
}


/*
EXPECTED OUTPUT ON A COMMON MODERN PLATFORM

=== VARIATION 1: Initialization ===
a = 10
b = 20
c = 30
d = 0

=== VARIATION 2: Digit Separators ===
1000000
1000000000000

=== VARIATION 3: Literal Suffixes ===
float = 2.5
double = 2.5
long long = 10

=== VARIATION 4: Wide Arithmetic ===
area = 10000000000

=== VARIATION 5: Floating Point ===
0.1 -> 0.10000000000000001

=== VARIATION 6: bool Formatting ===
normal = 1
boolalpha = true

=== VARIATION 7: sizeof ===
char: 1
int: 4
long long: 8
double: 8

=== VARIATION 8: Limits ===
int min = -2147483648
int max = 2147483647
long long max = 9223372036854775807

=== VARIATION 9: Fixed Width ===
int32_t value = 123
int64_t value = 5000000000

Type sizes and some floating-point formatting are implementation-dependent.

WHAT'S NEXT:
01_C++__/03_TYPE_CONVERSION_AND_CASTING/
*/
