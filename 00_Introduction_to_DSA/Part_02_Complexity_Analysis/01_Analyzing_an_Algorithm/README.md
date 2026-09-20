# 01 — Analyzing an Algorithm (Priori vs Posteriori)

- Analyzing an algorithm means studying its TIME, SPACE and CORRECTNESS before trusting it with large inputs.
- **Priori analysis** counts operations by reading the code (f(n) formulas) — machine-independent, used in interviews.
- **Posteriori analysis** runs the code and measures wall-clock time with `chrono` — machine-specific profiling.
- The two answers complement each other: Priori predicts *growth class* (O(n)), Posteriori measures *actual seconds* on one box.
- A fast but wrong algorithm is worthless — correctness is a separate characteristic you must verify.

**Real-world analogy:** Reading a recipe and counting pans before cooking (Priori) vs timing yourself with a stopwatch while cooking (Posteriori). Both give you useful but different information.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Full theory of the two analysis methods + a working demo: `findMax` instrumented with `opCount`, timed on n=5 and n=1,000,000 with `chrono`, edge case n=0. |
| `task.cpp` | 6 problems (EASY → HARD): count operations of sum, verify n−1 comparisons, posteriori timing at 3 sizes, sequential vs nested loops, correctness tester, predict-then-measure loop vs formula. Full solutions inside. |
| `README.md` | Summary, cheat-sheet, complexity table, common mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
//        PRIORI                      //        POSTERIORI
// count on paper:                   // measure on machine:
//   int maxV = a[0];     → 1 op     auto start = high_resolution_clock::now();
//   for (i=1; i<n; i++)  → n-1 ops  result = findMax(a, n, ops);
//     opCount++;  // compare        auto end   = high_resolution_clock::now();
//   f(n) = (n-1) + 2                // elapsed microseconds = (end-start)
//   → O(n)
```

**Key formulas:**

- `sum 1..n = n(n+1)/2` — used to count nested-loop totals like `1+2+...+n`.
- `sum 1..(n-1) = n(n-1)/2` — the inner loop of `for(i) for(j<i)` runs this many times → O(n²).
- Rules to go from f(n) to big-O:
  ```
  f(n) = 3n + 4      → take largest term 3n → drop 3      → O(n)
  f(n) = 2n² + 5n + 1→ take largest term 2n² → drop 2      → O(n²)
  f(n) = 100         → no n at all                        → O(1)
  ```

## Complexity comparison (from the demo)

| Function | Operation count derived | Big-O | Auxiliary space |
|----------|-------------------------|-------|-----------------|
| `findMax` (loop `i=1..n-1`, 1 comparison each) | (n−1) + 2 | O(n) | O(1) |
| `sumWithCount` (test n+1, body n, i++ n, init/return) | 3n + 4 | O(n) | O(1) |
| Fragment A (two sequential loops) | n + n = 2n | O(n) | O(1) |
| Fragment B (two nested loops) | n × n = n² | O(n²) | O(1) |
| `loopSum` (add 1..n in a loop) | ≈ 3n | O(n) | O(1) |
| `fastSum` (n(n+1)/2) | 3 (fixed) | O(1) | O(1) |

## ⚠️ Common mistakes

- **"My code ran in 2 ms" as the whole answer** — on which machine? Always give the Priori class (O(n)) first, then the measured number.
- **Thinking Priori counts seconds** — it counts *operations*, a pure function of n, never wall-clock.
- **Counting only the loop body** — the loop test `i<n` runs n+1 times and `i++` runs n times; include them for an exact f(n).
- **Calling posteriori results "general truth"** — a timing is only valid for that CPU/cache/OS; the other machine may differ 10x.
- **Assuming fast = correct** — a wrong comparator can still run in O(n); always test correctness too.

## Interview Q&A

- **Q: What is Priori vs Posteriori analysis?** A: Priori counts operations from reading the code before running (f(n), machine-independent). Posteriori measures real runtime after running (machine-dependent).
- **Q: Which is more useful in an interview?** A: Priori — you can't run code, and O(n) tells the growth story for any machine.
- **Q: Why isn't wall-clock time a good complexity measure?** A: It depends on processor speed, background load, and data — the same algorithm gives wildly different seconds on different machines.
- **Q: Why is correctness a form of analysis?** A: An algorithm is only *useful* if output matches expected result for all valid inputs; speed on wrong answers is useless.
- **Q: Given f(n) = 3n² + 5n + 100, what is the class?** A: Keep the largest term 3n², drop the multiplier → O(n²); for large n the n² term dominates (~99%+ of the work).