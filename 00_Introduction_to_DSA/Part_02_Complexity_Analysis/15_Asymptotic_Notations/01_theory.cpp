/*
═══════════════════════════════════════════════
 ASYMPTOTIC NOTATIONS
 (Big-O upper bound · Omega lower bound · Theta tight bound
  + little-o / little-omega)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    A teacher grades exams by giving three kinds of promises about a student.
    "Scoring at most 95" is an upper bound — it may be 20, but you know the
    ceiling (that is big-O). "Scoring at least 40" is a lower bound — the
    student can't ruin the grade below a floor (that is Omega). "Scoring
    between 70 and 90 every single time" pins the grade inside a tight band
    (that is Theta). The same three lenses apply to algorithms: big-O says
    "it will never exceed c·g(n)", Omega says "it will never go below c·g(n)",
    and Theta says "it stays sandwiched between two scaled copies of g(n)".
    Interviews ask "prove f(n) is O(n²)" — which simply means *find* one
    constant c and one starting size n₀ that make the inequality forever true.

 📖 THEORY: (pure English, formal)
    Let f, g be functions of n (n = input size, integer, positive).

    BIG-O (upper bound):
       f(n) = O(g(n))  ⇔  ∃ c, n₀ > 0 such that  f(n) ≤ c·g(n)  ∀ n ≥ n₀
       Meaning: f grows NO faster than g. Only an upper cap is promised.

    OMEGA (lower bound):
       f(n) = Ω(g(n))  ⇔  ∃ c, n₀ > 0 such that  f(n) ≥ c·g(n)  ∀ n ≥ n₀
       Meaning: f grows NO slower than g. Lower floor is guaranteed.

    THETA (tight bound):
       f(n) = Θ(g(n))  ⇔  ∃ c₁, c₂, n₀ > 0 such that
                          c₁·g(n) ≤ f(n) ≤ c₂·g(n)  ∀ n ≥ n₀
       Meaning: f and g grow at EXACTLY the same rate (both upper + lower).
       Equivalent to: f(n) = O(g(n)) AND f(n) = Ω(g(n)).

    LITTLE-O (strictly slower): f(n) = o(g(n)) ⇔ for EVERY c > 0 there is
       n₀ with f(n) < c·g(n) ∀ n ≥ n₀ — f is dwarfed in the limit.
    LITTLE-OMEGA (strictly faster): f(n) = ω(g(n)) ⇔ for EVERY c > 0 there
       is n₀ with f(n) > c·g(n) ∀ n ≥ n₀ — g is dwarfed by f.

    ASCII — the same f(n) viewed through three windows:

        ops ▲
            │ ──────── c₂·g(n)        ← big-O ceiling (upper)
            │        ╱
            │       f(n)·······        ← f grows between the two
            │      ╱
            │ ──── c₁·g(n)            ← Omega floor (lower)
            │
            └────────────────────────► n
              Θ(g) band keeps f inside; O(g) only caps it;
              Ω(g) only floors it.

    - WHEN TO USE: Big-O for "worst-case/upper" guarantees in interviews;
      Omega when you must promise a minimum amount of work; Theta when you
      have both and can be exact. Little-o/ω for algorithm-design proofs
      ("this is strictly better than that class").

 🧠 LOGIC — STEP BY STEP: (pure English)
    Step 1: Pick a candidate g(n) for the class you want to prove.
                                              WHY: you must always name the
            comparator function explicitly.
    Step 2: Write f(n) as dominant-term + junk: f(n) = 3n + 2.
            Junk = 2.                                   WHY: junk decides how
            big c must be and where n₀ starts.
    Step 3: Force the inequality: 3n + 2 ≤ c·n. Since 2 ≤ 2n for n ≥ 1,
            we get 3n + 2 ≤ 3n + 2n = 5n → choose c = 4 (even tighter:
            3n+2 ≤ 4n holds ⇔ n ≥ 2).                    WHY: replace the junk by
            a fixed multiple of n, then solve for n₀.
    Step 4: Verify: print the table f(n) vs c·g(n) and CHECK every n ≥ n₀
            passes.                                      WHY: the definition is
            universal (∀ n ≥ n₀) — one failing row kills the proof.
    Step 5: For Θ, repeat the same with a lower bound; pick c₁ from the
            dominant term (3n ≥ 3n always → c₁ = 3).      WHY: Ω needs f ≥ c·g.

 VISUAL WALKTHROUGH (verification table the demo prints, g(n) = n, c = 4):

    Big-O check: is f(n) = 3n+2 ≤ 4n for every n ≥ n₀?
    ┌────┬───────┬────────┬───────────────┐
    │ n  │ 3n+2  │ 4n     │ 3n+2 ≤ 4n?    │
    ├────┼───────┼────────┼───────────────┤
    │ 1  │ 5     │ 4      │ NO   ← fails  │
    │ 2  │ 8     │ 8      │ YES  ← n₀=2 ✓ │
    │ 3  │ 11    │ 12     │ YES           │
    │ 4  │ 14    │ 16     │ YES           │
    │ 5  │ 17    │ 20     │ YES           │
    │ ...│ ...   │ ...    │ YES (all n≥2) │
    └────┴───────┴────────┴───────────────┘
    The smallest valid n₀ = 2. Ω(f) with c₁ = 3: 3n+2 ≥ 3n ∀ n ≥ 1.
    Since both O(n) and Ω(n) hold → Θ(n).

 DRY RUN (demo values):
    n = 1 : f(1) = 3·1+2 = 5 ; c·g = 4·1 = 4 ; 5 ≤ 4 ? NO
    n = 2 : f(2) = 8       ; c·g = 8       ; 8 ≤ 8 ? YES  (exactly at bound)
    n = 3 : f(3) = 11      ; c·g = 12      ; 11 ≤ 12 ? YES
    n = 6 : f(6) = 20      ; c·g = 24      ; 20 ≤ 24 ? YES
    So with c = 4, n₀ = 2 the inequality is TRUE for all n ≥ 2 → proof done.

 TIME COMPLEXITY CALCULATION:
    - f(n) = 3n + 2 : dominant term 3n, junk 2.
      Upper: 3n+2 ≤ 3n + 2n = 5n for n ≥ 1   → c = 5, n₀ = 1 works.
      Tighter: 3n+2 ≤ 4n ⇔ 2 ≤ n             → c = 4, n₀ = 2 works.
      Lower: 3n+2 ≥ 3n (c₁ = 3, n₀ = 1)      → Ω(n).
      Both bounds → Θ(n).
    → Time Complexity = O(n) = Ω(n) = Θ(n); also f ∈ o(n·log n),
      f ∈ ω(1) — the class exactly matches n.

 SPACE COMPLEXITY CALCULATION:
    - The verification routine uses only n, c and two function calls — a
      constant number of variables, no arrays.
    → Space Complexity = O(1).

 APPROACH COMPARISON:
    ┌──────────────┬──────────────────────────────┬──────────────────────────────┐
    │ Notation     │ Formal meaning               │ Typical use                  │
    ├──────────────┼──────────────────────────────┼──────────────────────────────┤
    │ O (Big-O)    │ f ≤ c·g for n ≥ n₀           │ upper bound / worst-case     │
    │ Ω (Omega)    │ f ≥ c·g for n ≥ n₀           │ lower bound of work          │
    │ Θ (Theta)    │ c₁g ≤ f ≤ c₂g for n ≥ n₀    │ exact growth rate            │
    │ o (little-o) │ f < c·g for ALL c              │ strictly slower (proper sub)-│
    │ ω (omega)    │ f > c·g for ALL c              │ strictly faster (superset)  │
    └──────────────┴──────────────────────────────┴──────────────────────────────┘
*/
#include <iostream>
using namespace std;

