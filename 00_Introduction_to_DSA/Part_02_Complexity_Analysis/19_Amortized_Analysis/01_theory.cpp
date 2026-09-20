/*
═══════════════════════════════════════════════
 AMORTIZED ANALYSIS — The Average Cost Per Operation
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You are paying your hostel mess bill at the end of the month. Some days you
 eat only a ₹40 breakfast; one day of a friend's birthday party costs ₹2,000.
 If someone asks "how expensive is one meal?", an honest answer is not the ₹2,000
 peak (scary) and not the ₹40 cheapest (misleading). It is the AVERAGE: total
 money spent ÷ number of meals. That average — the cost spread evenly over every
 operation — is exactly what amortized analysis computes. A single push to a
 dynamic array can cost O(n) during a resize, but when we share that cost over
 the n cheap pushes that preceded it, each push is only O(1) on average.

 📖 THEORY: (formal English)
 - Definition: amortized cost of an operation over a sequence of m operations =
      ( total cost of all m operations ) / m
   We count the WHOLE sequence, not a single call in isolation.
 - Key idea: averaging. One expensive operation (a resize) gets "prepaid" by
   many cheap operations before it, so the per-operation cost stays constant.
 - Formal claim for dynamic arrays: for m pushes,
      total cost  ≤  m + (1 + 2 + 4 + ... + 2^(⌈log₂m⌉ − 1))     = m + (2^k − 1)
      where 2^k ≤ 2m   ⇒   total ≤ m + 2m = 3m   ⇒   amortized cost per push ≤ 3 = O(1)
   With capacity exactly doubled from 1, the copies follow the geometric series
   1, 2, 4, 8, ... which sums to just under 2·(largest term).

   ASCII diagram — capacity doubling:
      push #:    1    2    3   4    5   6   7   8    9   ...
      cap:       1 →  2 →  4     4 → 8        8    16
                ├┴┐  ├┴┐  ├┴┬┴┐  ├┴┬┴┬┴┬┴┐  ├┴┬┴┬┴┬┴─┴─┴─┐
      cost:      1   2   3   1   5   1   1   1    9    1 1 1 1 ...
      resize:    -   Y   Y   -   Y   -   -   -    Y    - ...
      The resizes (cost 2,3,5,9,...) are rare; the cheap 1s dominate;
      average stays ≈ 2.

 - When to use:
   * when a data structure has occasional expensive internal repairs
     (hash tables rehashing, dynamic arrays resizing, splay trees rotating)
   * when you need the cost of a SEQUENCE of operations, not one lucky call
   * to justify why `push_back` on std::vector is "O(1)" in practice

 🧠 LOGIC — STEP BY STEP:
 Step 1: Model the actual cost of one push.
         WHY: cheap push = 1 (write the element); resize push = n+1 (copy all old
         n elements, then write the new one). This is the work we must average.
 Step 2: Watch when resizes happen.
         WHY: with doubling, resizes happen at n = 1, 2, 4, 8, 16, ... — powers
         of two. They are LOG₂ m rare, not O(m) frequent.
 Step 3: Sum the copies: they form a geometric series 1+2+4+...+2^(k−1).
         WHY: geometric series have a magic closed form: sum = 2^k − 1 < 2^k ≤ 2m.
         One formula replaces the whole summation.
 Step 4: Divide by m.
         WHY: amortized = (m writes + ~2m copies) / m  ≈  3  =  O(1).

   Worked instance — m = 16 pushes, starting capacity 1:
       resize events: at push 2 (copy 1), push 3 (copy 2), push 5 (copy 4),
                      push 9 (copy 8)   →   copies = 1+2+4+8 = 15 < 16 = m
       total cost    = m + copies        = 16 + 15 = 31  ≤  2m  = 32
       amortized     = 31 / 16           ≈ 1.94  →  O(1)  ✔

 VISUAL WALKTHROUGH: (the exact table the demo prints)
   push | size | cap | cost | total | avg/push
   -----+------+-----+------+-------+----------
     1  |  1   |  1  |  1   |  1    | 1.00
     2  |  2   |  2  |  2   |  3    | 1.50   ← first resize (copy 1 + write)
     3  |  3   |  4  |  3   |  6    | 2.00   ← resize (copy 2 + write)
     4  |  4   |  4  |  1   |  7    | 1.75
     5  |  5   |  8  |  5   | 12    | 2.40   ← resize (copy 4 + write)
     6  |  6   |  8  |  1   | 13    | 2.17
    ... | ...  | ... | ... | ...   | ...
     9  |  9   | 16  |  9   | 24    | 2.67   ← resize (copy 8 + write)
    16  | 16   | 16  |  1   | 31    | 1.94   ← final avg ≈ 1.94 < 2
   Observations: the average NEVER explodes — resizes cost O(k) but only at
   powers of two; the cheap 1s dilute them.

 DRY RUN: (demo on top, 6 pushes only, line by line)
    cap starts 1, size 0, total 0.
    push 1: size(0) == cap(1)? NO → cost 1, size 1, total 1, avg = 1.00
    push 2: size(1) == cap(1)? YES → copy 1 (cost 1) + write (cost 1) = 2,
            cap → 2, size 2, total 3, avg = 1.50
    push 3: size(2) == cap(2)? YES → copy 2 + write = 3, cap → 4, size 3,
            total 6, avg = 2.00
    push 4: size(3) == cap(4)? NO  → cost 1, size 4, total 7, avg = 1.75
    push 5: size(4) == cap(4)? YES → copy 4 + write = 5, cap → 8, size 5,
            total 12, avg = 2.40
    push 6: size(5) == cap(8)? NO  → cost 1, size 6, total 13, avg = 2.17
    → average stays ≈ 2.0 (never crosses ~3) — that is the amortized O(1).

 TIME COMPLEXITY CALCULATION:
 - Cheap push cost:  1 write.
 - Resize push cost: COPY the existing n elements + 1 write = n + 1.
 - The copies over m pushes, with doubling from capacity 1, are exactly:
       1 + 2 + 4 + ... + 2^(k−1)   where 2^(k−1) is the largest power of two ≤ m.
     Geometric series formula:  1 + 2 + 4 + ... + 2^(k−1) = 2^k − 1  <  2^k  ≤  2m.
 - Total cost for m pushes:
       total  =  m writes  +  copies
              ≤  m + (2m − 1)     <  3m
 - Amortized cost per push:
       total / m  ≤  (3m) / m  =  3   →   O(1)   amortized.
   For the specific demo with m = 16: copies = 1+2+4+8 = 15 = 2·8 − 1 < 16;
   total = 16 + 15 = 31 ≤ 32 = 2m;  amortized = 31/16 ≈ 1.94 ≈ 2.
 - Compare worst single push: O(n) during a resize. Amortized across the
   sequence: O(1). Same data structure — different question asked.
 → Time Complexity = O(1) AMORTIZED per push (worst single push is still O(n)).

 SPACE COMPLEXITY CALCULATION:
 - Capacity doubles, so at any moment cap ≤ 2·size (after a resize cap = 2·size,
   and size only grows after that, halving the slack ratio).
 - Memory used = capacity  ≤  2n  =  O(n). At most ~2× the elements, wasted
   space ≤ n (the empty slots).
 - If we over-allocate by exactly 2×, the geometric doubling guarantees we
   never hold more than O(n) memory total.
 → Space Complexity = O(n)  (with a ≤ 2× slack factor)

 APPROACH COMPARISON: worst-case single push vs amortized cost
 ┌────────────────────┬──────────────────────────────────────────┬─────────────────────────────────────────┐
 │ Analytic approach  │ What it answers                          │ Result for push_back                  │
 ├────────────────────┼──────────────────────────────────────────┼─────────────────────────────────────────┤
 │ Worst case         │ cost of the single MOST expensive call    │ O(n) — one painful copy on every resize│
 │ Amortized          │ average cost over a long SEQUENCE         │ O(1) — the copies are spread out       │
 │ Aggregate method   │ total = m writes + (1+2+4+...+2^k−1) boxes │ ≤ 3m ⇒ per-op ≤ 3 ⇔ O(1)              │
 └────────────────────┴──────────────────────────────────────────┴─────────────────────────────────────────┘
 Lesson: never confuse "one call can be O(n)" with "the sequence is O(n)".
 Amortized analysis answers the right question for real-world usage.
*/

