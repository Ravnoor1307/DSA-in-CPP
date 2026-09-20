# Abstraction

- Abstraction shows only the **essential features** of an object and hides implementation details behind a clean interface.
- In C++ it is achieved with **pure virtual functions**: `virtual void pay() = 0;` (the `= 0` gives it no body in the base).
- A class with at least one pure virtual is **abstract** — it canNOT be instantiated; it only defines a **contract** for derived classes.
- Every concrete derived class MUST override all pure virtuals; otherwise it remains abstract too.
- Use the abstract type as a pointer/reference so callers depend on the interface, not on any concrete class. Abstract classes still need a `virtual` destructor.

**Real-world analogy:** The steering wheel of a car. You interact only with the wheel, pedals, and lever (essential features), while the engine internals stay hidden. A TV remote declares the contract ("on/off") that every TV brand implements differently. Same interface, different internals.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + comparison table (abstraction vs encapsulation) + Payment gateway demo (CreditCardPay / UPIPay) |
| `task.cpp` | 6 solved tasks: abstract Animal, Drawable interface, Machine start, Creature counter, Shape2D metrics, Report dashboard |

## Cheat sheet / syntax

```cpp
class Payment {                     // abstract base (contract)
public:
    virtual void pay(double amt) = 0;    // pure virtual — no body
    virtual void receipt() const = 0;
    virtual ~Payment() {}                // virtual dtor always!
};

class UPIPay : public Payment {           // concrete
public:
    void pay(double amt) override { /* real logic */ }
    void receipt() const override { /* real logic */ }
};

Payment* p = new UPIPay("a@upi");   // abstract pointer -> derived object
p->pay(250);                         // runtime dispatch to UPIPay
```

## Complexity

**Time: O(1) per op** — a virtual call = vptr read (1 op) + indirect jump (1 op); each `pay()` body is a constant number of prints/string ops. Processing *n* objects in a loop = n × O(1) = O(n).

**Space: O(1) per object** — abstract base adds no data members; each concrete object carries one vptr; the vtable is shared per class. No dynamic structures.

## ⚠️ Common mistakes

- Forgetting `= 0` → the class becomes concrete but with a meaningless default body — no contract enforced.
- Forgetting to override one pure virtual → derived class stays abstract and you can't instantiate it.
- Creating objects of the abstract class → compile error (that's the design working!).
- Missing `virtual` destructor in the abstract base → derived cleanup skipped on `delete basePtr`.
- Doing complex work in pure virtual *default implementations* — keep the contract thin.
- Confusing abstraction with encapsulation — abstraction hides *implementation*, encapsulation hides *data*.

## Interview Q&A

**Q1. What is abstraction?** Showing only essential features of an object while hiding implementation details, via a clean interface (e.g., steering wheel vs engine).

**Q2. What makes a class abstract?** At least one pure virtual function (`= 0` syntax). Abstract classes cannot be instantiated.

**Q3. Can an abstract class have normal (non-pure) functions?** Yes — concrete methods, data members, and even a pure virtual with a default body (must still be overridden).

**Q4. Abstraction vs encapsulation?** Abstraction hides *what* the object does (design/interface); encapsulation hides *how* the data is guarded (private members, validated setters). They complement each other.

**Q5. What happens if a derived class doesn't override a pure virtual?** It remains abstract — you cannot instantiate it; you must override in the next derived level.

**Q6. Can a constructor be pure virtual or virtual?** Constructors can't be virtual (no object exists for the vptr yet); destructors must be virtual in polymorphic bases.

**Q7. How is an interface different from an abstract class?** In C++ an "interface" is just an abstract class with *only* pure virtuals (and a virtual dtor) — no data, no implementation.