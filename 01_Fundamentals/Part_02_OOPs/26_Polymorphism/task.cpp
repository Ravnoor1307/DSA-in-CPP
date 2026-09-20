/*
═══════════════════════════════════════════════
 TASK SET — POLYMORPHISM
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A zoo app plays each animal's sound over speakers. The code
stores Animal* and calls playSound(); each animal (Dog, Cat) decides its own sound at
run time. Similarly, a calculator keyboard has ONE "area" key that works for many shapes.
🧠 HOW TO SOLVE: For runtime polymorphism, create a base with a `virtual` function and
override in derived classes, then call through base pointers/references. For
compile-time polymorphism, overload the same function name with different signatures.
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

/* =============================
   TASK 1 (EASY) - Compile-time overloaded findMax
   Statement: Overload a function findMax(int,int), findMax(double,double,double) and
   findMax(string,string). Each returns the bigger value. Call all three from main.
   HINT: use ternary logic, write three separate definitions.
   STARTER CODE:
   // int findMax(int a, int b) { return a > b ? a : b; }
   // double findMax(double a, double b, double c) { ... }
   // string findMax(string a, string b) { ... }
============================= */

// =============================
// SOLUTION 1
// =============================
#include <iostream>
#include <string>
using namespace std;

int findMax(int a, int b) {
    return a > b ? a : b;            // simple ternary comparison
}

double findMax(double a, double b, double c) {
    double m = a > b ? a : b;
    return m > c ? m : c;
}

string findMax(string a, string b) {
    return a > b ? a : b;            // lexicographic dictionary comparison
}

/* =============================
   TASK 2 (EASY) - Runtime virtual makeSound
   Statement: class Animal with virtual void makeSound(); derive Dog ("Woof") and Cat
   ("Meow") overriding it. In main, store both in Animal* variables and call it.
   Also call makeSound() through a base REFERENCE.
   HINT: base pointer + virtual == runtime dispatch. Add virtual dtor too.
   STARTER CODE:
   // class Animal {
   //   public: virtual void makeSound() const { cout << "..." << endl; }
   //           virtual ~Animal() {}
   // };
============================= */

// =============================
// SOLUTION 2
// =============================
class Animal {
public:
    virtual void makeSound() const {
        cout << "  Generic animal sound" << endl;
    }
    virtual ~Animal() {}            // base dtor virtual — derived cleanup guaranteed
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "  Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "  Meow ~" << endl;
    }
};

/* =============================
   TASK 3 (MEDIUM) - Shape area family with virtual + pointer array
   Statement: Base class Shape has virtual area() returning 0. Derive Square(side)
   and Triangle(base,height). Fill Shape* arr[2], call area() for each via the loop.
   HINT: use the base pointer loop; the vtable resolves each object.
   STARTER CODE:
   // class Shape { public: virtual double area() const { return 0; } virtual ~Shape(){} };
   // class Square   : public Shape { double side; ... };
   // class Triangle : public Shape { double b, h; ... };
============================= */

