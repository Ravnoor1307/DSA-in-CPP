/*
═══════════════════════════════════════════════
 TASK SET — ABSTRACTION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Your school's animal project needs a Zoo that can call
"describe()" on any creature without knowing whether it's a fish, bird, or mammal.
Similarly an art app needs every object to "draw()". An ABSTRACT base class defines the
contract ("every animal must describe itself") and concrete classes supply the details.
🧠 HOW TO SOLVE: Create abstract base classes using pure virtual `= 0`; derive concrete
classes override every pure virtual; use pointers/references of the abstract type to
call the methods polymorphically.
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

/* =============================
   TASK 1 (EASY) - Abstract Animal contract
   Statement: Define abstract class Animal with pure virtual void sound(). Derive
   Dog and Cat, overriding sound(). Show that an Animal object cannot be created.
   HINT: `virtual void sound() = 0;` in the base. Prove instantiation fails in comments.
   STARTER CODE:
   // class Animal {
   //  public:
   //   virtual void sound() = 0;
   //   virtual ~Animal() {}
   // };
============================= */

// =============================
// SOLUTION 1
// =============================
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void sound() = 0;          // pure virtual — contract
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "  Woof Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "  Meow~" << endl;
    }
};

/* =============================
   TASK 2 (EASY) - Interface Drawable
   Statement: Define interface Drawable { virtual void draw() = 0; }. Circle and
   Square implement draw() with unique outputs. Draw both via Drawable*.
   HINT: interface class = all methods pure virtual + virtual dtor.
   STARTER CODE:
   // class Drawable { public: virtual void draw() = 0; virtual ~Drawable() {} };
============================= */

// =============================
// SOLUTION 2
// =============================
class Drawable {
public:
    virtual void draw() = 0;
    virtual ~Drawable() {}
};

class Circle : public Drawable {
private:
    double r;
public:
    Circle(double radius) : r(radius) {}
    void draw() override {
        cout << "  O  (circle of radius " << r << ")" << endl;
    }
};

class Square : public Drawable {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void draw() override {
        cout << "  [ ]  (square of side " << side << ")" << endl;
    }
};

/* =============================
   TASK 3 (MEDIUM) - Abstract Machine + startButton contract
   Statement: Abstract Machine has pure virtual void start() and void stop(). Concrete
   WashingMachine and CoffeeMaker implement both. Loop through Machine*[2] pressing the
   same "start button".
   HINT: same pattern as Payment — uniform contract, different concrete behaviours.
   STARTER CODE:
   // class Machine { public: virtual void start() = 0; virtual void stop() = 0; virtual ~Machine(){} };
============================= */

// =============================
// SOLUTION 3
// =============================
class Machine {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Machine() {}
};

class WashingMachine : public Machine {
public:
    void start() override {
        cout << "  WashingMachine: tumbling clothes..." << endl;
    }
    void stop() override {
        cout << "  WashingMachine: stopped, drum empty" << endl;
    }
};

class CoffeeMaker : public Machine {
public:
    void start() override {
        cout << "  CoffeeMaker: brewing beans..." << endl;
    }
    void stop() override {
        cout << "  CoffeeMaker: cup ready" << endl;
    }
};

/* =============================
   TASK 4 (MEDIUM) - Abstract Animal with protected state + counter
   Statement: Animal has protected string name + pure virtual speak(). Parrot and
   Dolphin override speak() using name in their messages. Create them and call speak()
   polymorphically. Also count how many animals were ever created using a shared counter.
   HINT: static int count in base, incremented in the base ctor.
   STARTER CODE:
   // class Animal { protected: string name; static int total; public: Animal(string n); virtual void speak() = 0; virtual ~Animal(){} };
============================= */

// =============================
// SOLUTION 4 (renamed class to avoid clash with Task 1's Animal)
// =============================
class Creature {
protected:
    string name;
    static int total;                 // shared count across all creatures

public:
    Creature(string n) : name(n) {
        total++;
        cout << "  [Creature] " << name << " added (total " << total << ")" << endl;
    }
    virtual void speak() = 0;
    virtual ~Creature() {
        total--;
        cout << "  [Creature] " << name << " removed (total " << total << ")" << endl;
    }
    static int count() { return total; }
};

int Creature::total = 0;

class Parrot : public Creature {
public:
    Parrot(string n) : Creature(n) {}
    void speak() override {
        cout << "  " << name << " says: Squawk! Polly wants a cracker" << endl;
    }
};

class Dolphin : public Creature {
public:
    Dolphin(string n) : Creature(n) {}
    void speak() override {
        cout << "  " << name << " clicks: *echolocation*" << endl;
    }
};

