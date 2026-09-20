/*
═══════════════════════════════════════════════
 CONDITIONAL STATEMENTS (if, else if, else, switch)
 ⏱️ TIME COMPLEXITY: O(1) — exactly one branch is executed.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Picture a road traffic light system. The signal checks road conditions
 one by one: if there's an emergency vehicle → open lane; else if rush
 hour → adjust timings; else → normal cycle. The same pattern drives a
 school's grading software: if marks ≥ 90 → 'A', else if ≥ 80 → 'B',
 and so on. Decision-making lets programs behave DIFFERENTLY for each
 situation — without conditionals every user would get identical output,
 making software useless in the real world.

 📖 THEORY: (pure English, beginner-level)

 1) if — checks ONE condition.
    if (condition) { run these lines if TRUE }
    - Condition must evaluate to bool (or an int: 0=false, non-zero=true).

 2) if / else — two-way decision.
    Do X when condition true, else do Y. ALWAYS exactly one runs.

 3) if / else if / else — MULTI-way decision chain.
    - Checked TOP to BOTTOM.
    - FIRST matching condition wins — the REST are ignored.
    - Order of conditions matters for edge cases!

 4) NESTED if — an if inside another if.
    if (a > 0) { if (a % 2 == 0) { ... } }
    - Useful for layered validation (is number positive? is it even?).

 5) switch — JUMP TABLE alternative to long if-else chains.
    switch (expression) {
      case value1: ...; break;   // exact match
      case value2: ...; break;
      default: ...;              // no match
    }
    - Compares ONLY for == equality against constants (int/char/enum).
    - CanNOT compare ranges like (marks >= 90).
    - WITHOUT break: control FALLS THROUGH to the next case (often bug!).

 6) ASCII FLOWCHART — if / else if / else:
    ┌─────────────────┐
    │      Start      │
    └────────┬────────┘
             ▼
    ┌──────────────┐   true   ┌──────────────┐
    │ marks >= 90? ├─────────►│ Grade = 'A'  │
    └──────┬───────┘          └──────────────┘
        false│                         ▼
             ▼                    ┌────────┐
    ┌──────────────┐   true   ┌──►│  End   │
    │ marks >= 80? ├─────────►│ A └────────┘
    └──────┬───────┘          │
        false│                │
             ▼                │
    ┌──────────────┐   true   │   ┌────────────────┐
    │ marks >= 70? ├─────────►└──►│ Grade = 'C'    │
    └──────┬───────┘             └────────────────┘
        false│
             ▼
    ┌──────────────┐
    │ Grade = 'F'  │
    └──────────────┘

 7) ASCII FLOWCHART — switch:
    ┌───────────────────────┐
    │  switch (choice)      │
    └───────────┬───────────┘
                ▼
    ┌──────────────┬──────────────┬──────────────┬──────────────┐
    ▼              ▼              ▼              ▼
  case 1        case 2        case 3        default
  chai          coffee        juice         invalid
    │              │              │              │
    ▼              ▼              ▼              ▼
  break         break         break         (end)
   │              │              │              │
   └──────► All paths MERGE at end (exit switch)

 8) WHEN TO USE:
    - if-else       → ranges, conditions mixing && ||, general logic
    - switch        → menu selections, exact known values, day-of-week
    - nested if     → multi-layer validation (inputs ki safety check)

 🧠 LOGIC — STEP BY STEP: (demo program)

 Step 1: Read marks from user.
   WHY: Marks are the input that drives all branches.

 Step 2: Validate marks are in range [0, 100].
   WHY: Edge case! Negative marks or >100 are impossible — must reject
   early, otherwise grade logic gives WRONG answers.

 Step 3: Use if/else-if chain for grade A-F.
   WHY: Grade bands are ranges (90-100, 80-89...) — switch can't do ranges.

 Step 4: Separate even/odd demo with nested if (positive + even check).
   WHY: Shows layered validation.

 Step 5: switch on a menu choice.
   WHY: Exactly the case where switch shines.

 Step 6: Demonstrate fall-through (deliberate, with comment) as edge case.
   WHY: Beginners must understand what 'break' protects against.

 VISUAL WALKTHROUGH (marks = 82):
   marks=82: is 82>=90? NO → next
              is 82>=80? YES → grade='B'  ← stops here, rest skipped

 VISUAL WALKTHROUGH (marks = -5):
   marks=-5: validate: -5 < 0 → "Invalid marks" → program returns early.
   (without validation, grade 'F' is awarded — which is wrong)

 DRY RUN (demo: marks=82, num=8, choice=2):
   82 → 'B' (82>=90 false, 82>=80 true)
   8  → positive, 8%2==0 → even positive
   2  → case 2 → "Coffee selected"

 TIME COMPLEXITY CALCULATION:
 - A chain of if/else-if checks conditions top-down; in the WORST case
   the input matches the last branch, so K conditions are evaluated
   where K is the number of branches (a small constant, ≤ 5 here).
 - All checks are O(1) comparisons.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - Only marks, num, choice, grade variables are stored — fixed set.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌────────────────────┬───────────────────────┬───────────────────────────┐
 │ Aspect             │ if / else if chain   │ switch                    │
 ├────────────────────┼───────────────────────┼───────────────────────────┤
 │ Compare ranges?    │ YES (marks >= 90)    │ NO (only == exact values) │
 │ Condition types    │ any bool expression  │ int/char/enum constants   │
 │ Readability        │ verbose for 10+ cases│ compact jump-table        │
 │ Fall-through       │ N/A                  │ must remember 'break'     │
 │ Compiler opt       │ O(n) worst check     │ O(1) jump table possible  │
 └────────────────────┴───────────────────────┴───────────────────────────┘
*/

