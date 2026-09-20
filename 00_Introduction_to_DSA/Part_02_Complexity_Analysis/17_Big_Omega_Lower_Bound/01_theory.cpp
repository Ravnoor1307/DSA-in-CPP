/*
═══════════════════════════════════════════════
 BIG OMEGA (LOWER BOUND) — Ω Notation
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You order a parcel and the courier promises: "Delivery will NOT take fewer than
 2 days." That 2-day floor is a guaranteed minimum — the parcel can never arrive
 faster. It may take 2 days, 4 days, or 7 days, but it surely cannot be quicker
 than the floor. Big Omega is exactly this courier guarantee: it tells us the
 minimum growth rate the running time can never drop below. Every run, however
 lucky the input, must spend at least a certain amount of work — no algorithm can
 cheat below its own floor.

 📖 THEORY: (formal English)
 - Formal definition:
      f(n) = Ω(g(n))   ⟺   ∃ c > 0, ∃ n₀ ≥ 0  such that  f(n) ≥ c·g(n)  ∀ n ≥ n₀
   Read: "f(n) grows at least as fast as g(n), up to a constant factor c."
 - Intuition: g(n) is a CEILING for Big-O but is a FLOOR here. Ω(g(n)) means
   g(n) is a guaranteed lower bound — a line under which f(n) can never dip once
   we pass n₀.
 - "Best-case-ish" meaning: Big-Omega is a LOWER BOUND, so it pairs naturally
   with the best case. If even the luckiest input must do ≥ Ω(g(n)) work, then
   the bound holds for every input of the algorithm.
 - Trivial lower bound: any real algorithm must do at least ONE operation, so
   f(n) ≥ 1·1 for all n ≥ 1  ⟹  f(n) = Ω(1) ALWAYS holds. It is weak but true.
 - Example — Linear Search: even if the key sits at index 0, we still perform
   1 comparison before returning. For the worst input the key is absent and we
   do all n comparisons. n ≥ 1·n with c = 1, so T(n) = n = Ω(n).

   ASCII diagram — the floor line:
       f(n)
      |            f(n) = n  (actual work line)
      |          /
      |        /    ←  c·g(n) = 1·n  is ALWAYS ≤ f(n)   (here they coincide)
      |      /                     so the line "n" is a valid FLOOR
      |    /
      |  /
      +---------------------------- n
      n₀ = 0       f(n) ≥ c·g(n)  for all n ≥ n₀   ✔

 - When to use:
   * proving "no algorithm for this problem can ever be faster than X" (problem lower bounds)
   * stating the guaranteed minimum cost of an algorithm
   * combining with Big-O to derive Big-Theta (tight bound)

 🧠 LOGIC — STEP BY STEP:
 Step 1: Pick a candidate g(n) that you believe sits BELOW f(n).
         WHY: we must find some line that f(n) never falls under (after scaling).
 Step 2: Choose a constant c > 0 and a threshold n₀.
         WHY: Big-Omega only cares about a SCALED comparison beyond some point;
         the first few small n are irrelevant.
 Step 3: Verify f(n) ≥ c·g(n) for every n ≥ n₀, by algebra or induction.
         WHY: the inequality must hold forever after n₀, not just at one point.
 Step 4: Declare f(n) = Ω(g(n)).
         WHY: now everyone knows the guaranteed minimum growth of the algorithm.

   Worked instance — f(n) = n, g(n) = n:
     choose c = 1, n₀ = 0   →    n ≥ 1·n   →   n ≥ n   ALWAYS EQUAL  ✔  ⟹ n = Ω(n)
   The trivial floor — f(n) = n, g(n) = 1:
     choose c = 1, n₀ = 1   →    n ≥ 1·1   →   n ≥ 1   TRUE for all n ≥ 1   ✔  ⟹ n = Ω(1)

 VISUAL WALKTHROUGH: (linear search — best case per array size n)
   n = 5:  arr = [5, 9, 2, 7, 1],  key = 5 (lucky, at index 0)

     step 1:  compare arr[0] == 5  →  MATCH  →  STOP
     → work done = exactly 1 comparison (never 0 for a non-empty search)
   For the WORST input the key is absent → all 5 comparisons are forced.
   Conclusion: comparisons ≥ 1 for ANY input  ⟹  Ω(1) floor always true.
              comparisons = n for the worst input  ⟹  Ω(n) meaningful bound.

   Dynamic example (what the demo verifies row by row):
     n   | f(n) = n | c·g(n) = 1·n |  f(n) ≥ c·g(n) ?
     ----|----------|--------------|-----------------
      1  |    1     |      1       |   TRUE (equal)
      2  |    2     |      2       |   TRUE (equal)
      3  |    3     |      3       |   TRUE (equal)
     ... |   ...    |     ...      |   TRUE every single row
   All rows TRUE ⟹ n ≥ 1·n for every n ≥ 0 ⟹ f(n) = n is Ω(n) with c=1, n₀=0.

 DRY RUN: (demo on top, line by line)
   • DEMO 1 starts, prints header "f(n) = n vs c·g(n) = 1·n".
   • For n = 1: computes f = 1, cg = 1*1 = 1 → 1 >= 1 TRUE → prints "TRUE (equal)".
   • For n = 2: f = 2, cg = 2 → TRUE. ... continues till n = 12.
   • allTrue stays true → prints "f(n)=n IS Ω(n)".
   • DEMO 2 runs same check with c = 0.5 → 2n ≥ n obviously TRUE for every n.
   • DEMO 3 (trivial floor): for array sizes n = 1..10 the BEST-case comparison
     count is always exactly 1  →  1 ≥ 1·1  →  Ω(1) holds for every size.
   • DEMO 4: worst case for n = 10 → 10 comparisons → line "worst = n ≥ 1·n = Ω(n)".

 TIME COMPLEXITY CALCULATION:
 - Linear search, WORST case: the key is absent → all n slots are compared.
     comparisons = n.  Show Ω:
        f(n) = n,  g(n) = n,  c = 1,  n₀ = 0
        n ≥ 1·n   →   n ≥ n    is TRUE for every n ≥ 0   ✔ (constant equality)
     Since the two sides are equal forever, this is a TIGHT lower bound.
     (Any c with 0 < c ≤ 1 also works — infinitely many constants; we need one.)
 - Linear search, BEST case: the key is at index 0 → exactly 1 comparison.
        f(n) = 1 ≥ 1·1  with c = 1, n₀ = 1   ⟹   best case = Ω(1), really Θ(1)
 - Trivial floor for the whole algorithm: comparisons ≥ 1 for every n ≥ 1
        f(n) ≥ 1·1  ⟹  T(n) = Ω(1)  (always correct, but a weak statement)
   n   |   f(n) = n     |   c·g(n) = 1·n    |  n ≥ n ✔
   0   |       0        |         0         |   TRUE
   5   |       5        |         5         |   TRUE
   100 |      100       |        100        |   TRUE
 → Time Complexity = Ω(1) trivial floor; tight meaningful bound for the worst
   branch is Ω(n)  (in fact the reassures with best-case = Θ(1)).

 SPACE COMPLEXITY CALCULATION:
 - Linear search uses only a loop index i and stores the key; no extra array,
   no recursion stack, no hashing table.
 - Auxiliary space = constants only = c·1  →  O(1)
 → Space Complexity = O(1)

 APPROACH COMPARISON: the same function f(n) = n judged by all three notations
 ┌──────────────┬──────────────────────────────┬───────────────────────────┬────────────────────────────┐
 │ Notation     │ Definition (formal)          │ Meaning for f(n)=n        │ Valid statements           │
 ├──────────────┼──────────────────────────────┼───────────────────────────┼────────────────────────────┤
 │ Big-O        │ f(n) ≤ c·g(n)  (upper bound) │ n grows at most linearly  │ O(n) ✔  (loose: O(n²) also)│
 │ Big-Omega Ω  │ f(n) ≥ c·g(n)  (lower bound) │ n grows at least linearly │ Ω(n) ✔  (loose: Ω(1) also) │
 │ Big-Theta Θ  │ c₁·g ≤ f ≤ c₂·g (tight)     │ n grows EXACTLY linearly  │ Θ(n) ✔  (only this)       │
 └──────────────┴──────────────────────────────┴───────────────────────────┴────────────────────────────┘
 Validity rule: Ω(n²) is False; Ω(n) True; Ω(1) True — a LOWER bound admits
 slower-growing functions. Θ nails down that f behaves exactly like n.
*/

