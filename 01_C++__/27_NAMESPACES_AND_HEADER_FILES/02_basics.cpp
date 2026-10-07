/*
Topic: Namespaces and Header Files
File: 02_basics.cpp

Purpose:
Practice:
- namespace qualification
- aliases
- using declarations
- declarations before definitions
- implementation-local helpers

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>

// ========== SECTION 1: TWO IDENTICAL NAMES ==========

namespace school {
    int count = 30;
}

namespace office {
    int count = 12;
}

// ========== SECTION 2: NESTED NAMESPACE ==========

namespace project::math {
    int add(int a, int b) {
        return a + b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
}

// ========== SECTION 3: ALIAS ==========

namespace pmath = project::math;

// ========== SECTION 4: ANONYMOUS NAMESPACE ==========

namespace {
    int clampToZero(int value) {
        return value < 0 ? 0 : value;
    }
}

// ========== SECTION 5: FORWARD FUNCTION DECLARATION ==========

int maximum(int a, int b);

int main() {
    std::cout << "=== BASIC 1: QUALIFIED NAMES ===\n";

    std::cout << "School count = "
              << school::count << '\n';

    std::cout << "Office count = "
              << office::count << '\n';

    std::cout << "\n=== BASIC 2: NESTED NAMESPACE ===\n";

    std::cout << "3 + 4 = "
              << project::math::add(3, 4)
              << '\n';

    std::cout << "3 * 4 = "
              << project::math::multiply(3, 4)
              << '\n';

    std::cout << "\n=== BASIC 3: ALIAS ===\n";

    std::cout << "Alias add = "
              << pmath::add(10, 5)
              << '\n';

    std::cout << "\n=== BASIC 4: USING DECLARATION ===\n";

    using project::math::multiply;

    std::cout << "multiply(6, 7) = "
              << multiply(6, 7)
              << '\n';

    std::cout << "\n=== BASIC 5: LOCAL HELPER ===\n";

    std::cout << "clampToZero(-5) = "
              << clampToZero(-5)
              << '\n';

    std::cout << "\n=== BASIC 6: DECLARE THEN DEFINE ===\n";

    std::cout << "maximum(8, 3) = "
              << maximum(8, 3)
              << '\n';

    std::cout << "\nNext: 28_AUTO_RANGE_BASED_LOOPS\n";

    return 0;
}

int maximum(int a, int b) {
    return a > b ? a : b;
}

/*
Expected output:

=== BASIC 1: QUALIFIED NAMES ===
School count = 30
Office count = 12

=== BASIC 2: NESTED NAMESPACE ===
3 + 4 = 7
3 * 4 = 12

=== BASIC 3: ALIAS ===
Alias add = 15

=== BASIC 4: USING DECLARATION ===
multiply(6, 7) = 42

=== BASIC 5: LOCAL HELPER ===
clampToZero(-5) = 0

=== BASIC 6: DECLARE THEN DEFINE ===
maximum(8, 3) = 8

Next: 28_AUTO_RANGE_BASED_LOOPS
*/
