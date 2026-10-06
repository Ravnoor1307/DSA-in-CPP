/*
TOPIC: Scope, Storage Duration, and Lifetime
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>

using namespace std;


// Namespace-scope variable.
// Storage duration: static.
int globalNumber = 50;


void ordinaryLocal() {

    // A new local is created each call.
    int value = 0;

    ++value;

    cout << value;
}


void persistentLocal() {

    // Initialized only once.
    static int value = 0;

    ++value;

    cout << value;
}


int main() {

    // ========================================================
    // BASIC 1: OUTER / INNER SCOPE
    // ========================================================

    cout << "=== BASIC 1: Nested Scope ===\n";

    int outer = 10;

    {
        int inner = 20;

        cout << "outer = "
             << outer << '\n';

        cout << "inner = "
             << inner << '\n';
    }

    cout << "outer still = "
         << outer << "\n\n";


    // ========================================================
    // BASIC 2: SEPARATE BLOCKS
    // ========================================================

    cout << "=== BASIC 2: Separate Blocks ===\n";

    {
        int x = 100;

        cout << x << '\n';
    }

    {
        // This is a different x.
        int x = 200;

        cout << x << '\n';
    }

    cout << '\n';


    // ========================================================
    // BASIC 3: SHADOWING
    // ========================================================

    cout << "=== BASIC 3: Shadowing ===\n";

    int score = 70;

    cout << "outer score = "
         << score << '\n';

    {
        int score = 90;

        cout << "inner score = "
             << score << '\n';
    }

    cout << "outer score = "
         << score << "\n\n";


    // ========================================================
    // BASIC 4: GLOBAL ACCESS
    // ========================================================

    cout << "=== BASIC 4: Global Variable ===\n";

    cout << "globalNumber = "
         << globalNumber
         << "\n\n";


    // ========================================================
    // BASIC 5: AUTOMATIC LOCAL
    // ========================================================

    cout << "=== BASIC 5: Automatic ===\n";

    ordinaryLocal();
    cout << ' ';

    ordinaryLocal();
    cout << ' ';

    ordinaryLocal();

    cout << "\n\n";


    // ========================================================
    // BASIC 6: STATIC LOCAL
    // ========================================================

    cout << "=== BASIC 6: Static Local ===\n";

    persistentLocal();
    cout << ' ';

    persistentLocal();
    cout << ' ';

    persistentLocal();

    cout << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Nested Scope ===
outer = 10
inner = 20
outer still = 10

=== BASIC 2: Separate Blocks ===
100
200

=== BASIC 3: Shadowing ===
outer score = 70
inner score = 90
outer score = 70

=== BASIC 4: Global Variable ===
globalNumber = 50

=== BASIC 5: Automatic ===
1 1 1

=== BASIC 6: Static Local ===
1 2 3

WHAT'S NEXT:
01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/
*/
