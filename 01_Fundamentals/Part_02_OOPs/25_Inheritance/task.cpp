/*
═══════════════════════════════════════════════
 TASK SET — INHERITANCE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A company's HR system stores employees. Every manager, engineer,
and intern IS-AN employee, sharing name + salary, but each has extra fields and duties.
Code that understands "Employee" can work with everyone, because of inheritance.
🧠 HOW TO SOLVE: Put shared data/behaviour in the BASE class; derive specialised classes
and add ONLY their differences. Chain constructors with the base initializer list.
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

/* =============================
   TASK 1 (EASY) — Employee → Manager
   Statement: Create class Employee { protected name, salary }. Derive Manager that
   adds a department. Constructor chaining: Employee(name, salary) → Manager(...).
   Provide print() in both.
   💡 HINT: use Manager(string n, double s, string dep) : Employee(n, s), dept(dep)
   ✏️ STARTER CODE:
   // class Employee {
   // protected:
   //     string name;
   //     double salary;
   // public:
   //     Employee(string n, double s) : name(n), salary(s) {}
   //     void print() const;
   // };
============================= */

// =============================
// SOLUTION 1
// =============================
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) {}

    void print() const {
        cout << "  [Employee] " << name << " earns " << salary << endl;
    }
};

class Manager : public Employee {
private:
    string dept;

public:
    // ctor chaining — Employee part pehle banega, phir dept
    Manager(string n, double s, string d) : Employee(n, s), dept(d) {}

    void print() const {
        Employee::print();
        cout << "  [Manager] dept: " << dept << endl;
    }
};

/* =============================
   TASK 2 (EASY) — Animal → Dog with protected member
   Statement: class Animal { protected: string sound; } with a speak() method.
   Derive Dog that overrides the sound inside its own constructor.
   Call speak() from a Dog object to confirm inherited behaviour.
   💡 HINT: protected member 'sound' can be written directly by Dog's ctor.
   ✏️ STARTER CODE:
   // class Animal {
   // protected:
   //     string sound;
   // public:
   //     Animal() : sound("...") {}
   //     void speak() const { cout << sound << endl; }
   // };
============================= */

// =============================
// SOLUTION 2
// =============================
class Animal {
protected:
    string sound;       // protected — derived class ise apne way me use kar sakta hai

public:
    Animal() : sound("Generic animal noise") {}
    void speak() const {
        cout << "  " << sound << endl;
    }
};

class Dog : public Animal {
public:
    // derived ctor directly writes the inherited protected member — yahin re-use hai
    Dog() {
        sound = "Woof! Woof!";
    }
};

/* =============================
   TASK 3 (MEDIUM) — Geometric multilevel: Shape → Rectangle → Square
   Statement: Shape has protected double area; Rectangle : Shape adds width/height
   and computes area in its ctor; Square : Rectangle forces width==height. Print
   every level's info with overridden print().
   💡 HINT: Square's ctor calls Rectangle w/h with same value.
   ✏️ STARTER CODE:
   // class Shape { protected: double area; public: Shape() : area(0) {} void print() const; };
   // class Rectangle : public Shape { protected: double w,h; public: Rectangle(...); void print() const; };
   // class Square : public Rectangle { public: Square(double s); };
============================= */

// =============================
// SOLUTION 3
// =============================
class Shape {
protected:
    double area;

public:
    Shape() : area(0) {}

    void print() const {
        cout << "  [Shape] area = " << area << endl;
    }
};

class Rectangle : public Shape {
protected:
    double w, h;

public:
    Rectangle(double width, double height) : w(width), h(height) {
        area = w * h;      // area protected hai, derived use kar sakta hai
    }

    void print() const {
        cout << "  [Rectangle] " << w << " x " << h << " -> area " << area << endl;
    }
};

class Square : public Rectangle {
public:
    // square = rectangle jahan width == height
    Square(double s) : Rectangle(s, s) {}

    void print() const {
        cout << "  [Square] side " << w << " -> area " << area << endl;
    }
};

/* =============================
   TASK 4 (MEDIUM) — Account hierarchy: Account → SavingsAccount
   Statement: class Account { protected: double balance; } with deposit/withdraw.
   SavingsAccount adds an interestRate and a method applyInterest() that is only
   available on savings, not on a plain account.
   💡 HINT: derive, add new method, reuse deposit for the interest credit.
   ✏️ STARTER CODE:
   // class Account { protected: double balance; public: Account(double b):balance(b){} bool deposit(double); bool withdraw(double); double getBalance() const; };
============================= */

// =============================
// SOLUTION 4
// =============================
class Account {
protected:
    double balance;

public:
    Account(double b) : balance(b) {}

    bool deposit(double amt) {
        if (amt <= 0) {
            cout << "  ✗ deposit rejected" << endl;
            return false;
        }
        balance += amt;
        return true;
    }

