/*
═══════════════════════════════════════════════
 AMORTIZED ANALYSIS — PROBLEM SET
 File purpose: simulate a dynamic-array push sequence, prove amortized O(1)
 via the geometric series, design your own doubling strategy, and contrast
 worst-case vs amortized reasoning.
═══════════════════════════════════════════════

 Every proof must show the full math: total cost = cheap + resize, then
 division by m. No bare "O(1)".
═══════════════════════════════════════════════
*/

#include <iostream>
using namespace std;

// simulate push_back with the given strategy: returns total cost, prints table
// costPush: pure cost of one cheap push. resizeMultiplier: growth factor.
long long simulate(int m, int strategy, long long &totalOut){
    long long cap   = 1;
    int size        = 0;
    long long total = 0;
    cout << "   push | size | cap | cost | total\n";
    cout << "   -----+------+-----+------+------\n";
    for(int i = 1; i <= m; i++){
        int cost = 1;
        if(size == cap){
            // growth strategy:
            // 1 → double capacity  (classic vector)
            // 2 → grow by +1 every time (append-only, terrible)
            // 3 → grow by +5 every time (naive chunking)
            if(strategy == 1)      { cost += size; cap *= 2; }
            else if(strategy == 2) { cost += size; cap += 1; }
            else if(strategy == 3) { cost += size; cap += 5; }
        }
        size++;  total += cost;
        cout << "   " << i << (i < 10 ? "    |" : "   |") << "  "
             << size << "   | " << cap << (cap < 10 ? "   |" : "  |")
             << " " << cost << (cost < 10 ? "    |" : "   |")
             << " " << total << "\n";
    }
    totalOut = total;
    return total;
}

// ================================================================
// TASK 1 — SIMULATE doubling from size 1 and COMPUTE amortized cost
// ================================================================
// 💡 HINT:
//    Run simulate(m,1,...) with m = 16. Then:
//      copies = 1+2+4+8 = 15  (geometric, from the resize columns)
//      total  = m + copies = 16 + 15 = 31
//      amortized = total / m = 31/16 ≈ 1.94  →  O(1)
//    Check: 31 ≤ 2m = 32 — the upper bound holds in the demo.
// ✏️ STARTER CODE:
//    // long long t = 0;
//    // simulate(16, 1, t);
//    // print total, then copies (2*p-1) and t/m value
void solveTask1(){
    cout << "[Task 1] Simulate 16 pushes, doubling capacity (strategy 1)\n";
    long long t = 0;
    simulate(16, 1, t);
    cout << "   ---- analysis ----\n";
    // geometric sum: largest power ≤ 16 is 8, so 1+2+4+8 = 15
    long long p = 1; while(p * 2 <= 16) p *= 2;
    cout << "   copies  = 1+2+4+...+" << p << " = " << (2*p - 1) << endl;
    cout << "   total   = m + copies = 16 + " << (2*p-1) << " = " << t << endl;
    cout << "   amortized = " << t << "/16 = " << (double)t/16.0
         << "  ≤ 2 m/m  = O(1)   ✔ PROVEN\n\n";
    // edge: prove inequality explicitly
    cout << "   check: 1+2+4+8 = " << (2*p-1) << " < 2·" << p << " = " << (2*p) << "  ✔\n\n";
}

// ================================================================
// TASK 2 — WHY +1 (append-only) growth is O(n) amortized
// ================================================================
// 💡 HINT:
//    Strategy 2 grows capacity by 1 each time — that means EVERY single push
//    is a copy of everything! With m pushes:
//      cost of push i = 1 + (i − 1)  =  i   (copy all previous elements)
//      total = 1 + 2 + 3 + ... + m   =  m(m+1)/2
//      amortized = total / m         =  (m+1)/2  =  Θ(m)
//    That's why vectors use doubling and NOT append-only allocation.
//    Code: simulate(m,2,...) with m = 8 will show the SUM rising fast.
// ✏️ STARTER CODE:
//    // long long t2 = 0; simulate(8, 2, t2);
//    // print 1+2+3+4+5+6+7+8-formula: m*(m+1)/2 and t2/m
void solveTask2(){
    cout << "[Task 2] Append-only growth (+1 per push, strategy 2)\n";
    long long t2 = 0;
    simulate(8, 2, t2);
    long long m = 8;
    cout << "   total = 1+2+...+8   = m(m+1)/2 = " << m*(m+1)/2 << "   (matches " << t2 << ")\n";
    cout << "   amortized = total/m = " << (double)t2/m << "   →  Θ(m)  \n";
    cout << "   (m+1)/2 grows with m — NOT constant! Never do this.\n\n";
}

// ================================================================
// TASK 3 — DESIGN your doubling trigger: 2x vs 1.5x vs +5-chunks
// ================================================================
// 💡 HINT:
//    1.5× growth still amortizes to O(1) because capacity = 1.5^k grows
//    geometrically — copy cost = (1.5)^k single geometric series. The chunked
//    +5 strategy, however, resizes every 5th push forever and each copy is O(n),
//    so amortized = Θ(n) again. Use simulate with strategy 3 and m = 12 to see
//    the resizing each 5th push. Conclude: any GEOMETRIC growth (factor > 1)
//    is amortized O(1), any ADDITIVE growth is Θ(n).
// ✏️ STARTER CODE:
//    // long long t3 = 0; simulate(12, 3, t3);
//    // print the summarizing sentence about geometric vs additive
void solveTask3(){
    cout << "[Task 3] +5 chunks (strategy 3) — additive growth\n";
    long long t3 = 0;
    simulate(12, 3, t3);
    cout << "   resize happens EVERY 5th push (size hits cap) forever\n";
    cout << "   copies are O(n) each → amortized Θ(n)  (not constant)\n";
    cout << "   Only GEOMETRIC growth (2×, 1.5×) keeps amortized O(1).\n\n";
}

// ================================================================
// TASK 4 — Worst-case vs amortized: the interview argument
// ================================================================
// 💡 HINT:
//    Answer in two steps:
//      (1) single-worst call: the i-th push when i is a power of two costs
//          i+1 (copy + write) → single worst case = O(n).
//      (2) sequence total: m writes + (1+2+4+...+2^k−1) ≤ m + 2m = 3m →
//          per-push ≤ 3 → amortized O(1).
//    The demo: simulate m = 20, print the single most expensive row's cost
//    (should be the power-of-two pushes like 17 → 17) and the average row.
// ✏️ STARTER CODE:
//    // long long t4 = 0; simulate(20, 1, t4);
//    // find the max single cost in a loop (they occur at powers of two)
//    // then print amortized = t4/20 and both conclusions
void solveTask4(){
    cout << "[Task 4] Worst single push vs amortized over 20 pushes\n";
    long long t4 = 0;
    simulate(20, 1, t4);
    // recompute max cost quickly (pure math): max at push = 17 (power of two)
    long long cap = 1, sz = 0, maxCost = 0;
    for(int i = 1; i <= 20; i++){
        int cost = 1;
        if(sz == cap){ cost += sz; cap *= 2; }
        if(cost > maxCost) maxCost = cost;
        sz++;
    }
    cout << "   single worst push = " << maxCost << "   →  O(n) single call\n";
    cout << "   amortized = " << t4 << "/20 = " << (double)t4/20.0
         << "   →  O(1) over the sequence\n";
    cout << "   ⇒ 'worst-case O(n)' and 'amortized O(1)' are BOTH true.\n";
}

int main(){
    cout << "============ AMORTIZED ANALYSIS PROBLEM SET ============\n\n";
    solveTask1();
    solveTask2();
    solveTask3();
    solveTask4();
    return 0;
}