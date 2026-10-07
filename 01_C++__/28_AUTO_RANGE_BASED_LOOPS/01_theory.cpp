/*
Topic: auto and Range-Based Loops

Covers:
- auto deduction
- copies and references
- const auto&
- auto pointers
- function return deduction
- range-based for
- modification through references
- arrays, strings, std::array, std::vector
- structured bindings
- nested iteration

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// ========== SECTION 1: BASIC auto ==========

auto add(int a, int b) {
    return a + b;
}

// ========== SECTION 2: STRUCTURED BINDING TYPE ==========

struct Point {
    int x;
    int y;
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== DEMO 1: BASIC auto ===\n";

    auto integer = 10;
    auto decimal = 3.5;
    auto letter = 'A';
    auto text = std::string("DSA");

    std::cout << integer << '\n';
    std::cout << decimal << '\n';
    std::cout << letter << '\n';
    std::cout << text << '\n';

    std::cout << "\n=== DEMO 2: auto MAKES A VALUE ===\n";

    int original = 10;
    auto copy = original;

    copy = 50;

    std::cout << "original = "
              << original << '\n';

    std::cout << "copy = "
              << copy << '\n';

    std::cout << "\n=== DEMO 3: auto& MAKES A REFERENCE ===\n";

    auto& reference = original;

    reference = 80;

    std::cout << "original after reference change = "
              << original << '\n';

    std::cout << "\n=== DEMO 4: const auto& ===\n";

    const auto& readOnly = original;

    std::cout << "readOnly = "
              << readOnly << '\n';

    // readOnly = 100;
    // ERROR: readOnly is a reference to const.

    std::cout << "\n=== DEMO 5: TOP-LEVEL const ===\n";

    const int fixed = 25;

    auto mutableCopy = fixed;
    mutableCopy = 30;

    std::cout << "fixed = "
              << fixed << '\n';

    std::cout << "mutableCopy = "
              << mutableCopy << '\n';

    std::cout << "\n=== DEMO 6: auto POINTER ===\n";

    int value = 42;

    auto* pointer = &value;

    *pointer = 99;

    std::cout << "value = "
              << value << '\n';

    std::cout << "\n=== DEMO 7: DEDUCED FUNCTION RETURN ===\n";

    auto sum = add(4, 5);

    std::cout << "add(4, 5) = "
              << sum << '\n';

    std::cout << "\n=== DEMO 8: RANGE LOOP BY VALUE ===\n";

    int values[] = {10, 20, 30};

    for (auto item : values) {
        item *= 2;
    }

    std::cout << "Array remains: ";

    for (auto item : values) {
        std::cout << item << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== DEMO 9: RANGE LOOP BY REFERENCE ===\n";

    for (auto& item : values) {
        item *= 2;
    }

    std::cout << "Array becomes: ";

    for (const auto& item : values) {
        std::cout << item << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== DEMO 10: STRING RANGE ===\n";

    std::string word = "dsa";

    for (auto& character : word) {
        if (character >= 'a' && character <= 'z') {
            character = static_cast<char>(
                character - 'a' + 'A'
            );
        }
    }

    std::cout << word << '\n';

    std::cout << "\n=== DEMO 11: std::array ===\n";

    std::array<int, 3> numbers = {1, 2, 3};

    for (const auto& number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== DEMO 12: std::vector ===\n";

    std::vector<int> dynamicValues = {
        5, 10, 15
    };

    for (auto& element : dynamicValues) {
        element += 1;
    }

    for (const auto& element : dynamicValues) {
        std::cout << element << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== DEMO 13: STRUCTURED BINDING ===\n";

    Point point{3, 7};

    auto [x, y] = point;

    x = 100;

    std::cout << "Copied x = "
              << x << '\n';

    std::cout << "Original point.x = "
              << point.x << '\n';

    auto& [realX, realY] = point;

    realX = 50;
    realY = 60;

    std::cout << "Point after reference binding = "
              << point.x
              << ", "
              << point.y
              << '\n';

    std::cout << "\n=== DEMO 14: PAIR BINDING ===\n";

    std::pair<std::string, int> student{
        "Asha",
        95
    };

    const auto& [name, marks] = student;

    std::cout << name
              << " -> "
              << marks
              << '\n';

    std::cout << "\n=== DEMO 15: 2D RANGE LOOP ===\n";

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (const auto& row : matrix) {
        for (auto element : row) {
            std::cout << element << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "\nNext: 29_LAMBDAS\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: BASIC auto ===
10
3.5
A
DSA

=== DEMO 2: auto MAKES A VALUE ===
original = 10
copy = 50

=== DEMO 3: auto& MAKES A REFERENCE ===
original after reference change = 80

=== DEMO 4: const auto& ===
readOnly = 80

=== DEMO 5: TOP-LEVEL const ===
fixed = 25
mutableCopy = 30

=== DEMO 6: auto POINTER ===
value = 99

=== DEMO 7: DEDUCED FUNCTION RETURN ===
add(4, 5) = 9

=== DEMO 8: RANGE LOOP BY VALUE ===
Array remains: 10 20 30

=== DEMO 9: RANGE LOOP BY REFERENCE ===
Array becomes: 20 40 60

=== DEMO 10: STRING RANGE ===
DSA

=== DEMO 11: std::array ===
1 2 3

=== DEMO 12: std::vector ===
6 11 16

=== DEMO 13: STRUCTURED BINDING ===
Copied x = 100
Original point.x = 3
Point after reference binding = 50, 60

=== DEMO 14: PAIR BINDING ===
Asha -> 95

=== DEMO 15: 2D RANGE LOOP ===
1 2 3
4 5 6

Next: 29_LAMBDAS
*/
