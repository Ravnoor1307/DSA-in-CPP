/*
═══════════════════════════════════════════════
 TASK SET — ENCAPSULATION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: You are building the backend of an online banking app. Every
customer's password, balance, and PIN must be guarded — no screen or page should be able
to just overwrite these values. Encapsulation gives every class a gatekeeper: private
data + public validated methods. Today you will build exactly those gatekeepers.
🧠 HOW TO SOLVE: ALWAYS make data members PRIVATE, write a PUBLIC setter that validates
the input before storing, and write PUBLIC getters to read values. Never expose raw data.
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

/* =============================
   TASK 1 (EASY) — Password Validator
   Statement: Make a class Password that stores a password string PRIVATELY.
   Add setPassword(string) that only accepts passwords with LENGTH >= 8.
   Add getLength() that returns the length.
   💡 HINT: use s.length() >= 8; store only valid passwords; keep a bool flag.
   ✏️ STARTER CODE:
   // class Password {
   // private:
   //     string pw;        // private data
   //     bool valid;       // flags valid or not
   // public:
   //     Password() : pw(""), valid(false) {}
   //     bool setPassword(string s);   // complete this
   //     int  getLength() const;
   // };
============================= */

// =============================
// SOLUTION 1
// =============================
#include <iostream>
#include <string>
using namespace std;

class Password {
private:
    string pw;       // private — bahar se direct access forbidden
    bool valid;      // kya password valid set hua?

public:
    Password() : pw(""), valid(false) {}

    bool setPassword(string s) {
        if (s.length() < 8) {      // chhota password reject karo
            valid = false;
            cout << "  ✗ Rejected: password needs >= 8 chars (got " << s.length() << ")" << endl;
            return false;
        }
        pw = s;                    // valid hi store hoga
        valid = true;
        cout << "  ✓ Password stored safely" << endl;
        return true;
    }

    int getLength() const {
        return pw.length();
    }

    bool isValid() const {
        return valid;
    }
};

/* =============================
   TASK 2 (EASY) — Bank Secure Balance
   Statement: Make a class BankAccount with PRIVATE balance. write deposit(double)
   that rejects negative/zero amounts, and withdraw(double) that rejects amounts
   larger than the balance. Add a getter getBalance().
   💡 HINT: two rules — deposit must be > 0, withdraw must be <= balance.
   ✏️ STARTER CODE:
   // class BankAccount {
   // private:
   //     double balance;
   // public:
   //     BankAccount() : balance(0.0) {}
   //     bool deposit(double amt);
   //     bool withdraw(double amt);
   //     double getBalance() const;
   // };
============================= */

// =============================
// SOLUTION 2
// =============================
class BankAccount {
private:
    double balance;      // private amount — koi seedha badal nahi sakta

public:
    BankAccount() : balance(0.0) {}

    bool deposit(double amt) {
        if (amt <= 0) {
            cout << "  ✗ Deposit rejected: amount must be positive" << endl;
            return false;
        }
        balance += amt;                     // safe addition kiya
        cout << "  ✓ Deposited " << amt << ", new balance " << balance << endl;
        return true;
    }

