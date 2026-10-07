/*
Topic: Namespaces and Header Files
File: 04_practice_problems.cpp

Practice:
1. Resolve namespace name collisions
2. Build a nested namespace
3. Use a namespace alias
4. Practice forward declarations
5. Understand a header/source build

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>

// ========== PROBLEM 1: NAME COLLISION ==========

namespace metric {
    int convert(int meters) {
        return meters * 100;
    }
}

namespace doubled {
    int convert(int value) {
        return value * 2;
    }
}

// ========== PROBLEM 2: NESTED NAMESPACE ==========

namespace dsa::math {
    int gcdSimple(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }

        return a >= 0 ? a : -a;
    }
}

// ========== PROBLEM 3: NAMESPACE ALIAS ==========

namespace dm = dsa::math;

// ========== PROBLEM 4: FORWARD DECLARATION ==========

class Tree;

class TreeHandle {
private:
    Tree* tree;

public:
    explicit TreeHandle(Tree* tree)
        : tree(tree) {
    }

    bool valid() const {
        return tree != nullptr;
    }
};

class Tree {
private:
    int rootValue;

public:
    explicit Tree(int rootValue)
        : rootValue(rootValue) {
    }

    int root() const {
        return rootValue;
    }
};

// ========== PROBLEM 5: DECLARATION THEN DEFINITION ==========

namespace algorithms {
    int linearSearch(
        const int values[],
        int size,
        int target
    );
}

int algorithms::linearSearch(
    const int values[],
    int size,
    int target
) {
    for (int i = 0; i < size; ++i) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== PROBLEM 1: NAMESPACE COLLISION ===\n";

    std::cout << "2 meters = "
              << metric::convert(2)
              << " centimeters\n";

    std::cout << "double 2 = "
              << doubled::convert(2)
              << '\n';

    std::cout << "\n=== PROBLEM 2: NESTED NAMESPACE ===\n";

    std::cout << "gcd(48, 18) = "
              << dsa::math::gcdSimple(48, 18)
              << '\n';

    std::cout << "\n=== PROBLEM 3: ALIAS ===\n";

    std::cout << "Alias gcd(20, 12) = "
              << dm::gcdSimple(20, 12)
              << '\n';

    std::cout << "\n=== PROBLEM 4: FORWARD DECLARATION ===\n";

    Tree tree(50);
    TreeHandle handle(&tree);

    std::cout << "Handle valid? "
              << handle.valid() << '\n';

    std::cout << "Root = "
              << tree.root() << '\n';

    std::cout << "\n=== PROBLEM 5: SEPARATE DECLARATION ===\n";

    int values[] = {4, 8, 15, 16, 23, 42};

    std::cout << "Index of 16 = "
              << algorithms::linearSearch(
                     values,
                     6,
                     16
                 )
              << '\n';

    std::cout << "Index of 99 = "
              << algorithms::linearSearch(
                     values,
                     6,
                     99
                 )
              << '\n';

    std::cout << "\n=== MULTI-FILE EXERCISE ===\n";

    std::cout
        << "Create calculator.h with declarations.\n"
        << "Create calculator.cpp with definitions.\n"
        << "Create main.cpp that includes calculator.h.\n"
        << "Compile both .cpp files together.\n";

    std::cout << "\nSuggested header guard:\n"
              << "#ifndef CALCULATOR_H\n"
              << "#define CALCULATOR_H\n"
              << "// declarations\n"
              << "#endif\n";

    std::cout << "\nCompile command:\n"
              << "g++ -std=c++17 main.cpp calculator.cpp -o app\n";

    std::cout << "\nNext: 28_AUTO_RANGE_BASED_LOOPS\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: NAMESPACE COLLISION ===
2 meters = 200 centimeters
double 2 = 4

=== PROBLEM 2: NESTED NAMESPACE ===
gcd(48, 18) = 6

=== PROBLEM 3: ALIAS ===
Alias gcd(20, 12) = 4

=== PROBLEM 4: FORWARD DECLARATION ===
Handle valid? true
Root = 50

=== PROBLEM 5: SEPARATE DECLARATION ===
Index of 16 = 3
Index of 99 = -1

=== MULTI-FILE EXERCISE ===
Create calculator.h with declarations.
Create calculator.cpp with definitions.
Create main.cpp that includes calculator.h.
Compile both .cpp files together.

Suggested header guard:
#ifndef CALCULATOR_H
#define CALCULATOR_H
// declarations
#endif

Compile command:
g++ -std=c++17 main.cpp calculator.cpp -o app

Next: 28_AUTO_RANGE_BASED_LOOPS
*/
