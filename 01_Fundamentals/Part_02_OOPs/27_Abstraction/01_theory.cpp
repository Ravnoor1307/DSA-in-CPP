/*
═══════════════════════════════════════════════
 ABSTRACTION
 ⏱️ TIME COMPLEXITY: O(1) per virtual call — dispatch through vtable; each pay() body is a constant number of steps.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 When you drive a car you use the steering wheel, pedals, and gear lever — you do NOT
 touch the engine internals, fuel lines, or spark plugs. The steering interface shows
 the ESSENTIAL features and hides the implementation. Same with a TV remote: the on/off
 button works no matter which manufacturer's chip is inside. In software, an ABSTRACT
 CLASS is that steering wheel — it declares WHAT operations must exist (a contract) while
 leaving HOW they work to the concrete derived classes. A payment gateway is the perfect
 example: whether the customer pays by credit card or UPI, the checkout screen simply
 says "pay()" — nobody needs to know the banking APIs behind it.

 📖 THEORY: (pure English, beginner-level)
 - ABSTRACTION = showing only the ESSENTIAL features of an object, hiding the
   implementation details behind a clean interface.
 - Achieved in C++ with PURE VIRTUAL FUNCTIONS: `virtual void pay() = 0;`
   (the `= 0` makes it pure — no body required in the base).
 - A class containing at least one pure virtual function is ABSTRACT.
 - An abstract class CANNOT be instantiated (no objects of `Payment`), it only
   defines a CONTRACT that derived classes must fulfil.
 - Every concrete derived class MUST override ALL pure virtuals or it stays abstract too.
 - This is different from ENCAPSULATION: encapsulation hides DATA (mechanism of
   protection), abstraction hides IMPLEMENTATION (design of what is exposed).

 ASCII DIAGRAM — Interface vs Implementation:
 ┌───────────────────────────────────────────────┐
 │   abstract class Payment  (the CONTRACT)       │
 │   ┌───────────────────────────────────┐        │
 │   │  virtual pay(double amount)=0     │  ◄── contract only
 │   │  virtual void receipt()=0         │  ◄── no body in base
 │   └───────────────────────────────────┘        │
 │        ▲                    ▲                  │
 │        │ implement          │ implement        │
 │        │                    │                  │
 │ ┌──────────────┐    ┌────────────────┐         │
 │ │CreditCardPay │    │   UPIPay       │         │
 │ │ pay(): ask   │    │ pay(): direct  │         │
 │ │  bank API    │    │  UPI switch    │         │
 │ └──────────────┘    └────────────────┘         │
 └───────────────────────────────────────────────┘
   main() processes both via:  Payment* p = new CreditCardPay(...); p->pay(500);

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Declare an abstract class with pure virtual methods (contract).
         WHY: The base announces which operations every payment method MUST support.
 Step 2: Derive concrete classes and override every pure virtual with real logic.
         WHY: Fulfilling the contract makes the class concrete and instantiable.
 Step 3: Use the abstract type as a POINTER/REFERENCE pointing to derived objects.
         WHY: Callers depend on the interface, not on CreditCardPay/UPIPay specifics.
 Step 4: Call the pure virtual through the abstract pointer.
         WHY: Runtime dispatch calls the correct concrete implementation.
 Step 5: Destroy through the abstract pointer using a virtual destructor.
         WHY: Correct cleanup for the real derived object.

 VISUAL WALKTHROUGH: (payment processing flow)
        Payment* p
   (abstract pointer)
        ├─► p = new CreditCardPay("4000 1234 5678 9010", card)
        │       p->pay(500)  ──►  "Processing card ....9010 ... 500 OK"
        │
        └─► p = new UPIPay("ravi@upi")
                p->pay(250)  ──►  "Sending UPI request to ravi@upi ..."

 DRY RUN: (line-by-line trace of demo)
   Payment* p = new CreditCardPay("4000 1234 5678 9010", 500);
     → CreditCardPay ctor prints "[Card] token created for 9010"
     → p->pay(500) → virtual dispatch → prints "Card 9010 paying 500 ... success"
     → p->receipt() → prints "Receipt: card 9010, 500 paid"
   p = new UPIPay("ravi@upi");
     → UPIPay ctor prints "[UPI] handle ravi@upi ready"
     → p->pay(250) → prints "UPI ravi@upi paying 250 ... success"
   delete p;  → virtual dtor → prints "[UPI] closed", then "[Payment] destroyed"
   try: Payment pmt;  → COMPILE ERROR: cannot instantiate abstract class
   (commented in source to keep file compiling)

 TIME COMPLEXITY CALCULATION:
 - Virtual call: vptr read + indirect jump = constant 2 ops → O(1)
 - CreditCardPay::pay: one mask + string ops (constant length input) = O(1)
 - UPIPay::pay: string prefix + one message print = O(1)
 - Two objects processed in sequence: 2 × O(1) = O(1); with n payments = O(n)
 → Time Complexity = O(1) per payment

 SPACE COMPLEXITY CALCULATION:
 - CreditCardPay: vptr + two strings (token, pan) = fixed size
 - UPIPay: vptr + one string = fixed size
 - Abstract base has no data members; vtable shared per class (created once)
 - No arrays, no dynamic growth
 → Space Complexity = O(1) per object

 APPROACH COMPARISON:
 ┌──────────────────────┬───────────────────────────────┬────────────────────────────────┐
 │ Aspect               │ Abstraction                   │ Encapsulation                  │
 ├──────────────────────┼───────────────────────────────┼────────────────────────────────┤
 │ Hides               │ Implementation details         │ Data / internal state          │
 │ Mechanism           │ Pure virtual functions=0       │ private + public methods       │
 │ Goal                │ Simplify interface / contract  │ Protect integrity of data      │
 │ Example             │ Payment.pay() interface        │ Thermometer.setCelsius range   │
 │ Relationship        │ "What it does"                 │ "How it is protected"          │
 └──────────────────────┴───────────────────────────────┴────────────────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

// ---------- ABSTRACT BASE (contract) ----------
class Payment {
public:
    // pure virtual — base me body nahi hoti, derived ko override karna HI padega
    virtual void pay(double amount) = 0;

    virtual void receipt() const = 0;

    // virtual dtor — abstract class must always have virtual dtor
    virtual ~Payment() {
        cout << "  [Payment] destroyed" << endl;
    }
};

// ---------- CONCRETE: CreditCardPay ----------
class CreditCardPay : public Payment {
private:
    string pan;        // credit card number (private!)
    string token;      // masked last-4 for display

public:
    CreditCardPay(string cardNumber) {
        // private internals: sirf last 4 token me store hote hain
        pan = cardNumber;
        token = cardNumber.substr(cardNumber.size() - 4, 4);
        cout << "  [Card] token created for ****" << token << endl;
    }

    // contract fulfil — card ki implementation
    void pay(double amount) override {
        cout << "  Card ****" << token << " paying " << amount << " ... success" << endl;
    }

    void receipt() const override {
        cout << "  Receipt: card ****" << token << endl;
    }

    ~CreditCardPay() override {
        cout << "  [Card] token erased" << endl;
    }
};

// ---------- CONCRETE: UPIPay ----------
class UPIPay : public Payment {
private:
    string upiId;      // e.g. ravi@okbank (private!)

public:
    UPIPay(string id) : upiId(id) {
        cout << "  [UPI] handle " << upiId << " ready" << endl;
    }

    void pay(double amount) override {
        cout << "  UPI request to " << upiId << " for " << amount << " ... success" << endl;
    }

    void receipt() const override {
        cout << "  Receipt: paid via " << upiId << endl;
    }

    ~UPIPay() override {
        cout << "  [UPI] session closed" << endl;
    }
};

int main() {
    cout << "========== ABSTRACTION DEMO: PAYMENT GATEWAY ==========" << endl << endl;

    // Abstract pointer se derived object manage karo — interface se baat karo
    cout << "--- 1) Credit Card payment via Payment* ---" << endl;
    Payment* p = new CreditCardPay("4000 1234 5678 9010");
    p->pay(500);
    p->receipt();
    delete p;
    cout << endl;

    cout << "--- 2) UPI payment via Payment* ---" << endl;
    p = new UPIPay("ravi@upi");
    p->pay(250);
    p->receipt();
    delete p;
    cout << endl;

    cout << "--- 3) Array of Payment*: uniform processing ---" << endl;
    {
        Payment* gateways[2];
        gateways[0] = new CreditCardPay("5111 1111 1111 1111");
        gateways[1] = new UPIPay("sita@upi");

        for (int i = 0; i < 2; i++) {
            gateways[i]->pay(100.0 + 50.0 * i);
        }
        for (int i = 0; i < 2; i++) {
            delete gateways[i];      // virtual dtor → correct cleanup sequence
        }
    }

    cout << "\n--- 4) Edge cases ---" << endl;
    {
        CreditCardPay c("1234 5678 9012 3456");
        c.pay(0.0);         // zero amount — valid mathematically, displays fine
        c.pay(1999.99);     // decimal precision handled by double
        UPIPay u("short@upi");
        u.pay(-5.0);        // negative amount — prints, business logic guards elsewhere
    }

    cout << "\n--- 5) Abstract class cannot be instantiated (commented) ---" << endl;
    // Payment pmt;   // COMPILE ERROR: cannot instantiate abstract class Payment
    // The comment above proves the rule — uncomment to see the error.

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}