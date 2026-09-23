/*
═══════════════════════════════════════════════
 TASK SET — DESTRUCTORS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: After a fest, halls close in the REVERSE order
    they opened — the stage that opened first is cleaned last. Similarly a
    destructor is the automatic "cleaning staff" of an object: it runs at
    scope-end, at delete, and at program-end, and it always runs for stack
    objects in LIFO order.

 🧠 HOW TO SOLVE: 1) Close in the destructor any resource the constructor
    opened (file, heap, timer) — this is called RAII. 2) When a scope
    ends, stack objects are destroyed in reverse order. 3) Always answer
    new with delete; if you forget delete, the destructor will NOT run.
    4) If you delete a derived object through a base pointer, make the
    base destructor virtual.

 MODES/TOPICS COVERED:
  1. Timer: the RAII pattern
  2. Destruction order across nested blocks
  3. Array of objects destroyed in reverse (LIFO)
  4. new/delete: manual destruction and leaks
  5. Virtual destructor for polymorphic delete
  6. Early-return cleanup guaranteed by RAII
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