/*
═══════════════════════════════════════════════
  TASK SET — ASYMPTOTIC NOTATIONS
  (find c and n₀, verify Big-O / Omega / Theta)
═══════════════════════════════════════════════

  🌍 REAL-WORLD SCENARIO:
    Exam-grader ki teen promises hain: upper bound (O), lower bound (Ω), aur
    tight band (Θ). Kisi function ka class prove karne ke liye sirf ek kaam
    karना hai: aise c aur n₀ dhundhna ki inequality UNIVERSE (∀ n ≥ n₀) ke
    liye hai. Yehi "proof by constants" interview ka signature question hai.

  🧠 HOW TO SOLVE:
    1) f(n) = dominant term + junk likho.
    2) Junk ko dominant ke multiple me chhupa do: c·g(n) banate waqt junk ≤
       (extra)·g(n) prove karo.
    3) Inequality solve karke n₀ nikaalo; us par table se verify karo.
    4) Ω ke liye lower inequality f(n) ≥ c₁·g(n); Θ ke liye dono prove karo.
    5) Yaad rakho: n² = O(n) KABHI NAHI — ek hi suffices: n > c pe fail.

  TASKS (EASY → HARD):

  ── TASK 1 [EASY] ─────────────────────────────────────────────
    Prove: f(n) = 5n + 3  is  O(n).  c = 6, n₀ = ? dhundho aur verify karo.
    💡 HINT: 5n+3 ≤ 6n ⇔ 3 ≤ n → n₀ = 3. Table n=1..8 print karo.
    ✏️ STARTER CODE:
      int f(int n){ return 5*n + 3; }       // f(n) = 5n+3
      int cg(int n){ return 6*n; }          // c·g = 6n
      int main(){
          // TODO: n=1..8 tak f(n) <= 6n check + print
          // TODO: pehla passing n0 print karo
          return 0;
      }

  ── TASK 2 [EASY] ─────────────────────────────────────────────
    Prove: f(n) = n² + 2n  is  O(n²).   c = 2 .  n₀?  verify karo.
    💡 HINT: 2n ≤ n² for n ≥ 2 → n²+2n ≤ 2n² for n≥2 → n₀=2.
    ✏️ STARTER CODE:
      int main(){
          // TODO: table n=1..8: f=n*n+2n, cg=2*n*n
          return 0;
      }

  ── TASK 3 [MEDIUM] ──────────────────────────────────────────
    f(n) = n² + 10n. Tight c=2, n0=10 prove karo; loose (c=11, n0=1) bhi.
    Dono ka table chhapo.
    💡 HINT: n²+10n ≤ 2n² ⇔ 10n ≤ n² ⇔ n ≥ 10. Loose: n²+10n ≤ 11n² ✓ n≥1.
    ✏️ STARTER CODE:
      int main(){
          // TODO: n=1..15: tight (2n²) vs loose (11n²) dono columns
          return 0;
      }

  ── TASK 4 [MEDIUM] ──────────────────────────────────────────
    Prove f(n) = 100n + 5 is BOTH O(n) and Ω(n) — phir Θ(n).
    O: c2=101, n0=5. Ω: c1=1, n0=1. Dono inequalities table ke saath.
    💡 HINT: 100n+5 ≤ 101n ⇔ 5 ≤ n → n₀=5; 100n+5 ≥ n ∀n≥1 (trivial).
    ✏️ STARTER CODE:
      int main(){
          // TODO: upper: 100n+5 <= 101n ; lower: 100n+5 >= n
          // TODO: dono ka table + "THETA" verdict
          return 0;
      }

  ── TASK 5 [MEDIUM-HARD] ─────────────────────────────────────
    f(n) = n² + 3n + 1 class = Θ(n²). c₁, c₂, n₀ dhundho.
    💡 HINT: c₁=1 (n² ≤ n²+3n+1); c₂=5 (3n+1 ≤ 4n² → total ≤ 5n² ∀ n≥1 → n₀=1).
    ✏️ STARTER CODE:
      int main(){
          // TODO: dono sides print + verdict: c1=1 <= f/n^2 <= c2=5
          return 0;
      }

  ── TASK 6 [HARD] ────────────────────────────────────────────
    Na-POSSIBLE prove karo:  f(n) = n³  is NOT  O(n²).
    ®Rule: n³ ≤ c·n² ⇔ n ≤ c — n > c choose karne pe hamesha fail.
    Table n=1..10 with c=3 dikhao (har row fail hogi jahan n>3).
    💡 HINT: n³ vs 3n² table; n=4 ke baad hamesha n³ > 3n².
    ✏️ STARTER CODE:
      int main(){
          int c = 3;
          // TODO: n=1..10: f=n*n*n, cg=c*n*n; kahan fail hota hai dikhao
          return 0;
      }
 ═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;
using ll = long long;

// ---------------- TASK 1: 5n+3 = O(n), c=6, n0=3 ----------------
int f1(int n) { return 5 * n + 3; }

void sol_task1() {
    cout << "   f(n)=5n+3 vs 6n :\n";
    cout << "    n | 5n+3 | 6n  | ≤?\n";
    cout << "   ---+------+-----+----\n";
    for (int n = 1; n <= 8; n++) {
        bool ok = f1(n) <= 6 * n;
        cout << "   " << n << " |  " << f1(n) << "  |  " << 6 * n
             << "  | " << (ok ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: 5n+3 ≤ 6n ⇔ 3 ≤ n ⇔ n₀=3 → c=6,n₀=3 ⇒ O(n)\n\n";
}

// ---------------- TASK 2: n²+2n = O(n²), c=2, n0=2 ----------------
void sol_task2() {
    cout << "   f(n)=n²+2n vs 2n² :\n";
    cout << "    n | n²+2n | 2n² | ≤?\n";
    cout << "   ---+-------+-----+----\n";
    for (int n = 1; n <= 8; n++) {
        long long f = (long long)n * n + 2 * n;
        long long g = 2LL * n * n;
        cout << "   " << n << " |  " << f << "   |  " << g
             << "  | " << (f <= g ? "Y" : "N") << "\n";
    }
    cout << "   DERIVATION: 2n ≤ n² ∀ n≥2 → n²+2n ≤ n²+n² = 2n² ⇒ O(n²)\n\n";
}

// ---------------- TASK 3: n²+10n tight vs loose ----------------
void sol_task3() {
    cout << "   n |  n²+10n | 2n²(tight) | 11n²(loose)\n";
    cout << "  ---+--------+-----------+-----------\n";
    for (int n = 1; n <= 15; n++) {
        long long f = (long long)n * n + 10LL * n;
        bool t = f <= 2LL * n * n;
        bool l = f <= 11LL * n * n;
        cout << "  " << n << " |  " << f << "   |    "
             << 2LL * n * n << (t ? " ✓" : " ✗") << "     |    "
             << 11LL * n * n << (l ? " ✓" : " ✗") << "\n";
    }
    cout << "   Tight c=2 ↑ passes from n=10; loose c=11 passes from n=1.\n";
    cout << "   DERIVATION: tight 10n≤n² ⇔ n≥10; loose 10n≤10n² ∀n≥1 +\n"
            "   n²≤n² → total ≤ 11n² ⇒ O(n²) dono se\n\n";
}

// ---------------- TASK 4: 100n+5 both bounds → Θ(n) ----------------
void sol_task4() {
    cout << "   n | 100n+5 | 101n (O) | 1n (Ω)\n";
    cout << "  ---+--------+---------+--------\n";
bool oAll = true, wAll = true;
    for (int n = 1; n <= 10; n++) {
        ll f = 100LL * n + 5;
        bool o = f <= 101LL * n;
        bool w = f >= 1LL * n;
        if (n >= 5) oAll &= o;      // O-claim n₀=5 se shuru — uske aage sab check
        wAll &= w;
        cout << "  " << n << " |  " << f << "   |   "
             << 101LL * n << (o ? "  ✓" : "  ✗") << "    |    "
             << n << (w ? "  ✓" : "  ✗") << "\n";
    }
    cout << "   O: c=101 valid WHEN n ≥ 5 (5 ≤ n); all n≥5 pass = "
         << (oAll ? "YES" : "NO") << "\n";
    cout << "   Ω: c=1 (100n+5 ≥ n trivial), all n≥1 pass = "
         << (wAll ? "YES" : "NO") << "\n";
    cout << "   => O(n) with n₀=5 AND Ω(n) with n₀=1  ⇒  Θ(n) (n₀=5 covers dono)\n\n";
}

// ---------------- TASK 5: n²+3n+1 = Θ(n²), c1=1, c2=5, n0=1 ----------------
void sol_task5() {
    cout << "   n | f(n)      | c1·n² | c2·n² | c1≤f≤c2?\n";
    cout << "  ---+-----------+-------+-------+----------\n";
    bool all = true;
    for (int n = 1; n <= 8; n++) {
        long long f = (long long)n * n + 3LL * n + 1;
        long long lo = 1LL * n * n;
        long long hi = 5LL * n * n;
        bool ok = lo <= f && f <= hi;
        all &= ok;
        cout << "  " << n << " |   " << f << "     |  "
             << lo << "    |  " << hi << "   | " << (ok ? "YES" : "NO ") << "\n";
    }
    cout << "   DERIVATION: lower 3n+1≥0 → f≥n² (c₁=1). Upper 3n≤3n² and\n"
            "   1≤n² ∀n≥1 → f ≤ n²+3n²+n² = 5n² (c₂=5). n₀=1 ⇒ Θ(n²).\n\n";
}

// ---------------- TASK 6: n³ is NOT O(n²) ----------------
void sol_task6() {
    int c = 3;
    cout << "   n | n³    | 3n²   | n³≤3n²?\n";
    cout << "  ---+-------+-------+--------\n";
    for (int n = 1; n <= 10; n++) {
        long long f = (long long)n * n * n;
        long long g = 3LL * n * n;
        bool ok = f <= g;
        cout << "  " << n << " |  " << f << "   |  "
             << g << "   | " << (ok ? "YES " : "NO ") << "\n";
    }
    cout << "   DERIVATION: n³ ≤ c·n² ⇔ n ≤ c. Jab n > c (yahan n>3)\n"
            "   inequality TUTA rahata hai — hamesha koi n₀ milega jo fail\n"
            "   kare. Kyunki ALL n ≥ n₀ chahiye → O(n²) galat ⇒ n³ ∉ O(n²).\n";
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