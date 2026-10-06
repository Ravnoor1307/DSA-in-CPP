/*
TOPIC: Pass by Value, Reference, and Pointer

Covers:
- Pass by value
- References
- Pass by reference
- const references
- Addresses
- Pointer basics
- nullptr
- Dereferencing
- Pointer parameters
- Pointer-to-const
- const pointer
- Aliasing
- Swap
- Dangling pointer/reference awareness

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: PASS BY VALUE ==========
//
//     void change(int x)
//
// x is a separate parameter object.
//
// Changing x does not change the caller's int.


// ========== SECTION 2: REFERENCE ==========
//
//     int value = 10;
//     int& ref = value;
//
// ref acts as an alias for value.
//
// Assignment through ref modifies value.


// ========== SECTION 3: PASS BY REFERENCE ==========
//
//     void change(int& x)
//
// x refers to the caller's object.
//
// Changing x changes that object.


// ========== SECTION 4: CONST REFERENCE ==========
//
//     void inspect(const int& x)
//
// x refers to an existing object but cannot be used to modify
// that object through this reference.
//
// For tiny ints, passing by value is usually simpler.
// const references become important for large objects later.


// ========== SECTION 5: ADDRESS-OF ==========
//
//     &value
//
// obtains the address of value.
//
// Exact addresses are runtime/implementation dependent.


// ========== SECTION 6: POINTER ==========
//
//     int* ptr = &value;
//
// ptr is a separate object containing value's address.


// ========== SECTION 7: DEREFERENCE ==========
//
//     *ptr
//
// accesses the pointed-to object.
//
//     *ptr = 50;
//
// modifies that object if ptr points to a valid mutable int.


// ========== SECTION 8: NULL POINTER ==========
//
//     int* ptr = nullptr;
//
// nullptr means the pointer currently designates no object.
//
// Never dereference nullptr.


// ========== SECTION 9: POINTER PARAMETER ==========
//
//     void change(int* ptr)
//
// The pointer itself is passed by value.
//
// But:
//
//     *ptr
//
// accesses the caller's pointed-to object.


// ========== SECTION 10: CONST POINTER FORMS ==========
//
// Pointer to const:
//
//     const int* ptr
//
// Cannot modify pointed int through ptr.
// ptr can be reseated.
//
// Const pointer:
//
//     int* const ptr
//
// ptr cannot be reseated.
// pointed int can be modified.


// ========== SECTION 11: ALIASING ==========
//
//     int x = 10;
//     int& ref = x;
//     int* ptr = &x;
//
// x, ref and *ptr can all access the same underlying int.


// ========== SECTION 12: LIFETIME ==========
//
// Never return pointers/references to automatic locals.
//
// The local object's lifetime ends when its function/block ends.
//
// An address remaining in a pointer does not keep an object alive.


void changeByValue(int x);
void changeByReference(int& x);
void changeByPointer(int* ptr);
void safeIncrement(int* ptr);
void swapByValue(int a, int b);
void swapByReference(int& a, int& b);
void inspect(const int& value);
void resetPointerCopy(int* ptr);


int main() {

    cout << "=== DEMO 1: Pass by Value ===\n";

    int value = 10;

    cout << "before = "
         << value << '\n';

    changeByValue(value);

    cout << "after = "
         << value << "\n\n";


    cout << "=== DEMO 2: Reference Alias ===\n";

    int original = 20;
    int& alias = original;

    cout << "original = "
         << original << '\n';

    alias = 99;

    cout << "after alias = 99, original = "
         << original << "\n\n";


    cout << "=== DEMO 3: Pass by Reference ===\n";

    int referenceValue = 10;

    changeByReference(referenceValue);

    cout << "after function = "
         << referenceValue << "\n\n";


    cout << "=== DEMO 4: Pointer Basics ===\n";

    int pointerValue = 25;
    int* ptr = &pointerValue;

    cout << "pointerValue = "
         << pointerValue << '\n';

    cout << "*ptr = "
         << *ptr << '\n';

    *ptr = 50;

    cout << "after *ptr = 50, pointerValue = "
         << pointerValue << "\n\n";


    cout << "=== DEMO 5: Pointer Parameter ===\n";

    int pointerArgument = 5;

    changeByPointer(&pointerArgument);

    cout << "after function = "
         << pointerArgument << "\n\n";


    cout << "=== DEMO 6: nullptr ===\n";

    int* nullPointer = nullptr;

    cout << boolalpha;

    cout << "nullPointer == nullptr: "
         << (nullPointer == nullptr)
         << "\n\n";


    cout << "=== DEMO 7: Safe Pointer Function ===\n";

    safeIncrement(nullptr);

    int safeValue = 7;
    safeIncrement(&safeValue);

    cout << "safeValue = "
         << safeValue << "\n\n";


    cout << "=== DEMO 8: Swap by Value Fails to Affect Caller ===\n";

    int a = 10;
    int b = 20;

    swapByValue(a, b);

    cout << "a = "
         << a
         << ", b = "
         << b
         << "\n\n";


    cout << "=== DEMO 9: Swap by Reference ===\n";

    swapByReference(a, b);

    cout << "a = "
         << a
         << ", b = "
         << b
         << "\n\n";


    cout << "=== DEMO 10: const Reference ===\n";

    inspect(a);

    cout << '\n';


    cout << "=== DEMO 11: Aliasing ===\n";

    int shared = 1;
    int& sharedRef = shared;
    int* sharedPtr = &shared;

    sharedRef = 2;

    cout << "after reference: "
         << shared << '\n';

    *sharedPtr = 3;

    cout << "after pointer: "
         << shared << "\n\n";


    cout << "=== DEMO 12: Pointer Parameter Is Passed by Value ===\n";

    int number = 123;
    int* numberPtr = &number;

    resetPointerCopy(numberPtr);

    cout << "caller pointer is still non-null: "
         << (numberPtr != nullptr)
         << '\n';

    cout << "*numberPtr = "
         << *numberPtr
         << '\n';

    return 0;
}


void changeByValue(int x) {

    x = 100;

    cout << "inside function = "
         << x << '\n';
}


void changeByReference(int& x) {

    x = 100;
}


void changeByPointer(int* ptr) {

    if (ptr == nullptr) {
        return;
    }

    *ptr = 100;
}


void safeIncrement(int* ptr) {

    if (ptr == nullptr) {
        return;
    }

    ++(*ptr);
}


void swapByValue(int a, int b) {

    int temp = a;
    a = b;
    b = temp;
}


void swapByReference(int& a, int& b) {

    int temp = a;
    a = b;
    b = temp;
}


void inspect(const int& value) {

    cout << "read-only view = "
         << value << '\n';

    // value = 500;
    // ERROR: cannot modify through const reference.
}


void resetPointerCopy(int* ptr) {

    // This changes only the local pointer parameter.
    ptr = nullptr;

    // Avoid an unused-but-set warning under strict diagnostics.
    (void)ptr;
}


/*
EXPECTED OUTPUT

=== DEMO 1: Pass by Value ===
before = 10
inside function = 100
after = 10

=== DEMO 2: Reference Alias ===
original = 20
after alias = 99, original = 99

=== DEMO 3: Pass by Reference ===
after function = 100

=== DEMO 4: Pointer Basics ===
pointerValue = 25
*ptr = 25
after *ptr = 50, pointerValue = 50

=== DEMO 5: Pointer Parameter ===
after function = 100

=== DEMO 6: nullptr ===
nullPointer == nullptr: true

=== DEMO 7: Safe Pointer Function ===
safeValue = 8

=== DEMO 8: Swap by Value Fails to Affect Caller ===
a = 10, b = 20

=== DEMO 9: Swap by Reference ===
a = 20, b = 10

=== DEMO 10: const Reference ===
read-only view = 20

=== DEMO 11: Aliasing ===
after reference: 2
after pointer: 3

=== DEMO 12: Pointer Parameter Is Passed by Value ===
caller pointer is still non-null: true
*numberPtr = 123

WHAT'S NEXT:
01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/
*/
