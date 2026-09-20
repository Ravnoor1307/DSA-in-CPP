# 16. References — Aliases of a Variable

> **Ek line me:** Pointer ne *taakat* di, reference ne *safai* di. Ek reference ek existing variable ka **dusra naam** hai — memory me koi copy nahi banti, dono naam ek hi dabbe pe ishaara karte hain.

A reference is a second name for the SAME memory box. No copy, no new allocation — changing through one name instantly changes the other. We use pass-by-reference to modify a caller's variable inside a function without pointers, and `const &` to pass large data cheaply and safely.

- **Real-world analogy:** Rahul Verma is called "Rahul" by friends, "Golu" by grandma, and "R. Verma" on his office badge. One body, many names — a haircut changes everyone's picture instantly. `int rahul = 10; int& golu = rahul;` — do naam, ek dabba.
- **Files in this folder:**
  - `01_theory.cpp` — full theory with ASCII address diagram, swap demo, const reference, dangling-return pitfall, and edge cases (must-initialize, cannot-rebind).
  - `task.cpp` — 6 tasks EASY→HARD (swap, swap-pairs, rotate, adjust, min/max outputs, two-largest) with full solutions.
  - `README.md` — this cheat sheet.
- **Cheat sheet / syntax:**

| Syntax | Meaning |
|---|---|
| `int &ref = num;` | ref is an alias of num — same address |
| `void f(int &x)` | pass by reference (caller changes!) |
| `void f(const int &x)` | read-only alias, no copy |
| `int& f(...) { return x; }` | return lvalue (only if x outlives f!) |
| `int &r;` | ❌ ERROR — must initialize at declaration |
| `r = b;` | copies b's VALUE (does NOT rebind r) |

- **Complexity:**

```
TIME : reference banana            -> O(1)  (sirf ek pata bind)
       swap via reference          -> 3 o(1) assignments = O(1)
       const& se bada data bhejna  -> O(1)  (kuch copy nahi hota)
SPACE: reference apni memory nahi leta -> O(1)
       (compiler hidden pointer use kare ya optimize karke uda de)
```

- ⚠️ **Common mistakes:**
  1. Reference without initialization — compile error (`int &r;`).
  2. Thinking `r = b` REBINDS — it only copies the value into a.
  3. Returning a reference to a LOCAL variable — dangling reference → UB.
  4. Using `const int&` for tiny data (copy is cheaper than an 8-byte pointer).
  5. Forgetting that `int x = v[0]` is a COPY, not a reference.
- **Interview Q&A:**
  - *Q: Reference vs pointer?* — A: Reference can't be null, can't be rebind, has no own address. Pointer can be null, can be reassigned, needs `->`/`*`.
  - *Q: Why do Linked List / Tree nodes use pointers, not references?* — A: Nodes need a "next = nullptr" (no object) and `p = p->next` (reassignment) — references support neither.
  - *Q: When is `const T&` best?* — A: For large data you only read. 90% of function params. (Example: `long long sum(const vector<int>& v)` — huge speedup, same O(n).)
  - *Q: Can you return a reference from a function?* — A: Yes, but only to something that still exists after the call (static/global/array element). Returning a local = dangling.