// f(n) = 3n + 2 — verify karne wali function
int f(int n) { return 3 * n + 2; }

// c·g(n) = 4·n  (g(n) = n, c = 4)
int cg(int n) { return 4 * n; }

int main() {
    cout << "BIG-O VERIFICATION: f(n) = 3n+2  vs  c·g(n) = 4n  (g=n, c=4)\n";
    cout << "Rule: ∃ c,n0>0 : f(n) ≤ c·g(n)  ∀ n ≥ n0\n\n";

    cout << " n | 3n+2 | 4n |  3n+2 ≤ 4n ?\n";
    cout << "---+------+----+---------------\n";
    int firstPass = -1;                 // pehla n0 jahan se hamesha true
    for (int n = 1; n <= 10; n++) {
        bool ok = (f(n) <= cg(n));      // inequality check
        if (ok && firstPass == -1) firstPass = n;   // sabse chhota n0
        cout << " " << n << " |  " << f(n) << "  |  " << cg(n)
             << " | " << (ok ? "YES" : "NO ") << "\n";
    }
    cout << "\n=> smallest n0 = " << firstPass << "  (row 2 se hamesha 3n+2 ≤ 4n)\n";
    cout << "=> f(n) = O(n) with c = 4, n0 = " << firstPass << "\n\n";

    cout << "OMEGA VERIFICATION: f(n) = 3n+2 ≥ c1·g(n) = 3n  (c1 = 3)\n";
    bool omegaOk = true;
    for (int n = 1; n <= 10; n++)
        if (f(n) < 3 * n) omegaOk = false;    // 3n+2 - 3n = 2 > 0 hamesha
    cout << "   3n+2 − 3n = 2 > 0 -> " << (omegaOk ? "YES" : "NO")
         << "  for all n ≥ 1 => f(n) = Ω(n)\n\n";

    cout << "THETA: f(n) = O(n) AND f(n) = Ω(n)  =>  f(n) = Θ(n)\n";
    cout << "Tightest bounds: c1=3 (floor), c2=4 (ceiling), n0=2\n";
    cout << "\nEDGE CASE (big-O false claim): is f(n) = n² = O(n)?? NO —\n";
    cout << "   n² ≤ c·n ⇔ n ≤ c fails once n > c, ANY c ke liye.\n";
    return 0;
}