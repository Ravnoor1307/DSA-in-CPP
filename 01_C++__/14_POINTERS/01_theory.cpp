/*
TOPIC: Pointers

Covers:
- Pointer objects
- Address-of
- Dereferencing
- nullptr
- Pointer copying/reassignment
- Pointer parameters
- Reference to pointer
- Pointer to pointer
- const pointer combinations
- Dangling pointers
- Arrays vs pointers
- Pointer to arrays
- void*
- Function pointers

Detailed pointer arithmetic is intentionally left for the next folder.

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: POINTER OBJECT ==========
//
// A pointer is an object that can hold an address.
//
//     int value = 10;
//     int* ptr = &value;


// ========== SECTION 2: ADDRESS-OF ==========
//
//     &value
//
// obtains value's address.
//
// Exact numeric addresses vary between executions/environments.


// ========== SECTION 3: DEREFERENCE ==========
//
//     *ptr
//
// accesses the pointed-to object.
//
//     *ptr = 50;
//
// modifies that object when ptr validly points to a mutable int.


// ========== SECTION 4: NULL POINTER ==========
//
//     int* ptr = nullptr;
//
// ptr intentionally designates no int object.
//
// Never dereference nullptr.


// ========== SECTION 5: POINTER COPY ==========
//
//     int* p1 = &value;
//     int* p2 = p1;
//
// p1 and p2 are separate pointer objects.
//
// Both can point to the same int.


// ========== SECTION 6: POINTER PARAMETER ==========
//
//     void change(int* ptr)
//
// ptr itself is passed by value.
//
//     *ptr
//
// can still modify the shared pointed-to object.


// ========== SECTION 7: REFERENCE TO POINTER ==========
//
//     void reset(int*& ptr)
//
// ptr aliases the caller's pointer object.
//
// Assigning ptr changes the caller's pointer.


// ========== SECTION 8: POINTER TO POINTER ==========
//
//     int value = 10;
//     int* ptr = &value;
//     int** pp = &ptr;
//
// *pp  -> ptr
// **pp -> value


// ========== SECTION 9: CONST COMBINATIONS ==========
//
//     const int* p
//
// pointer to const int.
//
//     int* const p
//
// const pointer to int.
//
//     const int* const p
//
// const pointer to const int.


// ========== SECTION 10: DANGLING POINTER ==========
//
// A pointer becomes dangling when the object it designated
// no longer exists.
//
// A remaining address value does not keep an object alive.


// ========== SECTION 11: ARRAY RELATIONSHIP ==========
//
//     int values[3];
//
// values is an array object.
//
// In many expressions it converts to:
//
//     &values[0]
//
// It is NOT literally a pointer object.


// ========== SECTION 12: POINTER TO ARRAY ==========
//
//     int (*p)[3];
//
// pointer to array of 3 int.
//
// Different from:
//
//     int* p[3];
//
// array of 3 pointers.


// ========== SECTION 13: VOID POINTER ==========
//
//     void* generic;
//
// can hold an object address in low-level generic code.
//
// It cannot be directly dereferenced because void does not
// identify a concrete object type.


// ========== SECTION 14: FUNCTION POINTER ==========
//
//     int (*operation)(int, int);
//
// means:
//
// operation is a pointer to a function taking two ints
// and returning int.


void modifyThroughPointer(int* ptr);
void resetCopy(int* ptr);
void resetCallerPointer(int*& ptr);

int add(int a, int b);
int multiply(int a, int b);


int main() {

    cout << boolalpha;


    cout << "=== DEMO 1: Basic Pointer ===\n";

    int value = 10;
    int* ptr = &value;

    cout << "value = "
         << value << '\n';

    cout << "*ptr = "
         << *ptr << "\n\n";


    cout << "=== DEMO 2: Modify Through Pointer ===\n";

    *ptr = 50;

    cout << "value = "
         << value << "\n\n";


    cout << "=== DEMO 3: Pointer Reassignment ===\n";

    int first = 1;
    int second = 2;

    ptr = &first;

    cout << "*ptr = "
         << *ptr << '\n';

    ptr = &second;

    cout << "*ptr = "
         << *ptr << "\n\n";


    cout << "=== DEMO 4: Pointer Copy ===\n";

    int shared = 10;

    int* p1 = &shared;
    int* p2 = p1;

    *p2 = 99;

    cout << "shared = "
         << shared << '\n';

    cout << "*p1 = "
         << *p1 << '\n';

    cout << "*p2 = "
         << *p2 << "\n\n";


    cout << "=== DEMO 5: nullptr ===\n";

    int* empty = nullptr;

    cout << "empty == nullptr: "
         << (empty == nullptr)
         << "\n\n";


    cout << "=== DEMO 6: Pointer Parameter ===\n";

    int parameterValue = 5;

    modifyThroughPointer(
        &parameterValue
    );

    cout << "value = "
         << parameterValue << "\n\n";


    cout << "=== DEMO 7: Pointer Parameter Copy ===\n";

    int original = 7;
    int* originalPtr = &original;

    resetCopy(originalPtr);

    cout << "caller pointer non-null: "
         << (originalPtr != nullptr)
         << "\n\n";


    cout << "=== DEMO 8: Reference to Pointer ===\n";

    resetCallerPointer(
        originalPtr
    );

    cout << "caller pointer is null: "
         << (originalPtr == nullptr)
         << "\n\n";


    cout << "=== DEMO 9: Double Pointer ===\n";

    int number = 25;
    int* numberPtr = &number;
    int** pp = &numberPtr;

    cout << "**pp = "
         << **pp << '\n';

    **pp = 75;

    cout << "number = "
         << number << "\n\n";


    cout << "=== DEMO 10: Pointer to const ===\n";

    int a = 10;
    int b = 20;

    const int* readOnly = &a;

    cout << "*readOnly = "
         << *readOnly << '\n';

    readOnly = &b;

    cout << "after reseat = "
         << *readOnly << "\n\n";


    cout << "=== DEMO 11: const Pointer ===\n";

    int mutableValue = 3;

    int* const fixedPointer =
        &mutableValue;

    *fixedPointer = 30;

    cout << "mutableValue = "
         << mutableValue << "\n\n";


    cout << "=== DEMO 12: Array Conversion ===\n";

    int values[3] = {
        10, 20, 30
    };

    int* firstElement =
        values;

    cout << "pointer == &values[0]: "
         << (firstElement == &values[0])
         << '\n';

    cout << "*firstElement = "
         << *firstElement
         << "\n\n";


    cout << "=== DEMO 13: void* ===\n";

    int genericValue = 123;

    void* generic =
        &genericValue;

    int* recovered =
        static_cast<int*>(generic);

    cout << "*recovered = "
         << *recovered
         << "\n\n";


    cout << "=== DEMO 14: Function Pointer ===\n";

    int (*operation)(int, int) =
        add;

    cout << "add: "
         << operation(4, 5)
         << '\n';

    operation = multiply;

    cout << "multiply: "
         << operation(4, 5)
         << '\n';

    return 0;
}


void modifyThroughPointer(
    int* ptr
) {
    if (ptr == nullptr) {
        return;
    }

    *ptr = 100;
}


void resetCopy(
    int* ptr
) {
    ptr = nullptr;

    // Silence set-but-unused warnings.
    (void)ptr;
}


void resetCallerPointer(
    int*& ptr
) {
    ptr = nullptr;
}


int add(int a, int b) {

    return a + b;
}


int multiply(int a, int b) {

    return a * b;
}


/*
EXPECTED OUTPUT

=== DEMO 1: Basic Pointer ===
value = 10
*ptr = 10

=== DEMO 2: Modify Through Pointer ===
value = 50

=== DEMO 3: Pointer Reassignment ===
*ptr = 1
*ptr = 2

=== DEMO 4: Pointer Copy ===
shared = 99
*p1 = 99
*p2 = 99

=== DEMO 5: nullptr ===
empty == nullptr: true

=== DEMO 6: Pointer Parameter ===
value = 100

=== DEMO 7: Pointer Parameter Copy ===
caller pointer non-null: true

=== DEMO 8: Reference to Pointer ===
caller pointer is null: true

=== DEMO 9: Double Pointer ===
**pp = 25
number = 75

=== DEMO 10: Pointer to const ===
*readOnly = 10
after reseat = 20

=== DEMO 11: const Pointer ===
mutableValue = 30

=== DEMO 12: Array Conversion ===
pointer == &values[0]: true
*firstElement = 10

=== DEMO 13: void* ===
*recovered = 123

=== DEMO 14: Function Pointer ===
add: 9
multiply: 20

WHAT'S NEXT:
01_C++__/15_POINTER_ARITHMETIC/
*/
