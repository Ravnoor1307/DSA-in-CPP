/*
TOPIC: Function Overloading and Default Arguments
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;


// ============================================================
// BASIC 1: OVERLOAD BY TYPE
// ============================================================

void describe(int value) {

    cout << "integer: "
         << value << '\n';
}


void describe(double value) {

    cout << "double: "
         << value << '\n';
}


// ============================================================
// BASIC 2: OVERLOAD BY PARAMETER COUNT
// ============================================================

int maximum(int a, int b) {

    return (a > b) ? a : b;
}


int maximum(int a, int b, int c) {

    return maximum(
        maximum(a, b),
        c
    );
}


// ============================================================
// BASIC 3: DEFAULT PARAMETER
// ============================================================

int powerLike(
    int value,
    int repetitions = 2
) {
    int result = 1;

    for (int i = 0; i < repetitions; ++i) {
        result *= value;
    }

    return result;
}


// ============================================================
// BASIC 4: MULTIPLE DEFAULTS
// ============================================================

void printRange(
    int start,
    int end = 5,
    int step = 1
) {
    for (int value = start;
         value <= end;
         value += step) {

        cout << value << ' ';
    }

    cout << '\n';
}


int main() {

    cout << "=== BASIC 1: Overload by Type ===\n";

    describe(10);
    describe(2.5);

    cout << '\n';


    cout << "=== BASIC 2: Overload by Count ===\n";

    cout << maximum(10, 20)
         << '\n';

    cout << maximum(10, 30, 20)
         << "\n\n";


    cout << "=== BASIC 3: Default Argument ===\n";

    cout << "default repetitions: "
         << powerLike(3)
         << '\n';

    cout << "explicit repetitions: "
         << powerLike(3, 3)
         << "\n\n";


    cout << "=== BASIC 4: Multiple Defaults ===\n";

    printRange(1);
    printRange(2, 8);
    printRange(2, 10, 2);

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Overload by Type ===
integer: 10
double: 2.5

=== BASIC 2: Overload by Count ===
20
30

=== BASIC 3: Default Argument ===
default repetitions: 9
explicit repetitions: 27

=== BASIC 4: Multiple Defaults ===
1 2 3 4 5
2 3 4 5 6 7 8
2 4 6 8 10

WHAT'S NEXT:
01_C++__/12_ARRAYS_1D_2D/
*/
