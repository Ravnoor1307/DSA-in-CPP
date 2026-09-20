/*
═══════════════════════════════════════════════
 ALGORITHM
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Before a chef makes tea, he follows a fixed recipe: boil water → add tea leaves →
 wait 2 minutes → strain → add sugar → serve. Every step is clear, ordered and
 must finish. That recipe IS an algorithm. Any time you give a computer a clear
 step-by-step procedure that stops, the computer executes an algorithm — like a
 calculator computing 1+2+...+100 or your phone finding the fastest route.

 📖 THEORY: (pure English, beginner-level)
 - Definition: An algorithm is a FINITE, well-defined, ordered sequence of steps
   that takes some input, performs a task, and produces an output.
 - Five formal properties (Knuth's properties):
   1. INPUT  — zero or more values given from outside.
   2. OUTPUT — at least one value produced.
   3. FINITENESS — the steps must terminate after a finite number of them.
   4. DEFINITENESS — each step must be precise, unambiguous (no "do something").
   5. EFFECTIVENESS — every step must be basic enough to be executed (even by
      pencil and paper).
 - Note: a program is an algorithm written in a language a computer runs; an
   algorithm can be written as pseudo-code (plain English + math), flowchart,
   or real code.

 PSEUDO-CODE example — sum of first n numbers:
   Input:  n
   Output: sum of 1 + 2 + ... + n
   ALGORITHM sumLoop(n):
     1.  sum <- 0
     2.  for i = 1 to n:
     3.      sum <- sum + i
     4.  return sum

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Decide the exact inputs and outputs of the algorithm.
         WHY: property INPUT + OUTPUT must be fixed before coding.
 Step 2: Choose the method — loop (add each number) or formula.
         WHY: both are valid algorithms; formula is faster, loop is easier to
         trace step-by-step.
 Step 3: For the loop: start accumulator at 0, add i from 1 to n.
         WHY: accumulator stores the running total after each iteration.
 Step 4: For the formula: use the closed form n*(n+1)/2 derived from the sum of
         an arithmetic progression.
         WHY: it skips the loop entirely → O(1).
 Step 5: Return / print the result.
         WHY: OUTPUT property ensures the algorithm always gives an answer.

 VISUAL WALKTHROUGH:
   Flowchart for sumLoop:
   +--------+     +-----------+     +------------------+     +---------+
   | START  | --> | Input n   | --> | sum <- 0, i <- 1 | --> | i <= n? |
   +--------+     +-----------+     +------------------+     +---------+
                                                                 |  |
                                            (yes, add i)        |  v
                                        +----------------+   +---------+
                                        | sum <- sum + i |<--|  i++    |
                                        +----------------+   +---------+
                                                            (no)
                                                              |
                                                              v
                                                         +---------+
                                                         | Output  |
                                                         |   sum   |
                                                         +---------+
   1 + 2 + 3 + 4 + 5 = 15        formula: 5*6/2 = 15

   What does it mean each step:
   Step       operation            effect (n = 5)
   init       sum=0, i=1           sum=0
   iter 1     sum += 1, i=2        sum=1
   iter 2     sum += 2, i=3        sum=3
   iter 3     sum += 3, i=4        sum=6
   iter 4     sum += 4, i=5        sum=10
   iter 5     sum += 5, i=6 (6<=5 false) -> exit
   result     sum = 15

 DRY RUN: (n = 5)
   sumLoop(5):
     sum=0
     i=1 -> sum=1
     i=2 -> sum=3
     i=3 -> sum=6
     i=4 -> sum=10
     i=5 -> sum=15
     i=6 stops loop -> returns 15
   sumFormula(5) = 5*(5+1)/2 = 5*6/2 = 15   ✓ same answer

 TIME COMPLEXITY CALCULATION:
 - Loop method:
   One iteration per i from 1 to n. Each iteration does constant work (1 add +
   1 compare + 1 increment) => n iterations * O(1) each => n operations.
   → Time Complexity = O(n)
 - Formula method:
   Constant sequence: multiply (1), add (1), divide (1) => 3 operations.
   → Time Complexity = O(1)
 - Conclusion: for large n formula is far faster; loop is still simplest logic.

 SPACE COMPLEXITY CALCULATION:
 - Loop method: only the variables sum, i — 2 ints, independent of n.
   → Space Complexity = O(1)
 - Formula method: only the expression values — again constant few vars.
   → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌───────────────────┬───────────────────────────┬───────────────────────────┐
 │ Aspect            │ Loop method               │ Formula method            │
 ├───────────────────┼───────────────────────────┼───────────────────────────┤
 │ Time complexity   │ O(n)                      │ O(1)                      │
 │ Steps in code     │ easy to trace, 5+ lines   │ one expression             │
 │ Works for n       │ any n (loop runs w steps) │ needs n*(n+1)/2 in int    │
 │ Risk              │ slow for huge n           │ overflow for very large n │
 └───────────────────┴───────────────────────────┴───────────────────────────┘
*/

#include <iostream>
using namespace std;

// algorithm 1: loop — har number ko ek-ek karke add karo
int sumLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    return sum;
}

// algorithm 2: formula — direct closed form, koi loop nahi
int sumFormula(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n = 100;
    cout << "n = " << n << "\n";
    cout << "sumLoop(100)    = " << sumLoop(n) << "\n";
    cout << "sumFormula(100) = " << sumFormula(n) << "\n";

    // edge cases: n = 0 and n = 1 (dono methods agree)
    cout << "n=0 -> " << sumLoop(0) << " / " << sumFormula(0) << "\n";
    cout << "n=1 -> " << sumLoop(1) << " / " << sumFormula(1) << "\n";
    cout << "Formula uses no loop, runs in O(1); loop runs in O(n).\n";
    return 0;
}