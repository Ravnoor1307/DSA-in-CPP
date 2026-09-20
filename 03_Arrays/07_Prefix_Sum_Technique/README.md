# Prefix Sum Technique

- **Core idea:** `prefix[i] = prefix[i-1] + arr[i]`; a range sum is a single subtraction `prefix[r] - prefix[l-1]` instead of re-adding the window each time.
- **1D build is O(n) once; every range query becomes O(1).** Brute makes every query O(n) — the whole point is many queries on a static array.
- **2D variant reuses inclusion–exclusion:** `P[i][j] = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]`, and a rectangle sum needs just 4 lookups.
- **Works with negatives and gives rise to prefix-mod tricks** (subarrays divisible by k) and prefix/suffix products (product except self).
- **l == 0 is a special case** — `prefix[-1]` does not exist, so answer becomes `prefix[r]` directly.

## Real-world analogy
Like your bank's running monthly total: when asked "how much did you spend March→June?", you don't re-add every receipt — you subtract the June total and the February total. Two stored numbers answer an entire range of transactions.

## Files
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concept, ASCII visuals, dry runs, complexity derivations, compile-ready demo |
| `task.cpp` | 6 tasks (easy→hard) with hints, starter code, and full solved solutions |

## Cheat sheet
```
prefix[0] = arr[0]
prefix[i] = prefix[i-1] + arr[i]
sum(l..r)   = prefix[r] - prefix[l-1]       (l == 0 → prefix[r])
P[i][j]     = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
rect(r1,c1,r2,c2) = P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]
equilibrium: left == total - a[i] - left
divisible-by-k: same prefix remainder → pair (freq based)
product except self: left[i-1] * right[i+1]
```

## Complexity table
| Operation | Brute | Prefix |
|-----------|-------|--------|
| Build 1D | — | O(n) |
| Range query (1D) | O(n) per query | O(1) per query |
| Build 2D | — | O(R·C) |
| Rectangle query (2D) | O(R·C) per query | O(1) per query |
| Extra space | O(1) | O(n) 1D / O(R·C) 2D |

## ⚠️ Common mistakes
- Forgetting the `l == 0` case → index out of bounds / `prefix[-1]`.
- Using prefix sums while the array **changes** between queries (updates make the table stale → need Fenwick/persistent trees instead).
- Negative modulo (`x % k` returns negative in C++) — normalize with `((x % k) + k) % k` for divisibility problems.
- Mixing up 2D inclusion–exclusion signs; the corner term `P[i-1][j-1]` must be **subtracted** during build but **added** during the rectangle query formula.
- Returning the sum type as `int` when numbers can overflow — use `long long`.

## Interview Q&A
- **Q:** When is prefix sum useless? **A:** When the array is mutated between queries — the O(n) table goes stale; a Fenwick/segment tree is the fix.
- **Q:** Can we answer subarray sum divisible by k with prefix? **A:** Yes — two prefix sums give equal remainders mod k, so count-frequency on remainders (add `freq[0]=1` at start).
- **Q:** Product except self without division? **A:** Precompute left run products and right run products; combine per index. Division is disallowed when zeros exist.
- **Q:** How do you handle an all-negative array? **A:** The same formulas hold; subtraction of totals is sign-safe. Only the minimum/maximum-style follow-up questions need care.