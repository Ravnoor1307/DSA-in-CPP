/*
Topic: Lambdas
File: 02_basics.cpp

Purpose:
Practice:
- basic lambdas
- parameters
- captures
- mutable
- generic lambdas
- local predicates

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== BASIC 1: SIMPLE LAMBDA ===\n";

    auto greet = []() {
        std::cout << "Hello from lambda\n";
    };

    greet();

    std::cout << "\n=== BASIC 2: PARAMETERS ===\n";

    auto maximum = [](int a, int b) {
        return a > b ? a : b;
    };

    std::cout << "maximum(10, 25) = "
              << maximum(10, 25)
              << '\n';

    std::cout << "\n=== BASIC 3: VALUE CAPTURE ===\n";

    int multiplier = 4;

    auto multiply = [multiplier](int value) {
        return multiplier * value;
    };

    multiplier = 10;

    std::cout << "multiply(5) = "
              << multiply(5)
              << '\n';

    std::cout << "\n=== BASIC 4: REFERENCE CAPTURE ===\n";

    int counter = 0;

    auto increment = [&counter]() {
        ++counter;
    };

    increment();
    increment();
    increment();

    std::cout << "counter = "
              << counter << '\n';

    std::cout << "\n=== BASIC 5: mutable VALUE CAPTURE ===\n";

    int start = 10;

    auto sequence = [start]() mutable {
        return start++;
    };

    std::cout << sequence() << '\n';
    std::cout << sequence() << '\n';
    std::cout << sequence() << '\n';

    std::cout << "Outside start = "
              << start << '\n';

    std::cout << "\n=== BASIC 6: GENERIC LAMBDA ===\n";

    auto twice = [](auto value) {
        return value + value;
    };

    std::cout << "twice(5) = "
              << twice(5) << '\n';

    std::cout << "twice(2.5) = "
              << twice(2.5) << '\n';

    std::cout << "\n=== BASIC 7: CAPTURED THRESHOLD ===\n";

    std::vector<int> values{
        4, 10, 15, 20
    };

    int threshold = 10;

    auto aboveThreshold = [
        threshold
    ](int value) {
        return value > threshold;
    };

    for (int value : values) {
        if (aboveThreshold(value)) {
            std::cout << value << ' ';
        }
    }

    std::cout << '\n';

    std::cout << "\nNext: 30_SMART_POINTERS_AND_RAII\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: SIMPLE LAMBDA ===
Hello from lambda

=== BASIC 2: PARAMETERS ===
maximum(10, 25) = 25

=== BASIC 3: VALUE CAPTURE ===
multiply(5) = 20

=== BASIC 4: REFERENCE CAPTURE ===
counter = 3

=== BASIC 5: mutable VALUE CAPTURE ===
10
11
12
Outside start = 10

=== BASIC 6: GENERIC LAMBDA ===
twice(5) = 10
twice(2.5) = 5

=== BASIC 7: CAPTURED THRESHOLD ===
15 20

Next: 30_SMART_POINTERS_AND_RAII
*/
