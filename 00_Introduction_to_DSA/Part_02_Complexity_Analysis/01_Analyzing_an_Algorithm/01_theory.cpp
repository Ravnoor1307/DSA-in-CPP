/*
═══════════════════════════════════════════════
 ANALYZING AN ALGORITHM (Priori vs Posteriori)
═══════════════════════════════════════════════
 ⏱️ TOTAL TIME LOW: 0.00s · 0.10s max ... O(n)
 (concrete big-O derived fully below — never an unknown O(?))

 🌍 REAL-WORLD SCENARIO:
 You must cook dinner for 100 guests and you have two recipes. Before
 touching a single pan you read both recipes and *count* the bowls,
 chopping boards and minutes each step needs — that is Priori analysis
 (predicting on paper). After the party you also time yourself rebuilding
 the same dish with a stopwatch to see whether your prediction was right —
 that is Posteriori analysis (measuring on the actual machine). A smart
 chef does BOTH: predict first, then confirm with the clock. A great
 software engineer does exactly the same thing for an algorithm before
 trusting it with a million-item input.

 📖 THEORY: (pure English, formal)
 - definition: Analyzing an algorithm means systematically studying (1) how
   much TIME it will take, (2) how much SPACE/memory it will use, and
   (3) whether it always produces the CORRECT answer. There are precisely
   two ways to perform this study:
     • PRIORI analysis  — done BEFORE the program runs. We read the code,
       count the basic operations as a function of input size n, and write
       a formula f(n) = number of operations. It is machine-independent,
       works everywhere, and is what interviews ask you for.
     • POSTERIORI analysis — done AFTER the program runs. We execute the
       code on a real machine and measure wall-clock seconds with a
       stopwatch (chrono in C++). It is machine-dependent: the same code
       runs differently on a phone vs a supercomputer.
 - key points / properties:
   • Priori = analytical (exact count, reusable); Posteriori = empirical
     (real number, but only true on that one machine).
   • The three characteristics of an algorithm to analyze:
       1. TIME   — f(n) = number of basic operations (the Priori measure).
       2. SPACE  — how much extra memory beyond the input is used.
       3. CORRECTNESS — does the output always match the expected result?
   • Priori answers "how will this behave as n grows?"; Posteriori answers
     "how long did it actually take right now?".
 - when to use:
   • Use PRIORI whenever you compare algorithms on paper, in exams, in
     interviews, or before writing code for large constraints.
   • Use POSTERIORI when you must prove a real system meets a time budget
     (e.g. "must answer within 50 ms") on the actual production machine.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Write a helper that returns the maximum of an array.
         WHY: A max-finder is the smallest honest algorithm to analyze —
         one loop, one comparison per element, and a clear op count.
 Step 2: Count every comparison with an opCount++ inside the loop.
         WHY: Priori analysis needs a concrete number of basic operations;
         the counter makes the theory visible and checkable in the output.
 Step 3: Run the counter on a tiny array n=5.
         WHY: Small inputs let us hand-verify the formula f(n) = n - 1
         (4 comparisons for 5 elements) by reading the printout.
 Step 4: Run the same function on n = 1,000,000 inside chrono timers.
         WHY: Posteriori analysis measures real time on the real machine;
         large n shows the measured seconds instead of just a count.
 Step 5: Print predicted ops (n-1) side-by-side with actual opCount,
         then print the measured wall-clock time.
         WHY: The pairing proves the Priori prediction exactly equals the
         instrumented count, and the Posterioori timing is machine-specific.

 VISUAL WALKTHROUGH:

   PRIORI (before running — count on paper)
   ┌─────────────────────────────────────────────┐
   │ read the code → count how many times each line runs │
   │ loop: i=1..n-1  →  (n-1) iterations        │
   │ each: 1 comparison                          │
   │ f(n) = (n-1) + O(1)  →  O(n)               │
   └─────────────────────────────────────────────┘
                        │
                        ▼
   POSTERIORI (after running — measure with clock)
   ┌─────────────────────────────────────────────┐
   │ code chalao on real machine                 │
   │ chrono stop     →  1273 microseconds        │
   │ (this number is machine dependent)          │
   └─────────────────────────────────────────────┘

 DRY RUN: (full line-by-line trace for arr = {3, 9, 4, 7, 2}, n = 5)
   findMax(arr, 5, ops):
     ops = 0
     n <= 0? No (n = 5)      → continue
     maxV = arr[0] = 3
     loop i = 1 → i < 5
       i=1: ops=1; arr[1]=9 > 3  → maxV=9
       i=2: ops=2; arr[2]=4 > 9? NO
       i=3: ops=3; arr[3]=7 > 9? NO
       i=4: ops=4; arr[4]=2 > 9? NO
     loop ends (i=5 fails i<5)
     return maxV = 9
   Output:  max = 9   opCount = 4   (matches priori prediction n-1 = 4)
   n=1,000,000 run:  opCount = 999,999 and a measured time such as
   1,273 microseconds — the *count* is identical every machine, the
   *seconds* change from machine to machine.

 TIME COMPLEXITY CALCULATION:
   - findMax assigns maxV once                       → 1 step
   - loop runs for i = 1 to n-1, i.e. (n - 1) times.
     Inside each iteration exactly ONE comparison
     happens (`if (arr[i] > maxV)`)                 → (n - 1) steps
   - loop counter updates i++ run (n - 1) times     → (n - 1) steps
     (we fold these into the constant below since they are O(1) each)
   - Total  f(n) = 1 + (n-1) + (n-1) + 2 (return)  =  2n   (approx)
   - Drop the constant multiplier: since f(n) = 2n is bounded above by
     c·n with c=2 for all n ≥ 1, the dominant term is exactly n.
 → Time Complexity = O(n)     (one single pass, no nesting)

 SPACE COMPLEXITY CALCULATION:
   - Input array is passed as a pointer + n (const ref)  → O(1) extra
     (not counting the input storage itself)
   - Locals: maxV, i, opCount (caller's), return slot → 4 constants
   - No extra array, no recursion, no data structure allocated
   - Total extra memory = fixed number of variables, independent of n
 → Space Complexity = O(1)     (auxiliary space)

 APPROACH COMPARISON: (Priori vs Posteriori analysis)
 ┌──────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Aspect           │ PRIORI analysis              │ POSTERIORI analysis          │
 ├──────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ When             │ Before running the code      │ After running the code       │
 │ Method           │ Count operations by reading  │ Measure wall-clock time      │
 │                  │ the code: f(n) formula       │ with a stopwatch (chrono)    │
 │ Result           │ O(n) — a growth class, same  │ 1273 microseconds — a real   │
 │                  │ on every machine             │ number, only true on THIS box│
 │ Machine dependent│ No (pure maths)              │ Yes (CPU, cache, OS)         │
 │ Input dependent  │ Only on size n               │ Also on size n AND data      │
 │ When it shines   │ Exams, interviews, design    │ Real-time budgets, profiling │
 │ Weakness         │ Gives no "seconds"           │ Gives no general law         │
 └──────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// arr ka maximum return karta hai; har comparison opCount me count hota hai
int findMax(const int arr[], int n, int& opCount) {
    opCount = 0;
    if (n <= 0) {
        return -1;              // edge case: khaali/garbage input ka koi max nahi
    }
    int maxV = arr[0];          // pehla element ko abhi tak ka max maan lo
    for (int i = 1; i < n; i++) {
        opCount++;              // prioiri ka 1 basic operation — ek comparison
        if (arr[i] > maxV) {
            maxV = arr[i];      // bada element mila → max update karo
        }
    }
    return maxV;
}

int main() {
    // ---- PRIORI demo: chhota input, hand-verify karo ----
    int small[] = {3, 9, 4, 7, 2};
    int opsSmall = 0;
    int m1 = findMax(small, 5, opsSmall);
    cout << "n=5        : max=" << m1
         << "  opCount=" << opsSmall
         << "  (priori prediction: n-1 = 4)\n";

    // ---- POSTERIORI demo: bada input, chrono se time measure karo ----
    const int n = 1000000;
    int* big = new int[n];                  // heap pe n elements
    for (int i = 0; i < n; i++) {
        big[i] = (i * 7) % 1000;            // simple pseudo-random data
    }

    int opsBig = 0;
    int m2 = findMax(big, n, opsBig);              // pehla (untimed) call — max + count

    const int REPS = 500;                          // repeat calls taaki clock pe dikhe
    auto start = high_resolution_clock::now();     // stopwatch start
    for (int r = 0; r < REPS; r++) {
        big[0] = r;            // har call pe data badlo → compiler call ko hoist na kar paye
        int o2;
        findMax(big, n, o2);
    }
    auto stop = high_resolution_clock::now();      // stopwatch stop
    auto dur = duration_cast<microseconds>(stop - start).count();

    cout << "n=1000000  : max=" << m2
         << "  opCount=" << opsBig
         << "  (priori prediction: n-1 = 999999)\n";
    cout << "posteriori: " << REPS << " calls took " << dur
         << " us → avg " << (double)dur / REPS
         << " us/call (machine-specific)\n";

    // edge case check — empty array
    int opsEmpty = 0;
    int me = findMax(big, 0, opsEmpty);
    cout << "n=0        : max=" << me << "  opCount=" << opsEmpty
         << "  (edge case guarded)\n";

    delete[] big;
    return 0;
}