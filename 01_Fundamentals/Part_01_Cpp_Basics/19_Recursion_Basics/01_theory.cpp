/*
═══════════════════════════════════════════════
 RECURSION BASICS — Function Calling Itself
 ⏱️ TIME COMPLEXITY: factorial O(n), fibonacci O(2^n) — derived below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a line of people in a dark cinema hall. Person 5 asks
 "which row am I in?" Person 4 doesn't know either, so asks Person 3,
 who asks Person 2, who asks Person 1. Person 1 is at the front and
 knows "I'm in row 1" — that's the BASE CASE. Now the answer travels
 BACK: Person 2 says "then I'm in row 2", Person 3 says "row 3", and
 so on until Person 5 learns "I'm in row 5." The question traveled
 FORWARD (recursion unwinding) and the answer traveled BACKWARD
 (return values propagating). This is exactly how a recursive function
 works — smaller versions of the same question are pushed onto a call
 stack until a base case is hit, then results bubble back up.

 📖 THEORY: (pure English, beginner-level)
 - Recursion: a function that calls itself, solving a smaller sub-problem
   each time until reaching a base case (stopping condition).
 - Two essential parts:
   1. BASE CASE: tells the function when to STOP. Without it → infinite
      recursion → stack overflow → crash.
   2. RECURSIVE STEP: breaks the problem into a smaller piece and calls
      itself with that smaller piece.
 - Call Stack: each recursive call adds a FRAME (local vars, return addr)
   to the stack. Frames pile up until base case, then unwind as returns.
 - Direct recursion: function A calls function A directly.
 - Indirect recursion: function A calls function B, which calls function A.
 - Stack overflow: default stack is ~8 MB. Each frame takes some bytes.
   Too many recursive calls → stack fills up → crash (SIGSEGV).
 - Fibonacci naive recursion is exponentially slow O(2^n) because of
   repeated sub-problems. Factorial is O(n) linear.

 ASCII CALL STACK — factorial(5):

   Piling (calls going deeper):          Unwinding (returns coming back):
   ┌───────────────────┐
   │ fact(5): 5 * ?    │
   ├───────────────────┤
   │ fact(4): 4 * ?    │
   ├───────────────────┤
   │ fact(3): 3 * ?    │
   ├───────────────────┤
   │ fact(2): 2 * ?    │
   ├───────────────────┤
   │ fact(1): return 1 │  ← BASE CASE
   └───────────────────┘

   Unwinding:
   fact(1) returns 1  → fact(2) = 2 * 1 = 2
   fact(2) returns 2  → fact(3) = 3 * 2 = 6
   fact(3) returns 6  → fact(4) = 4 * 6 = 24
   fact(4) returns 24 → fact(5) = 5 * 24 = 120

 RECURSION TREE — fibonacci(5):

                   fib(5)
                /          \
           fib(4)            fib(3)
          /      \           /     \
      fib(3)   fib(2)    fib(2)  fib(1)
      /  \      /   \      /  \
  fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
   /  \
 fib(1) fib(0)

 Total nodes: 15 (but only 6 unique sub-problems!)
 This is why naive fib is O(2^n) — massive redundancy.

 🧠 LOGIC — STEP BY STEP:
 Step 1: DEFINE the base case.
         WHY: tells recursion when to stop. Without it, infinite loop on stack.
 Step 2: DEFINE the recursive step (smaller sub-problem).
         WHY: guarantees progress toward the base case.
 Step 3: TRUST the recursive call returns the correct answer for the smaller input.
         WHY: the function's contract is "I will compute correctly for n-1."
              You just use that result to compute for n.
 Step 4: RETURN the combined result.
         WHY: builds the answer from bottom (base case) to top (original call).

 VISUAL WALKTHROUGH — factorial(3) with trace:

   factorial(3):
     cout << "factorial(3) called"     // TRACE
     n != 0 && n != 1 → return 3 * factorial(2)

       factorial(2):
         cout << "factorial(2) called"
         return 2 * factorial(1)

           factorial(1):
             cout << "factorial(1) called"
             n == 1 → return 1

         return 2 * 1 = 2
       return 3 * 2 = 6

 DRY RUN — fib(4):
   fib(4) calls fib(3) and fib(2)
     fib(3) calls fib(2) and fib(1)
       fib(2) calls fib(1) and fib(0) → returns 1+0=1
       fib(1) → returns 1
     fib(3) = 1+1 = 2
     fib(2) calls fib(1) and fib(0) → returns 1+0=1
   fib(4) = 2+1 = 3

 TIME COMPLEXITY CALCULATION:
 - Factorial:
     T(n) = T(n-1) + O(1)   [one recursive call + constant work]
     T(1) = O(1)
     Unrolling: T(n) = T(n-1) + c = T(n-2) + 2c = ... = T(1) + (n-1)c
     = O(1) + (n-1) × O(1) = n × O(1)
   → Time Complexity (factorial) = O(n)

 - Fibonacci (naive):
     T(n) = T(n-1) + T(n-2) + O(1)
     The recursion tree has ~2^n nodes (doubles each level).
     Level 0: 1 call, Level 1: 2 calls, Level 2: 4 calls, ...
     Total calls ≈ 1 + 2 + 4 + ... + 2^(n-1) = 2^n - 1
   → Time Complexity (fibonacci naive) = O(2^n)

 SPACE COMPLEXITY CALCULATION:
 - Factorial: max call stack depth = n (one call per level) → O(n)
 - Fibonacci: max call stack depth = n (follows fib(n)→fib(n-1)→...→fib(1))
   → O(n) stack space
 - Note: O(n) space for both despite very different time complexities.
   Space counts DEPTH of recursion, not total calls.
 → Space Complexity (factorial) = O(n)
 → Space Complexity (fibonacci) = O(n)

 APPROACH COMPARISON:
 ┌─────────────────────┬──────────────────┬──────────────────────────┐
 │ Recursion vs Loop   │ Time             │ Space                    │
 ├─────────────────────┼──────────────────┼──────────────────────────┤
 │ Factorial (recur)   │ O(n)             │ O(n) stack               │
 │ Factorial (loop)    │ O(n)             │ O(1)                     │
 │ Fibonacci (naive)   │ O(2^n)           │ O(n) stack               │
 │ Fibonacci (memo)    │ O(n)             │ O(n) stack + O(n) array  │
 │ Fibonacci (loop)    │ O(n)             │ O(1)                     │
 │ Binary search (recur)│ O(log n)        │ O(log n) stack           │
 │ Binary search (loop) │ O(log n)        │ O(1)                     │
 └─────────────────────┴──────────────────┴──────────────────────────┘
   Recursion shines for TREES, GRAPHS, BACKTRACKING, DIVIDE & CONQUER
   where the structure naturally branches.
*/

