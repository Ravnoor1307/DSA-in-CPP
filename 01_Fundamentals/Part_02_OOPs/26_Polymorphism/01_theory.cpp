/*
═══════════════════════════════════════════════
 POLYMORPHISM
 ⏱️ TIME COMPLEXITY: virtual call dispatch O(1) — one indirect jump through the vtable; area computation O(1) per shape.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think about the remote control on your couch. One "Power" button switches on your TV,
 your AC, or your projector — you press the SAME button and each device reacts in its
 OWN way. The remote does not care which device it is talking to; it only knows "this
 device understands the Power command". In C++, that is exactly runtime polymorphism:
 one interface — Shape* — but each concrete object (Circle, Rectangle) reacts with its
 own version of area(). Meanwhile, compile-time polymorphism is like two phone keypads
 on the same device: calling the SAME function name (say, `print`) with different
 argument types routes to different, selected-at-compile-time versions.

 📖 THEORY: (pure English, beginner-level)
 - POLYMORPHISM = "many forms": one name/interface, multiple behaviours.
 - COMPILE-TIME: function overloading (same name, different parameter lists) and
   operator overloading — the compiler picks the version at compile time.
 - RUNTIME: virtual functions — the decision of WHICH version runs is made at
   run time based on the ACTUAL type of the object, not the pointer type.
 - `virtual` keyword in the base marks a function for dynamic dispatch.
 - `override` (C++11) tells the compiler this function overrides a base virtual,
   catching signature typos at compile time.
 - A base POINTER (or reference) to a derived object calling a virtual function
   triggers dynamic dispatch → derived version runs.
 - Behind the scenes each class with virtuals gets a hidden VTABLE (table of function
   pointers); each object carries one hidden vptr to that table. (Beginner mental model.)

 ASCII DIAGRAM — VTABLE concept (beginner level):
 Shape* sp = new Circle(...);

        sp ────────► ┌──────────────────┐     vptr  ─►  Shape::vtable
                      │ object (Circle)  │                    │
                      │  radius = 3.0    │        ┌─►  area() ─► Circle::area()
                      │  vptr ──────────►│──────┘   │   print()─► Shape::print()
                      └──────────────────┘          └── src: Shape's tables
                     compiler doesn't know the real type — it follows vptr!

 Typical call:  double a = sp->area();
    1. read vptr from object
    2. jump through the vtable slot for area()
    3. execute Circle::area() → O(1)

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Declare a virtual function in the base class (e.g. `virtual double area() const`).
         WHY: This tells the compiler "let derived classes replace this at runtime".
 Step 2: Override it in each derived class using the `override` keyword.
         WHY: Guarantees we really match the base signature, so dispatch works.
 Step 3: Store objects through a BASE pointer or reference (array of Shape*).
         WHY: Now one loop can call area() on every shape without knowing its type.
 Step 4: At runtime, the vptr decides which area() runs.
         WHY: The exact version depends on the real object, enabling late binding.
 Step 5: DELETE through the base with a virtual destructor.
         WHY: Without `virtual ~Shape()` the derived cleanup never runs → leak.

 VISUAL WALKTHROUGH: (array of Shape* dispatch)
 Shape* arr[3] = { new Circle(3), new Rect(4,5), new Circle(1.5) };
 for (Shape* s : arr)  s->area();
       s=Circle(3)   ─► vtable of Circle → r*r*π = 28.27
       s=Rect(4,5)   ─► vtable of Rect   → w*h   = 20
       s=Circle(1.5) ─► vtable of Circle → r*r*π = 7.07

 DRY RUN: (line-by-line trace)
 Circle c("Circle A", 3.0);            // Circle ctor prints: [Circle] created r=3
 Rect   r("Rect B", 4.0, 5.0);         // Rect ctor prints: [Rect] created 4x5
 arr[0]=&c;  arr[1]=&r;                // both upcast to Shape*
 arr[0]->area();  → vptr → Circle::area → 3.0*3.0*3.14159 = 28.2743   prints
 arr[1]->area();  → vptr → Rect::area   → 4.0*5.0 = 20.0             prints
 arr[0]->print(); → virtual → Circle::print includes name "Circle A"
 arr[1]->print(); → virtual → Rect::print includes name "Rect B"
 (compile-time overload demo) area(c) prints "overload branch 1", area(r) prints
 "overload branch 2" — both selected at compile time, no vtable involved.

 TIME COMPLEXITY CALCULATION:
 - Virtual dispatch: read vptr (1 op) + indirect jump (1 op) = constant → O(1) per call
 - Circle::area: 2 mults + return = O(1); Rect::area: 1 mult + return = O(1)
 - Overloaded area(circle) / area(rect): picked at compile time, body O(1)
 - Loop over n shapes: n × O(1) → O(n) if we needed to process all of them
 → Time Complexity = O(1) per virtual call (loop over all shapes = O(n))

 SPACE COMPLEXITY CALCULATION:
 - Each polymorphic class stores one hidden vptr (8 bytes on 64-bit) pointing to a
   shared vtable (one per class, not per object)
 - Circle object: vptr + double radius = 16 bytes; Rect object: vptr + 2 doubles
 - Vtable is class-level, not counted per object beyond the pointer
 → Space Complexity = O(1) per object (plus one shared vtable per class)

 APPROACH COMPARISON:
 ┌───────────────────────┬──────────────────────────────────────┬───────────────────────────────────┐
 │ Aspect                │ Compile-time (overloading)          │ Runtime (virtual functions)       │
 ├───────────────────────┼──────────────────────────────────────┼───────────────────────────────────┤
 │ When chosen            │ At compilation                       │ At run time                       │
 │ Mechanism             │ Signature matching                   │ vtable + vptr indirection         │
 │ Performance           │ Fastest (direct call)                │ One extra indirection             │
 │ Flexibility           │ Fixed set of overloads               │ Open set of derived classes      │
 │ Typical use           │ area(circle) vs area(rect)           │ array of Shape* handled uniformly │
 └───────────────────────┴──────────────────────────────────────┴───────────────────────────────────┘
*/

