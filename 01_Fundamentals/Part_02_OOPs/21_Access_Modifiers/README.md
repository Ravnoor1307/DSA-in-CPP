# 21 — Access Modifiers (public / private / protected)

- **public** members are reachable from anywhere (class, derived class, and outside code = `main()`).
- **private** members are reachable only inside the same class — neither derived classes nor outside code can touch them (best for sensitive state).
- **protected** members are reachable inside the class and its **derived classes** only — outsiders are locked out.
- The **getter/setter pattern** (public `getX()` / validated `setX()`) is how you expose private data safely and keep a read-only view.
- **Data hiding** == private members + guarded public doors = every write is validated (no negative amounts, no over-withdrawals).

- **Real-world analogy:** the bank vault is *private* (only the key-holder banker), the staff room is *protected* (branch + parent-bank employees only), and the customer hall is *public* (anyone walks in).

- **Files in this folder**
  | file | purpose |
  |------|---------|
  | `01_theory.cpp` | theory notes + access table, bank-layout ASCII diagram + compile-ready demo (`Account` with validation + protected inheritance) |
  | `task.cpp` | 6 tasks: getter/setter, public vs private, validation, protected inheritance, friend, full vault data hiding |
  | `README.md` | this summary, cheat sheet, complexity, mistakes, interview Q&A |

- **Cheat sheet / syntax**
  | keyword | class itself | derived class | outside code |
  |---------|:------------:|:-------------:|:------------:|
  | `public` | ✅ | ✅ | ✅ |
  | `protected` | ✅ | ✅ | ❌ |
  | `private` | ✅ | ❌ | ❌ |
  | setter | `void setSalary(double s) { if (s < 0) s = 0; salary = s; }` |
  | getter | `double getBalance() const { return balance; }` |

- **Complexity**
  - Time: `deposit()` = 1 compare + 1 add; `withdraw()` = ≤2 compares + 1 subtract; `getBalance()` = 1 read — all constant, no loops → **O(1)** per call.
  - Space: each object holds its own members → **O(1)** per object; methods are one shared copy, no extra runtime state for access checking.

- **⚠️ Common mistakes**
  - Writing sensitive data as `public` and skipping validation.
  - Expecting `protected` to be visible from `main()` — it is **not**; it is visible inside derived *methods* only.
  - Setters that accept garbage (negative salary, over-withdrawal) — always validate.
  - Returning a *reference* from a getter so callers can mutate private state; return a **copy** (`const` getter).
  - Making every member public "for speed" — you lose data hiding and validation.

- **Interview Q&A**
  - *Q: What is the difference between private and protected?* A: private = only the class itself; protected = the class + its derived classes; neither is visible outside.
  - *Q: Why use getters/setters?* A: to validate writes, control read access, and change internals without breaking user code.
  - *Q: Can a derived class access a private base member?* A: No, never directly. Use protected or a public base method.
  - *Q: What is data hiding?* A: hiding implementation details (private data) behind a safe public interface so invariants stay valid.