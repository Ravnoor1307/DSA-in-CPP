# Pointers

A pointer is a variable that stores the **memory address** of another variable. `&x` gives an address, `*p` dereferences (reads/writes the value at that address). Pointers let functions modify caller data, avoid copying large data, walk arrays via arithmetic, and handle dynamic memory. `nullptr` means "points to nothing."

Real-world analogy: A house is the variable; its address written on a slip is the pointer. You can photocopy the slip (cheap) for many people — they all reach the same single house.

## Files

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: &, *, *pp, pointer arithmetic, pointer size, nullptr — with ASCII arrow diagrams |
| `task.cpp` | 6 tasks: swap, find max, square-by-pointer, count evens, pointer-to-pointer, sum via arithmetic |
| `README.md` | This file — summary, cheat sheet, complexity, mistakes, interview Q&A |

## Cheat Sheet

```cpp
int x = 42;
int* p = &x;      // p ---► x   (stores x's address)
*p = 99;          // writes 99 INTO x (dereference)

int** pp = &p;    // pointer to pointer: pp ---► p ---► x
**pp;             // x's value = 42

int arr[4] = {10,20,30,40};
int* pa = arr;            // arr decayed to &arr[0]
*(pa + 1);                // 20  (same as arr[1])
pa++;                     // skip 1 int (4 bytes)

int* np = nullptr;        // points to nothing
if (np) *np = 5;          // ALWAYS null-check before deref
```

## Complexity

| Operation | Time | Derivation |
|-----------|------|------------|
| &x (address-of) | O(1) | compiler generates address once |
| *p (dereference) | O(1) | one memory read/write |
| p = &x (assign) | O(1) | copy one address |
| pointer walk N elements | O(N) | N increments + N dereferences = 2N ops |

**Space:** One pointer always occupies `sizeof(void*)` bytes — 4 on 32-bit, 8 on 64-bit — no matter what it points to. Additional O(1) per level of indirection.

## Common Mistakes

1. **Dereferencing nullptr**: `*p` when `p == nullptr` → segmentation fault (crash).
2. **Uninitialized pointer**: `int* p;` garbage address — dereferencing is undefined behavior. Always initialize (`= nullptr` or `= &something`).
3. **`*p` vs `p`**: printing `p` gives the address, `*p` gives the value. Mixing them up is the #1 mistake.
4. **`**pp` levels**: `*pp` = value stored in pp (which is an address), `**pp` = value at that address. Count the stars.
5. **Pointer arithmetic units**: `p+1` moves `sizeof(type)` bytes, NOT 1 byte. `int* p; p+1` = 4 bytes ahead.
6. **Comparing `==`**: if the underlying type is a C-string, `p == q` compares ADDRESSES, not contents (use `strcmp`).

## Interview Q&A

**Q: What is a pointer?**
A: A variable storing the memory address of another variable. Declared as `type* name`, dereferenced with `*`.

**Q: Difference between `int* p` and `int** pp`?**
A: `p` stores an int's address; `pp` stores the address of an `int*` — "pointer to pointer." `*pp` gives an address, `**pp` gives the final value.

**Q: What is `nullptr`? Why not `NULL`?**
A: `nullptr` is a typed null pointer constant (type `std::nullptr_t`). `NULL` is just `0` (an integer macro) — `nullptr` is type-safe and preferred in C++.

**Q: What is dangling pointer?**
A: A pointer that points to memory already freed or out of scope. Dereferencing it is undefined behavior. Avoid by resetting to nullptr after delete.