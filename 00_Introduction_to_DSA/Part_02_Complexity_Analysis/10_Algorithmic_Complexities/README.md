# Algorithmic Complexity Classes

Every algorithm belongs to a complexity class that describes how its running time (or space) grows as a function of the input size `n`. The major classes — O(1), O(log n), O(n), O(n log n), O(n²), O(2ⁿ), and O(n!) — form a hierarchy from fastest to slowest. Knowing which class an algorithm falls into lets you immediately predict its scalability. This topic maps concrete, well-known algorithms to their respective classes and demonstrates the enormous empirical difference between a naive exponential approach and a polynomial/dynamic-programming approach using Fibonacci as the canonical example.

Real-world analogy: Think of transportation speeds. O(1) is an elevator — fixed time regardless of building height. O(log n) is a GPS navigator — it narrows down destinations quickly. O(n) is walking every street once. O(n log n) is sorting your errands by distance then walking them. O(n²) is comparing every pair of items in a shopping list. O(2ⁿ) is trying every possible route between all stores. O(n!) is trying every possible visit order — completely absurd for more than a handful of stops.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory + demo: maps algorithms to classes, demos naive fib vs DP fib with step counting, prints the enormous difference |
| `task.cpp` | Practice tasks: classify code snippets into complexity classes with derivation, implement and compare fib approaches |
| `README.md` | This file — summary, algorithm-to-class mapping, cheat sheet, interview Q&A |

## Cheat Sheet — Algorithm → Complexity Class

| Algorithm | Technique | Time | Space | Class |
|-----------|-----------|------|-------|-------|
| Array index access | Direct indexing | O(1) | O(1) | Constant |
| Binary search | Divide & conquer | O(log n) | O(1) | Logarithmic |
| Linear search | Scan one by one | O(n) | O(1) | Linear |
| Merge sort | Divide & conquer + merge | O(n log n) | O(n) | Linearithmic |
| Heap sort | Heapify + extract | O(n log n) | O(1) | Linearithmic |
| Bubble sort | Nested compare-swap | O(n²) | O(1) | Quadratic |
| Selection sort | Nested min-find | O(n²) | O(1) | Quadratic |
| Insertion sort | Insert into sorted prefix | O(n²) avg | O(1) | Quadratic |
| Subset generation | Recursive include/exclude | O(2ⁿ) | O(n) | Exponential |
| Recursive Fibonacci | Two recursive calls per call | O(2ⁿ) | O(n) stack | Exponential |
| Permutations | Swap each position | O(n!) | O(n) | Factorial |

## Complexity Comparison — Concrete Operations

| Class | n = 10 | n = 20 | n = 30 | n = 50 | Scalability |
|-------|--------|--------|--------|--------|-------------|
| O(1) | 1 | 1 | 1 | 1 | Excellent |
| O(log n) | 3 | 4 | 5 | 6 | Excellent |
| O(n) | 10 | 20 | 30 | 50 | Very good |
| O(n log n) | 33 | 86 | 149 | 282 | Good |
| O(n²) | 100 | 400 | 900 | 2 500 | Moderate |
| O(n³) | 1 000 | 8 000 | 27 000 | 125 000 | Poor |
| O(2ⁿ) | 1 024 | ~1 million | ~1 billion | ~10¹⁵ | Terrible |
| O(n!) | 3.6 million | ~2.4 × 10¹⁸ | ~2.7 × 10³² | ~3 × 10⁶⁴ | Impossible |

## Recurrence Relations Cheat Sheet

| Class | Recurrence | Example |
|-------|------------|---------|
| O(1) | T(n) = c | Array access |
| O(log n) | T(n) = T(n/2) + c | Binary search |
| O(n) | T(n) = T(n-1) + c → telescoping | Linear search |
| O(n log n) | T(n) = 2T(n/2) + O(n) | Merge sort |
| O(n²) | T(n) = T(n-1) + O(n) → sum 1..n = n(n+1)/2 | Bubble sort |
| O(2ⁿ) | T(n) = T(n-1) + T(n-2) + O(1) ≈ O(2ⁿ) | Naive fib |
| O(n!) | T(n) = n × T(n-1) + O(n) | Permutations |

## ⚠️ Common Mistakes

1. **Confusing best/average/worst case**: Bubble sort is O(n²) worst case but O(n) best case (already sorted). Always clarify which case you mean.
2. **Claiming recursion = O(2ⁿ)**: Not all recursion is exponential. Binary search is recursive and O(log n). Check the branching factor.
3. **Ignoring space complexity**: Merge sort is O(n log n) time but O(n) space. In-place sort like heap sort is O(1) extra space.
4. **Forgetting that O(2ⁿ) ≠ O(n²)**: Exponential means doubling with each +1 of n. Quadratic means quadrupling when n doubles. Completely different leagues.
5. **Not using memoisation when subproblems repeat**: If a recursive solution recomputes the same subproblems (like naive fib), memoisation can reduce from O(2ⁿ) to O(n).

## Interview Q&A

**Q: How do you prove an algorithm is O(n log n)?**
A: Show the recurrence T(n) = 2T(n/2) + O(n) and solve via the Master Theorem: a=2, b=2, f(n)=n → log_b(a) = 1, f(n) = Θ(n^1) → T(n) = Θ(n log n).

**Q: What's the difference between O(n log n) and O(n) × O(log n)?**
A: Mathematically they are the same: n × log n = n log n. But structurally, O(n log n) typically arises from divide-and-conquer (merge at each level, log n levels), while O(n) × O(log n) might mean "do an O(log n) operation for each of n elements" (e.g. insertion into a balanced BST for each element).

**Q: Why is naive Fibonacci O(2ⁿ)?**
A: The recurrence T(n) = T(n-1) + T(n-2) + O(1) creates a binary recursion tree of height n. The number of nodes is Θ(2ⁿ) because each level roughly doubles the work. (More precisely, it's Θ(φⁿ) where φ ≈ 1.618, which is still O(2ⁿ).)

**Q: What algorithm class does hash table lookup belong to?**
A: O(1) average case, O(n) worst case (all keys collide). In practice with a good hash function, it's effectively O(1).

**Q: Can you have an algorithm better than O(n)?**
A: Yes — O(log n) for binary search, O(1) for hash lookup. But these require specific data structures or preconditions (sorted data, hash table).
