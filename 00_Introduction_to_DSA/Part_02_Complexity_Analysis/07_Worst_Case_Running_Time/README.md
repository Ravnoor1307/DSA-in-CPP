# Worst Case Running Time

Worst case running time is the maximum number of operations an algorithm performs for any input of size n. It is the hard upper bound — the algorithm can never take longer than this.

**Real-world analogy:** Your size is out of stock at a shoe store with 200 boxes. You must check every single box before giving up. That's the worst case: the slowest possible outcome, and the guarantee you can make about the algorithm's upper limit.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: target absent and target-at-last-index demos, edge cases, selection sort fixed-count analysis |
| `task.cpp` | Tasks: two worst scenarios, brute-force max-over-all-inputs, formal O(n) proof |
| `README.md` | This file — summary, formulas, comparison table |

## Cheat Sheet / Formulas

```
Worst Case Linear Search:
  Scenario A: target at last index -> n comparisons
  Scenario B: target absent         -> n comparisons (+1 return)

  f(n) = n
  Big-O check: get c=1, n0=1 such that n <= 1*n for all n >= 1
  → Worst Case = O(n)

  Since no input needs MORE than n steps, worst case is exactly Θ(n).

Worst case of common algorithms:
  Selection Sort:  n(n-1)/2 comparisons (all inputs, always)
  Insertion Sort:  n(n-1)/2 comparisons + moves (descending input)
  Merge Sort:      n·log2(n) comparisons total
  Quick Sort:      n² (bad pivot choice / sorted input)

Worst case triggers:
  Linear search  -> target absent / at end
  Insertion sort -> descending array
  Quick sort     -> already sorted with fixed pivot
```

## Complexity Comparison Table

```
┌────────────────────┬────────────┬────────────┬────────────┐
│     Algorithm       │ Best Case  │ Avg Case   │ Worst Case │
├────────────────────┼────────────┼────────────┼────────────┤
│ Linear Search      │ Ω(1)       │ Θ(n)       │ O(n)       │
│ Binary Search      │ Ω(1)       │ Θ(log n)   │ O(log n)   │
│ Selection Sort     │ Ω(n²)      │ Θ(n²)      │ O(n²)      │
│ Insertion Sort     │ Ω(n)       │ Θ(n²)      │ O(n²)      │
│ Quicksort          │ Ω(n log n) │ Θ(n log n) │ O(n²)      │
└────────────────────┴────────────┴────────────┴────────────┘

Linear search: the three cases
  Best:   target at index 0      -> 1 comparison      → Ω(1)
  Avg:    target anywhere        -> (n+1)/2           → Θ(n)
  Worst:  target last/absent     -> n                 → O(n)
```

## ⚠️ Common Mistakes

1. **Forgetting the absent case:** A search that never finds its target must check all n elements. "Target at last index" is only ONE worst input; absence is the other.
2. **Claiming worst case is always achievable unlucky:** Some algorithms (selection sort) have a worst case equal to every case because comparisons are input-independent.
3. **Best case is not a valid guarantee:** Quoting best case as "how fast it runs" is misleading; always quote worst case first in interviews.
4. **Worst case ≠ n+1 vs n nitpicking:** The extra assignment/return adds constants; asymptotically it is still O(n).
5. **Ignoring hidden worst cases:** Sorted input is a worst case for naive Quicksort but a best case for Insertion Sort — same data, opposite meaning.

## Interview Q&A

**Q: What is the worst case of linear search, and when does it happen?**
A: Exactly n comparisons. It happens when the target is at the last index, or the target is absent from the array entirely.

**Q: Which is more important — worst or average case?**
A: Worst case, because it is a guarantee. Mission-critical and real-time systems must know the upper bound. Average case tells the expected behavior but not the worst behavior.

**Q: Can the worst case be avoided?**
A: Sometimes. Randomized algorithms (randomized Quicksort) make the worst-case input unpredictable. But the worst-case TIME bound still exists mathematically.

**Q: Why is bubble sort worst case equal to average for comparisons?**
A: The comparison loops always run n(n-1)/2 times regardless of input order. Only the SWAP count varies (worst: n(n-1)/2 swaps on reversed input, best: 0).