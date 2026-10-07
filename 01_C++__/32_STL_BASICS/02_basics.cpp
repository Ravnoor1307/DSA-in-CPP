/*
Topic: STL Basics
File: 02_basics.cpp

Purpose:
Practice the STL tools most frequently encountered in basic DSA code.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

int main() {
    std::cout << std::boolalpha;

    // ========== SECTION 1: VECTOR BASICS ==========

    std::cout << "=== BASIC 1: vector ===\n";

    std::vector<int> values{
        5, 2, 8, 2, 1
    };

    std::cout << "size = "
              << values.size()
              << '\n';

    std::cout << "first = "
              << values.front()
              << '\n';

    std::cout << "last = "
              << values.back()
              << '\n';

    values.push_back(10);

    std::cout << "after push_back: ";

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 2: SORT ==========

    std::cout << "\n=== BASIC 2: sort ===\n";

    std::sort(
        values.begin(),
        values.end()
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 3: FIND ==========

    std::cout << "\n=== BASIC 3: find ===\n";

    auto found = std::find(
        values.begin(),
        values.end(),
        8
    );

    std::cout << "Found 8? "
              << (found != values.end())
              << '\n';

    // ========== SECTION 4: ACCUMULATE ==========

    std::cout << "\n=== BASIC 4: accumulate ===\n";

    std::cout << "Sum = "
              << std::accumulate(
                     values.begin(),
                     values.end(),
                     0
                 )
              << '\n';

    // ========== SECTION 5: SET ==========

    std::cout << "\n=== BASIC 5: set ===\n";

    std::set<int> unique(
        values.begin(),
        values.end()
    );

    for (int value : unique) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 6: MAP ==========

    std::cout << "\n=== BASIC 6: map frequency ===\n";

    std::map<int, int> frequency;

    for (int value : values) {
        ++frequency[value];
    }

    for (const auto& [value, count] : frequency) {
        std::cout << value
                  << " -> "
                  << count
                  << '\n';
    }

    // ========== SECTION 7: STACK ==========

    std::cout << "\n=== BASIC 7: stack ===\n";

    std::stack<int> stack;

    for (int value : {10, 20, 30}) {
        stack.push(value);
    }

    while (!stack.empty()) {
        std::cout << stack.top()
                  << ' ';

        stack.pop();
    }

    std::cout << '\n';

    // ========== SECTION 8: QUEUE ==========

    std::cout << "\n=== BASIC 8: queue ===\n";

    std::queue<int> queue;

    for (int value : {10, 20, 30}) {
        queue.push(value);
    }

    while (!queue.empty()) {
        std::cout << queue.front()
                  << ' ';

        queue.pop();
    }

    std::cout << '\n';

    // ========== SECTION 9: PRIORITY QUEUE ==========

    std::cout << "\n=== BASIC 9: priority_queue ===\n";

    std::priority_queue<int> priority;

    priority.push(20);
    priority.push(50);
    priority.push(10);

    while (!priority.empty()) {
        std::cout << priority.top()
                  << ' ';

        priority.pop();
    }

    std::cout << '\n';

    // ========== SECTION 10: BINARY SEARCH ==========

    std::cout << "\n=== BASIC 10: binary search ===\n";

    std::cout << "Contains 5? "
              << std::binary_search(
                     values.begin(),
                     values.end(),
                     5
                 )
              << '\n';

    std::cout << "Contains 99? "
              << std::binary_search(
                     values.begin(),
                     values.end(),
                     99
                 )
              << '\n';

    std::cout << "\nNext: 33_C++_FOR_COMPETITIVE_PROGRAMMING\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: vector ===
size = 5
first = 5
last = 1
after push_back: 5 2 8 2 1 10

=== BASIC 2: sort ===
1 2 2 5 8 10

=== BASIC 3: find ===
Found 8? true

=== BASIC 4: accumulate ===
Sum = 28

=== BASIC 5: set ===
1 2 5 8 10

=== BASIC 6: map frequency ===
1 -> 1
2 -> 2
5 -> 1
8 -> 1
10 -> 1

=== BASIC 7: stack ===
30 20 10

=== BASIC 8: queue ===
10 20 30

=== BASIC 9: priority_queue ===
50 20 10

=== BASIC 10: binary search ===
Contains 5? true
Contains 99? false

Next: 33_C++_FOR_COMPETITIVE_PROGRAMMING
*/
