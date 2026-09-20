# Binary Search — log₂n Proof ⭐

Binary Search is the star of search algorithms: on a SORTED array it eliminates half the remaining elements every step, giving O(log n) worst-case time — exponentially better than linear search's O(n).

**Real-world analogy:** Finding a name in a sorted 1000-page telephone directory. Open the middle — if your name sorts later, discard the entire left half. Repeat. 1000 pages need at most ~10 jumps (2¹⁰ = 1024), not 1000 page-by-page checks. That middle-splitting trick IS binary search.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: the halving table, n=32 worked example, 16-element visual hunt, n=50 linear vs binary (50 vs 6 steps), full derivation |
| `task.cpp` | Tasks: recursive binary search with step counter, n=1024 steps proof (10 vs 1024), and THE formal O(log n) proof |
| `README.md` | This file — the complete log₂ proof, formulas, cheat sheet |

## The Complete log₂(n) Proof

```
Given: sorted array of n elements. Each step halves the search space.

  After 1 step   -> search space size = n / 2
  After 2 steps  -> search space size = n / 2² = n / 4
  After 3 steps  -> search space size = n / 2³ = n / 8
  ...
  After k steps  -> search space size = n / 2^k

The search STOPS when only 1 element is left:

      n / 2^k  =  1

Multiply both sides by 2^k:

      n  =  2^k

Take log₂ of both sides:

      log₂(n)  =  log₂(2^k)  =  k

          =>   k  =  log₂(n)

Interpretation: the maximum number of steps binary search needs for
n elements is log₂(n). Each step does O(1) work. Therefore:

      Worst Case Time = O(1) × log₂(n) = O(log n)
```

### Worked example — n = 32 (halving table)

```
Step 0: 32 elements
Step 1: 16   (32/2)
Step 2: 8    (32/4)
Step 3: 4    (32/8)
Step 4: 2    (32/16)
Step 5: 1    (32/32 = 1)  ← DONE

Steps = 5 = log₂(32)     ✓   because 2⁵ = 32
```

## Cheat Sheet / Formulas

```
Binary Search basics:
  mid = low + (high - low) / 2    // overflow-safe middle
  target == arr[mid]  → found
  target  <  arr[mid]  → high = mid - 1   (left half)
  target  >  arr[mid]  → low  = mid + 1   (right half)
  low > high           → not found

Steps needed (MAXIMUM):
  k = ⌈log₂(n)⌉     (ceil of log base 2 of n)

Classic values:
   n          max steps
   16         4
   32         5
   50         6
   256        8
   1024       10
   1000000    ~20
   1e9        ~30

n=50 demo (star):
  linear worst  = 50 comparisons
  binary worst  = 6 steps  (log₂(50) ≈ 5.64 → 6)
  → 50 vs 6 = a 8x difference for just 50 elements!
```

## Complexity Comparison Table

```
┌──────────────────┬────────────┬────────────┬────────────┬──────────────┐
│   Search         │ Best Case  │ Avg Case   │ Worst Case │ Space        │
├──────────────────┼────────────┼────────────┼────────────┼──────────────┤
│ Linear Search    │ Ω(1)       │ Θ(n)       │ O(n)       │ O(1)         │
│ Binary (iterative)│ Ω(1)      │ Θ(log n)   │ O(log n)   │ O(1)         │
│ Binary (recursive)│ Ω(1)      │ Θ(log n)   │ O(log n)   │ O(log n)+stack│
└──────────────────┴────────────┴────────────┴────────────┴──────────────┘

    n=50 absolute numbers:
      Linear:  1 (best) / 25.5 (avg) / 50 (worst) comparisons
      Binary:  1 (best) / ~5.6 (avg) / 6 (worst)   steps
```

## ⚠️ Common Mistakes

1. **Using binary search on an UNSORTED array:** It silently returns wrong results. Either sort first or use linear search.
2. **Off-by-one with `low <= high` vs `low < high`:** Using `low < high` skips the final single-element check. Be consistent: `low <= high`.
3. **Integer overflow in `(low+high)/2`:** For huge arrays `low+high` can overflow int. Always use `low + (high-low)/2`.
4. **Confusing halving with the answer:** Halving repeats until ONE element — that's log₂n steps, NOT n/2.
5. **floor vs ceil:** For non-power-of-two n, max steps is ⌈log₂(n)⌉, not ⌊log₂(n)⌋. E.g., n=50 needs 6 steps, not 5.
6. **Assuming binary beats linear always:** For tiny arrays or when sorted data is unguaranteed, linear may be simpler and comparable.

## Interview Q&A

**Q: Prove binary search is O(log n).**
A: Each step halves the search space. After k steps the space has n/2^k elements. The search stops when one element remains: n/2^k = 1 → n = 2^k → taking log₂ of both sides gives k = log₂(n). Each step is constant work (one comparison and pointer update), so total time is 1 × log₂(n) = O(log n).

**Q: Why does binary search need a sorted array?**
A: The decision "go left or right" is only valid if all smaller elements are on the left and all larger on the right. Sorting guarantees that invariant so discarding a half never throws away the answer.

**Q: Recurrence relation for binary search?**
A: T(n) = T(n/2) + O(1). Solving by Master's theorem (case 2): a=1, b=2, f(n)=O(1), log_b(a)=0, so T(n) = O(log n).

**Q: What is the space complexity?**
A: Iterative version: O(1) — only low, mid, high. Recursive version: O(log n) because the recursion stack reaches depth log₂(n).

**Q: When is linear search better than binary?**
A: When the array is unsorted (sorting costs O(n log n) first), when n is tiny (constant factors dominate), or when you need only one lookup on transient data.

**Q: How many elements can you search with 10 comparisons?**
A: Up to 2¹⁰ = 1024 elements. With 30 comparisons: roughly 1 billion elements.