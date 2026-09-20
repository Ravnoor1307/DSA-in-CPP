# Searching Algorithms

Linear search scans every element one by one and needs no ordering, while binary search
repeatedly cuts the search window in half and therefore **requires a sorted array**. Binary
search runs in O(log n) because after k halvings the window holds n/2^k elements, and the
search stops when n/2^k = 1, i.e. k = log₂(n). We also study duplicates (first/last
occurrence and counting), lower/upper-bound style variants (floor/ceil), the rotated-sorted
search, and the powerful "binary search on the answer" technique used to compute square roots.
The classic mistake is applying binary search to unsorted data or getting the `low <= high`
loop condition wrong.

**Real-world analogy:** Finding "Ravnoor" in a sorted phone book, you never flip every page —
you open the middle, compare, and discard half the book each time. That is binary search. If
pages were shuffled, you would have to scan from the first page to the last, one by one — that
is linear search.

## Files & Purpose

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure concept: linear, iterative/recursive binary search, first/last occurrence, count, sqrt via BS. Demos with step traces and edge cases (empty array, absent target, first/last position, duplicates). |
| `task.cpp` | 7 practice tasks: (a) linear index, (b) count occurrences, (c) first occurrence, (d) ceil, (e) floor, (f) search in rotated sorted array, (g) sqrt with precision. Full solved code with derived complexities. |

## Cheat Sheet

- mid formula: `mid = low + (high - low) / 2` — equals `(low+high)/2` but never overflows.
- loop condition: `while (low <= high)` — when `low == high` one candidate still needs testing.
- binary search complexity proof:
  `n/2^k = 1  →  n = 2^k  →  log₂(n) = k  →  O(log n)`
- first occurrence: on match, save `ans` and keep going left (`high = mid - 1`).
- last occurrence: on match, save `ans` and keep going right (`low = mid + 1`).
- count occurrences: `last - first + 1` (0 if first is -1).
- ceil(x): smallest element ≥ x — candidate when `a[mid] >= x`, go left to shrink.
- floor(x): largest element ≤ x — candidate when `a[mid] <= x`, go right to grow.
- rotated sorted array: one of the halves is always sorted; decide by comparing `target` against the sorted half's bounds.
- binary search on answer: define a monotonic predicate (e.g. `mid*mid <= x`) and search the value space, not an array.

## Complexity Table

| Problem | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| Linear search | O(n) (n comparisons worst case) | O(1) |
| Binary search (iterative) | O(log n) | O(1) |
| Binary search (recursive) | O(log n) | O(log n) recursion stack |
| First / Last occurrence | O(log n) | O(1) |
| Count occurrences | O(log n) (two BS calls) | O(1) |
| Ceil / Floor | O(log n) | O(1) |
| Search in rotated sorted | O(log n) | O(1) |
| sqrt via BS (precision ε) | O(log(x/ε)) | O(1) |

## ⚠️ Common Mistakes

- **Running binary search on an UNSORTED array** — the mid comparison gives no honest signal; results are garbage. Always sort first.
- **mid overflow**: `mid = (low + high) / 2` wraps when `low + high > INT_MAX` in C++. Use `low + (high - low) / 2`.
- **Off-by-one in the loop**: `low < high` (instead of `low <= high`) skips the last element when they are equal. Test `low == high` case explicitly.
- **Infinite loop on `low = mid` (not `mid+1`)** in some BS-on-answer variants for integers — use `mid+1` for integer ranges, or use the floating `high - low > epsilon` style.
- **Ignoring duplicates** — first occurrence needs "keep hunting left", not a naive early return.
- **Not deriving complexity** — always justify O(log n) with `n/2^k = 1 → k = log₂(n)`, never hand-wave.

## Interview Q&A

- Q: Why is binary search O(log n)? A: Each step halves the window; solving `n/2^k = 1` gives `k = log₂(n)` steps.
- Q: Why `low + (high-low)/2` instead of `(low+high)/2`? A: Mathematically identical, but the first form avoids integer overflow when `low + high > INT_MAX`.
- Q: Can binary search work on unsorted data? A: No — the mid comparison requires a total ordering; unsorted data needs linear search.
- Q: How to count frequency of x in O(log n)? A: `lastOccurrence(x) - firstOccurrence(x) + 1`; two binary searches is O(log n) total.
- Q: How would you add search to a rotated sorted array? A: At every mid, either the left or right half is sorted; decide which half holds `target` from the sorted half's bounds.
- Q: When do you binary search "the answer" instead of the array? A: When the predicate is monotonic — e.g. "is mid² ≤ x?" — you can search the value space and land on sqrt, minimum required capacity, etc.
- Q: Iterative or recursive binary search? A: Iterative — O(1) space, no stack-overflow risk; recursion is cleaner but costs O(log n) stack space.