/*
TOPIC: Function Overloading and Default Arguments

Covers:
- Overload sets
- Overloading by type
- Overloading by parameter count
- Overload resolution
- Exact matches and conversions
- Ambiguity
- const/reference overloads
- Return-type limitation
- Default arguments
- Trailing defaults
- Defaults and overload ambiguity

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: FUNCTION OVERLOADING ==========
//
// Multiple functions can share a name when their parameter
// lists distinguish them.
//
// Example:
//
//     void show(int);
//     void show(double);


// ========== SECTION 2: RETURN TYPE IS NOT ENOUGH ==========
//
// INVALID:
//
//     int test(int);
//     double test(int);
//
// Return type alone cannot distinguish overloads.


// ========== SECTION 3: OVERLOAD RESOLUTION ==========
//
// Simplified mental model:
//
//     candidates
//         |
//     viable functions
//         |
//     conversion ranking
//         |
//     unique best function
//
// No unique best candidate means an ambiguous call.


// ========== SECTION 4: TYPE MATTERS ==========
//
//     10    -> int
//     10LL  -> long long
//     3.5   -> double
//     3.5f  -> float
//
// These types influence overload selection.


// ========== SECTION 5: OVERLOAD BY PARAMETER COUNT ==========
//
// Valid:
//
//     sum(int, int)
//     sum(int, int, int)


// ========== SECTION 6: CONST REFERENCE OVERLOADS ==========
//
//     inspect(int&)
//     inspect(const int&)
//
// A mutable int lvalue prefers int& in this overload set.
//
// const values and temporaries can use const int&.


// ========== SECTION 7: TOP-LEVEL CONST VALUE PARAMETER ==========
//
// These are NOT distinct overloads:
//
//     process(int)
//     process(const int)
//
// Top-level const on a by-value parameter does not distinguish
// the function type for overloading.


// ========== SECTION 8: DEFAULT ARGUMENTS ==========
//
// Declaration:
//
//     int multiply(int value, int factor = 2);
//
// Calls:
//
//     multiply(5)    -> factor defaults to 2
//     multiply(5, 3) -> explicit factor 3


// ========== SECTION 9: TRAILING DEFAULTS ==========
//
// Common valid form:
//
//     f(int a, int b = 10, int c = 20)
//
// Calls:
//
//     f(1)
//     f(1, 2)
//     f(1, 2, 3)
//
// Arguments are positional; we cannot skip b and supply c.


// ========== SECTION 10: DEFAULTS BELONG AT DECLARATION ==========
//
// Common:
//
//     int multiply(int value, int factor = 2);
//
// Definition:
//
//     int multiply(int value, int factor) {
//         ...
//     }
//
// Do not repeat the same default in the definition.


// ========== SECTION 11: OVERLOAD + DEFAULT AMBIGUITY ==========
//
// Dangerous interface:
//
//     void show(int);
//     void show(int, int = 0);
//
// Call:
//
//     show(5);
//
// Both functions are viable.
// The call becomes ambiguous.


// Function declarations.

void show(int value);
void show(double value);

int sum(int a, int b);
int sum(int a, int b, int c);

int multiply(
    int value,
    int factor = 2
);

void printValue(
    int value,
    int times = 1
);

void inspect(int& value);
void inspect(const int& value);


int main() {

    cout << "=== DEMO 1: Type Overloading ===\n";

    show(10);
    show(3.5);

    cout << '\n';


    cout << "=== DEMO 2: Parameter Count Overloading ===\n";

    cout << "sum(2, 3) = "
         << sum(2, 3)
         << '\n';

    cout << "sum(2, 3, 4) = "
         << sum(2, 3, 4)
         << "\n\n";


    cout << "=== DEMO 3: Default Argument ===\n";

    cout << "multiply(5) = "
         << multiply(5)
         << '\n';

    cout << "multiply(5, 3) = "
         << multiply(5, 3)
         << "\n\n";


    cout << "=== DEMO 4: Multiple Calls With Default ===\n";

    printValue(7);
    printValue(9, 3);

    cout << '\n';


    cout << "=== DEMO 5: Reference Overloads ===\n";

    int mutableValue = 10;
    const int constantValue = 20;

    inspect(mutableValue);
    inspect(constantValue);
    inspect(30);

    cout << '\n';


    cout << "=== DEMO 6: Literal Types ===\n";

    // 2 is int -> show(int)
    show(2);

    // 2.0 is double -> show(double)
    show(2.0);

    return 0;
}


void show(int value) {

    cout << "show(int): "
         << value << '\n';
}


void show(double value) {

    cout << "show(double): "
         << value << '\n';
}


int sum(int a, int b) {

    return a + b;
}


int sum(int a, int b, int c) {

    return a + b + c;
}


int multiply(
    int value,
    int factor
) {
    return value * factor;
}


void printValue(
    int value,
    int times
) {
    for (int i = 0; i < times; ++i) {
        cout << value;

        if (i + 1 < times) {
            cout << ' ';
        }
    }

    cout << '\n';
}


void inspect(int& value) {

    cout << "mutable int&: "
         << value << '\n';
}


void inspect(const int& value) {

    cout << "const int&: "
         << value << '\n';
}


/*
EXPECTED OUTPUT

=== DEMO 1: Type Overloading ===
show(int): 10
show(double): 3.5

=== DEMO 2: Parameter Count Overloading ===
sum(2, 3) = 5
sum(2, 3, 4) = 9

=== DEMO 3: Default Argument ===
multiply(5) = 10
multiply(5, 3) = 15

=== DEMO 4: Multiple Calls With Default ===
7
9 9 9

=== DEMO 5: Reference Overloads ===
mutable int&: 10
const int&: 20
const int&: 30

=== DEMO 6: Literal Types ===
show(int): 2
show(double): 2

WHAT'S NEXT:
01_C++__/12_ARRAYS_1D_2D/
*/
