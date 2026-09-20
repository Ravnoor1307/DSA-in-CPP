# Average Case Running Time

Average case running time is the expected number of operations an algorithm performs over all possible inputs of size n, assuming each input is equally likely. For linear search, the average is (n+1)/2 comparisons.

**Real-world analogy:** In a queue of 100 people, your friend could be at any position. Before finding them, you would expect to check about 50 people on average — halfway through the line on every typical hunt.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory with derivation of (n+1)/2, uniform distribution, demos running search across all positions |
| `task.cpp` | Tasks: average-comparison simulation, bubble sort nested loop counting, formal probability proof |
| `README.md` | This file — summary, formulas, comparison table |

## Cheat Sheet / Formulas

```
Average Case Linear Search (target present):
  Average = (1 + 2 + ... + n) / n
          = [n(n+1)/2] / n
          = (n+1)/2
  → Average Case = Θ(n)

Average Case (target may be absent):
  If absent case also possible, and each of the n+1 outcomes
  (positions 0..n-1 + "absent") equally likely:
  Average = [1+2+...+n + n] / (n+1)
          = [n(n+1)/2 + n] / (n+1)
          = n(n+3) / (2(n+1))
          ≈ n/2 still → O(n)

Expected value formula:
  E[X] = Σ ( x * P(X = x) )

Bubble sort average comparisons (always the same):
  Total = (n-1) + (n-2) + ... + 1 = n(n-1)/2
  → Average = Θ(n²)
```

## Complexity Comparison Table

```
┌─────────────────────┬────────────┬────────────┬────────────┐
│     Algorithm        │ Best Case  │ Avg Case   │ Worst Case │
├─────────────────────┼────────────┼────────────┼────────────┤
│ Linear Search       │ Ω(1)       │ Θ(n)       │ O(n)       │
│ Binary Search       │ Ω(1)       │ Θ(log n)   │ O(log n)   │
│ Insertion Sort      │ Ω(n)       │ Θ(n²)      │ O(n²)      │
│ Bubble Sort         │ Ω(n)       │ Θ(n²)      │ O(n²)      │
│ Merge Sort          │ Ω(n log n) │ Θ(n log n) │ O(n log n) │
└─────────────────────┴────────────┴────────────┴────────────┘

Linear search three cases:
  Best:   1 comparison              → Ω(1)
  Average: (n+1)/2 comparisons      → Θ(n)
  Worst:   n comparisons            → O(n)
```

## ⚠️ Common Mistakes

1. **Assuming uniform distribution without justification:** The (n+1)/2 formula assumes all positions equally likely. If real inputs cluster near the front, the average is lower.
2. **Forgetting the absent case:** If your search input can also mean "not found," the average increases slightly. Always define the sample space clearly.
3. **Saying average is "n/2 exactly":** It's (n+1)/2, not n/2. Close for large n, but mathematically distinct for small n.
4. **Confusing average and worst case for bubble sort:** Bubble sort comparisons are n(n-1)/2 in ALL cases — but the number of SWAPS differs. Comparisons themselves are fixed.
5. **Ignoring the probability weighting:** Average is a WEIGHTED sum, not just "middle of best and worst."

## Interview Q&A

**Q: What is the average case of linear search?**
A: (n+1)/2 comparisons, assuming the target is equally likely at each of n positions. Derived as (1/n)·(1+2+...+n) = (1/n)·n(n+1)/2 = (n+1)/2. This is Θ(n).

**Q: Average case is n/2, why does everyone write O(n)?**
A: Because Big-O drops constant factors. n/2, n, 3n all are O(n). The average case is HALF of the worst case in absolute terms but the same in asymptotic order.

**Q: How do you compute average case formally?**
A: Enumerate all inputs, count operations for each, multiply each by its probability, and sum. E[X] = Σ x·P(X=x). Only if inputs are equally likely do we divide by n.

**Q: Why is bubble sort's average equal to its worst case for comparisons?**
A: Because the loop bounds don't depend on the data — every run performs exactly (n-1)+(n-2)+...+1 = n(n-1)/2 comparisons regardless of input order. Only swaps vary.