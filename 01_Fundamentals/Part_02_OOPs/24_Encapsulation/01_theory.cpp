/*
═══════════════════════════════════════════════
 ENCAPSULATION
 ⏱️ TIME COMPLEXITY: O(1) per method call — every operation is a fixed number of comparisons and assignments; no loops, no scaling with input size.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine walking up to an ATM machine. You see a screen, a keypad, and a card slot —
 that is the PUBLIC interface. You press buttons to withdraw cash, check your balance,
 or transfer money. But you never get direct access to the bank's internal vault, the
 database of account numbers, or the network that talks to the bank's servers. Those
 are PRIVATE internals. The ATM validates your PIN, checks your balance before
 dispensing cash, and logs every transaction. If the bank changes its internal database
 software, your ATM experience stays exactly the same — because the buttons (interface)
 didn't change. That is encapsulation: bundle data + methods, hide the internals, and
 expose only a safe, controlled interface.

 📖 THEORY: (pure English, beginner-level)
 - Encapsulation is the OOP principle of BUNDLING data (variables) and the methods
   (functions) that operate on that data into a single unit called a CLASS.
 - It also means HIDING the internal state of an object by marking data members PRIVATE.
 - Access to private data is provided ONLY through PUBLIC methods (getters/setters).
 - This protects data integrity — the class validates every change before allowing it.
 - It makes maintenance easy — you can change the internal implementation without
   breaking any external code that uses the class.

 ASCII DIAGRAM — Encapsulated Thermometer:
 ┌───────────────────────────────────────┐
 │         class Thermometer             │
 │  ┌─────────────────────────────────┐  │
 │  │  PRIVATE (hidden internals)     │  │
 │  │   - celsius : double            │  │
 │  │   - MIN_TEMP : const double      │  │
 │  │   - MAX_TEMP : const double      │  │
 │  └─────────────────────────────────┘  │
 │  ┌─────────────────────────────────┐  │
 │  │  PUBLIC (controlled interface)  │  │
 │  │   + Thermometer()               │  │
 │  │   + setCelsius(double) : bool   │  │
 │  │   + getCelsius() : double       │  │
 │  │   + getFahrenheit() : double    │  │
 │  │   + display()                   │  │
 │  └─────────────────────────────────┘  │
 │         ▲                             │
 │         │ only via public methods     │
 │       (MAIN / USERS)                 │
 └───────────────────────────────────────┘

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Declare data members as PRIVATE.
         WHY: No code outside the class can touch them directly, so invalid values
         can never sneak in through an unguarded assignment.
 Step 2: Provide PUBLIC methods (getters/setters) to interact with the data.
         WHY: These methods become gatekeepers that control exactly how a user can
         read or modify the internal state.
 Step 3: In the setter, VALIDATE the incoming value before storing it.
         WHY: Rejecting bad input at the class boundary keeps the object always
         consistent and bug-free.
 Step 4: In getters, return a computed (or stored) value.
         WHY: Callers get the information they need without knowing how it is stored.

 VISUAL WALKTHROUGH: (construction + access flow)
 main()                     Thermometer
 ──────                     ───────────
 Thermometer t;      ──►   celsius = 0.0   (default)
 t.setCelsius(25);   ──►   check -40 ≤ 25 ≤ 60 ?  YES  →  celsius = 25   ✓
 t.setCelsius(100);  ──►   check -40 ≤ 100 ≤ 60 ?  NO   →  rejected       ✗
 t.getFahrenheit();  ──►   return 25*9/5 + 32 = 77
 t.celsius = 999;    ──►   COMPILE ERROR — private!

 DRY RUN: (line-by-line trace of the demo)
 Thermometer t;                    // ctor prints "[CTOR] ... 0°C", celsius = 0.0
 SET 25.0  → 25.0≥-40 AND ≤60  → true → celsius=25.0 → prints "✓ Set to 25°C"
 SET -40.0 → -40.0≥-40 AND ≤60 → true → celsius=-40.0 → "✓ Set to -40°C"
 SET 60.0  → 60.0≥-40 AND ≤60  → true → celsius=60.0 → "✓ Set to 60°C"
 SET 100.0 → 100.0≥-40? yes; 100.0≤60? no → false → "✗ REJECTED: 100"
 SET -50.0 → -50.0≥-40? no → false → "✗ REJECTED: -50"
 SET 60.5  → 60.5≤60? no → false → "✗ REJECTED: 60.5"
 SET -39.999→ within range → true → celsius=-39.999 → "✓ Set to -39.999°C"
 display() → prints "-39.999°C / -39.999°F converted"

 TIME COMPLEXITY CALCULATION:
 - setCelsius: 2 comparisons + 1 assignment = fixed 3 ops  → O(1)
 - getCelsius: 1 return                                   → O(1)
 - getFahrenheit: 1 multiply + 1 divide + 1 add + 1 return → O(1)
 - display: calls getters, constant print count            → O(1)
 → Time Complexity = O(1) per operation (worst case still constant)

 SPACE COMPLEXITY CALCULATION:
 - celsius (double) = 8 bytes, two static const doubles shared = 16 bytes once
 - No arrays, no malloc, no recursion
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌────────────────────┬────────────────────────────┬───────────────────────────────────┐
 │ Aspect             │ Without Encapsulation      │ With Encapsulation                │
 ├────────────────────┼────────────────────────────┼───────────────────────────────────┤
 │ Data access        │ Direct (any value)         │ Controlled (validated)            │
 │ Data integrity     │ Not guaranteed             │ Enforced by the class             │
 │ Maintenance        │ Change everywhere          │ Change the class only             │
 │ Testing            │ Test every call site       │ Test class methods once           │
 │ Security           │ Internals visible          │ Internals hidden from callers     │
 └────────────────────┴────────────────────────────┴───────────────────────────────────┘
*/

