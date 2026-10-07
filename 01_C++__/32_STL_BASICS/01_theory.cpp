/*
Topic: STL Basics

Covers:
- containers
- vector, array, deque, list
- set, map, unordered containers
- stack, queue, priority_queue
- pair
- iterators and half-open ranges
- common algorithms
- lambdas with algorithms
- binary search helpers
- iterator invalidation awareness

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int main() {
    std::cout << std::boolalpha;

    // ========== SECTION 1: VECTOR ==========

    std::cout << "=== DEMO 1: vector ===\n";

    std::vector<int> values;

    values.push_back(30);
    values.push_back(10);
    values.push_back(20);

    std::cout << "size = "
              << values.size() << '\n';

    std::cout << "values: ";

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 2: ARRAY ==========

    std::cout << "\n=== DEMO 2: array ===\n";

    std::array<int, 3> fixed{
        4, 5, 6
    };

    std::cout << "fixed size = "
              << fixed.size() << '\n';

    std::cout << "fixed[1] = "
              << fixed[1] << '\n';

    // ========== SECTION 3: DEQUE ==========

    std::cout << "\n=== DEMO 3: deque ===\n";

    std::deque<int> deck;

    deck.push_back(20);
    deck.push_front(10);
    deck.push_back(30);

    std::cout << "front = "
              << deck.front() << '\n';

    std::cout << "back = "
              << deck.back() << '\n';

    // ========== SECTION 4: LIST ==========

    std::cout << "\n=== DEMO 4: list ===\n";

    std::list<int> linked{
        30, 10, 20
    };

    linked.sort();

    for (int value : linked) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 5: SET ==========

    std::cout << "\n=== DEMO 5: set ===\n";

    std::set<int> uniqueValues{
        30, 10, 20, 10
    };

    for (int value : uniqueValues) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "Contains 20? "
              << (uniqueValues.find(20)
                  != uniqueValues.end())
              << '\n';

    // ========== SECTION 6: MAP ==========

    std::cout << "\n=== DEMO 6: map ===\n";

    std::map<std::string, int> marks;

    marks["Asha"] = 95;
    marks["Ravi"] = 87;

    for (const auto& [name, mark] : marks) {
        std::cout << name
                  << " -> "
                  << mark
                  << '\n';
    }

    // ========== SECTION 7: UNORDERED CONTAINERS ==========

    std::cout << "\n=== DEMO 7: unordered containers ===\n";

    std::unordered_set<int> lookup{
        10, 20, 30
    };

    std::cout << "unordered_set has 20? "
              << (lookup.find(20)
                  != lookup.end())
              << '\n';

    std::unordered_map<char, int> frequency;

    std::string word = "banana";

    for (char character : word) {
        ++frequency[character];
    }

    // Access explicitly so output order is deterministic.
    std::cout << "b = "
              << frequency['b'] << '\n';

    std::cout << "a = "
              << frequency['a'] << '\n';

    std::cout << "n = "
              << frequency['n'] << '\n';

    // ========== SECTION 8: STACK ==========

    std::cout << "\n=== DEMO 8: stack ===\n";

    std::stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "top = "
              << stack.top() << '\n';

    stack.pop();

    std::cout << "after pop = "
              << stack.top() << '\n';

    // ========== SECTION 9: QUEUE ==========

    std::cout << "\n=== DEMO 9: queue ===\n";

    std::queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << "front = "
              << queue.front() << '\n';

    queue.pop();

    std::cout << "after pop = "
              << queue.front() << '\n';

    // ========== SECTION 10: PRIORITY QUEUE ==========

    std::cout << "\n=== DEMO 10: priority_queue ===\n";

    std::priority_queue<int> heap;

    heap.push(10);
    heap.push(50);
    heap.push(20);

    std::cout << "top = "
              << heap.top() << '\n';

    heap.pop();

    std::cout << "next = "
              << heap.top() << '\n';

    // ========== SECTION 11: PAIR ==========

    std::cout << "\n=== DEMO 11: pair ===\n";

    std::pair<std::string, int> student{
        "Mina",
        90
    };

    const auto& [studentName, studentMark] =
        student;

    std::cout << studentName
              << " -> "
              << studentMark
              << '\n';

    // ========== SECTION 12: ITERATORS ==========

    std::cout << "\n=== DEMO 12: iterators ===\n";

    auto iterator = values.begin();

    std::cout << "First through iterator = "
              << *iterator << '\n';

    ++iterator;

    std::cout << "Second = "
              << *iterator << '\n';

    // ========== SECTION 13: SORT ==========

    std::cout << "\n=== DEMO 13: sort ===\n";

    std::sort(
        values.begin(),
        values.end()
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 14: FIND / COUNT ==========

    std::cout << "\n=== DEMO 14: find and count ===\n";

    auto found = std::find(
        values.begin(),
        values.end(),
        20
    );

    std::cout << "Found 20? "
              << (found != values.end())
              << '\n';

    std::vector<int> duplicates{
        1, 2, 2, 2, 3
    };

    std::cout << "Count of 2 = "
              << std::count(
                     duplicates.begin(),
                     duplicates.end(),
                     2
                 )
              << '\n';

    // ========== SECTION 15: COUNT_IF ==========

    std::cout << "\n=== DEMO 15: count_if ===\n";

    auto evenCount = std::count_if(
        duplicates.begin(),
        duplicates.end(),
        [](int value) {
            return value % 2 == 0;
        }
    );

    std::cout << "Even count = "
              << evenCount << '\n';

    // ========== SECTION 16: REVERSE ==========

    std::cout << "\n=== DEMO 16: reverse ===\n";

    std::reverse(
        values.begin(),
        values.end()
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // Restore ascending order for binary search demos.
    std::sort(
        values.begin(),
        values.end()
    );

    // ========== SECTION 17: MIN / MAX ==========

    std::cout << "\n=== DEMO 17: min/max ===\n";

    auto minimum = std::min_element(
        values.begin(),
        values.end()
    );

    auto maximum = std::max_element(
        values.begin(),
        values.end()
    );

    std::cout << "min = "
              << *minimum << '\n';

    std::cout << "max = "
              << *maximum << '\n';

    // ========== SECTION 18: ACCUMULATE ==========

    std::cout << "\n=== DEMO 18: accumulate ===\n";

    int sum = std::accumulate(
        values.begin(),
        values.end(),
        0
    );

    std::cout << "sum = "
              << sum << '\n';

    // ========== SECTION 19: BINARY SEARCH ==========

    std::cout << "\n=== DEMO 19: binary_search ===\n";

    std::cout << "Contains 20? "
              << std::binary_search(
                     values.begin(),
                     values.end(),
                     20
                 )
              << '\n';

    // ========== SECTION 20: BOUNDS ==========

    std::cout << "\n=== DEMO 20: lower/upper bound ===\n";

    std::vector<int> sorted{
        1, 3, 3, 3, 5, 8
    };

    auto lower = std::lower_bound(
        sorted.begin(),
        sorted.end(),
        3
    );

    auto upper = std::upper_bound(
        sorted.begin(),
        sorted.end(),
        3
    );

    std::cout << "lower index = "
              << (lower - sorted.begin())
              << '\n';

    std::cout << "upper index = "
              << (upper - sorted.begin())
              << '\n';

    std::cout << "number of 3s = "
              << (upper - lower)
              << '\n';

    // ========== SECTION 21: CUSTOM SORT ==========

    std::cout << "\n=== DEMO 21: lambda comparator ===\n";

    std::sort(
        sorted.begin(),
        sorted.end(),
        [](int a, int b) {
            return a > b;
        }
    );

    for (int value : sorted) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "\nNext: 33_C++_FOR_COMPETITIVE_PROGRAMMING\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: vector ===
size = 3
values: 30 10 20

=== DEMO 2: array ===
fixed size = 3
fixed[1] = 5

=== DEMO 3: deque ===
front = 10
back = 30

=== DEMO 4: list ===
10 20 30

=== DEMO 5: set ===
10 20 30
Contains 20? true

=== DEMO 6: map ===
Asha -> 95
Ravi -> 87

=== DEMO 7: unordered containers ===
unordered_set has 20? true
b = 1
a = 3
n = 2

=== DEMO 8: stack ===
top = 30
after pop = 20

=== DEMO 9: queue ===
front = 10
after pop = 20

=== DEMO 10: priority_queue ===
top = 50
next = 20

=== DEMO 11: pair ===
Mina -> 90

=== DEMO 12: iterators ===
First through iterator = 30
Second = 10

=== DEMO 13: sort ===
10 20 30

=== DEMO 14: find and count ===
Found 20? true
Count of 2 = 3

=== DEMO 15: count_if ===
Even count = 3

=== DEMO 16: reverse ===
30 20 10

=== DEMO 17: min/max ===
min = 10
max = 30

=== DEMO 18: accumulate ===
sum = 60

=== DEMO 19: binary_search ===
Contains 20? true

=== DEMO 20: lower/upper bound ===
lower index = 1
upper index = 4
number of 3s = 3

=== DEMO 21: lambda comparator ===
8 5 3 3 3 1

Next: 33_C++_FOR_COMPETITIVE_PROGRAMMING
*/
