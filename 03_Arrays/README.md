# 03_Arrays — Arrays for DSA

Complete arrays module in C++. Every topic follows the strict notes format:
real-world scenario → English theory doc → step-by-step logic with WHY → ASCII visuals →
dry run → full complexity derivation → approach comparison. Inline code comments in
Hinglish, all code compile-ready.

## Folder Tree

```txt
03_Arrays/
├── 01_Array_Basics/
│   ├── 01_theory.cpp       → contiguous memory, base+offset addressing, O(1) access/update
│   ├── task.cpp            → 5-6 tasks EASY→HARD with solutions
│   └── README.md
├── 02_Array_Operations_Insert_Delete/
│   ├── 01_theory.cpp       → insert end O(1) vs middle/start O(n) shift, delete, update
│   ├── task.cpp
│   └── README.md
├── 03_Searching_Algorithms/
│   ├── 01_theory.cpp       → linear vs binary, first/last occurrence, count, BS on answer
│   ├── task.cpp
│   └── README.md
├── 04_Sorting_Algorithms/
│   ├── 01_theory.cpp       → bubble, selection, insertion, merge, quick (lomuto/random), counting
│   ├── task.cpp
│   └── README.md
├── 05_Array_Reverse_Rotate/
│   ├── 01_theory.cpp       → two-pointer reverse, rotate by one/k, reversal algorithm
│   ├── task.cpp
│   └── README.md
├── 06_Two_Pointer_Technique/
│   ├── 01_theory.cpp       → pair sum, move zeros, remove duplicates (sorted)
│   ├── task.cpp
│   └── README.md
├── 07_Prefix_Sum_Technique/
│   ├── 01_theory.cpp       → range sum queries, 2D prefix, equilibrium index
│   ├── task.cpp
│   └── README.md
├── 08_Sliding_Window/
│   ├── 01_theory.cpp       → fixed window, variable window, monotonic deque, first negative
│   ├── task.cpp
│   └── README.md
├── 09_Frequency_Counting/
│   ├── 01_theory.cpp       → naive nested, visited-marking, hash-map counting, max occurring
│   ├── task.cpp
│   └── README.md
├── 10_Array_Problems_Easy/
│   ├── 01_theory.cpp       → isSorted, remove element, largest three, segregate even/odd, leaders, stock
│   ├── task.cpp
│   └── README.md
├── 11_Array_Problems_Medium/
│   ├── 01_theory.cpp       → Kadane (max subarray), Moore's voting (majority), rain water
│   ├── task.cpp
│   └── README.md
└── 12_Array_Problems_Hard/
    ├── 01_theory.cpp       → max consecutive ones, longest consecutive sequence, next permutation, rotate matrix
    ├── task.cpp
    └── README.md
```

## Master comparison table

| Section | Main patterns | Key complexity ideas |
|---|---|---|
| 01_Array_Basics | contiguous layout, indexed access | access/update `O(1)`, traversal `O(n)` |
| 02_Insert/Delete/Update | shift-based insert/delete | end/update `O(1)`, middle/start `O(n)` |
| 03_Searching | linear, binary, first/last, BS on answer | linear `O(n)`, binary `O(log n)` |
| 04_Sorting | bubble, selection, insertion, merge, quick, counting | `O(n²)`, merge/quick `O(n log n)`, counting `O(n+k)` |
| 05_Reverse/Rotate | two pointers, rotate-by-k, reversal algo | reverse `O(n)/O(1)`, rotate `O(n)` best |
| 06_Two_Pointer | pair sum, move zeros, dup removal | brute `O(n²)` → pointer `O(n)` |
| 07_Prefix Sum | range queries, 2D prefix, equilibrium | build `O(n)`, query `O(1)` |
| 08_Sliding Window | fixed/variable window, deque | brute `O(n·k)` → `O(n)` |
| 09_Frequency | nested, visited, hashing | `O(n²)` → `O(n)` average |
| 10_Easy Problems | single-pass scanning patterns | mostly `O(n)` |
| 11_Medium Problems | Kadane, Moore, rain water | brute `O(n²)`, optimized `O(n)` |
| 12_Hard Problems | k-flips window, set/sort, permutation, matrix | `O(n)`, `O(n log n)`, `O(n²)` |

## Must-remember formulas

```cpp
// Array addressing
address(arr[i]) = base + i * sizeof(type);
linearIndex2D   = row * cols + col;          // row-major

// Binary search
mid = low + (high - low) / 2;                // overflow-safe
n / 2^k = 1  ->  k = log2(n);

// Prefix sum
prefix[i] = prefix[i-1] + arr[i];
rangeSum(l, r) = prefix[r] - prefix[l-1];

// Sliding window
newSum = oldSum - arr[left] + arr[right];    // incoming - outgoing

// Rotation
newIndex = (i + k) % n;
leftRotate(k) == rightRotate(n - k);

// Kadane (max subarray)
cur = max(arr[i], cur + arr[i]);
best = max(best, cur);

// Rain water trapped at i
water[i] = min(leftMax[i], rightMax[i]) - height[i];

// Next permutation
// find rightmost pivot where a[i] < a[i+1] -> swap with next greater in suffix -> reverse suffix
```

## Completion checklist

- Real-world scenario in every `01_theory.cpp`
- English doc blocks (theory/logic/scenario) + Hinglish inline code comments
- ASCII visual walkthroughs everywhere
- Dry run states included
- Complexity always derived step-by-step before stating Big-O (no bare `O(?)`)
- Compile-ready C++ (`g++ -std=c++17 -Wall`), edge cases handled
- `01_theory.cpp` contains no tasks; tasks live only in `task.cpp`
- `README.md` + `task.cpp` present in every section