/*
TOPIC: Functions

Covers:
- Function definitions
- Function declarations
- Calls
- Parameters
- Arguments
- Return values
- void
- Early return
- Local variables
- Pass-by-value introduction
- Functions calling functions
- Call-stack mental model
- Function decomposition
- Function complexity

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: FUNCTION DECLARATIONS ==========
//
// A declaration introduces a function interface:
//
//     int add(int a, int b);
//
// The parameter names can even be omitted in a declaration:
//
//     int add(int, int);
//
// The definition appears later.


// Function declarations used by main().
void greet();
int add(int a, int b);
int square(int x);
bool isEven(int x);
int maximum(int a, int b);
long long sumToN(int n);
void changeCopy(int x);
int sumOfSquares(int a, int b);
void printPositive(int x);


// ========== SECTION 2: FUNCTION DEFINITION ==========
//
// Example:
//
//     int add(int a, int b) {
//         return a + b;
//     }
//
// int:
//     return type
//
// add:
//     name
//
// a, b:
//     parameters
//
// {...}:
//     body


// ========== SECTION 3: FUNCTION CALL ==========
//
//     add(10, 20)
//
// 10 and 20 are arguments.
//
// The call transfers control to add.
//
// add eventually returns control to the caller.


// ========== SECTION 4: PARAMETERS VS ARGUMENTS ==========
//
// Definition:
//
//     int add(int a, int b)
//
// a and b are parameters.
//
// Call:
//
//     add(4, 7)
//
// 4 and 7 are arguments.


// ========== SECTION 5: RETURN ==========
//
// A value-returning function can:
//
//     return expression;
//
// return both provides a result and ends the current function call.


// ========== SECTION 6: VOID ==========
//
// void means the function does not return a value.
//
//     void greet() {
//         cout << "Hello";
//     }


// ========== SECTION 7: EARLY RETURN ==========
//
// A function can return before reaching its final brace.
//
//     void printPositive(int x) {
//         if (x <= 0) {
//             return;
//         }
//
//         cout << x;
//     }


// ========== SECTION 8: LOCAL VARIABLES ==========
//
// Variables declared inside a function/block are local to their
// scope.
//
// Each independent active call has its own parameters and locals.


// ========== SECTION 9: PASS BY VALUE INTRODUCTION ==========
//
// Ordinary scalar parameter:
//
//     void changeCopy(int x)
//
// receives a separate value.
//
// Changing x does not modify the caller's int.
//
// References and pointers are taught later.


// ========== SECTION 10: FUNCTIONS CALLING FUNCTIONS ==========
//
// A helper can call another helper.
//
//     sumOfSquares()
//         |
//         +--> square()
//         |
//         +--> square()


// ========== SECTION 11: CALL STACK MENTAL MODEL ==========
//
// main calls A:
//
//     main
//       |
//       v
//       A
//
// A calls B:
//
//     main -> A -> B
//
// B returns:
//
//     main -> A
//
// A returns:
//
//     main
//
// This model becomes critical during recursion.


// ========== SECTION 12: FUNCTION COMPLEXITY ==========
//
// A function's complexity depends on its implementation.
//
//     square(x)
//     -> O(1)
//
//     sumToN(n)
//     -> O(n)
//
// Calling a function does not make the work disappear from
// complexity analysis.


int main() {

    cout << "=== DEMO 1: void Function ===\n";

    greet();

    cout << '\n';


    cout << "=== DEMO 2: Parameters and Return Value ===\n";

    int answer = add(10, 20);

    cout << "add(10, 20) = "
         << answer << "\n\n";


    cout << "=== DEMO 3: Reusing a Function ===\n";

    cout << "square(3) = "
         << square(3) << '\n';

    cout << "square(7) = "
         << square(7) << "\n\n";


    cout << "=== DEMO 4: Boolean Function ===\n";

    cout << boolalpha;

    cout << "isEven(8) = "
         << isEven(8) << '\n';

    cout << "isEven(9) = "
         << isEven(9) << "\n\n";

    cout << noboolalpha;


    cout << "=== DEMO 5: Maximum ===\n";

    cout << "maximum(12, 30) = "
         << maximum(12, 30)
         << "\n\n";


    cout << "=== DEMO 6: Function With a Loop ===\n";

    cout << "sumToN(5) = "
         << sumToN(5)
         << "\n\n";


    cout << "=== DEMO 7: Pass by Value Preview ===\n";

    int number = 10;

    cout << "Before call: "
         << number << '\n';

    changeCopy(number);

    cout << "After call: "
         << number << "\n\n";


    cout << "=== DEMO 8: Function Calling Functions ===\n";

    cout << "sumOfSquares(3, 4) = "
         << sumOfSquares(3, 4)
         << "\n\n";


    cout << "=== DEMO 9: Early Return ===\n";

    printPositive(-5);
    printPositive(12);

    return 0;
}


// ============================================================
// FUNCTION DEFINITIONS
// ============================================================

void greet() {

    cout << "Hello from greet()\n";
}


int add(int a, int b) {

    return a + b;
}


int square(int x) {

    return x * x;
}


bool isEven(int x) {

    return x % 2 == 0;
}


int maximum(int a, int b) {

    if (a > b) {
        return a;
    }

    return b;
}


long long sumToN(int n) {

    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    return sum;
}


void changeCopy(int x) {

    cout << "Inside before change: "
         << x << '\n';

    x = 99;

    cout << "Inside after change: "
         << x << '\n';
}


int sumOfSquares(int a, int b) {

    return square(a) + square(b);
}


void printPositive(int x) {

    if (x <= 0) {
        cout << x
             << " is not positive; returning early.\n";

        return;
    }

    cout << x << " is positive.\n";
}


/*
EXPECTED OUTPUT

=== DEMO 1: void Function ===
Hello from greet()

=== DEMO 2: Parameters and Return Value ===
add(10, 20) = 30

=== DEMO 3: Reusing a Function ===
square(3) = 9
square(7) = 49

=== DEMO 4: Boolean Function ===
isEven(8) = true
isEven(9) = false

=== DEMO 5: Maximum ===
maximum(12, 30) = 30

=== DEMO 6: Function With a Loop ===
sumToN(5) = 15

=== DEMO 7: Pass by Value Preview ===
Before call: 10
Inside before change: 10
Inside after change: 99
After call: 10

=== DEMO 8: Function Calling Functions ===
sumOfSquares(3, 4) = 25

=== DEMO 9: Early Return ===
-5 is not positive; returning early.
12 is positive.

WHAT'S NEXT:
01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/
*/
