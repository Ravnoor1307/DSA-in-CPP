/*
═══════════════════════════════════════════════
 ACCESS MODIFIERS — public, private, protected
 ⏱️ TIME COMPLEXITY: O(1) per method call — see derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a big bank branch. The CASH VAULT in the basement is PRIVATE —
 only the banker who owns the vault key can go inside; customers see only
 the deposit slip window. The STAFF ROOM is PROTECTED — employees of this
 branch and of the parent bank may enter, but a random street customer
 cannot. The CUSTOMER HALL is PUBLIC — anybody can walk in. That is exactly
 public / private / protected in C++.

 📖 THEORY: (pure English, beginner-level)
 - public:     accessible from ANYWHERE — inside the class, outside the
               class (main), and inside derived classes.
 - private:    accessible ONLY inside the same class. Neither outside code
               nor derived classes can touch it. The most sensitive data
               lives here.
 - protected:  accessible inside the same class AND inside derived classes.
               Outside code still cannot touch it.
 - GETTER / SETTER pattern: expose private data safely through public
   methods — `int getSalary() const;` and
   `void setSalary(int s) { if (s < 0) s = 0; ... }`.
 - DATA HIDING: private members + guarded public doors = you can VALIDATE
   every write (no negative salary, no over-withdrawal) and still give a
   clean read-only view to the outside world.

  WHO CAN ACCESS WHAT? (access table)
   ┌────────────┬──────────────┬──────────────┬──────────────┐
   │ keyword    │ class itself │ derived class│ outside code │
   ├────────────┼──────────────┼──────────────┼──────────────┤
   │ public     │     ✅      │     ✅      │     ✅      │
   │ protected  │     ✅      │     ✅      │     ❌      │
   │ private    │     ✅      │     ❌      │     ❌      │
   └────────────┴──────────────┴──────────────┴──────────────┘

   BANK LAYOUT AS ACCESS LEVELS
   ┌────────────────────────────────────────────┐
   │  CUSTOMER HALL          (PUBLIC)           │
   │    deposit() withdraw() getBalance()       │
   ├────────────────────────────────────────────┤
   │  STAFF ROOM             (PROTECTED)        │
   │    branchCode   (only the branch and its      │
   │                  child classes may access)   │
   ├────────────────────────────────────────────┤
   │  CASH VAULT            (PRIVATE)           │
   │    balance                   ╔═══════╗     │
   │    realCashBox               ║  $$$  ║     │
   │    randomBanknotes           ╚═══════╝     │
   └────────────────────────────────────────────┘

 WHEN TO USE:
 - private   → sensitive state that MUST be validated: balance, password, id.
 - protected → a value the base class wants to hand to its CHILDREN only.
 - public    → the polished safe interface: deposit(), withdraw(), getter.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Decide what is SECRET → in Account, `double balance;` is the crown
   jewel, so mark it private. WHY: nobody must touch money directly.
 Step 2: Build PUBLIC doors → deposit(), withdraw(), getBalance(). WHY:
   every operation now passes through code that can validate.
 Step 3: Validate inside the door → reject non-positive amounts and
   over-withdrawals politely. WHY: data hiding pays off only when writes
   are guarded.
 Step 4: Use protected for the semi-secret → `branchCode` is visible to the
   SavingsAccount (derived) class but not to main(). WHY: derived classes
   are trusted family; strangers are not.
 Step 5: Expose a read-only view via getter → return a COPY of balance. WHY:
   the caller can SEE the value but can never reassign it.

 VISUAL WALKTHROUGH:
   main()
     │ a.deposit(500)      ──────▶  public method (VALIDATED) ┐
     │ a.getBalance()      ──────▶  public getter             │
     │ a.balance = 1;      ✖ COMPILE ERROR (private) ◀────────┘
     │ s.branchCode = "X"  ✖ COMPILE ERROR (protected)
     │                                                        ▼
     │                                    ┌────────────────────────┐
     │ SavingsAccount::showBranch()       │ private:  balance   ★ │
     │ (derived class = trusted family) ─▶│ protected: branch    │
     │                                    └────────────────────────┘

 DRY RUN: (trace of the demo below, printed values shown)
   Account a(1000);             → balance = 1000
   a.deposit(500);              → 500 > 0 ✅ → balance = 1500
   a.withdraw(200);             → 200 <= 1500 ✅ → balance = 1300
   cout << a.getBalance();      → prints 1300
   SavingsAccount s(500);       → base ctor runs → balance=500, branch="DEL-01"
   s.deposit(100);              → balance = 600
   s.showBranch();              → prints "Branch code: DEL-01"
   a.deposit(-50);              → rejected (negative) — balance stays 1300
   a.withdraw(-1);              → rejected (negative)
   a.withdraw(999999);          → rejected (insufficient funds)

 TIME COMPLEXITY CALCULATION:
 - deposit(): 1 comparison + 1 addition         → 2 ops, constant.
 - withdraw(): 2 comparisons (worst case) + 1 subtraction → constant.
 - getBalance(): 1 read                          → constant.
 - No loops; method count is fixed no matter how many objects exist.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - sizeof(Account) = sizeof(double balance) + sizeof(string branch) + padding.
 - n objects → n × sizeof(Account) → memory grows linearly with object count.
 - Methods share a single code-segment copy and cost no extra per object.
 → Space Complexity = O(1) per object

 APPROACH COMPARISON: (ways of exposing data)
 ┌──────────────┬────────────────┬────────────────┬──────────────────────┐
 │ approach     │ outside access │ validation     │ use case             │
 ├──────────────┼────────────────┼────────────────┼──────────────────────┤
 │ public data  │ direct write   │ NONE           │ simple struct DTOs    │
 │ private+setter│through setter │ ✅ possible    │ salary, balance, pin  │
 │ private+getter│read-only copy │ ✅ possible    │ read-only reports     │
 │ protected    │ only derived   │ in derived     │ family-shared state   │
 └──────────────┴────────────────┴────────────────┴──────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    double balance;          // PRIVATE — vault samjho, bahar se koi na chhu sakta

protected:
    string branchCode;       // PROTECTED — derived classes (family) access kar sakti hain

public:
    Account(double initial) {
        balance = (initial < 0) ? 0 : initial;   // edge case: negative initial balance reject
    }

    void deposit(double amt) {
        if (amt <= 0) {                           // edge case: negative / zero amount
            cout << "  Rejected: deposit amount must be > 0\n";
            return;
        }
        balance += amt;
        cout << "  Deposited " << amt << " -> new balance " << balance << "\n";
    }

    bool withdraw(double amt) {
        if (amt <= 0) {                           // edge case: negative / zero amount
            cout << "  Rejected: withdraw amount must be > 0\n";
            return false;
        }
        if (amt > balance) {                      // edge case: over-withdrawal
            cout << "  Insufficient balance!\n";
            return false;
        }
        balance -= amt;
        cout << "  Withdrew " << amt << " -> new balance " << balance << "\n";
        return true;
    }

    double getBalance() const {   // getter — read-only safe view (copy return hota hai)
        return balance;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double init) : Account(init) {
        branchCode = "DEL-01";    // protected member → derived class me access OK
    }

    void showBranch() {
        cout << "  Branch code: " << branchCode << "\n";
    }
};

int main() {
    cout << "=== Account: private vault + public safe doors ===\n";
    Account a(1000);
    a.deposit(500);
    a.withdraw(200);
    cout << "  Balance via getter: " << a.getBalance() << "\n";

    // ⚠️ COMPILE-ERROR examples (code me daalne par compiler turant galti batayega):
    //   a.balance = 9999;        // ERROR: 'balance' is private within this context
    //   a.branchCode = "NX-9";   // ERROR: 'branchCode' is protected

    cout << "\n=== Protected member via inheritance (SavingsAccount) ===\n";
    SavingsAccount s(500);
    s.deposit(100);               // public method — inherited, usable outside
    s.showBranch();               // protected data ko derived class ke andar read kiya

    cout << "\n=== Edge cases: negative amounts rejected ===\n";
    a.deposit(-50);               // rejected
    a.withdraw(-1);               // rejected
    a.withdraw(999999);           // insufficient funds
    return 0;
}