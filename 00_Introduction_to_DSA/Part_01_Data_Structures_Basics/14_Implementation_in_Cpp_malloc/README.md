# MALLOC vs NEW in C++

C++ offers two ways to allocate dynamic memory: the C-style `malloc()`/`free()` and the C++-style `new`/`delete`. The critical difference is that `new` **constructs** objects (calls constructors) while `malloc` just reserves raw bytes — and `delete` calls destructors while `free` does not.

- `malloc(n)` → returns `void*` (needs a cast), allocates **raw, uninitialized** memory.
- `new T` → returns a typed `T*`, allocates **and constructs** (calls constructor).
- `free(ptr)` → releases memory, does **not** call destructors.
- `delete ptr` → calls the destructor, **then** releases memory.
- Array versions: `malloc(n * sizeof(T))` ↔ `new T[n]`, and `delete[]` must match `new[]`.

**Real-world analogy:** malloc gives you an empty room with no furniture; new hands you a fully furnished room. You must use the matching cleanup — `malloc`↔`free`, `new`↔`delete`, `new[]`↔`delete[]`.

---

## Files in this folder

| File                | Purpose                                                                              |
|---------------------|--------------------------------------------------------------------------------------|
| `01_theory.cpp`     | Pure concept + working demo: int and Node allocated BOTH ways, printed, freed.       |
| `task.cpp`          | 7 solved tasks: int/array/Node via both, safe helper, garbage demo, mixing danger.   |
| `README.md`         | This summary + comparison table + mistakes + interview Q&A.                          |

---

## Cheat sheet / syntax

```cpp
#include <cstdlib>   // malloc / free ke liye

int* p1 = (int*)malloc(sizeof(int));   // cast zaroori, value garbage
*p1 = 42;
free(p1);                              // sirf bytes release

int* p2 = new int;                     // no cast, typed pointer
*p2 = 99;
delete p2;                             // destructor (agar hai) + release

int* a1 = (int*)malloc(5 * sizeof(int));
free(a1);

int* a2 = new int[5];
delete[] a2;                           // naya[] ka saathi delete[] hi hai

struct Node { int data; Node* next; Node(){ /* ctor */ } };
Node* n = (Node*)malloc(sizeof(Node)); // ctor NAHI chalega!
Node* m = new Node;                    // ctor chalega
```

---

## malloc vs new comparison

| Feature          | malloc / free            | new / delete                   |
|------------------|--------------------------|--------------------------------|
| Language         | C (works in C++)         | C++ only                       |
| Returns          | `void*` (cast needed)    | Typed pointer (no cast)        |
| Constructor      | NOT called               | Called automatically           |
| Destructor       | NOT called               | Called by `delete`             |
| Size calculation | Manual (`sizeof`)        | Automatic                      |
| Errors           | Returns `NULL`           | Throws `bad_alloc`             |
| Headers          | `<cstdlib>`              | None (keyword)                 |
| Arrays           | `malloc(n*sizeof(T))`    | `new T[n]` + `delete[]`        |

---

## ⚠️ Common mistakes

- Mixing systems: `new`/`free` or `malloc`/`delete` → **undefined behavior, crashes**.
- Forgetting `delete[]` for `new[]` arrays → leak / heap corruption.
- Not casting `void*` from `malloc` → compile error in C++.
- Assuming malloc initializes values → it returns **garbage**.
- Using `sizeof(pointer)` instead of `sizeof(type)` with malloc → wrong memory size.

---

## Interview Q&A

1. **Does malloc call the constructor?** — No. It allocates only raw bytes; `new` calls the constructor.
2. **Why must you cast malloc's return in C++?** — Malloc returns `void*`; C++ needs an explicit cast (unlike C).
3. **Can you use free() on memory allocated with new?** — No. That is undefined behavior; always match `new`↔`delete`, `malloc`↔`free`.
4. **What happens if malloc fails vs new fails?** — Malloc returns `NULL`; `new` throws `std::bad_alloc`.
5. **Why would anyone still use malloc in C++?** — Compatibility with C code or when you truly want raw uninitialized memory for PODs; otherwise prefer `new`.
6. **new[] vs new — difference?** — `new[]` allocates an array; must be freed with `delete[]` so each element's destructor runs.