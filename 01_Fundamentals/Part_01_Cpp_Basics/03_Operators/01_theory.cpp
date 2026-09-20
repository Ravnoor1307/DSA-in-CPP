/*
═══════════════════════════════════════════════
 OPERATORS
 ⏱️ TIME COMPLEXITY: O(1) — each operator takes constant CPU time.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a supermarket billing machine. It must add up the prices of
 items (+), decide if a bill exceeds the discount threshold (>), check
 if a customer is eligible for BOTH a student discount AND a festival
 offer (&&), and update the running total every time a new item is
 scanned (+=). The machine also counts items — sometimes it needs the
 count BEFORE showing it on screen (prefix) and sometimes AFTER (postfix).
 Operators are the grammar of all such decisions and calculations.

 📖 THEORY: (pure English, beginner-level)

 1) ARITHMETIC OPERATORS: + - * / %
    - / on integers performs INTEGER division (9/2 = 4, remainder dropped).
    - % (modulus) gives the REMAINDER: 9 % 2 = 1.
    - 10 % 3 = 1, 10 % 2 = 0 (even number), 15 % 2 = 1 (odd number).
    - Division by zero is an ERROR — always guard against it (edge case!).

 2) RELATIONAL OPERATORS: < > <= >= == !=
    - Result is a bool (true/false).
    - == compares, = assigns — MIXING THEM IS THE NUMBER 1 BUG!

 3) LOGICAL OPERATORS: && (AND), || (OR), ! (NOT)
    - AND is true only if BOTH are true.
    - OR is true if AT LEAST ONE is true.
    - NOT flips true→false.
    - SHORT-CIRCUIT: in a && b, if a is false, b is NEVER evaluated.
      In a || b, if a is true, b is NEVER evaluated.

 4) ASSIGNMENT OPERATORS: = += -= *= /= %=
    - x += 5  means x = x + 5  (faster to type, same result).
    - Each updates the variable IN PLACE.

 5) INCREMENT/DECREMENT: ++ and --
    PREFIX (++i): increment FIRST, then use the NEW value.
    POSTFIX (i++): use the CURRENT value FIRST, then increment.
    THE DIFFERENCE IS THE ENTIRE POINT — see diagram below.

 6) TERNARY OPERATOR:  condition ? value_if_true : value_if_false
    - A compact if-else that RETURNS a value.
    - int max = (a > b) ? a : b;

 7) OPERATOR PRECEDENCE LADDER (HIGH to LOW):
    ┌─────────────────────────────────────────────┐
    │  () []        → parentheses, brackets      │
    │  ++ -- ! unary→ prefix inc/dec, NOT       │
    │  * / %        → multiplication, division   │
    │  + -          → addition, subtraction      │
    │  < <= > >=    → relational                 │
    │  == !=        → equality                   │
    │  &&           → logical AND                │
    │  ||           → logical OR                 │
    │  ?:           → ternary                    │
    │  = += -= ...  → assignment (lowest)        │
    └─────────────────────────────────────────────┘
    HIGHER = evaluated FIRST.

 8) PREFIX vs POSTFIX — ASCII DIAGRAM:
    int i = 5;

    PREFIX:  x = ++i;
    ┌───────────────────────────────────────────┐
    │ Step 1: i becomes 6   (i = 5 + 1)         │
    │ Step 2: x gets 6      (new value)         │
    │ Result: i = 6, x = 6                      │
    └───────────────────────────────────────────┘

    POSTFIX: y = i++;
    ┌───────────────────────────────────────────┐
    │ Step 1: y gets 5      (CURRENT value)     │
    │ Step 2: i becomes 6   (then increment)    │
    │ Result: i = 6, y = 5                      │
    └───────────────────────────────────────────┘

    THE KEY: peg New value vs Old value — whatever comes out differently is the difference.

 🧠 LOGIC — STEP BY STEP: (demo program)

 Step 1: Perform basic arithmetic (+, -, *, /, %) on two numbers.
   WHY: Shows calculation mechanics including integer division quirk.

 Step 2: Demo % operator for even/odd and divisibility.
   WHY: This is the classic real-world use of modulus.

 Step 3: Relational + logical operators evaluate to true/false.
   WHY: Conditions in if statements depend on these results.

 Step 4: Compound assignment (+=, -=, *=, /=, %=) updates in place.
   WHY: The supermarket billing example — running totals.

 Step 5: Prefix vs postfix side-by-side.
   WHY: The most misunderstood concept; must see both output values.

 Step 6: Ternary operator.
   WHY: Compact replacement for small if-else.

 Step 7: Edge cases — division by zero guard, short-circuit display.
   WHY: Real programs MUST handle these safely.

 VISUAL WALKTHROUGH:

 Division:
   17 / 5 = 3     (17 ka quotient — remainder discard)
   17 % 5 = 2     (17 ka remainder)
   Check: 5 * 3 + 2 = 17 ✔  (quotient*divisor + remainder = dividend)

 Compound assignment on running_total:
   int bill = 0;
   bill += 100;   → 100
   bill += 50;    → 150
   bill -= 20;    → 130
   bill *= 2;     → 260

 DRY RUN (a=17, b=5):
   a + b = 22, a - b = 12, a * b = 85
   a / b = 3  (integer division — remainder dropped)
   a % b = 2  (remainder)
   17 is ODD  (17 % 2 == 1)
   (a > b) → true;  (a == b) → false

 TIME COMPLEXITY CALCULATION:
 - Each arithmetic/relational/logical/assignment operator executes in a
   single CPU instruction — constant time, independent of input size.
 - We perform a fixed number (~30) of such operations in the demo.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - We declare roughly 8-10 primitive variables (int, bool) — each O(1).
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌───────────────────┬──────────────────────────┬────────────────────────────┐
 │ Aspect            │ Prefix (++i)            │ Postfix (i++)              │
 ├───────────────────┼──────────────────────────┼────────────────────────────┤
 │ When updated      │ Before use              │ After use                  │
 │ Expression value  │ NEW value               │ OLD value                  │
 │ Typical use       │ When you need new value │ Loop counters (classic)    │
 │ Overhead (objects)│ No copy made            │ May create temporary copy  │
 └───────────────────┴──────────────────────────┴────────────────────────────┘
*/

