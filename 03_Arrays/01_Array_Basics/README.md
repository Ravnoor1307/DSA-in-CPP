# ARRAY BASICS — Memory Layout, Indexing & Traversal

## Summary
- An array is a fixed-size collection of same-type elements stored in CONTIGUOUS memory, enabling direct indexed access.
- Address of element i = `base + i * size_of_element`; for `int` every element sits exactly 4 bytes after the previous one.
- Array access and update are O(1) — a single arithmetic jump, no search involved.
- Traversal (print / sum / find) touches all n elements once, so it is O(n).
- 2D arrays are stored row-major; the flat index of `mat[r][c]` is `r * cols + c`.

## Real-world analogy
A cinema row has fixed numbered seats — you jump straight to seat 4, never checking seats 1–3. A train coach has berths numbered 1..20 in one fixed strip — you jump directly to berth 12. Arrays give the same instant jump to any numbered cell.

## Files + purpose
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concepts, ASCII memory maps, address formula, running demo + edge cases |
| `task.cpp` | 5 solved tasks — max, second max, sum & average, linear search, reverse print |
| `README.md` | This quick-reference document |

## Cheat sheet
- Address formula: `addr(arr[i]) = base + i * size_of_element`
- Flat 2D index (row-major): `flat = r * cols + c`
- Traversal pattern: `for (int i = 0; i < n; i++) { ... arr[i] ... }`
- Safe-access guard: `if (i < 0 || i >= n) { /* reject */ } else { use arr[i] }`
- Update: `arr[i] = value;` (O(1) — direct write)

## Complexity table
| Operation | Time | Why |
|-----------|------|-----|
| Access `arr[i]` | O(1) | address = base + i*4 — one multiply-add, no search |
| Update `arr[i]` | O(1) | one write at the computed address |
| Traversal | O(n) | must visit all n elements |
| 2D access `mat[r][c]` | O(1) | `r*cols + c` is pure arithmetic |
| Space | O(n) | n cells stored + O(1) loop variables |

## ⚠️ Common mistakes
- Index out of range — C arrays give NO warning; always guard negative or `>= n` indices.
- Forgetting 0-indexing: the last valid index is `n-1`, not `n`.
- Integer division for average — cast to `double` first, else fractional part is lost.
- Treating `arr` and `&arr[i]` confusingly — `arr` alone decays to the base address.
- Reading uninitialized cells — only indices `0..n-1` are your data.

## Interview Q&A
- Q: Why is array access O(1)? A: `addr = base + i*size` is one formula — no loop, no search, just a multiply-add.
- Q: How is a 2D array stored? A: Row-major — row 0 fully, then row 1...; flat index = `r*cols + c`.
- Q: Can we find the max without extra memory? A: Yes — one running-best variable, O(n) time, O(1) space.
- Q: Why is the last element at `n-1`? A: 0-based indexing; the offset `i` starts at 0, so `arr[n-1]` is the nth cell.
- Q: Which is faster — `arr[5000]` or searching a list for value X? A: `arr[5000]` is instant O(1); searching is O(n).