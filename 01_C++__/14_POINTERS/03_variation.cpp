/*
TOPIC: Pointers
FILE: 03_variation.cpp

Purpose:
Explore:
- multiple pointer levels
- pointer constness
- array vs pointer distinction
- pointer-to-array syntax
- function pointers

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


int subtract(int a, int b) {

    return a - b;
}


int add(int a, int b) {

    return a + b;
}


void makeNull(
    int*& ptr
) {
    ptr = nullptr;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: POINTER TO POINTER
    // ========================================================

    int value = 10;
    int* ptr = &value;
    int** pp = &ptr;

    cout << "=== VARIATION 1: Double Pointer ===\n";

    cout << "value = "
         << value << '\n';

    cout << "*ptr = "
         << *ptr << '\n';

    cout << "**pp = "
         << **pp << '\n';

    **pp = 50;

    cout << "after **pp = 50: "
         << value << "\n\n";


    // ========================================================
    // VARIATION 2: REFERENCE TO POINTER
    // ========================================================

    cout << "=== VARIATION 2: Reference to Pointer ===\n";

    makeNull(ptr);

    cout << "ptr == nullptr: "
         << (ptr == nullptr)
         << "\n\n";


    // ========================================================
    // VARIATION 3: POINTER TO CONST
    // ========================================================

    int a = 1;
    int b = 2;

    const int* readOnly =
        &a;

    cout << "=== VARIATION 3: Pointer to const ===\n";

    cout << *readOnly << ' ';

    readOnly = &b;

    cout << *readOnly
         << "\n\n";


    // ========================================================
    // VARIATION 4: CONST POINTER
    // ========================================================

    int mutableValue = 10;

    int* const fixed =
        &mutableValue;

    *fixed = 25;

    cout << "=== VARIATION 4: const Pointer ===\n";

    cout << mutableValue
         << "\n\n";


    // ========================================================
    // VARIATION 5: ARRAY VS POINTER SIZE
    // ========================================================

    int values[4] = {
        10, 20, 30, 40
    };

    int* firstElement =
        values;

    cout << "=== VARIATION 5: Array vs Pointer ===\n";

    cout << "sizeof(array) = "
         << sizeof(values)
         << '\n';

    cout << "sizeof(pointer) = "
         << sizeof(firstElement)
         << '\n';

    cout << "same first address = "
         << (firstElement == &values[0])
         << "\n\n";


    // ========================================================
    // VARIATION 6: POINTER TO WHOLE ARRAY
    // ========================================================

    int (*arrayPointer)[4] =
        &values;

    cout << "=== VARIATION 6: Pointer to Array ===\n";

    // Dereferencing arrayPointer gives the whole array.
    // Indexing [0] on that array accesses its first int.
    cout << "first = "
         << (*arrayPointer)[0]
         << '\n';

    cout << "last = "
         << (*arrayPointer)[3]
         << "\n\n";


    // ========================================================
    // VARIATION 7: FUNCTION POINTER
    // ========================================================

    int (*operation)(int, int) =
        add;

    cout << "=== VARIATION 7: Function Pointer ===\n";

    cout << operation(8, 3)
         << '\n';

    operation = subtract;

    cout << operation(8, 3)
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT ON A COMMON 64-BIT SYSTEM

=== VARIATION 1: Double Pointer ===
value = 10
*ptr = 10
**pp = 10
after **pp = 50: 50

=== VARIATION 2: Reference to Pointer ===
ptr == nullptr: true

=== VARIATION 3: Pointer to const ===
1 2

=== VARIATION 4: const Pointer ===
25

=== VARIATION 5: Array vs Pointer ===
sizeof(array) = 16
sizeof(pointer) = 8
same first address = true

=== VARIATION 6: Pointer to Array ===
first = 10
last = 40

=== VARIATION 7: Function Pointer ===
11
5

sizeof(int), array storage, and pointer size are implementation-dependent.

WHAT'S NEXT:
01_C++__/15_POINTER_ARITHMETIC/
*/
