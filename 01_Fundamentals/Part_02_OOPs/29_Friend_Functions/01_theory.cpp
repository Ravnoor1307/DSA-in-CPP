/*
═══════════════════════════════════════════════
 FRIEND FUNCTIONS & FRIEND CLASS
 ⏱️ TIME COMPLEXITY: O(1) — friend functions do direct field access; no loops.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A company keeps its financial ledgers in a highly secure room with very tight
 locks — only account managers know the combination (private members). To get
 a fair annual audit, they grant a special access badge to an EXTERNAL auditor
 who does not work for the company. The auditor is not an employee, so they do
 not hold a key from the HR system, but the company deliberately writes the
 auditor's name on the access list. This is exactly what a friend function is:
 an OUTSIDE free function that the class explicitly grants access to, so it can
 read the private books (private members) without being a member itself. In C++,
 the class issues the "badge" with the `friend` keyword.

 📖 THEORY: (pure English, beginner-level)

 1. FRIEND FUNCTION:
    - A non-member (free/global) function that is declared INSIDE the class
      using the `friend` keyword.
    - Because of that declaration, it can access private AND protected members.
    - It is NOT a member of the class — no `this` pointer, cannot be called
      with `object.friendFunction()`.
    - Called like a normal function: `add(d1, d2);`
    - Friendship is given, NOT taken — only the class decides who is a friend.

 2. FRIEND CLASS:
    - A class B can be declared as a friend of class A.
    - Then ALL member functions of B can access private/protected parts of A.
    - Friendship is NOT symmetric and NOT transitive:
        A is friend of B  ≠  B is friend of A
        A friend of B, B friend of C  ≠  A friend of C

 3. PROS:
    - Natural way to write operator overloading for user types
      (e.g. `d1 + d2`, `cout << d1`).
    - Efficient — direct access, no repeated getter calls.
    - Lets related helper utilities coordinate with a class cleanly.

 4. CONS:
    - Breaks encapsulation — private data leaks to outside code.
    - Tight coupling — if the class changes internals, friends break too.
    - Maintenance hazard in large codebases.

 5. WHEN TO USE:
    - Operator overloading (<<, >>, +, ==) that needs both operands.
    - Utility functions that logically belong to the class but as free functions.

 ╔══════════════════════════════════════════════════════════════════════╗
 ║          FRIEND FUNCTION — "KEY TO THE PRIVATE ROOM"                ║
 ╠══════════════════════════════════════════════════════════════════════╣
 ║                                                                     ║
 ║   ┌────────────────────────────┐        ┌─────────────────────────────┐ ║
 ║   │  class Distance            │        │  global function            │ ║
 ║   │  ┌──────────────────────┐  │        │  Distance add(D, D)         │ ║
 ║   │  │ PRIVATE ROOM         │  │        │  {                         │ ║
 ║   │  │  feet  ←waiting      │  │        │     // friend declared:     │ ║
 ║   │  │  inches              │  │        │     d1.feet  ✅ ACCESS      │ ║
 ║   │  └──────────────────────┘  │        │     d2.inches ✅ ACCESS     │ ║
 ║   │                            │        │  }                         │ ║
 ║   │  friend Distance           │        │                             │ ║
 ║   │  add(Distance, Distance);  │        │                             │ ║
 ║   └────────────────────────────┘        └─────────────────────────────┘ ║
 ║              │   The class gifts a KEY (friend keyword)                 ║
 ║              └───────────────►  to this outside function                ║
 ║                                                                        ║
 ║   KEY POINT: normal outsider can NEVER see feet/inches.                ║
 ║   The friend function has a special pass that opens the private room.  ║
 ╚════════════════════════════════════════════════════════════════════════╝

 ╔══════════════════════════════════════════════════════════════════════╗
 ║                    FRIEND CLASS — ACCESS WEB                        ║
 ╠══════════════════════════════════════════════════════════════════════╣
 ║                                                                     ║
 ║   class A { private: int secret; friend class B; };                 ║
 ║   class B {  void peek(A& a) { a.secret = 42; } };  ✅ works        ║
 ║                                                                     ║
 ║   BUT (not symmetric):                                              ║
 ║     B::anything inside A  → NO, unless A also says friend class B    ║
 ║     (not transitive):                                               ║
 ║     A gives key to B, B gives key to C — C STILL cannot enter A      ║
 ╚══════════════════════════════════════════════════════════════════════╝

 🧠 LOGIC — STEP BY STEP:

 Step 1: Define class Distance with private members feet and inch.
   WHY: Encapsulation — measurement data stays protected by default.

 Step 2: Declare `friend Distance add(Distance, Distance);` inside the class.
   WHY: This is the "badge" — now the free function may touch privates.

 Step 3: Write the free (global) function `add` OUTSIDE the class.
   WHY: Friend functions are defined outside; no scope operator needed.

 Step 4: Inside add, normalize inches (carry every 12 inches → 1 foot).
   WHY: Real-world units: 12 inches = 1 foot. Handles overflow cleanly.

 Step 5: Declare `friend class Auditor;` so the second class can read privates.
   WHY: Demonstrates friend CLASS — a whole set of functions gets access.

 Step 6: Handle edge cases — negative feet/inches and inch > 12.
   WHY: Robust API must not print garbage like "5 ft 15 in".

 VISUAL WALKTHROUGH: (state of add(d1, d2))

   d1: feet=3, inch=7        d2: feet=4, inch=8
        │                        │
        └────────────┬───────────┘
                     ▼
              add(d1, d2):
                 totalFeet  = 3  + 4      = 7
                 totalInch  = 7  + 8      = 15
                 15 >= 12   → inchCarry  = 15 / 12 = 1
                 finalFeet  = 7  + 1      = 8
                 finalInch  = 15 % 12     = 3
                     │
                     ▼
              Result: feet=8, inch=3   ✅ correct!

 DRY RUN: (demo in main)

   Distance d1(5, 9);      // feet=5, inch=9
   Distance d2(2, 6);      // feet=2, inch=6
   sum = add(d1, d2);      // friend function access
       → totalFeet = 5+2 = 7
       → totalInch = 9+6 = 15, carry = 1, inch = 3, feet = 8
   sum.print()             // "8 ft 3 in"

   Distance d3(4, 20);     // EDGE: inch = 20 (> 12)
   Distance d4(-3, 5);     // EDGE: negative feet
   add(d3, d4):
       → feet = 4 + (-3) = 1, inch = 20 + 5 = 25
       → carry = 2, inch = 1, feet = 3
       → "3 ft 1 in"

   Distance neg(-1, -8);   // EDGE: both negative → warning shown

 TIME COMPLEXITY CALCULATION:
 - add(): 2 additions + 1 division + 1 mod (normalization)   → O(1)
 - print(): 1 cout (fixed work)                              → O(1)
 - friend function setup: compile-time only, zero runtime cost → O(1)
 - No loops over collections anywhere                        → O(1)
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - Each Distance object: 2 ints (feet, inch)                 → 8 bytes
 - add() local variables: totalFeet, totalInch, carry        → 12 bytes (stack)
 - No extra structures allocated                             → O(1) extra
 → Space Complexity = O(1) per operation

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Aspect               │ Friend Function              │ Getter-Based Access           │
 ├──────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Encapsulation        │ Broken (deliberately)        │ Preserved                    │
 │ Syntax               │ friend declared in class     │ public getFeet()/setFeet()    │
 │ Private access       │ Direct — private members OK  │ Only via getters             │
 │ Code locality        │ Lives outside class          │ Lives inside class           │
 │ Use case             │ Operator overloading, utils  │ General safe read/write      │
 │ Coupling             │ Tight                       │ Loose                        │
 │ Performance          │ No function-call overhead    │ Extra getter call per read   │
 └──────────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
using namespace std;

// ═══════════════════════════════════════════════════════════════
// CLASS Distance — private feet & inch, friend function declared
// ═══════════════════════════════════════════════════════════════
class Distance {
private:
    int feet;
    int inch;

public:
    // ═══ Constructor (inline) ═══
    Distance(int f, int i) {
        feet = f;
        inch = i;
    }

    // ═══ FRIEND DECLARATIONS — "badge" issued for outsiders ═══
    // ye declaration ke baad hi add() private members ko chhu sakti hai
    friend Distance add(Distance d1, Distance d2);

    // const display — sirf padhne ke liye, modify nahi karega
    void display() const {
        if (feet < 0 || inch < 0)          // EDGE CASE: negative units
            cout << "  [!] Warning: negative measurement (" << feet
                 << " ft " << inch << " in)" << endl;
        else
            cout << "  " << feet << " ft " << inch << " in" << endl;
    }
};

// ═══════════════════════════════════════════════════════════════
// FRIEND FUNCTION — defined OUTSIDE the class
// NO Distance:: scope needed, NO this pointer — it is a free function
// ═══════════════════════════════════════════════════════════════
Distance add(Distance d1, Distance d2) {
    int totalFeet = d1.feet + d2.feet;   // private members directly access — friend hone ki shakti!
    int totalInch = d1.inch + d2.inch;

    // ═══ NORMALIZATION: 12 inches = 1 foot ═══
    int carry = totalInch / 12;          // kitne feet banengi inches se
    totalInch = totalInch % 12;          // jo inches bach jaayein
    totalFeet += carry;                  // carry ko feet me add karo

    return Distance(totalFeet, totalInch);
}

// ═══════════════════════════════════════════════════════════════
// FRIEND CLASS DEMO — two cooperating classes
// ═══════════════════════════════════════════════════════════════
class Auditor;   // forward declaration

class Finance {
private:
    int cashInHand;   // private data — sirf Finance ke apne functions + friend
    int goldValue;

public:
    Finance(int c, int g) {
        cashInHand = c;
        goldValue = g;
    }

    // Class Auditor ko full access de diya — saf private members, directly
    friend class Auditor;

    void show() const {
        cout << "Cash: " << cashInHand << ", Gold: " << goldValue << endl;
    }
};

// Auditor class — friend of Finance → sab private members access kar sakti hai
class Auditor {
public:
    // Auditor ka member function Finance ke private me ghus sakta hai
    void audit(Finance& f) {
        cout << "  Auditor inspects: Cash = $" << f.cashInHand
             << ", Gold = $" << f.goldValue << " ✅ (private data readable!)" << endl;
    }

    // Auditor apne audit report me data modify bhi kar sakti hai
    void adjustGold(Finance& f, int delta) {
        f.goldValue += delta;   // private member direct modify — friend ka hukum
        cout << "  Auditor adjusted gold by " << delta
             << " → new Gold = $" << f.goldValue << endl;
    }
};

// ═══════════════════════════════════════════════════════════════
// COMPILE-RUN DEMO WITH EDGE CASES
// ═══════════════════════════════════════════════════════════════
int main() {
    cout << "=============================================" << endl;
    cout << " FRIEND FUNCTIONS & FRIEND CLASS — DEMO" << endl;
    cout << "=============================================" << endl;

    // ═══ EDGE CASE 1: Normal addition ═══
    cout << "\n--- Edge Case 1: Normal addition ---" << endl;
    Distance d1(5, 9);
    Distance d2(2, 6);
    Distance sum1 = add(d1, d2);   // friend function call — object-ke-through NAHI
    cout << "5 ft 9 in + 2 ft 6 in =";
    sum1.display();
    // Expected: 8 ft 3 in (carry of 1 foot from 15 inches)

    // ═══ EDGE CASE 2: Inch overflow (> 12) in inputs ═══
    cout << "\n--- Edge Case 2: Inch overflow in inputs ---" << endl;
    Distance d3(4, 20);            // invalid raw value: 20 inches
    Distance d4(3, 5);
    Distance sum2 = add(d3, d4);
    cout << "4 ft 20 in + 3 ft 5 in =";
    sum2.display();
    // Expected: 9 ft 1 in (20+5=25 inches → carry 2 → feet 4+3+2=9, inch=1)

    // ═══ EDGE CASE 3: Negative feet ═══
    cout << "\n--- Edge Case 3: Negative feet ---" << endl;
    Distance d5(-3, 5);
    Distance d6(6, 7);
    Distance sum3 = add(d5, d6);
    cout << "-3 ft 5 in + 6 ft 7 in =";
    sum3.display();
    // Expected: 4 ft 0 in (feet -3+6=3, inch 5+7=12 → carry 1 → feet 4, inch 0)

    // ═══ EDGE CASE 4: Both values produce exactly 0 ═══
    cout << "\n--- Edge Case 4: Cancel-out to zero ---" << endl;
    Distance d7(2, 6);
    Distance d8(-2, -6);
    Distance sum4 = add(d7, d8);
    cout << "2 ft 6 in + (-2 ft -6 in) =";
    sum4.display();
    // Expected: 0 ft 0 in

    // ═══ EDGE CASE 5: Both inputs empty/zero ═══
    cout << "\n--- Edge Case 5: Zero + Zero ---" << endl;
    Distance z1(0, 0);
    Distance z2(0, 0);
    Distance sum5 = add(z1, z2);
    cout << "0 ft 0 in + 0 ft 0 in =";
    sum5.display();
    // Expected: 0 ft 0 in

    // ═══ EDGE CASE 6: Negative display warning ═══
    cout << "\n--- Edge Case 6: Negative raw object ---" << endl;
    Distance neg(-1, -8);
    neg.display();   // warning branch triggered
    // Expected: warning message printed

    // ═══ FRIEND CLASS DEMO ═══
    cout << "\n--- Friend Class: Auditor inspects Finance ---" << endl;
    Finance fin(50000, 12000);
    cout << "Company books:" << endl;
    fin.show();

    Auditor a1;              // auditor object
    a1.audit(fin);           // finance ke private data padha (friend class)
    a1.adjustGold(fin, 3000); // finance ke private data badla (friend class)
    cout << "After audit report:" << endl;
    fin.show();

    cout << "\n=============================================" << endl;
    cout << " All edge cases handled — compiles & runs." << endl;
    cout << "=============================================" << endl;
    return 0;
}