// =============================
// SOLUTION 3
// =============================
class Shape {
public:
    virtual double area() const {
        return 0.0;                  // base fallback
    }
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

/* =============================
   TASK 4 (MEDIUM) - DisplayShapeWithName: polymorphic printName
   Statement: Base class NamedShape has virtual void printName(). Triangle (from T3)
   prints "Triangle", Pentagon prints "Pentagon". Show both through Shape-like base.
   HINT: reuse inheritance of NamedShape, override printName without computing area.
   STARTER CODE:
   // class NamedShape { public: virtual string name() const = 0; virtual ~NamedShape(){} };
============================= */

// =============================
// SOLUTION 4
// =============================
class NamedShape {
public:
    virtual void printName() const {
        cout << "  Generic shape" << endl;
    }
    virtual ~NamedShape() {}
};

class Pentagon : public NamedShape {
public:
    void printName() const override {
        cout << "  I am a Pentagon (5 sides)" << endl;
    }
};

class Heptagon : public NamedShape {
public:
    void printName() const override {
        cout << "  I am a Heptagon (7 sides)" << endl;
    }
};

/* =============================
   TASK 5 (HARD) - Polymorphic zoo with virtual destructor check
   Statement: Base class Creature (virtual speak + virtual dtor), derive two classes
   Lion and Elephant. Show fact that deleting via Creature* runs BOTH destructors:
   give each class a destructor that prints. Allocate with new, delete via base ptr.
   HINT: without virtual dtor the derived dtor is skipped — print order proves correctness.
   STARTER CODE:
   // class Creature {
   //   string tag;
   //  public: Creature(string t):tag(t){}
   //   virtual void speak() const = 0;
   //   virtual ~Creature(){ cout << "[Creature] dying\n"; }
   // };
============================= */

// =============================
// SOLUTION 5
// =============================
class Creature {
protected:
    string tag;
public:
    Creature(string t) : tag(t) {
        cout << "  [Creature] born: " << tag << endl;
    }
    virtual void speak() const {
        cout << "  ..." << endl;
    }
    virtual ~Creature() {
        cout << "  [Creature] destroyed: " << tag << endl;
    }
};

class Lion : public Creature {
public:
    Lion() : Creature("Lion") {}
    void speak() const override {
        cout << "  ROAR!!" << endl;
    }
    ~Lion() override {
        cout << "  [Lion] destroyed" << endl;
    }
};

class Elephant : public Creature {
public:
    Elephant() : Creature("Elephant") {}
    void speak() const override {
        cout << "  TROMPET" << endl;
    }
    ~Elephant() override {
        cout << "  [Elephant] destroyed" << endl;
    }
};

/* =============================
   TASK 6 (HARD) - Operator overloading as compile-time polymorphism
   Statement: Create struct Money { double amount; }. Overload operator+ (add money),
   operator> (compare), and operator<< (print) so that cout << m1 << " vs " << m2 works.
   Demonstrate in main with two Money objects.
   HINT: friend ostream& operator<<(ostream&, const Money&); operator+ returns by value.
   STARTER CODE:
   // struct Money { double amount; };
   // Money operator+(const Money& a, const Money& b) { return {a.amount + b.amount}; }
   // bool  operator>(const Money& a, const Money& b) { return a.amount > b.amount; }
============================= */

// =============================
// SOLUTION 6
// =============================
struct Money {
    double amount;
};

Money operator+(const Money& a, const Money& b) {
    return Money{ a.amount + b.amount };       // compile-time dispatch, no vtable
}

bool operator>(const Money& a, const Money& b) {
    return a.amount > b.amount;
}

ostream& operator<<(ostream& os, const Money& m) {
    os << "$" << m.amount;
    return os;
}

int main() {
    cout << "========== TASK SOLUTIONS: POLYMORPHISM ==========" << endl;

    cout << "\n--- Task 1: Overloaded findMax (compile-time) ---" << endl;
    cout << "  max(3,7)=" << findMax(3, 7)
         << " | max(2.5,1.1,4.9)=" << findMax(2.5, 1.1, 4.9)
         << " | max(\"apple\",\"banana\")=" << findMax(string("apple"), string("banana"))
         << endl;

    cout << "\n--- Task 2: virtual makeSound via pointer and reference ---" << endl;
    Dog d;
    Cat c;
    Animal* ptr = &d;
    ptr->makeSound();                 // runtime dispatch -> Dog
    ptr = &c;
    ptr->makeSound();                 // runtime dispatch -> Cat
    Animal& ref = d;
    ref.makeSound();                  // reference also dispatches virtually

    cout << "\n--- Task 3: Shape area family ---" << endl;
    Square   sq(4.0);
    Triangle tr(3.0, 6.0);
    Shape* shapes[2] = { &sq, &tr };
    for (int i = 0; i < 2; i++) {
        cout << "  area = " << shapes[i]->area() << endl;   // vtable resolves each
    }

    cout << "\n--- Task 4: NamedShape polymorphism ---" << endl;
    Pentagon p;
    Heptagon h;
    NamedShape* ns[2] = { &p, &h };
    for (int i = 0; i < 2; i++) {
        ns[i]->printName();
    }

    cout << "\n--- Task 5: Virtual destructor ordering ---" << endl;
    Creature* c1 = new Lion();
    Creature* c2 = new Elephant();
    c1->speak();
    c2->speak();
    delete c1;        // prints [Lion] then [Creature] -> derived dtor ran because virtual
    delete c2;

    cout << "\n--- Task 6: Operator overloading ---" << endl;
    Money a{ 100.0 }, b{ 50.0 };
    Money sum = a + b;
    cout << "  " << a << " + " << b << " = " << sum << endl;
    cout << "  a > b ? " << (a > b ? "yes" : "no") << endl;

    cout << "\n========== ALL POLYMORPHISM TASKS DONE ==========" << endl;
    return 0;
}