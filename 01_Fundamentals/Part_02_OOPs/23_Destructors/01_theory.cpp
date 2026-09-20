/*
═══════════════════════════════════════════════
 DESTRUCTORS — cleanup, destruction order, virtual destructors
 ⏱️ TIME COMPLEXITY: O(1) per object; O(n) to destroy n objects
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 After a college fest, the ground is littered and every hall is messy. A
 dedicated CLEANING STAFF shuts each hall only AFTER the event in that hall
 finishes — and halls close in the REVERSE order they were opened. The main
 stage that opened FIRST is cleaned LAST; the small stalls that opened later
 are cleaned FIRST. In C++, the cleaning crew is the DESTRUCTOR and it runs
 automatically the moment an object's lifetime ends.

 📖 THEORY: (pure English, beginner-level)
 - DESTRUCTOR: `~ClassName()` — a member function with the class name
   prefixed by `~`, NO return type and NO parameters. It runs automatically
   when an object DIES and is used to RELEASE resources (delete[] heap,
   close files, release locks).
 - WHEN IS IT CALLED?
     (1) a stack object reaches the end of its scope (closing `}` or return)
     (2) `delete p;` is executed on a heap object
     (3) the program ends → remaining global/static objects are destroyed
 - DESTRUCTION ORDER: ALWAYS the REVERSE of construction. Objects built
   FIRST are destroyed LAST (LIFO). Arrays are destroyed from the LAST
   element back to the first.
 - MEMBER destruction: after the destructor body runs, members are destroyed
   in the REVERSE order of their declaration.
 - VIRTUAL DESTRUCTOR: if you delete a DERIVED object through a BASE-class
   pointer and the base destructor is not virtual, only ~Base runs → the
   Derived part leaks its resources. Declare the base destructor virtual.
 - RAII IDEA: as soon as a resource is acquired in the constructor, the
   destructor guarantees release — even on early return or exceptions.

  DESTRUCTION ORDER (stack objects in ONE scope)
   created:     f1  →  f2  →  x1  →  x2
                    ┌────────────────────┐
                    ▼                    ▼
   destroyed:   f1  ←  f2  ←  x2  ←  x1     (REVERSE order = LIFO)
   rule: "whatever was built first is destroyed last"

   ARRAY OF OBJECTS
   built  :  arr[0] → arr[1] → arr[2]
   killed :  arr[2] → arr[1] → arr[0]

   VIRTUAL DESTRUCTOR LESSON
   Base* p = new Derived();  delete p;
   non-virtual base dtor:  only "Base dtor" runs → Derived part LEAK ✗
   virtual base dtor:      "Derived dtor" → "Base dtor"   → full cleanup ✓

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: f1 declared at main() scope prints "Opening a.txt" — constructor =
   resource acquisition. WHY: the object is born with its resource ready.
 Step 2: An inner block declares f2 and then the array arr[2] of Files.
   WHY: nested blocks give a natural stage to watch lifetimes.
 Step 3: The inner block ENDS → immediately arr[1], arr[0], then f2 are
   destroyed. WHY: stack objects die in LIFO order as scope unwinds.
 Step 4: `new File("heap.txt")` then `delete p;` → only `delete` triggers
   the destructor. WHY: heap objects have no automatic scope cleanup.
 Step 5: Delete through a base pointer → the virtual keyword makes ~Derived
   run before ~Base. WHY: the derived part must free its own stuff first.
 Step 6: main() ends → f1, created FIRST, is destroyed LAST.
   WHY: destruction always mirrors construction in reverse.

 VISUAL WALKTHROUGH: (the demo below)
   ┌─ main scope ───────────────────────────────────────┐
   │  File f1  ◄── created 1st                         │
   │  ┌─ inner block ────────────────────────────────┐ │
   │  │  File f2       ◄── created 2nd               │ │
   │  │  File arr[2]   ◄── created 3rd (x1, x2)      │ │
   │  │  }  ← block ends: destroy x2 → x1 → f2       │ │ ← destruction
   │  │  delete heap.txt   (manual, NOW)             │ │   starts at the
   │  │  delete derived    (virtual chain)           │ │   INNERMOST level
   │  └──────────────────────────────────────────────┘ │   (LIFO)
   │  }  ← main ends: destroy f1 (created 1st, LAST)   │
   └────────────────────────────────────────────────────┘

 DRY RUN: (trace of the demo — exact printed sequence)
   main:
   "Opening file : a.txt"      ← File f1 (outer scope, built FIRST)
   "Opening file : b.txt"      ← File f2 (inner block)
   "Opening file : x1.txt"     ← arr[0]
   "Opening file : x2.txt"     ← arr[1]
   "Closing file : x2.txt"     ← block ends → arr[1] killed (REVERSE)
   "Closing file : x1.txt"     ← arr[0] killed
   "Closing file : b.txt"      ← f2 killed
   "Opening file : heap.txt"   ← new File("heap.txt")
   "Closing file : heap.txt"   ← delete p → destructor runs RIGHT NOW
   "  Base ctor" / "  Derived ctor"        ← new Derived()
   "  Derived dtor" / "  Base dtor"        ← delete b (virtual → full chain)
   "Closing file : a.txt"      ← main ends → f1 killed LAST

 TIME COMPLEXITY CALCULATION:
 - ~File(): prints 1 line + destroys one string   → constant ops.
 - Array arr[2]: destroys n = 2 objects           → n destructor calls.
 - delete p: 1 destructor + OS free               → constant.
 - Virtual dispatch: 1 extra indirect call/v-table lookup → ~O(1).
 → Time Complexity = O(n) to destroy n objects, O(1) for a single object

 SPACE COMPLEXITY CALCULATION:
 - Each File holds one std::string → O(1) per object.
 - n alive objects → n × sizeof(File) → peak usage O(n).
 - Destruction allocates NO extra memory — it only frees.
 → Space Complexity = O(n) for n objects, O(1) per object

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────────────────────────────────┐
 │ destroy...           │ result                                          │
 ├──────────────────────┼──────────────────────────────────────────────────┤
 │ scope } ends         │ destructor runs AUTOMATICALLY (stack objects)   │
 │ delete p             │ destructor runs for heap object (manual trigger)│
 │ end of main          │ remaining global/static objects destroyed       │
 │ non-virtual base dtor│ ~Base only → derived resources LEAK             │
 │ virtual base dtor    │ ~Derived then ~Base → full cleanup              │
 └──────────────────────┴──────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

class File {
private:
    string path;          // jo resource "khula" hai use band karna hai
public:
    File(const string& p) : path(p) {
        cout << "Opening file : " << path << "\n";
    }

    ~File() {             // destructor — object ke marne par khud chal jata hai
        cout << "Closing file : " << path << "\n";
    }
};

// virtual destructor demo — base pointer se derived delete karne par
// derived ka dtor bhi chale, isliye base ka dtor virtual banana padta hai
class Base {
public:
    Base()  { cout << "  Base    ctor\n"; }
    virtual ~Base() { cout << "  Base    dtor\n"; }   // ← virtual yahan fix karta hai
};
class Derived : public Base {
public:
    Derived()  { cout << "  Derived ctor\n"; }
    ~Derived() { cout << "  Derived dtor\n"; }        // pehle derived, phir base
};

int main() {
    cout << "--- File f1 (outer scope) ---\n";
    File f1("a.txt");

    {
        cout << "--- inner block ---\n";
        File f2("b.txt");

        cout << "--- array of objects ---\n";
        File arr[2] = { File("x1.txt"), File("x2.txt") };
        cout << "--- inner block END: reverse-order destruction shuru ---\n";
    }   // yahan destroy: arr[1] → arr[0] → f2  (construction ka ULTA)

    cout << "--- new/delete: destructor delete par call hota hai ---\n";
    File* p = new File("heap.txt");
    delete p;                        // delete → ~File() turant chala

    cout << "--- virtual destructor (base pointer se delete) ---\n";
    Base* b = new Derived();
    delete b;                        // Derived dtor pehle, phir Base dtor

    cout << "--- end of main: f1 (sabse pehle bana) LAST me destroy ---\n";
    return 0;
}