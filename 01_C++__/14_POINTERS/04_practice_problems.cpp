/*
TOPIC: Pointers
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;


// ============================================================
// PROBLEM 1: MODIFY THROUGH POINTER
// ============================================================

bool addTen(
    int* ptr
) {
    if (ptr == nullptr) {
        return false;
    }

    *ptr += 10;

    return true;
}


// ============================================================
// PROBLEM 2: SWAP THROUGH POINTERS
// ============================================================

bool swapValues(
    int* first,
    int* second
) {
    if (first == nullptr ||
        second == nullptr) {

        return false;
    }

    int temp = *first;

    *first = *second;
    *second = temp;

    return true;
}


// ============================================================
// PROBLEM 3: SAFE READ
// ============================================================

bool readValue(
    const int* ptr,
    int& output
) {
    if (ptr == nullptr) {
        return false;
    }

    output = *ptr;

    return true;
}


// ============================================================
// PROBLEM 4: RESET CALLER POINTER
// ============================================================

void resetPointer(
    int*& ptr
) {
    ptr = nullptr;
}


// ============================================================
// PROBLEM 5: DOUBLE POINTER MODIFICATION
// ============================================================

bool setThroughDoublePointer(
    int** pp,
    int value
) {
    if (pp == nullptr ||
        *pp == nullptr) {

        return false;
    }

    **pp = value;

    return true;
}


// ============================================================
// BONUS: FUNCTION POINTER
// ============================================================

int add(int a, int b) {

    return a + b;
}


int multiply(int a, int b) {

    return a * b;
}


int calculate(
    int a,
    int b,
    int (*operation)(int, int)
) {
    if (operation == nullptr) {
        return 0;
    }

    return operation(a, b);
}


int main() {

    cout << boolalpha;


    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Add Ten ===\n";

    int value = 5;

    cout << "success = "
         << addTen(&value)
         << '\n';

    cout << "value = "
         << value << '\n';

    cout << "null success = "
         << addTen(nullptr)
         << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Swap ===\n";

    int a = 10;
    int b = 20;

    cout << "success = "
         << swapValues(&a, &b)
         << '\n';

    cout << "a = "
         << a
         << ", b = "
         << b
         << "\n\n";


    // ========================================================
    // TEST 3
    // ========================================================

    cout << "=== PROBLEM 3: Safe Read ===\n";

    int output{};

    cout << "success = "
         << readValue(&a, output)
         << '\n';

    cout << "output = "
         << output
         << "\n\n";


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Reset Pointer ===\n";

    int* ptr = &a;

    resetPointer(ptr);

    cout << "is null = "
         << (ptr == nullptr)
         << "\n\n";


    // ========================================================
    // TEST 5
    // ========================================================

    cout << "=== PROBLEM 5: Double Pointer ===\n";

    int target = 7;

    int* targetPtr =
        &target;

    int** pp =
        &targetPtr;

    cout << "success = "
         << setThroughDoublePointer(
                pp,
                99
            )
         << '\n';

    cout << "target = "
         << target
         << "\n\n";


    // ========================================================
    // BONUS
    // ========================================================

    cout << "=== BONUS: Function Pointer ===\n";

    cout << "add = "
         << calculate(
                4,
                5,
                add
            )
         << '\n';

    cout << "multiply = "
         << calculate(
                4,
                5,
                multiply
            )
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Add Ten ===
success = true
value = 15
null success = false

=== PROBLEM 2: Swap ===
success = true
a = 20, b = 10

=== PROBLEM 3: Safe Read ===
success = true
output = 20

=== PROBLEM 4: Reset Pointer ===
is null = true

=== PROBLEM 5: Double Pointer ===
success = true
target = 99

=== BONUS: Function Pointer ===
add = 9
multiply = 20


PRACTICE LINKS

1. HackerRank Pointer
https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

2. GFG Pointers in C++
https://www.geeksforgeeks.org/cpp-pointers/

3. GFG Double Pointer
https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/

4. GFG Function Pointer
https://www.geeksforgeeks.org/function-pointer-in-c/

5. LeetCode 876
https://leetcode.com/problems/middle-of-the-linked-list/


WHAT'S NEXT:
01_C++__/15_POINTER_ARITHMETIC/
*/
