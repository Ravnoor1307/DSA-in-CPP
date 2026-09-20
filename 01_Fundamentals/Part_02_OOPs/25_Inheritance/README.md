# Inheritance

- Inheritance lets a derived (child) class reuse the members of a base (parent) class, modelling an **IS-A** relationship: `Car IS-A Vehicle`, `Dog IS-A Animal`, `Manager IS-A Employee`.
- Syntax is `class Child : public Base { ... };`. Public inheritance preserves `public`/`protected` visibility in the child.
- `protected` members are visible to the base and every derived class, but hidden from outside code — the sweet spot for shared data.
- Constructor order is **base first, derived second**; destructor order is the exact **reverse** (derived first, base last).
- Multilevel inheritance chains `A → B → C`; multiple inheritance lets `D` inherit from two bases (`class D : public B, public C`) — powerful but risks ambiguity/diamond problems.

**Real-world analogy:** Every Car and Bus IS-A Vehicle — same brand, same engine concept, same rules of the road — but each adds its own extra features. You write the common vehicle behaviour once and reuse it for all.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + constructor/destructor order demo (Vehicle→Car→ElectricCar, Duck multiple inheritance) |
| `task.cpp` | 6 solved tasks: Manager, Dog, multilevel geometric shapes, savings account, protected chain, fixed deposit |

## Cheat sheet / syntax

```cpp
class Vehicle {
protected:
    string brand;              // visible to derived classes
public:
    Vehicle(string b) : brand(b) {}
    virtual ~Vehicle() {}
};

class Car : public Vehicle {   // Car IS-A Vehicle
    int seats;
public:
    Car(string b, int s) : Vehicle(b), seats(s) {}   // chain to base ctor
};

class ElectricCar : public Car { ... };              // multilevel
class Duck : public Flyable, public Swimmable { };   // multiple
```

- Ctor chain: `Electric Car → Car → Vehicle`.
- Dtor chain: `Vehicle → Car → ElectricCar` (reverse).

## Complexity

**Time: O(1)** — Construction does a fixed call chain (derived ctor + base ctor = constant number of calls). Destruction is the same chain reversed. `print()` runs a constant number of output ops. Nothing scans or scales with input size, so worst case stays O(1).

**Space: O(1)** — A `Vehicle` is a fixed-size string + int; a `Car` adds one more int. Total memory is constant regardless of runtime data. (No vptr here, since this demo uses no virtual functions.)

## ⚠️ Common mistakes

- Forgetting to chain the base constructor → compiler calls the base default ctor (which may not exist!) and you get an error.
- Declaring a destructor **non-virtual** in the base → deleting a derived object via a base pointer leaks/crashes. Always make base destructors `virtual`.
- Making data `private` in the base and then wondering why the child can't touch it — use `protected`.
- Ignoring the reverse destructor order → releasing child resources after the parent's memory is gone.
- Overusing multiple inheritance → ambiguous `x` in diamond shapes; prefer interface-style composition.

## Interview Q&A

**Q1. What is inheritance and when is it appropriate?** Reusing a base class's members in a derived class to model an IS-A relationship. Use it when there is genuine "is-a" logic, not just "has-a".

**Q2. What's the constructor/destructor order?** Base ctor → derived ctor on creation; derived dtor → base dtor on destruction (reverse).

**Q3. What is protected access?** Visible inside the base class and any derived class, invisible to everyone else.

**Q4. Why must a base class destructor be virtual?** When you `delete` a derived object through a base pointer, the virtual dtor dispatches to the derived dtor (which then runs the base one) — otherwise only the base dtor runs and derived resources leak.

**Q5. What is public vs protected vs private inheritance?** Public: IS-A preserved. Protected/private: technically means the base relationship is invisible to outsiders (has-a-like); rarely used.

**Q6. What is the diamond problem and how do you solve it?** `D : B, C` where both `B` and `C` derive from `A` copies `A` twice → ambiguity. Virtual inheritance (`class B : virtual public A`) merges the single `A` subobject.

**Q7. Can you assign a base object to a derived pointer?** No. Derived-to-base (upcast) is safe; base-to-derived (downcast) requires a cast like `static_cast`/`dynamic_cast` and must be justified.