#include <iostream>
using namespace std;

int main(){
    int m;
    cout << "Dynamic array (vector::push_back) simulation — capacity doubling\n";
    cout << "Enter how many pushes to simulate (m): ";
    cin >> m;
    if(m <= 0){
        cout << "m must be positive. Using m = 16.\n";
        m = 16;
    }

    long long cap   = 1;              // capacity vector ke liye
    int size        = 0;              // kitne elements abhi andar hain
    long long total = 0;              // total cost

    cout << "\n push | size | cap | this cost | total | avg/push\n";
    cout << "------+------+-----+-----------+-------+----------\n";
    for(int i = 1; i <= m; i++){
        int cost = 1;                 // naya element insert karne ka cost

        if(size == cap){
            cost += size;             // resize: saare puraane elements copy karne hain
            cap *= 2;                 // capacity double karo (1→2→4→8→16...)
        }
        size++;
        total += cost;

        // financing accuracy: shaandaar avg value sirf jab i chhota ho
        double avg = (double)total / i;
        cout << " " << i << (i < 10 ? "   " : "  ")
             << " | " << size << (size < 10 ? "   " : "  ")
             << " | " << cap << (cap < 10 ? "   " : "  ")
             << " |   " << cost << (cost < 10 ? "     " : "    ")
             << " | " << total << (total < 10 ? "     " : "    ")
             << " | " << avg << "\n";
    }

    cout << "\n===== VERIFICATION =====" << endl;
    cout << "Total cost  = " << total << "   (m writes + copies)\n";

    // copies ka geometric sum: resize par copies 1,2,4,... jab tak (copy+1) <= m
    long long copies = 0;
    for(long long q = 1; q + 1 <= m; q *= 2) copies += q;   // 1+2+4+...+p = 2p-1
    long long p = 1;
    while(p * 2 + 1 <= m){ p *= 2; }          // sabse bada copy value p (p+1 <= m)
    cout << "Copies = 1+2+4+...+" << p << " = " << copies
         << "   (2·" << p << " − 1 = " << (2*p - 1) << ")\n";
    cout << "Geometric formula: 1+2+4+...+p = 2p−1 = " << (2*p - 1)
         << "  <  2p = " << (2*p) << "  ✔\n";
    cout << "Total = m writes + copies = " << m << " + " << copies
         << " = " << (m + copies) << "   (simulation total = " << total << ")\n";
    cout << "Total  ≤  3m?  " << total << " ≤ " << (3LL*m)
         << "  →  " << (total <= 3LL*m ? "TRUE ✔" : "check") << "\n";
    cout << "Amortized cost/push = total/m = " << total << "/" << m << " = "
         << ((double)total / m) << "  ≈  2  →  O(1) amortized  ✔\n";

    // ===== EDGE CASES =====
    cout << "\n===== EDGE CASES =====" << endl;
    // (1) sirf 1 push
    {
        long long c = 1, s = 0, t = 0;
        for(int i = 1; i <= 1; i++){
            int cost = 1;
            if(s == c){ cost += s; c *= 2; }
            s++; t += cost;
        }
        cout << "m = 1  →  cost " << t << ", avg " << (double)t << "  (no resize needed)\n";
    }
    // (2) m = power of two wala exact case
    {
        long long c = 1, s = 0, t = 0;
        int M = 8;
        for(int i = 1; i <= M; i++){
            int cost = 1;
            if(s == c){ cost += s; c *= 2; }
            s++; t += cost;
        }
        cout << "m = " << M << "  →  total " << t
             << "  =  m + (1+2+4) = 8 + 7  ≤  2m = 16   →  avg " << (double)t/M << "\n";
    }
    return 0;
}