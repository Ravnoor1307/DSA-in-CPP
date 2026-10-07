/*
Topic: Lambdas
File: 03_variation.cpp

Purpose:
Explore:
- init-capture
- returning lambdas
- generic callables
- std::function
- algorithm comparators
- object capture with this and *this

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// ========== SECTION 1: RETURN A SAFE VALUE-CAPTURING LAMBDA ==========

auto makeAdder(int amount) {
    return [amount](int value) {
        return value + amount;
    };
}

// ========== SECTION 2: TEMPLATE ACCEPTING ANY CALLABLE ==========

template <typename Function>
int transformValue(int value, Function function) {
    return function(value);
}

// ========== SECTION 3: CLASS CAPTURE ==========

class Number {
private:
    int value;

public:
    explicit Number(int value)
        : value(value) {
    }

    auto makeReader() const {
        return [this]() {
            return value;
        };
    }

    auto makeSnapshotReader() const {
        return [*this]() {
            return value;
        };
    }

    void set(int newValue) {
        value = newValue;
    }
};

// ========== SECTION 4: OBJECT FOR SORTING ==========

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::cout << "=== VARIATION 1: INIT-CAPTURE ===\n";

    int base = 5;

    auto operation = [
        doubled = base * 2
    ](int value) {
        return doubled + value;
    };

    std::cout << "Result = "
              << operation(3)
              << '\n';

    std::cout << "\n=== VARIATION 2: RETURNED LAMBDA ===\n";

    auto addTen = makeAdder(10);

    std::cout << "addTen(7) = "
              << addTen(7)
              << '\n';

    std::cout << "\n=== VARIATION 3: TEMPLATE CALLABLE ===\n";

    int transformed = transformValue(
        6,
        [](int value) {
            return value * value;
        }
    );

    std::cout << "Transformed = "
              << transformed
              << '\n';

    std::cout << "\n=== VARIATION 4: std::function ===\n";

    std::function<bool(int)> isEven =
        [](int value) {
            return value % 2 == 0;
        };

    std::cout << std::boolalpha;

    std::cout << "8 even? "
              << isEven(8) << '\n';

    std::cout << "7 even? "
              << isEven(7) << '\n';

    std::cout << "\n=== VARIATION 5: CUSTOM SORT ===\n";

    std::vector<Student> students{
        {"Ravi", 80},
        {"Asha", 95},
        {"Mina", 88}
    };

    std::sort(
        students.begin(),
        students.end(),
        [](const Student& left, const Student& right) {
            return left.marks > right.marks;
        }
    );

    for (const auto& student : students) {
        std::cout << student.name
                  << ": "
                  << student.marks
                  << '\n';
    }

    std::cout << "\n=== VARIATION 6: this VS *this ===\n";

    Number number(10);

    auto liveReader = number.makeReader();
    auto snapshotReader = number.makeSnapshotReader();

    number.set(99);

    std::cout << "this reader = "
              << liveReader()
              << '\n';

    std::cout << "*this snapshot = "
              << snapshotReader()
              << '\n';

    // liveReader is safe here because number is still alive.
    // Calling it after number's lifetime ends would be dangerous.

    std::cout << "\nNext: 30_SMART_POINTERS_AND_RAII\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: INIT-CAPTURE ===
Result = 13

=== VARIATION 2: RETURNED LAMBDA ===
addTen(7) = 17

=== VARIATION 3: TEMPLATE CALLABLE ===
Transformed = 36

=== VARIATION 4: std::function ===
8 even? true
7 even? false

=== VARIATION 5: CUSTOM SORT ===
Asha: 95
Mina: 88
Ravi: 80

=== VARIATION 6: this VS *this ===
this reader = 99
*this snapshot = 10

Next: 30_SMART_POINTERS_AND_RAII
*/
