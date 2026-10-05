/*
TOPIC: C++ Introduction
FILE: 02_basics.cpp

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>

using namespace std;

int main() {

    // ========================================================
    // BASIC 1: PRINTING TEXT
    // ========================================================

    cout << "=== BASIC 1: Printing Text ===\n";

    cout << "Hello, World!\n";
    cout << "I am learning C++ for DSA.\n\n";


    // ========================================================
    // BASIC 2: SEQUENTIAL EXECUTION
    // ========================================================

    cout << "=== BASIC 2: Sequential Execution ===\n";

    cout << "First\n";
    cout << "Second\n";
    cout << "Third\n\n";


    // ========================================================
    // BASIC 3: NO AUTOMATIC SPACES
    // ========================================================

    cout << "=== BASIC 3: Spaces ===\n";

    cout << "Data";
    cout << "Structures";
    cout << '\n';

    cout << "Data";
    cout << " ";
    cout << "Structures";
    cout << '\n';

    cout << '\n';


    // ========================================================
    // BASIC 4: CHAINING OUTPUT
    // ========================================================

    cout << "=== BASIC 4: Chaining ===\n";

    cout << "C++" << " " << "DSA" << " " << "Journey" << '\n';

    cout << '\n';


    // ========================================================
    // BASIC 5: ESCAPE SEQUENCES
    // ========================================================

    cout << "=== BASIC 5: Escape Sequences ===\n";

    cout << "Line 1\nLine 2\n";
    cout << "Tab:\tHere\n";
    cout << "Quote: \"Hello\"\n";
    cout << "Path: C:\\DSA\\C++\n";

    cout << '\n';


    // ========================================================
    // BASIC 6: SIMPLE REPORT
    // ========================================================

    cout << "=== BASIC 6: Report ===\n";

    cout << "Course: C++ DSA\n";
    cout << "Topic: Introduction\n";
    cout << "Status: Started\n";

    return 0;
}

/*
EXPECTED OUTPUT

=== BASIC 1: Printing Text ===
Hello, World!
I am learning C++ for DSA.

=== BASIC 2: Sequential Execution ===
First
Second
Third

=== BASIC 3: Spaces ===
DataStructures
Data Structures

=== BASIC 4: Chaining ===
C++ DSA Journey

=== BASIC 5: Escape Sequences ===
Line 1
Line 2
Tab:    Here
Quote: "Hello"
Path: C:\DSA\C++

=== BASIC 6: Report ===
Course: C++ DSA
Topic: Introduction
Status: Started

Tab width may differ by terminal.

WHAT'S NEXT:
01_C++__/02_VARIABLES_AND_DATA_TYPES/
*/
