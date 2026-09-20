/*
═══════════════════════════════════════════════
 COMMON TIME COMPLEXITIES — Quick Reference
 (O(1) ... O(n!), real algorithms + analogies)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    A village post office must handle n parcels every morning. The clerk
    memorizes eight ways the work can scale:
      O(1) — the boss walks in and the clerk already knows where everything is
             (one glance, however many parcels).
      O(log n) — find one parcel in the alphabetized ledger by tearing the
             book in half, again and again.
      O(n) — read the arrival list top to bottom, once.
      O(n log n) — sort the shelves by splitting the pile in halves and merging
             sorted halves back together.
      O(n²) — compare every parcel against every other parcel for a school
             project on weights.
      O(n³) — test every triple of parcels from three shelves.
      O(2ⁿ) — list every possible subset of the parcels.
      O(n!) — try every possible ordering of the parcels on the truck.
    The lesson the clerk learns: the same n bytes of work can explode into
    microseconds or into millennia — everything depends on WHICH shape the
    loop takes. This cheat-sheet turns loop shapes into complexity classes.

 📖 THEORY: (pure English, formal)
    - Each class bounds the number of operations f(n) an algorithm performs on
      an input of size n, up to a constant factor, for large n.

    ┌──────────┬───────────────────────────────┬───────────────────────────────┐
    │ Class    │ ONE real algorithm            │ Real-world analogy            │
    ├──────────┼───────────────────────────────┼───────────────────────────────┤
    │ O(1)     │ array[i] direct access        │ knowing the room number       │
    │ O(log n) │ binary search in sorted array │ dictionary halving            │
    │ O(n)     │ linear scan                   │ reading attendance once       │
    │ O(n log n)│ merge sort / heapsort        │ split-and-merge sorting       │
    │ O(n²)    │ nested double loop / bubble   │ every student vs every other  │
    │ O(n³)    │ naive matrix multiply (3 loops)│ every triple from 3 lists    │
    │ O(2ⁿ)    │ subset generation, naive fib  │ every subset of a set         │
    │ O(n!)    │ permutations, brute TSP       │ every seating arrangement     │
    └──────────┴───────────────────────────────┴───────────────────────────────┘

    ASCII growth curves (lower is faster):

        ops ▲
            │                            n!
            │                       2ⁿ
            │                    n³
            │               n²
            │          n log n
            │        n
            │    log n
            │ 1
            └───────────────────────────────► n

    - WHEN TO USE: the moment you see a loop pattern, map it: constant body →
      weight of loop nesting, halving step → log n, doubling work per element →
      n log n, nested full loops → powers of n, exhaustive enumeration → 2ⁿ/n!.

 🧠 LOGIC — STEP BY STEP: (pure English)
    Step 1: Write the raw operation count f(n) of the innermost statement, as a
            function of n.                       WHY: everything else is constant
            multiples we will drop.
    Step 2: Count how many times each loop runs: full n runs → factor n;
            halving (i*=2 / i/=2) → factor log₂n; depth-k recursion → nᵏ...
                                                          WHY: loop bounds decide
            the iterates, exactly like nesting boxes.
    Step 3: Multiply nested-loop factors together (outer × inner) — nested
            loops iterate concurrently, so counts multiply.
            WHY: each outer step runs the whole inner loop.
    Step 4: Drop constants and lower-order terms to land on a single class.
            WHY: that is the Big-O definition — only the dominant growth matters.
    Step 5: Confirm empirically: double n; if ops ~×2 → O(n), if ~×4 → O(n²),
            if +constant → O(1).                 WHY: ratios reveal growth class.

 VISUAL WALKTHROUGH (timing experiment, n = 1000, repeat tuned so every shape
    performs ≈ 10 million operations near the wall-clock scale of milliseconds):

    shape           ops per call at n=1000      repeat    elapsed µs
    ────────────────────────────────────────────────────────────────────
    O(1)     (3 fixed stmts)           3       3,000,000   ~ X µs
    O(log n) (i*=2)                   10       1,000,000   ~ X µs
    O(n)     (single loop)         1,000          10,000   ~ X µs
    O(n log n)(n × j/=2)           9,996           1,000   ~ X µs
    O(n²)    (double loop)      1,000,000             10   ~ X µs
    ────────────────────────────────────────────────────────────────────
    ≈ same total operations ⇒ ≈ similar microseconds: the TRUE lesson is the
    ops-per-input column, which jumps from 3 to 1,000,000 as the class grows.

 DRY RUN (shape5 = O(n²), n = 1000):
    call shape5(1000):
      i=0   → inner j loops 0..999 = 1000 ops
      i=1   → inner j loops 1000 ops
      ...
      i=999 → inner j loops 1000 ops
      total = 1000 × 1000 = 1,000,000 ops  →  f(n) = n²  →  O(n²) ✓
    Repeat = 10 → 10,000,000 ops elapsed in the µs shown by demo.

 TIME COMPLEXITY CALCULATION:
    shape1 (O(1))     : 3 fixed statements → f(n) = 3 → O(1)
                        (constant, it does not grow with n)
    shape2 (O(log n)) : i=1; i<n; i*=2 → i hits 1,2,4,8,...,< n
                        → iterations = ⌊log₂n⌋ + 1 → f(n) = log₂n → O(log n)
    shape3 (O(n))     : i=0..n-1 → f(n) = n → O(n)
    shape4 (O(n log n)): outer n iterations × inner halving ⌊log₂n⌋
                        → f(n) = n·⌊log₂n⌋ → O(n log n)
    shape5 (O(n²))    : outer n × inner n → f(n) = n² → O(n²)
    → Time Complexity = O(1), O(log n), O(n), O(n log n), O(n²) respectively.

 SPACE COMPLEXITY CALCULATION:
    All five shapes use ONLY a loop variable (and one accumulator): besides the
    input there is a constant number of ints.
    → Input = O(n); Auxiliary = O(1); Total Space = O(n) for the timing loops.

 APPROACH COMPARISON (n = 1000: approx. operations, assuming ~10⁸ ops/sec):
    ┌──────────┬───────────────────────┬──────────────────┬───────────────────┐
    │ Class    │ Algorithm             │ ops @ n=1000     │ wall-time @ 10⁸/s  │
    ├──────────┼───────────────────────┼──────────────────┼───────────────────┤
    │ O(1)     │ array indexing        │ 1                │ 10 ns             │
    │ O(log n) │ binary search         │ 10               │ 100 ns            │
    │ O(n)     │ linear search         │ 1,000            │ 10 µs             │
    │ O(n log n)│ merge sort           │ ~10,000          │ 100 µs            │
    │ O(n²)    │ bubble sort           │ 1,000,000        │ 10 ms             │
    │ O(n³)    │ naive matrix mul      │ 10⁹              │ 10 s              │
    │ O(2ⁿ)    │ subset gen, n=30      │ ~10⁹             │ 10 s              │
    │ O(n!)    │ brute TSP, n=12       │ ~4.8·10⁸         │ 5 s               │
    └──────────┴───────────────────────┴──────────────────┴───────────────────┘
*/
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// O(1)      — 3 fixed statements, loop nahi
long long shape1(int n) {
    long long ops = 0;
    ops += 1; ops += 1; ops += 1;       // hamesha 3 ops desthi hein
    (void)n;
    return ops;
}

