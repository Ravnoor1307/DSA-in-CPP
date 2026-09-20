# INSERT / DELETE / UPDATE IN ARRAY

## Summary
- Insert at end is O(1) — a single write at `arr[size]`, then `size++` (if a free slot exists).
- Insert in the middle (or start) is O(n) — every element after the position must be right-shifted to open a gap.
- Delete from the middle is O(n) — elements after the position are left-shifted to close the gap.
- Update is O(1) — one direct write, zero shifting.
- Capacity (allocated slots) is always >= size (filled slots); C arrays never check this, so guards are mandatory.

## Real-world analogy
A movie-ticket line: adding a friend in the middle makes everyone behind step back (O(n)); someone leaving up front makes everyone behind step forward (O(n)); serving the person at the front or adding at the back (if space) is instant (O(1)).

## Files + purpose
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Shift logic, ASCII diagrams, step-by-step insert/delete/update demo + edge cases |
| `task.cpp` | 5 solved tasks — sorted insert, delete all x, insert both ends, left shift, dedupe sorted array |
| `README.md` | This quick-reference document |

## Cheat sheet
- Insert at end (capacity available): `arr[size] = x; size++;`
- Insert at position p (right-shift from back):
  `for (int i = size-1; i >= p; i--) arr[i+1] = arr[i]; arr[p] = x; size++;`
- Delete position p (left-shift forward):
  `for (int i = p; i < size-1; i++) arr[i] = arr[i+1]; size--;`
- Update: `arr[p] = x;`
- Guards: insert `size < CAPACITY`, delete `p >= 0 && p < size`

## Complexity table
| Operation | Time | Why |
|-----------|------|-----|
| Insert at end | O(1) | write `arr[size]` + `size++`, no movement |
| Insert at start/middle | O(n) | right-shift up to n elements to open a gap |
| Delete from end | O(1) | just `size--` |
| Delete from start/middle | O(n) | left-shift up to n elements to close the gap |
| Update | O(1) | one direct write at `arr[p]` |
| Space | O(C) | capacity C cells + O(1) temp variable |

## ⚠️ Common mistakes
- Forgetting the capacity guard — writing past the fixed size overflows memory (undefined behaviour).
- Shifting FORWARD when inserting — overwrites values you still need; always right-shift from the back.
- Shifting BACKWARD when deleting — same problem; always left-shift from the front.
- Editing `size` wrongly — after delete the tail duplicates still exist in memory but are ignored via `size--`.
- Negative / out-of-range positions — always guard `0 <= p < size`.
- Zero/one-element edge cases — deleting to size 0 is fine, but inserting into a full array is rejected.

## Interview Q&A
- Q: Why is insert-at-middle O(n) while access is O(1)? A: Access uses the direct address formula `base + i*size`; insert must physically shift every element after p to keep cells contiguous.
- Q: Does `std::vector::push_back` avoid the shift? A: It is amortized O(1) at the back, but `insert` in the middle is still O(n) — same shifting, just hidden.
- Q: Can we delete duplicates in one pass? A: Yes, if sorted — one write-index (read/write cursors) pass, O(n) time, O(1) space.
- Q: How to avoid shifting when inserting? A: Use a data structure with pointers/links (linked list) or process updates in batches — arrays always pay for the shift.
- Q: What happens to the last element after a delete? A: It is duplicated at the tail; `size--` simply excludes it — no need to zero it out.