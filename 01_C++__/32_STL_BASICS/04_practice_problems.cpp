/*
Topic: STL Basics
File: 04_practice_problems.cpp

Practice:
1. Sort and remove duplicates
2. Frequency counting
3. Search using lower_bound
4. Find the top 3 values with priority_queue
5. Count values satisfying a lambda predicate

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// ========== PROBLEM 1: SORT AND UNIQUE ==========
//
// Given:
// [4, 2, 4, 1, 2, 5]
//
// Produce:
// [1, 2, 4, 5]
//
// std::unique does not by itself resize vector.
// It moves duplicate-free values to the front and returns the
// logical new end. erase() removes the leftover tail.
//
// Time: O(n log n), dominated by sorting.

void problem1() {
    std::vector<int> values{
        4, 2, 4, 1, 2, 5
    };

    std::sort(
        values.begin(),
        values.end()
    );

    auto newEnd = std::unique(
        values.begin(),
        values.end()
    );

    values.erase(
        newEnd,
        values.end()
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

// ========== PROBLEM 2: FREQUENCY COUNTING ==========
//
// Average expected time: O(n) with unordered_map.
// Worst case can degrade to O(n^2) across n operations under
// pathological hashing/collision behavior.

void problem2() {
    std::string text = "banana";

    std::unordered_map<char, int> frequency;

    for (char character : text) {
        ++frequency[character];
    }

    // Deterministic output order:
    std::cout << "a = "
              << frequency['a'] << '\n';

    std::cout << "b = "
              << frequency['b'] << '\n';

    std::cout << "n = "
              << frequency['n'] << '\n';
}

// ========== PROBLEM 3: LOWER_BOUND SEARCH ==========
//
// Find the first index containing a value >= target.
//
// Time: O(log n) on sorted vector.

void problem3() {
    std::vector<int> values{
        1, 3, 5, 7, 9
    };

    int target = 6;

    auto position = std::lower_bound(
        values.begin(),
        values.end(),
        target
    );

    if (position != values.end()) {
        std::cout << "First value >= "
                  << target
                  << " is "
                  << *position
                  << " at index "
                  << (position - values.begin())
                  << '\n';
    }
}

// ========== PROBLEM 4: TOP 3 VALUES ==========
//
// Build max-priority queue: O(n log n) via repeated pushes here.
// Removing three elements: O(log n) each.
//
// Later heap lessons will discuss build-heap complexity and
// alternative top-k approaches in depth.

void problem4() {
    std::vector<int> values{
        10, 50, 20, 80, 40, 70
    };

    std::priority_queue<int> heap;

    for (int value : values) {
        heap.push(value);
    }

    std::cout << "Top 3: ";

    for (int i = 0; i < 3; ++i) {
        std::cout << heap.top()
                  << ' ';

        heap.pop();
    }

    std::cout << '\n';
}

// ========== PROBLEM 5: count_if ==========
//
// Count values that are both:
// - greater than threshold
// - even
//
// Time: O(n)

void problem5() {
    std::vector<int> values{
        4, 8, 11, 12, 16, 21, 24
    };

    int threshold = 10;

    auto count = std::count_if(
        values.begin(),
        values.end(),
        [threshold](int value) {
            return value > threshold
                && value % 2 == 0;
        }
    );

    std::cout << "Count = "
              << count << '\n';
}

int main() {
    std::cout << "=== PROBLEM 1: SORT + UNIQUE ===\n";
    problem1();

    std::cout << "\n=== PROBLEM 2: FREQUENCY ===\n";
    problem2();

    std::cout << "\n=== PROBLEM 3: LOWER_BOUND ===\n";
    problem3();

    std::cout << "\n=== PROBLEM 4: TOP 3 ===\n";
    problem4();

    std::cout << "\n=== PROBLEM 5: PREDICATE ===\n";
    problem5();

    std::cout << "\nNext: 33_C++_FOR_COMPETITIVE_PROGRAMMING\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: SORT + UNIQUE ===
1 2 4 5

=== PROBLEM 2: FREQUENCY ===
a = 3
b = 1
n = 2

=== PROBLEM 3: LOWER_BOUND ===
First value >= 6 is 7 at index 3

=== PROBLEM 4: TOP 3 ===
Top 3: 80 70 50

=== PROBLEM 5: PREDICATE ===
Count = 4

Next: 33_C++_FOR_COMPETITIVE_PROGRAMMING
*/
