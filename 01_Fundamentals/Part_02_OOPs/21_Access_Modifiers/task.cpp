/*
═══════════════════════════════════════════════
 TASK SET — ACCESS MODIFIERS (public/private/protected)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A bank's cash vault is private (only the banker touches it), the staff
 room is protected (only employees of the branch and its child branches
 may enter), and the customer hall is public (everyone walks in). You build
 the same three layers in every class: private data, protected values for
 children, and a public safe interface of getters/setters.

 🧠 HOW TO SOLVE:
 1) Sensitive data (salary, balance, pin) ko private rakho.
 2) Har write-guard ke liye public setter banao jo validate kare.
 3) Read-only view ke liye public getter banao.
 4) Jo value sirf family (derived classes) ko chahiye, use protected rakho.
 5) main() me rakha data directly kabhi mat chhedo — compile error aayega.

 TASKS (EASY → HARD):

 TASK 1 — EMPLOYEE salary via getter/setter (EASY)
 class Employee: private name + salary. Public setName()/setSalary() and
 getName()/getSalary(). Negative salary rejects — set to 0.
 💡 HINT: setter ke andar validation — salary < 0 ho to 0 kar do.
 ✏️ STARTER CODE:
 // class Employee {
 //   private: string name; double salary;
 //   public:
 //     void setName(string n);
 //     void setSalary(double s);      // negative → 0
 //     string getName() const;
 //     double getSalary() const;
 // };

 TASK 2 — public vs private ka fark (EASY)
 Make struct OpenBox { int code; }; and class SecretBox with private code.
 Set OpenBox.code directly (OK), then try SecretBox.code directly — show in
 a comment that it is a COMPILE ERROR, and use a setter/getter instead.
 💡 HINT: struct = public by default, class = private by default.
 ✏️ STARTER CODE:
 // struct OpenBox { int code; };
 // class  SecretBox { int code; public: void setCode(int c); int getCode() const; };
 // main: OpenBox o; o.code = 7;          // ✅
 //       // SecretBox s; s.code = 7;     // ❌ compile error

 TASK 3 — BankAccount with validation (MEDIUM)
 class BankAccount: private double balance. deposit() / withdraw() that
 REJECT negative or zero amounts and over-withdrawals. Print success/fail.
 💡 HINT: har method ki shuruaat me `if (amt <= 0)` check lagao.
 ✏️ STARTER CODE:
 // class BankAccount {
 //   private: double balance;
 //   public:
 //     bool deposit(double amt);   // <= 0 reject
 //     bool withdraw(double amt);  // <= 0 ya overdraw reject
 //     double getBalance() const;
 // };

 TASK 4 — protected + inheritance (MEDIUM)
 class Meter with protected int reading. class DigitalMeter : public Meter —
 inside it match(int guess) compares guess with reading (protected access
 from derived is allowed). main() me dolphin batao ki reading direct access
 nahi ho sakta.
 💡 HINT: protected sirf derived class ke METHODS ke andar dikhta hai.
 ✏️ STARTER CODE:
 // class Meter {
 //   protected: int reading = 0;
 //   public: void addReading(int r) { reading += r; }
 // };
 // class DigitalMeter : public Meter {
 //   public: bool isHigh() { return reading > 100; }
 // };

 TASK 5 — friend function private member ko dekh saki hai (HARD)
 class Ledger: private int entries. Add records via add(). Declare a friend
 function countEntries() that reads entries directly. Normal (non-friend)
 free function ko private access NAHI milega.
 💡 HINT: friend declaration class ke andar likhi jati hai, aur function
    class ke bahar define hota hai.
 ✏️ STARTER CODE:
 // class Ledger {
 //   private: int entries = 0;
 //   public: void add() { entries++; }
 //   friend int countEntries(const Ledger& L);
 // };
 // int countEntries(const Ledger& L) { return L.entries; }

 TASK 6 — SecureVault: full data hiding (HARD)
 class SecureVault: private string secret + attempts counter. Public method
 open(pwd) returns the secret only for correct password, else "Wrong
 password", and after 3 wrong tries returns "LOCKED". Validate everything.
 💡 HINT: private helper unlock() + public gate open() — data hiding ka
    complete pattern.
 ✏️ STARTER CODE:
 // class SecureVault {
 //   private:
 //     string secret = "gold-bars";
 //     int failed = 0;
 //     bool unlock(string pwd) { return pwd == "open-sesame"; }
 //   public:
 //     string open(string pwd);   // 3 galat try → LOCKED
 // };
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <string>
using namespace std;

// ============ TASK 1 SOLUTION — Employee getter/setter ============
class Employee {
private:
    string name;
    double salary;             // sensitive → private

public:
    void setName(string n) { name = n; }
    void setSalary(double s) {
        if (s < 0) s = 0;      // edge case: negative salary → 0
        salary = s;
    }
    string getName() const { return name; }      // getter — read-only
    double getSalary() const { return salary; }  // getter — read-only
};

void runTask1() {
    Employee e;
    e.setName("Kavya");
    e.setSalary(45000);
    e.setSalary(-5000);        // negative → 0 rakh diya
    cout << "Task1 : " << e.getName() << " salary = Rs." << e.getSalary() << "\n";
}

// ============ TASK 2 SOLUTION — public vs private ============
struct OpenBox { int code; };                    // sab public

class SecretBox {
private:
    int code;                                    // private — bahar se direct NO
public:
    void setCode(int c) { code = c; }            // safe public door
    int getCode() const { return code; }
};

void runTask2() {
    OpenBox o;
    o.code = 7;                                  // ✅ struct — direct chalega
    cout << "Task2 : OpenBox.code = " << o.code << "\n";

    // SecretBox s; s.code = 7;   // ❌ COMPILE ERROR: 'code' is private
    // uncomment karke try karo — compiler takra jayega.

    SecretBox s;
    s.setCode(999);                              // ✅ setter se sahi raasta
    cout << "        SecretBox via setter = " << s.getCode() << "\n";
}

// ============ TASK 3 SOLUTION — BankAccount validation ============
class BankAccount {
private:
    double balance = 0;

public:
    bool deposit(double amt) {
        if (amt <= 0) {                          // edge case: 0/negative
            cout << "        (rejected: deposit must be > 0)\n";
            return false;
        }
        balance += amt;
        return true;
    }
    bool withdraw(double amt) {
        if (amt <= 0) {                          // edge case: 0/negative
            cout << "        (rejected: withdrawal must be > 0)\n";
            return false;
        }
        if (amt > balance) {                     // edge case: overdraw
            cout << "        (rejected: insufficient funds)\n";
            return false;
        }
        balance -= amt;
        return true;
    }
    double getBalance() const { return balance; }
};

void runTask3() {
    BankAccount b;
    b.deposit(1000);
    cout << "Task3 : deposit 1000  -> balance " << b.getBalance() << "\n";
    cout << "        deposit -40   -> " << (b.deposit(-40) ? "ok" : "no") << "\n";
    cout << "        withdraw 9999 -> " << (b.withdraw(9999) ? "ok" : "no") << "\n";
    cout << "        final balance = " << b.getBalance() << "\n";
}

// ============ TASK 4 SOLUTION — protected + inheritance ============
class Meter {
protected:
    int reading = 0;             // protected → sirf derived family ke liye

public:
    void addReading(int r) { reading += r; }
};

class DigitalMeter : public Meter {
public:
    bool isHigh() {
        return reading > 100;    // protected access → derived me ALLOWED
    }
};

void runTask4() {
    DigitalMeter dm;
    dm.addReading(30);
    dm.addReading(90);           // reading = 120
    cout << "Task4 : reading 120 → isHigh = " << (dm.isHigh() ? "true" : "false")
         << "\n";
    // dm.reading = 5;  // ❌ COMPILE ERROR: 'reading' is protected —
    // main() = stranger hai, protected sirf derived class ke methods me dikhta hai.
}

// ============ TASK 5 SOLUTION — friend function ============
class Ledger {
private:
    int entries = 0;

public:
    void add() { entries++; }
    // friend → ye free function is class ke private members ko dekh sakti hai
    friend int countEntries(const Ledger& L);
};

int countEntries(const Ledger& L) {        // class ke bahar define — friend hai isliye allowed
    return L.entries;                       // private member direct padha — sirf friend can
}

void runTask5() {
    Ledger L;
    L.add();
    L.add();
    L.add();                             // 3 records
    cout << "Task5 : entries (friend read) = " << countEntries(L) << "\n";
}

// ============ TASK 6 SOLUTION — SecureVault data hiding ============
class SecureVault {
private:
    string secret = "gold-bars";
    int failed = 0;                       // galat try counter — private

    bool unlock(string pwd) {             // private helper — bahar se na dikhe
        return pwd == "open-sesame";
    }

public:
    string open(string pwd) {
        if (unlock(pwd)) {
            failed = 0;                   // sahi password → counter reset
            return secret;
        }
        failed++;
        if (failed >= 3) return "LOCKED — too many wrong attempts";
        return "Wrong password";
    }
};

void runTask6() {
    SecureVault v;
    cout << "Task6 : " << v.open("hello")   << "\n";
    cout << "        " << v.open("test")    << "\n";
    cout << "        " << v.open("hack")    << "\n";   // 3rd fail → LOCKED
    cout << "        " << v.open("open-sesame") << "  (sahi password bhi ab band)\n";
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