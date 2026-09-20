# 03 — Time Complexity (count of basic operations as a function of input size)

- Time complexity is the number of BASIC OPERATIONS (comparisons, additions, assignments) an algorithm executes, expressed as f(n) of the input size.
- It is deliberately NOT wall-clock time — it ignores CPU speed and machine load, so it stays true on every computer.
- For linear search the count varies with data: best = 1, average = (n+1)/2, worst = n comparisons — yet all collapse to the same class O(n).
- To state a complexity you always derive f(n) first: count each line's executions, sum them (tests n+1, bodies n, increments n), then reduce.
- Growth classes are what matter: n → 2n doubles comparisons, proving linear growth that no stopwatch can fake.

**Real-world analogy:** Searching 200 cinema seats one-by-one until you find your phone. Nobody guarantees "3 minutes" — the honest statement is "at most 200 checks, usually ~100". Time complexity is exactly that honest, stopwatch-free statement.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | What time complexity is (count of ops, not seconds) + a working demo: `linearSearch` counting comparisons for best/middle/absent cases, edge case n=0, and a count-vs-n table. |
| `task.cpp` | 6 problems (EASY → HARD): count-vs-n worst case, max-position independence, triangle sum n(n-1)/2, exact 3n+4 verification, sorted early-exit, and the stable-count-vs-noisy-seconds experiment. Full solutions inside. |
| `README.md` | Summary, cheat-sheet, complexity table, common mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
// Time = operation count, NOT seconds
long long linearSearch(int a[], int n, int key, long long& cmp) {
    cmp = 0;
    for (int i = 0; i < n; i++) {
        cmp++;                    // 1 comparison — the basic operation
        if (a[i] == key) return i;
    }
    return -1;
}
// worst: cmp = n      avg: cmp = (n+1)/2      best: cmp = 1
```

**Key formulas (always show these workings):**

```
Worst linear search   : comparisons = n            → O(n)
Best linear search    : comparisons = 1            → O(1)
Average               : (1+2+...+n)/n = n(n+1)/2/n = (n+1)/2 → O(n)
findMax               : comparisons = n-1          → O(n)
Duplicate check       : (n-1)+(n-2)+...+1          = n(n-1)/2 → O(n²)
sum-of-array exact    : f(n) = (n+1) + n + n + 2   = 3n + 4   → O(n)
Gauss identity        : 1+2+...+n = n(n+1)/2
```

**Reduction:** `f(n) = 2n + 3 → keep 2n → drop 2 → O(n)`.

## Complexity comparison (operation counts are machine-stable)

| Algorithm | Operation counted | Exact f(n) | Class | At n=10⁶ |
|-----------|-------------------|------------|-------|----------|
| Linear search (worst) | key comparisons | n | O(n) | 10⁶ |
| Linear search (average) | key comparisons | (n+1)/2 | O(n) | ≈ 5×10⁵ |
| findMax | comparisons | n−1 | O(n) | ≈ 10⁶ |
| sum of array | all ops counted | 3n+4 | O(n) | ≈ 3×10⁶ |
| duplicate check | comparisons | n(n−1)/2 | O(n²) | ≈ 5×10¹¹ ⚠️ |
| sorted early-exit search | comparisons | ≤ n (worst n) | O(n) | ≤ 10⁶ |

## ⚠️ Common mistakes

- **Reporting wall-clock seconds as "time complexity"** — seconds vary by machine; the operation count does not. Say "O(n)" and separately report the measured ms.
- **Forgetting the loop test.** `for (i=0;i<n;i++)` executes the test n+1 times — an exact f(n) must include it.
- **Thinking average = (best+worst)/2.** Average case needs a probability model (uniform position → (n+1)/2); it is not the arithmetic mean of 1 and n.
- **Believing "early exit" changes linear to sub-linear worst case.** It helps the average case only; worst case (key absent / at end) is still n comparisons.
- **Ignoring operations inside function calls.** If a called function contains a loop, its cost counts too.
- **Counting only C++ statements instead of operations.** One `a[i] > m` is one comparison; but `i++` and `i<n` are additional operations in an exact count.

## Interview Q&A

- **Q: What exactly is time complexity?** A: The number of basic operations as a function of input size n, summarized into a growth class like O(n). Not seconds.
- **Q: Why do best/average/worst all matter?** A: Same algorithm, same n, different data → different counts (1 vs (n+1)/2 vs n for linear search). Worst case is the guarantee.
- **Q: Why is average linear-search exactly (n+1)/2?** A: Key uniformly at position i uses i+1 comparisons; summing 1..n and dividing by n via Gauss gives n(n+1)/2 / n = (n+1)/2 → O(n).
- **Q: When do you count comparisons instead of all ops?** A: For search/sort problems comparisons dominate and are what the algorithm is defined by; for other problems count every basic operation.
- **Q: How do I know a solution will TLE?** A: Derive f(n); estimate operations (10⁸ ≈ 1 s); if f(n) for the given limit exceeds it, change approach.