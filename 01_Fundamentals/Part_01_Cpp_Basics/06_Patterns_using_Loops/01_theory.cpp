/*
═══════════════════════════════════════════════
 PATTERNS USING LOOPS (Nested Loops)
 ⏱️ TIME COMPLEXITY: n rows, total inner-loop executions = Σ i (i=1..n) = n(n+1)/2 → O(n²)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A game developer renders a triangle-shaped health bar on screen, row by row.
 A shop prints a pyramid-shaped barcode design across a receipt. A wedding
 planner arranges chairs: row 1 gets 1 chair, row 2 gets 2 chairs, and so on —
 building the triangle one row at a time. Every one of these is a NESTED LOOP:
 an outer loop that picks the row, and an inner loop that fills that row with
 characters.

 📖 THEORY: (pure English, beginner-level)
 - A PATTERN is any arrangement of characters (stars, numbers, letters) printed
   row after row.
 - NESTED LOOPS = a loop inside a loop. The OUTER loop controls ROWS; the INNER
   loop controls the characters in the current row.
 - Right triangle (n rows): row i (1-based) prints exactly i stars.
 - Pyramid (n rows): row i prints (n - i) spaces first, then (2*i - 1) stars.
 - Diamond: a pyramid on top + an inverted pyramid below (widest row NOT repeated).
 - NUMBER PATTERNS: the inner loop prints numbers instead of stars — either the
   row number i or the counting number j, depending on the pattern.
 - KEY INSIGHT: the total number of inner-loop runs = the total work done =
   the big-O complexity of the whole pattern.

  ASCII — right triangle (n = 4):
   *
   * *
   * * *
   * * * *

  ASCII — pyramid (n = 4):
        *
       * *
      * * *
     * * * *

  ASCII — diamond (n = 4):
       *
      * *
     * * *
    * * * *
     * * *
      * *
       *

 WHEN TO USE:
 - Printing grids & boards (chessboards, tile maps, seating charts, ASCII art).
 - Practising loop counters — patterns are the fastest way to build loop intuition.
 - Generating 2-D text graphics inside console tools.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Outer loop walks rows: for (int i = 1; i <= n; i++).
        WHY: one outer iteration = exactly one printed row.
 Step 2: Inner loop prints the right COUNT of characters for that row.
        WHY: the count is a function of i (e.g. i stars for a right triangle).
 Step 3: For centered shapes print spaces first, then the characters.
        WHY: spaces are just "positioning" characters printed by their own loop.
 Step 4: End every row with a newline (endl).
        WHY: without it every row would squash onto one single line.

 VISUAL WALKTHROUGH: (right triangle, n = 4)
  i=1 → 1 star            → *
  i=2 → 2 stars           → * *
  i=3 → 3 stars           → * * *
  i=4 → 4 stars           → * * * *

 DRY RUN: (right triangle, n = 3)
  printRightTriangle(3)
  i=1: j=1 → prints "*", then newline        → line 1 = "*"
  i=2: j=1,2 → prints "*" "*", newline       → line 2 = "* *"
  i=3: j=1,2,3 → prints "*" "*" "*", newline → line 3 = "* * *"

  Final output:
  *
  * *
  * * *

 TIME COMPLEXITY CALCULATION:
 - Outer loop runs exactly n times (one per row).
 - Inner loop for row i executes exactly i times.
 - Total inner-body executions = 1 + 2 + 3 + ... + n = n(n+1)/2.
 - n(n+1)/2 = (n² + n)/2 → for large n the n² term dominates.
 → Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - We use only a few integer counters (i, j, s). No memory grows with n.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────┬──────────────────────┬──────────────────────────┐
 │ Aspect           │ Nested-loop printing │ Per-row string building  │
 ├──────────────────┼──────────────────────┼──────────────────────────┤
 │ How it works     │ characters printed   │ row built as string then │
 │                  │ one by one directly  │ printed as a single unit │
 │ Time             │ O(n²) characters     │ O(n²) characters built   │
 │ Space            │ O(1)                 │ O(n) if row kept, O(n²)  │
 │                  │                      │ if all rows are stored   │
 │ Clarity          │ textbook classic     │ handy for centering /    │
 │                  │                      │ reusing whole rows       │
 └──────────────────┴──────────────────────┴──────────────────────────┘
*/
#include <iostream>
using namespace std;

// Right triangle: row i pe exactly i stars. Outer = rows, inner = chars.
void printRightTriangle(int n) {
    for (int i = 1; i <= n; i++) {        // har i ek row hai
        for (int j = 1; j <= i; j++) {    // is row me i stars chahiye
            cout << "* ";
        }
        cout << endl;                     // row khatam -> newline
    }
}

// Pyramid: pehle (n-i) do-space slots (alignment), phir (2i-1) stars.
void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) cout << "  ";   // spaces = position
        for (int j = 1; j <= 2 * i - 1; j++) cout << "* ";
        cout << endl;
    }
}

// Diamond = top pyramid + bottom inverted pyramid (widest row ek baar hi).
void printDiamond(int n) {
    // top half (pyramid)
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
    // bottom half (ulta pyramid, i = n-1 se 1 tak)
    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

// Number pattern: row i me number i, exactly i baar repeat.
void printNumberTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";             // row number print karo, j nahi
        }
        cout << endl;
    }
}

int main() {
    cout << "=== Right Triangle (n=4) ===" << endl;
    printRightTriangle(4);

    cout << "\n=== Pyramid (n=4) ===" << endl;
    printPyramid(4);

    cout << "\n=== Diamond (n=4) ===" << endl;
    printDiamond(4);

    cout << "\n=== Number Triangle (n=5) ===" << endl;
    printNumberTriangle(5);

    // EDGE CASES: n=0 (koi row nahi) aur n=1 (sirf ek star)
    cout << "\n=== EDGE CASE: n = 0 (right triangle) ===" << endl;
    printRightTriangle(0);                // loop 0 baar chalta hai -> blank
    cout << "(upar blank hona BILKUL correct hai)" << endl;

    cout << "\n=== EDGE CASE: n = 1 (diamond) ===" << endl;
    printDiamond(1);                      // sirf ek star, top+bottom khaali

    cout << "\n=== EDGE CASE: n = 1 (number triangle) ===" << endl;
    printNumberTriangle(1);               // sirf "1"

    return 0;
}