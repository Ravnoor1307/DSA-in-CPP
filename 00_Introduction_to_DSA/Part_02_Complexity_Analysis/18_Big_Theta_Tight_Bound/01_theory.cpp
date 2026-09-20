/*
═══════════════════════════════════════════════
 BIG THETA (TIGHT BOUND) — Θ Notation
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You ask a bakery how long a batch of cookies takes. The honest answer is an
 exact window: "it can't be faster than 20 minutes and can't be slower than
 30 minutes — baked between these two bounds." That is Big Theta: BOTH a floor
 and a ceiling around the true value, so the true time is "sandwiched" inside
 a known band. Big-O alone would only say "at most 30 minutes" (useless if a
 batch ever takes 5...). Big-Theta pins the true cost down: the algorithm
 behaves EXACTLY like g(n), within constant factors on both sides.

 📖 THEORY: (formal English)
 - Formal definition:
      f(n) = Θ(g(n))  ⟺  ∃ c₁ > 0, ∃ c₂ > 0, ∃ n₀ ≥ 0
                          such that  c₁·g(n) ≤ f(n) ≤ c₂·g(n)  ∀ n ≥ n₀
   In other words: f is simultaneously O(g(n)) (upper) AND Ω(g(n)) (lower)
   with the SAME g(n). The two bounds can differ by constants only.
 - Intuition: the true curve of f(n) is trapped between two scaled copies of
   g(n). Once n ≥ n₀, f never breaks out of the sandwich.
 - Example — Linear Search: at the END (worst case) it does exactly n
   comparisons. c₁·n ≤ n ≤ c₂·n is true with c₁ = 1, c₂ = 1, n₀ = 1 ⇒ Θ(n).
 - Example — f(n) = n² + 3n is Θ(n²):
      lower:  n² + 3n ≥ 1·n²   trivially (3n ≥ 0)     → c₁ = 1, TRUE for all n
      upper:  n² + 3n ≤ 2·n²   ⟺  3n ≤ n²   ⟺  n ≥ 3  → c₂ = 2, n₀ = 3
   So with c₁=1, c₂=2, n₀=3 the sandwich holds ⇒ Θ(n²).

   ASCII diagram — the sandwich:
       f(n)
      |  c₂·g(n) = 2·n²   ─────────────────────  (upper slice)
      |                    /   f(n) = n² + 3n    (true curve, inside)
      |                   /
      |  c₁·g(n) = 1·n²  ────────────────────────∎ (lower slice)
      |                  /
      +------------------------------ n
      n₀ = 3         for every n ≥ 3 :  1·n² ≤ n²+3n ≤ 2·n²   ✔

 - When to use:
   * when you want the EXACT growth class (analyse tight bounds, not loose ones)
   * as the standard way to compare two algorithms of equal class
   * in recurrence theorems (Master method) which output Θ directly

 🧠 LOGIC — STEP BY STEP:
 Step 1: Guess the tight class g(n) (usually the dominant term).
         WHY: the fastest-growing term decides the whole story.
 Step 2: Prove the LOWER side f(n) ≥ c₁·g(n) (an Ω proof).
         WHY: without a floor the sandwich collapses.
 Step 3: Prove the UPPER side f(n) ≤ c₂·g(n) (an O proof).
         WHY: without a ceiling we only have Ω, not Θ.
 Step 4: Merge: same g(n) with both sides ⇒ Θ(g(n)).
         WHY: that is exactly the definition of a tight bound.

   Worked instance — f(n) = n² + 3n:
     lower  : n² + 3n ≥ n²  →  need 3n ≥ 0  →  TRUE ∀ n ≥ 1  → c₁ = 1, n₀ = 1
     upper  : n² + 3n ≤ 2n² →  need n² ≥ 3n → n ≥ 3          → c₂ = 2, n₀ = 3
     combined c₁=1, c₂=2, n₀=3   ⇒   f(n) = Θ(n²)

 VISUAL WALKTHROUGH: (the sandwich table the demo prints)
   n   |  c₁·n²  |  f(n)=n²+3n   |  c₂·n²  |  c₁g ≤ f ≤ c₂g ?
  -----|---------|---------------|---------|-------------------
    1  |    1    |       4       |    2    |    4 ≤ 2? FALSE
    2  |    4    |      10       |    8    |   10 ≤ 8? FALSE
    3  |    9    |      18       |   18    |   9 ≤ 18 ≤ 18 TRUE
    4  |   16    |      28       |   32    |   16 ≤ 28 ≤ 32 TRUE
    ...|   ...   |      ...      |   ...   |   TRUE from here on
   Only n=1 and n=2 violate the upper slice; from n₀=3 onwards every row is TRUE.

 DRY RUN: (what the demo actually prints, 6 rows)
   for n = 3:  f = 3*3 + 3*3 = 18;   lower = 2*3*3 = 18? No — 1*9 = 9;   upper = 2*9 = 18.
   9 ≤ 18 ≤ 18  → TRUE
   for n = 6:  f = 36 + 18 = 54;   lower = 36;  upper = 72;  36 ≤ 54 ≤ 72 → TRUE
   for n = 10: f = 100 + 30 = 130; lower = 100; upper = 200;  100 ≤ 130 ≤ 200 → TRUE
   Every row ≥ 3 succeeds → print "Θ(n²) PROVEN".

 TIME COMPLEXITY CALCULATION:
 - Linear search, worst case: T(n) = n comparisons.
     c₁·n ≤ n ≤ c₂·n   with c₁ = 1, c₂ = 1, n₀ = 1   →  equal on all sides
     ⇒ linear search worst case = Θ(n). Best case = 1 = Θ(1).
 - Quadratic example f(n) = n² + 3n:
     Lower (Ω):  n² + 3n ≥ c₁·n²  →  choose c₁ = 1 → need 3n ≥ 0, TRUE for n ≥ 1.
     Upper (O):  n² + 3n ≤ c₂·n²  →  choose c₂ = 2 → need 3n ≤ n²,  TRUE for n ≥ 3.
     So ∃ c₁=1, c₂=2, n₀=3 ⇒ 1·n² ≤ n²+3n ≤ 2·n² for all n ≥ 3 ⇒ Θ(n²).
 - Therefore:  T(n) = Θ(n²)  — the 3n term is a lower-order correction.
   n   | 1·n² | n²+3n | 2·n² | sandwich?
   3   |  9   |  18   | 18   |  yes (touch upper)
   4   | 16   |  28   | 32   |  yes
   5   | 25   |  40   | 50   |  yes
   10  | 100  | 130   | 200  |  yes
   All n ≥ 3 rows TRUE → Θ(n²) ✔
 → Time Complexity = Θ(n²) for f(n)=n²+3n, Θ(n) worst for linear search.

 SPACE COMPLEXITY CALCULATION:
 - All examples use a couple of loop counters and one key variable; no extra
   arrays, no recursion, so the auxiliary space is constant.
 - aux = c·1   →   Space = Θ(1)  (tight: you literally can't do it in negative
   space, the constants are fixed regardless of n).
 → Space Complexity = Θ(1)

 APPROACH COMPARISON: f(n) = n² + 3n in all three notations
 ┌──────────────┬──────────────────────────────┬───────────────────────────────┬──────────────────────────────┐
 │ Notation     │ What it promises             │ For f(n)=n²+3n                 │ Is it tight?                │
 ├──────────────┼──────────────────────────────┼───────────────────────────────┼──────────────────────────────┤
 │ O(n²)        │ an upper bound               │ TRUE (with c₂=2, n₀=3)         │ tight-ish (but O(n³) also T)│
 │ Ω(n²)        │ a lower bound                │ TRUE (with c₁=1, n₀=1)         │ tight-ish (but Ω(n) also T) │
 │ Θ(n²)        │ BOTH bounds agree            │ TRUE (c₁=1, c₂=2, n₀=3)        │ EXACT — nothing else needed │
 └──────────────┴──────────────────────────────┴───────────────────────────────┴──────────────────────────────┘
 The lesson: Θ is the "precise" label; the other two either forget a floor
 or overstate a ceiling.
*/

