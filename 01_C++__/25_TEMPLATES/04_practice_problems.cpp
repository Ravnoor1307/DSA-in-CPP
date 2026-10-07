/*
Topic: Templates
File: 04_practice_problems.cpp

Practice:
1. Generic maximum of three values
2. Generic array sum
3. Generic pair
4. Fixed-capacity stack template
5. Generic linear search

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>

using namespace std;

// ========== PROBLEM 1: MAXIMUM OF THREE ==========
//
// Required operation on T:
// operator<
//
// Complexity: O(1) comparisons.

template <typename T>
T maxOfThree(
    const T& a,
    const T& b,
    const T& c
) {
    T best = a;

    if (best < b) {
        best = b;
    }

    if (best < c) {
        best = c;
    }

    return best;
}

// ========== PROBLEM 2: GENERIC ARRAY SUM ==========
//
// Required operations:
// - T can be value-initialized
// - T supports +=
//
// Complexity:
// Time:  O(n)
// Space: O(1) auxiliary, ignoring T's internal costs.

template <typename T>
T arraySum(const T values[], int size) {
    T sum{};

    for (int i = 0; i < size; ++i) {
        sum += values[i];
    }

    return sum;
}

// ========== PROBLEM 3: GENERIC PAIR ==========

template <typename First, typename Second>
class Pair {
private:
    First first;
    Second second;

public:
    Pair(
        const First& first,
        const Second& second
    )
        : first(first), second(second) {
    }

    const First& getFirst() const {
        return first;
    }

    const Second& getSecond() const {
        return second;
    }
};

// ========== PROBLEM 4: FIXED STACK TEMPLATE ==========
//
// The element type is generic.
// Capacity is known at compile time.
//
// push: O(1)
// pop:  O(1)
// top:  O(1)

template <typename T, int Capacity>
class Stack {
private:
    T values[Capacity] = {};
    int currentSize = 0;

public:
    bool push(const T& value) {
        if (currentSize == Capacity) {
            return false;
        }

        values[currentSize] = value;
        ++currentSize;

        return true;
    }

    bool pop() {
        if (currentSize == 0) {
            return false;
        }

        --currentSize;
        return true;
    }

    bool top(T& result) const {
        if (currentSize == 0) {
            return false;
        }

        result = values[currentSize - 1];
        return true;
    }

    int size() const {
        return currentSize;
    }

    bool empty() const {
        return currentSize == 0;
    }
};

// ========== PROBLEM 5: GENERIC LINEAR SEARCH ==========
//
// Required operation:
// operator==
//
// Complexity:
// Time:  O(n)
// Space: O(1)

template <typename T>
int linearSearch(
    const T values[],
    int size,
    const T& target
) {
    for (int i = 0; i < size; ++i) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << boolalpha;

    cout << "=== PROBLEM 1: MAX OF THREE ===\n";

    cout << maxOfThree(10, 30, 20) << '\n';
    cout << maxOfThree(3.5, 7.2, 1.8) << '\n';

    cout << "\n=== PROBLEM 2: ARRAY SUM ===\n";

    int numbers[] = {10, 20, 30, 40};
    double decimals[] = {1.5, 2.5, 3.0};

    cout << "Integer sum = "
         << arraySum(numbers, 4) << '\n';

    cout << "Double sum = "
         << arraySum(decimals, 3) << '\n';

    cout << "\n=== PROBLEM 3: GENERIC PAIR ===\n";

    Pair<string, int> student("Asha", 95);

    cout << student.getFirst()
         << " -> "
         << student.getSecond()
         << '\n';

    cout << "\n=== PROBLEM 4: TEMPLATE STACK ===\n";

    Stack<int, 3> stack;

    cout << "Push 10: "
         << stack.push(10) << '\n';

    cout << "Push 20: "
         << stack.push(20) << '\n';

    cout << "Push 30: "
         << stack.push(30) << '\n';

    cout << "Push 40: "
         << stack.push(40) << '\n';

    int topValue = 0;

    if (stack.top(topValue)) {
        cout << "Top = "
             << topValue << '\n';
    }

    stack.pop();

    if (stack.top(topValue)) {
        cout << "After pop = "
             << topValue << '\n';
    }

    cout << "Size = "
         << stack.size() << '\n';

    cout << "\n=== PROBLEM 5: LINEAR SEARCH ===\n";

    int values[] = {4, 8, 15, 16, 23, 42};

    cout << "Index of 16 = "
         << linearSearch(values, 6, 16)
         << '\n';

    string words[] = {
        "array",
        "tree",
        "graph"
    };

    cout << "Index of graph = "
         << linearSearch(
                words,
                3,
                string("graph")
            )
         << '\n';

    cout << "Index of heap = "
         << linearSearch(
                words,
                3,
                string("heap")
            )
         << '\n';

    cout << "\nNext: 26_EXCEPTION_HANDLING\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: MAX OF THREE ===
30
7.2

=== PROBLEM 2: ARRAY SUM ===
Integer sum = 100
Double sum = 7

=== PROBLEM 3: GENERIC PAIR ===
Asha -> 95

=== PROBLEM 4: TEMPLATE STACK ===
Push 10: true
Push 20: true
Push 30: true
Push 40: false
Top = 30
After pop = 20
Size = 2

=== PROBLEM 5: LINEAR SEARCH ===
Index of 16 = 3
Index of graph = 2
Index of heap = -1

Next: 26_EXCEPTION_HANDLING
*/
