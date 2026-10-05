/*
TOPIC: C++ Introduction
FILE: 04_practice_problems.cpp

Try to produce each requested output yourself before reading
the implementation.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>

using namespace std;

int main() {

    // ========================================================
    // PROBLEM 1
    // ========================================================
    //
    // Print:
    //
    // Hello, DSA!

    cout << "=== PROBLEM 1 ===\n";

    cout << "Hello, DSA!\n\n";


    // ========================================================
    // PROBLEM 2
    // ========================================================
    //
    // Print:
    //
    // Learn
    // Practice
    // Improve

    cout << "=== PROBLEM 2 ===\n";

    cout << "Learn\n";
    cout << "Practice\n";
    cout << "Improve\n\n";


    // ========================================================
    // PROBLEM 3
    // ========================================================
    //
    // Build this output using chained << operators:
    //
    // C++ -> DSA -> Algorithms

    cout << "=== PROBLEM 3 ===\n";

    cout << "C++"
         << " -> "
         << "DSA"
         << " -> "
         << "Algorithms"
         << '\n';

    cout << '\n';


    // ========================================================
    // PROBLEM 4
    // ========================================================
    //
    // Print quotation marks and a Windows-style path:
    //
    // He said, "Learn C++".
    // Folder: C:\DSA

    cout << "=== PROBLEM 4 ===\n";

    cout << "He said, \"Learn C++\".\n";
    cout << "Folder: C:\\DSA\n\n";


    // ========================================================
    // PROBLEM 5
    // ========================================================
    //
    // Print a simple card.

    cout << "=== PROBLEM 5 ===\n";

    cout << "--------------------\n";
    cout << "C++ DSA JOURNEY\n";
    cout << "Topic: Introduction\n";
    cout << "Status: Learning\n";
    cout << "--------------------\n\n";


    // ========================================================
    // BONUS: DRY RUN
    // ========================================================
    //
    // Predict this before running:
    //
    // cout << "A";
    // cout << "B\nC";
    // cout << '\n';
    // cout << "D";
    //
    // Output should be:
    //
    // AB
    // C
    // D

    cout << "=== BONUS ===\n";

    cout << "A";
    cout << "B\nC";
    cout << '\n';
    cout << "D";
    cout << '\n';

    return 0;
}

/*
EXPECTED OUTPUT

=== PROBLEM 1 ===
Hello, DSA!

=== PROBLEM 2 ===
Learn
Practice
Improve

=== PROBLEM 3 ===
C++ -> DSA -> Algorithms

=== PROBLEM 4 ===
He said, "Learn C++".
Folder: C:\DSA

=== PROBLEM 5 ===
--------------------
C++ DSA JOURNEY
Topic: Introduction
Status: Learning
--------------------

=== BONUS ===
AB
C
D

WHAT'S NEXT:
01_C++__/02_VARIABLES_AND_DATA_TYPES/
*/
