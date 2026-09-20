# Sliding Window

- **Core idea:** reuse the previous window's answer — `newSum = oldSum − a[left going out] + a[right coming in]` — instead of re-summing the window every step.
- **Fixed window (size k):** first window O(k), then each slide is O(1); total O(n) vs brute O(n·k).
- **Variable window (two pointers):** grow `right`, shrink `left` while the condition breaks; each element moves at most twice total → O(n).
- **Window max / first negative:** a monotonic deque of indices; front is always the answer, and each element pushes/popped at most once → O(n).
- **EDGE CASES matter:** `k > n` (no window → guard), `k = 1`, empty arrays, all-negative input (max-sum must still be computed, don't init best to 0 blindly).

## Real-world analogy
A 3-day rolling blood-sugar average: each morning you drop yesterday-minus-3's reading and add today's — you never re-add all readings. Stocks, sensor stream smoothing, and rolling sales reports all work the same way.

## Files
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Fixed + variable windows, deque, ASCII diagrams, dry runs, complexity derivations, compile-ready demo |
| `task.cpp` | 6 tasks (easy→hard) with hints, starter code, and full solved solutions |

## Cheat sheet
```
Fixed window size k:
  sum = sum(a[0..k-1]); best = sum;
  for i = k..n-1:  sum = sum - a[i-k] + a[i];   best = max(best, sum);

Window max (deque, indices decreasing by value):
  while a[dq.back()] <= a[i]: dq.pop_back();  dq.push_back(i);
  if dq.front() <= i-k: dq.pop_front();       ans = a[dq.front()];

Variable window, longest valid:
  for r: grow (add a[r]);  while (condition breaks) shrink (remove a[l], l++);
  best = max(best, r-l+1);

Shortest window target: while (sum >= target) { best = min(best, r-l+1); sum -= a[l++]; }
Count subarrays (≤ d distinct): while (freq.size() > d) shrink; ans += r-l+1;
```

## Complexity table
| Problem | Brute | Sliding | Extra space |
|---------|-------|---------|-------------|
| Max sum of every size-k window | O(n·k) | O(n) | O(1) |
| First negative / max of each window | O(n·k) | O(n) | O(k) deque |
| Longest subarray sum ≤ k | O(n²) | O(n) | O(1) |
| Count subarrays with ≤ d distinct | O(n²·d) | O(n) | O(d) map |

## ⚠️ Common mistakes
- Trusting restrictive conditions (sum ≤ k / ≤2 distinct) only — those need **non-negative / monotone shrink**, otherwise two-pointer may skip valid windows.
- Not guarding `k > n` (out-of-bounds) or `k ≤ 0` (infinite loop in shrink).
- In the deque, forgetting the **out-of-window front** purge (`dq.front() <= i-k`) — stale indices poison the answer.
- Popping with `a[dq.back()] < a[i]` instead of `<=` for max — duplicates then never leave, making the deque grow unboundedly.
- Tracking `best` shorthand (`best = max(best, r-l+1)`) inside the shrink loop instead of after — miscounts median cases; measure the window once the invariant holds.
- For min-window problems using greedy shrink before recording the answer.

## Interview Q&A
- **Q:** When can two pointers be used for a "longest valid window" problem? **A:** When shrinking from the left monotonically restores validity — e.g., sum/target problems with non-negative numbers, or ≤ k distinct values. If a future right-extension can require un-shrinking, the two-pointer greedy fails.
- **Q:** Why total O(n) for the deque approaches? **A:** Each element is pushed once and popped at most once; stale-front removal is amortised into those pops.
- **Q:** Duplicate values in the max deque — how handled? **A:** Use `<=` so only the newest survivor stays; the older equal one becomes useless sooner.
- **Q:** Sliding vs prefix sum — which one and when? **A:** Prefix sum answers arbitrary `(l,r)` range queries on a static array; sliding window handles contiguous-window constraints while sliding in order.