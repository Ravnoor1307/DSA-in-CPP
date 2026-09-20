/*
═══════════════════════════════════════════════
 INHERITANCE
 ⏱️ TIME COMPLEXITY: O(1) for ctor/dtor chaining (fixed call chain per object) and O(1) for member access; no loops involved.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of an animal kingdom. Every dog is an animal — it breathes, eats, and sleeps,
 exactly like every other animal. But a dog ALSO barks and wags its tail. Instead of
 rewriting "breathe/eat/sleep" inside the Dog class, we say "Dog IS-A Animal" and let
 Dog inherit all the animal behaviour automatically. The same pattern runs your city:
 every Car and Bus IS-A Vehicle — they all have a brand, a top speed, and an engine,
 but a Car adds seats while a Bus adds passenger capacity. Inheritance means you write
 the common stuff ONCE in the base class and then REUSE it everywhere.

 📖 THEORY: (pure English, beginner-level)
 - Inheritance lets a DERIVED (child) class reuse the members of a BASE (parent) class.
 - It models an IS-A relationship: Car IS-A Vehicle, Dog IS-A Animal, Manager IS-A Employee.
 - Syntax: class Car : public Vehicle { ... };
 - PUBLIC inheritance keeps base's public members public and base's protected members protected in the child.
 - PROTECTED members are accessible in the base AND in derived classes, but not by outsiders.
 - CONSTRUCTOR ORDER: base ctor runs FIRST, then derived ctor (base must be built before adding child parts).
 - DESTRUCTOR ORDER is REVERSED: derived dtor first, then base dtor (destroy child parts before the base).
 - MULTILEVEL: A → B → C (C inherits everything from A through B).
 - MULTIPLE inheritance: class D : public B, public C (D inherits from two bases) — rare and requires care.

 ASCII DIAGRAM — Vehicle → Car chain:
 ┌─────────────────────────────┐
 │   class Vehicle (base)      │
 │  protected:                 │
 │    string brand;            │
 │    int speed;               │
 │  public:                    │
 │    Vehicle(string, int)     │
 │    void print()             │
 └────────────┬────────────────┘
              │  "Car IS-A Vehicle"
              ▼
 ┌─────────────────────────────┐
 │   class Car : public Vehicle│
 │  private:                   │
 │    int seats;               │
 │  public:                    │
 │    Car(string, int, int)    │
 │    void print()             │
 └─────────────────────────────┘

 CONSTUCTOR/DESTRUCTOR ORDER (ASCII):
  ctor:  Vehicle() ──► Car()
  dtor:  Car()     ──► Vehicle()
          (reverse order)

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Write the base class with shared data + behaviour (brand, speed, print()).
         WHY: Common code is written once, reducing duplication across all vehicles.
 Step 2: Derive Car : public Vehicle and add ONLY what is new (seats).
         WHY: Code reuse — Car automatically owns brand & speed from Vehicle.
 Step 3: Chain constructors — Car's ctor calls Vehicle's ctor via the initializer list.
         WHY: The base part of the object must exist before the derived part is built.
 Step 4: Override print() in the child to show child-specific data too.
         WHY: The child customises behaviour while still honouring the IS-A contract.

 VISUAL WALKTHROUGH: (construction of a Car object)
 step1: allocate memory (Vehicle part + Car part)
 step2: Vehicle(string,int) runs        → brand & speed initialized
 step3: Car(...) runs                   → seats initialized
        ┌─────────────────────────┐
        │ object: brand=Volvo     │  ← from Vehicle
        │         speed=180       │
        │         seats=5         │  ← added by Car
        └─────────────────────────┘

 DRY RUN: (trace of demo output)
 Creating myCar("Volvo", 180, 5):
   1. Car ctor invoked.
   2. Initializer list calls Vehicle("Volvo", 180).
   3. Vehicle ctor prints "[Vehicle] Created: Volvo @ 180 km/h"
   4. Car ctor body prints "[Car] Created: Volvo with 5 seats"
 myCar.print():
   → delegation: base print prints brand & speed; then Car prints its seats.
 Destroying myCar:
   → Car dtor prints "[Car] Destroyed", then base dtor prints "[Vehicle] Destroyed".
 Multilevel: cycles of three print chain from topmost base to deepest child.
 Multiple inheritance D: D←B, D←C — bees fly AND animals breathe...

 TIME COMPLEXITY CALCULATION:
 - Constructor chain: derived calls base (1 extra call) = constant → O(1)
 - Destructor chain: derived dtor then base dtor = constant → O(1)
 - print(): each print runs a constant number of << ops → O(1)
 - No scanning, no growth with input size
 → Time Complexity = O(1) for construction, destruction, and access

 SPACE COMPLEXITY CALCULATION:
 - Vehicle object: brand (std::string ~32 bytes) + speed (int 4 bytes) ≈ O(1) fixed
 - Car object: Vehicle part + seats (int) = fixed, does NOT depend on runtime data
 - One vpointer is NOT added here because there are no virtual functions in this demo
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────────────┬────────────────────────────────────┐
 │ Aspect               │ Multilevel (A→B→C)           │ Multiple (D: B, C)                 │
 ├──────────────────────┼──────────────────────────────┼────────────────────────────────────┤
 │ Relationship         │ Linear chain (IS-A)          │ Two parents (IS-A both)            │
 │ Code reuse           │ One direction only           │ Two sources at once                │
 │ Diamond problem      │ Impossible                    │ Possible (D inherits twice from A) │
 │ Readability          │ Simple, easy to trace        │ Harder, ambiguous members          │
 │ Typical use          │ Animal→Mammal→Dog            │ Flyable+Swimable mixin            │
 └──────────────────────┴──────────────────────────────┴────────────────────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

// ---------- BASE CLASS ----------
class Vehicle {
protected:
    string brand;   // protected — derived ko dikhega, bahar wale ko nahi
    int speed;      // km/h

public:
    // base constructor — derived ke initializer list se call hota hai
    Vehicle(string b, int s) : brand(b), speed(s) {
        cout << "[Vehicle] CONSTRUCTED: " << brand << " @ " << speed << " km/h" << endl;
    }

    // print base info (child isko override karega)
    void print() const {
        cout << "  Vehicle info -> Brand: " << brand << " | Speed: " << speed << " km/h";
    }

    // base destructor — object destroy honge tab sabse LAST me yahi chalta hai
    ~Vehicle() {
        cout << "[Vehicle] DESTROYED: " << brand << endl;
    }
};

// ---------- DERIVED CLASS ----------
class Car : public Vehicle {   // Car IS-A Vehicle
private:
    int seats;      // bas yahi naya data hona chahiye, baaki base se saja leya

public:
    // constructor chaining — base part pehle banega
    Car(string b, int s, int n) : Vehicle(b, s), seats(n) {
        cout << "[Car] CONSTRUCTED: " << brand << " with " << seats << " seats" << endl;
    }

    // override — pehle base ka print call, phir apna extra
    void print() const {
        Vehicle::print();
        cout << " | Seats: " << seats << endl;
    }

    ~Car() {
        cout << "[Car] DESTROYED: " << brand << endl;
    }
};

// ---------- MULTILEVEL: Bus extends Vehicle ----------
class Bus : public Vehicle {
private:
    int capacity;   // passenger count

public:
    Bus(string b, int s, int cap) : Vehicle(b, s), capacity(cap) {
        cout << "[Bus] CONSTRUCTED: " << brand << " capacity " << capacity << endl;
    }

    void print() const {
        Vehicle::print();
        cout << " | Capacity: " << capacity << endl;
    }

    ~Bus() {
        cout << "[Bus] DESTROYED: " << brand << endl;
    }
};

// ---------- MULTILEVEL: ElectricCar -> Car -> Vehicle ----------
class ElectricCar : public Car {
private:
    int batteryRange;  // km

public:
    ElectricCar(string b, int s, int n, int range)
        : Car(b, s, n), batteryRange(range) {
        cout << "[ElectricCar] CONSTRUCTED: " << brand << " range " << batteryRange << " km" << endl;
    }

    void print() const {
        Car::print();   // Car::print uses Vehicle::print internally too
        cout << "  Battery range: " << batteryRange << " km" << endl;
    }

    ~ElectricCar() {
        cout << "[ElectricCar] DESTROYED: " << brand << endl;
    }
};

// ---------- MULTIPLE INHERITANCE INTRO ----------
class Flyable {
public:
    void fly() const {
        cout << "  * Flying through the sky" << endl;
    }
};

class Swimmable {
public:
    void swim() const {
        cout << "  * Swimming through the water" << endl;
    }
};

// Duck inherits from TWO bases — behaviour of both
class Duck : public Flyable, public Swimmable {
public:
    void quack() const {
        cout << "  * Quack Quack!" << endl;
    }
};

int main() {
    cout << "========== INHERITANCE DEMO ==========" << endl << endl;

    cout << "--- 1) Simple Inheritance: Car (IS-A Vehicle) ---" << endl;
    {
        Car myCar("Volvo", 180, 5);
        myCar.print();
        // protected member accessible in main? NO:
        // cout << myCar.brand;  // ERROR: 'brand' is protected
    } // <- yahin Car aur Vehicle ke destructors reverse order me chalenge

    cout << "\n--- 2) Multilevel: ElectricCar -> Car -> Vehicle ---" << endl;
    {
        ElectricCar tesla("Tesla", 200, 5, 500);
        tesla.print();
    }

    cout << "\n--- 3) Higher-level pointer to a derived object (still works) ---" << endl;
    {
        Bus cityBus("Volvo Bus", 100, 60);
        Vehicle *vp = &cityBus;    // base pointer derived ko point karta hai (slicing safe here)
        cout << "  Vehicle pointer -> ";
        vp->print();
        cout << "\n  Bus pointer     -> ";
        cityBus.print();
    }

    cout << "\n--- 4) Multiple Inheritance: Duck inherits Flyable + Swimmable ---" << endl;
    Duck d;
    d.fly();
    d.swim();
    d.quack();

    cout << "\n--- 5) Protected member access demonstration ---" << endl;
    {
        Bus b2("Tata", 80, 40);
        cout << "  Bus.print() (base->derived chain): ";
        b2.print();
    }

    cout << "\n--- 6) Edge: very long multilevel chain ---" << endl;
    {
        ElectricCar e2("Nexon EV", 120, 4, 350);
        e2.print();
    }

    cout << "\n========== DEMO COMPLETE (observe ctor/dtor ordering printed above) ==========" << endl;
    return 0;
}