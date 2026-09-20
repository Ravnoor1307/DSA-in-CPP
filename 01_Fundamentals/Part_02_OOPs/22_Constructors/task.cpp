/*
═══════════════════════════════════════════════
 TASK SET — CONSTRUCTORS
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Every product in a factory starts its life through a standard "birth
 process": a blank order makes a default item, a detailed order makes a
 custom item, and duplicating an item must copy the DATA without sharing
 the raw material. In C++ that birth process is the constructor — default,
 parameterized, and copy.

 🧠 HOW TO SOLVE:
 1) Jis tarah ka object chahiye, us hisaab se constructor ka parameter list
    choose karo (0 args = default, k args = parameterized, reference = copy).
 2) Initializer list me members ko pehle ready karo, body me validate karo.
 3) Pointer member ho to COPY CTOR me naya heap allocate karo (DEEP copy),
    warna dono objects ek hi heap share karenge → double-delete crash.

 TASKS (EASY → HARD):

 TASK 1 — Point: default + parameterized (EASY)
 class Point with int x, y. Write a default ctor (0,0) and a parameterized
 ctor (a,b). Each ctor prints what it created. In main() make P1 (default)
 and P2(3,4), print both.
 💡 HINT: ctor name = class name, no return type; initializer list : x(a), y(b).
 ✏️ STARTER CODE:
 // class Point {
 //   private: int x, y;
 //   public:
 //     Point();            // default → (0,0)
 //     Point(int a, int b);
 //     void show() const;
 // };

 TASK 2 — Employee: overloaded ctors printing (EASY)
 class Employee with name + id. Write THREE ctors: default (name "unknown",
 id 0), name-only, and name+id. Every ctor prints "Employee created: ...".
 In main() make all three kinds.
 💡 HINT: overload = same name, alag parameter lists — compiler call ke
    hisaab se chunega.
 ✏️ STARTER CODE:
 // class Employee {
 //   private: string name; int id;
 //   public:
 //     Employee();
 //     Employee(string n);
 //     Employee(string n, int i);
 // };

 TASK 3 — Rectangle: initializer list (MEDIUM)
 class Rectangle: private int len, wid, area. Parameterized ctor sirf
 initializer list se len/wid set kare aur body me area = len * wid kare
 (default args l=0, w=0). Methods: areaValue(), setDim(), show().
 💡 HINT: default args ek hi ctor ko default + param dono bana dete hain.
 ✏️ STARTER CODE:
 // class Rectangle {
 //   private: int len; int wid; int area;
 //   public:
 //     Rectangle(int l = 0, int w = 0);   // initializer list use karo
 //     void show() const;
 // };

 TASK 4 — Circle: overloaded birth styles (MEDIUM)
 class Circle with double r. Ctors: default r=0, ctor(radius), and
 ctor(double val, bool isDiameter). isDiameter true ho to r = val/2.
 Print "Circle created" with radius in each.
 💡 HINT: (double, bool) signature overload ko disambiguate karta hai.
 ✏️ STARTER CODE:
 // class Circle {
 //   private: double r;
 //   public:
 //     Circle();
 //     Circle(double radius);
 //     Circle(double val, bool isDiameter);
 //     void show() const;
 // };

 TASK 5 — DynamicArray: DEEP copy (HARD)
 class DynamicArray with int* arr + int n. Parameterized ctor (size, seed)
 fills arr[i] = i*seed. Copy ctor = DEEP copy (naya heap, values copy).
 Destructor delete[] kare. Methods: set(), show(). Prove independence:
 copy A2 = A1, change A2[0], show A1 unchanged.
 💡 HINT: custom copy ctor ke bina default SHALLOW copy hoti — second delete[]
    pe crash. Alag heap = alag zindagi.
 ✏️ STARTER CODE:
 // class DynamicArray {
 //   private: int* arr; int n;
 //   public:
 //     DynamicArray(int size, int seed);
 //     DynamicArray(const DynamicArray& src);   // deep copy
 //     ~DynamicArray();
 //     void set(int i, int v);
 //     void show() const;
 // };

 TASK 6 — Gadget: static alive counter (HARD)
 class Gadget: private string serial; static int alive. Ctor alive++ and
 print build message with alive count; dtor alive-- with destroy message.
 Make 3 gadgets in a block, jo block khatam hote hi sab destroy hon.
 💡 HINT: static int Gadget::alive = 0; class ke BAHAR define karna mat bhoolo.
 ✏️ STARTER CODE:
 // class Gadget {
 //   private: string serial; static int alive;
 //   public:
 //     Gadget(string s);
 //     ~Gadget();
 //     static int count() { return alive; }
 // };
 // int Gadget::alive = 0;
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <string>
using namespace std;

// ============ TASK 1 SOLUTION — Point ============
class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {                              // DEFAULT ctor
        cout << "  Point default ctor -> (" << x << ", " << y << ")\n";
    }
    Point(int a, int b) : x(a), y(b) {                  // PARAMETERIZED ctor
        cout << "  Point param ctor   -> (" << x << ", " << y << ")\n";
    }
    void show() const {
        cout << "  point = (" << x << ", " << y << ")\n";
    }
};

void runTask1() {
    Point P1;              // default → (0,0)
    Point P2(3, 4);        // param    → (3,4)
    cout << "Task1 :\n";
    P1.show();
    P2.show();
}

// ============ TASK 2 SOLUTION — Employee overloaded ctors ============
class Employee {
private:
    string name;
    int id;

public:
    Employee() : name("unknown"), id(0) {               // ctor #1: default
        cout << "  Employee created: " << name << " (id " << id << ")\n";
    }
    Employee(string n) : name(n), id(0) {               // ctor #2: name-only
        cout << "  Employee created: " << name << " (id " << id << ")\n";
    }
    Employee(string n, int i) : name(n), id(i) {        // ctor #3: name + id
        cout << "  Employee created: " << name << " (id " << id << ")\n";
    }
};

void runTask2() {
    cout << "Task2 :\n";
    Employee e1;                 // default
    Employee e2("Ravi");         // name-only
    Employee e3("Neha", 1042);   // name + id  → overloading ne sahi ctor chuna
}

// ============ TASK 3 SOLUTION — Rectangle initializer list ============
class Rectangle {
private:
    int len;
    int wid;
    int area = 0;                // default member init

public:
    // initializer list me len/wid/area pehle hi set, body me sirf compute:
    Rectangle(int l = 0, int w = 0) : len(l), wid(w), area(l * w) {}

    void setDim(int l, int w) {
        len = l;
        wid = w;
        area = l * w;
    }
    void show() const {
        cout << "  len=" << len << " wid=" << wid << " area=" << area << "\n";
    }
};

void runTask3() {
    cout << "Task3 :\n";
    Rectangle r1;                // default (0,0) — default args ne handle kiya
    Rectangle r2(6, 5);          // param — initializer list se set hua
    r1.show();
    r2.show();
}

// ============ TASK 4 SOLUTION — Circle overloads ============
class Circle {
private:
    double r;

public:
    Circle() : r(0) {
        cout << "  Circle created (default radius 0)\n";
    }
    Circle(double radius) : r(radius) {
        cout << "  Circle created (radius=" << r << ")\n";
    }
    Circle(double val, bool isDiameter) : r(isDiameter ? val / 2 : val) {
        cout << "  Circle created from diameter (" << val << ") -> r=" << r << "\n";
    }
    void show() const {
        cout << "  radius = " << r << ", area = " << (3.14 * r * r) << "\n";
    }
};

void runTask4() {
    cout << "Task4 :\n";
    Circle a;                    // default
    Circle b(5);                 // radius style
    Circle c(14, true);          // diameter style → r = 7
    a.show();
    b.show();
    c.show();
}

// ============ TASK 5 SOLUTION — DynamicArray deep copy ============
class DynamicArray {
private:
    int* arr;
    int n;

public:
    DynamicArray(int size, int seed) : n(size) {        // param ctor
        arr = new int[n];                               // heap allocate
        for (int i = 0; i < n; i++) arr[i] = i * seed;  // fill seed pattern
        cout << "  DynamicArray created, size=" << n << "\n";
    }

    DynamicArray(const DynamicArray& src) : n(src.n) {  // COPY ctor
        arr = new int[n];                               // DEEP: naya heap
        for (int i = 0; i < n; i++) arr[i] = src.arr[i];// values copy
        cout << "  Copy (DEEP) done for size=" << n << "\n";
    }

    ~DynamicArray() {
        delete[] arr;                                   // heap free — no leak
        cout << "  DynamicArray destroyed, size=" << n << "\n";
    }

    void set(int i, int v) {
        if (i >= 0 && i < n) arr[i] = v;                // bounds check
    }
    void show() const {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};

void runTask5() {
    cout << "Task5 :\n";
    DynamicArray A1(4, 3);        // → 0 3 6 9
    A1.show();
    DynamicArray A2 = A1;         // deep copy → naya heap
    cout << "  A2[0] change 99 ...\n";
    A2.set(0, 99);
    cout << "  A1 (original): "; A1.show();
    cout << "  A2 (copy)    : "; A2.show();
    cout << "  proof: A1 ka data 0 hai (deep copy = independent)\n";
}

// ============ TASK 6 SOLUTION — Gadget static alive counter ============
class Gadget {
private:
    string serial;
    static int alive;             // ek hi counter, sab objects share

public:
    Gadget(string s) : serial(s) {
        alive++;
        cout << "  Gadget '" << serial << "' built  | alive = " << alive << "\n";
    }
    ~Gadget() {
        alive--;
        cout << "  Gadget '" << serial << "' killed | alive = " << alive << "\n";
    }
    static int count() { return alive; }
};

int Gadget::alive = 0;            // static member ko bahar define karo

void runTask6() {
    cout << "Task6 :\n";
    if (true) {                   // block scope
        Gadget g1("A"), g2("B"), g3("C");
        cout << "  inside block: alive = " << Gadget::count() << "\n";
    }                             // block ends → g3, g2, g1 reverse me destroy
    cout << "  after block : alive = " << Gadget::count() << "\n";
}

// ============ MAIN — sab tasks chalao ============
int main() {
    runTask1();
    cout << "\n";
    runTask2();
    cout << "\n";
    runTask3();
    cout << "\n";
    runTask4();
    cout << "\n";
    runTask5();
    cout << "\n";
    runTask6();
    return 0;
}