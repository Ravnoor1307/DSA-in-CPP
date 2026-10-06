/*
TOPIC: Pointers
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;


void setValue(
    int* ptr,
    int value
) {
    if (ptr == nullptr) {
        return;
    }

    *ptr = value;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // BASIC 1: ADDRESS AND DEREFERENCE
    // ========================================================

    int number = 10;

    int* ptr = &number;

    cout << "=== BASIC 1: Pointer ===\n";

    cout << "number = "
         << number << '\n';

    cout << "*ptr = "
         << *ptr << "\n\n";


    // ========================================================
    // BASIC 2: MODIFY
    // ========================================================

    *ptr = 20;

    cout << "=== BASIC 2: Modification ===\n";

    cout << "number = "
         << number << "\n\n";


    // ========================================================
    // BASIC 3: RESEAT
    // ========================================================

    int other = 50;

    ptr = &other;

    cout << "=== BASIC 3: Reseat ===\n";

    cout << "*ptr = "
         << *ptr << "\n\n";


    // ========================================================
    // BASIC 4: NULL
    // ========================================================

    ptr = nullptr;

    cout << "=== BASIC 4: nullptr ===\n";

    cout << "is null = "
         << (ptr == nullptr)
         << "\n\n";


    // ========================================================
    // BASIC 5: SAFE FUNCTION
    // ========================================================

    cout << "=== BASIC 5: Pointer Function ===\n";

    int value = 5;

    setValue(&value, 99);

    cout << "value = "
         << value << '\n';

    setValue(nullptr, 50);

    cout << "null call completed safely\n\n";


    // ========================================================
    // BASIC 6: TWO POINTERS SAME OBJECT
    // ========================================================

    cout << "=== BASIC 6: Aliasing ===\n";

    int shared = 7;

    int* p1 = &shared;
    int* p2 = &shared;

    *p1 = 8;
    *p2 = 9;

    cout << "shared = "
         << shared << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Pointer ===
number = 10
*ptr = 10

=== BASIC 2: Modification ===
number = 20

=== BASIC 3: Reseat ===
*ptr = 50

=== BASIC 4: nullptr ===
is null = true

=== BASIC 5: Pointer Function ===
value = 99
null call completed safely

=== BASIC 6: Aliasing ===
shared = 9

WHAT'S NEXT:
01_C++__/15_POINTER_ARITHMETIC/
*/
