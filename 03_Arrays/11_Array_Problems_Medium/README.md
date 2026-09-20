# Medium Array Classics

Four medium-important classics in one folder: **Kadane (max subarray)**,
**Moore's Voting (majority element)** and **trapping rain water** — each with a
brute version and the optimal O(n) version, fully derived. These are the
problems where "just loop twice" is visibly too slow and the O(n) insight wins
the interview.

- **Real-world analogy:** Kadane = best profit stretch of stock days; Moore's =
  deciding if one product outsells everything else combined; rainwater = how
  much water a city skyline actually traps between roofs.
- Common thread: keep tiny running state (max-so-far, vote counter, two
  boundary maxima) and the answer falls out in a single pass.

## Files + purpose

| File            | Purpose |
|-----------------|---------|
| `01_theory.cpp` | Full derivations: Kadane brute O(n²)/KP O(n), Moore's O(n) proof of two passes, rainwater O(n²)/O(n)/O(n) with comparison tables + ASCII |
| `task.cpp`      | Kadane sum, Kadane with range, majority verify, rainwater two-pointer, max circular subarray |
| `README.md`     | This summary + cheat sheet + interview Q&A |

## Cheat sheet

```cpp
// Kadane — O(n): current best subarray ENDING at i
int cur = 0, best = INT_MIN;
for (int x : a) { cur = max(x, cur + x); best = max(best, cur); }

// Moore's — two passes: cancel, then verify
for (int x : a) { if (votes==0){cand=x;votes=1;} else if (x==cand) votes++; else votes--; }
int cnt = count(a, cand);  if (cnt > n/2) return cand; else return -1;

// Rainwater two-pointer — O(n)/O(1)
while (l <= r) {
  if (lmax <= rmax) { lmax = max(lmax, h[l]); water += lmax - h[l++]; }
  else              { rmax = max(rmax, h[r]); water += rmax - h[r--]; }
}
```

## Complexity table

| Classic               | Brute time | Optimal time | Optimal space |
|-----------------------|------------|--------------|---------------|
| Kadane max subarray   | O(n²)      | O(n)         | O(1)          |
| Moore's majority      | O(n log n) | O(n) (2 pass)| O(1)          |
| Rainwater brute/prefix| O(n²)      | O(n) prefix / O(n) 2ptr | O(n) / O(1) |

Derivations: Kadane brute enumerates n(n+1)/2 subarrays → O(n²); the DP form
resets when `cur < 0`, giving one pass → O(n). Moore's two passes each do n
operations → O(n). Rainwater brute does a left+right scan per cell →
n(n-1) steps → O(n²); prefix precomputes L[]/R[] in two passes → O(n)/O(n);
two-pointer converges l and r in at most n moves → O(n)/O(1).

## ⚠️ Common mistakes

- Kadane: forgetting the all-negative case (plain `cur<0 → reset to 0` returns
  0 instead of the max single element); initialize `best = INT_MIN`.
- Moore's: skipping the second pass — a candidate is not a majority until recount
  proves `cnt > n/2` (e.g. {1,2,3} leaves a stale candidate).
- Rainwater: subtracting h[i] BEFORE taking mins could go negative — water is
  `max(0, min(L,R)-h[i])`; using `>=` between lmax and rmax flips the tie rule.
- Prefix variant: forgetting `if (n==0)` guard before indexing `L[0]`.
- Circular Kadane: applying `total - minKadane` when ALL elements are negative —
  that gives 0; guard with `total == minK`.

## Interview Q&A

**Q1. Why does Kadane "reset to zero"?** A negative running sum can never help a
future element — `cur + x < x ⇔ cur < 0`, so starting fresh always beats
extending. The DP form `max(x, cur+x)` states exactly that.

**Q2. Prove Moore's voting.** Pair each decrement with two different elements.
A true majority (> n/2) has more copies than the rest combined, so it can never
be fully cancelled by pairing; the surviving candidate must be it. Verify count
separately because without a majority the survivor is meaningless.

**Q3. Rainwater: why is cap the MIN of left-max and right-max?** Water spills
over the lower of the two enclosing walls — the min decides the level, and the
filling rule `min(L,R) - h[i]` is exact.

**Q4. Which rainwater solution for an interview?** Start with brute to show
understanding, then the prefix method (easiest correct O(n)), then mention the
two-pointer as the O(1)-space optimization — that arc scores maximum points.