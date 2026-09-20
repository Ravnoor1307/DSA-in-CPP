/*
═══════════════════════════════════════════════
 TASK SET — PATTERNS USING LOOPS
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
  A game's health-bar, a wedding seating chart, or a console tile map — all of
  them are printed in rows & columns. Every pattern is just a game of nested
  loops: the outer loop picks the row, the inner loop fills the row.

 🧠 HOW TO SOLVE:
  First write the pattern down on paper. Count how many spaces and how many
  characters each row has. Write that count as a function of i (the row
  number), then translate it into loops. Outer loop = rows, inner loop =
  filling of the current row.

  MODES/TOPICS COVERED:
   1. Right-aligned right triangle (spaces + stars)
   2. Inverted right triangle (reverse outer loop)
   3. Number pyramid, center aligned (two inner loops)
   4. Diamond (pyramid + inverted pyramid)
   5. Number triangle (print the row number i)
   6. Alphabet pattern (char arithmetic 'A' + j - 1)
   7. Hollow triangle (boundary-only stars)

  ═══════════════════════════════════════════════
   TASK 1 (EASY) — Right-aligned right triangle
   n rows; row i has (n - i) spaces, then i stars.
   n=4:
         *
        **
       ***
      ****
   💡 HINT: First print (n - i) spaces, then i stars.
   ✏️ STARTER CODE (description): function printRightAligned(int n); outer loop
       i=1..n; inside, first loop s=1..(n-i) prints " ", second loop j=1..i
       prints "*".

   TASK 2 (EASY) — Inverted right triangle
   n=4:
      ****
      ***
      **
      *
   💡 HINT: Row i has (n - i + 1) stars — just run the outer loop in reverse.
   ✏️ STARTER CODE (description): outer loop i = n down to 1 (reverse); inner
       loop j=1..i prints "*".

   TASK 3 (MEDIUM) — Number pyramid (center aligned)
   n=4:
          1
        1 2
      1 2 3
    1 2 3 4
   💡 HINT: first (n - i) two-char space slots, then numbers j=1..i.
   ✏️ STARTER CODE (description): two inner loops — the first prints "  "
       (n-i times), the second prints "cout << j << ' '" (j=1..i).

   TASK 4 (MEDIUM) — Diamond
   n=4:
        *
       * *
      * * *
     * * * *
      * * *
       * *
        *
   💡 HINT: Top = pyramid (i=1..n), bottom = inverted pyramid (i=n-1 down to 1).
   ✏️ STARTER CODE (description): first loop i=1..n: (n-i) spaces + (2i-1) stars.
       Second loop i=n-1..1: same logic in reverse.

   TASK 5 (MEDIUM) — Number triangle (row number repeat)
   n=4:
      1
      2 2
      3 3 3
      4 4 4 4
   💡 HINT: The inner loop runs i times, but print i (the row number).
   ✏️ STARTER CODE (description): outer i=1..n; inner j=1..i; inside use
       "cout << i" (do not print j).

   TASK 6 (HARD) — Alphabet pattern
   n=4:
      A
      A B
      A B C
      A B C D
   💡 HINT: char c = 'A' + (j - 1); — characters are also numbers.
   ✏️ STARTER CODE (description): outer i=1..n; inner j=1..i; print
       char('A' + j - 1) with a space after each.

   TASK 7 (HARD) — Hollow triangle
   n=6:
      *
      * *
      *   *
      *     *
      *       *
      * * * * * *
   💡 HINT: Print a star only when j==1, j==i, or i==n; elsewhere print two spaces.
   ✏️ STARTER CODE: // void hollowTriangle(int n) {
       //   for (int i = 1; i <= n; i++) {
       //     for (int j = 1; j <= i; j++) {
       //       if (j == 1 || j == i || i == n) cout << "*";
       //       else cout << "  ";
       //     }
       //     cout << endl;
       //   }
       // }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// SOLUTION 1 — right-aligned triangle (spaces pehle, stars baad)
void printRightAligned(int n) {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) cout << " ";   // (n-i) spaces
        for (int j = 1; j <= i; j++) cout << "*";       // i stars
        cout << endl;
    }
}

// SOLUTION 2 — inverted triangle (ulta outer loop)
void inverted(int n) {
    for (int i = n; i >= 1; i--) {                      // i: n, n-1, ..., 1
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }
}

// SOLUTION 3 — number pyramid, center aligned
void numberPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) cout << "  ";  // 2-char wide slots
        for (int j = 1; j <= i; j++) cout << j << " ";  // numbers 1..i
        cout << endl;
    }
}

// SOLUTION 4 — diamond (top pyramid + bottom inverted pyramid)
void diamond(int n) {
    for (int i = 1; i <= n; i++) {                      // top
        for (int s = 1; s <= n - i; s++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {                  // bottom (widest row repeat nahi)
        for (int s = 1; s <= n - i; s++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

// SOLUTION 5 — row number i, i baar repeat
void numberTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << i << " ";  // i hi print hota hai
        cout << endl;
    }
}

// SOLUTION 6 — alphabet triangle (char arithmetic)
void alphabetTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char('A' + j - 1) << " ";           // j=1 -> 'A', j=2 -> 'B'...
        }
        cout << endl;
    }
}

// SOLUTION 7 — hollow triangle (sirf boundary pe stars)
void hollowTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) cout << "*"; // boundary ya last row
            else cout << "  ";                           // andar khali
        }
        cout << endl;
    }
}

int main() {
    cout << "TASK 1 — right-aligned (n=4)\n";
    printRightAligned(4);

    cout << "\nTASK 2 — inverted (n=4)\n";
    inverted(4);

    cout << "\nTASK 3 — number pyramid (n=4)\n";
    numberPyramid(4);

    cout << "\nTASK 4 — diamond (n=4)\n";
    diamond(4);

    cout << "\nTASK 5 — number triangle (n=5)\n";
    numberTriangle(5);

    cout << "\nTASK 6 — alphabet (n=4)\n";
    alphabetTriangle(4);

    cout << "\nTASK 7 — hollow triangle (n=6)\n";
    hollowTriangle(6);

    cout << "\n===== EDGE CASES =====\n";
    cout << "n=0 inverted (kuch nahi print hona chahiye):\n";
    inverted(0);
    cout << "(upar blank correct hai)\n";
    cout << "n=1 diamond:\n";
    diamond(1);
    cout << "n=1 number pyramid:\n";
    numberPyramid(1);

    return 0;
}