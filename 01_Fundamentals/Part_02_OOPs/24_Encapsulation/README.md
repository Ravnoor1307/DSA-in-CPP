# Encapsulation

- Encapsulation bundles data (variables) and the methods that operate on it into a single class, while hiding that data from the outside world using `private` access.
- The only way to read or modify the hidden state is through public "gatekeeper" methods (getters/setters) that validate every change.
- This protects **data integrity** — invalid values are rejected at the class boundary, so objects never enter a broken state.
- Encapsulation makes maintenance easy: you can rewrite internal storage or logic without touching any code outside the class.
- Access levels in C++; `private` (class only), `protected` (class + derived), and `public` (everyone) form the encapsulation toolkit.

**Real-world analogy:** An ATM machine. You see only the screen and keypad (public interface), while the vault, database, and network stay hidden (private internals). The ATM validates your PIN and balance before giving cash.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready Thermometer demo showing range validation |
| `task.cpp` | 6 solved tasks: Password, BankAccount, secure transfer, PIN door, units, counter history |

## Cheat sheet / syntax

```cpp
class Thermometer {
private:              // ← hidden state
    double celsius;
public:               // ← controlled interface
    void  setCelsius(double v);   // validates before storing
    double getCelsius() const;
};
```

- `class` defaults to `private`; `struct` defaults to `public`.
- Setter pattern: check rule → reject or store.
- Getter pattern: just return (optionally a derived/calculated value, e.g. Fahrenheit).

## Complexity

**Time: O(1)** — `setCelsius`: 2 comparisons + 1 assignment = constant count of operations. `getFahrenheit`: 1 multiply + 1 divide + 1 add + 1 return = constant. No loops, no growth with input size, so worst case stays O(1).

**Space: O(1)** — one `double` (8 bytes) per object. No arrays, no dynamic allocation, no recursion.

## ⚠️ Common mistakes

- Making data `public` → anyone can set `-999°C` or `1e9 balance`; all validation is bypassed.
- Forgetting `const` on getters → getters can still mutate the object.
- Complex logic in getters instead of keeping them light and predictable.
- Setters that silently ignore invalid input instead of returning a success/failure flag.
- Exposing internal representation (e.g., giving away the raw buffer) instead of a derived value.

## Interview Q&A

**Q1. What is encapsulation and why is it useful?** Bundling data + methods and hiding data via `private`, exposing only validated public methods. It protects integrity and makes change localised.

**Q2. How is encapsulation different from abstraction?** Encapsulation is *how* the state is hidden (access control/mechanism); abstraction is *what* is hidden (design of essential features). Encapsulation is about protecting data; abstraction is about simplifying the interface.

**Q3. Can someone still read private data?** Yes — through members like `friend` functions/classes or pointer hacks, but breaking encapsulation is strongly discouraged. The class then loses its integrity guarantees.

**Q4. Should all members be private?** Data should generally be private; an empty struct/class or a trivial DTO is the traditional exception. Constants and pure configuration are often fine as `public` `const`/`static`.

**Q5. Why use getters instead of public variables?** Getters let you add validation, logging, caching, or change the internal representation later without touching callers.

**Q6. What is the difference between `public`, `protected`, and `private`?** `public`: accessible everywhere. `protected`: class + derived classes. `private`: only the class itself (and friends).