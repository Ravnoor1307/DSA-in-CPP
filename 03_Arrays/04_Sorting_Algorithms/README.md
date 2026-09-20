# Sorting Algorithms

Sorting is the art of rearranging a collection into ascending order so that searching, ranking, and reporting become fast. This module covers six algorithms across three families — quadratic comparison sorts (bubble, selection, insertion), divide-and-conquer sorts (merge, quick), and a linear non-comparison sort (counting). Each file pairs deep theory with runnable C++ demo code, and the task file takes you from a plain bubble sort all the way to O(n) Dutch-flag partitioning. After this module you should be able to derive any sort's complexity from its loop structure or recurrence, and pick the right algorithm for a real workload instantly.

- **Bubble / Selection / Insertion** — simple O(n²) sorts; insertion is the only one you actually use (nearly-sorted data).
- **Merge sort** — guaranteed O(n log n), stable, but needs O(n) extra memory.
- **Quick sort** — fastest on average, in-place, but fixed pivots blow up to O(n²) on sorted input.
- **Counting sort** — sorts small integer ranges in O(n + k) without any comparisons.

## Real-world analogy

Think of a library shelf of books in random heights. Bubble sort = keep swapping neighbours until the tallest book floats to the end. Selection sort = each round find the shortest remaining book and place it at the front. Insertion sort = the way you actually arrange cards in a hand — slide each card left into its spot. Merge sort = split the shelf in half, sort each half, then interleave the two sorted piles. Quick sort = pick one book as a divider, put shorter books on its left and taller on its right, then repeat on both sides. Counting sort = if books only come in five heights, count how many of each height and fill the shelf in order.

## Files + purpose

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Full theory: real-world scenario, step-by-step logic with WHY, ASCII walkthroughs, dry runs, complete time & space complexity derivations, comparison table + a working demo of all 6 sorts with counters and edge cases |
| `task.cpp` | 8 practice tasks (easy → hard) with hints, starter code, and fully solved, commented solutions |
| `README.md` | This cheat-sheet: summaries, tables, common mistakes, interview Q&A |

## Cheat sheet (one-liner + complexity)

- **Bubble sort** — swap adjacent out-of-order pairs; the largest element bubbles to the end each pass. `O(n²)` worst, `O(n)` best with a swap flag.
- **Selection sort** — find the min of the unsorted part and swap it to the front; minimal swaps (≤ n−1) but always `O(n²)`.
- **Insertion sort** — shift larger cards right and insert the key; `O(n)` on almost-sorted input, `O(n²)` worst.
- **Merge sort** — divide in half, sort each half, merge with two pointers; `O(n log n)` always, stable, `O(n)` space.
- **Quick sort** — Lomuto partition puts the pivot in its final spot; `O(n log n)` average, `O(n²)` worst (random pivot avoids it), in-place.
- **Counting sort** — tally frequencies, prefix sums, place right-to-left; `O(n + k)` time/space, stable, for small integer ranges only.

## Master comparison table

| Algorithm    | Best        | Average     | Worst       | Space     | Stable  | When to use                  |
|--------------|-------------|-------------|-------------|-----------|---------|------------------------------|
| Bubble       | O(n) opt    | O(n²)       | O(n²)       | O(1)      | Yes     | Teaching / tiny inputs       |
| Selection    | O(n²)       | O(n²)       | O(n²)       | O(1)      | No      | Fewest swaps; small arrays   |
| Insertion    | O(n)        | O(n²)       | O(n²)       | O(1)      | Yes     | Nearly-sorted data; online   |
| Merge        | O(n log n)  | O(n log n)  | O(n log n)  | O(n)      | Yes     | Guaranteed time; stable      |
| Quick (rand) | O(n log n)  | O(n log n)  | O(n²)       | O(log n)  | No      | Fastest in practice; in-place |
| Counting     | O(n + k)    | O(n + k)    | O(n + k)    | O(n + k)  | Yes     | Small int keys in known range|

## ⚠️ Common mistakes

- **Off-by-one partitions (quick sort)**: recursing on `[lo..p]` instead of `[lo..p-1]` causes infinite recursion — the pivot is already final, never re-include it. Same for merge: index `k` must start at `lo`, not `0`, or you overwrite the wrong segment.
- **Merge temp arrays wrong size**: reading `[mid+1..hi]` into R with size `hi - mid + 1` (off by one) reads out of bounds and breaks the sorted result.
- **Counting sort with negatives**: using `freq[x]` directly crashes on `x < 0`. Always subtract the min value → `freq[x - lo]`, so the range maps to `[0, k)`.
- **Ignoring stability**: counting sort placed left-to-right without prefix sums scrambles equal keys; the stable build goes right-to-left using prefix sums.
- **Stack overflow / deep recursion**: merge and quick recurse O(log n) deep normally, but fixed-pivot quick sort on sorted input recurses O(n) deep → call-stack overflow on big arrays. Use a random pivot.
- **Bubble without a swap flag**: on already-sorted arrays the naive version still scans all n−1 passes and wastes O(n²) comparisons.
- **`(lo+hi)/2` overflow**: on huge arrays `lo+hi` can overflow int; use `lo + (hi - lo)/2`.

## Interview Q&A

**Q1. When is insertion sort better than merge sort?** Pair-wise for nearly-sorted data — insertion sort is O(n), merge stays O(n log n), and insertion's constant factor is far smaller on tiny n.

**Q2. Why does quick sort degrade and how do you fix it?** With a fixed first/last pivot on already-sorted input, every partition is maximally unbalanced: T(n) = T(n−1) + O(n) = O(n²). A random (or median-of-three) pivot makes a bad split extremely unlikely, giving expected O(n log n).

**Q3. Why is merge sort stable but quick sort not?** Merge only ever compares the left head vs right head and copies the left on ties (≤), so equal keys keep source order. Lomuto quick sort performs long-distance swaps inside the partition, which can push an equal key across another.

**Q4. How is counting sort O(n + k) when it loops many times?** Tally is O(n), prefix sums O(k), output build O(n) → total O(n + k). When k is small (e.g. digits 0..9) this beats every O(n log n) comparison sort.

**Q5. What is the Dutch National Flag problem?** Sorting an array containing only 0, 1, 2 with one pass, O(n) time, O(1) space, using three pointers low/mid/high and an invariant of three zones — no comparison sort, no counting sort needed.

**Q6. Can you prove T(n) = 2T(n/2) + O(n) = O(n log n)?** The recursion tree has log₂n levels; each level merges exactly n elements total, so total work = n · log₂n = O(n log n) (Master Theorem, case a=2, b=2, d=1).