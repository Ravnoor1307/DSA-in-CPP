/*
TOPIC: Function Overloading and Default Arguments
FILE: 03_variation.cpp

Purpose:
Explore overload resolution details and default-argument
design issues without deliberately placing compilation errors
in executable code.

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>

using namespace std;


// ============================================================
// VARIATION 1: FLOAT VS DOUBLE
// ============================================================

void identify(float) {

    cout << "float overload\n";
}


void identify(double) {

    cout << "double overload\n";
}


// ============================================================
// VARIATION 2: INT VS DOUBLE
// ============================================================

void classify(int) {

    cout << "int overload\n";
}


void classify(double) {

    cout << "double overload\n";
}


// ============================================================
// VARIATION 3: CONST REFERENCE
// ============================================================

void access(int&) {

    cout << "mutable reference\n";
}


void access(const int&) {

    cout << "const reference\n";
}


// ============================================================
// VARIATION 4: DEFAULTS
// ============================================================

void configure(
    int width = 800,
    int height = 600
) {
    cout << width
         << 'x'
         << height
         << '\n';
}


// ============================================================
// VARIATION 5: CORE OVERLOAD + CONVENIENCE OVERLOAD
// ============================================================

int rectangleArea(
    int width,
    int height
);

int rectangleArea(int side) {

    // Delegate to the two-argument overload.
    return rectangleArea(side, side);
}


int rectangleArea(
    int width,
    int height
) {
    return width * height;
}


int main() {

    cout << "=== VARIATION 1: Literal Types ===\n";

    identify(2.5f);
    identify(2.5);

    cout << '\n';


    cout << "=== VARIATION 2: Exact Match ===\n";

    classify(5);
    classify(5.0);

    cout << '\n';


    cout << "=== VARIATION 3: Reference Selection ===\n";

    int mutableValue = 10;
    const int constantValue = 20;

    access(mutableValue);
    access(constantValue);
    access(30);

    cout << '\n';


    cout << "=== VARIATION 4: Default Arguments ===\n";

    configure();
    configure(1920);
    configure(1920, 1080);

    cout << '\n';


    cout << "=== VARIATION 5: Delegating Overload ===\n";

    cout << "square area = "
         << rectangleArea(5)
         << '\n';

    cout << "rectangle area = "
         << rectangleArea(5, 8)
         << "\n\n";


    cout << "=== VARIATION 6: Invalid Examples (Comments Only) ===\n";

    cout << "See source comments for intentionally invalid cases.\n";

    /*
    ------------------------------------------------------------
    INVALID CASE A: RETURN TYPE ONLY
    ------------------------------------------------------------

    int test(int);
    double test(int);

    Not a valid overload pair.


    ------------------------------------------------------------
    INVALID CASE B: AMBIGUITY CAUSED BY DEFAULT
    ------------------------------------------------------------

    void show(int);
    void show(int, int = 0);

    show(5);

    Both overloads are viable.


    ------------------------------------------------------------
    INVALID CASE C: REPEATED DEFAULT
    ------------------------------------------------------------

    void example(int value = 1);

    void example(int value = 1) {
    }

    Do not repeat the same default.


    ------------------------------------------------------------
    INVALID CASE D: MIDDLE PARAMETER WITHOUT DEFAULT
    ------------------------------------------------------------

    void example(
        int first = 1,
        int second
    );

    This simple declaration violates the trailing-default rule.


    ------------------------------------------------------------
    POSSIBLY AMBIGUOUS CASE: CONVERSIONS
    ------------------------------------------------------------

    void choose(int);
    void choose(double);

    choose(10LL);

    A long long can require standard conversion for either
    candidate, and the compiler may have no unique best function.
    */

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Literal Types ===
float overload
double overload

=== VARIATION 2: Exact Match ===
int overload
double overload

=== VARIATION 3: Reference Selection ===
mutable reference
const reference
const reference

=== VARIATION 4: Default Arguments ===
800x600
1920x600
1920x1080

=== VARIATION 5: Delegating Overload ===
square area = 25
rectangle area = 40

=== VARIATION 6: Invalid Examples (Comments Only) ===
See source comments for intentionally invalid cases.

WHAT'S NEXT:
01_C++__/12_ARRAYS_1D_2D/
*/