// O(log n)  — i har step me DOUBLE
long long shape2(int n) {
    long long ops = 0;
    for (int i = 1; i < n; i *= 2) ops++;   // 1,2,4,8,... ~ log2n baar
    return ops;
}

// O(n)      — single loop
long long shape3(int n) {
    long long ops = 0;
    for (int i = 0; i < n; i++) ops++;
    return ops;
}

// O(n log n) — outer n × inner halving
long long shape4(int n) {
    long long ops = 0;
    for (int i = 0; i < n; i++)             // n baar outer
        for (int j = n; j > 1; j /= 2) ops++;   // har baar ~log2n halvings
    return ops;
}

// O(n²)     — double nested loop
long long shape5(int n) {
    long long ops = 0;
    for (int i = 0; i < n; i++)             // n baar
        for (int j = 0; j < n; j++) ops++;  // n baar → n*n total
    return ops;
}

// Timing helper — shape ko 'repeat' baar chala kar microseconds batata hai
long long timeShape(long long (*shape)(int), int n, int repeat) {
    volatile long long sink = 0;            // compiler optimization roko
    auto start = steady_clock::now();
    for (int r = 0; r < repeat; r++) sink += shape(n);
    auto stop = steady_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}

int main() {
    const int n = 1000;

    cout << "SHAPE LAB (n = " << n << "): exact ops per call:\n";
    cout << "   O(1)      : " << shape1(n) << "\n";
    cout << "   O(log n)  : " << shape2(n) << "\n";
    cout << "   O(n)      : " << shape3(n) << "\n";
    cout << "   O(n log n): " << shape4(n) << "\n";
    cout << "   O(n^2)    : " << shape5(n) << "\n\n";

    cout << "TIMING (repeat tuned taa har shape ≈ 10M operations kare):\n";
    cout << "   O(1)      : " << timeShape(shape1, n, 3000000) << " us\n";
    cout << "   O(log n)  : " << timeShape(shape2, n, 1000000) << " us\n";
    cout << "   O(n)      : " << timeShape(shape3, n, 10000)   << " us\n";
    cout << "   O(n log n): " << timeShape(shape4, n, 1000)    << " us\n";
    cout << "   O(n^2)    : " << timeShape(shape5, n, 10)      << " us\n\n";

    cout << "GROWTH CHECK — n double karo (shape3 O(n) vs shape5 O(n^2)):\n";
    for (int s : {100, 200, 400, 800})
        cout << "   n=" << s << "  O(n)=" << shape3(s)
             << "  O(n^2)=" << shape5(s) << "\n";
    cout << "   O(n) x2/niranti ⇔ O(n);  O(n^2) x4 ⇔ quadratic growth ✓\n";
    return 0;
}