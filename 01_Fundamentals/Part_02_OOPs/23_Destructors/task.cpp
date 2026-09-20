/*
═══════════════════════════════════════════════
 TASK SET — DESTRUCTORS
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 After a fest, halls close in the REVERSE order they opened — the stage
 that opened first is cleaned last. Similarly a destructor is the automatic
 "cleaning staff" of an object: it runs at scope-end, at delete, and at
 program-end, and it always runs for stack objects in LIFO order.

 🧠 HOW TO SOLVE:
 1) Jo resource ctor me khola (file, heap, timer) use dtor me band karo —
    isi ko RAII kehte hain.
 2) Scope khatam → stack objects reverse order me destroy hote hain.
 3) new ka jawab humesha delete se do; delete bhool gaye to dtor NAHI chalega.
 4) Base pointer se derived delete karna ho to base ka dtor virtual rakho.

 TASKS (EASY → HARD):

 TASK 1 — Timer: RAII (EASY)
 class Timer: label + start time. Ctor prints "Timer started", dtor prints
 "Timer destroyed". In main() make a Timer inside a block and watch it die
 at the block's closing brace.
 💡 HINT: dtor ka syntax ~Timer() { ... } — block } par khud chal jata hai.
 ✏️ STARTER CODE:
 // class Timer {
 //   private: string label;
 //   public:
 //     Timer(string l);   // print started
 //     ~Timer();          // print destroyed
 // };
 // main: { Timer t("A"); ... }   ← } par dtor chala

 TASK 2 — Destruction order: nested blocks (EASY)
 Make 3 Timers: A at main scope, B inside one inner block, C inside an even
 deeper block. Print as each scope opens/closes. Observe that C dies first
 and A dies last — REVERSE of construction.
 💡 HINT: scope jitna under, dtor utna pehle.
 ✏️ STARTER CODE:
 // void demo() {
 //   Timer A("A");
 //   { Timer B("B");
 //     { Timer C("C"); }
 //     cout << "inner block over, B alive\n";
 //   }
 // }   // order: C → B → A

 TASK 3 — Array of objects (MEDIUM)
 Make an ARRAY of 3 Timers {"P","Q","R"} inside a block. Print construction
 and destruction — the array is destroyed PICHHE se (R → Q → P).
 💡 HINT: array destruction = last element se first tak, LIFO.
 ✏️ STARTER CODE:
 // Timer arr[3] = { Timer("P"), Timer("Q"), Timer("R") };
 // // destruction: R, Q, P

 TASK 4 — new/delete: manual destruction (MEDIUM)
 Create two heap Timers with new. delete only the FIRST one with delete —
 print when its destructor runs. Leave the second undeleted and comment on
 why its destructor never runs (memory/resource LEAK).
 💡 HINT: heap objects scope par destroy NAHI hote — sirf delete par.
 ✏️ STARTER CODE:
 // Timer* p = new Timer("heap-1");
 // delete p;              // ← dtor yahan chala
 // Timer* q = new Timer("leak");  // delete bhool gaye → LEAK

 TASK 5 — Virtual destructor (HARD)
 class Base { public: virtual ~Base(); };
 class Derived : public Base { public: ~Derived(); };
 In main(): Base* obj = new Derived(); delete obj; observe which destructor
 runs. Comment: WITHOUT virtual, sirf ~Base chalta → Derived part leak.
 💡 HINT: base pointer se delete karte waqt virtual dtor derived ka bhi dtor
    chain se chalata hai.
 ✏️ STARTER CODE:
 // Base* obj = new Derived();
 // delete obj;   // virtual → Derived dtor, phir Base dtor

 TASK 6 — Session early-return cleanup (HARD)
 class Session: ctor prints "acquired", dtor prints "released". Write
 doWork(bool fail) that creates a Session, then RETURNS EARLY on failure.
 Show that even on early return the destructor runs automatically (RAII).
 Then call doWork(true) and doWork(false).
 💡 HINT: stack objects ko early return bhi nahi bachata — scope exit par
    dtor pakka chalta hai.
 ✏️ STARTER CODE:
 // bool doWork(bool fail) {
 //   Session s("db-conn");
 //   if (fail) return false;   // yahan bhi ~Session() chala
 //   return true;
 // }
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <string>
using namespace std;

// ============ TASK 1 SOLUTION — Timer RAII ============
class Timer {
private:
    string label;

public:
    Timer(string l) : label(l) {
        cout << "    Timer [" << label << "] started\n";
    }
    ~Timer() {
        cout << "    Timer [" << label << "] destroyed\n";
    }
};

void runTask1() {
    cout << "Task1 :\n";
    {
        Timer t("scope-1");          // is block ke } par dtor chale ga
        cout << "    ... using timer ...\n";
    }                                // ← yahan clear
}

// ============ TASK 2 SOLUTION — destruction order ============
void runTask2() {
    cout << "Task2 :\n";
    Timer A("A");                    // sabse pehle bana
    {
        cout << "    -> inner block open\n";
        Timer B("B");                // doosre number me bana
        {
            cout << "    -> deepest block open\n";
            Timer C("C");            // sabse aakhir me bana
        }                            // C dies FIRST
        cout << "    -> inner block still has B alive\n";
    }                                // B dies second
    cout << "    -> outer still has A alive\n";
}                                    // A dies LAST (= reverse of construction)

// ============ TASK 3 SOLUTION — array of objects ============
void runTask3() {
    cout << "Task3 :\n";
    Timer arr[3] = { Timer("P"), Timer("Q"), Timer("R") };
    cout << "    -> block ends: array destruction R -> Q -> P\n";
}                                    // R, Q, P — last element first (LIFO)

// ============ TASK 4 SOLUTION — new/delete manual ============
void runTask4() {
    cout << "Task4 :\n";
    Timer* p = new Timer("heap-1");  // heap — koi scope nahi
    delete p;                        // ← dtor ABHI chala (manual trigger)
    cout << "    -> heap-1 deleted\n";

    Timer* q = new Timer("leak-demo");
    // delete q;   // ⚠️ delete BHOOL gaye → ~Timer() kabhi NAHI chalega;
    // isliye heap par jo bhi object bana, uski zindagi aapke haath me hai.
    cout << "    -> leak-demo deliberately NOT deleted (comment dekho)\n";
}

// ============ TASK 5 SOLUTION — virtual destructor ============
class Base {
public:
    Base()  { cout << "      Base ctor\n"; }
    virtual ~Base() { cout << "      Base dtor (virtual)\n"; }   // ← virtual zaroori
};
class Derived : public Base {
public:
    Derived()  { cout << "      Derived ctor\n"; }
    ~Derived() { cout << "      Derived dtor\n"; }               // pehle derived, phir base
};

void runTask5() {
    cout << "Task5 :\n";
    Base* obj = new Derived();       // base pointer → derived object
    delete obj;                      // virtual → Derived dtor → Base dtor dono
    cout << "      (agar dtor virtual na hota: sirf Base dtor chalta,\n";
    cout << "       Derived ka resource LEAK ho jata)\n";
}

// ============ TASK 6 SOLUTION — early-return cleanup (RAII) ============
class Session {
private:
    string id;

public:
    Session(string i) : id(i) {
        cout << "    Session " << id << " acquired\n";
    }
    ~Session() {
        cout << "    Session " << id << " released\n";
    }
};

bool doWork(bool fail) {
    Session s("db-conn");            // resource khula
    if (fail) {
        cout << "    work failed → early return\n";
        return false;                // 💡 phir bhi ~Session() chala — RAII guarantee
    }
    cout << "    work completed\n";
    return true;
}

void runTask6() {
    cout << "Task6 :\n";
    cout << "  -> call doWork(fail=true)\n";
    doWork(true);
    cout << "  -> call doWork(fail=false)\n";
    doWork(false);
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
    cout << "\n(done)\n";
    return 0;
}