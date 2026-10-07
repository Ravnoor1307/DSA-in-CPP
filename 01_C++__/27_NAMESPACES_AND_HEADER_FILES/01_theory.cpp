/*
Topic: Namespaces and Header Files

Covers:
- namespaces
- nested namespaces
- namespace aliases
- using declarations
- global scope resolution
- anonymous namespaces
- declarations vs definitions
- header guards
- translation units
- separate compilation
- linkage basics
- forward declarations

This file is intentionally runnable as one translation unit. The
multi-file examples are printed and explained rather than requiring
extra lesson files beyond the repository's required five-file format.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

// ========== SECTION 1: BASIC NAMESPACES ==========

namespace first {
    int value = 10;

    void show() {
        std::cout << "first::show\n";
    }
}

namespace second {
    int value = 20;

    void show() {
        std::cout << "second::show\n";
    }
}

// ========== SECTION 2: NESTED NAMESPACE ==========

namespace dsa::math {
    int square(int value) {
        return value * value;
    }
}

// ========== SECTION 3: REOPENING A NAMESPACE ==========

namespace utilities {
    int doubleValue(int value) {
        return value * 2;
    }
}

namespace utilities {
    int tripleValue(int value) {
        return value * 3;
    }
}

// ========== SECTION 4: NAMESPACE ALIAS ==========

namespace mathematics = dsa::math;

// ========== SECTION 5: GLOBAL SCOPE ==========

int number = 100;

// ========== SECTION 6: ANONYMOUS NAMESPACE ==========

namespace {
    int localHelper(int value) {
        return value + 1;
    }
}

// ========== SECTION 7: DECLARATION BEFORE DEFINITION ==========

int subtract(int a, int b);

// ========== SECTION 8: FORWARD DECLARATION ==========

class Engine;

class EnginePointerHolder {
private:
    Engine* engine;

public:
    explicit EnginePointerHolder(Engine* engine)
        : engine(engine) {
    }

    bool hasEngine() const {
        return engine != nullptr;
    }
};

// Full definition appears later.
class Engine {
private:
    int horsepower;

public:
    explicit Engine(int horsepower)
        : horsepower(horsepower) {
    }

    int getHorsepower() const {
        return horsepower;
    }
};

// ========== SECTION 9: DEFINITION ==========

int subtract(int a, int b) {
    return a - b;
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== DEMO 1: NAMESPACES ===\n";

    std::cout << "first::value = "
              << first::value << '\n';

    std::cout << "second::value = "
              << second::value << '\n';

    first::show();
    second::show();

    std::cout << "\n=== DEMO 2: NESTED NAMESPACE ===\n";

    std::cout << "dsa::math::square(6) = "
              << dsa::math::square(6)
              << '\n';

    std::cout << "\n=== DEMO 3: NAMESPACE ALIAS ===\n";

    std::cout << "mathematics::square(7) = "
              << mathematics::square(7)
              << '\n';

    std::cout << "\n=== DEMO 4: REOPENED NAMESPACE ===\n";

    std::cout << "doubleValue(5) = "
              << utilities::doubleValue(5)
              << '\n';

    std::cout << "tripleValue(5) = "
              << utilities::tripleValue(5)
              << '\n';

    std::cout << "\n=== DEMO 5: GLOBAL SCOPE RESOLUTION ===\n";

    int number = 25;

    std::cout << "Local number = "
              << number << '\n';

    std::cout << "Global number = "
              << ::number << '\n';

    std::cout << "\n=== DEMO 6: USING DECLARATION ===\n";

    using std::string;

    string message = "specific std::string imported";

    std::cout << message << '\n';

    std::cout << "\n=== DEMO 7: ANONYMOUS NAMESPACE ===\n";

    std::cout << "localHelper(9) = "
              << localHelper(9)
              << '\n';

    std::cout << "\n=== DEMO 8: DECLARATION / DEFINITION ===\n";

    std::cout << "subtract(10, 3) = "
              << subtract(10, 3)
              << '\n';

    std::cout << "\n=== DEMO 9: FORWARD DECLARATION ===\n";

    Engine engine(150);
    EnginePointerHolder holder(&engine);

    std::cout << "Holder has engine? "
              << holder.hasEngine()
              << '\n';

    std::cout << "Horsepower = "
              << engine.getHorsepower()
              << '\n';

    std::cout << "\n=== DEMO 10: MULTI-FILE BUILD MODEL ===\n";

    std::cout
        << "math_utils.h   -> declarations\n"
        << "math_utils.cpp -> definitions\n"
        << "main.cpp       -> uses declarations\n"
        << "compiler       -> object files\n"
        << "linker         -> executable\n";

    std::cout << "\nExample build:\n";
    std::cout
        << "g++ -std=c++17 main.cpp "
        << "math_utils.cpp -o app\n";

    std::cout << "\nNext: 28_AUTO_RANGE_BASED_LOOPS\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: NAMESPACES ===
first::value = 10
second::value = 20
first::show
second::show

=== DEMO 2: NESTED NAMESPACE ===
dsa::math::square(6) = 36

=== DEMO 3: NAMESPACE ALIAS ===
mathematics::square(7) = 49

=== DEMO 4: REOPENED NAMESPACE ===
doubleValue(5) = 10
tripleValue(5) = 15

=== DEMO 5: GLOBAL SCOPE RESOLUTION ===
Local number = 25
Global number = 100

=== DEMO 6: USING DECLARATION ===
specific std::string imported

=== DEMO 7: ANONYMOUS NAMESPACE ===
localHelper(9) = 10

=== DEMO 8: DECLARATION / DEFINITION ===
subtract(10, 3) = 7

=== DEMO 9: FORWARD DECLARATION ===
Holder has engine? true
Horsepower = 150

=== DEMO 10: MULTI-FILE BUILD MODEL ===
math_utils.h   -> declarations
math_utils.cpp -> definitions
main.cpp       -> uses declarations
compiler       -> object files
linker         -> executable

Example build:
g++ -std=c++17 main.cpp math_utils.cpp -o app

Next: 28_AUTO_RANGE_BASED_LOOPS
*/
