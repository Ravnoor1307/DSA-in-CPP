# Pointers with Arrays

An array name **decays** to a pointer to its first element when passed to a function. `arr[i]` is identical to `*(arr + i)` — the compiler translates everything to pointer arithmetic. Functions receiving arrays actually receive a single pointer (no copy). Arrays and pointers differ: `sizeof(arr)` gives the whole array, `sizeof(p)` gives 8 bytes; arrays can't be reassigned, pointers can.

Real-world analogy: A delivery list of addresses — you hand the courier the FIRST address; they walk the rest one by one. You never hand over the whole list (no copying of the array happens).

## Files

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: decay, arr[i]==*(arr+i), passing arrays, sizeof difference, two-pointer reverse |
| `task.cpp` | 6 tasks: array sum, largest, reverse in-place, count occurrences, selection sort, two sum |
| `README.md` | This file — summary, cheat sheet, complexity, mistakes, interview Q&A |

## Cheat Sheet

```cpp
int arr[5] = {7, 14, 21, 28, 35};
int* p = arr;             // decay: p = &arr[0]

arr[2] == *(arr + 2) == *(p + 2) == p[2]   // all 21

// pass to function — only ONE pointer copied
int sumArr(int* arr, int n);   // same as int sumArr(int arr[], int n)
sumArr(arr, 5);

// two-pointer reverse
int l = 0, r = n - 1;
while (l < r) { swap(arr[l], arr[r]); l++; r--; }

// differences
sizeof(arr);   // 20 (whole array, 5 * 4 bytes)
sizeof(p);     // 8  (pointer, fixed)
arr = p;       // ERROR — array name can't be reassigned
p = arr;       // OK — pointer can move anywhere
```

## Complexity

| Operation | Time | Derivation |
|-----------|------|------------|
| arr[i] / *(arr+i) | O(1) | one memory access, `i*sizeof(int)` offset |
| Array sum | O(N) | N iterations, each an add |
| Find max / count | O(N) | N comparisons |
| Reverse (two ptr) | O(N) | N/2 swaps, each O(1) |
| Selection sort | O(N²) | N outer × N inner scans = N² compares |

**Space:** array `N*sizeof(int)`. Passing to a function copies just the pointer (8 bytes) — no array copy, so O(1) extra. In-place operations add nothing.

## Common Mistakes

1. **`sizeof` mistake**: `sizeof(arr)` inside a function equals 8 (pointer), not the array size. Pass `n` separately.
2. **Reassigning an array name**: `arr = other;` is a compile error — arrays are fixed; use a pointer.
3. **Passing without size**: `void f(int arr[])` gives no length — always pass `n`.
4. **Out-of-bounds walking**: `for (int i = 0; i <= n; i++)` reads one past the end — use `< n`.
5. **`p+1` is not `p` + 1 byte**: it's `sizeof(int)` bytes ahead. Misusing this breaks indexing.
6. **Null array**: passing `nullptr` length `0` — always null-check/early-return for size 0 arrays.

## Interview Q&A

**Q: What does array decay mean?**
A: In most expressions, an array name converts to a pointer to its first element (`&arr[0]`). Inside functions, `int arr[]` and `int* arr` are literally the same parameter.

**Q: `arr[i]` and `*(arr+i)` — same?**
A: Yes, the compiler defines `arr[i]` as `*(arr + i)`. The only exception is inside `sizeof(arr)` and `&arr` where no decay happens.

**Q: Why can't I assign to an array name?**
A: An array name is a fixed starting address with no pointer variable behind it. Use `int* p = arr;` then redirect `p` freely.

**Q: How do I get the array size from a pointer?**
A: You can't — pointer only stores the start address. Pass the length as a parameter (or know it from the container).