# Scope and Memory (Lifetime, static, Storage Classes)

- Scope = where a NAME is visible (a `{}` block); lifetime = how long the MEMORY exists; the two differ — a static local has block scope but program lifetime.
- Globals live in the static/data segment for the whole program; locals live on the stack and die when their block ends.
- `static` inside a function keeps its value across calls while keeping the name private to that function — perfect for counters.
- Storage classes decide where and how long memory lives: `auto`/`register` (locals), `static`, `extern` (shared global), plus advanced `thread_local`.
- Process memory layout (low→high): code/text → static/data → heap (grows up) → stack (grows down).

- Real-world analogy: Office — the reception notice board is global (everyone sees it), a manager's cabin files are local (gone when the cabin closes), and the office register is a static local that remembers its count across every visitor.

- Files in this folder:
  - `01_theory.cpp` — memory-layout ASCII, shadowing diagram, demo (shadowing, block scope, static vs local counter, zero-initialized global, edge cases).
  - `task.cpp` — 7 tasks EASY→HARD (global counter, block scope, shadowing, static counter, dangling vs static pointer, storage classes, sibling/nested blocks) + full solutions.

- Cheat sheet / syntax table:

  | Storage class | Location     | Lifetime          | Example                 |
  |---------------|--------------|-------------------|-------------------------|
  | `auto` local  | stack        | until block ends  | `auto x = 5;` / `int y;`|
  | `register`    | CPU-anywhere | until block ends  | `register int r = 4;`   |
  | static local  | data segment | whole program     | `static int c = 0;`     |
  | global        | data segment | whole program     | `int g = 1;`            |
  | `extern`      | data segment | whole program     | `extern int g;`         |

- Complexity:
  - Scope rules are enforced at compile time (zero runtime cost); static counter calls are constant work → **O(1)** time, **O(1)** space per call.

- ⚠️ Common mistakes:
  - Assuming a global changed because a local shadowed it inside a function.
  - Returning a pointer to a local variable → dangling pointer, undefined behaviour.
  - Forgetting that a static local initializes ONCE, not on every call.
  - Reading an uninitialized local (garbage) while expecting the auto-zero behaviour that only globals/statics (.bss) get.

- Interview Q&A:
  - Q: Scope vs lifetime? A: Scope is visibility (where the name works); lifetime is existence of memory. A static local is visible only in its block but its memory lives for the whole program.
  - Q: Where do globals and locals live? A: Globals/statics in the static/data segment; locals on the stack.
  - Q: How many times is a static local initialized? A: Exactly once — on the first execution of its declaration.
  - Q: Why is uninitialized local garbage but uninitialized global zero? A: Locals are not cleaned by the stack; uninitialized globals land in `.bss`, which the OS zero-fills.