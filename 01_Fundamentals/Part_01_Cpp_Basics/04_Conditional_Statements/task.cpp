/*
═══════════════════════════════════════════════
 TASK SET — CONDITIONAL STATEMENTS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
 A school's automation system evaluates students — grades for reports, pass/
 fail for promotions, and scholarship decisions. A traffic-light controller
 also uses conditionals for signals. Every branch-free program would return
 the same answer for everyone; conditionals make software smart enough to
 react differently to different inputs.

🧠 HOW TO SOLVE:
 Decide the check order FIRST. Always validate input (negative/out-of-range
 must be rejected before business logic). Use if/else-if for ranges, switch
 for exact menu values, and always place edge cases FIRST where needed.

 5 TASKS (EASY → HARD):

 ═══════════════════════════════════════════════
 TASK 1: LARGEST OF THREE NUMBERS
 ═══════════════════════════════════════════════
 Statement:
   Read 3 integers. Print the largest. Use if / else if / else
   (no ternary). Handle all-equal case too.

 💡 HINT:
   Compare a>b and a>c first; then b>c; else fallback. Print the result.
   Ties: if all equal, "All three are equal".

 // TODO: Read a, b, c
 // TODO: if (a>=b && a>=c) largest=a; else if (b>=c) largest=b; else largest=c
 // TODO: Print largest (mention ties if equal)

 ═══════════════════════════════════════════════
 TASK 2: LEAP YEAR CHECKER
 ═══════════════════════════════════════════════
 Statement:
   Year is leap if: divisible by 400 → leap; divisible by 100 → not;
   divisible by 4 → leap; else not.

 💡 HINT:
   leap = (year%400==0) || (year%100!=0 && year%4==0);
   Edge case: year <= 0 invalid.

 // TODO: Read year
 // TODO: Validate year > 0
 // TODO: Compute leap using the combined condition
 // TODO: Print result

 ═══════════════════════════════════════════════
 TASK 3: ELECTRICITY BILL CALCULATOR
 ═══════════════════════════════════════════════
 Statement:
   Slabs: first 50 units @ Rs 3/unit, next 100 units @ Rs 5/unit,
   beyond 150 @ Rs 7/unit. Read units, print bill.

 💡 HINT:
   If units <= 50: bill = u*3.
   else if units <= 150: bill = 50*3 + (u-50)*5.
   else: bill = 50*3 + 100*5 + (u-150)*7.
   Edge case: negative units → error.

 // TODO: Read units, validate >= 0
 // TODO: Apply slab conditions in order
 // TODO: Print bill

 ═══════════════════════════════════════════════
 TASK 4: CALCULATOR — SWITCH VERSION
 ═══════════════════════════════════════════════
 Statement:
   Read two numbers and an operator (+, -, *, /). Use switch to
   compute the result. Guard division by zero.

 💡 HINT:
   char op; switch(op) { case '+': ... }
   Edge case: '/' with b==0 → error message, do NOT divide.

 // TODO: Read a, b, op
 // TODO: switch(op) with cases + - * /
 // TODO: default: invalid operator message
 // TODO: inside '/' case: if b==0 print error else divide

 ═══════════════════════════════════════════════
 TASK 5: TRIANGLE VALIDATOR
 ═══════════════════════════════════════════════
 Statement:
   Read 3 sides. Validate: all positive. Then check:
   (a + b > c) && (b + c > a) && (c + a > b) → VALID triangle.
   Also classify: equilateral, isosceles, scalene.

 💡 HINT:
   Validate sides > 0 first. Then triangle inequality.
   Classification: a==b && b==c → equilateral;
   a==b || b==c || a==c → isosceles; else scalene.

 // TODO: Read a, b, c
 // TODO: Reject if any <= 0
 // TODO: Check triangle inequality → valid?
 // TODO: Classify shape with nested if

═══════════════════════════════════════════════
*/

// ==================== SOLUTIONS ====================
#include <iostream>
using namespace std;

// -------- TASK 1: Largest of Three --------
void task1_largest_of_three() {
    cout << "===== TASK 1: Largest of Three =====" << endl;

    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    if (a >= b && a >= c) {
        cout << "Largest = " << a << endl;
    } else if (b >= c) {
        cout << "Largest = " << b << endl;
    } else {
        cout << "Largest = " << c << endl;
    }

    // tie case
    if (a == b && b == c) {
        cout << "All three are equal!" << endl;
    }
    cout << endl;
}

// -------- TASK 2: Leap Year --------
void task2_leap_year() {
    cout << "===== TASK 2: Leap Year =====" << endl;

    int year;
    cout << "Enter year: ";
    cin >> year;

    if (year <= 0) {
        cout << "Invalid year!" << endl;
    } else {
        // classical rule with logical operators
        bool leap = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);

        if (leap)
            cout << year << " is a LEAP year (366 days)" << endl;
        else
            cout << year << " is NOT a leap year (365 days)" << endl;
    }
    cout << endl;
}

// -------- TASK 3: Electricity Bill --------
void task3_electricity_bill() {
    cout << "===== TASK 3: Electricity Bill =====" << endl;

    int units;
    double bill = 0;

    cout << "Enter units consumed: ";
    cin >> units;

    if (units < 0) {
        cout << "Invalid units! Cannot be negative." << endl;
    } else if (units <= 50) {
        bill = units * 3.0;
    } else if (units <= 150) {
        bill = 50 * 3.0 + (units - 50) * 5.0;
    } else {
        bill = 50 * 3.0 + 100 * 5.0 + (units - 150) * 7.0;
    }

    cout << "Units = " << units << " → Bill = Rs " << bill << endl;
    cout << endl;
}

// -------- TASK 4: Calculator with Switch --------
void task4_switch_calculator() {
    cout << "===== TASK 4: Calculator (Switch) =====" << endl;

    double a, b;
    char op;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Enter operator (+ - * /): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case '/':
            if (b == 0) {
                cout << "ERROR: Division by zero!" << endl;
            } else {
                cout << a << " / " << b << " = " << (a / b) << endl;
            }
            break;
        default:
            cout << "Invalid operator! Use +, -, *, /" << endl;
            break;
    }
    cout << endl;
}

// -------- TASK 5: Triangle Validator --------
void task5_triangle_validator() {
    cout << "===== TASK 5: Triangle Validator =====" << endl;

    double a, b, c;
    cout << "Enter three sides: ";
    cin >> a >> b >> c;

    // pehli validation — sides must be positive
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Invalid: sides must be positive!" << endl;
    } else {
        // triangle inequality — teeno conditions zaroori
        bool valid = (a + b > c) && (b + c > a) && (c + a > b);

        if (!valid) {
            cout << "NOT a valid triangle (sides violate triangle inequality)"
                 << endl;
        } else {
            cout << "VALID triangle" << endl;

            // classification with nested if
            if (a == b && b == c) {
                cout << "Type: EQUILATERAL (all sides equal)" << endl;
            } else if (a == b || b == c || a == c) {
                cout << "Type: ISOSCELES (two sides equal)" << endl;
            } else {
                cout << "Type: SCALENE (all sides different)" << endl;
            }
        }
    }
    cout << endl;
}

int main() {
    task1_largest_of_three();
    task2_leap_year();
    task3_electricity_bill();
    task4_switch_calculator();
    task5_triangle_validator();

    cout << "All tasks completed!" << endl;
    return 0;
}