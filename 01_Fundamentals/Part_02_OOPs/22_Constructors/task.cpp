/*
═══════════════════════════════════════════════
 TASK SET — CONSTRUCTORS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: Every product in a factory starts its life
    through a standard "birth process": a blank order makes a default
    item, a detailed order makes a custom item, and duplicating an item
    must copy the DATA without sharing the raw material. In C++ that birth
    process is the constructor — default, parameterized, and copy.

 🧠 HOW TO SOLVE: 1) Choose the constructor's parameter list based on the
    kind of object you need (0 args = default, k args = parameterized,
    reference = copy). 2) Prepare members first in the initializer list,
    then validate in the body. 3) With a pointer member, allocate a NEW
    heap in the copy constructor (DEEP copy); otherwise both objects share
    the same heap → double-delete crash.

 MODES/TOPICS COVERED:
  1. Point: default + parameterized constructors
  2. Employee: overloaded constructors that print
  3. Rectangle: initializer list with default arguments
  4. Circle: overloaded "birth styles" (radius vs diameter)
  5. DynamicArray: deep copy constructor
  6. Gadget: static alive counter
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