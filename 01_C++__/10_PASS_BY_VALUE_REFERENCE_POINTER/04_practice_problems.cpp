/*
TOPIC: Pass by Value, Reference, and Pointer
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;


// ============================================================
// PROBLEM 1: TRY TO MODIFY BY VALUE
// ============================================================

void addTenByValue(int value) {

    value += 10;
}


// ============================================================
// PROBLEM 2: MODIFY BY REFERENCE
// ============================================================

void addTenByReference(int& value) {

    value += 10;
}


// ============================================================
// PROBLEM 3: MODIFY THROUGH POINTER
// ============================================================

bool addTenByPointer(int* value) {

    if (value == nullptr) {
        return false;
    }

    *value += 10;

    return true;
}


// ============================================================
// PROBLEM 4: SWAP
// ============================================================

void swapValues(int& a, int& b) {

    int temp = a;
    a = b;
    b = temp;
}


// ============================================================
// PROBLEM 5: MIN/MAX OUTPUT PARAMETERS
// ============================================================

void findMinMax(
    int a,
    int b,
    int& minimum,
    int& maximum
) {
    if (a < b) {
        minimum = a;
        maximum = b;
    } else {
        minimum = b;
        maximum = a;
    }
}


// ============================================================
// BONUS: SAFE POINTER READ
// ============================================================

bool readPointedValue(
    const int* ptr,
    int& output
) {
    if (ptr == nullptr) {
        return false;
    }

    output = *ptr;

    return true;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Pass by Value ===\n";

    int first = 5;

    addTenByValue(first);

    cout << "first = "
         << first << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Pass by Reference ===\n";

    int second = 5;

    addTenByReference(second);

    cout << "second = "
         << second << "\n\n";


    // ========================================================
    // TEST 3
    // ========================================================

    cout << "=== PROBLEM 3: Pointer Parameter ===\n";

    int third = 5;

    bool success =
        addTenByPointer(&third);

    cout << "success = "
         << success << '\n';

    cout << "third = "
         << third << '\n';

    cout << "nullptr success = "
         << addTenByPointer(nullptr)
         << "\n\n";


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Swap ===\n";

    int a = 10;
    int b = 20;

    cout << "before: "
         << a << ' '
         << b << '\n';

    swapValues(a, b);

    cout << "after: "
         << a << ' '
         << b << "\n\n";


    // ========================================================
    // TEST 5
    // ========================================================

    cout << "=== PROBLEM 5: Min/Max ===\n";

    int minimum{};
    int maximum{};

    findMinMax(
        40,
        15,
        minimum,
        maximum
    );

    cout << "minimum = "
         << minimum << '\n';

    cout << "maximum = "
         << maximum << "\n\n";


    // ========================================================
    // BONUS
    // ========================================================

    cout << "=== BONUS: Safe Read ===\n";

    int source = 77;
    int output{};

    bool readSuccess =
        readPointedValue(
            &source,
            output
        );

    cout << "success = "
         << readSuccess << '\n';

    cout << "output = "
         << output << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Pass by Value ===
first = 5

=== PROBLEM 2: Pass by Reference ===
second = 15

=== PROBLEM 3: Pointer Parameter ===
success = true
third = 15
nullptr success = false

=== PROBLEM 4: Swap ===
before: 10 20
after: 20 10

=== PROBLEM 5: Min/Max ===
minimum = 15
maximum = 40

=== BONUS: Safe Read ===
success = true
output = 77


PRACTICE LINKS

1. HackerRank - Pointer
https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

2. GFG - References in C++
https://www.geeksforgeeks.org/references-in-cpp/

3. GFG - Pointers in C++
https://www.geeksforgeeks.org/cpp-pointers/

4. LeetCode 2235
https://leetcode.com/problems/add-two-integers/

5. LeetCode 1929
https://leetcode.com/problems/concatenation-of-array/


WHAT'S NEXT:
01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/
*/
