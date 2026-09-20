# 44_STL_Algorithms — The <algorithm> + <numeric> Toolkit

- Does ONE LINE what a hand-written loop does in ten: sort, reverse, find, count, min/max, accumulate, unique, next_permutation, fill, copy.
- **Sort** = Introsort (quicksort + heapsort fallback + insertionsort tail), always O(n log n), works through iterators on any random-access container.
- **binary_search / lower_bound / upper_bound** are the premium tools: O(log n) by halving — but they GUARANTEE wrong results on unsorted data. Sort first.
- **unique** only merges adjacent duplicates → always `sort` then `unique` then `erase` to actually shrink.
- **accumulate** (from `<numeric>`) is the fold machine: sum with init `0`, or swap the 3rd arg for a lambda to multiply/concat.

## Real-world analogy
The exam-cell register: one messy list of names and marks. Sort prints the alphabetical seating chart, binary_search finds a student's seat in O(log n), count tells how many hit 95+, accumulate totals the class marks, sort+unique+erase cleans duplicate roll numbers, fill blanks every seat slot, rotate shifts a bench's people.

```
sorted lookup pipeline:  [unsorted] --sort O(n log n)--> [sorted] --lower/upper_bound O(log n)--> answers
dedup pipeline:          [dups] --sort--> [adjacent dups] --unique--> --erase--> [clean list]
```

## Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | Pure concept + compile-ready demo (sort, reverse, min/max, find, count, accumulate, binary_search, lower/upper_bound, unique, next_permutation, fill, copy) with unsorted-binary_search caveat + empty-container edge cases |
| `task.cpp` | 6 tasks easy→hard (sort+print, top-3, count, accumulate+avg, rotate, sorted-rank queries) each with hint + starter, plus full solved code |

## Cheat sheet / syntax table

| Job | Code | Complexity |
|---|---|---|
| Sort ascending | `sort(b,e)` | O(n log n) |
| Sort descending | `sort(rbegin,rend)` or comparator | O(n log n) |
| Reverse order | `reverse(b,e)` | O(n) |
| Find value | `find(b,e,v)` → iterator | O(n) |
| Count value | `count(b,e,v)` | O(n) |
| Count by condition | `count_if(b,e,lambda)` | O(n) |
| Total sum | `accumulate(b,e,0)` | O(n) |
| Exists? (sorted!) | `binary_search(b,e,v)` | O(log n) |
| First `>= x` | `lower_bound(b,e,x)` | O(log n) |
| First `> x` | `upper_bound(b,e,x)` | O(log n) |
| Dedup (sort first!) | `sort; unique; erase` | O(n log n) |
| Next lexicographic order | `next_permutation(b,e)` | O(n) per call |
| Fill value | `fill(b,e,v)` | O(n) |
| Copy range | `copy(sB,sE,dB)` | O(n) |
| Min/max element | `min_element(b,e)` / `max_element` | O(n) |

## Complexity — with the math

- **Time:** sort = quicksort with n work per level × log n halving levels → **O(n log n)**. find/count/accumulate/min/max_element/fill/copy = single pass → **O(n)**. binary_search/lower_bound/upper_bound = each step halves: n → n/2 → n/4 … log₂n steps → **O(log n)**. next_permutation = right-scan with ≤ n swaps → **O(n)** per call.
- **Space:** everything above is in-place on the existing container → **O(1)** auxiliary, except sort's recursion stack **O(log n)** and copy's fresh destination **O(n)**.

## ⚠️ Common mistakes

- **binary_search on unsorted data** → garbage answer or UB. The "not found" result is not trustworthy. **Sort first.**
- **using `lower_bound(v.begin(), v.end(), x)` on a `set`** → O(n), not O(log n); sets want their member `s.lower_bound(x)`. ⚠️ Babel error—on `set`, member function is the O(log n) one.
- **forgetting `erase` after `unique`** → duplicates logically gone but the vector is not actually shrunk.
- **`accumulate` with wrong init** → sum must start at 0, product at 1, or the first fold is off.
- **integer division for averages** → cast to `double` before dividing by `size()`.
- **`find` returns an iterator**, not a bool; compare against `end()` or reference the value with `*it`.

## Interview Q&A

1. **How does `sort` work and what complexity?** Introsort = quicksort with heapsort worst-case fallback + insertionsort for small ranges; each of the log n split levels does O(n) total work → O(n log n); in-place with O(log n) recursion stack.
2. **`find` vs `binary_search`?** find works on anything, O(n). binary_search needs sorted data, O(log n). Use find on tiny/unsorted, binary_search for repeated lookups on one sorted structure.
3. **How to count duplicates efficiently?** `upper_bound(x) - lower_bound(x)` on a sorted range — each O(log n), so duplicates in O(log n) instead of scanning.
4. **Why does ordered-`unique` need `sort` first?** It only merges adjacent equals; sorting clusters all copies together so one pass collapses them.
5. **What does `next_permutation` return?** A bool — `false` when the range was already the largest permutation (fully descending), and it leaves the range reset to the smallest (ascending) order.
6. **Rotate an array by k left in O(1) space?** `std::rotate(begin, begin+k, end)` — internally it does three reverses / gcd-based cyclic swaps in O(n) time, O(1) space.