#include <iostream>
using namespace std;

int main(){
    // ===== DEMO 1: sandwich n^2 <= n^2 + 3n <= 2 n^2 for n >= 3 =====
    cout << "===== DEMO 1: verify 1·n^2 <= f(n)=n^2+3n <= 2·n^2 for n >= 3 =====\n";
    cout << " n | c1·n^2 | f(n)=n^2+3n | c2·n^2 | c1·n^2 <= f <= c2·n^2 ?\n";
    cout << "---+--------+-------------+--------+------------------------\n";
    bool allHold = true;
    for(int n = 1; n <= 15; n++){
        long long lower = 1LL*n*n;      // c1·g(n) = 1·n^2
        long long f     = 1LL*n*n + 3LL*n;   // f(n) = n^2 + 3n
        long long upper = 2LL*n*n;      // c2·g(n) = 2·n^2
        bool ok = (lower <= f && f <= upper);
        if(!ok) allHold = false;
        cout << " " << n << " |   " << lower << "   |      " << f
             << "       |   " << upper << "   |  "
             << (ok ? "TRUE" : "FALSE") << "\n";
    }
    cout << "\nDerivation:\n";
    cout << "  lower side: n^2+3n >= 1·n^2  ⟺  3n >= 0  →   TRUE for all n ≥ 1\n";
    cout << "  upper side: n^2+3n <= 2·n^2  ⟺  3n <= n^2 → TRUE for all n ≥ 3\n";
    cout << "  Therefore with c1=1, c2=2, n0=3 the sandwich holds"
         << (allHold ? "  →  f(n) = Θ(n^2) PROVEN ✔" : "  ✗ mismatch") << "\n\n";

    // ===== DEMO 2: show n=1,2 are the ONLY violating rows (edge cases) =====
    cout << "===== DEMO 2: edge cases — n=1 and n=2 break the upper slice =====\n";
    for(int n = 1; n <= 2; n++){
        long long f = 1LL*n*n + 3LL*n;
        long long upper = 2LL*n*n;
        cout << "  n = " << n << ":  f = " << f << ",  upper 2·n^2 = " << upper
             << "   →  " << (f <= upper ? "OK" : "VIOLATION (f > c2·g)") << "\n";
    }
    cout << "  This is WHY n0 matters: the bound is only guaranteed from n0 onwards.\n\n";

    // ===== DEMO 3: linear search worst case = exactly n → Θ(n) =====
    cout << "===== DEMO 3: linear search worst case (key absent) = Θ(n) =====\n";
    for(int n = 1; n <= 8; n++){
        int arr[10];
        for(int i = 0; i < n; i++) arr[i] = i;
        int cmp = 0, key = 1000;              // absent key → full scan
        for(int i = 0; i < n; i++){ cmp++; if(arr[i] == key) break; }
        cout << "   n = " << n << "  →  comparisons = " << cmp
             << "   (" << (cmp == n ? "n ✔" : "??") << ")   Θ(n) confirmed\n";
    }
    cout << "  Best case (key at index 0) = 1 comparison = Θ(1).\n\n";

    cout << "===== SUMMARY =====\n";
    cout << "f(n) = n^2+3n  is Θ(n^2) because 1·n^2 ≤ n^2+3n ≤ 2·n^2 for n ≥ 3.\n";
    cout << "Linear search: best Θ(1), worst Θ(n) — exact growth both ways.\n";
    cout << "Θ = O AND Ω with the SAME g(n); the bounds only differ by c1, c2.\n";
    return 0;
}