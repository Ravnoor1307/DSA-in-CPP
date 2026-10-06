/*
TOPIC: Functions
FILE: 03_variation.cpp

Purpose:
Explore declarations, early returns, pass-by-value,
nested calls, and function decomposition.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


// This is only a declaration.
// The definition appears after main.
int cube(int x);


bool isEven(int x) {

    return x % 2 == 0;
}


bool isOdd(int x) {

    // Reuse another function.
    return !isEven(x);
}


int absoluteForSafeInput(int x) {

    // Early return.
    //
    // This simple implementation is intended for ordinary values.
    // Negating INT_MIN would overflow.

    if (x >= 0) {
        return x;
    }

    return -x;
}


void modifyCopy(int value) {

    value = 500;

    cout << "Inside modifyCopy: "
         << value << '\n';
}


int minimum(int a, int b) {

    if (a < b) {
        return a;
    }

    return b;
}


int minimumOfThree(int a, int b, int c) {

    // Function composition:
    return minimum(
        minimum(a, b),
        c
    );
}


int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: DECLARATION BEFORE DEFINITION
    // ========================================================

    cout << "=== VARIATION 1: Prototype ===\n";

    cout << "cube(4) = "
         << cube(4)
         << "\n\n";


    // ========================================================
    // VARIATION 2: FUNCTION REUSE
    // ========================================================

    cout << "=== VARIATION 2: Function Reuse ===\n";

    cout << "isEven(7) = "
         << isEven(7) << '\n';

    cout << "isOdd(7) = "
         << isOdd(7) << "\n\n";


    // ========================================================
    // VARIATION 3: EARLY RETURN
    // ========================================================

    cout << "=== VARIATION 3: Early Return ===\n";

    cout << "abs-like value of -12 = "
         << absoluteForSafeInput(-12)
         << "\n\n";


    // ========================================================
    // VARIATION 4: PASS-BY-VALUE PREVIEW
    // ========================================================

    int original = 10;

    cout << "=== VARIATION 4: Pass by Value ===\n";

    cout << "Before: "
         << original << '\n';

    modifyCopy(original);

    cout << "After: "
         << original << "\n\n";


    // ========================================================
    // VARIATION 5: COMPOSING FUNCTIONS
    // ========================================================

    cout << "=== VARIATION 5: Composition ===\n";

    cout << "minimum of 30, 10, 20 = "
         << minimumOfThree(30, 10, 20)
         << '\n';

    return 0;
}


// Definition corresponding to the earlier declaration.
int cube(int x) {

    return x * x * x;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Prototype ===
cube(4) = 64

=== VARIATION 2: Function Reuse ===
isEven(7) = false
isOdd(7) = true

=== VARIATION 3: Early Return ===
abs-like value of -12 = 12

=== VARIATION 4: Pass by Value ===
Before: 10
Inside modifyCopy: 500
After: 10

=== VARIATION 5: Composition ===
minimum of 30, 10, 20 = 10

WHAT'S NEXT:
01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/
*/