#include <iostream>
using namespace std;

int main() {
    cout << "========== CONDITIONAL STATEMENTS DEMO ==========" << endl;

    // -------- 1. GRADE CALCULATOR WITH VALIDATION --------
    cout << "\n--- 1. Grade Calculator (if / else if / else) ---" << endl;
    int marks;
    cout << "Enter marks (0-100): ";
    cin >> marks;

    char grade;
    if (marks < 0 || marks > 100) {
        cout << "INVALID marks! Must be between 0 and 100." << endl;
        grade = '?';   // invalid state
    } else if (marks >= 90) {
        grade = 'A';
    } else if (marks >= 80) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'C';
    } else if (marks >= 60) {
        grade = 'D';
    } else if (marks >= 33) {
        grade = 'E';
    } else {
        grade = 'F';   // fail
    }

    if (grade != '?') {
        cout << "Marks = " << marks << " → Grade = " << grade << endl;
    }

    // edge case batao — 100 and 0 dono extreme ko test karo
    cout << "(edge) marks=100 → ";
    char g100 = (100 >= 90) ? 'A' : '?';
    cout << "Grade " << g100 << endl;

    // -------- 2. EVEN/ODD WITH NESTED if --------
    cout << "\n--- 2. Even/Odd with Nested if ---" << endl;
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    // layered: pehle positive check, phir even check
    if (num > 0) {
        if (num % 2 == 0) {
            cout << num << " is a POSITIVE EVEN number" << endl;
        } else {
            cout << num << " is a POSITIVE ODD number" << endl;
        }
    } else if (num < 0) {
        cout << num << " is NEGATIVE" << endl;
    } else {
        cout << num << " is ZERO (neither positive nor negative)" << endl;
    }

    // -------- 3. SWITCH — MENU SELECTION --------
    cout << "\n--- 3. Switch — Drink Menu ---" << endl;
    cout << "1. Chai   2. Coffee   3. Juice   4. Water" << endl;
    cout << "Enter your choice (1-4): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You selected Chai ☕" << endl;
            break;   // break na lagaya to fall-through hota! edge case
        case 2:
            cout << "You selected Coffee " << endl;
            break;
        case 3:
            cout << "You selected Juice" << endl;
            break;
        case 4:
            cout << "You selected Water" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter 1-4." << endl;
            break;
    }

    // -------- 4. FALL-THROUGH DEMO (edge case) --------
    cout << "\n--- 4. Fall-Through (remember your break!) ---" << endl;
    int day = 6;
    // break ka use WITHOUT — deliberate to show behavior
    switch (day) {
        case 6:
            cout << "It's Saturday";
        case 7:
            cout << " — weekend!" << endl;
            break;          // sirf yahan break; pehle case me nahi
        default:
            cout << "weekday" << endl;
    }
    cout << "See? case 6 'fell through' into case 7 and printed both."
         << endl;

    // -------- 5. TERNARY AS CONDITIONAL --------
    cout << "\n--- 5. Ternary (compact if-else) ---" << endl;
    int age = 20;
    cout << "age = " << age << " → "
         << (age >= 18 ? "Adult" : "Minor") << endl;

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}