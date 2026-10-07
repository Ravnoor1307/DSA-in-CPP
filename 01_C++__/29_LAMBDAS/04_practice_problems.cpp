/*
Topic: Lambdas
File: 04_practice_problems.cpp

Practice:
1. Even-number predicate
2. Count values above a captured threshold
3. Transform values with a lambda
4. Sort students with a lambda comparator
5. Build a stateful lambda

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ========== PROBLEM 1: EVEN PREDICATE ==========
//
// Predicate call: O(1)

void problem1() {
    auto isEven = [](int value) {
        return value % 2 == 0;
    };

    std::cout << std::boolalpha;

    std::cout << "8 even? "
              << isEven(8) << '\n';

    std::cout << "9 even? "
              << isEven(9) << '\n';
}

// ========== PROBLEM 2: CAPTURED THRESHOLD ==========
//
// Count values greater than a runtime threshold.
//
// Time: O(n)

void problem2() {
    std::vector<int> values{
        2, 7, 10, 15, 20
    };

    int threshold = 9;

    int count = static_cast<int>(
        std::count_if(
            values.begin(),
            values.end(),
            [threshold](int value) {
                return value > threshold;
            }
        )
    );

    std::cout << "Above "
              << threshold
              << " = "
              << count
              << '\n';
}

// ========== PROBLEM 3: TRANSFORM IN PLACE ==========
//
// Modify elements by reference capture.
//
// Time: O(n)

void problem3() {
    std::vector<int> values{
        1, 2, 3, 4
    };

    int multiplier = 3;

    auto multiplyAll = [
        &values,
        multiplier
    ]() {
        for (auto& value : values) {
            value *= multiplier;
        }
    };

    multiplyAll();

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

// ========== PROBLEM 4: CUSTOM SORT ==========
//
// Sort by:
// 1. marks descending
// 2. name ascending when marks tie
//
// std::sort performs O(n log n) comparisons on average/typically
// under its required complexity guarantees.

struct Student {
    std::string name;
    int marks;
};

void problem4() {
    std::vector<Student> students{
        {"Ravi", 90},
        {"Asha", 95},
        {"Mina", 90},
        {"John", 80}
    };

    std::sort(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b) {
            if (a.marks != b.marks) {
                return a.marks > b.marks;
            }

            return a.name < b.name;
        }
    );

    for (const auto& student : students) {
        std::cout << student.name
                  << " "
                  << student.marks
                  << '\n';
    }
}

// ========== PROBLEM 5: STATEFUL LAMBDA ==========
//
// Build a closure that owns its own counter.
//
// mutable lets the closure modify its captured copy.

auto makeCounter(int start) {
    return [start]() mutable {
        return start++;
    };
}

void problem5() {
    auto counter = makeCounter(100);

    std::cout << counter() << '\n';
    std::cout << counter() << '\n';
    std::cout << counter() << '\n';
}

// ========== EXTRA: GENERIC LAMBDA ==========

void extraProblem() {
    auto maximum = [](const auto& a, const auto& b) {
        return a < b ? b : a;
    };

    std::cout << "max int = "
              << maximum(5, 9)
              << '\n';

    std::cout << "max double = "
              << maximum(3.2, 1.5)
              << '\n';
}

int main() {
    std::cout << "=== PROBLEM 1: EVEN PREDICATE ===\n";
    problem1();

    std::cout << "\n=== PROBLEM 2: CAPTURE THRESHOLD ===\n";
    problem2();

    std::cout << "\n=== PROBLEM 3: TRANSFORM ===\n";
    problem3();

    std::cout << "\n=== PROBLEM 4: CUSTOM SORT ===\n";
    problem4();

    std::cout << "\n=== PROBLEM 5: STATEFUL LAMBDA ===\n";
    problem5();

    std::cout << "\n=== EXTRA: GENERIC LAMBDA ===\n";
    extraProblem();

    std::cout << "\nNext: 30_SMART_POINTERS_AND_RAII\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: EVEN PREDICATE ===
8 even? true
9 even? false

=== PROBLEM 2: CAPTURE THRESHOLD ===
Above 9 = 3

=== PROBLEM 3: TRANSFORM ===
3 6 9 12

=== PROBLEM 4: CUSTOM SORT ===
Asha 95
Mina 90
Ravi 90
John 80

=== PROBLEM 5: STATEFUL LAMBDA ===
100
101
102

=== EXTRA: GENERIC LAMBDA ===
max int = 9
max double = 3.2

Next: 30_SMART_POINTERS_AND_RAII
*/
