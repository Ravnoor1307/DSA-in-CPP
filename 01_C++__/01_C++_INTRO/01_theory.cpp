/*
TOPIC: C++ Introduction

Covers:
- Program structure
- #include
- main()
- statements
- cout
- newlines
- escape sequences
- namespaces
- comments
- compile time and runtime

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: PROGRAM STRUCTURE ==========
//
// A C++ source file commonly ends in .cpp.
//
// A normal standalone program begins execution at main().
//
// int main() {
//     ...
//     return 0;
// }
//
// return 0 conventionally indicates successful termination.


// ========== SECTION 2: IOSTREAM ==========
//
// #include <iostream>
//
// makes standard stream declarations such as std::cout
// available to this source file.


// ========== SECTION 3: COUT ==========
//
// cout represents the standard output stream.
//
// Example:
//
// cout << "Hello";
//
// << sends information into the output stream.
//
// cout does not automatically add a newline.


// ========== SECTION 4: NEWLINES ==========
//
// cout << "A";
// cout << "B";
//
// produces:
//
// AB
//
// We can explicitly add a newline:
//
// cout << '\n';


// ========== SECTION 5: ESCAPE SEQUENCES ==========
//
// \n  newline
// \t  tab
// \\  backslash
// \"  double quote


// ========== SECTION 6: NAMESPACE STD ==========
//
// cout's fully-qualified name is:
//
// std::cout
//
// "using namespace std;" allows us to write cout instead.
//
// In larger programs, broad using-directives are commonly avoided
// because they can introduce naming conflicts.


// ========== SECTION 7: COMMENTS ==========
//
// // creates a line comment.
//
// Block comments use slash-star and star-slash.
//
// Comments are not executable program instructions.


// ========== SECTION 8: COMPILATION ==========
//
// Simplified:
//
// source
//   |
// preprocessing
//   |
// compilation
//   |
// assembly
//   |
// linking
//   |
// executable
//
// Compile time and runtime are separate phases.


// ========== SECTION 9: ERROR CATEGORIES ==========
//
// Compilation error:
// Source cannot successfully compile.
//
// Linker error:
// Required definitions cannot be resolved while building.
//
// Runtime error:
// A problem occurs while executing.
//
// Logical error:
// Program executes but produces the wrong answer.


int main() {

    cout << "=== DEMO 1: main() ===\n";
    cout << "Execution is currently inside main().\n\n";


    cout << "=== DEMO 2: Sequential Statements ===\n";

    cout << "First\n";
    cout << "Second\n";
    cout << "Third\n";

    cout << '\n';


    cout << "=== DEMO 3: No Automatic Newline ===\n";

    cout << "A";
    cout << "B";
    cout << "C";

    cout << '\n';
    cout << '\n';


    cout << "=== DEMO 4: Chained Output ===\n";

    cout << "C++" << " + " << "DSA" << '\n';

    cout << '\n';


    cout << "=== DEMO 5: Escape Sequences ===\n";

    cout << "Newline:\nNext line\n";
    cout << "Tab:\tC++\n";
    cout << "Quote: \"DSA\"\n";
    cout << "Backslash: \\\n";

    cout << '\n';


    cout << "=== DEMO 6: Namespace ===\n";

    cout << "cout works because std names were made available.\n";
    std::cout << "std::cout explicitly names the standard namespace.\n";

    cout << '\n';


    cout << "=== DEMO 7: Comments ===\n";

    // This text exists in source code but produces no output.

    cout << "Comments do not become normal program output.\n\n";


    cout << "=== DEMO 8: Program Termination ===\n";
    cout << "main() will now return 0.\n";

    return 0;
}

/*
EXPECTED OUTPUT

=== DEMO 1: main() ===
Execution is currently inside main().

=== DEMO 2: Sequential Statements ===
First
Second
Third

=== DEMO 3: No Automatic Newline ===
ABC

=== DEMO 4: Chained Output ===
C++ + DSA

=== DEMO 5: Escape Sequences ===
Newline:
Next line
Tab:    C++
Quote: "DSA"
Backslash: \

=== DEMO 6: Namespace ===
cout works because std names were made available.
std::cout explicitly names the standard namespace.

=== DEMO 7: Comments ===
Comments do not become normal program output.

=== DEMO 8: Program Termination ===
main() will now return 0.

Tab width can differ between terminals.

WHAT'S NEXT:
01_C++__/02_VARIABLES_AND_DATA_TYPES/
*/
