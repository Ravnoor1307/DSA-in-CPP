/*
Topic: Move Semantics Basics
File: 04_practice_problems.cpp

Practice:
1. Identify lvalue/rvalue overloads
2. Transfer unique_ptr ownership
3. Move a vector and reuse the source
4. Implement a small movable resource owner
5. Apply the Rule of Zero

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// ========== PROBLEM 1: VALUE CATEGORY OVERLOAD ==========

void identify(const int&) {
    std::cout << "lvalue-compatible\n";
}

void identify(int&&) {
    std::cout << "rvalue\n";
}

void problem1() {
    int value = 10;

    identify(value);
    identify(20);
    identify(std::move(value));
}

// ========== PROBLEM 2: unique_ptr TRANSFER ==========

void takeOwnership(
    std::unique_ptr<int> value
) {
    std::cout << "Received "
              << *value << '\n';
}

void problem2() {
    auto pointer =
        std::make_unique<int>(42);

    std::cout << std::boolalpha;

    std::cout << "Before = "
              << static_cast<bool>(pointer)
              << '\n';

    takeOwnership(std::move(pointer));

    std::cout << "After = "
              << static_cast<bool>(pointer)
              << '\n';
}

// ========== PROBLEM 3: MOVE VECTOR ==========

void problem3() {
    std::vector<int> source{
        1, 2, 3, 4
    };

    std::vector<int> destination =
        std::move(source);

    std::cout << "Destination: ";

    for (int value : destination) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // Do not assume source.empty() is guaranteed merely because it
    // was moved from. Establish a new known state instead.
    source = {9, 8};

    std::cout << "Reused source: ";

    for (int value : source) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

// ========== PROBLEM 4: MOVABLE RESOURCE OWNER ==========
//
// This class deliberately manages a raw resource for education.
// In production, prefer Rule-of-Zero members such as unique_ptr.
//
// Copying is disabled.
// Moving transfers exclusive ownership.

class IntOwner {
private:
    int* pointer;

public:
    explicit IntOwner(int value)
        : pointer(new int(value)) {
        std::cout << "Allocate "
                  << *pointer << '\n';
    }

    IntOwner(const IntOwner&) = delete;
    IntOwner& operator=(const IntOwner&) = delete;

    IntOwner(IntOwner&& other) noexcept
        : pointer(other.pointer) {
        other.pointer = nullptr;

        std::cout << "Move owner\n";
    }

    IntOwner& operator=(
        IntOwner&& other
    ) noexcept {
        if (this != &other) {
            delete pointer;

            pointer = other.pointer;
            other.pointer = nullptr;
        }

        std::cout << "Move-assign owner\n";

        return *this;
    }

    bool hasValue() const {
        return pointer != nullptr;
    }

    int get() const {
        return pointer ? *pointer : -1;
    }

    ~IntOwner() {
        if (pointer) {
            std::cout << "Delete "
                      << *pointer << '\n';
        }

        delete pointer;
    }
};

void problem4() {
    IntOwner first(100);

    IntOwner second(
        std::move(first)
    );

    std::cout << std::boolalpha;

    std::cout << "first owns? "
              << first.hasValue()
              << '\n';

    std::cout << "second = "
              << second.get()
              << '\n';

    IntOwner third(200);

    third = std::move(second);

    std::cout << "second owns? "
              << second.hasValue()
              << '\n';

    std::cout << "third = "
              << third.get()
              << '\n';
}

// ========== PROBLEM 5: RULE OF ZERO ==========

class Student {
private:
    std::string name;
    std::vector<int> marks;

public:
    Student(
        std::string name,
        std::vector<int> marks
    )
        : name(std::move(name)),
          marks(std::move(marks)) {
    }

    int total() const {
        int result = 0;

        for (int mark : marks) {
            result += mark;
        }

        return result;
    }

    const std::string& getName() const {
        return name;
    }
};

void problem5() {
    Student student(
        "Asha",
        std::vector<int>{90, 80, 85}
    );

    std::cout << student.getName()
              << " total = "
              << student.total()
              << '\n';

    // No custom destructor, copy constructor, move constructor,
    // or assignment operators were needed.
}

int main() {
    std::cout << "=== PROBLEM 1: VALUE CATEGORIES ===\n";
    problem1();

    std::cout << "\n=== PROBLEM 2: unique_ptr MOVE ===\n";
    problem2();

    std::cout << "\n=== PROBLEM 3: VECTOR MOVE ===\n";
    problem3();

    std::cout << "\n=== PROBLEM 4: CUSTOM MOVE OWNER ===\n";
    problem4();

    std::cout << "\n=== PROBLEM 5: RULE OF ZERO ===\n";
    problem5();

    std::cout << "\nNext: 32_STL_BASICS\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: VALUE CATEGORIES ===
lvalue-compatible
rvalue
rvalue

=== PROBLEM 2: unique_ptr MOVE ===
Before = true
Received 42
After = false

=== PROBLEM 3: VECTOR MOVE ===
Destination: 1 2 3 4
Reused source: 9 8

=== PROBLEM 4: CUSTOM MOVE OWNER ===
Allocate 100
Move owner
first owns? false
second = 100
Allocate 200
Move-assign owner
second owns? false
third = 100
Delete 100

=== PROBLEM 5: RULE OF ZERO ===
Asha total = 255

Next: 32_STL_BASICS
*/