#include <iostream>
using namespace std;

int main() {
    cout << "========== OPERATORS DEMO ==========" << endl;

    // -------- 1. ARITHMETIC OPERATORS --------
    cout << "\n--- 1. Arithmetic (+, -, *, /, %) ---" << endl;
    int a = 17, b = 5;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << "   (integer division! remainder dropped)" << endl;
    cout << "a % b = " << (a % b) << "   (remainder)" << endl;
    cout << "Check  : " << b << " * " << (a / b) << " + " << (a % b) << " = "
         << 5 * 3 + 2 << " == a ✔" << endl;

    // -------- 2. % FOR EVEN/ODD (real-world usage) --------
    int num = 7;
    cout << "\n--- 2. Modulus for Even/Odd ---" << endl;
    cout << num << " % 2 = " << (num % 2) << " → " << num << " is " 
         << ((num % 2 == 0) ? "EVEN" : "ODD") << endl;
    num = 10;
    cout << num << " % 2 = " << (num % 2) << " → " << num << " is "
         << ((num % 2 == 0) ? "EVEN" : "ODD") << endl;

    // -------- 3. DIVISION BY ZERO GUARD (edge case) --------
    cout << "\n--- 3. Division by Zero Guard ---" << endl;
    int divisor = 0;
    if (divisor == 0) {
        cout << "Cannot divide by zero — 16/0 would CRASH the program!" << endl;
    } else {
        cout << "16 / " << divisor << " = " << (16 / divisor) << endl;
    }

    // -------- 4. RELATIONAL OPERATORS --------
    cout << "\n--- 4. Relational (<, >, <=, >=, ==, !=) ---" << endl;
    int x1 = 10, x2 = 20;
    cout << "x1=" << x1 << ", x2=" << x2 << endl;
    cout << "x1 <  x2 : " << (x1 < x2) << "  (true=1, false=0)" << endl;
    cout << "x1 >  x2 : " << (x1 > x2) << endl;
    cout << "x1 == x2 : " << (x1 == x2) << endl;
    cout << "x1 != x2 : " << (x1 != x2) << endl;
    cout << "check: == compares; = assigns — inhe kabhi mix mat karo!" << endl;

    // -------- 5. LOGICAL OPERATORS --------
    cout << "\n--- 5. Logical (&&, ||, !) ---" << endl;
    bool sunny = true;
    bool holiday = false;
    cout << "sunny=" << sunny << ", holiday=" << holiday << endl;
    cout << "sunny && holiday : " << (sunny && holiday) << "  (AND: both true)" << endl;
    cout << "sunny || holiday : " << (sunny || holiday) << "  (OR: any true)" << endl;
    cout << "!sunny           : " << (!sunny) << "  (NOT flips)" << endl;

    // -------- 6. SHORT-CIRCUIT DEMO (edge case) --------
    cout << "\n--- 6. Short-Circuit Evaluation ---" << endl;
    int zero = 0;
    // 2nd condition kabhi evaluate nahi hogi kyunki 1st already false
    bool sc = (zero != 0) && (10 / zero > 1);
    cout << "(zero!=0) && (10/zero>1) = " << sc 
         << "  ← safe; 2nd part never ran (no crash!)" << endl;

    // -------- 7. COMPOUND ASSIGNMENT --------
    cout << "\n--- 7. Compound Assignment (+=, -=, *=, /=, %=) ---" << endl;
    int bill = 0;
    bill += 100;   cout << "bill += 100 → " << bill << endl;
    bill += 50;    cout << "bill += 50  → " << bill << endl;
    bill -= 20;    cout << "bill -= 20  → " << bill << endl;
    bill *= 2;     cout << "bill *= 2   → " << bill << endl;
    bill %= 3;     cout << "bill %= 3   → " << bill << endl;

    // -------- 8. PREFIX vs POSTFIX --------
    cout << "\n--- 8. Prefix (++i) vs Postfix (i++) ---" << endl;
    int i = 5;
    int pref = ++i;   // i pehle badhta hai, phir pref me new value jati hai
    cout << "i = 5;  pref = ++i;  → pref = " << pref << ", i = " << i << endl;

    i = 5;
    int postf = i++;  // i pehle de diya, phir badhta hai
    cout << "i = 5;  postf = i++; → postf = " << postf << ", i = " << i << endl;

    // -------- 9. TERNARY OPERATOR --------
    cout << "\n--- 9. Ternary (condition ? a : b) ---" << endl;
    int m1 = 45, m2 = 78;
    int higher = (m1 > m2) ? m1 : m2;
    cout << "max(" << m1 << ", " << m2 << ") = " << higher << endl;
    cout << (m1 > m2 ? "m1 greater" : "m2 greater") << endl;

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}