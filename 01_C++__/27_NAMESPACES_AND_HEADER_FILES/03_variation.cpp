/*
Topic: Namespaces and Header Files
File: 03_variation.cpp

Purpose:
Explore:
- namespace ambiguity
- global qualification
- nested namespaces
- forward-declared classes
- declarations and definitions
- multi-file project layout as runnable output

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>

// ========== SECTION 1: NAME COLLISION ==========

namespace alpha {
    std::string name() {
        return "alpha";
    }
}

namespace beta {
    std::string name() {
        return "beta";
    }
}

// ========== SECTION 2: GLOBAL NAME ==========

int value = 1000;

// ========== SECTION 3: FORWARD-DECLARED TYPE ==========

class Node;

class NodeObserver {
private:
    const Node* node;

public:
    explicit NodeObserver(const Node* node)
        : node(node) {
    }

    bool exists() const {
        return node != nullptr;
    }
};

class Node {
private:
    int value;

public:
    explicit Node(int value)
        : value(value) {
    }

    int getValue() const {
        return value;
    }
};

// ========== SECTION 4: HEADER-LIKE NAMESPACE DESIGN ==========

namespace dsa::array {
    int sum(const int values[], int size);
}

int dsa::array::sum(
    const int values[],
    int size
) {
    int result = 0;

    for (int i = 0; i < size; ++i) {
        result += values[i];
    }

    return result;
}

// ========== SECTION 5: INTERNAL IMPLEMENTATION ==========

namespace {
    int hiddenDouble(int value) {
        return value * 2;
    }
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== VARIATION 1: COLLIDING NAMES ===\n";

    std::cout << alpha::name() << '\n';
    std::cout << beta::name() << '\n';

    // Using both namespaces broadly could make name() ambiguous.
    // Explicit qualification makes the choice clear.

    std::cout << "\n=== VARIATION 2: GLOBAL QUALIFICATION ===\n";

    int value = 50;

    std::cout << "Local = "
              << value << '\n';

    std::cout << "Global = "
              << ::value << '\n';

    std::cout << "\n=== VARIATION 3: INCOMPLETE TYPE POINTER ===\n";

    Node node(42);
    NodeObserver observer(&node);

    std::cout << "Observer has node? "
              << observer.exists() << '\n';

    std::cout << "Node value = "
              << node.getValue() << '\n';

    std::cout << "\n=== VARIATION 4: NAMESPACED DECLARATION ===\n";

    int numbers[] = {10, 20, 30, 40};

    std::cout << "Sum = "
              << dsa::array::sum(numbers, 4)
              << '\n';

    std::cout << "\n=== VARIATION 5: INTERNAL HELPER ===\n";

    std::cout << "hiddenDouble(9) = "
              << hiddenDouble(9)
              << '\n';

    std::cout << "\n=== VARIATION 6: PROJECT LAYOUT ===\n";

    std::cout
        << "include/math_utils.h\n"
        << "src/math_utils.cpp\n"
        << "src/main.cpp\n";

    std::cout << "\nHeader:\n"
              << "#ifndef MATH_UTILS_H\n"
              << "#define MATH_UTILS_H\n"
              << "namespace math { int add(int, int); }\n"
              << "#endif\n";

    std::cout << "\nBuild:\n"
              << "g++ -std=c++17 src/main.cpp "
              << "src/math_utils.cpp -Iinclude -o app\n";

    std::cout << "\nNext: 28_AUTO_RANGE_BASED_LOOPS\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: COLLIDING NAMES ===
alpha
beta

=== VARIATION 2: GLOBAL QUALIFICATION ===
Local = 50
Global = 1000

=== VARIATION 3: INCOMPLETE TYPE POINTER ===
Observer has node? true
Node value = 42

=== VARIATION 4: NAMESPACED DECLARATION ===
Sum = 100

=== VARIATION 5: INTERNAL HELPER ===
hiddenDouble(9) = 18

=== VARIATION 6: PROJECT LAYOUT ===
include/math_utils.h
src/math_utils.cpp
src/main.cpp

Header:
#ifndef MATH_UTILS_H
#define MATH_UTILS_H
namespace math { int add(int, int); }
#endif

Build:
g++ -std=c++17 src/main.cpp src/math_utils.cpp -Iinclude -o app

Next: 28_AUTO_RANGE_BASED_LOOPS
*/
