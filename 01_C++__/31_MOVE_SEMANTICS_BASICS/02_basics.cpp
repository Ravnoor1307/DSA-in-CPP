/*
Topic: Move Semantics Basics
File: 02_basics.cpp

Purpose:
Practice:
- lvalue/rvalue references
- std::move
- moving strings
- moving vectors
- moving unique_ptr
- reusing moved-from standard objects safely

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// ========== SECTION 1: REFERENCE CATEGORY ==========

void inspect(const std::string&) {
    std::cout << "lvalue-compatible overload\n";
}

void inspect(std::string&&) {
    std::cout << "rvalue overload\n";
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== BASIC 1: LVALUE / RVALUE ===\n";

    std::string text = "hello";

    inspect(text);
    inspect(std::string("temporary"));
    inspect(std::move(text));

    // std::move did not itself destroy text.
    // But a function accepting string&& could choose to move from it.
    text = "restored";

    std::cout << "text = "
              << text << '\n';

    std::cout << "\n=== BASIC 2: MOVE STRING ===\n";

    std::string first =
        "Data Structures";

    std::string second =
        std::move(first);

    std::cout << "second = "
              << second << '\n';

    std::cout
        << "first remains valid but contents are unspecified\n";

    first = "Algorithms";

    std::cout << "first reused = "
              << first << '\n';

    std::cout << "\n=== BASIC 3: MOVE VECTOR ===\n";

    std::vector<int> numbers{
        10, 20, 30
    };

    std::vector<int> movedNumbers =
        std::move(numbers);

    std::cout << "Destination: ";

    for (int number : movedNumbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    numbers = {1, 2};

    std::cout << "Source reused: ";

    for (int number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== BASIC 4: MOVE unique_ptr ===\n";

    auto owner =
        std::make_unique<int>(99);

    auto newOwner =
        std::move(owner);

    std::cout << "old owner? "
              << static_cast<bool>(owner)
              << '\n';

    std::cout << "new owner value = "
              << *newOwner
              << '\n';

    std::cout << "\nNext: 32_STL_BASICS\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: LVALUE / RVALUE ===
lvalue-compatible overload
rvalue overload
rvalue overload
text = restored

=== BASIC 2: MOVE STRING ===
second = Data Structures
first remains valid but contents are unspecified
first reused = Algorithms

=== BASIC 3: MOVE VECTOR ===
Destination: 10 20 30
Source reused: 1 2

=== BASIC 4: MOVE unique_ptr ===
old owner? false
new owner value = 99

Next: 32_STL_BASICS
*/
