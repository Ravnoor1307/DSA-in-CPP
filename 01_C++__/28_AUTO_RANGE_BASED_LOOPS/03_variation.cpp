/*
Topic: auto and Range-Based Loops
File: 03_variation.cpp

Purpose:
Explore:
- top-level const deduction
- pointer deduction
- structured bindings
- value vs reference bindings
- copying of class objects during iteration

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>
#include <utility>

// ========== SECTION 1: TRACK COPIES ==========

class Item {
private:
    int value;

public:
    explicit Item(int value = 0)
        : value(value) {
    }

    Item(const Item& other)
        : value(other.value) {
        std::cout << "Item copied: "
                  << value << '\n';
    }

    int get() const {
        return value;
    }

    void add(int amount) {
        value += amount;
    }
};

// ========== SECTION 2: STRUCTURED BINDING ==========

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::cout << "=== VARIATION 1: TOP-LEVEL const ===\n";

    const int fixed = 10;

    auto copy = fixed;
    copy = 20;

    const auto anotherFixed = fixed;

    std::cout << "fixed = "
              << fixed << '\n';

    std::cout << "copy = "
              << copy << '\n';

    std::cout << "anotherFixed = "
              << anotherFixed << '\n';

    std::cout << "\n=== VARIATION 2: auto POINTER ===\n";

    int number = 5;

    auto* pointer = &number;

    *pointer = 15;

    std::cout << "number = "
              << number << '\n';

    std::cout << "\n=== VARIATION 3: LOOP COPIES ===\n";

    Item items[] = {
        Item(10),
        Item(20),
        Item(30)
    };

    std::cout << "By value:\n";

    for (auto item : items) {
        std::cout << "Read "
                  << item.get()
                  << '\n';
    }

    std::cout << "By const reference:\n";

    for (const auto& item : items) {
        std::cout << "Read "
                  << item.get()
                  << '\n';
    }

    std::cout << "\n=== VARIATION 4: MODIFY BY REFERENCE ===\n";

    for (auto& item : items) {
        item.add(5);
    }

    for (const auto& item : items) {
        std::cout << item.get()
                  << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== VARIATION 5: STRUCTURED BINDING COPY ===\n";

    Student student{
        "Asha",
        90
    };

    auto [nameCopy, marksCopy] = student;

    marksCopy = 100;

    std::cout << "Copy marks = "
              << marksCopy << '\n';

    std::cout << "Original marks = "
              << student.marks << '\n';

    std::cout << "\n=== VARIATION 6: STRUCTURED BINDING REFERENCE ===\n";

    auto& [nameRef, marksRef] = student;

    marksRef = 95;
    nameRef = "Asha Sharma";

    std::cout << student.name
              << " -> "
              << student.marks
              << '\n';

    std::cout << "\n=== VARIATION 7: PAIR ===\n";

    std::pair<std::string, int> entry{
        "graph",
        42
    };

    const auto& [key, value] = entry;

    std::cout << key
              << " -> "
              << value
              << '\n';

    std::cout << "\nNext: 29_LAMBDAS\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: TOP-LEVEL const ===
fixed = 10
copy = 20
anotherFixed = 10

=== VARIATION 2: auto POINTER ===
number = 15

=== VARIATION 3: LOOP COPIES ===
By value:
Item copied: 10
Read 10
Item copied: 20
Read 20
Item copied: 30
Read 30
By const reference:
Read 10
Read 20
Read 30

=== VARIATION 4: MODIFY BY REFERENCE ===
15 25 35

=== VARIATION 5: STRUCTURED BINDING COPY ===
Copy marks = 100
Original marks = 90

=== VARIATION 6: STRUCTURED BINDING REFERENCE ===
Asha Sharma -> 95

=== VARIATION 7: PAIR ===
graph -> 42

Next: 29_LAMBDAS
*/
