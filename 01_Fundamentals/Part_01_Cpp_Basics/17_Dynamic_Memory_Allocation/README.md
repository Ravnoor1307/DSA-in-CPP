# 17. Dynamic Memory Allocation — new / delete

> **Ek line me:** Ab aapke paas wo taakat hai jo pehle nahi thi — **chalte-chalte memory maangna** (runtime size) aur cheez ko **function ke baad bhi zinda rakhna**. Heap isi se banta hai — Stack fixed-size automatic hota hai, Heap dynamic aur manual.

Dynamic allocation lets you get memory at RUN TIME (when the user tells you the size), from a large region called the HEAP. It must be freed manually with `delete` / `delete[]`. Forgetting to free = memory leak; using a pointer after free = dangling pointer (undefined behavior).

- **Real-world analogy:** A movie theatre has 100 fixed seats (stack). 150 people arrive → the manager rents 50 extra chairs at runtime (heap), then must return them after the show (delete[]). Forgetting to return them = rows of chairs permanently blocking the hall (leak). Sitting on a returned chair = dangling pointer.
- **Files in this folder:**
  - `01_theory.cpp` — theory with stack vs heap ASCII layout, `new`/`delete` vs `new[]`/`delete[]`, leak & dangling-pointer demos, n=0 edge case, `sizeof` on heap pointer.
  - `task.cpp` — 6 tasks EASY→HARD (alloc/fill/print/free, resize to bigger buffer, merge two arrays, in-place reverse, even/odd via pointer, dynamic string builder) with full solutions.
  - `README.md` — this cheat sheet.
- **Cheat sheet / syntax:**

| Operation | Code |
|---|---|
| Single int | `int* p = new int(42);` ... `delete p; p = nullptr;` |
| Array | `int* a = new int[n];` ... `delete[] a; a = nullptr;` |
| Safe allocation | `int* a = new (nothrow) int[n]; if (a == nullptr) {...}` |
| RESIZE trick | alloc new bigger ⇒ copy ⇒ `delete[] old` ⇒ point to new |
| `new int[0]` | legal — valid pointer, `delete[]` safe |
| sizeof on heap ptr | 8 bytes (pointer) — NEVER the array size! |

- **Complexity:**

```
TIME : new / delete        -> O(1)*   (allocator ka paperwork — slow than stack)
       fill n elements     -> n × O(1)  =  O(n)
       print n elements    -> n × O(1)  =  O(n)
       delete[] simple     -> O(1)* ; delete[] of class array -> O(n) destructors
SPACE: heap array of n int -> 4n bytes = O(n)
       local variables     -> O(1)
DERIVATION (vector push_back): doubling -> 1+2+4+...+n = 2n-1 = O(n) total
    over n pushes -> O(1) amortized per push
```

- ⚠️ **Common mistakes:**
  1. `delete` instead of `delete[]` for arrays (or forgetting the brackets).
  2. `delete` bhoolna → **memory leak** (grows until program exit).
  3. Delete ke baad `p = nullptr` na karna → **dangling pointer** → UB.
  4. **Double delete** → crash. (`delete nullptr` is safe.)
  5. Node delete se pehle `next` na sambhalna → poori list kho jaati hai.
  6. `new` + `free` / `malloc` + `delete` mixing → UB.
  7. Bina zarurat `new` karna — stack/vector often enough.
- **Interview Q&A:**
  - *Q: Stack vs heap?* — A: Stack = small (~8 MB), automatic lifetime, fast. Heap = big (up to RAM), manual lifetime, slower.
  - *Q: `new int[n]` vs `int arr[n]`?* — A: `int arr[n]` is a non-standard VLA (MSVC fails, big n = stack overflow). `new int[n]` works anywhere and n can be huge.
  - *Q: What is a memory leak?* — A: Memory allocated with `new` but never freed. Real demo in this folder: 20,000 × `new int[1000]` → RSS 2 MB → 80 MB; all deleted → back to 4 MB.
  - *Q: Why `delete[]` and not `delete`?* — A: For classes, `delete[]` calls destructors for EVERY element; `delete` destroys only the first.
  - *Q: How do you resize a dynamic array?* — A: Allocate a new bigger buffer, copy over, `delete[]` old, update pointer. (This is literally what `vector` does.)