#include <iostream>
using namespace std;

// factorial with trace — har call print hota hai
long long factorial(int n) {
    cout << "  factorial(" << n << ") called" << endl;
    if (n < 0) {
        cout << "  [negative input! returning -1]" << endl;
        return -1;    // edge case: negative factorial undefined
    }
    if (n == 0 || n == 1) {
        cout << "  [base case hit! returning 1]" << endl;
        return 1;     // base case
    }
    return n * factorial(n - 1);   // recursive step
}

// fibonacci with trace — trace prints to show call tree explosion
long long fib(int n) {
    cout << "  fib(" << n << ") called" << endl;
    if (n < 0) return -1;          // edge case guard
    if (n == 0) return 0;          // base case 1
    if (n == 1) return 1;          // base case 2
    return fib(n - 1) + fib(n - 2); // two recursive calls
}

// indirect recursion example
void funcB(int n);    // forward declaration

void funcA(int n) {
    if (n <= 0) return;        // base case
    cout << "  funcA(" << n << ")" << endl;
    funcB(n - 1);              // A calls B
}

void funcB(int n) {
    if (n <= 0) return;
    cout << "  funcB(" << n << ")" << endl;
    funcA(n / 2);              // B calls A (indirect recursion)
}

int main() {

    // ═══════════════════════════════════════
    // DEMO 1: Factorial with trace
    // ═══════════════════════════════════════
    cout << "=== DEMO 1: Factorial(5) ===" << endl;
    long long result1 = factorial(5);
    cout << "  Result: factorial(5) = " << result1 << "\n" << endl;

    // ═══════════════════════════════════════
    // DEMO 2: Factorial edge case — n=0
    // ═══════════════════════════════════════
    cout << "=== DEMO 2: Factorial(0) ===" << endl;
    long long result2 = factorial(0);
    cout << "  Result: factorial(0) = " << result2 << "\n" << endl;

    // ═══════════════════════════════════════
    // DEMO 3: Factorial edge case — negative
    // ═══════════════════════════════════════
    cout << "=== DEMO 3: Factorial(-3) ===" << endl;
    long long result3 = factorial(-3);
    cout << "  Result: factorial(-3) = " << result3 << " (undefined, guarded)\n" << endl;

    // ═══════════════════════════════════════
    // DEMO 4: Fibonacci with trace (small n)
    // ═══════════════════════════════════════
    cout << "=== DEMO 4: Fibonacci(5) with trace ===" << endl;
    long long result4 = fib(5);
    cout << "  Result: fib(5) = " << result4 << "\n" << endl;

    // ═══════════════════════════════════════
    // DEMO 5: Fibonacci edge case — negative
    // ═══════════════════════════════════════
    cout << "=== DEMO 5: Fibonacci(-1) ===" << endl;
    long long result5 = fib(-1);
    cout << "  Result: fib(-1) = " << result5 << " (guarded)\n" << endl;

    // ═══════════════════════════════════════
    // DEMO 6: Indirect recursion
    // ═══════════════════════════════════════
    cout << "=== DEMO 6: Indirect Recursion (funcA ↔ funcB) ===" << endl;
    funcA(10);
    cout << endl;

    // ═══════════════════════════════════════
    // DEMO 7: Call count comparison
    // ═══════════════════════════════════════
    cout << "=== DEMO 7: Call Count Explosion ===" << endl;
    cout << "  fib(5)  calls ~15 nodes (tree)" << endl;
    cout << "  fib(10) calls ~177 nodes" << endl;
    cout << "  fib(20) calls ~21,891 nodes" << endl;
    cout << "  fib(30) calls ~2,692,537 nodes  <-- exponential!" << endl;
    cout << "  This is why naive recursion needs memoization or loops.\n" << endl;

    // ═══════════════════════════════════════
    // DEMO 8: Stack overflow danger
    // ═══════════════════════════════════════
    cout << "=== DEMO 8: Stack Overflow Danger ===" << endl;
    cout << "  void infinite() { return infinite(); }  // NO base case!" << endl;
    cout << "  Default stack: ~8 MB. Each frame: ~16-128 bytes." << endl;
    cout << "  At 32B/frame: max depth = 8MB/32 = 262,144" << endl;
    cout << "  Exceeding this -> SIGSEGV (stack overflow crash)\n" << endl;

    cout << "All recursion demos complete." << endl;
    return 0;
}
