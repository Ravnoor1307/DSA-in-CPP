/*
═══════════════════════════════════════════════
 BIG O — UPPER BOUND
 (f(n) = O(g(n)) : constants c, n₀ · drop constants
  & lower-order terms · 5n³+2n+7 → O(n³))
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    A shopkeeper promises delivery "within 2 months, no matter how many
    orders arrive after the first 10". The essence of Big-O is that same
    promise: however messy the real cost f(n) looks — extra taxes, handling
    fees, idle hours — it will NEVER exceed some scaled, simpler budget
    c·g(n), once n passes a starting size n₀. Big-O is deliberately a
    pessimistic-but-honest ceiling. When f(n) = 5n³ + 2n + 7 (nested work,
    tiny overhead, fixed set-up cost), an experienced engineer instantly
    declares "that's an O(n³) algorithm" — because n³ is the only term that
    matters as n grows; the constants 5 and the little +2n and +7 fade to
    nothing against it. This "dropping" is exactly what Big-O is for.

 📖 THEORY: (pure English, formal)
    - DEFINITION: f(n) = O(g(n))  ⇔  ∃ c, n₀ > 0 such that
      0 ≤ f(n) ≤ c·g(n)  for ALL n ≥ n₀.
      g(n) is the "budget function"; c is the multiplier; n₀ is the point
      after which the guarantee is permanently on.
    - DROPPING CONSTANTS: 5n³ vs 1000n³ — both are O(n³); the constant 5 or
      1000 is absorbed into c. Big-O counts GROWTH, not exact speed.
    - DROPPING LOWER-ORDER TERMS: for large n the biggest-power term
      dominates. Adding 2n + 7 to 5n³ changes almost nothing in the limit
      because (2n + 7)/n³ → 0.
    - FORMAL PATTERN (polynomial rule):
        aₖnᵏ + aₖ₋₁nᵏ⁻¹ + ... + a₀  =  O(nᵏ)
      because each smaller term aᵢnⁱ ≤ |aᵢ|·nᵏ for n ≥ 1, so the whole sum
      fits inside (Σ|aᵢ|)·nᵏ.
    - ASCII — the guarantee means "under the budget line forever after n₀":

         cost ▲
              │                            f(n) = 5n³+2n+7 (real cost)
              │                          ╱
              │                        ╱
              │                 ─────▶╱   c·g(n) = 6n³ (budget ceiling)
              │               ╱───────
              │             ╱
              │           ╱
              │  n₀=3 ← ─╱ GAP (f under budget) from here on
              └──────────────────────────────► n

    - WHEN TO USE: whenever you report "worst-case-ish" complexity for
      interviews/algorithms; Big-O = the standard "big picture" ceiling.

 🧠 LOGIC — STEP BY STEP: (pure English)
    Step 1: Identify the dominant (highest-power) term of f(n): for
            f(n) = 5n³ + 2n + 7 → dominant is 5n³.            WHY: for large n,
            every other term becomes negligible relative to n³.
    Step 2: Pick g(n) = dominant base n³ (constant dropped → 5 absorbed into c)
            and guess c = 6, i.e. the budget 6n³.              WHY: we want a
            clean multiple that clearly dominates the real function.
    Step 3: Verify the junk fits: need 5n³+2n+7 ≤ 6n³ ⇔ 2n+7 ≤ n³. For n ≥ 3:
            2(3)+7 = 13 ≤ 27 ✓, and the gap only widens.        WHY: comparing
            the leftover (2n+7) against n³ at the smallest candidate n finds
            the honest starting point n₀.
    Step 4: Set n₀ = 3. Print the table: every row n ≥ 3 must show
            f(n) ≤ 6n³.                                         WHY: the
            definition is universal (∀ n ≥ n₀) — one row out of line kills it.
    Step 5: Conclude f(n) = O(n³) (constants + lower terms dropped).
                                              WHY: c = 6, n₀ = 3 are a valid
            existential pair, so the proof is complete.

 VISUAL WALKTHROUGH (verification table the demo prints):

    Is f(n) = 5n³ + 2n + 7 ≤ 6n³ for all n ≥ n₀?
    ┌────┬──────────┬──────┬───────────────┐
    │ n  │ 5n³+2n+7 │ 6n³  │ f(n) ≤ 6n³?   │
    ├────┼──────────┼──────┼───────────────┤
    │ 1  │ 14       │ 6    │ NO   ← early  │
    │ 2  │ 51       │ 48   │ NO            │
    │ 3  │ 148      │ 162  │ YES ← n₀=3 ✓  │
    │ 4  │ 335      │ 384  │ YES           │
    │ 5  │ 642      │ 750  │ YES           │
    │ .. │ ...      │ ...  │ YES (all n≥3) │
    └────┴──────────┴──────┴───────────────┘
    Small n are allowed to fail — Big-O only promises from n₀ onwards.

 DRY RUN (demo values):
    n = 1 : f = 5·1 + 2 + 7 = 14 ; 6·1 = 6   ; 14 ≤ 6?  NO  (n < n₀, ok)
    n = 2 : f = 5·8 + 4 + 7 = 51 ; 6·8 = 48  ; 51 ≤ 48? NO  (n < n₀, ok)
    n = 3 : f = 5·27+6+7 = 148  ; 6·27 = 162 ; 148 ≤ 162? YES → n₀ = 3
    n = 10: f = 5·1000+20+7=5027; 6·1000=6000; 5027 ≤ 6000? YES
    Every n from 3 upward stays under the 6n³ budget → proof holds.

 TIME COMPLEXITY CALCULATION:
    - f(n) = 5n³ + 2n + 7.
      Lower-order vs dominant: (2n + 7)/n³ → 0 as n → ∞.
      Bound: 2n + 7 ≤ n³ for all n ≥ 3 → 5n³ + 2n + 7 ≤ 5n³ + n³ = 6n³.
      (Looser, always-safe: 5n³ + 2n³ + 7n³ = 14n³ for n ≥ 1 → c = 14, n₀ = 1.)
    - DROP: constant 5 and 2, 7 (lower-order) → dominant n³.
    → Time Complexity = O(n³).

 SPACE COMPLEXITY CALCULATION:
    - The verification routine allocates nothing: only n, f(n), c·g(n)
      values and a loop counter — a constant number of variables.
    → Space Complexity = O(1).

 APPROACH COMPARISON:
    ┌──────────────────────┬────────────────────┬───────────────────────────────┐
    │ Candidate bound      │ Constants          │ Verdict                       │
    ├──────────────────────┼────────────────────┼───────────────────────────────┤
    │ 6n³ (c=6, n₀=3)      │ tight, proven      │ ✓ O(n³) — every n≥3 under it  │
    │ 14n³ (c=14, n₀=1)    │ loose, always-safe │ ✓ O(n³) — simple one-liner    │
    │ 5n² (c=5)            │ wrong class        │ ✗ f grows like n³, not n²     │
    │ n³ (c=1, n₀=0)       │ too tight          │ ✗ fails for n≥1 (2n+7>0)     │
    └──────────────────────┴────────────────────┴───────────────────────────────┘
*/
#include <iostream>
using namespace std;
using ll = long long;

