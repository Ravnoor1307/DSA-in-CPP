/*
═══════════════════════════════════════════════
 TASK SET — CLASSES AND OBJECTS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A school registry stores name, roll number and
    marks for every student. One report-card formula works for the whole
    school, but every student has different data. You need one reusable
    TEMPLATE (the class) and many independent RECORDS (the objects).

 🧠 HOW TO SOLVE: 1) First decide the DATA: which things each object
    stores (members). 2) Then decide the BEHAVIOUR: which actions go into
    methods (set/display). 3) In main(), create an object and call methods
    with the dot (.) operator. 4) Remember: every object has its own copy
    of the data — changing one object does NOT affect another.

 MODES/TOPICS COVERED:
  1. Circle area using a setter and a method
  2. Bank account with create/deposit/withdraw/show
  3. Student average across two subjects
  4. Car park: an array of objects with accelerate()
  5. Book counter via a static member
  6. struct vs class and the size of an empty class
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <string>
using namespace std;

// ============ TASK 1 SOLUTION — Circle ============
class Circle {
private:
    double radius;          // private → main() directly touch nahi kar sakta

public:
    void setRadius(double r) {
        if (r < 0) r = 0;   // edge case: negative radius thoda bhi nahi
        radius = r;
    }
    double area() {
        return 3.14 * radius * radius;   // pi * r^2
    }
};

void runTask1() {
    Circle c;               // object bana (empty state)
    c.setRadius(7);         // setter se value dii
    cout << "Task1 : Circle area (r=7) = " << c.area() << "\n";
}

// ============ TASK 2 SOLUTION — BankAccount ============
class BankAccount {
private:
    string holder;
    double balance = 0;     // default member init — safe starting value

public:
    void create(string h, double b) {
        holder = h;
        balance = b;
    }
    void deposit(double amt) {
        balance += amt;
    }
    bool withdraw(double amt) {
        if (amt > balance) return false;   // paisa nahi hai → deny
        balance -= amt;
        return true;
    }
    void show() {
        cout << "  " << holder << " balance = " << balance << "\n";
    }
};

void runTask2() {
    BankAccount a;
    a.create("Rohit", 1000);
    a.deposit(2000);
    bool ok = a.withdraw(500);
    cout << "Task2 : withdraw 500 -> " << (ok ? "success" : "failed") << "\n";
    a.show();
}

// ============ TASK 3 SOLUTION — Student average ============
class Student {
private:
    string name;
    double s1, s2;          // 2 subjects ke marks

public:
    void setData(string n, double a, double b) {
        name = n;
        s1 = a;
        s2 = b;
    }
    double average() {
        return (s1 + s2) / 2.0;   // /2.0 → decimal division
    }
    void report() {
        cout << "  " << name << " average = " << average() << "\n";
    }
};

void runTask3() {
    Student u1, u2;         // 2 alag objects
    u1.setData("Meera", 78, 90);
    u2.setData("Arjun", 88, 85);
    cout << "Task3 : ";
    u1.report();
    cout << "        ";
    u2.report();
}

// ============ TASK 4 SOLUTION — Car fleet ============
class Car {
private:
    string brand;
    int speed;

public:
    void setCar(string b, int s) {
        brand = b;
        speed = s;
    }
    void accelerate() {
        speed += 10;        // har call pe 10 km/h badhao
    }
    void show() {
        cout << "  " << brand << " @ " << speed << " km/h\n";
    }
};

void runTask4() {
    Car fleet[3];           // array of OBJECTS — 3 alag cars
    fleet[0].setCar("Honda", 20);
    fleet[1].setCar("BMW", 30);
    fleet[2].setCar("Tata", 15);

    for (int i = 0; i < 3; i++) {
        fleet[i].accelerate();   // 1st bar
        fleet[i].accelerate();   // 2nd bar
    }
    cout << "Task4 : fleet after 2 accelerations each:\n";
    for (int i = 0; i < 3; i++) fleet[i].show();
}

// ============ TASK 5 SOLUTION — Book static counter ============
class Book {
private:
    string title;
    static int count;       // static → EK hi variable, sab objects share

public:
    Book(string t) : title(t) {
        count++;            // har naya book banne par +1
        cout << "  (Book created: " << title << ", total = " << count << ")\n";
    }
    ~Book() {
        count--;            // book mitti par -1
        cout << "  (Book destroyed: " << title << ", total = " << count << ")\n";
    }
    static int total() { return count; }   // static method — object ke bina bhi callable
};

int Book::count = 0;        // static member ko class ke BAHAR define karna padta hai

void runTask5() {
    cout << "Task5 :\n";
    Book b1("DSA"), b2("OOP"), b3("DBMS");   // teeno ek saath ban rahe hain
    cout << "  total books alive = " << Book::total() << "\n";
}

// ============ TASK 6 SOLUTION — struct vs class + empty class ============
struct Point { int x; };   // struct → sab members PUBLIC
class  Box   { int x; };   // class  → membership DEFAULT PRIVATE
class Empty {};            // koi member nahi

void runTask6() {
    Point p;
    p.x = 5;                          // ✅ public → direct assign
    cout << "Task6 : p.x = " << p.x << " (struct member public)\n";

    // Box b; b.x = 5;                // ❌ COMPILE ERROR: 'x' is private
    // (upar ki line uncomment karo to compiler turant galti batayega)

    cout << "        sizeof(Empty) = " << sizeof(Empty)
         << "  → 1 byte, kabhi 0 nahi (alag objects = alag addresses)\n";
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