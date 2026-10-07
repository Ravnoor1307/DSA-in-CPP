/*
Topic: auto and Range-Based Loops
File: 02_basics.cpp

Purpose:
Practice type deduction and choosing value/reference loop variables.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "=== BASIC 1: auto DEDUCTION ===\n";

    auto age = 20;
    auto price = 99.5;
    auto name = std::string("Asha");

    std::cout << "age = "
              << age << '\n';

    std::cout << "price = "
              << price << '\n';

    std::cout << "name = "
              << name << '\n';

    std::cout << "\n=== BASIC 2: COPY VS REFERENCE ===\n";

    int value = 10;

    auto copy = value;
    auto& reference = value;

    copy = 20;
    reference = 30;

    std::cout << "value = "
              << value << '\n';

    std::cout << "copy = "
              << copy << '\n';

    std::cout << "\n=== BASIC 3: VALUE LOOP ===\n";

    int values[] = {1, 2, 3};

    for (auto element : values) {
        element += 100;
    }

    for (auto element : values) {
        std::cout << element << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== BASIC 4: REFERENCE LOOP ===\n";

    for (auto& element : values) {
        element += 100;
    }

    for (const auto& element : values) {
        std::cout << element << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== BASIC 5: STRING ===\n";

    std::string text = "abc";

    for (auto& character : text) {
        character = static_cast<char>(
            character + 1
        );
    }

    std::cout << text << '\n';

    std::cout << "\n=== BASIC 6: VECTOR ===\n";

    std::vector<int> scores = {
        70, 80, 90
    };

    int total = 0;

    for (const auto& score : scores) {
        total += score;
    }

    std::cout << "Total = "
              << total << '\n';

    std::cout << "\n=== BASIC 7: NESTED ARRAY ===\n";

    int matrix[2][2] = {
        {1, 2},
        {3, 4}
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

=== BASIC 1: auto DEDUCTION ===
age = 20
price = 99.5
name = Asha

=== BASIC 2: COPY VS REFERENCE ===
value = 30
copy = 20

=== BASIC 3: VALUE LOOP ===
1 2 3

=== BASIC 4: REFERENCE LOOP ===
101 102 103

=== BASIC 5: STRING ===
bcd

=== BASIC 6: VECTOR ===
Total = 240

=== BASIC 7: NESTED ARRAY ===
1 2
3 4

Next: 29_LAMBDAS
*/
