/*
═══════════════════════════════════════════════
 TASK SET — CLASSES AND OBJECTS
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A school registry stores name, roll number and marks for every student.
 One report-card formula works for the whole school, but every student has
 different data. You need one reusable TEMPLATE (the class) and many
 independent RECORDS (the objects).

 🧠 HOW TO SOLVE:
 1) Pehle decide DATA: kaunsi cheezein har object me store hongi (members).
 2) Phir decide BEHAVIOUR: kaunse kaam methods me likhne hain (set/display).
 3) main() me object banao aur dot (.) operator se methods call karo.
 4) Yaad rakho: har object ki apni data copy hoti hai — ek object me change
    karne se doosre object pe koi asar NAHI hota.

 TASKS (EASY → HARD):

 TASK 1 — CIRCLE ka area  (EASY)
 Make a class Circle with a private double radius. Provide setRadius() and
 a method area() that returns 3.14 * radius * radius. In main() set the
 radius to 7 and print the area.
 💡 HINT: setter me assign karo, area() me compute karo — basic data hiding.
 ✏️ STARTER CODE:
 // class Circle {
 //   private:
 //     double radius;
 //   public:
 //     void setRadius(double r) { radius = r; }
 //     double area() { return 3.14 * radius * radius; }
 // };
 // main me: Circle c; c.setRadius(7); cout << c.area();

 TASK 2 — BANK ACCOUNT  (EASY)
 Make class BankAccount with holder name and balance (private). Methods:
 create(), deposit(), withdraw() (return false if amount > balance), show().
 Create one account, deposit 2000, withdraw 500, print final balance.
 💡 HINT: withdraw me pehle check karo ki paisa kafi hai ya nahi.
 ✏️ STARTER CODE:
 // class BankAccount {
 //   private:
 //     string holder;
 //     double balance;
 //   public:
 //     void create(string h, double b);
 //     void deposit(double amt);
 //     bool withdraw(double amt);
 //     void show();
 // };

 TASK 3 — STUDENT ka AVERAGE  (EASY)
 class Student with name + marks of 2 subjects. setData() for input and
 average() returning (sub1 + sub2) / 2. In main() make 2 students and print
 each one's name + average.
 💡 HINT: average = (marks1 + marks2) / 2.0 — /2.0 se double division hota hai.
 ✏️ STARTER CODE:
 // class Student {
 //   private: string name; double s1, s2;
 //   public:
 //     void setData(string n, double a, double b);
 //     double average();
 //     void report();
 // };

 TASK 4 — CAR PARK (MEDIUM)
 class Car with brand and speed. Methods: setCar(), accelerate() (speed
 +10) and show(). Make an ARRAY of 3 cars, accelerate each car twice, then
 print all speeds.
 💡 HINT: Car fleet[3]; loop me fleet[i] ka method call karo.
 ✏️ STARTER CODE:
 // class Car {
 //   private: string brand; int speed;
 //   public:
 //     void setCar(string b, int s);
 //     void accelerate();     // speed += 10
 //     void show();
 // };

 TASK 5 — BOOK COUNTER via STATIC member (MEDIUM)
 class Book with title + a STATIC int count. The constructor increases
 count, the destructor decreases it. Create 3 books and print total() after
 each creation.
 💡 HINT: static member sabhi objects SHARE karte hain; class ke bahar define
    karna padta hai: int Book::count = 0;
 ✏️ STARTER CODE:
 // class Book {
 //   private: string title; static int count;
 //   public:
 //     Book(string t);
 //     static int total();
 // };
 // int Book::count = 0;

 TASK 6 — class vs struct + empty class size (HARD)
 Make struct Point { int x; }; and class Box { int x; };. Inside main() try
 p.x = 5 (OK) and b.x = 5 (compile error — private). Then print sizeof() of
 an empty class and explain why it is never 0.
 💡 HINT: struct = public by default, class = private by default.
 ✏️ STARTER CODE:
 // struct Point { int x; };
 // class  Box   { int x; };
 // class Empty {};
 // Point p;   p.x = 5;        // ✅ public member
 // Box   b;   b.x = 5;        // ❌ COMPILE ERROR: x private hai
 // cout << sizeof(Empty);     // 1
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