# Plotting Common Functions / Growth of Functions

Understanding how different mathematical functions grow as input size `n` increases is the cornerstone of algorithm analysis. The growth rate of a function directly determines the time-complexity class of an algorithm. Functions like constant O(1), logarithmic O(log n), linear O(n), linearithmic O(n log n), quadratic O(n²), cubic O(n³), exponential O(2ⁿ), and factorial O(n!) each represent drastically different performance tiers. As `n` grows large, even small differences in growth exponent lead to enormous — sometimes cosmic — differences in actual computation time. Mastering these growth curves lets you predict algorithm behaviour before writing a single line of code.

Real-world analogy: Imagine you are a chef scaling a recipe for more guests. O(1) is grabbing one item from the top of a stack — doesn't matter if 2 or 200 guests show up. O(n) is plating each guest's meal one by one — double the guests, double the time. O(n²) is having every guest shake hands with every other guest — double the guests, quadruple the handshakes. O(2ⁿ) is trying every possible combination of garnishes — one extra guest doubles your work. O(n!) is ordering every possible seating arrangement — completely impractical beyond a small dinner party.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory + demo: prints a value table for all 8 functions at n=1,2,4,8,16,32 and draws an ASCII bar chart comparing growth |
| `task.cpp` | Practice tasks: order functions by growth for a given n, predict which algorithm class fits, extend the table |
| `README.md` | This file — summary, cheat sheet, comparison table, interview Q&A |

## Cheat Sheet / Formulas

| Function | Name | n=1 | n=8 | n=16 | n=32 |
|----------|------|-----|-----|------|------|
| 1 | Constant | 1 | 1 | 1 | 1 |
| log₂ n | Logarithmic | 0 | 3 | 4 | 5 |
| n | Linear | 1 | 8 | 16 | 32 |
| n log₂ n | Linearithmic | 0 | 24 | 64 | 160 |
| n² | Quadratic | 1 | 64 | 256 | 1 024 |
| n³ | Cubic | 1 | 512 | 4 096 | 32 768 |
| 2ⁿ | Exponential | 2 | 256 | 65 536 | ~4.29 billion |
| n! | Factorial | 1 | 40 320 | ~2.09 × 10¹² | ~2.63 × 10³⁵ |

**Growth order (slowest → fastest):**
```
1  <  log₂ n  <  n  <  n log n  <  n²  <  n³  <  2ⁿ  <  n!
```

**Key recurrence for linearithmic:** T(n) = 2T(n/2) + O(n) → O(n log n) — appears in merge sort, heap sort.

**Rules of thumb:**
- If your algorithm is O(n²) and `n` doubles → runtime ×4
- If your algorithm is O(2ⁿ) and `n` increases by 1 → runtime ×2
- O(n!) is only feasible for n ≤ 12 in practice

## Complexity Comparison Table (operations for various n)

| Complexity | Name | n = 10 | n = 100 | n = 1 000 | n = 10 000 | Practical? |
|------------|------|--------|---------|-----------|------------|------------|
| O(1) | Constant | 1 | 1 | 1 | 1 | Always |
| O(log n) | Logarithmic | 3 | 7 | 10 | 13 | Always |
| O(n) | Linear | 10 | 100 | 1 000 | 10 000 | Usually |
| O(n log n) | Linearithmic | 33 | 664 | 9 966 | 132 877 | Usually |
| O(n²) | Quadratic | 100 | 10 000 | 1 000 000 | 100 000 000 | Small n |
| O(n³) | Cubic | 1 000 | 1 000 000 | 10⁹ | 10¹² | Very small n |
| O(2ⁿ) | Exponential | 1 024 | ~10³⁰ | ~10³⁰¹ | ~10³⁰¹⁰ | Tiny n only |
| O(n!) | Factorial | 3 628 800 | ~10¹⁵⁷ | ~10²⁵⁶⁷ | astronomical | Tiny n only |

## ⚠️ Common Mistakes

1. **Ignoring constant factors**: O(2n) simplifies to O(n), but in practice the factor of 2 matters. Don't over-optimise constants while ignoring the complexity class.
2. **Confusing log₂ with log₁₀**: Both are O(log n) class, but log₂ n ≈ 3.32 × log₁₀ n. When counting halving steps, use log₂.
3. **Assuming small n means O(n²) is fine**: For n = 1 000, n² = 1 000 000 operations — fast. For n = 100 000, n² = 10¹⁰ — too slow. Always consider the expected input size.
4. **Forgetting overflow**: Computing 2³² or 33! in a 32-bit integer overflows silently. Use `long long` and guard against overflow.
5. **Not checking the hidden lower-order terms**: O(n² + n) = O(n²) asymptotically, but for small n the linear term adds up.

## Interview Q&A

**Q: Which grows faster — n² or 2ⁿ?**
A: For n ≤ 4, n² ≥ 2ⁿ. For n ≥ 5, 2ⁿ grows much faster. In complexity analysis we care about large n, so O(2ⁿ) is worse.

**Q: Is O(n log n) always better than O(n²)?**
A: For large n, yes. But for very small n, an O(n²) algorithm with tiny constants (e.g. insertion sort) can beat an O(n log n) algorithm with large overhead (e.g. merge sort).

**Q: How do I estimate log₂ n without a calculator?**
A: Count how many times you can halve n before reaching 1. For n = 1024, halve 10 times → log₂(1024) = 10.

**Q: Can an O(n²) algorithm ever be preferred?**
A: Yes — when n is guaranteed to be small (e.g. n ≤ 50), when constant factors are very small, or when the algorithm is simpler and easier to maintain.

**Q: What if my algorithm has two nested loops but only iterates up to a constant C?**
A: That's O(C²) = O(1), not O(n²). Complexity is always expressed as a function of input size `n`.