#include <iostream>
using namespace std;

// linear search: key dhundo, comparisons count karte hue
int linearSearch(int arr[], int n, int key, int &comparisons){
    for(int i = 0; i < n; i++){
        comparisons++;                    // ek comparison: arr[i] == key
        if(arr[i] == key)
            return i;                     // mil gaya → turant return
    }
    return -1;                            // pura array dekh liya, nahi mila
}

int main(){
    // ====== DEMO 1: verify f(n)=n ≥ c·g(n) with c=1, g(n)=n ======
    cout << "===== DEMO 1: f(n)=n  vs  c·g(n)=1·n  (c=1, n0=0) =====\n";
    cout << " n | f(n)=n | c·g(n)=1·n | f(n) >= c·g(n) ?\n";
    cout << "---+--------+------------+----------------\n";
    bool allTrue = true;
    for(int n = 0; n <= 12; n++){
        int f  = n;                    // yahan f(n) = n
        int cg = 1 * n;                // c·g(n) = 1·n
        bool ok = (f >= cg);
        if(!ok) allTrue = false;
        cout << " " << n << " |   " << f << "    |     " << cg << "      |  "
             << (ok ? "TRUE (equal)" : "FALSE") << "\n";
    }
    cout << "\nResult: har row TRUE → n >= 1·n  ∀ n ≥ 0"
         << (allTrue ? "  →  f(n)=n IS Ω(n)" : "  →  NOT Ω(n)") << "\n\n";

    // ====== DEMO 2: c = 1/2 bhi kaam karta hai (2n >= n) ======
    cout << "===== DEMO 2: same check with c = 0.5  (verify 2n >= n) =====\n";
    bool okHalf = true;
    for(int n = 0; n <= 12; n++){
        if( (double)n < 0.5 * n ){      // n ≥ 0.5n   ⇔   n ≥ 0, hamesha true
            okHalf = false;
            break;
        }
    }
    cout << "2n >= n for all n ≥ 0  →  " << (okHalf ? "TRUE" : "FALSE")
         << "   →  n = Ω(n) with c = 0.5 bhi chalta hai\n\n";

    // ====== DEMO 3: trivial floor Ω(1) — best case always ≥ 1 cmp ======
    cout << "===== DEMO 3: TRIVIAL LOWER BOUND Ω(1) — best-case comparisons =====\n";
    cout << " n | best-case comparisons | 1 (c·g(n)) | >= 1 ?\n";
    cout << "---+----------------------+-------------+-------\n";
    bool trivial = true;
    for(int n = 1; n <= 10; n++){
        int key = 0;                     // key = arr[0] rakhte hain → lucky input
        int cmp = 0;
        int arr[10];
        for(int i = 0; i < n; i++) arr[i] = i;
        linearSearch(arr, n, key /* = arr[0] */, cmp);
        if(cmp < 1) trivial = false;     // 1 se kam comparison impossible
        cout << " " << n << " |          " << cmp
             << "          |     1      |  " << (cmp >= 1 ? "TRUE" : "FALSE") << "\n";
    }
    cout << "\nHar non-empty search ≥ 1 comparison → "
         << (trivial ? "f(n) = Ω(1) ALWAYS  ✔" : "ERROR") << "\n\n";

    // ====== DEMO 4: worst case = n comparisons → Ω(n) ======
    cout << "===== DEMO 4: WORST case of linear search = n comparisons =====\n";
    int n  = 10, key = 999, cmp = 0;
    int arr[10];
    for(int i = 0; i < n; i++) arr[i] = i;
    linearSearch(arr, n, key, cmp);   // key absent → n comparisons
    cout << "n = " << n << ", comparisons = " << cmp
         << "  →  " << cmp << " >= 1·" << n
         << "  →  " << (cmp >= n ? "TRUE: T(n) = Ω(n)  ✔" : "FALSE")
         << "\n\n";

    cout << "===== SUMMARY =====\n";
    cout << "Ω(1)   : trivial floor (har algorithm karta hai ≥ 1 kaam)\n";
    cout << "Ω(n)   : tight lower bound of linear search (worst hai n comparisons)\n";
    cout << "Best-case = 1 comparison = Θ(1); worst-case = n = O(n) AND Ω(n)\n\n";

    // ====== EDGE CASE CHECK: n = 0 (empty array) ======
    cout << "===== EDGE CASE: n=0 (khali array) =====\n";
    int cmp0 = 0;
    int idx0 = linearSearch(arr, 0, 5, cmp0);   // 0 size → koi comparison nahi
    cout << "size 0 → comparisons = " << cmp0 << ", return = " << idx0
         << "\nDhyan do: Ω(1)/Ω(n) baatein n≥1 ke liye; n=0 par loop hi chal nahi sakta.\n";
    return 0;
}