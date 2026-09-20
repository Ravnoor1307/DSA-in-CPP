# std::vector — The Dynamic Array

`std::vector` is a self-growing dynamic array: one contiguous memory block that appends, inserts, erases, and resizes automatically. It separates `size` (elements actually stored) from `capacity` (allocated slots), doubling capacity when full so `push_back` stays amortized O(1). Indexing is O(1) via `v[i]`, while `at(i)` adds a checked access that throws `std::out_of_range` on bad indices. Insertion/erasure in the middle costs O(n) because following elements must shift to preserve contiguity. `reserve`, `resize`, `clear`, and `shrink_to_fit` give precise control over memory.

- Real-world analogy: a metro train that automatically adds whole coaches when seats run out (capacity doubling) — the guard walking coach to coach is an iterator, and the train remembers its total coaches separately from passengers actually seated (capacity vs size).

## Files in this folder

| File            | Purpose                                                                 |
| --------------- | ----------------------------------------------------------------------- |
| `01_theory.cpp` | Pure theory: growth mechanism with ASCII doubling diagram, push/insert/erase/resize/reserve/shrink_to_fit demos, `at()` throws edge case, empty-container edge. |
| `task.cpp`      | 6 tasks (easy → hard): remove duplicates by index, reverse by swapping, rotate left by k, running sum, biggest element without sort, delete all rolls < K. |
| `README.md`     | This summary, cheat sheet, complexity derivation, mistakes, interview Q&A. |

## Cheat sheet / syntax table

| Member / snippet                        | What it does                        | Time complexity |
| --------------------------------------- | ----------------------------------- | --------------- |
| `v.push_back(x)`                        | Append x                           | O(1) amortized |
| `v.pop_back()`                          | Remove last element                | O(1) |
| `v.insert(it, x)`                       | Insert x before iterator `it`      | O(n) shift |
| `v.erase(it)`                           | Remove one element                 | O(n) shift |
| `v[i]` / `v.at(i)`                      | Random access (at is checked)      | O(1) |
| `v.front()` / `v.back()`                | First / last element               | O(1) |
| `v.size()`                              | Element count                      | O(1) |
| `v.capacity()` / `v.max_size()`         | Slots allocated / theoretical max  | O(1) |
| `v.clear()`                             | Drop all elements (keeps capacity) | O(n) |
| `v.resize(n)`                           | Force size = n                     | O(n) worst |
| `v.reserve(n)`                          | Pre-allocate n slots               | O(n) worst |
| `v.shrink_to_fit()`                     | Trim capacity to size              | O(n) |
| `v.empty()`                             | Is size zero?                      | O(1) |
| `v.begin()` / `v.end()`                 | Iterators to range boundaries      | O(1) |
| `for (int x : v)`                       | Range-based read loop              | O(n) total |

## Complexity: time & space (with derivation)

- **push_back O(1) amortized**: a doubling copy of n elements happens only every ~n-th push, so n pushes cost n normal appends + (1 + 2 + 4 + ... + n) copies ≈ 2n total → 2 units per push → constant → **O(1) amortized**.
- **insert / erase O(n)**: inserting at position p shifts (n − p) elements right; erasing shifts (n − p − 1) left. Worst case p = 0 shifts all n → **O(n)**.
- **at / [] O(1)**: address = base + index·sizeof(T); one arithmetic step → **O(1)**.
- **resize / reserve / shrink_to_fit O(n)**: any reallocation copies the current n elements into a fresh block → n copies → **O(n)**.
- **Space O(n)**: vector allocates at most 2× the current size before doubling, so memory is between n and 2n slots; a constant factor of 2 → **O(n)**.

## ⚠️ Common mistakes

- Using `v[i]` with a wrong index — silent garbage or crash. Prefer `at()` when the index is user input.
- Calling `front()` / `back()` on an empty vector — undefined behaviour; always check `!v.empty()`.
- Forgetting that `clear()` keeps `capacity()`, then leaking big memory; use `shrink_to_fit()` to release it.
- Not handling iterator invalidation: after `push_back`/`insert`/`erase`, old iterators may point into freed memory — recompute them.
- Inserting at `v.begin()` repeatedly in a loop → O(n²) total from all the shifting; consider a different structure if front-insertion is common.
- Using `size()` (size_t) in `for` loops with signed `i` and `i < v.size() - 1` — underflow when size is 0.

## Interview Q&A

- **Q: Why is push_back amortized O(1) but insert O(n)?** A: push_back only triggers a rare doubling copy that amortizes to O(1) per push; insert in the middle must physically shift every element after it, so worst case it moves all n.
- **Q: Difference between size, capacity, and max_size?** A: size = elements present, capacity = slots already allocated, max_size = largest size the platform can theoretically give.
- **Q: What is iterator invalidation?** A: Structural changes (push_back past capacity, insert, erase) move data to a new block or shuffle it, so old iterators/pointers point to stale memory; dereferencing them is UB.
- **Q: When would you use reserve()?** A: When you know the final count up front (e.g. reading n numbers) — avoids repeated reallocations and keeps memory at exactly what you need.
- **Q: at() vs [].** A: `at()` throws `std::out_of_range` on a bad index (slower, safe); `[]` is unchecked pointer math (fast, dangerous).