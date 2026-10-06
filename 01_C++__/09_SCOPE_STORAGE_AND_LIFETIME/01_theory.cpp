/*
TOPIC: Scope, Storage Duration, and Lifetime

Covers:
- Block scope
- Function-local scope
- Parameters
- Nested scope
- Shadowing
- Namespace/global variables
- Automatic storage duration
- Static storage duration
- Static local variables
- Object lifetime
- Zero initialization of static-storage objects
- Scope vs lifetime
- DSA implications

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: THREE DIFFERENT QUESTIONS ==========
//
// SCOPE:
//
//     Where can a NAME be used?
//
// STORAGE DURATION:
//
//     How long is storage for the OBJECT maintained?
//
// LIFETIME:
//
//     During what part of execution does the OBJECT exist?
//
// These concepts are related, but they are not identical.


// ========== SECTION 2: BLOCK SCOPE ==========
//
// Example:
//
//     {
//         int x = 10;
//     }
//
// The local name x belongs to the block.
//
// Outside that block, x cannot be referred to by that local name.


// ========== SECTION 3: ENCLOSING SCOPES ==========
//
// An inner scope can commonly use a name from an enclosing scope.
//
//     int x = 10;
//
//     {
//         cout << x;
//     }


// ========== SECTION 4: SHADOWING ==========
//
// An inner declaration can hide an outer declaration.
//
//     int x = 10;
//
//     {
//         int x = 20;
//         cout << x; // inner x
//     }
//
// Avoid unnecessary shadowing because it makes state harder to track.


// ========== SECTION 5: AUTOMATIC STORAGE DURATION ==========
//
// Typical local variables have automatic storage duration.
//
//     void demo() {
//         int x = 10;
//     }
//
// x's lifetime begins when its initialization occurs.
//
// Its lifetime ends when execution leaves the block.


// ========== SECTION 6: STATIC LOCAL VARIABLE ==========
//
//     void visit() {
//         static int count = 0;
//         ++count;
//     }
//
// The NAME count remains locally scoped.
//
// The OBJECT persists between calls.
//
// This demonstrates:
//
//     scope != storage duration


// ========== SECTION 7: NAMESPACE-SCOPE VARIABLES ==========
//
// A variable declared outside functions:
//
//     int globalValue = 10;
//
// has namespace scope and static storage duration.
//
// In small programs it is commonly called a "global variable."
//
// Avoid unnecessary mutable global state.


// ========== SECTION 8: INITIALIZATION DIFFERENCE ==========
//
// Static-storage object:
//
//     int globalValue;
//
// receives zero initialization.
//
// Automatic local:
//
//     void f() {
//         int local;
//     }
//
// local is not automatically initialized to zero.
//
// Reading such an uninitialized local scalar can result in
// undefined behavior.


// ========== SECTION 9: FUNCTION CALLS ==========
//
// Each call gets its own automatic local objects.
//
//     demo();
//     demo();
//
// An ordinary local does not remember its previous call.
//
// A static local can.


// ========== SECTION 10: LIFETIME AND FUTURE POINTERS ==========
//
// Later, pointers/references can outlive the object they refer to.
//
// Example idea:
//
//     local object dies
//           |
//           v
//     pointer/reference remains
//           |
//           v
//     dangling access
//
// Understanding lifetime prevents these bugs.


// Global namespace-scope object.
int globalValue = 100;


// Uninitialized static-storage object.
// It receives zero initialization.
int zeroInitializedGlobal;


// Function declarations.
void automaticCounter();
void staticCounter();
void demonstrateParameterScope(int parameter);
void staticInsideLoopDemo();


int main() {

    cout << "=== DEMO 1: Block Scope ===\n";

    int outer = 10;

    cout << "outer before block = "
         << outer << '\n';

    {
        int inner = 20;

        cout << "outer inside block = "
             << outer << '\n';

        cout << "inner inside block = "
             << inner << '\n';
    }

    // inner no longer exists here and its name is out of scope.
    cout << "outer after block = "
         << outer << "\n\n";


    cout << "=== DEMO 2: Shadowing ===\n";

    int value = 10;

    cout << "outer value = "
         << value << '\n';

    {
        int value = 20;

        cout << "inner value = "
             << value << '\n';
    }

    cout << "outer value again = "
         << value << "\n\n";


    cout << "=== DEMO 3: Local vs Global ===\n";

    int globalValue = 200;

    cout << "local globalValue = "
         << globalValue << '\n';

    cout << "::globalValue = "
         << ::globalValue << "\n\n";


    cout << "=== DEMO 4: Static-Storage Zero Initialization ===\n";

    cout << "zeroInitializedGlobal = "
         << zeroInitializedGlobal
         << "\n\n";


    cout << "=== DEMO 5: Automatic Local Across Calls ===\n";

    automaticCounter();
    automaticCounter();
    automaticCounter();

    cout << '\n';


    cout << "=== DEMO 6: Static Local Across Calls ===\n";

    staticCounter();
    staticCounter();
    staticCounter();

    cout << '\n';


    cout << "=== DEMO 7: Function Parameter Scope ===\n";

    demonstrateParameterScope(42);

    cout << '\n';


    cout << "=== DEMO 8: Loop Block Locals ===\n";

    for (int i = 0; i < 3; ++i) {

        int local = i * 10;

        cout << "iteration "
             << i
             << ": local = "
             << local
             << '\n';
    }

    cout << '\n';


    cout << "=== DEMO 9: Static Local Inside Repeated Block ===\n";

    staticInsideLoopDemo();

    return 0;
}


void automaticCounter() {

    int count = 0;

    ++count;

    cout << count << ' ';
}


void staticCounter() {

    static int count = 0;

    ++count;

    cout << count << ' ';
}


void demonstrateParameterScope(int parameter) {

    cout << "parameter = "
         << parameter << '\n';

    int local = parameter + 1;

    cout << "local = "
         << local << '\n';
}


void staticInsideLoopDemo() {

    for (int i = 0; i < 3; ++i) {

        static int persistent = 0;

        ++persistent;

        cout << "iteration "
             << i
             << ": persistent = "
             << persistent
             << '\n';
    }
}


/*
EXPECTED OUTPUT

=== DEMO 1: Block Scope ===
outer before block = 10
outer inside block = 10
inner inside block = 20
outer after block = 10

=== DEMO 2: Shadowing ===
outer value = 10
inner value = 20
outer value again = 10

=== DEMO 3: Local vs Global ===
local globalValue = 200
::globalValue = 100

=== DEMO 4: Static-Storage Zero Initialization ===
zeroInitializedGlobal = 0

=== DEMO 5: Automatic Local Across Calls ===
1 1 1

=== DEMO 6: Static Local Across Calls ===
1 2 3

=== DEMO 7: Function Parameter Scope ===
parameter = 42
local = 43

=== DEMO 8: Loop Block Locals ===
iteration 0: local = 0
iteration 1: local = 10
iteration 2: local = 20

=== DEMO 9: Static Local Inside Repeated Block ===
iteration 0: persistent = 1
iteration 1: persistent = 2
iteration 2: persistent = 3

WHAT'S NEXT:
01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/
*/
