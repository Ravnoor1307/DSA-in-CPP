/*
Topic: Lambdas

Covers:
- basic lambda syntax
- closure objects
- value/reference captures
- default and mixed captures
- mutable lambdas
- init-capture
- generic lambdas
- lambdas with algorithms
- std::function
- function pointer conversion
- this capture
- immediately invoked lambdas

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// ========== SECTION 1: LAMBDA AS FUNCTION ARGUMENT ==========

template <typename Function>
void repeat(int times, Function action) {
    for (int i = 0; i < times; ++i) {
        action();
    }
}

// ========== SECTION 2: RETURNING A LAMBDA ==========

auto makeMultiplier(int factor) {
    return [factor](int value) {
        return factor * value;
    };
}

// ========== SECTION 3: THIS CAPTURE ==========

class Counter {
private:
    int value;

public:
    explicit Counter(int value)
        : value(value) {
    }

    void demonstrateLambda() const {
        auto readValue = [this]() {
            return value;
        };

        std::cout << "Captured this value = "
                  << readValue() << '\n';
    }
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== DEMO 1: BASIC LAMBDA ===\n";

    auto square = [](int value) {
        return value * value;
    };

    std::cout << "square(6) = "
              << square(6) << '\n';

    std::cout << "\n=== DEMO 2: PARAMETERS ===\n";

    auto add = [](int a, int b) {
        return a + b;
    };

    std::cout << "add(3, 4) = "
              << add(3, 4) << '\n';

    std::cout << "\n=== DEMO 3: VALUE CAPTURE ===\n";

    int factor = 3;

    auto multiply = [factor](int value) {
        return factor * value;
    };

    factor = 10;

    std::cout << "Outside factor = "
              << factor << '\n';

    std::cout << "multiply(5) = "
              << multiply(5) << '\n';

    std::cout << "\n=== DEMO 4: REFERENCE CAPTURE ===\n";

    int total = 0;

    auto addToTotal = [&total](int value) {
        total += value;
    };

    addToTotal(10);
    addToTotal(20);

    std::cout << "total = "
              << total << '\n';

    std::cout << "\n=== DEMO 5: DEFAULT CAPTURES ===\n";

    int a = 10;
    int b = 20;

    auto valueCapture = [=]() {
        return a + b;
    };

    auto referenceCapture = [&]() {
        ++a;
        ++b;
    };

    std::cout << "Captured sum = "
              << valueCapture() << '\n';

    referenceCapture();

    std::cout << "After reference capture: "
              << a << ", "
              << b << '\n';

    std::cout << "\n=== DEMO 6: MIXED CAPTURE ===\n";

    int limit = 100;
    int used = 20;

    auto consume = [limit, &used](int amount) {
        if (used + amount <= limit) {
            used += amount;
            return true;
        }

        return false;
    };

    std::cout << "Consume 30? "
              << consume(30) << '\n';

    std::cout << "Used = "
              << used << '\n';

    std::cout << "\n=== DEMO 7: mutable ===\n";

    int starting = 5;

    auto next = [starting]() mutable {
        return ++starting;
    };

    std::cout << next() << '\n';
    std::cout << next() << '\n';

    std::cout << "Outside starting = "
              << starting << '\n';

    std::cout << "\n=== DEMO 8: INIT-CAPTURE ===\n";

    int base = 4;

    auto scaled = [
        factorCopy = base * 2
    ](int value) {
        return factorCopy * value;
    };

    std::cout << "scaled(3) = "
              << scaled(3) << '\n';

    std::cout << "\n=== DEMO 9: GENERIC LAMBDA ===\n";

    auto genericAdd = [](auto left, auto right) {
        return left + right;
    };

    std::cout << "ints: "
              << genericAdd(2, 3) << '\n';

    std::cout << "doubles: "
              << genericAdd(2.5, 1.5) << '\n';

    std::cout << "\n=== DEMO 10: LAMBDA AS ARGUMENT ===\n";

    repeat(3, []() {
        std::cout << "Hello\n";
    });

    std::cout << "\n=== DEMO 11: RETURNED LAMBDA ===\n";

    auto triple = makeMultiplier(3);

    std::cout << "triple(7) = "
              << triple(7) << '\n';

    std::cout << "\n=== DEMO 12: ALGORITHM PREDICATE ===\n";

    std::vector<int> values{
        1, 2, 3, 4, 5, 6
    };

    auto evenCount = std::count_if(
        values.begin(),
        values.end(),
        [](int value) {
            return value % 2 == 0;
        }
    );

    std::cout << "Even count = "
              << evenCount << '\n';

    std::cout << "\n=== DEMO 13: SORT COMPARATOR ===\n";

    std::sort(
        values.begin(),
        values.end(),
        [](int left, int right) {
            return left > right;
        }
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== DEMO 14: std::function ===\n";

    std::function<int(int, int)> operation =
        [](int left, int right) {
            return left * right;
        };

    std::cout << "operation(4, 5) = "
              << operation(4, 5)
              << '\n';

    std::cout << "\n=== DEMO 15: FUNCTION POINTER ===\n";

    int (*subtract)(int, int) =
        [](int left, int right) {
            return left - right;
        };

    std::cout << "subtract(10, 3) = "
              << subtract(10, 3)
              << '\n';

    std::cout << "\n=== DEMO 16: this CAPTURE ===\n";

    Counter counter(42);
    counter.demonstrateLambda();

    std::cout << "\n=== DEMO 17: IMMEDIATE INVOCATION ===\n";

    int immediate = [](int x) {
        return x * 10;
    }(7);

    std::cout << "Immediate result = "
              << immediate << '\n';

    std::cout << "\nNext: 30_SMART_POINTERS_AND_RAII\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: BASIC LAMBDA ===
square(6) = 36

=== DEMO 2: PARAMETERS ===
add(3, 4) = 7

=== DEMO 3: VALUE CAPTURE ===
Outside factor = 10
multiply(5) = 15

=== DEMO 4: REFERENCE CAPTURE ===
total = 30

=== DEMO 5: DEFAULT CAPTURES ===
Captured sum = 30
After reference capture: 11, 21

=== DEMO 6: MIXED CAPTURE ===
Consume 30? true
Used = 50

=== DEMO 7: mutable ===
6
7
Outside starting = 5

=== DEMO 8: INIT-CAPTURE ===
scaled(3) = 24

=== DEMO 9: GENERIC LAMBDA ===
ints: 5
doubles: 4

=== DEMO 10: LAMBDA AS ARGUMENT ===
Hello
Hello
Hello

=== DEMO 11: RETURNED LAMBDA ===
triple(7) = 21

=== DEMO 12: ALGORITHM PREDICATE ===
Even count = 3

=== DEMO 13: SORT COMPARATOR ===
6 5 4 3 2 1

=== DEMO 14: std::function ===
operation(4, 5) = 20

=== DEMO 15: FUNCTION POINTER ===
subtract(10, 3) = 7

=== DEMO 16: this CAPTURE ===
Captured this value = 42

=== DEMO 17: IMMEDIATE INVOCATION ===
Immediate result = 70

Next: 30_SMART_POINTERS_AND_RAII
*/
