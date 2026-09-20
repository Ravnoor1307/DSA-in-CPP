# 22 — Constructors

- A **constructor** is a special member function with the class name, no return type, run **automatically at object creation**.
- **Default ctor** (no args) gives safe start values; **parameterized ctor** takes arguments for different initial data; **overloading** lets you provide several birth styles.
- The **initializer list** (`: len(l), wid(w)`) initialises members *before* the body runs — safer and faster than assignment; **default member init** (`int area = 0;`) sets fallback values.
- The **copy constructor** builds an object from another; the default is **shallow** (copies pointer addresses → shared heap → double-delete), the fix is a **deep copy** (fresh heap + copied values).
- Constructor **overloading** is resolved by the compiler from the argument list at the call site.

- **Real-world analogy:** a garments factory — a blank order slip makes a *default* shirt, a detailed slip makes a *tailored* shirt, and a copy run duplicates an existing shirt using a fresh roll of cloth (never shared with the original).

- **Files in this folder**
  | file | purpose |
  |------|---------|
  | `01_theory.cpp` | ctor theory + shallow vs deep ASCII diagram + compile-ready demo (`Rectangle` default/param/copy, negative-dims clamp, `ShallowBox` trap) |
  | `task.cpp` | 6 tasks: Point, overloaded Employee, initializer-list Rectangle, Circle overloads, deep-copy DynamicArray, static alive counter |
  | `README.md` | this summary, cheat sheet, complexity, mistakes, interview Q&A |

- **Cheat sheet / syntax**
  | constructor | syntax |
  |-------------|--------|
  | default | `Rectangle() { ... }` |
  | parameterized | `Rectangle(int l, int b) : dim(new int[2]), area(0) { ... }` |
  | copy (deep) | `Rectangle(const Rectangle& r) { dim = new int[2]; ... copy values ... }` |
  | default member init | `int area = 0;` inside the class |
  | call styles | `Rectangle r1;` `Rectangle r2(5,4);` `Rectangle r3 = r2;` |

- **Complexity**
  - Time: default/parameterized ctors = a constant number of allocations + assignments → **O(1)**; copy ctor copies **n** members → the calculation is n copy operations → **O(n)** (here n = 2 → O(1) practically).
  - Space: each object's heap block is **O(1)** (fixed dims) so k objects use **O(k)**; a deep copy allocates exactly what the copy needs — no extra temporary storage.

- **⚠️ Common mistakes**
  - Forgetting to define a copy ctor when the class owns **heap memory** → default shallow copy → **double delete / crash**.
  - Using `delete` instead of `delete[]` for array members.
  - Ignoring **negative / invalid** arguments inside constructors (clamp them).
  - Forgetting that constructors have **no return type** and cannot return values.
  - Assuming constructors run on *declaration* only — copy ctor also fires on pass-by-value and return-by-value.

- **Interview Q&A**
  - *Q: What is a constructor?* A: a special no-return-type method, same name as the class, auto-run at object creation to initialise the object.
  - *Q: Shallow vs deep copy?* A: shallow copies pointer *addresses* (objects share one heap block → double free); deep copies *values* into fresh heap (independent objects).
  - *Q: What is the initializer list?* A: `: a(x), b(y)` — members initialised before the ctor body; required for `const`/reference members, and faster.
  - *Q: When is the copy ctor called?* A: copy-initialisation (`r3 = r2`), passing by value, and returning by value.
  - *Q: Can a constructor be overloaded?* A: Yes — several constructors with different parameter lists; the compiler picks by matching arguments.