// f(n) = 5n³ + 2n + 7 — asal cost function
ll f(int n) { return 5LL * n * n * n + 2LL * n + 7; }

// budget c·g(n) = 6·n³ (g(n) = n³, c = 6)
ll cg(int n) { return 6LL * n * n * n; }

int main() {
    cout << "BIG-O PROOF TABLE: f(n) = 5n³ + 2n + 7  vs  c·g(n) = 6n³\n";
    cout << "Definition: ∃ c, n₀ > 0 : f(n) ≤ c·g(n)  ∀ n ≥ n₀\n\n";

    cout << "  n |   5n³+2n+7 |     6n³ | f ≤ 6n³?\n";
    cout << " ---+------------+---------+----------\n";
    int n0 = -1;                                // pehla passing row = n₀
    bool allAfter = true;                       // n₀ ke bad saari rows pass?
    for (int n = 1; n <= 12; n++) {
        bool ok = (f(n) <= cg(n));
        if (ok && n0 == -1) n0 = n;             // first passing row capture
        if (n0 != -1 && n >= n0 && !ok) allAfter = false;
        cout << " " << n << " | " << f(n) << " | " << cg(n);
        cout << " | " << (ok ? "YES" : "NO ") << "\n";
    }

    cout << "\n=> smallest n₀ = " << n0 << " (row " << n0
         << " se har n par 5n³+2n+7 ≤ 6n³)\n";
    cout << "=> ALL n ≥ n₀ pass? " << (allAfter ? "YES ✓" : "NO ✗")
         << "  (n₀ ke aage koi row fail nahi)\n";
    cout << "=> DROP constants (5,2,7) + lower order (2n,7): dominant = n³\n";
    cout << "=> f(n) = O(n³)   with c = 6, n₀ = " << n0 << "\n\n";

    cout << "LOOSE (always-safe) VERSION:\n";
    cout << "   5n³ + 2n + 7 ≤ 5n³ + 2n³ + 7n³ = 14n³  for n ≥ 1\n";
    cout << "   => c = 14, n₀ = 1 bhi kaam karta hai (loose bound)\n";
    cout << "   NOTE: dono c = 6 (tight) aur c = 14 (loose) O(n³) prove karte hain.\n";

    return 0;
}