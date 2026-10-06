/*
TOPIC: Scope, Storage Duration, and Lifetime
FILE: 03_variation.cpp

Purpose:
Demonstrate important variations:
- global/local shadowing
- static local persistence
- loop-local lifetime
- nested blocks
- independent function locals

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


int value = 10;


void firstFunction() {

    int local = 100;

    cout << "first local = "
         << local << '\n';
}


void secondFunction() {

    // Different object despite same spelling.
    int local = 200;

    cout << "second local = "
         << local << '\n';
}


void statefulFunction() {

    static int calls = 0;

    ++calls;

    cout << "call count = "
         << calls << '\n';
}


int main() {

    // ========================================================
    // VARIATION 1: LOCAL HIDES GLOBAL
    // ========================================================

    cout << "=== VARIATION 1: Global vs Local ===\n";

    int value = 99;

    cout << "local = "
         << value << '\n';

    cout << "global = "
         << ::value << "\n\n";


    // ========================================================
    // VARIATION 2: SAME NAME IN DIFFERENT FUNCTIONS
    // ========================================================

    cout << "=== VARIATION 2: Function Locals ===\n";

    firstFunction();
    secondFunction();

    cout << '\n';


    // ========================================================
    // VARIATION 3: LOOP LOCAL OBJECT
    // ========================================================

    cout << "=== VARIATION 3: Loop Local ===\n";

    for (int i = 1; i <= 3; ++i) {

        int local = i;

        cout << "created local = "
             << local << '\n';

        // local's lifetime ends when this iteration
        // leaves the block.
    }

    cout << '\n';


    // ========================================================
    // VARIATION 4: STATIC LOCAL
    // ========================================================

    cout << "=== VARIATION 4: Stateful Function ===\n";

    statefulFunction();
    statefulFunction();
    statefulFunction();

    cout << '\n';


    // ========================================================
    // VARIATION 5: DEEPLY NESTED VISIBILITY
    // ========================================================

    cout << "=== VARIATION 5: Nested Visibility ===\n";

    int a = 1;

    {
        int b = 2;

        {
            int c = 3;

            cout << a << ' '
                 << b << ' '
                 << c << '\n';
        }

        cout << a << ' '
             << b << '\n';
    }

    cout << a << "\n\n";


    // ========================================================
    // VARIATION 6: STATIC IN A LOOP BLOCK
    // ========================================================

    cout << "=== VARIATION 6: Static in Loop ===\n";

    for (int i = 0; i < 4; ++i) {

        static int persistent = 10;

        ++persistent;

        cout << persistent << ' ';
    }

    cout << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Global vs Local ===
local = 99
global = 10

=== VARIATION 2: Function Locals ===
first local = 100
second local = 200

=== VARIATION 3: Loop Local ===
created local = 1
created local = 2
created local = 3

=== VARIATION 4: Stateful Function ===
call count = 1
call count = 2
call count = 3

=== VARIATION 5: Nested Visibility ===
1 2 3
1 2
1

=== VARIATION 6: Static in Loop ===
11 12 13 14

WHAT'S NEXT:
01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/
*/
