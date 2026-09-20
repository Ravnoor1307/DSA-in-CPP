/*
═══════════════════════════════════════════════
 TASK SET — OPERATORS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
 A billing counter needs to calculate totals (arithmetic), apply buy-1-get-1
 logic (modulo), offer discounts to specific customer groups (logical and
 relational), and keep a running bill (compound assignment). Operators are
 what power every vertical bar / calculator / game scoreboard.

🧠 HOW TO SOLVE:
 Read the operation needed, then pick the operator: % for remainder/
 even-odd, compound ops for running totals, ternary for max/min,
 relational + logical for eligibility checks. ALWAYS watch the division
 by zero edge case.

 5 TASKS (EASY → HARD):

 ═══════════════════════════════════════════════
 TASK 1: EVEN OR ODD CHECKER
 ═══════════════════════════════════════════════
 Statement:
   Read an integer. Print "EVEN" if divisible by 2, else "ODD".
   Also handle negative numbers correctly (-4 is EVEN).

 💡 HINT:
   num % 2 == 0 means even. Works for negatives too (-4 % 2 == 0).
   Edge case: what about 0? (0 % 2 == 0 → EVEN).

 // TODO: Read int n
 // TODO: if (n % 2 == 0) print EVEN else print ODD
 // TODO: Also print n % 2 to show the pattern

 ═══════════════════════════════════════════════
 TASK 2: ARITHMETIC ON TWO NUMBERS — MINI CALC
 ═══════════════════════════════════════════════
 Statement:
   Read two integers. Print a+b, a-b, a*b, a/b, a%b.
   Guard against b == 0 for division.

 💡 HINT:
   Integer division drops remainder — note it in output.
   If b == 0, show error for '/' and '%' but still show + - *.

 // TODO: Read a, b
 // TODO: Print a+b, a-b, a*b
 // TODO: if b != 0 print a/b and a%b, else print division error

 ═══════════════════════════════════════════════
 TASK 3: MAX OF THREE USING TERNARY
 ═══════════════════════════════════════════════
 Statement:
   Read three integers. Find the largest using only the ternary
   operator (no if-else). Print it.

 💡 HINT:
   max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
   Nested ternary works like nested if-else.

 // TODO: Read a, b, c
 // TODO: Use nested ternary to compute max
 // TODO: Print max

 ═══════════════════════════════════════════════
 TASK 4: DIGIT SUM AND REVERSED DIGITS
 ═══════════════════════════════════════════════
 Statement:
   Read a 2-digit number (10-99). Print sum of its digits and the
   reversed number. Example: 47 → sum=11, reversed=74.
   Use / and % to extract digits.

 💡 HINT:
   tens = n / 10; ones = n % 10; reversed = ones*10 + tens;
   Edge case: two-digit validation (if outside 10-99, restart/error).

 // TODO: Read n (validate 10-99)
 // TODO: tens = n / 10; ones = n % 10
 // TODO: print sum and reversed

 ═══════════════════════════════════════════════
 TASK 5: SCHOLARSHIP ELIGIBILITY CHECKER
 ═══════════════════════════════════════════════
 Statement:
   A student gets a scholarship if (marks >= 85 AND attendance >= 90%)
   OR (has sports certificate). Read marks, attendance %, and whether
   they have a sports certificate (0/1). Print ELIGIBLE or NOT.
   Use logical + relational + ternary.

 💡 HINT:
   eligible = (marks >= 85 && attendance >= 90) || sports_certificate;
   Print result with ternary.
   Edge case: marks negative → reject immediately.

 // TODO: Read marks, attendance, sportsCert
 // TODO: Validate marks >= 0
 // TODO: eligible = (marks >= 85 && att >= 90) || sportsCert
 // TODO: Print ELIGIBLE / NOT using ternary

═══════════════════════════════════════════════
*/

// ==================== SOLUTIONS ====================
#include <iostream>
using namespace std;

// -------- TASK 1: Even or Odd --------
void task1_even_odd() {
    cout << "===== TASK 1: Even or Odd =====" << endl;

    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << n << " % 2 = " << (n % 2) << endl;
    if (n % 2 == 0)
        cout << n << " is EVEN" << endl;
    else
        cout << n << " is ODD" << endl;

    // negative ko bhi test karte hain
    int neg = -4;
    cout << "(edge) " << neg << " % 2 = " << (neg % 2)
         << " → " << (neg % 2 == 0 ? "EVEN" : "ODD") << endl;
    cout << endl;
}

// -------- TASK 2: Mini Calculator --------
void task2_mini_calc() {
    cout << "===== TASK 2: Mini Calculator =====" << endl;

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;

    if (b != 0) {
        cout << a << " / " << b << " = " << (a / b)
             << "   (integer division)" << endl;
        cout << a << " % " << b << " = " << (a % b) << "   (remainder)" << endl;
    } else {
        // division by zero guard — crash hone se bachao
        cout << "/ and %: DIVISION BY ZERO — not allowed!" << endl;
    }
    cout << endl;
}

// -------- TASK 3: Max of Three with Ternary --------
void task3_max_of_three() {
    cout << "===== TASK 3: Max of Three (Ternary) =====" << endl;

    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    // nested ternary — if-else jaisa hi, bas compact
    int max_val = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    cout << "max(" << a << ", " << b << ", " << c << ") = " << max_val << endl;
    cout << endl;
}

// -------- TASK 4: Digit Sum and Reverse --------
void task4_digit_sum_reverse() {
    cout << "===== TASK 4: Digit Sum and Reverse =====" << endl;

    int n;
    cout << "Enter a two-digit number (10-99): ";
    cin >> n;

    // validation
    if (n < 10 || n > 99) {
        cout << "Error: Please enter a 2-digit number only." << endl;
    } else {
        int tens = n / 10;   // quotient = tens digit
        int ones = n % 10;   // remainder = ones digit

        int sum = tens + ones;
        int reversed = ones * 10 + tens;

        cout << n << " → tens=" << tens << ", ones=" << ones << endl;
        cout << "Sum of digits       = " << sum << endl;
        cout << "Reversed number     = " << reversed << endl;
    }
    cout << endl;
}

// -------- TASK 5: Scholarship Eligibility --------
void task5_scholarship() {
    cout << "===== TASK 5: Scholarship Eligibility =====" << endl;

    double marks;
    double attendance;
    int sports_cert;

    cout << "Enter marks (0-100): ";
    cin >> marks;
    cout << "Enter attendance % (0-100): ";
    cin >> attendance;
    cout << "Has sports certificate? (1 for yes, 0 for no): ";
    cin >> sports_cert;

    if (marks < 0 || marks > 100 || attendance < 0 || attendance > 100) {
        cout << "Invalid input! Marks and attendance must be 0-100." << endl;
    } else {
        // logical + relational combine karke condition banayi
        bool eligible = (marks >= 85 && attendance >= 90) || (sports_cert == 1);

        cout << (eligible ? "ELIGIBLE for scholarship ✔" : "NOT eligible ✘")
             << endl;
        cout << "Reason breakdown:" << endl;
        cout << "  marks>=85 : " << (marks >= 85) << endl;
        cout << "  att>=90   : " << (attendance >= 90) << endl;
        cout << "  sports    : " << (sports_cert == 1) << endl;
    }
    cout << endl;
}

int main() {
    task1_even_odd();
    task2_mini_calc();
    task3_max_of_three();
    task4_digit_sum_reverse();
    task5_scholarship();

    cout << "All tasks completed!" << endl;
    return 0;
}