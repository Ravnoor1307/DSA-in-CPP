/*
═══════════════════════════════════════════════
 TASK SET — STATIC MEMBERS & this POINTER
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: An HR system tracks how many employees are
    currently working across all branches. Every new hire increments a
    shared counter, and every resignation decrements it. Meanwhile, when
    an employee updates their own profile, the system must know they are
    editing THEIR OWN record — that is the this pointer at work.

 🧠 HOW TO SOLVE: Static data member: declare `static int x;` inside the
    class, define it OUTSIDE. Static member function: declare
    `static returnType fun();`, call via ClassName::fun(). this pointer:
    use `this->member` when the parameter hides the member name. Method
    chaining: setters return `*this` (a reference to the current object).
    const member functions: append `const` after the parameter list to
    promise no mutation.

 MODES/TOPICS COVERED:
  1. Object counter with a static total
  2. Shared company config (static data members)
  3. Name shadowing resolved with this->
  4. Method chaining (setters return *this)
  5. Ticket IDs via static nextId + const isValid
  6. Full method-chaining bank account
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <string>
using namespace std;

// ═══════════════════════════════════════════════════════════
// SOLUTION 1 — Object Counter
// ═══════════════════════════════════════════════════════════
class Counter {
private:
    static int total;   // ye 3 objects me share hoga, har object ki copy nahi
public:
    Counter() {
        total++;  // naya object bana → total badha
    }
    ~Counter() {
        total--;  // object destroyed → total ghata
    }
    static int getTotal() {
        return total;  // static function sirf static member access kar sakti hai
    }
};
int Counter::total = 0;  // static member ko class ke bahar define KARNA ZAROORI hai

void solveTask1() {
    cout << "\n=== SOLUTION 1: Object Counter ===" << endl;
    Counter c1, c2, c3;  // 3 objects → total = 3
    cout << "Total counters after creating 3: " << Counter::getTotal() << endl;
    // Expected: 3

    {
        Counter c4;  // inner scope → total = 4
        cout << "Inside scope (4th counter): " << Counter::getTotal() << endl;
    }  // c4 destroyed → total = 3
    cout << "After c4 destroyed: " << Counter::getTotal() << endl;
    // Expected: 3
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 2 — Shared Company Config
// ═══════════════════════════════════════════════════════════
class Employee {
private:
    static string company;  // sab employees ke liye ek hi company
    static double bonus;    // sab ke liye same bonus (shared)
    string name;            // har employee ki apni name (instance)

public:
    Employee(string n) : name(n) {}  // constructor using initializer list

    static void setBonus(double b) {
        bonus = b;  // static function static member ko modify karti hai
    }

    static void showConfig() {
        cout << "Company: " << company << ", Bonus: " << bonus << "%" << endl;
    }
};
string Employee::company = "TechNova";  // bahar define — static segment me memory
double Employee::bonus = 5.0;

void solveTask2() {
    cout << "\n=== SOLUTION 2: Shared Company Config ===" << endl;
    Employee e1("Ravi"), e2("Priya");
    cout << "Before change:" << endl;
    Employee::showConfig();            // sabko 5% dikh raha hai
    e1.setBonus(10.0);                 // sirf e1 ne bonus badala
    cout << "After e1 changes bonus (e2 bhi dikhega):" << endl;
    Employee::showConfig();            // e2 bhi 10% dikhega — PROOF of sharing
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 3 — Name Shadowing with this->
// ═══════════════════════════════════════════════════════════
class Account {
private:
    string owner;
    int balance;
public:
    Account(string owner, int balance) {
        this->owner = owner;      // this->owner = MEMBER, owner = parameter
        this->balance = balance;  // shadowing yaha bhi solve hua
    }
    void setOwner(string owner) {
        this->owner = owner;  // BINA this-> ke: owner = owner (khud ko hi assign)
    }
    void print() const {
        cout << "Owner: " << owner << ", Balance: Rs." << balance << endl;
    }
};

void solveTask3() {
    cout << "\n=== SOLUTION 3: Name Shadowing with this-> ===" << endl;
    Account acc("Madhur", 5000);
    acc.print();
    acc.setOwner("Madhur Kumar");  // same name member + parameter
    acc.print();
    // Expected: owner becomes "Madhur Kumar" — this-> ne fix kiya
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 4 — Method Chaining
// ═══════════════════════════════════════════════════════════
class Product {
private:
    string name;
    int price;
    int rating;   // extra field for extended chain
public:
    Product() : rating(0) {}

    Product& setName(string n) {
        name = n;
        return *this;  // return reference to CURRENT object → chain aage badhta hai
    }
    Product& setPrice(int p) {
        price = p;
        return *this;
    }
    Product& setRating(int r) {
        rating = r;
        return *this;   // extended chain ka hissa
    }
    void print() const {
        cout << "Product: " << name << ", Rs." << price
             << ", Rating: " << rating << "/5" << endl;
    }
};

void solveTask4() {
    cout << "\n=== SOLUTION 4: Method Chaining ===" << endl;
    Product p;
    p.setName("Laptop").setPrice(55000).setRating(4).print();
    // chain me 4 calls → har ek ne *this return kiya → sab ek hi object par
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 5 — Ticket IDs (static nextId + const isValid)
// ═══════════════════════════════════════════════════════════
class Ticket {
private:
    static int nextId;  // agle ticket ko kaunsa id milega — shared counter
    int id;             // har ticket ki apni id
public:
    Ticket() {
        this->id = nextId;   // current value assign karo
        nextId++;            // phir next ke liye increment
    }
    static int sold() {
        return nextId;  // kitne tickets allot hue? (static function)
    }
    bool isValid() const {   // const — object modify nahi karegi
        return (id % 2 == 0);  // even id = valid (fun rule)
    }
    int getID() const { return id; }
};
int Ticket::nextId = 1000;   // IDs 1000 se start

void solveTask5() {
    cout << "\n=== SOLUTION 5: Ticket IDs ===" << endl;
    Ticket tickets[6];  // 6 tickets → IDs: 1000,1001,...,1005
    cout << "Tickets sold so far: " << Ticket::sold() << endl;

    for (int i = 0; i < 6; i++) {
        cout << "Ticket #" << tickets[i].getID()
             << (tickets[i].isValid() ? " ✅ VALID" : " ❌ INVALID")
             << endl;
    }
    // Even IDs (1000,1002,1004) valid, odd IDs invalid
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 6 — Full Method-Chaining BankAccount
// ═══════════════════════════════════════════════════════════
class BankAccount {
private:
    double balance;
    string owner;
public:
    BankAccount(string owner, double balance) {
        this->owner = owner;
        this->balance = balance;
    }

    BankAccount& deposit(double amt) {
        balance += amt;  // money add karo
        cout << "  ₹" << amt << " deposited. Balance: Rs." << balance << endl;
        return *this;    // chain continue
    }

    BankAccount& withdraw(double amt) {
        if (amt <= balance) {          // EDGE CASE: over-withdrawal guard
            balance -= amt;
            cout << "  ₹" << amt << " withdrawn. Balance: Rs." << balance << endl;
        } else {
            cout << "  ❌ Insufficient funds! Tried ₹" << amt
                 << " but have Rs." << balance << endl;
            // balance unchanged — negative hone se bachaya
        }
        return *this;  // dono paths me *this return karo
    }

    void print() const {  // const — sirf read karta hai
        cout << "  " << owner << ": Balance = Rs." << balance << endl;
    }
};

void solveTask6() {
    cout << "\n=== SOLUTION 6: Method-Chaining BankAccount ===" << endl;
    BankAccount a("Shreya", 10000);

    cout << "Initial:" << endl;
    a.print();

    cout << "Chain: deposit(5000).withdraw(2000).deposit(300)" << endl;
    a.deposit(5000).withdraw(2000).deposit(300).print();

    cout << "Edge case — withdraw more than balance:" << endl;
    a.withdraw(999999).print();
    // Expected: refusal message, balance unchanged (Rs.13300)
}

int main() {
    cout << "═══════════════════════════════════════" << endl;
    cout << " TASK SOLUTIONS — STATIC & this POINTER" << endl;
    cout << "═══════════════════════════════════════" << endl;

    solveTask1();   // Object Counter
    solveTask2();   // Shared Company Config
    solveTask3();   // this-> shadowing
    solveTask4();   // Method chaining
    solveTask5();   // Ticket IDs
    solveTask6();   // BankAccount chaining

    return 0;
}