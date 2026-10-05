/*
TOPIC: Conditionals

Covers:
- if
- if-else
- else-if chains
- independent if statements
- nested conditions
- logical conditions
- short circuiting
- switch
- case/break/default
- fallthrough
- common conditional mistakes

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: IF ==========
//
// Syntax:
//
// if (condition) {
//     statements;
// }
//
// The body executes only when the condition is true.


// ========== SECTION 2: IF-ELSE ==========
//
// if (condition) {
//     true branch
// } else {
//     false branch
// }
//
// Exactly one branch executes.


// ========== SECTION 3: ELSE-IF CHAIN ==========
//
// Conditions are tested from top to bottom.
//
// The first true branch executes.
//
// Remaining branches in that chain are skipped.


// ========== SECTION 4: ORDER MATTERS ==========
//
// For overlapping score thresholds:
//
// if (score >= 90) ...
// else if (score >= 80) ...
//
// is meaningful.
//
// Putting a broad condition such as >= 60 first can make
// later stronger conditions unreachable for high scores.


// ========== SECTION 5: INDEPENDENT IF VS ELSE-IF ==========
//
// Independent:
//
// if (positive) ...
// if (even) ...
//
// Both may execute.
//
// Chain:
//
// if (positive) ...
// else if (even) ...
//
// At most one branch in the chain executes.


// ========== SECTION 6: LOGICAL CONDITIONS ==========
//
// && -> both conditions required
// || -> at least one required
// !  -> logical negation
//
// Example range:
//
// score >= 0 && score <= 100


// ========== SECTION 7: SHORT CIRCUITING ==========
//
// false && right
// skips right.
//
// true || right
// skips right.
//
// Put safety checks before expressions that depend on them.


// ========== SECTION 8: NESTED IF ==========
//
// An if can contain another if.
//
// if (adult) {
//     if (hasID) {
//         ...
//     }
// }


// ========== SECTION 9: BRACES ==========
//
// Prefer braces even for one statement.
//
// Indentation does NOT define control flow in C++.
//
// Avoid:
//
// if (condition)
//     statement1;
//     statement2;
//
// statement2 is outside the if.


// ========== SECTION 10: SWITCH ==========
//
// switch compares one integral/enum-like expression with
// discrete case constants.
//
// switch (value) {
//     case 1:
//         ...
//         break;
//
//     default:
//         ...
// }


// ========== SECTION 11: FALLTHROUGH ==========
//
// Without break, execution can continue into the next case.
//
// Sometimes this is intentional.
//
// C++17 provides:
//
// [[fallthrough]];
//
// for explicitly documenting intentional fallthrough.


// ========== SECTION 12: COMMON BUGS ==========
//
// Assignment:
//
//     x = 5
//
// Equality:
//
//     x == 5
//
// Wrong mathematical chaining:
//
//     0 < x < 10
//
// Correct:
//
//     0 < x && x < 10
//
// Wrong OR test:
//
//     choice == 'y' || 'Y'
//
// Correct:
//
//     choice == 'y' || choice == 'Y'


int main() {

    cout << "=== DEMO 1: Simple if ===\n";

    int age = 20;

    if (age >= 18) {
        cout << "Adult\n";
    }

    cout << "After the if\n\n";


    cout << "=== DEMO 2: if-else ===\n";

    int number = -5;

    if (number >= 0) {
        cout << "Non-negative\n";
    } else {
        cout << "Negative\n";
    }

    cout << '\n';


    cout << "=== DEMO 3: else-if Chain ===\n";

    int score = 85;

    if (score >= 90) {
        cout << "Grade A\n";
    } else if (score >= 80) {
        cout << "Grade B\n";
    } else if (score >= 70) {
        cout << "Grade C\n";
    } else {
        cout << "Below C\n";
    }

    cout << '\n';


    cout << "=== DEMO 4: Independent Conditions ===\n";

    int value = 10;

    if (value > 0) {
        cout << "Positive\n";
    }

    if (value % 2 == 0) {
        cout << "Even\n";
    }

    cout << '\n';


    cout << "=== DEMO 5: Range Condition ===\n";

    int percentage = 92;

    bool valid =
        percentage >= 0 &&
        percentage <= 100;

    if (valid) {
        cout << "Valid percentage\n";
    } else {
        cout << "Invalid percentage\n";
    }

    cout << '\n';


    cout << "=== DEMO 6: Nested if ===\n";

    bool isAdult = true;
    bool hasID = true;

    if (isAdult) {
        if (hasID) {
            cout << "Entry allowed\n";
        }
    }

    cout << '\n';


    cout << "=== DEMO 7: Positive/Negative/Zero ===\n";

    int test = 0;

    if (test > 0) {
        cout << "Positive\n";
    } else if (test < 0) {
        cout << "Negative\n";
    } else {
        cout << "Zero\n";
    }

    cout << '\n';


    cout << "=== DEMO 8: Even/Odd ===\n";

    int integer = 17;

    if (integer % 2 == 0) {
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }

    cout << '\n';


    cout << "=== DEMO 9: Short Circuit ===\n";

    int counter = 0;

    if (false && (++counter > 0)) {
        cout << "This will not print\n";
    }

    cout << "counter = "
         << counter << "\n\n";


    cout << "=== DEMO 10: switch ===\n";

    int day = 2;

    switch (day) {
        case 1:
            cout << "Monday\n";
            break;

        case 2:
            cout << "Tuesday\n";
            break;

        case 3:
            cout << "Wednesday\n";
            break;

        default:
            cout << "Unknown\n";
            break;
    }

    cout << '\n';


    cout << "=== DEMO 11: Intentional Shared Case ===\n";

    char grade = 'B';

    switch (grade) {
        case 'A':
        case 'B':
            cout << "High grade\n";
            break;

        case 'C':
            cout << "Middle grade\n";
            break;

        default:
            cout << "Other grade\n";
            break;
    }

    cout << '\n';


    cout << "=== DEMO 12: Leap Year ===\n";

    int year = 1900;

    bool leap =
        year % 400 == 0 ||
        (year % 4 == 0 &&
         year % 100 != 0);

    if (leap) {
        cout << year << " is leap\n";
    } else {
        cout << year << " is not leap\n";
    }

    return 0;
}


/*
EXPECTED OUTPUT

=== DEMO 1: Simple if ===
Adult
After the if

=== DEMO 2: if-else ===
Negative

=== DEMO 3: else-if Chain ===
Grade B

=== DEMO 4: Independent Conditions ===
Positive
Even

=== DEMO 5: Range Condition ===
Valid percentage

=== DEMO 6: Nested if ===
Entry allowed

=== DEMO 7: Positive/Negative/Zero ===
Zero

=== DEMO 8: Even/Odd ===
Odd

=== DEMO 9: Short Circuit ===
counter = 0

=== DEMO 10: switch ===
Tuesday

=== DEMO 11: Intentional Shared Case ===
High grade

=== DEMO 12: Leap Year ===
1900 is not leap

WHAT'S NEXT:
01_C++__/07_LOOPS/
*/
