# 09 — Drawbacks / Limitations of Array

- An array reserves one contiguous block of memory once, so its size is **fixed for life** — you cannot grow or shrink it at runtime.
- **Inserting or deleting in the middle is costly**: every element after the position must be shifted, giving O(n) worst-case time.
- You pay for the **capacity**, not the count — unused slots are wasted memory, and the whole array needs one uninterrupted stretch of RAM (fragmentation).
- C++ performs **no bounds checking**: `arr[size]` is undefined behaviour, not an error you can catch.
- Understanding these weaknesses is the motivation for the **linked list**, which trades random access for cheap middle insert/delete.
- Real-world analogy: a **fixed 100-seat cinema hall** — you cannot add seat 101, the middle rows force everyone to shuffle, and empty seats still cost rent.
- Files in this folder:
  | File | Purpose |
  |---|---|
  | `01_theory.cpp` | Theory + demo: insert/delete shift counts, wastage table, full-array rejection |
  | `task.cpp` | 5 tasks (EASY→HARD): shift formula, insertAt, deleteAt, wastage, sorted insert |
  | `README.md` | This cheat sheet |
- Cheat sheet / key snippets:

  ```cpp
  int shifts = n - pos;                // elements that must move on insert
  for (int i = n; i > pos; --i)        // INSERT: shift from BACK (else data lost)
      arr[i] = arr[i - 1];
  for (int i = pos; i < n - 1; ++i)    // DELETE: shift from FRONT
      arr[i] = arr[i + 1];
  int wasted = (capacity - used) * sizeof(int);   // bytes paid for but unused
  ```

- Complexity comparison table:

  | Operation | Derivation | Array |
  |---|---|---|
  | Access `arr[i]` | base + i×w = 2 fixed ops | **O(1)** |
  | Insert at p | (n − p) shifts + 1 write | worst **O(n)**, append Ω(1) |
  | Delete at p | (n − 1 − p) shifts | worst **O(n)**, tail Ω(1) |
  | Search | worst n comparisons | O(n) |
  | Space (total) | capacity × sizeof(type) | O(n) |
  | Space (auxiliary) | 1 temp for shifting | **O(1)** |

- ⚠️ Common mistakes:
  1. **Inserting from the front first** — overwrites values before they are copied. Always shift **back-to-front**.
  2. **Deleting from the back first** — wrong direction; delete shifts **front-to-back**.
  3. **Counting memory by `used`** — an array occupies `capacity × size` bytes even with 1 element.
  4. **Thinking the array is "bad"** — access is O(1), memory is 4× cheaper, and it is cache friendly. It is a trade-off, not a villain.
  5. **Writing `arr[100]` on a size-5 array** — C++ will not stop you; `vector.at(i)` throws instead.
- Interview Q&A:
  - **Q: Why is inserting into an array O(n)?** A: The block is contiguous, so a middle hole cannot exist; each of the (n−p) elements after p must be copied one step right.
  - **Q: Which array operation is O(1) and why?** A: Access — the address is `base + i×elementSize`, two fixed arithmetic operations, no matter how large n is.
  - **Q: What does "memory wastage" mean for arrays?** A: Allocation happens for capacity, not usage; `(capacity − n) × size` bytes stay reserved and unused.
  - **Q: Where does the linked list beat this?** A: Known-position insert/delete becomes O(1) pointer swaps, size grows freely, and scattered memory works — that is the next topic (Folder 10).