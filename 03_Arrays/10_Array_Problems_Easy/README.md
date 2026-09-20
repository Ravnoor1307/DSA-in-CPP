# Easy Array Classics

Six foundational single-pass problems every interview warm-up uses: **isSorted**,
**remove element in-place**, **three largest distinct**, **segregate even/odd**,
**leaders** and one-trade **stock max profit**. The unifying theme: walk the
array once, keep a few running variables or two pointers, answer with O(n) time
and O(1) extra space.

- **Real-world analogy:** A quality-control inspector on a conveyor belt — each
  product is inspected once as it passes, a handful of notes are kept, and the
  decision for every product is made before the next one arrives.
- The patterns here (running max/min, write/read pointers, two ends meeting,
  reverse-pass with max-so-far) appear everywhere in harder problems too.

## Files + purpose

| File            | Purpose |
|-----------------|---------|
| `01_theory.cpp` | Theory + ASCII diagrams + complexity derivations for all six classics, compile-ready demo |
| `task.cpp`      | 5 practise tasks EASY→HARD (isSorted, removeElement, top3, leaders, maxProfit) |
| `README.md`     | This summary + cheat sheet + interview Q&A |

## Cheat sheet

```cpp
// isSorted — neighbours only
for (int i = 1; i < n; ++i) if (a[i] < a[i-1]) return false;

// removeElement — write pointer
int w = 0;
for (int r = 0; r < n; ++r) if (a[r] != val) a[w++] = a[r]; // return w

// top3 distinct — 3-variable chain
for (int x : a) if (x>f) {t=s; s=f; f=x;} else if (x>s) {t=s; s=x;} else if (x>t) {t=x;}

// segregate evens first — meet in the middle
while (l < r) { if (even a[l]) l++; else if (odd a[r]) r--; else swap(a[l++], a[r--]); }

// leaders — reverse scan, max so far
for (i = n-1; i >= 0; --i) if (a[i] > mx) { push; mx = a[i]; } reverse(res);

// maxProfit — running min
for (price : p) { mn = min(mn, price); best = max(best, price - mn); }
```

## Complexity table

| Classic         | Brute     | Optimal  | Space        |
|-----------------|-----------|----------|--------------|
| isSorted        | O(n²)     | O(n)     | O(1)         |
| removeElement   | O(n) copy | O(n)     | O(1) in-place|
| three largest   | O(n log n)| O(n)     | O(1)         |
| segregate e/o   | O(n) buf  | O(n)     | O(1)         |
| leaders         | O(n²)     | O(n)     | O(d) output  |
| max profit      | O(n²)     | O(n)     | O(1)         |

Derivations: leaders brute — for each i scan the n-i elements to its right →
Σ(n-i) = O(n²); optimal uses one reverse pass → O(n). maxProfit brute tests
n(n-1)/2 ordered pairs → O(n²); optimal computes `best = price - minSoFar` with
one update per day → O(n). Everything else is a single pass over n elements →
O(n).

## ⚠️ Common mistakes

- isSorted: comparing all pairs instead of neighbours, or treating `<=` == strict.
- removeElement: forgetting to return `w` (not original size), or using a second
  array (defeats "in-place").
- top3: not de-duplicating values, or initializing with 0 (breaks negative inputs).
- segregate: assuming order must be preserved (statement usually says order-free).
- leaders: printing in right-to-left order without reversing; using `>=` instead
  of `>` (equal values are not leaders).
- maxProfit: allowing sell before buy, or forgetting best can stay 0 on a
  decreasing series.

## Interview Q&A

**Q1. isSorted in one pass?** Yes — a single descent `a[i] > a[i+1]` proves it's
unsorted; boundaries need one compare each.

**Q2. removeElement: why write/read pointers?** Read scans all n, write only
advances on kept values, so no shifting — new length is exactly `w`, O(1) space.

**Q3. What if two largest values are equal?** The distinct-check skips duplicates,
so equal values occupy one slot not two; return unique three.

**Q4. Leaders: why scan from the right?** "Greater than all to the right" is one
running-max when reading backwards — rightmost element is always a leader.

**Q5. Why can max profit never be negative?** Because you can always choose not
to trade (answer 0); only positive spreads count as profit.