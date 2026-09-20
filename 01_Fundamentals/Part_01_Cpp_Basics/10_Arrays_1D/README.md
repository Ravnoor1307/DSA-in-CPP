# 1-D Arrays (Traversal, Sum, Max/Min, Search, Reverse)

- An array is a fixed-size, same-type collection stored in one contiguous block, indexed from 0 to n−1.
- `arr[i]` = base address + i × sizeof(element) — that is why random access is constant time, O(1).
- Traversal, sum, max/min, and reverse all touch n elements once → O(n); linear search is O(n) in the worst case.
- Reversing is in-place with n/2 swaps (two ends meeting in the middle), using O(1) extra space.
- Edge sizes (empty and single-element) need care: max/min seed with `arr[0]`, so they require n ≥ 1.

- Real-world analogy: A teacher's flat marks list — walk down the list to total it and find the topper; or a train coach with seats 0..59 in one row where seat 25 is found instantly.

- Files in this folder:
  - `01_theory.cpp` — ASCII address diagram, dry runs (sum/max, reverse), compile-ready demo (traverse, sum, max, search, reverse, edge cases), per-operation complexity derivation.
  - `task.cpp` — 7 tasks EASY→HARD (sum, average, min/max, linear search, reverse in-place, second largest, left rotate by k) + full solutions.

- Cheat sheet / syntax table:

  | Operation      | Code idea                          | Time | Space |
  |----------------|------------------------------------|------|-------|
  | index access   | `arr[i]`                           | O(1) | O(1)  |
  | traverse / sum | loop 0..n−1, accumulate            | O(n) | O(1)  |
  | max / min      | seed `arr[0]`, compare the rest    | O(n) | O(1)  |
  | linear search  | scan until equal, else −1          | O(n) | O(1)  |
  | reverse        | swap `i`↔`n−1−i` while `i < n/2`  | O(n) | O(1)  |

- Complexity:
  - Time: indexing **O(1)**; traversal/sum/max/min/reverse/linear-search-worst-case **O(n)** (reverse is n/2 swaps ≈ n steps).
  - Space: **O(n)** for the array itself, **O(1)** extra for all listed algorithms.

- ⚠️ Common mistakes:
  - Accessing `arr[n]` (out of bounds) — undefined behaviour, no error is raised.
  - Using `i <= n` in loop bounds — the classic off-by-one that reads past the end.
  - Integer division in average: `sum / n` truncates; cast to `double` first.
  - Forgetting arrays decay to pointers when passed — the size must be passed separately.
  - Swapping across the middle in reverse (loop up to n instead of n/2), undoing the reversal.

- Interview Q&A:
  - Q: How does `arr[i]` work internally? A: base address + i × sizeof(element) — one address computation, hence O(1).
  - Q: Reverse in-place vs copy? A: In-place uses n/2 swaps and O(1) extra space; copying needs O(n) extra space.
  - Q: Find second largest in one pass? A: Keep `largest` and `secondLargest`; when a new max appears, demote the old max to second.
  - Q: Why is empty-array max a problem? A: There is no `arr[0]` to seed from — handle n==0 before calling such functions.