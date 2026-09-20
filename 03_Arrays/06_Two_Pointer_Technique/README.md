# TWO POINTER TECHNIQUE

## 📌 5-Line Summary
1. Two indices (`lo`, `hi`) start at both ends and move inward — every step removes exactly one element from consideration.
2. Turns **O(n²) nested loops** into one **O(n)** pass over sorted data (pair sum, three-sum).
3. Also solves **partition** problems (move zeros, odd/even split) using a write-head + scan pointer.
4. **Remove duplicates** on a sorted array reuses the same write-head compaction.
5. Valid when data is **sorted** or the problem has a **monotone/partition structure** (e.g. container with most water).

## 🌍 Real-World Analogy
Two people guessing numbers from a sorted card deck — one from the top, one from the
bottom, closing in from both ends. Because the deck is sorted, each failed guess removes
exactly one card, so together they inspect at most n cards instead of every possible pair.

## 📁 Files & Purpose
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concepts, complexity derivation, ASCII pointer diagrams, compile-ready demo |
| `task.cpp` | 7 solved tasks EASY→HARD with Hinglish comments |
| `README.md` | Cheat sheet + common mistakes + interview Q&A |

## 🧮 Cheat Sheet
```
pairSum:   sum==t -> record, ++lo, --hi ; sum<t -> ++lo ; sum>t -> --hi
moveZeros: w=0; i scans; a[i]!=0 -> a[w++]=a[i]; then tail = 0
removeDups: w=1; a[i]!=a[w-1] -> a[w++]=a[i]; return w
maxWater:   area = min(h[lo],h[hi])*(hi-lo); move the SHORTER line
threeSum:   sort; fix i; two-pointer on i+1..n-1; skip duplicates
```

## ⏱️ Complexity Table
| Operation | Time | Space (aux) |
|---|---|---|
| Brute pair sum | O(n²) — n·(n−1)/2 comparisons | O(1) |
| Two-pointer pair sum | O(n) — ≤ 2n pointer moves | O(1) |
| Move zeros (extra array) | O(n) — 2 passes | O(n) |
| Move zeros (two-pointer) | O(n) — 1 scan + tail fill | O(1) |
| Remove duplicates | O(n) — 1 scan | O(1) |
| Container with most water | O(n) — shrink shorter line | O(1) |

## ⚠️ Common Mistakes
- Using two-pointer pair-sum on an **UNSORTED** array → wrong or missed pairs.
- Forgetting to **skip duplicates** in three-sum → repeated triplets in the result.
- **Move zeros**: forgetting the tail-fill loop → zeros never actually move.
- Picking O(n²) brute-force on large inputs when the two-pointer gives O(n).
- In non-decreasing vs strictly increasing data, comparing `a[i] != a[w-1]` fails for duplicates — keep sorted order intact.

## ❓ Interview Q&A
**Q: Why does the two-pointer pair-sum need a sorted array?**
A: The extreme pair bounds every possible sum; only on sorted data does `sum<t` imply *all* lo-side pairs are too small, so one pointer move eliminates a whole family of candidates in one step.

**Q: Move zeros — can it run in O(n) with O(1) space?**
A: Yes — a scan pointer reads every element once, a write head places non-zeros at the front, and the remaining tail is zeroed; both pointers stay in one array.

**Q: When is the write-head pattern used?**
A: For any compaction or partition: move zeros, remove duplicates from sorted data, separating odd/even, or negative/positive elements — one read index, one write index, no extra memory.

**Q: Container with most water — why move the shorter line?**
A: The water is capped by the shorter wall; keeping it while shrinking width can never improve the area, so the shorter line is provably irrelevant for the remaining range.