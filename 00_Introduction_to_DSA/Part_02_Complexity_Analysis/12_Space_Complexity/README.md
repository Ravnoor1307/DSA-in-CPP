# Space Complexity

Space complexity measures the total amount of memory an algorithm needs as a function of the input size `n`. It includes both the **input space** (memory for the input itself) and **auxiliary space** (extra memory the algorithm allocates beyond the input). Understanding space complexity is critical when working with memory-constrained systems (embedded devices, mobile phones) or when processing very large datasets that may not fit in RAM. Common space-complexity classes are O(1) (constant), O(n) (linear), and O(n²) (quadratic), each arising from different programming patterns.

Real-world analogy: Imagine you're working on a puzzle. O(1) space is like having a single sticky note to jot down one number as you work — you never need more. O(n) space is like spreading all puzzle pieces on a table — the number of pieces scales with the puzzle size. O(n²) space is like needing a separate reference sheet comparing every pair of pieces. The space complexity tells you how much table space you'll need as the puzzle gets bigger.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory + demo: O(1) sum vs O(n) array copy with byte-level sizeof accounting, O(n²) matrix allocation |
| `task.cpp` | Practice tasks: analyse space of bubble sort, two-pointer technique, array copy; compute sizeof totals |
| `README.md` | This file — summary, space-class reference, sizeof accounting guide, interview Q&A |

## Cheat Sheet — Space Classes

| Class | Description | Example Pattern | Typical Usage |
|-------|-------------|-----------------|---------------|
| O(1) | Fixed extra variables | Single accumulator, two pointers | Sum of array, two-sum (sorted) |
| O(log n) | Recursion stack depth log n | Binary search recursion | Binary search |
| O(n) | One extra array of size n | Copy array, memo table | Merge sort auxiliary, memoisation |
| O(n²) | 2D array of size n×n | Adjacency matrix, DP table | Floyd-Warshall, LCS table |
| O(n log n) | Recursive stack + array | Merge sort recursion | Merge sort (stack depth log n + array n) |

## Space Breakdown by Algorithm

| Algorithm | Input Space | Auxiliary Space | Total Space |
|-----------|-------------|-----------------|-------------|
| Sum of array (accumulator) | O(n) for array | O(1) for sum variable | O(n) input dominant |
| Linear search | O(n) for array | O(1) for index | O(n) input dominant |
| Binary search (iterative) | O(n) for array | O(1) for lo, hi, mid | O(n) input dominant |
| Binary search (recursive) | O(n) for array | O(log n) stack | O(n) input dominant |
| Merge sort | O(n) for array | O(n) for temp array | O(n) |
| Bubble sort | O(n) for array | O(1) for temp swap | O(n) input dominant |
| Naive fibonacci (recursive) | O(1) for n | O(n) call stack | O(n) |
| Memoised fibonacci | O(1) for n | O(n) memo table + O(n) stack | O(n) |

## sizeof Accounting Guide

In C++, `sizeof(type)` gives bytes:
| Type | sizeof (typical) | Purpose |
|------|-------------------|---------|
| `bool` | 1 | Boolean flag |
| `char` | 1 | Character |
| `int` | 4 | Integer |
| `long long` | 8 | Large integer |
| `float` | 4 | Single-precision float |
| `double` | 8 | Double-precision float |
| `int*` (pointer) | 4 or 8 | Depends on 32/64-bit system |
| `int[n]` | 4 × n | Array of n integers |

**Formula for an `int` array of size n:**
```
Total bytes = sizeof(int) × n = 4n bytes
```

**Formula for a 2D `int` matrix of size n×n:**
```
Total bytes = sizeof(int) × n × n = 4n² bytes
```

## ASCII: O(1) vs O(n) Memory Usage

```
O(1) Space — Sum of Array:
┌──────────────────────────────┐
│ Input array (external)       │ ← O(n), but NOT counted in auxiliary
│ [10, 20, 30, 40, 50]        │
│                              │
│ Auxiliary variables:         │
│ ┌──────┐  ┌───────┐         │
│ │ sum  │  │   i   │  ← 8 bytes total │
│ │  150 │  │   5   │         │
│ └──────┘  └───────┘         │
└──────────────────────────────┘
Auxiliary Space = O(1) ✓

O(n) Space — Copy Array:
┌──────────────────────────────┐
│ Input array (external)       │
│ [10, 20, 30, 40, 50]        │
│                              │
│ Auxiliary: NEW array of n    │
│ ┌──────┬──────┬──────┬──────┬──────┐
│ │  10  │  20  │  30  │  40  │  50  │ ← 20 bytes │
│ └──────┴──────┴──────┴──────┴──────┘
│                              │
│ Plus: i variable (4 bytes)   │
└──────────────────────────────┘
Auxiliary Space = O(n) ✓
```

## ⚠️ Common Mistakes

1. **Confusing input space with auxiliary space**: When we say "space complexity = O(1)", we typically mean auxiliary space. The input itself always takes space. Clarify which you mean.
2. **Forgetting recursion stack space**: A recursive function with depth n uses O(n) stack space even if it declares no local arrays. Always account for the call stack.
3. **Assuming vectors always resize**: `std::vector<int> v(n)` allocates n elements upfront — O(n) space. But `push_back` may cause reallocations. Reserve if you know the size.
4. **Ignoring string storage**: `std::string` of length n uses O(n) space. Copying strings doubles memory usage.
5. **Not considering pointers vs copies**: Passing a vector by value copies it (O(n) space). Passing by reference uses O(1) extra space.

## Interview Q&A

**Q: What is the difference between space complexity and memory usage?**
A: Space complexity is an asymptotic measure — how memory scales with n. Memory usage is the actual bytes consumed at runtime. Space complexity abstracts away constants and overhead.

**Q: How do you calculate the space complexity of a recursive function?**
A: Count: (1) space per stack frame (local variables, parameters), (2) maximum recursion depth. Total auxiliary space = frame_size × depth. For fib: frame has O(1) locals, depth is n → O(n).

**Q: Why do we sometimes say O(n) space when the input is also O(n)?**
A: If auxiliary space is O(1), total is O(n) input + O(1) auxiliary = O(n). We usually report auxiliary space separately: "O(n) time, O(1) auxiliary space."

**Q: What's O(1) space example?**
A: Reversing an array in-place with two pointers (swap first/last, move inward). Only two index variables needed regardless of array size.

**Q: Can a function use O(n) auxiliary space but still be "in-place"?**
A: No. "In-place" means O(1) auxiliary space. However, some definitions are looser, allowing O(log n) space (e.g. in-place merge sort variants with log n recursion stack).
