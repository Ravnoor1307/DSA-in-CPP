/*
TOPIC: Functions
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;


// ============================================================
// BASIC FUNCTION 1: NO PARAMETERS, NO RETURN VALUE
// ============================================================

void printSeparator() {

    cout << "--------------------\n";
}


// ============================================================
// BASIC FUNCTION 2: PARAMETER + RETURN VALUE
// ============================================================

int square(int number) {

    return number * number;
}


// ============================================================
// BASIC FUNCTION 3: MULTIPLE PARAMETERS
// ============================================================

int add(int a, int b) {

    return a + b;
}


// ============================================================
// BASIC FUNCTION 4: BOOL RETURN
// ============================================================

bool isPositive(int value) {

    return value > 0;
}


// ============================================================
// BASIC FUNCTION 5: LOOP INSIDE FUNCTION
// ============================================================

long long sumFromOneTo(int n) {

    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    return sum;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    cout << boolalpha;


    cout << "=== BASIC 1: void Function ===\n";

    printSeparator();

    cout << '\n';


    cout << "=== BASIC 2: Return Value ===\n";

    int result = square(6);

    cout << "square(6) = "
         << result << "\n\n";


    cout << "=== BASIC 3: Multiple Parameters ===\n";

    cout << "add(7, 8) = "
         << add(7, 8) << "\n\n";


    cout << "=== BASIC 4: bool Function ===\n";

    cout << "isPositive(9) = "
         << isPositive(9) << '\n';

    cout << "isPositive(-2) = "
         << isPositive(-2) << "\n\n";


    cout << "=== BASIC 5: Repeated Calls ===\n";

    cout << square(2) << '\n';
    cout << square(3) << '\n';
    cout << square(4) << "\n\n";


    cout << "=== BASIC 6: Loop in Function ===\n";

    cout << "sum 1..10 = "
         << sumFromOneTo(10)
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: void Function ===
--------------------

=== BASIC 2: Return Value ===
square(6) = 36

=== BASIC 3: Multiple Parameters ===
add(7, 8) = 15

=== BASIC 4: bool Function ===
isPositive(9) = true
isPositive(-2) = false

=== BASIC 5: Repeated Calls ===
4
9
16

=== BASIC 6: Loop in Function ===
sum 1..10 = 55

WHAT'S NEXT:
01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/
*/
