# Time-Space Trade-Off

The time-space trade-off is a fundamental principle in computer science: you can often reduce an algorithm's running time by using more memory, or reduce memory usage at the cost of more time. The most common technique exploiting this trade-off is **memoisation** (top-down dynamic programming), where computed results are stored in an array/table so they never need to be recomputed. This converts an exponential-time recursive algorithm into a polynomial-time algorithm at the cost of O(n) extra memory. Other examples include prefetching (cache memory), index tables (database indexes), and lookup tables (precomputed sin/cos values).

Real-world analogy: Imagine you are solving math homework. Without memoisation, every time you need fib(5), you re-derive fib(4) and fib(3) from scratch — like a student who never writes anything down. With memoisation, you write each answer in a notebook. Next time you need it, you just look it up — O(1). You use an extra notebook (memory), but save enormous time. The notebook is your "memo table."

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory + demo: naive recursive fib vs memoised DP fib with step counters and memory tracking, ASCII recursion tree vs memo table |
| `task.cpp` | Practice tasks: implement both approaches, compare step counts empirically, extend to other problems |
| `README.md` | This file — summary, derivation of recurrences, comparison table, interview Q&A |

## Cheat Sheet — Key Recurrences

| Approach | Recurrence | Solution | Space |
|----------|------------|----------|-------|
| Naive recursive fib | T(n) = T(n-1) + T(n-2) + O(1) | O(2ⁿ) time | O(n) stack |
| Memoised fib | T(n) = O(1) per unique subproblem, n subproblems | O(n) time | O(n) table + O(n) stack |
| Iterative DP fib | T(n) = O(1) per step, n steps | O(n) time | O(1) or O(n) |

**Key insight:** Memoisation eliminates redundant computation. In naive fib, fib(3) is computed ~2^(n-3) times. With memoisation, each value is computed exactly once.

## ASCII: Recursion Tree vs Memo Table

**Naive Recursion Tree for fib(5):**
```
                    fib(5)
                   /      \
              fib(4)       fib(3)
             /     \       /    \
         fib(3)  fib(2) fib(2) fib(1)
         /   \    / \     / \
     fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
     / \
 fib(1) fib(0)

Total nodes: 15 (many duplicates!)
fib(3) computed 2 times, fib(2) computed 3 times, fib(1) computed 5 times
```

**Memo Table (filled once, looked up thereafter):**
```
Index:  0   1   2   3   4   5
Value: [0] [1] [1] [2] [3] [5]
        ↑   ↑   ↑   ↑   ↑   ↑
      filled bottom-up, each cell written ONCE
Total writes: 6 (n+1), Total lookups: O(n)
```

## Time-Space Trade-Off Examples

| Problem | Without trade-off | With trade-off | Saved |
|---------|-------------------|----------------|-------|
| Fibonacci | O(2ⁿ) time, O(n) space | O(n) time, O(n) space | Exponential time saved |
| Subsequence sum | O(2ⁿ) time | O(n × sum) time, O(n × sum) space | Time, if sum is bounded |
| Shortest path (Dijkstra) | O(V²) time | O((V+E) log V) time, O(V) space with heap | Time |
| String matching (KMP) | O(n×m) time, O(1) space | O(n+m) time, O(m) space for prefix table | Time |

## ⚠️ Common Mistakes

1. **Memoising the wrong subproblems**: If the recursive function has parameters that change, you need a 2D memo table. A 1D table won't work for knapsack.
2. **Forgetting that memoisation adds space**: Memoised fib is O(n) space for the table. If memory is extremely tight, iterative bottom-up DP with O(1) space might be better.
3. **Assuming memoisation always helps**: If subproblems don't repeat (e.g. simple recursion with no overlapping subproblems), memoisation adds overhead with no benefit.
4. **Confusing memoisation with tabulation**: Memoisation = top-down (recursive, fill as needed). Tabulation = bottom-up (iterative, fill all). Both are dynamic programming.
5. **Not considering the stack space**: Recursive fib uses O(n) call stack. Even without a memo table, the stack itself is O(n) space.

## Interview Q&A

**Q: What is the time-space trade-off?**
A: You can use extra memory to store intermediate results (memoisation, lookup tables, indexes) to avoid recomputation, reducing time complexity. Alternatively, you can recompute values to save memory (e.g. generator functions vs precomputed arrays).

**Q: When would you prefer O(n²) time with O(1) space over O(n) time with O(n) space?**
A: When memory is extremely constrained (embedded systems, GPU kernels) or when n is small enough that n² is fast. Also when the O(n) space version has large constants.

**Q: Is there always a time-space trade-off?**
A: No. Some problems have optimal algorithms that are both time- and space-efficient. Also, some problems have inherent lower bounds (e.g. comparison sorts need Ω(n log n) time regardless of space).

**Q: What's the difference between memoisation and caching?**
A: Memoisation is a specific form of caching for function results based on arguments. Caching is a broader term that includes result caching, page caching, DNS caching, etc. All memoisation is caching, but not all caching is memoisation.

**Q: How does the fibonacci example demonstrate the trade-off?**
A: Naive recursion: O(2ⁿ) time, O(n) stack space. Memoised: O(n) time, O(n) table + O(n) stack = O(n) space. Same space class, but exponential time reduction. True trade-off visible when comparing to iterative DP: O(n) time, O(1) space — no trade-off needed if you restructure the algorithm.