#include <iostream>
using namespace std;

class Thermometer {
private:
    double celsius;            // yahan temperature store hota hai — private, bahar se koi nahi chhed sakta

public:
    // constructor — default init 0°C
    Thermometer() : celsius(0.0) {
        cout << "[CTOR] Thermometer initialized to 0°C" << endl;
    }

    // setter with range validation — range check -40..60
    bool setCelsius(double val) {
        const double MIN_TEMP = -40.0;
        const double MAX_TEMP = 60.0;
        if (val < MIN_TEMP || val > MAX_TEMP) {
            cout << "  ✗ REJECTED: " << val << "°C out of range [" << MIN_TEMP
                 << ", " << MAX_TEMP << "]" << endl;
            return false;               // galat value reject, data safe raha
        }
        celsius = val;                   // sab kuch valid hai to hi store karo
        cout << "  ✓ Set to " << celsius << "°C" << endl;
        return true;
    }

    // getter — stored value return
    double getCelsius() const {
        return celsius;
    }

    // derived value — user ko chahiye Fahrenheit, internal bas Celsius hi hai
    double getFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32.0;
    }

    void display() const {
        cout << "  Current reading: " << celsius << "°C / "
             << getFahrenheit() << "°F" << endl;
    }
};

int main() {
    cout << "========== ENCAPSULATION DEMO: THERMOMETER ==========" << endl << endl;

    Thermometer t;

    cout << "\n--- 1) Valid inputs ---" << endl;
    t.setCelsius(25.0);
    t.display();

    cout << "\n--- 2) Edge: exactly min and max are ACCEPTED ---" << endl;
    t.setCelsius(-40.0);
    t.display();
    t.setCelsius(60.0);
    t.display();

    cout << "\n--- 3) Invalid inputs are REJECTED, state stays safe ---" << endl;
    t.setCelsius(100.0);     // sieve point: too hot
    t.setCelsius(-50.0);     // too cold
    t.setCelsius(60.5);      // passa byaah: just above max
    t.setCelsius(-40.5);     // just below min

    cout << "\n--- 4) Value unchanged after failures ---" << endl;
    t.display();

    cout << "\n--- 5) Private access is blocked at compile time ---" << endl;
    // t.celsius = 999.0;   // COMPILE ERROR: 'double Thermometer::celsius' is private
    // cout << t.celsius;   // saath hi ye bhi error dega

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}