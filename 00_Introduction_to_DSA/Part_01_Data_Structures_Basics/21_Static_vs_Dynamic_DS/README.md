# 21. Static vs Dynamic Data Structures

- A **static** data structure has a **fixed size decided at compile time** (e.g. `int arr[5]`), while a **dynamic** one grows/shrinks at runtime (e.g. `std::vector`, linked list).
- Static structures live typically on the stack, are fastest, and have zero overhead, but can never hold more than their declared size.
- Dynamic structures allocate on the heap and **re-allocate + copy** when full — this is why vectors keep growing seamlessly.
- A vector stores two extra facts: `size()` (elements currently used) and `capacity()` (slots actually reserved).
- Chose static when the count is known in advance; choose dynamic when the count depends on runtime input.

**Real-world analogy:** A wedding hall with exactly 100 fixed chairs (static) vs a food stall that keeps adding and shifting tables for every new customer (dynamic).

## Files in this folder
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concept, ASCII memory-view diagrams, dry run, complexity derivation + working static/vector demo |
| `task.cpp` | 6 graded tasks (easy→hard) with hint, starter TODO, and fully solved code |
| `README.md` | This summary, cheat sheet, common mistakes, interview Q&A |

## Cheat sheet / syntax
```cpp
int arr[5] = {1,2,3,4,5};              // static: 5 slots forever
int sz = sizeof(arr)/sizeof(arr[0]);   // count elements (bytes / one element)

#include <vector>
vector<int> v;         // dynamic, starts empty
v.push_back(10);       // add at the end
v.size();              // elements used
v.capacity();          // slots reserved (>= size)
v.reserve(10);         // fix capacity in advance
v.shrink_to_fit();     // trim capacity down to size
```

## Complexity comparison
| Operation | Static array | Vector (amortised) |
|-----------|--------------|---------------------|
| Access index `i` | O(1) | O(1) |
| Add at end | Impossible (out of bounds) | O(1) amortised |
| Insert at middle | Shifting, O(n) | Shifting, O(n) |
| Extra memory | none | up to ~2x spare capacity |

## ⚠️ Common mistakes
- Writing `arr[n]` beyond the declared size — **undefined behaviour**, may crash or print garbage.
- Confusing `size()` (used) with `capacity()` (reserved) when debugging a vector.
- Using a fixed array for user-driven input without bounds checking.
- Forgetting `#include <vector>` and `#include <iostream>`.

## Interview Q&A
- **Q1:** Difference between static and dynamic? — Static has fixed compile-time size and can't grow; dynamic grows at runtime via heap allocation.
- **Q2:** Why use a vector? — Гif size is unknown, it re-allocates and copies when full (amortised O(1) push).
- **Q3:** What is re-allocation? — When `size == capacity`, vector allocates a bigger block (usually 2x), copies all elements, frees the old block.
- **Q4:** Which is faster, array or vector for indexed access? — Both O(1); plain array has zero overhead but cannot grow.