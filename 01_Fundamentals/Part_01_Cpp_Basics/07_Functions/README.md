# Functions (Pass by Value vs Pass by Reference)

- A function is a named, reusable block: parameters (inputs) in, a return value out, plus optional side effects on caller data.
- Pass by value makes a copy on the stack — the caller's data is always safe; pass by reference (`&`) creates an alias so the original can change.
- Prototypes let you define a function after `main`; default arguments fill in values the caller omits.
- Every call pushes a frame onto the call stack and pops it on return — that push/pop cycle is the function's lifetime.
- Choose by value for read-only computation and by reference for modifying caller data or avoiding expensive copies.

- Real-world analogy: A recipe is pass-by-value (the chef gets photocopied ingredients and cannot ruin your pantry). An ATM withdrawal is pass-by-reference — the bank updates YOUR real account balance.

- Files in this folder:
  - `01_theory.cpp` — concept, ASCII stack diagrams (copy vs alias), call/return flow, dry runs, compile-ready demo (add, swapByRef, factorial, applyTax) with edge cases (0!, 1!, negative input).
  - `task.cpp` — 7 tasks EASY→HARD (sumTwo, maxOfArray, isPrime, swap by ref, factorial, default-arg tax, pass-by-value proof) + full solutions.

- Cheat sheet / syntax table:

  | Syntax                          | Meaning                             |
  |---------------------------------|-------------------------------------|
  | `int add(int a, int b);`        | prototype (signature only)          |
  | `int add(int x, int y) { }`     | definition (body)                   |
  | `void f(int a)`                 | pass by value (copy of a)            |
  | `void f(int &r)`                | pass by reference (alias of caller) |
  | `int f(int a, int b = 5)`       | default argument (b optional)       |
  | `return value;`                 | send result back to caller          |

- Complexity:
  - `add` / `swap`: constant instructions → **O(1)** time, **O(1)** space per call.
  - `factorialLoop(n)`: n−1 iterations → **O(n)** time, **O(1)** space.

- ⚠️ Common mistakes:
  - Forgetting `&` and then wondering why the caller's variable never changed.
  - Returning a pointer/reference to a local variable — a dangling reference to freed stack memory.
  - Passing arguments in the wrong order against the prototype.
  - Returning nothing from a non-void function on some path.
  - Repeating the default argument in the definition (allowed only in the prototype).

- Interview Q&A:
  - Q: Value vs reference? A: Value copies (safe), reference aliases (can modify, zero copy cost).
  - Q: When is a function's local memory freed? A: At `return`, when the stack frame pops.
  - Q: What is a dangling reference? A: A reference/pointer to a local that died when its function returned — undefined behaviour.
  - Q: Why pass arrays to functions? A: Arrays decay to pointers, so a size parameter is needed to avoid out-of-bounds reads.