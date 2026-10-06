/*
TOPIC: Pass by Value, Reference, and Pointer
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;


void valueChange(int value) {

    value = 50;

    cout << "inside valueChange = "
         << value << '\n';
}


void referenceChange(int& value) {

    value = 50;
}


void pointerChange(int* value) {

    if (value == nullptr) {
        return;
    }

    *value = 50;
}


void increment(int& value) {

    ++value;
}


bool tryIncrement(int* value) {

    if (value == nullptr) {
        return false;
    }

    ++(*value);

    return true;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // BASIC 1: PASS BY VALUE
    // ========================================================

    cout << "=== BASIC 1: Value ===\n";

    int a = 10;

    valueChange(a);

    cout << "caller a = "
         << a << "\n\n";


    // ========================================================
    // BASIC 2: REFERENCE
    // ========================================================

    cout << "=== BASIC 2: Reference ===\n";

    int b = 10;

    referenceChange(b);

    cout << "caller b = "
         << b << "\n\n";


    // ========================================================
    // BASIC 3: POINTER
    // ========================================================

    cout << "=== BASIC 3: Pointer ===\n";

    int c = 10;

    pointerChange(&c);

    cout << "caller c = "
         << c << "\n\n";


    // ========================================================
    // BASIC 4: REFERENCE ALIAS
    // ========================================================

    cout << "=== BASIC 4: Alias ===\n";

    int original = 5;
    int& alias = original;

    alias += 10;

    cout << "original = "
         << original << '\n';

    cout << "alias = "
         << alias << "\n\n";


    // ========================================================
    // BASIC 5: POINTER CAN CHANGE TARGET
    // ========================================================

    cout << "=== BASIC 5: Pointer Reseating ===\n";

    int first = 1;
    int second = 2;

    int* ptr = &first;

    cout << "*ptr = "
         << *ptr << '\n';

    ptr = &second;

    cout << "*ptr after reseating = "
         << *ptr << "\n\n";


    // ========================================================
    // BASIC 6: NULL CHECK
    // ========================================================

    cout << "=== BASIC 6: nullptr ===\n";

    int* empty = nullptr;

    cout << "increment nullptr succeeded: "
         << tryIncrement(empty)
         << '\n';

    int number = 7;

    cout << "increment number succeeded: "
         << tryIncrement(&number)
         << '\n';

    cout << "number = "
         << number << "\n\n";


    // ========================================================
    // BASIC 7: REFERENCE MUTATION
    // ========================================================

    cout << "=== BASIC 7: Repeated Reference Calls ===\n";

    int counter = 0;

    increment(counter);
    increment(counter);
    increment(counter);

    cout << "counter = "
         << counter << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Value ===
inside valueChange = 50
caller a = 10

=== BASIC 2: Reference ===
caller b = 50

=== BASIC 3: Pointer ===
caller c = 50

=== BASIC 4: Alias ===
original = 15
alias = 15

=== BASIC 5: Pointer Reseating ===
*ptr = 1
*ptr after reseating = 2

=== BASIC 6: nullptr ===
increment nullptr succeeded: false
increment number succeeded: true
number = 8

=== BASIC 7: Repeated Reference Calls ===
counter = 3

WHAT'S NEXT:
01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/
*/
