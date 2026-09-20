# Static Members & this Pointer

- A **static data member** is a single variable shared by ALL objects of the class — it lives in the static memory segment, not inside any object, and must be defined outside the class with `int ClassName::var = 0;`.
- A **static member function** belongs to the class itself, can ONLY touch static members, and is called with `ClassName::name()` — it has no `this` pointer.
- The **this pointer** is an implicit pointer available in every non-static member function; it holds the address of the object that invoked the call.
- `this->` is the standard fix for **name shadowing** (when a parameter has the same name as a member variable), and `return *this;` enables **method chaining** like `e.setName("X").setSalary(500).print()`.
- A **const member function** (`void print() const`) promises not to modify object state, allowing it to be called on const objects.

- **Real-world analogy:** The company's single HR register (static) counts every employee regardless of branch, while each employee's personal ID card (instance) is unique; when you update "your own" card you point to yourself (this).

## Files in this folder

| File          | Purpose                                                          |
|---------------|------------------------------------------------------------------|
| `01_theory.cpp` | Full concept walkthrough — static members, static functions, this pointer, const functions, memory-layout ASCII diagrams, dry run, complexity derivation, edge-case demo. Compile-ready. |
| `task.cpp`      | 6 graded tasks (EASY → HARD) with hints, starter code, and fully-solved, commented solutions. |

## Cheat Sheet / Syntax

| Concept                 | Syntax / Example                                                    |
|-------------------------|---------------------------------------------------------------------|
| Static data member      | `static int count;`  →  `int Employee::count = 0;` (definition outside class!) |
| Static member function  | `static int getCount() { return count; }`  →  `Employee::getCount()` |
| this pointer            | `this->name = name;` in setter                                        |
| Method chaining         | `Employee& setName(string n) { this->name = n; return *this; }`     |
| const member function   | `void print() const { ... }`                                        |
| Call static from object | `emp1.getCount();` (allowed — compiler maps to class)               |

## Complexity

**Time:**
- Static member read (`count`): 1 variable access → O(1)
- Constructor/destructor increment/decrement: 1 arithmetic op → O(1)
- this-> assignment / setter: 1 pointer deref + 1 write → O(1)
- Method chain of k calls: k × O(1) → **O(1) per operation**

**Space:**
- Static count: exactly ONE int (4 bytes) in static segment — independent of object count
- Each object: instance members only (name, salary) → object_size each
- Total for n objects: n × object_size + 4 bytes static → **O(n)**

## ⚠️ Common Mistakes

1. **Forgetting the outside-class definition** — `Employee::count = 0;` missing → linker error "undefined reference". The `static int count;` inside class is only a declaration.
2. **Accessing instance members from a static function** — `static void f() { cout << name; }` → compile error. Static functions can ONLY access static members.
3. **Using `this` in a static function** — There is no object, so `this` does not exist there.
4. **Shadowing bug** — `void set(string name) { name = name; }` assigns parameter to itself; always write `this->name = name;`.
5. **Returning by value instead of reference** — `Employee setName(...)` (no &) breaks chaining semantics because each link works on a COPY.
6. **Calling non-const functions on const objects** — a const object can only call const functions; compiler rejects otherwise.

## Interview Q&A

- **Q: Difference between static and instance member?**
  A: Static member → one shared copy, lives in static segment, accessible via `ClassName::`, no `this`. Instance member → one copy per object, accessible via `obj.member`.

- **Q: Can a static function access a non-static member?**
  A: No. Static functions have no `this` pointer, so they cannot know which object's data to access.

- **Q: Why does `this->` fix shadowing?**
  A: `this->name` dereferences the object's own memory through the hidden pointer, so `this->name` is the member, while bare `name` is the parameter.

- **Q: What is wrong with `void f() { name = name; }`?**
  A: If the parameter is also called `name`, the assignment copies the parameter into itself; the member never changes. Use `this->name = name;`.

- **Q: Why use `return *this;` and not `return this;`?**
  A: `this` is a pointer; `*this` dereferences it to the object itself. Returning `*this` as reference (`Employee&`) gives the caller the same object for the next dot-call. Returning `this` would be a pointer, not chainable with `.`.

- **Q: When to make a function const?**
  A: When the function only reads (getters, print, validation). It enables calling on const objects and documents intent.