# DATA STRUCTURE

- A **data structure** is a way of organizing and storing data so it can be used efficiently — it defines the memory layout AND the operations (insert, search, update, delete, traverse).
- A good data structure bundles related facts into one logical unit (e.g. `struct Student { name; marks; }`) instead of scattering them across parallel arrays.
- Operation speeds depend on the structure chosen: arrays give O(1) indexed access, linked lists give O(1) insert at head, trees give O(log n) search.
- **Data Structure + Algorithm = Program**: the structure stores, the algorithm processes.
- There is no single "best" structure — you pick per job (search-heavy, insert-heavy, hierarchical, memory-tight).

**Real-world analogy:** A well-organized library with labelled shelves and a catalogue is a data structure. Your raw pile of books on the floor is just data. Both hold the same books — but finding one when you need it takes seconds with structure and hours without.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | What a data structure is + demo: array of `Student` records with traversal, linear search, update and average — plus duplicate-name edge case. |
| `task.cpp` | 6 problems (EASY → HARD): parallel arrays, array of structs, linear search, bonus update + topper, delete-by-shift, bank account struct. Full solutions inside. |
| `README.md` | Summary, cheat-sheet, complexity table, mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
struct Student {            // data structure: data bundled as one unit
    string name;
    int marks;
};

Student s[100];             // array of structs
s[i].name = "Riya";         // access field with dot operator
s[i].marks += 5;            // update operation

// linear search operation
for (int i = 0; i < n; i++)
    if (s[i].name == key) { found = i; break; }

// delete by shifting (array has no real delete)
for (int i = p; i < n-1; i++) s[i] = s[i+1];
n--;
```

## Complexity comparison

| Operation | Steps performed | Complexity |
|-----------|-----------------|------------|
| Print/traverse n records | 1 visit each → n steps | O(n) |
| Linear search (worst) | compare every record → n steps | O(n) |
| Indexed access `s[i]` | direct jump → 1 step | O(1) |
| Update one record | locate + assign → constant | O(1) |
| Delete by shifting | copy up to n-1 records → n steps | O(n) |
| Total space (array of n) | n records + constants → n + c units | O(n) |

## ⚠️ Common mistakes

- Using parallel arrays and letting indexes drift — one extra/missing write corrupts every pair. Bundle into a struct.
- Forgetting the `break` in linear search on duplicate keys (returns last match instead of first).
- Believing arrays can truly "delete" — deletion is overwrite plus index bookkeeping.
- Dividing by `n` after deleting without decrementing `n` (average gets wrong).
- Choosing a data structure by habit instead of by operation frequency (search-heavy → sorted array/tree, insert-heavy → linked list).
- No bounds check on fixed arrays (`int arr[100]` vs input > 100) — buffer overflow.

## Interview Q&A

- **Q: What is a data structure?** A: An organized way to store data in memory along with the operations to manipulate it efficiently.
- **Q: Why is array access O(1)?** A: Elements are contiguous, so address = base + index × size — one arithmetic jump, no scanning.
- **Q: Why is deletion in an array O(n)?** A: Removing an element shifts every later element left, up to n-1 moves.
- **Q: Parallel arrays vs array of structs?** A: Structs keep related fields together, avoiding index-mismatch bugs and making operations cleaner.
- **Q: How do you choose between structures?** A: By dominant operation — frequent search → sorted array/tree; frequent inserts → linked list; LIFO → stack; FIFO → queue.