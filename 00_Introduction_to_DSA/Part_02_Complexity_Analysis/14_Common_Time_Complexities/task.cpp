/*
═══════════════════════════════════════════════
  TASK SET — COMMON TIME COMPLEXITIES
  (count operations, match algorithms, order growth)
═══════════════════════════════════════════════

  🌍 REAL-WORLD SCENARIO:
    Post office clerk ki 8 scale-shapes hain (O(1)...O(n!)). Task practice se
    yeh shape-recognition pakki hoti hai: nested loop → n², halving → log n,
    outer + halving → n log n, enumerate subsets → 2ⁿ. Interview me aksar
    poocha jata hai: "is code ka time complexity batao aur derive karo".

  🧠 HOW TO SOLVE:
    1) Innermost line ko gino = 1 operation.
    2) Har loop ka iteration-count likho (n / log₂n / constant).
    3) Nested loops → multiply; sequential blocks → add; phir dominant par hi
       dekho (drop constants + lower terms).
    4) Sum-shape loops (1+2+...+n) → n(n+1)/2 = O(n²).
    5) Ratio test: n double karo → ops x2 = O(n), x4 = O(n²), same = O(1),
       +1 = O(log n).

  TASKS (EASY → HARD):

  ── TASK 1 [EASY] ─────────────────────────────────────────────
    Nested double loop:
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sum += 1;
    Total operations kya hongi? Derivation likho.
    💡 HINT: outer n baar, har outer me inner n baar → n × n.
    ✏️ STARTER CODE:
      int main() {
          int n = 5; long long sum = 0;
          // TODO: double nested loop, sum += 1
          // TODO: sum print karo (n^2 aana chahiye = 25)
          return 0;
      }

  ── TASK 2 [EASY] ─────────────────────────────────────────────
    Halving loop:
        for (int i = n; i > 0; i /= 2) ops++;
    n = 32 par kitni iteration hoti hain? Class kya hai?
    💡 HINT: 32→16→8→4→2→1 = 5 steps = log₂32.
    ✏️ STARTER CODE:
      int main() {
          int n = 32; long long ops = 0;
          // TODO: i = n; while(i > 0){ ops++; i /= 2; }
          // TODO: ops print karo (5 aana chahiye)
          return 0;
      }

  ── TASK 3 [MEDIUM] ───────────────────────────────────────────
    Algorithms ko correct class se match karo:
      (a) binary search        → O(?)
      (b) linear search        → O(?)
      (c) merge sort           → O(?)
      (d) double nested loop   → O(?)
      (e) saare subsets banana → O(?)
      (f) saare permutations   → O(?)
    💡 HINT: matched pair yaad karo — halving = log n, "split & merge" = n log n,
             har subset = 2ⁿ, har ordering = n!.
    ✏️ STARTER CODE:
      int main() {
          // (a)-(f) ka apna answer string banao aur print karo
          // e.g. cout << "binary search -> O(log n)\n";
          return 0;
      }

  ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    Inhe ascending growth order me rakho:
      1, log n, n, n², n²log n, n³, n log n, 2ⁿ, n!, √n
    💡 HINT: 2ⁿ < n! < nᵏ+1 < nᵏ < n (large n pe sequence sobi);
             √n = n^0.5, log n sabse slow.
    ✏️ STARTER CODE:
      int main() {
          // TODO: sorted list string print karo
          return 0;
      }

  ── TASK 5 [MEDIUM-HARD] ──────────────────────────────────────
    Triangular loop:
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) sum += 1;
    Total ops = 0+1+2+...+(n-1) = ? Derive karo aur class batao.
    💡 HINT: sum = n(n-1)/2 → n²/2 - n/2 → dominant n² → O(n²).
    ✏️ STARTER CODE:
      int main() {
          int n = 6; long long sum = 0;
          // TODO: i=0;i<n;i++ inner j=0;j<i;j++ sum++
          // TODO: sum print karo (15 aana chahiye)
          return 0;
      }

  ── TASK 6 [HARD] ─────────────────────────────────────────────
    5 loop-shapes ka exact op-counter banao (n = 64) — O(1), O(log n), O(n),
    O(n log n), O(n²) — aur verify karo ki log=6, n=64, nlogn=384, n²=4096.
    Shapes ko code karo aur ops count print karo.
    💡 HINT: shape4: outer i<n, inner j=n;j>1;j/=2 → n·⌊log₂n⌋.
    ✏️ STARTER CODE:
      long long c1(int n){ long long o=0; o+=1; o+=1; return o; }        // O(1)
      long long c2(int n){ long long o=0; // TODO: i=1;i<n;i*=2 o++;
                           return o; }                                    // O(logn)
      long long c3(int n){ long long o=0; // TODO: single loop
                           return o; }                                    // O(n)
      long long c4(int n){ long long o=0; // TODO: outer n x inner /=2
                           return o; }                                    // O(nlogn)
      long long c5(int n){ long long o=0; // TODO: double nested
                           return o; }                                    // O(n^2)
      int main(){ int n=64; // TODO: sab print karo
                  return 0; }
 ═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

// ---------------- TASK 1: double nested = O(n²) ----------------
void sol_task1() {
    int n = 5;
    long long sum = 0;
    for (int i = 0; i < n; i++)          // n baar
        for (int j = 0; j < n; j++)      // n baar
            sum += 1;
    cout << "   sum = " << sum << "   (n² = 5² = 25)\n";
    cout << "   DERIVATION: f(n) = n × n = n²  →  O(n²)\n"
            "   nested loops multiply: outer n ⋅ inner n → quadratic\n\n";
}

// ---------------- TASK 2: halving = O(log n) ----------------
void sol_task2() {
    int n = 32;
    long long ops = 0;
    for (int i = n; i > 1; i /= 2) ops++;   // 32→16→8→4→2 = 5 halvings
    cout << "   ops = " << ops << "   (log2 32 = 5)\n";
    cout << "   DERIVATION: i n/2 hota hai har step → steps = ⌊log₂n⌋\n"
            "   f(n) = log₂n  →  O(log n)\n\n";
}

// ---------------- TASK 3: match algorithms ----------------
void sol_task3() {
    cout << "   (a) binary search        -> O(log n)   (array aadha hota hai)\n";
    cout << "   (b) linear search        -> O(n)       (poora scan)\n";
    cout << "   (c) merge sort           -> O(n log n) (split n/2 + merge n)\n";
    cout << "   (d) double nested loop   -> O(n²)\n";
    cout << "   (e) saare subsets        -> O(2ⁿ)      (har element or in/out)\n";
    cout << "   (f) saare permutations   -> O(n!)\n";
    cout << "   DERIVATION: halve→logn, divide&merge→nlogn, n×n→n²,\n"
            "   2 choices^n→2ⁿ, n! orderings→n!\n\n";
}

// ---------------- TASK 4: growth ordering ----------------
void sol_task4() {
    cout << "   Ascending (slowest → fastest):\n";
    cout << "   1 < log n < √n < n < n log n < n² < n²log n < n³ < 2ⁿ < n!\n";
    cout << "   DERIVATION: n²·logn dominates n² (extra log factor), n³\n"
            "   beats n²logn (n³/n²logn = n/logn → ∞), 2ⁿ beats n³\n"
            "   (2ⁿ/n³ → ∞), n! eventually beats 2ⁿ (2ⁿ/n! → 0).\n\n";
}

// ---------------- TASK 5: triangular loop = O(n²) ----------------
void sol_task5() {
    int n = 6;
    long long sum = 0;
    for (int i = 0; i < n; i++)          // i=0..5
        for (int j = 0; j < i; j++)      // j=0..i-1 → i iterations
            sum += 1;
    cout << "   sum = " << sum << "   (0+1+2+3+4+5 = 15)\n";
    cout << "   DERIVATION: ops = 0+1+2+...+(n-1) = n(n-1)/2\n"
            "   = n²/2 − n/2; drop n/2 (lower order) → n²/2 → O(n²)\n\n";
}

// ---------------- TASK 6: exact op-counters, n=64 ----------------
long long c1(int n) { long long o = 0; o += 1; o += 1; (void)n; return o; }  // O(1)
long long c2(int n) { long long o = 0; for (int i = 1; i < n; i *= 2) o++; return o; }   // O(log n)
long long c3(int n) { long long o = 0; for (int i = 0; i < n; i++) o++; return o; }      // O(n)
long long c4(int n) { long long o = 0; for (int i = 0; i < n; i++) for (int j = n; j > 1; j /= 2) o++; return o; }  // O(n log n)
long long c5(int n) { long long o = 0; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) o++; return o; }     // O(n²)

void sol_task6() {
    int n = 64;
    cout << "   n=" << n << "\n";
    cout << "   O(1)     ops = " << c1(n) << "   (expect 2)\n";
    cout << "   O(log n) ops = " << c2(n) << "   (expect 6 = log2 64)\n";
    cout << "   O(n)     ops = " << c3(n) << "   (expect 64)\n";
    cout << "   O(nlogn) ops = " << c4(n) << "   (expect 64*6 = 384)\n";
    cout << "   O(n^2)   ops = " << c5(n) << "   (expect 4096)\n";
    cout << "   DERIVATION: exact counts verify karte hain — log=6,\n"
            "   n=64, 64·6=384, 64²=4096 ✓ class sahi hai\n";
}

int main() {
    cout << "TASK 1:\n"; sol_task1();
    cout << "TASK 2:\n"; sol_task2();
    cout << "TASK 3:\n"; sol_task3();
    cout << "TASK 4:\n"; sol_task4();
    cout << "TASK 5:\n"; sol_task5();
    cout << "TASK 6:\n"; sol_task6();
    return 0;
}