/* =============================
   TASK 5 (HARD) - Abstract geometric shape with perimeter + area contract
   Statement: Abstract Shape2D with pure virtual area() and perimeter(). Rectangle2D
   and Circle2D implement both. Process a list of Shape2D* and print both metrics
   (as in a civil engineer's take-off sheet).
   HINT: keep two virtuals, both overridden; use M_PI from <cmath>.
   STARTER CODE:
   // class Shape2D { public: virtual double area() const = 0; virtual double perimeter() const = 0; virtual ~Shape2D(){} };
============================= */

// =============================
// SOLUTION 5
// =============================
#include <cmath>

class Shape2D {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape2D() {}
};

class Rectangle2D : public Shape2D {
private:
    double w, h;
public:
    Rectangle2D(double ww, double hh) : w(ww), h(hh) {}
    double area() const override {
        return w * h;
    }
    double perimeter() const override {
        return 2 * (w + h);
    }
};

class Circle2D : public Shape2D {
private:
    double r;
public:
    Circle2D(double rr) : r(rr) {}
    double area() const override {
        return M_PI * r * r;
    }
    double perimeter() const override {
        return 2 * M_PI * r;
    }
};

/* =============================
   TASK 6 (HARD) - Dashboard: abstract Report with multiple sheets
   Statement: Abstract Report { virtual void render() = 0; }. SalesReport and
   InventoryReport implement render() printing different tables. Build an array of
   Report*, render each on demand, then clean up via virtual dtor order prints.
   HINT: derived destructors print before the base — proves virtual dtor correctness.
   STARTER CODE:
   // class Report { public: virtual void render() = 0; virtual ~Report(){} };
============================= */

// =============================
// SOLUTION 6
// =============================
class Report {
public:
    virtual void render() = 0;
    virtual ~Report() {
        cout << "  [Report] base destroyed" << endl;
    }
};

class SalesReport : public Report {
public:
    void render() override {
        cout << "  +--------- SALES ---------+" << endl;
        cout << "  | Jul $100 | Aug $150 |   |" << endl;
        cout << "  +---------------------------+" << endl;
    }
    ~SalesReport() override {
        cout << "  [SalesReport] destroyed" << endl;
    }
};

class InventoryReport : public Report {
public:
    void render() override {
        cout << "  +------- INVENTORY --------+" << endl;
        cout << "  | SKU-1 x40 | SKU-2 x12 |  |" << endl;
        cout << "  +--------------------------+" << endl;
    }
    ~InventoryReport() override {
        cout << "  [InventoryReport] destroyed" << endl;
    }
};

int main() {
    cout << "========== TASK SOLUTIONS: ABSTRACTION ==========" << endl;

    cout << "\n--- Task 1: Abstract animal ---" << endl;
    Dog d;
    Cat c;
    Animal* zoo[2] = { &d, &c };
    for (int i = 0; i < 2; i++) {
        zoo[i]->sound();               // contract called through abstract pointer
    }
    // Animal a;  // COMPILE ERROR: 'Animal' is an abstract class.

    cout << "\n--- Task 2: Drawable interface ---" << endl;
    Circle  c1(3.0);
    Square  s1(4.5);
    Drawable* art[2] = { &c1, &s1 };
    for (int i = 0; i < 2; i++) {
        art[i]->draw();
    }

    cout << "\n--- Task 3: Machine start button ---" << endl;
    WashingMachine wm;
    CoffeeMaker    cm;
    Machine* machines[2] = { &wm, &cm };
    for (int i = 0; i < 2; i++) {
        machines[i]->start();
        machines[i]->stop();
    }

    cout << "\n--- Task 4: Creature with static counter ---" << endl;
    {
        Parrot  p("Mithu");
        Dolphin d2("Flipper");
        p.speak();
        d2.speak();
        cout << "  living creatures = " << Creature::count() << endl;
    }
    cout << "  alive after scope = " << Creature::count() << endl;

    cout << "\n--- Task 5: Shape2D engineer sheet ---" << endl;
    Rectangle2D rect(4.0, 5.0);
    Circle2D    circ(3.0);
    Shape2D* shapes[2] = { &rect, &circ };
    for (int i = 0; i < 2; i++) {
        cout << "  area=" << shapes[i]->area()
             << "  perimeter=" << shapes[i]->perimeter() << endl;
    }

    cout << "\n--- Task 6: Report dashboard with virtual dtor order ---" << endl;
    {
        Report* reports[2];
        reports[0] = new SalesReport();
        reports[1] = new InventoryReport();
        for (int i = 0; i < 2; i++) {
            reports[i]->render();
        }
        for (int i = 0; i < 2; i++) {
            delete reports[i];        // derived-print THEN base-print -> virtual dtor
        }
    }

    cout << "\n========== ALL ABSTRACTION TASKS DONE ==========" << endl;
    return 0;
}