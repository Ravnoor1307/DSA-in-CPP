/*
═══════════════════════════════════════════════
 LOOPS (for, while, do-while, break/continue)
 ⏱️ TIME COMPLEXITY: O(n) — body executes n times.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine an elevator in a 10-floor building. When you press 7 from floor 2,
 the lift visits floors 3, 4, 5, 6, 7 — ONE by ONE — and STOPS at 7.
 This is exactly a loop: repeat the same action (go up one floor) until a
 condition (current floor == target) is met. If the elevator visited
 floors BEFORE checking if it should move (like do-while), it would go
 to floor 3 FIRST, then check. The lift door never opens while moving
 (skip certain floors = continue), but if there's a fire alarm, the
 lift immediately stops its pattern and reroutes (break). Loop types
 differ only in WHEN the condition is checked, and HOW MANY times the
 body is guaranteed to run.

 📖 THEORY: (pure English, beginner-level)

 1) for LOOP — WHEN YOU KNOW THE COUNT.
    for (init; condition; update) { body; }
    ┌──────────────────────────────────────────────┐
    │ Step 1: init  → runs ONCE before loop starts │
    │ Step 2: condition → before each iteration     │
    │ Step 3: body → executes if condition true     │
    │ Step 4: update → runs AFTER each body pass    │
    │ Return to Step 2.                             │
    └──────────────────────────────────────────────┘
    Best for: counting, traversing arrays, known iterations.

 2) while LOOP — CONDITION CHECKED BEFORE BODY (pre-test loop).
    while (condition) { body; }
    - Condition checked FIRST; if false, body never runs (0 to 0 times).
    - Best for: unknown iteration count, waiting for an event.

 3) do-while LOOP — BODY RUNS ONCE, THEN condition checked (post-test).
    do { body; } while (condition);
    - The body ALWAYS runs at least ONCE, even if condition is false initially.
    - Best for: menu systems, "do you want to continue?" prompts.

 4) ASCII: PRE-TEST vs POST-TEST:
    while (condition):
    ┌─────────┐
    │ cond?   │──false──► EXIT (body runs 0 or more times)
    └────┬────┘
         │true
         ▼
    ┌─────────┐
    │  body   │
    └────┬────┘
         └──────► loop back

    do { body } while (cond):
    ┌─────────┐
    │  body   │  ← always runs at least once
    └────┬────┘
         ▼
    ┌─────────┐
    │ cond?   │──false──► EXIT
    └────┬────┘
         │true
         └──────────► loop back

 5) ITERATION TRACE (for loop, i=1 to 5, summing):
    ┌──────────┬──────┬──────────────────────────────────────┐
    │ Iteration│  i   │  sum (running total)                  │
    ├──────────┼──────┼──────────────────────────────────────┤
    │    1     │  1   │  0 + 1 = 1                           │
    │    2     │  2   │  1 + 2 = 3                           │
    │    3     │  3   │  3 + 3 = 6                           │
    │    4     │  4   │  6 + 4 = 10                          │
    │    5     │  5   │  10 + 5 = 15  ← final answer        │
    └──────────┴──────┴──────────────────────────────────────┘

 6) break — EXITS the innermost enclosing loop completely.
    Use case: searching, early termination when goal found.

 7) continue — SKIPS the rest of current iteration, jumps to next.
    Use case: skip bad data, skip a specific iteration.

 8) INFINITE LOOP — when condition never becomes false.
    while (true) { ... }   ← must have a break inside or it never stops!
    for (;;) { ... }       ← also infinite.

 9) WHEN TO USE EACH:
    ┌───────────┬──────────────────────────────────────────┐
    │ Loop      │ When                                     │
    ├───────────┼──────────────────────────────────────────┤
    │ for       │ Known count (1..n, array traversal)      │
    │ while     │ Unknown count, condition-driven          │
    │ do-while  │ Must run at least once (menu, retry)     │
    └───────────┴──────────────────────────────────────────┘

 🧠 LOGIC — STEP BY STEP:

 DEMO (a) — WHILE REVERSE A NUMBER:
   Input: 12345
   Step 1: n=12345, rev=0
   Step 2: rev = 0*10 + 12345%10 = 5       → rev=5
   Step 3: n = 12345/10 = 1234
   Step 4: rev = 5*10 + 1234%10 = 54       → rev=54
   Step 5: n = 1234/10 = 123
   ... continue until n == 0.

 DEMO (b) — FOR LOOP SUM 1..N:
   Input: n=5
   Iteration i=1: sum=0+1=1
   Iteration i=2: sum=1+2=3
   Iteration i=3: sum=3+3=6
   Iteration i=4: sum=6+4=10
   Iteration i=5: sum=10+5=15
   Final: sum = 15 = 5*6/2 = n(n+1)/2  ← formula check!

 DEMO (c) — DO-WHILE MENU:
   Always prints menu once. If user enters 5 (exit), loop ends.
   If user enters 3 (invalid option), menu reprints.

 TIME COMPLEXITY CALCULATION:
 - Demo (a): while loop runs exactly d times where d = number of digits.
   d = floor(log10(n)) + 1 ≤ 20 for long long. Each iteration does O(1)
   work → O(d) = O(log n) for the reverse demo. For fixed max-size input
   (20 digits), it's bounded → treated as O(d).
 - Demo (b): for loop runs n times. Each iteration does O(1) work.
 → Time Complexity = O(n)

 - Demo (c): do-while runs between 1 and K times depending on user
   (constant-time body). For bounded K, O(K).

 → Overarching: if loops run over n, Time = O(n) per loop.
   Demo (a) reverse: O(d) where d = digit count = O(log n)
   Demo (b) sum: O(n)
   Demo (c) menu: O(K) where K = user interactions (bounded constant).

 SPACE COMPLEXITY CALCULATION:
 - No extra data structures; only individual variables (sum, rev, n, i).
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌───────────┬────────────────────┬─────────────────────┬────────────────────┐
 │ Feature   │ for                │ while               │ do-while           │
 ├───────────┼────────────────────┼─────────────────────┼────────────────────┤
 │ Runs at   │ 0 or more times   │ 0 or more times     │ AT LEAST 1 time    │
 │ Use when  │ count is known     │ condition-driven    │ must execute once  │
 │ Init/Ctr  │ inside for(...)    │ separate lines      │ separate lines     │
 │ Menu use? │ Awkward            │ Awkward             │ IDEAL              │
 └───────────┴────────────────────┴─────────────────────┴────────────────────┘

 VISUAL WALKTHROUGH — REVERSE A NUMBER (n=12345):

 n=12345, rev=0
 ┌──────────────┬──────────┬───────────────┬──────────────┐
 │ Iteration    │ n (start)│ rev = rev*10  │ n = n/10     │
 │              │          │   + n%10      │              │
 ├──────────────┼──────────┼───────────────┼──────────────┤
 │     1        │ 12345    │ 0*10+5 = 5    │ 1234         │
 │     2        │ 1234     │ 5*10+4 = 54   │ 123          │
 │     3        │ 123      │ 54*10+3 = 543 │ 12           │
 │     4        │ 12       │ 543*10+2=5432 │ 1            │
 │     5        │ 1        │ 5432*10+1=54321│ 0 (STOP)    │
 └──────────────┴──────────┴───────────────┴──────────────┘
 Final rev = 54321 ✔
*/

