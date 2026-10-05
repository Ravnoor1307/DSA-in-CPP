/*
TOPIC: Loops

Covers:
- while
- do-while
- for
- loop execution order
- counters
- accumulators
- break
- continue
- nested loops
- infinite loops
- digit-processing loops
- complexity intuition
- common loop mistakes

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: WHY LOOPS EXIST ==========
//
// Loops repeat work.
//
// Instead of manually writing:
//
//     cout << 1;
//     cout << 2;
//     cout << 3;
//
// we can describe the repetition itself.


// ========== SECTION 2: WHILE LOOP ==========
//
// Syntax:
//
//     while (condition) {
//         body;
//     }
//
// The condition is checked before every iteration.
//
// Therefore the body can execute zero times.


// ========== SECTION 3: LOOP PROGRESS ==========
//
// A terminating loop normally needs:
//
//     state
//     condition
//     progress
//
// Example:
//
//     int i = 0;
//
//     while (i < 5) {
//         ++i;
//     }
//
// i moves toward making i < 5 false.


// ========== SECTION 4: DO-WHILE ==========
//
// Syntax:
//
//     do {
//         body;
//     } while (condition);
//
// The body executes before the condition is first checked.
//
// Therefore it executes at least once.


// ========== SECTION 5: FOR LOOP ==========
//
// Syntax:
//
//     for (initialization; condition; update) {
//         body;
//     }
//
// Execution:
//
//     initialization
//         |
//     condition
//         |
//      true
//         |
//       body
//         |
//       update
//         |
//     condition again


// ========== SECTION 6: COUNTERS ==========
//
// A counter tracks how many times something happens.
//
// Example:
//
//     int count = 0;
//
//     for (...) {
//         ++count;
//     }


// ========== SECTION 7: ACCUMULATORS ==========
//
// A running sum:
//
//     int sum = 0;
//
//     for (...) {
//         sum += value;
//     }
//
// A running product commonly starts at 1.


// ========== SECTION 8: BREAK ==========
//
// break exits the nearest enclosing loop immediately.


// ========== SECTION 9: CONTINUE ==========
//
// continue skips the remainder of the current iteration.
//
// In a for loop, control proceeds to the update expression.
//
// In a while loop, be careful not to skip a necessary manual
// update and accidentally create an infinite loop.


// ========== SECTION 10: NESTED LOOPS ==========
//
// A loop can contain another loop.
//
// Typical matrix-style structure:
//
//     for each row
//         for each column
//
// If both loops run n times, the body executes n*n times.


// ========== SECTION 11: OFF-BY-ONE ERRORS ==========
//
//     i < n
//
// normally visits:
//
//     0 ... n-1
//
// exactly n values for positive n.
//
//     i <= n
//
// additionally visits n.


// ========== SECTION 12: LOGARITHMIC LOOP ==========
//
//     for (int i = 1; i < n; i *= 2)
//
// takes approximately log2(n) iterations.
//
// Starting at zero would be incorrect because:
//
//     0 * 2 = 0


// ========== SECTION 13: LOOP INVARIANT ==========
//
// A loop invariant is a useful fact maintained across iterations.
//
// Example running sum:
//
// Before processing i:
//
//     sum contains the total of previously processed values.
//
// Invariants become essential when proving algorithms correct.


int main() {

    cout << "=== DEMO 1: while ===\n";

    int i = 1;

    while (i <= 5) {
        cout << i << ' ';
        ++i;
    }

    cout << "\nFinal i = " << i << "\n\n";


    cout << "=== DEMO 2: do-while ===\n";

    int value = 5;

    do {
        cout << "Body executes with value = "
             << value << '\n';

        ++value;

    } while (value < 5);

    cout << '\n';


    cout << "=== DEMO 3: for ===\n";

    for (int j = 1; j <= 5; ++j) {
        cout << j << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 4: Countdown ===\n";

    for (int j = 5; j >= 1; --j) {
        cout << j << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 5: Step Size ===\n";

    for (int j = 0; j <= 10; j += 2) {
        cout << j << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 6: Accumulator ===\n";

    int sum = 0;

    for (int j = 1; j <= 5; ++j) {
        sum += j;

        cout << "after adding "
             << j
             << ", sum = "
             << sum
             << '\n';
    }

    cout << '\n';


    cout << "=== DEMO 7: Factorial ===\n";

    int n = 5;
    long long factorial = 1;

    for (int j = 2; j <= n; ++j) {
        factorial *= j;
    }

    cout << "5! = "
         << factorial
         << "\n\n";


    cout << "=== DEMO 8: break ===\n";

    for (int j = 1; j <= 10; ++j) {

        if (j == 5) {
            break;
        }

        cout << j << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 9: continue ===\n";

    for (int j = 1; j <= 5; ++j) {

        if (j == 3) {
            continue;
        }

        cout << j << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 10: Nested Loops ===\n";

    for (int row = 1; row <= 2; ++row) {

        for (int col = 1; col <= 3; ++col) {

            cout << '('
                 << row
                 << ','
                 << col
                 << ") ";
        }

        cout << '\n';
    }

    cout << '\n';


    cout << "=== DEMO 11: Digit Extraction ===\n";

    int number = 482;
    int temp = number;

    while (temp > 0) {

        int digit =
            temp % 10;

        cout << "digit = "
             << digit
             << '\n';

        temp /= 10;
    }

    cout << '\n';


    cout << "=== DEMO 12: Sum of Digits ===\n";

    number = 482;
    temp = number;

    int digitSum = 0;

    while (temp > 0) {

        int digit =
            temp % 10;

        digitSum += digit;
        temp /= 10;
    }

    cout << "sum = "
         << digitSum
         << "\n\n";


    cout << "=== DEMO 13: Logarithmic Progression ===\n";

    for (int power = 1;
         power < 20;
         power *= 2) {

        cout << power << ' ';
    }

    cout << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== DEMO 1: while ===
1 2 3 4 5
Final i = 6

=== DEMO 2: do-while ===
Body executes with value = 5

=== DEMO 3: for ===
1 2 3 4 5

=== DEMO 4: Countdown ===
5 4 3 2 1

=== DEMO 5: Step Size ===
0 2 4 6 8 10

=== DEMO 6: Accumulator ===
after adding 1, sum = 1
after adding 2, sum = 3
after adding 3, sum = 6
after adding 4, sum = 10
after adding 5, sum = 15

=== DEMO 7: Factorial ===
5! = 120

=== DEMO 8: break ===
1 2 3 4

=== DEMO 9: continue ===
1 2 4 5

=== DEMO 10: Nested Loops ===
(1,1) (1,2) (1,3)
(2,1) (2,2) (2,3)

=== DEMO 11: Digit Extraction ===
digit = 2
digit = 8
digit = 4

=== DEMO 12: Sum of Digits ===
sum = 14

=== DEMO 13: Logarithmic Progression ===
1 2 4 8 16

WHAT'S NEXT:
01_C++__/08_FUNCTIONS/
*/
