/*
TOPIC: Pass by Value, Reference, and Pointer
FILE: 03_variation.cpp

Purpose:
Explore const references, pointer constness, aliasing,
pointer-copy behavior, and multiple output parameters.

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


void quotientAndRemainder(
    int dividend,
    int divisor,
    int& quotient,
    int& remainder
) {
    quotient = dividend / divisor;
    remainder = dividend % divisor;
}


void inspect(const int& value) {

    cout << value << '\n';
}


void setNullLocally(int* ptr) {

    ptr = nullptr;

    (void)ptr;
}


void setNullForCaller(int*& ptr) {

    ptr = nullptr;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: const REFERENCE
    // ========================================================

    cout << "=== VARIATION 1: const Reference ===\n";

    int number = 42;

    inspect(number);

    // const reference can also bind to this temporary value.
    inspect(100);

    cout << '\n';


    // ========================================================
    // VARIATION 2: POINTER TO CONST
    // ========================================================

    cout << "=== VARIATION 2: Pointer to const ===\n";

    int first = 10;
    int second = 20;

    const int* ptrToConst = &first;

    cout << "*ptrToConst = "
         << *ptrToConst << '\n';

    // Pointer may be reseated.
    ptrToConst = &second;

    cout << "after reseat = "
         << *ptrToConst << "\n\n";

    // Not allowed:
    //
    // *ptrToConst = 99;


    // ========================================================
    // VARIATION 3: CONST POINTER
    // ========================================================

    cout << "=== VARIATION 3: const Pointer ===\n";

    int mutableValue = 5;

    int* const constPointer =
        &mutableValue;

    *constPointer = 99;

    cout << "mutableValue = "
         << mutableValue << "\n\n";

    // Not allowed:
    //
    // constPointer = &second;


    // ========================================================
    // VARIATION 4: POINTER COPY
    // ========================================================

    cout << "=== VARIATION 4: Pointer Copy ===\n";

    int shared = 7;

    int* p1 = &shared;
    int* p2 = p1;

    *p2 = 50;

    cout << "shared = "
         << shared << '\n';

    cout << "*p1 = "
         << *p1 << '\n';

    cout << "*p2 = "
         << *p2 << "\n\n";


    // ========================================================
    // VARIATION 5: POINTER PARAMETER COPY
    // ========================================================

    cout << "=== VARIATION 5: Pointer Passed by Value ===\n";

    int value = 123;

    int* pointer = &value;

    setNullLocally(pointer);

    cout << "pointer still non-null = "
         << (pointer != nullptr)
         << "\n\n";


    // ========================================================
    // VARIATION 6: REFERENCE TO POINTER
    // ========================================================

    cout << "=== VARIATION 6: Reference to Pointer ===\n";

    setNullForCaller(pointer);

    cout << "pointer is null = "
         << (pointer == nullptr)
         << "\n\n";


    // ========================================================
    // VARIATION 7: MULTIPLE OUTPUTS
    // ========================================================

    cout << "=== VARIATION 7: Output Parameters ===\n";

    int quotient{};
    int remainder{};

    quotientAndRemainder(
        17,
        5,
        quotient,
        remainder
    );

    cout << "quotient = "
         << quotient << '\n';

    cout << "remainder = "
         << remainder << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: const Reference ===
42
100

=== VARIATION 2: Pointer to const ===
*ptrToConst = 10
after reseat = 20

=== VARIATION 3: const Pointer ===
mutableValue = 99

=== VARIATION 4: Pointer Copy ===
shared = 50
*p1 = 50
*p2 = 50

=== VARIATION 5: Pointer Passed by Value ===
pointer still non-null = true

=== VARIATION 6: Reference to Pointer ===
pointer is null = true

=== VARIATION 7: Output Parameters ===
quotient = 3
remainder = 2

WHAT'S NEXT:
01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/
*/