#include <iostream>
using namespace std;

int main() {
    cout << "========== LOOPS DEMO ==========" << endl;

    // -------- A) WHILE LOOP — REVERSE A NUMBER --------
    cout << "\n--- A) While Loop: Reverse a Number ---" << endl;
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    // edge case: negative number bhi handle karo
    bool negative = (n < 0);
    long long num = negative ? -n : n;
    long long rev = 0;

    while (num > 0) {
        int last_digit = num % 10;      // kaat lo last digit
        rev = rev * 10 + last_digit;    // ulta jodte jao
        num = num / 10;                 // last digit hatao
        // iteration trace
        cout << "  n=" << num << ", rev=" << rev << endl;
    }

    if (negative) rev = -rev;
    cout << "Original : " << n << endl;
    cout << "Reversed : " << rev << endl;

    // -------- B) FOR LOOP — SUM 1 TO N --------
    cout << "\n--- B) For Loop: Sum 1 to N ---" << endl;
    int limit;
    cout << "Enter N: ";
    cin >> limit;

    // edge case: negative or zero input
    if (limit < 0) {
        cout << "Please enter a non-negative number." << endl;
    } else {
        long long sum = 0;
        for (int i = 1; i <= limit; i++) {
            sum += i;
        }
        cout << "Sum 1 to " << limit << " = " << sum << endl;
        cout << "Formula check: " << (long long)limit * (limit + 1) / 2
             << " (n(n+1)/2)" << endl;
    }

    // -------- C) DO-WHILE — MENU SYSTEM --------
    cout << "\n--- C) Do-While: Menu System ---" << endl;
    int choice;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Hello World" << endl;
        cout << "2. Print today's date" << endl;
        cout << "3. Calculator hint: 2+2=4" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Hello World!" << endl;
                break;
            case 2:
                cout << "Today is a great day to code!" << endl;
                break;
            case 3:
                cout << "2 + 2 = 4 (basic math!)" << endl;
                break;
            case 4:
                cout << "Exiting menu..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);   // body kam se kam ek baar chalega

    // -------- D) BREAK — EARLY EXIT --------
    cout << "\n--- D) Break: Find first number divisible by 7 after 50 ---" << endl;
    int search = 50;
    while (true) {                    // infinite loop — break se bhaagna padega!
        search++;
        if (search % 7 == 0) {
            cout << "First number > 50 divisible by 7: " << search << endl;
            break;                    // goal mila — loop se nikal lo
        }
    }

    // -------- E) CONTINUE — SKIP A SPECIFIC ITERATION --------
    cout << "\n--- E) Continue: Print odd numbers from 1 to 20 ---" << endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0)
            continue;   // even skip kar do — baaki kuch mat karo
        cout << i << " ";
    }
    cout << endl;

    // -------- F) INFINITE LOOP + BREAK (edge case) --------
    cout << "\n--- F) Infinite Loop Demo (broken after 3 iterations) ---" << endl;
    int counter = 0;
    while (true) {
        counter++;
        cout << "Iteration " << counter << endl;
        if (counter == 3) break;    // 3 ke baad band karo
    }

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}