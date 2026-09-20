# 04 — Categorization of Time Complexity

- Time complexities are grouped into named growth classes: O(1), O(log n), O(n), O(n log n), O(n²), O(n³), O(2ⁿ), O(n!) — each with its own real-world feel.
- Each class is derived from a counting formula first (n, n·log₂n, 2^(n+1)−1, e·n! …); only then is the name given.
- The classes form a strict order for large n: 1 < log n < n < n log n < n² < n³ < 2ⁿ < n!.
- Doubling the input is the fastest sanity test: O(1)→same, O(log n)→+1, O(n)→×2, O(n²)→×4, O(n³)→×8, O(2ⁿ)→roughly squared.
- Feasibility follows the class: n ≤ 20 may allow 2ⁿ/n!, but n = 10⁶ allows at most O(n log n) within ~10⁸ ops.

**Real-world analogy:** Mailing 1 friend vs phoning all n friends vs everyone phoning everyone (n² calls) vs arranging n guests in every seating order (n!). The crowd size n decides which chore is even possible — exactly like the growth class decides whether an algorithm survives.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | All 8 categories with real-world analogies + an instrumented demo that COUNTS operations (`opCount++`) for every class — including O(2ⁿ) via recursive calls (n=15) and O(n!) via branch-choices (n=7) — plus a doubling table. |
| `task.cpp` | 6 problems (EASY → HARD): classify 5 snippets, build the full 8-row category table, prove doubling laws, triangle-loop pattern recognition, constraint→allowed-class decision, and picking O(n log n) over O(n²) sorting under n=10⁶. Full solutions inside. |
| `README.md` | Summary, cheat-sheet, complexity table, common mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
// verify any class: count operations and compare with the formula
while (n > 1) { n /= 2; c++; }        // → c = log2 n        → O(log n)
for (i<n)                     c++;    // → c = n              → O(n)
for (i<n) for (j<n)           c++;    // → c = n²             → O(n²)
for (i<n) for (j<n) for (k<n) c++;    // → c = n³             → O(n³)
int f(int k) { c++; if (!k) return; f(k-1); f(k-1); }  // ≈2^(n+1) → O(2ⁿ)
```

**Key formulas (derive first, classify second):**

```
Sum 1..n            = n(n+1)/2         triangle inner loops   → O(n²)
Sum 1..(n-1)        = n(n-1)/2         inner loop for(j<i)    → O(n²)
Halving             n/2^k → k = log₂n                          → O(log n)
Merge-style         n work × log₂n levels                       → O(n log n)
Two-way recursion   C(n) = 2^(n+1) − 1                          → O(2ⁿ)
All-arrangements    T(n) ≈ e·n!   (e ≈ 2.718)                   → O(n!)
```

## Complexity comparison (verified counts from the demo)

| Category | Derived formula | n=10 | n=1000 | Doubling n |
|----------|-----------------|------|--------|------------|
| O(1) | 1 | 1 | 1 | stays 1 |
| O(log n) | log₂n | ≈3 | ≈10 | +1 |
| O(n) | n | 10 | 1,000 | ×2 |
| O(n log n) | n·log₂n | 33 | ≈10,000 | >×2 |
| O(n²) | n² | 100 | 10⁶ | ×4 |
| O(n³) | n³ | 1,000 | 10⁹ ⚠️ | ×8 |
| O(2ⁿ) | 2^(n+1)−1 | 2,047 | impossible | squared |
| O(n!) | ≈e·n! | ≈9.9×10⁶ | impossible | multiplied |

## ⚠️ Common mistakes

- **Writing a bare `O(?)`** — always derive f(n) first and only then name the class.
- **Confusing O(n log n) with O(n²)** — at n=10⁶, n log n ≈ 2×10⁷ (fine) but n² = 10¹² (~hours). They feel identical until scale hits.
- **Calling `for(j<i)` inner loop "half of O(n²) = O(n)"** — n(n−1)/2 is still O(n²); dropping the constant `1/2` is mandatory, dropping n² is not.
- **Testing only tiny n** — at n=10 even O(n!) seems fine; always multiply out the formula at the REAL constraint.
- **Forgetting stack depth in recursion classes** — O(2ⁿ) time uses only O(n) stack depth, which surprises people; state both axes.
- **Assuming "low constant = always the better class"** — for small n constants can win, but the class always wins at scale (Task 6).

## Interview Q&A

- **Q: Name the time complexity categories from fastest to slowest.** A: O(1), O(log n), O(n), O(n log n), O(n²), O(n³), O(2ⁿ), O(n!).
- **Q: How do I know a snippet is O(log n)?** A: The active size halves each step: n → n/2 → n/4 … stops after log₂n steps.
- **Q: Why are both O(2ⁿ) and O(n!) called "intractable"?** A: They explode beyond any machine; 2⁶⁰ is already ~10¹⁸ ops (decades), and n! grows even faster than 2ⁿ.
- **Q: What is the practical difference between O(n²) and O(n log n)?** A: At n=10⁶: ~10¹² vs ~2×10⁷ operations — minutes-to-hours vs a fraction of a second.
- **Q: How do the categories map to constraints?** A: n≤20 → 2ⁿ/n!; n≤500 → n³; n≤5,000 → n²; n≤10⁶ → n log n; n≤10⁸ → n; any n → log n or 1.