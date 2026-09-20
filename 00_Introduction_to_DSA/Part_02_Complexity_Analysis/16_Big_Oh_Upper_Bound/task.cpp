/*
═══════════════════════════════════════════════
  TASK SET — BIG O (UPPER BOUND)
  (reduce functions to O(...), find c & n₀, drop terms)
═══════════════════════════════════════════════

  🌍 REAL-WORLD SCENARIO:
    "Delivery within 2 months" — yeh Big-O ka promise hai: messy real cost
    kabhi c·g(n) budgood se upar nahi jayegi, n₀ ke baad. Har task me ek
    function diya hai; tumhe dominant term pehchano, constants/lower-order
    terms girao, c aur n₀ nikalo aur table se verify karo.

  🧠 HOW TO SOLVE:
    1) Dominant term pakdo (sabse badi power).
    2) Junk ko dominant ke haath me de do: junk ≤ K·(dominant) prove karo.
    3) n₀ solve karo; c = (dominant-coefficient + K).
    4) f(n) ≤ c·g(n) ka table chala kar prove pakka karo.
    5) Yaad rakho: polynomial → highest power; log n ≤ n; constants → O(1).

  TASKS (EASY → HARD):

  ── TASK 1 [EASY] ─────────────────────────────────────────────
    Reduce:  f(n) = 7n² + 9n + 3  →  O(?).  c aur n₀ bhi do.
    💡 HINT: 9n ≤ 9n² and 3 ≤ 3n² for n ≥ 1 → total ≤ 19n² → c=19, n₀=1.
    ✏️ STARTER CODE:
      int main(){
          // TODO: table n=1..8: f(n)=7n²+9n+3 vs 19n²
          // TODO: verdict + dropped-terms explanation print karo
          return 0;
      }

  ── TASK 2 [EASY] ─────────────────────────────────────────────
    Reduce:  f(n) = 2n² + n   →  O(?).  Tight c aur n₀ batao.
    💡 HINT: n ≤ n² for n ≥ 1 → 2n²+n ≤ 3n² → c=3, n₀=1. Behtar: n₀=1,c=3.
    ✏️ STARTER CODE:
      int main(){
          // TODO: f=2n²+n vs 3n² table n=1..8
          return 0;
      }

  ── TASK 3 [MEDIUM] ───────────────────────────────────────────
    Reduce:  f(n) = log₂n + 5   →  O(log n).  c, n₀ dhundho.
    💡 HINT: 5 ≤ 5·log₂n for n ≥ 2 → total ≤ 6·log₂n → c=6, n₀=2.
    ✏️ STARTER CODE:
      int main(){
          // TODO: n=1..16: f=logn+5 vs 6logn (integer log2 use karo)
          return 0;
      }

  ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    Reduce:  f(n) = 3n + 7·log₂n   →  O(n).   c, n₀ batao.
    💡 HINT: log₂n ≤ n for n ≥ 1 → 7logn ≤ 7n → total ≤ 10n → c=10, n₀=1.
    ✏️ STARTER CODE:
      int main(){
          // TODO: f=3n+7logn vs 10n table n=1..12
          return 0;
      }

  ── TASK 5 [MEDIUM-HARD] ──────────────────────────────────────
    Reduce:  f(n) = 4n³ + 2n² + 100  →  O(n³) tight c=5 n₀=? dhundho.
    💡 HINT: 2n²+100 ≤ n³ ⇔ n ≥ 6 (verify 6: 172≤216 ✓, 5:150≤125 ✗) → n₀=6.
    ✏️ STARTER CODE:
      int main(){
          // TODO: n=1..10 table: 4n³+2n²+100 vs 5n³
          // TODO: first passing n0 mark karo
          return 0;
      }

  ── TASK 6 [HARD] ─────────────────────────────────────────────
    Decision:  (a) 3n² = O(2ⁿ)?  — haan. c=3, n₀=4 (n² ≤ 2ⁿ for n≥4).
    (b) 2ⁿ = O(n²)? — NAHI. Proof: n > c choice pe hamesha fail.
    Dono tables se dikhao aur justify karo.
    💡 HINT: check n²≤2ⁿ at n=4 (16≤16 ✓) — exponential beats polynomial.
    ✏️ STARTER CODE:
      int main(){
          int c = 3;
          // TODO: (a) table 3n² vs 3·2ⁿ n=1..10
          // TODO: (b) table 2ⁿ vs 3n² n=1..12, dikhao WHERE 2ⁿ overtakes
          return 0;
      }
 ═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;
using ll = long long;

// log2 (integer floor) helper
int lg2(int n) { int k = 0; while ((1 << (k + 1)) <= n) k++; return k; }

// ---------------- TASK 1: 7n²+9n+3 → O(n²), c=19 ----------------
void sol_task1() {
    cout << "   n | 7n²+9n+3 | 19n² | ≤?\n";
    cout << "  ---+----------+------+----\n";
    for (int n = 1; n <= 8; n++) {
        ll f = 7LL * n * n + 9LL * n + 3;
        ll g = 19LL * n * n;
        cout << "  " << n << " |   " << f << "    |  "
             << g << " | " << (f <= g ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: 9n ≤ 9n² and 3 ≤ 3n² for n ≥ 1 →\n"
            "   7n²+9n+3 ≤ (7+9+3)n² = 19n² ⇒ c=19, n₀=1 → O(n²)\n\n";
}

// ---------------- TASK 2: 2n²+n → O(n²), c=3 ----------------
void sol_task2() {
    cout << "   n | 2n²+n | 3n² | ≤?\n";
    cout << "  ---+-------+-----+----\n";
    for (int n = 1; n <= 8; n++) {
        ll f = 2LL * n * n + n;
        ll g = 3LL * n * n;
        cout << "  " << n << " |   " << f << "  |  "
             << g << " | " << (f <= g ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: n ≤ n² for n ≥ 1 → 2n²+n ≤ 3n².\n"
            "   c=3, n₀=1. Lower order 'n' dropped → O(n²).\n\n";
}

// ---------------- TASK 3: log₂n+5 → O(log n), c=6, n₀=2 ----------------
void sol_task3() {
    cout << "   n | lg2n+5 | 6lg2n | ≤?\n";
    cout << "  ---+--------+-------+----\n";
    for (int n = 1; n <= 16; n++) {
        ll L = lg2(n);
        ll f = L + 5;
        ll g = 6 * L;
        cout << "  " << n << " |   " << f << "    |   "
             << g << "   | " << (f <= g ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: 5 ≤ 5·log₂n for n ≥ 2 (log₂n ≥ 1) →\n"
            "   f ≤ log₂n + 5log₂n = 6log₂n ⇒ c=6, n₀=2 → O(log n)\n"
            "   NOTE: row n=1 me log₂1=0 atakta hai → n₀=2 isliye\n\n";
}

// ---------------- TASK 4: 3n+7logn → O(n), c=10 ----------------
void sol_task4() {
    cout << "   n | 3n+7lg2n | 10n | ≤?\n";
    cout << "  ---+----------+-----+----\n";
    for (int n = 1; n <= 12; n++) {
        ll f = 3LL * n + 7LL * lg2(n);
        ll g = 10LL * n;
        cout << "  " << n << " |    " << f << "     |  "
             << g << " | " << (f <= g ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: log₂n ≤ n for n ≥ 1 → 7log₂n ≤ 7n →\n"
            "   f ≤ 3n + 7n = 10n ⇒ c=10, n₀=1 → O(n)\n"
            "   KEY IDEA: log-term polynomial-term se hamesha harata hai\n\n";
}

// ---------------- TASK 5: 4n³+2n²+100 → O(n³), c=5, n₀=6 ----------------
void sol_task5() {
    cout << "   n | 4n³+2n²+100 | 5n³ | ≤?\n";
    cout << "  ---+-------------+-----+----\n";
    int n0 = -1;
    for (int n = 1; n <= 10; n++) {
        ll f = 4LL * n * n * n + 2LL * n * n + 100;
        ll g = 5LL * n * n * n;
        bool ok = f <= g;
        if (ok && n0 == -1) n0 = n;
        cout << "  " << n << " |    " << f << "     |  "
             << g << " | " << (ok ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: 2n²+100 ≤ n³ ⇔ n₀=6 (row6: 172 ≤ 216 ✓;\n"
            "   row5: 150 ≤ 125 ✗). → 4n³+2n²+100 ≤ 4n³+n³ = 5n³\n"
            "   c=5, n₀=" << n0 << " → O(n³)\n\n";
}

// ---------------- TASK 6: 3n² = O(2ⁿ) true; 2ⁿ = O(n²) false ----------------
void sol_task6() {
    cout << "   (a) 3n² vs 3·2ⁿ  (c=3):\n";
    cout << "   n | 3n² | 3·2ⁿ | ≤?\n";
    cout << "  ---+-----+------+----\n";
    for (int n = 1; n <= 10; n++) {
        ll f = 3LL * n * n;
        ll g = 3LL * (1LL << n);
        cout << "  " << n << " |  " << f << "  |   "
             << g << "  | " << (f <= g ? "Y" : "N") << "\n";
    }
    cout << "   n² ≤ 2ⁿ from n=4 (16 ≤ 16 ✓) → c=3, n₀=4 → 3n² = O(2ⁿ) ✓\n\n";

    cout << "   (b) 2ⁿ vs 3n² — kyun 2ⁿ = O(n²) NAHI:\n";
    cout << "   n | 2ⁿ   | 3n²  | 2ⁿ≤3n²?\n";
    cout << "  ---+------+------+--------\n";
    for (int n = 1; n <= 14; n++) {
        ll f = 1LL << n;                 // 2ⁿ
        ll g = 3LL * n * n;
        cout << "  " << n << " |  " << f << "   |  "
             << g << "  | " << (f <= g ? "Y " : "N ") << "\n";
    }
    cout << "   DERIVATION: 2ⁿ ≤ c·n² ⇔ 2ⁿ/n² ≤ c. 2ⁿ/n² → ∞ as n→∞,\n"
            "   isliye KOI bhi c eventually fail — 2ⁿ/n² grows forever ⇒\n"
            "   2ⁿ ∉ O(n²) (exponential polynomial se technically toot-ti)\n";
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