    bool withdraw(double amt) {
        if (amt <= 0 || amt > balance) {
            cout << "  ✗ withdraw rejected" << endl;
            return false;
        }
        balance -= amt;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;   // 0.05 = 5%

public:
    SavingsAccount(double b, double rate) : Account(b), interestRate(rate) {}

    // naya method jo sirf savings ko mila — reuse deposit() for the credit
    void applyInterest() {
        double interest = balance * interestRate;
        deposit(interest);
        cout << "  Interest " << interest << " credited";
    }

    void describe() const {
        cout << "  Balance = " << balance << ", rate = " << interestRate * 100 << "%" << endl;
    }
};

/* =============================
   TASK 5 (HARD) — Puzzle: multilevel with protected chain
   (A→B→C, protected member visible to both levels)
   Statement: Build A { protected: int x; }, B : A { computes y = x*2 in ctor }, C : B
   adds z = x+y. Show that C can read x and y even though they were born in different
   classes — the whole chain shares the protected data.
   💡 HINT: derive B: public A and C: public B; C's ctor reads inherited members.
   ✏️ STARTER CODE:
   // class A { protected: int x; public: A(int v):x(v){} };
   // class B : public A { protected: int y; public: B(int v):A(v), y(x*2){} };
   // class C : public B { private: int z; public: C(int v):B(v), z(x+y){} void print() const; };
============================= */

// =============================
// SOLUTION 5
// =============================
class A {
protected:
    int x;

public:
    A(int v) : x(v) {
        cout << "  [A] built: x = " << x << endl;
    }
};

class B : public A {
protected:
    int y;

public:
    B(int v) : A(v), y(x * 2) {
        cout << "  [B] built: y = " << y << endl;
    }
};

class C : public B {
private:
    int z;

public:
    C(int v) : B(v), z(x + y) {
        cout << "  [C] built: z = " << z << endl;
    }

    void print() const {
        cout << "  x=" << x << " y=" << y << " z=" << z << endl;
    }
};

/* =============================
   TASK 6 (HARD) — Hybrid: inheritance + nothing else with invalid base input rejection
   Statement: Extend Task 4 by giving Account a static factory guard: creation must
   reject negative balance by printing an error and falling back to 0. Derive
   FixedDeposit from SavingsAccount that blocks withdrawal after creation (permanent).
   Show blocked withdraw returns false while balance stays intact.
   💡 HINT: override withdraw() in the child with an always-false policy.
   ✏️ STARTER CODE:
   // class FixedDeposit : public SavingsAccount {
   // public: FixedDeposit(double b, double r) : SavingsAccount(max(b,0.0), r) {}
   //         bool withdraw(double) override;
   // };
============================= */

// =============================
// SOLUTION 6
// =============================
class FixedDeposit : public SavingsAccount {
public:
    FixedDeposit(double b, double r)
        : SavingsAccount(b < 0 ? 0.0 : b, r) {   // negative balance guard at creation
        cout << "  [FixedDeposit] created; withdrawals permanently blocked" << endl;
    }

    // policy override: fail EVERY withdrawal
    bool withdraw(double amt) {
        cout << "  ✗ Withdrawal blocked: Fixed Deposit locked until maturity" << endl;
        return false;
    }
};

int main() {
    cout << "========== TASK SOLUTIONS: INHERITANCE ==========" << endl;

    cout << "\n--- Task 1: Employee -> Manager ---" << endl;
    Manager m("Anita", 90000, "Engineering");
    m.print();

    cout << "\n--- Task 2: Animal -> Dog (protected member reuse) ---" << endl;
    Animal a;
    a.speak();          // generic noise
    Dog d;
    d.speak();          // inherited method, overridden data

    cout << "\n--- Task 3: Geometric multilevel Shape -> Rectangle -> Square ---" << endl;
    Shape   s;
    Rectangle r(4, 5);
    Square   sq(6);
    s.print();
    r.print();
    sq.print();
    // protected member nahi pakdenge bahar se:
    // cout << sq.w;   // ERROR: protected

    cout << "\n--- Task 4: Account -> SavingsAccount ---" << endl;
    SavingsAccount sa(1000, 0.05);
    sa.describe();
    sa.applyInterest();
    cout << endl;
    sa.describe();

    cout << "\n--- Task 5: Multilevel protected chain A->B->C ---" << endl;
    C c(5);
    c.print();

    cout << "\n--- Task 6: FixedDeposit blocks withdrawals ---" << endl;
    FixedDeposit fd(2000, 0.06);
    fd.describe();
    fd.withdraw(500);      // blocked, balance untouched
    fd.describe();

    cout << "\n--- Edge cases ---" << endl;
    FixedDeposit bad(-500, 0.04);   // negative balance -> falls back to 0
    bad.describe();

    cout << "\n========== ALL INHERITANCE TASKS DONE ==========" << endl;
    return 0;
}