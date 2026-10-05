/*
TOPIC: C++ Introduction
FILE: 03_variation.cpp

This file demonstrates alternative valid forms of basic
C++ output.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>

// There is intentionally no:
//
// using namespace std;
//
// Therefore standard-library names are explicitly qualified.

int main() {

    // ========================================================
    // VARIATION 1: std::cout
    // ========================================================

    std::cout << "=== VARIATION 1: std::cout ===\n";
    std::cout << "using namespace std is optional.\n\n";


    // ========================================================
    // VARIATION 2: NEWLINE IN STRING
    // ========================================================

    std::cout << "=== VARIATION 2: Newline in String ===\n";

    std::cout << "A\n";
    std::cout << "B\n\n";


    // ========================================================
    // VARIATION 3: NEWLINE CHARACTER
    // ========================================================

    std::cout << "=== VARIATION 3: Newline Character ===\n";

    std::cout << "A" << '\n';
    std::cout << "B" << '\n';

    std::cout << '\n';


    // ========================================================
    // VARIATION 4: std::endl
    // ========================================================
    //
    // endl adds a newline and flushes the output stream.
    //
    // For routine algorithm output, '\n' is often preferred.

    std::cout << "=== VARIATION 4: std::endl ===" << std::endl;

    std::cout << "This uses endl." << std::endl;

    std::cout << '\n';


    // ========================================================
    // VARIATION 5: ONE OUTPUT EXPRESSION VS SEVERAL
    // ========================================================

    std::cout << "=== VARIATION 5: Equivalent Output ===\n";

    std::cout << "C++";
    std::cout << " ";
    std::cout << "DSA";
    std::cout << '\n';

    std::cout << "C++" << " " << "DSA" << '\n';

    std::cout << '\n';


    // ========================================================
    // VARIATION 6: SOURCE LINES VS OUTPUT LINES
    // ========================================================
    //
    // Breaking a statement across source lines does not
    // automatically create output newlines.

    std::cout << "=== VARIATION 6: Source Formatting ===\n";

    std::cout
        << "This "
        << "is "
        << "one output line."
        << '\n';


    return 0;
}

/*
EXPECTED OUTPUT

=== VARIATION 1: std::cout ===
using namespace std is optional.

=== VARIATION 2: Newline in String ===
A
B

=== VARIATION 3: Newline Character ===
A
B

=== VARIATION 4: std::endl ===
This uses endl.

=== VARIATION 5: Equivalent Output ===
C++ DSA
C++ DSA

=== VARIATION 6: Source Formatting ===
This is one output line.

WHAT'S NEXT:
01_C++__/02_VARIABLES_AND_DATA_TYPES/
*/
