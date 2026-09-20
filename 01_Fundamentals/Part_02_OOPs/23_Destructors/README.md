# 23 — Destructors

- A **destructor** (`~ClassName()`) is a no-return, no-parameter member function that runs **automatically** when an object dies: at scope end, on `delete`, and at program exit.
- **Destruction order is the reverse of construction (LIFO):** objects built first are destroyed last; arrays are destroyed from the last element to the first.
- Destructors are the guaranteed **cleanup spot**: free heap (`delete[]`), close files, release locks — the constructor/resource + destructor/release pair is **RAII**.
- A base destructor should be **`virtual`**: deleting a derived object through a base pointer without `virtual` runs only `~Base` and **leaks** the derived part.
- Heap objects have **no scope cleanup** — if `delete` is forgotten, the destructor never runs (resource leak); stack objects are cleaned up automatically, even on **early return**.

- **Real-world analogy:** the cleaning staff after a college fest — halls close in the reverse order they opened; the main stage (opened first) is cleaned last, the small stalls (opened later) are cleaned first.

- **Files in this folder**
  | file | purpose |
  |------|---------|
  | `01_theory.cpp` | destructor theory + LIFO order diagram + compile-ready demo (`File`, nested blocks, array of objects, `new/delete`, virtual dtor) |
  | `task.cpp` | 6 tasks: Timer RAII, nested-scope order, array destruction, new/delete + leak note, virtual dtor, early-return cleanup |
  | `README.md` | this summary, cheat sheet, complexity, mistakes, interview Q&A |

- **Cheat sheet / syntax**
  | situation | what runs |
  |-----------|-----------|
  | block `}` ends | destructor runs automatically for every stack object |
  | `delete p;` | destructor runs for that heap object (manual trigger) |
  | program end | remaining global / static objects destroyed |
  | `virtual ~Base(){}` | deleting derived via `Base*` runs `~Derived` then `~Base` |
  | forget `delete` | destructor **never** runs → leak |

- **Complexity**
  - Time: one destructor = a constant number of frees/prints → **O(1)** per object; destroying n objects (array) requires n destructor calls → the calculation is n×O(1) → **O(n)** total.
  - Space: each live object holds fixed-size members → **O(1)** per object; n live objects peak at **O(n)**; destruction allocates no extra memory.

- **⚠️ Common mistakes**
  - Forgetting `delete`/`delete[]` → destructor never runs → **leak**.
  - Using **non-virtual** base destructor with polymorphic deletion → derived resources leak.
  - **Double delete** on shared heap (shallow-copy classes) → runtime crash.
  - Expecting heap objects to clean themselves at scope end — they don't; only `delete` triggers their destructor.
  - Deleting with `delete` on a `new[]` array (and vice versa) — undefined behaviour.

- **Interview Q&A**
  - *Q: When is a destructor called?* A: scope end (stack), `delete` (heap), and program exit (globals/statics).
  - *Q: What is the destruction order?* A: reverse of construction (LIFO) — last created is first destroyed; arrays die from the last element back.
  - *Q: Why make a destructor virtual?* A: so deleting a derived object through a base pointer runs the full dtor chain (`~Derived` → `~Base`), avoiding leaks.
  - *Q: What is RAII?* A: acquire resources in the constructor, release them in the destructor — cleanup is automatic on every exit path, even early returns.