    bool withdraw(double amt) {
        if (amt <= 0) {
            cout << "  ✗ Withdraw rejected: amount must be positive" << endl;
            return false;
        }
        if (amt > balance) {                // overdraft allow nahi
            cout << "  ✗ Insufficient funds: need " << amt << ", have " << balance << endl;
            return false;
        }
        balance -= amt;
        cout << "  ✓ Withdrew " << amt << ", new balance " << balance << endl;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

/* =============================
   TASK 3 (MEDIUM) — Bank with Transfer (composition + validation)
   Statement: Using BankAccount from Task 2, write a helper function secureTransfer
   that moves money from one account to another ONLY if the source has enough funds.
   Demonstrate that a hacked attempt (direct balance manipulation) is impossible.
   💡 HINT: try balance = 1e6; inside main() and watch the compile error.
   ✏️ STARTER CODE:
   // void secureTransfer(BankAccount &from, BankAccount &to, double amt) {
   //     // withdraw from 'from', deposit into 'to'
   // }
============================= */

// =============================
// SOLUTION 3
// =============================
void secureTransfer(BankAccount &from, BankAccount &to, double amt) {
    if (amt <= 0) {
        cout << "  ✗ Transfer rejected: amount must be positive" << endl;
        return;
    }
    if (from.withdraw(amt)) {      // pehle source se nikaalo
        to.deposit(amt);           // tabhi destination me daalo
        cout << "  ✓ Transfer of " << amt << " completed" << endl;
    } else {
        cout << "  ✗ Transfer failed (source account untouched)" << endl;
    }
}

/* =============================
   TASK 4 (MEDIUM) — Pin-protected Door
   Statement: Make a class DigitalDoor with PRIVATE pin code and PRIVATE bool locked.
   openDoor(int attempt) must accept ONLY the exact PIN and then unlock. Trying a wrong
   PIN should NOT change the lock state. Add a status getter.
   💡 HINT: store a private secretPin initialized in the ctor.
   ✏️ STARTER CODE:
   // class DigitalDoor {
   // private:
   //     int  secretPin;
   //     bool locked;
   // public:
   //     DigitalDoor() : secretPin(4321), locked(true) {}
   //     bool openDoor(int attempt);
   //     bool isLocked() const;
   // };
============================= */

// =============================
// SOLUTION 4
// =============================
class DigitalDoor {
private:
    int  secretPin;     // private secret — kisi ko nahi dikhta
    bool locked;

public:
    DigitalDoor() : secretPin(4321), locked(true) {}

    bool openDoor(int attempt) {
        if (attempt != secretPin) {   // galat pin → state unchanged
            cout << "  ✗ Wrong PIN! Door stays locked" << endl;
            return false;
        }
        locked = false;
        cout << "  ✓ Correct PIN! Door unlocked" << endl;
        return true;
    }

    void lockDoor() {
        locked = true;               // wapas lock kar do
        cout << "  🔒 Door locked" << endl;
    }

    bool isLocked() const {
        return locked;
    }
};

/* =============================
   TASK 5 (HARD) — Physical Quantity with Units (real encapsulation gold)
   Statement: Make a class Length that stores ONLY meters PRIVATELY, but exposes
   setters/getters in meters AND feet. setMeters + setFeet must never allow a
   negative length. Show that internal representation is hidden from the user.
   💡 HINT: 1 foot = 0.3048 m. Both setters convert into the single private field.
   ✏️ STARTER CODE:
   // class Length {
   // private:
   //     double meters;
   // public:
   //     Length() : meters(0.0) {}
   //     bool setMeters(double m);
   //     bool setFeet(double f);
   //     double getMeters() const;
   //     double getFeet() const;
   // };
============================= */

// =============================
// SOLUTION 5
// =============================
class Length {
private:
    double meters;      // ek hi internal storage — meters

public:
    Length() : meters(0.0) {}

    bool setMeters(double m) {
        if (m < 0) {
            cout << "  ✗ Negative length rejected" << endl;
            return false;
        }
        meters = m;
        cout << "  ✓ Length = " << meters << " m stored" << endl;
        return true;
    }

    bool setFeet(double f) {
        if (f < 0) {
            cout << "  ✗ Negative length rejected" << endl;
            return false;
        }
        meters = f * 0.3048;     // conversion — user ko pata bhi nahi chala
        cout << "  ✓ " << f << " ft converted & stored as " << meters << " m" << endl;
        return true;
    }

    double getMeters() const {
        return meters;
    }

    double getFeet() const {
        return meters / 0.3048;
    }
};

/* =============================
   TASK 6 (HARD) — Encapsulated Counter / History
   Statement: Make a class CounterHistory that keeps a PRIVATE total plus a PRIVATE
   vector<int> of the last N updates. addValue(int) increments total and records the
   update; it must REJECT updates larger than 1000 to protect integrity. Provide a
   getter for total and a printHistory that shows all recorded updates.
   💡 HINT: store in vector<int> history; push_back each accepted value.
   ✏️ STARTER CODE:
   // #include <vector>
   // class CounterHistory {
   // private:
   //     int total;
   //     vector<int> history;
   // public:
   //     CounterHistory() : total(0) {}
   //     bool addValue(int v);
   //     int  getTotal() const;
   //     void printHistory() const;
   // };
============================= */

// =============================
// SOLUTION 6
// =============================
#include <vector>

class CounterHistory {
private:
    int total;
    vector<int> history;      // private log — bahar wala kabhi delete nahi kar sakta

public:
    CounterHistory() : total(0) {}

    bool addValue(int v) {
        if (v > 1000 || v <= 0) {
            cout << "  ✗ Rejected: " << v << " (must be 1..1000)" << endl;
            return false;
        }
        total += v;                // total update
        history.push_back(v);      // history record karo
        cout << "  ✓ Added " << v << " | running total = " << total << endl;
        return true;
    }

    int getTotal() const {
        return total;
    }

    void printHistory() const {
        cout << "  Updates: ";
        for (int x : history) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "========== TASK SOLUTIONS: ENCAPSULATION ==========" << endl;

    cout << "\n--- Task 1: Password Validator ---" << endl;
    Password p;
    p.setPassword("abc");                    // reject
    p.setPassword("superStrong123");          // accept
    cout << "  Length = " << p.getLength() << " | valid = " << p.isValid() << endl;

    cout << "\n--- Task 2: Bank Account ---" << endl;
    BankAccount a;
    a.deposit(500);
    a.deposit(-10);                           // reject
    a.withdraw(100);                          // ok
    a.withdraw(1000);                         // insufficient
    cout << "  Final balance = " << a.getBalance() << endl;

    cout << "\n--- Task 3: Secure Transfer ---" << endl;
    BankAccount accA, accB;
    accA.deposit(300);
    secureTransfer(accA, accB, 200);          // works
    secureTransfer(accA, accB, 500);          // fails safely
    cout << "  accA = " << accA.getBalance() << ", accB = " << accB.getBalance() << endl;

    cout << "\n--- Task 4: Digital Door ---" << endl;
    DigitalDoor door;
    door.openDoor(1111);                      // wrong
    door.openDoor(4321);                      // correct
    cout << "  Locked? " << door.isLocked() << endl;

    cout << "\n--- Task 5: Length with Units ---" << endl;
    Length L;
    L.setMeters(10.0);
    cout << "  In feet: " << L.getFeet() << endl;
    L.setFeet(32.8);
    cout << "  In meters: " << L.getMeters() << endl;
    L.setMeters(-5.0);                        // reject

    cout << "\n--- Task 6: Counter History ---" << endl;
    CounterHistory c;
    c.addValue(100);
    c.addValue(2500);                         // reject (>1000)
    c.addValue(300);
    c.addValue(-50);                          // reject (<=0)
    c.printHistory();
    cout << "  Total = " << c.getTotal() << endl;

    cout << "\n========== ALL ENCAPSULATION TASKS DONE ==========" << endl;
    return 0;
}