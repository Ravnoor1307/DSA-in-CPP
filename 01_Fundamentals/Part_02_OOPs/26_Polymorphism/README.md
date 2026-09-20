# Polymorphism

- Polymorphism = "many forms": one interface/name, many behaviours. Two flavours: **compile-time** (function/operator overloading) and **runtime** (virtual functions).
- Compile-time polymorphism is resolved by the compiler using signatures — fastest, but the set of variants is fixed at build time.
- Runtime polymorphism uses the `virtual` keyword: a base pointer/reference to a derived object calls the object's *real* version through a hidden vtable + per-object vptr.
- Use `override` on derived virtuals — it makes the compiler verify the base signature matches, catching typos early.
- Always declare base destructors `virtual`, otherwise deleting a derived object through a base pointer skips the derived cleanup and leaks.

**Real-world analogy:** One remote control button (interface) — pressing "Power" switches on a TV, an AC, or a projector; each device reacts in its own way. Same call, different behaviour.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + vtable beginner diagram + `Shape*` array demo (Circle/Rect), overload demo, virtual dtor demo |
| `task.cpp` | 6 solved tasks: overloaded `findMax`, `makeSound` Dog/Cat, Shape area family, NamedShape, virtual-dtor zoo, operator overloading |

## Cheat sheet / syntax

```cpp
class Shape {
public:
    virtual double area() const { return 0.0; }   // runtime polymorphism root
    virtual ~Shape() {}                            // virtual dtor — always!
};

class Circle : public Shape {
    double r;
public:
    double area() const override { return 3.14159*r*r; }
};

// overloads (compile-time):
double avg(double a, double b);
double avg(double a, double b, double c);

// usage:
Shape* arr[2] = { &circle, &rect };
arr[i]->area();        // vtable decides which area() runs
```

## Complexity

**Time: O(1) per virtual call** — a virtual dispatch is a vptr read (1 op) plus one indirect jump (1 op); each `area()` body is a constant number of mults/adds. Processing *n* polymorphic objects in a loop costs n × O(1) = O(n).

**Space: O(1) per object** — each polymorphic object stores one vptr (8 bytes); the vtable itself is **shared per class** (created once), not per object. So a Circle stores vptr + radius; total fixed size regardless of input.

## ⚠️ Common mistakes

- Missing `virtual` → base pointer calls the *base* version; silent wrong behaviour, not an error.
- Missing `override` → an unmatched signature silently becomes a new (hidden) function instead of overriding.
- Non-virtual destructor in a base → `delete basePtr` leaks derived resources; always make it virtual.
- Adding overloads but calling with `float`/implicit conversions → accidental ambiguous calls or wrong selection.
- Storing objects *by value* in an `vector<Shape>` — slicing! Use `Shape*`/references/unique_ptr.

## Interview Q&A

**Q1. What is polymorphism? Name the two types.** Many forms of one interface. Compile-time (overloading) chosen by compiler via signatures; runtime (virtual functions) chosen at run time via the object's real type.

**Q2. How does a virtual function work internally?** The class gets a vtable (array of function pointers); each object carries a vptr. A virtual call reads the vptr, jumps through the table slot, and runs the derived version.

**Q3. What is `override`?** A specifier that tells the compiler to verify the function truly overrides a base virtual — failing the check produces a compile error if the signature mismatches.

**Q4. What is object slicing?** Assigning a derived object to a base object *by value* trims the derived-specific part. Fix by using pointers or references.

**Q5. Can a constructor be virtual?** No, constructors cannot be virtual (no object exists to carry the vptr). Destructors can and should be.

**Q6. What costs does runtime polymorphism add?** One extra indirection per call plus vptr storage; negligible for most apps. With no virtuals, calls jump directly.

**Q7. Operator overloading — compile-time or runtime?** Compile-time — overload resolution happens while compiling, no vtable involved.