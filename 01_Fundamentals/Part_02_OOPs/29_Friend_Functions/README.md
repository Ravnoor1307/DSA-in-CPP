# Friend Functions & Friend Class

- A **friend function** is a non-member (global) function that a class explicitly grants access to via the `friend` keyword, letting it read private/protected members directly — like an outside auditor handed a key to the vault.
- Friendship is **issued by the class**, never taken: you must declare `friend` inside the class definition for the access to exist.
- Friend functions have **no `this` pointer** and are called like ordinary functions (`add(d1, d2)`), never with `obj.friendFunc()`.
- A **friend class** gives ALL member functions of one class access to another class's private members; friendship is **not symmetric and not transitive** (A friend of B does not make B friend of A).
- Friends are the natural home for **operator overloading** (`==`, `<<`, `+`) and utility functions that need both operands' internals.

- **Real-world analogy:** The company deliberately lists an external auditor on the VIP access sheet; the auditor is not an employee but can inspect the locked ledgers. That listed badge is the `friend` keyword.

## Files in this folder

| File          | Purpose                                                          |
|---------------|------------------------------------------------------------------|
| `01_theory.cpp` | Concept walkthrough — friend function, friend class, key-to-private-room ASCII diagram, non-symmetric/non-transitive rules, pros/cons table, dry run, complexity derivation, edge-case demo (overflow inches, negatives, zero). Compile-ready. |
| `task.cpp`      | 6 graded tasks (EASY → HARD) — peek private, swap private values, compare objects, guarded distance add, friend class grading, friend operator overloading. Hint + starter code per task, fully solved with Hinglish comments. |

## Cheat Sheet / Syntax

| Concept              | Syntax / Example                                                     |
|----------------------|----------------------------------------------------------------------|
| Friend function      | Inside class: `friend ReturnType name(Params);`                       |
| Friend definition    | Outside, NO `Class::` scope: `ReturnType name(Params) { ... }`       |
| Call a friend        | `add(d1, d2);` (plain call — no object-dot syntax)                   |
| Friend class         | Inside giver: `friend class Teacher;` → Teacher accesses giver privates |
| Access in friend     | Direct: `d1.feet`, `s.marks[i]` — no getters needed                  |
| Friend operator==    | `friend bool operator==(Point a, Point b);`                         |
| Friend operator<<    | `friend ostream& operator<<(ostream& out, Point p);`                |

## Complexity

**Time:**
- Friend calls (add/compare/swap): constant field reads + arithmetic → O(1)
- Distance normalization: 2 additions + 1 division + 1 modulo → O(1)
- Friend class grading loop: 3 iterations (fixed array size) → 3 × O(1) = O(1)
- **Overall Time Complexity = O(1)** for every operation

**Space:**
- Each object (Distance/Box/Point): 2–4 ints → O(1) per object
- Friend functions use only stack locals (totals, carries) → O(1) extra
- Friend class adds no storage (it just reads the friend's data) → O(1)
- **Overall Space Complexity = O(1) per operation**

## ⚠️ Common Mistakes

1. **Calling a friend with object syntax** — `d1.add(d2)` fails; friends are called as free functions: `add(d1, d2)`.
2. **Adding `Class::` to a friend definition** — writing `Distance::add(...)` makes it a member again; friend definitions must be plain global functions.
3. **Using `this` inside a friend** — there is no `this`; friends receive objects as explicit parameters.
4. **Believing friendship is symmetric/transitive** — A→B and B→C does NOT give A access to C.
5. **Forgetting the declaration inside the class** — without `friend` inside the class body, access to private members is a compile error.
6. **Overusing friends** — every friend loosens encapsulation; prefer getters unless operator overloading or a genuinely coupled utility demands it.
7. **Passing by value when modifying** — swap must take `Account&` (references), otherwise you swap copies and nothing changes.

## Interview Q&A

- **Q: Difference between a friend function and a member function?**
  A: Member functions have `this` and are called via the object; friends have no `this`, are declared inside the class for access rights, but defined and called as free functions.

- **Q: Does the friend function appear in the object's memory?**
  A: No. A friend declaration is compile-time metadata — it costs no extra bytes per object and adds no virtual table entry.

- **Q: Can a friend access static members?**
  A: Yes — friends can access private static members exactly like private instance members.

- **Q: If B is a friend of A, is A a friend of B?**
  A: No. Friendship is one-directional unless A separately declares B as friend.

- **Q: Why is operator overloading usually done with friends?**
  A: Binary operators (like `d1 + d2`, `cout << d1`) have the left operand as the implicit caller for member versions. The friend form treats both operands symmetrically and still reaches private fields.

- **Q: When should you AVOID friends?**
  A: When a normal public getter suffices, or when minimizing coupling matters more than direct access — friends must be updated whenever the class internals change.