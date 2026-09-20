# std::set — Sorted Unique Elements (Red-Black Tree)

## Summary
- `std::set` stores only **unique** values and keeps them **sorted ascending** automatically.
- Internally a **self-balancing Binary Search Tree** (red-black tree) → height `log2(n)`.
- Every operation (`insert`, `erase`, `find`, `count`, `lower_bound`, `upper_bound`) runs in **O(log n)**.
- Iteration (range-for / in-order) always yields **sorted order** for free.
- Inserting a duplicate is silently **ignored**; `count(x)` only ever returns 0 or 1.

## Real-world analogy
Think of an **attendance register sorted by roll number**, or a **friends list where nobody can appear twice**. In real systems, std::set powers things like "sorted unique stock tickers", "deduplicated timestamps", and "available seat numbers."

## Files in this folder
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready demo (sorted rolls, find/count, bounds, erase, empty-set edge cases). **No tasks.** |
| `task.cpp` | 6 tasks EASY→HARD (unique sorted print, union, count distinct, two-sum, kth smallest, merge intervals) + full solutions |
| `README.md` | This file: summary, cheat sheet, complexity, mistakes, interview Q&A |

## Cheat sheet / syntax table
```cpp
#include <set>
set<int> s;                       // empty set (ascending, unique)
s.insert(5);                      // insert — duplicate ignored
s.erase(5);                       // erase by value
s.find(5);                        // iterator to 5, or end()
s.count(5);                       // 0 or 1
s.lower_bound(5);                 // first element >= 5
s.upper_bound(5);                 // first element > 5
s.begin(); s.end();               // sorted iteration range
s.size(); s.empty();              // helpers
set<int> s2(v.begin(), v.end());  // build from a vector (dedupes)
```

## Complexity (with derivation)
- Tree height: each level doubles capacity → n nodes ⇒ `2^h = n ⇒ h = log2(n)`.
- `insert / erase / find / count / lower_bound / upper_bound`: one root→leaf walk = **O(log n)**.
- Building the set from n inserts: **O(n log n)**.
- Full iteration: visit every node once = **O(n)**.
- **Time = O(log n) per op; O(n log n) to build.**
- **Space = O(k)** where k = number of **distinct** elements (duplicates create no nodes).

## Common mistakes / pitfalls
1. **Assuming value lookup is O(1)** — it's O(log n), not O(1). Use `unordered_set` if order doesn't matter.
2. **Forgetting duplicates are ignored** — inserting the same value twice does NOT grow the size.
3. **Reading from `end()`** — dereferencing `find()` result without checking `!= s.end()` is undefined behavior.
4. **Changing an element while iterating** — you can't modify `*it` directly (keys are const); erase and re-insert instead.
5. **Forgetting `#include <set>`** — yes, it seems obvious, but transitive includes can hide dependencies in some codebases; always include explicitly.

## Interview Q&A
**Q1: Why is insert O(log n)?**
Because std::set is a red-black tree; the operation descends from root to leaf along a single path of length = tree height = log2(n), re-balancing after.

**Q2: set vs unordered_set?**
set → sorted + O(log n), supports lower_bound/upper_bound. unordered_set → unsorted + average O(1). Choose by whether order/predecessor queries matter.

**Q3: How do you count distinct elements in an array?**
Insert all into a set; answer is `set.size()`. Cost O(n log n).

**Q4: What does lower_bound(5) do if 5 exists?**
Returns an iterator to 5 itself ("first element not less than 5"). Use `upper_bound(5)` to get the first element strictly greater.

**Q5: Can two equal values exist in a set?**
Never. Sets enforce uniqueness by definition.