#include <iostream>
#include <cmath>
using namespace std;

// ---------- BASE CLASS with virtual area() ----------
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {
        cout << "  [Shape] created: " << name << endl;
    }

    // virtual — derived ise override kar ke apna version de sakega
    virtual double area() const {
        return 0.0;
    }

    virtual void print() const {
        cout << "  Generic shape" << endl;
    }

    // IMPORTANT: base destructor virtual hona chahiye taaki derived cleanup chale
    virtual ~Shape() {
        cout << "  [Shape] destroyed: " << name << endl;
    }
};

// ---------- DERIVED: Circle (override) ----------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(string n, double r) : Shape(n), radius(r) {
        cout << "  [Circle] created: radius = " << r << endl;
    }

    // override keyword — signature match compiler se verify karao
    double area() const override {
        // M_PI GNU extension hai, isliye strict C++17 me khud define kiya
        const double PI = 3.14159265358979323846;
        return PI * radius * radius;
    }

    void print() const override {
        cout << "Circle [" << name << "] radius " << radius
             << " => area " << area() << endl;
    }

    ~Circle() override {
        cout << "  [Circle] destroyed: " << name << endl;
    }
};

// ---------- DERIVED: Rect (override) ----------
class Rect : public Shape {
private:
    double w, h;

public:
    Rect(string n, double width, double height) : Shape(n), w(width), h(height) {
        cout << "  [Rect] created: " << w << " x " << h << endl;
    }

    double area() const override {
        return w * h;
    }

    void print() const override {
        cout << "Rect [" << name << "] " << w << " x " << h
             << " => area " << area() << endl;
    }

    ~Rect() override {
        cout << "  [Rect] destroyed: " << name << endl;
    }
};

// ---------- COMPILE-TIME: function overloading ----------
// same name, different parameter type → compiler picks at compile time
void printArea(Circle c) {
    cout << "  [overload#1] Circle version: " << c.area() << endl;
}

void printArea(Rect r) {
    cout << "  [overload#2] Rect version: " << r.area() << endl;
}

int main() {
    cout << "========== POLYMORPHISM DEMO ==========" << endl << endl;

    cout << "--- 1) Runtime polymorphism: array of Shape* ---" << endl;
    {
        Circle c("Circle A", 3.0);
        Rect   r("Rect B", 4.0, 5.0);

        // base pointer derived object ko point kar raha hai
        Shape* arr[2] = { &c, &r };

        // ek hi loop, alag-alag behaviour — yehi runtime polymorphism hai
        for (int i = 0; i < 2; i++) {
            cout << "    via base pointer -> ";
            arr[i]->print();
            cout << "    area = " << arr[i]->area() << endl << endl;
        }
    }

    cout << "\n--- 2) Compile-time polymorphism: overloading ---" << endl;
    {
        Circle c("Circle A", 3.0);
        Rect   r("Rect B", 4.0, 5.0);
        printArea(c);   // compiler ne Circle version chuna
        printArea(r);   // compiler ne Rect version chuna
    }

    cout << "\n--- 3) Edge: base method via base pointer on boundary value ---" << endl;
    {
        Circle zero("Zero-Radius", 0.0);
        Shape* sp = &zero;
        cout << "    zero-radius circle area = " << sp->area() << "  (valid!)" << endl;

        Rect tiny("Tiny", 1e-9, 1e-9);
        Shape* sp2 = &tiny;
        cout << "    tiny rect area = " << sp2->area() << endl;
    }

    cout << "\n--- 4) Edge: negative dimensions are user error, class handles gracefully ---" << endl;
    {
        Rect neg("Neg", -2.0, 5.0);
        Shape* sp = &neg;
        cout << "    negative width area (math quirk, but no crash): "
             << sp->area() << endl;
    }

    cout << "\n--- 5) Virtual destructor in action (delete through base pointer) ---" << endl;
    {
        Shape* heapObj = new Circle("Heap Circle", 2.5);
        double a = heapObj->area();
        cout << "    heap circle area = " << a << endl;
        delete heapObj;   // derived dtor AND base dtor dono chalenge (virtual dtor)
    }

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}