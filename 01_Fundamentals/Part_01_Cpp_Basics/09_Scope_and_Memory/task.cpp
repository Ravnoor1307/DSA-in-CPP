/*
═══════════════════════════════════════════════
 TASK SET — SCOPE & MEMORY (lifetime, static, storage classes)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
  Office: the reception notice board (global) is visible to everyone; the
  manager's cabin (local) data disappears the moment the cabin closes; the
  office register (static) remembers its value for every visitor.

 🧠 HOW TO SOLVE:
  Scope = WHERE the NAME is visible (the {} block). Lifetime = HOW LONG the
  MEMORY stays alive. A static local = a function-scope name, but
  program-lifetime memory. Keep these two separate in your mind — that is the
  core of all these tasks.

  MODES/TOPICS COVERED:
   1. Global counter
   2. Block scope {}
   3. Shadowing
   4. static counter that persists
   5. Dangerous lifetime: pointer to local vs static
   6. Storage classes (auto + register + extern)
   7. Nested & sibling blocks don't clash

  ═══════════════════════════════════════════════
   TASK 1 (EASY) — Global counter
   A global int counter = 0; and a function increment() that adds +1 to it and
   returns it. In main, call it 3 times and print.
   💡 HINT: A global is directly visible inside a function too.
   ✏️ STARTER CODE (description): outside "int counter = 0;" then
       "int increment() { counter++; return counter; }" and 3 calls in main.

   TASK 2 (EASY) — Block scope {}
   Declare a variable inside a { } block, print it inside, and show the line
   that touches it outside as a COMMENT (it would error).
   💡 HINT: The moment { } closes, the name's scope ends.
   ✏️ STARTER CODE: // { int secret = 42; cout << secret; }
       // cout << secret;   // ERROR: not declared in this scope

   TASK 3 (MEDIUM) — Shadowing
   Global x = 10, and a local x = 99 inside the function. Print x in the
   function and x in main — the values must differ.
   💡 HINT: The nearest declaration wins — the local shadows the global.
   ✏️ STARTER CODE (description): outside "int x = 10;" inside the function
       "int x = 99;" print in both places.

   TASK 4 (MEDIUM) — static counter that persists
   In a counter() function, "static int count = 0;" add +1 on every call and
   return it. 5 calls → must give 1,2,3,4,5 (if it were local, it would give 1
   every time).
   💡 HINT: static = initialized once, the value is remembered on later calls.
   ✏️ STARTER CODE: // int persistentCount() { static int c = 0; c++; return c; }

   TASK 5 (HARD) — Dangerous lifetime: pointer to local vs static
   One function returns a pointer to a LOCAL int (dangling — BAD, UB), and
   another returns a pointer to a STATIC local (SAFE). Instead of comparing
   values between the two, only demo the static one and explain the bad one in
   a comment.
   💡 HINT: a local dies on the stack; a static stays alive in the data segment.
   ✏️ STARTER CODE: // int* bad(){ int a = 5; return &a; }   // DANGLING
       // int* ok(){ static int a = 5; return &a; }          // SAFE

   TASK 6 (HARD) — Storage classes (auto + register + extern)
   auto loc = 5; (a normal local), register int hint = 4; (a compiler hint),
   and a global gv = 7; refer to it from a function with "extern int gv;" and
   print it.
   💡 HINT: register is deprecated but still compiles; extern means "this
   global is defined somewhere else".
   ✏️ STARTER CODE (description): outside "int gv = 7;" in the function
       "extern int gv; cout << gv;". Declare the auto/register locals yourself
       and print.

   TASK 7 (HARD) — Nested & sibling blocks don't clash
   Two separate for loops, each with its own "int total = 0;" inside — no
   conflict. Make a nested { } block: the inner one can see the outer one
   (outer accessible), the outer one cannot see the inner one.
   💡 HINT: every { } creates a new scope; the parent is visible inside a
   nested block.
   ✏️ STARTER CODE (description): an int total in one for loop; also an int
       total in the second for loop (both different). Nested block demo: print
       the outer var inside, show the inner var printed outside as a comment.
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// TASK 1 — global variable (data segment me zinda)
int counter = 0;
int increment() {
    counter++;                 // global direct dikhta hai
    return counter;
}

// TASK 3 — global x (shadowing demo ke liye)
int x = 10;
void shadowFunc() {
    int x = 99;                // local — global ko shadow
    cout << "  shadowFunc ke andar x = " << x << endl;
}

// TASK 4 — static counter (persist)
int persistentCount() {
    static int c = 0;          // ek baar create, phir persist
    c++;
    return c;
}

// TASK 5 — safe static pointer (bad wala comment me)
int* safeStatic() {
    static int a = 5;          // data segment — program bhar zinda
    return &a;
}

// TASK 6 — extern demo
int gv = 7;                    // global — yahin defined
void externDemo() {
    extern int gv;             // "ye variable bahar defined hai" -> wahi gv
    cout << "  extern ke through gv = " << gv << endl;
}

int main() {
    cout << "TASK 1 — global counter\n";
    for (int i = 0; i < 3; i++) cout << "  increment() = " << increment() << endl;

    cout << "\nTASK 2 — block scope {}\n";
    {
        int secret = 42;
        cout << "  andar secret = " << secret << endl;
    }
    // cout << secret;   // ERROR: 'secret' was not declared in this scope

    cout << "\nTASK 3 — shadowing\n";
    cout << "  main me x (global) = " << x << endl;
    shadowFunc();
    cout << "  main me wapas x    = " << x << "  (global safe)" << endl;

    cout << "\nTASK 4 — static counter (5 calls)\n";
    for (int i = 0; i < 5; i++) {
        cout << "  call " << i + 1 << " -> " << persistentCount() << endl;
    }

    cout << "\nTASK 5 — safe static pointer vs dangling local\n";
    int* p = safeStatic();     // safe pointer
    cout << "  safeStatic() deref = " << *p << endl;
    // BAD version: int* bad(){ int a = 5; return &a; } — a ka stack frame return
    // ke baad pop ho jaata hai; pointer "dangling" banta hai. Usse read karna
    // UNDEFINED BEHAVIOUR hai — kabhi value de sakta hai, kabhi garbage.
    // Isliye bad() ko yahan deliberately call NAHI kar rahe.

    cout << "\nTASK 6 — storage classes\n";
    auto loc = 5;              // auto = normal local (stack)
    register int hint = 4;     // register: compiler ko hint (deprecated but OK)
    externDemo();
    cout << "  auto loc = " << loc << ", register hint = " << hint << endl;

    cout << "\nTASK 7 — sibling & nested blocks\n";
    for (int i = 0; i < 2; i++) {
        int total = i * 10;    // is loop ka apna total
        cout << "  loop1 total = " << total << endl;
    }
    for (int i = 0; i < 2; i++) {
        int total = i + 100;   // dusre loop ka ALAG total — no clash
        cout << "  loop2 total = " << total << endl;
    }
    {
        int outer = 1;
        {
            int inner = 2;
            cout << "  nested: inner = " << inner
                 << ", outer accessible = " << outer << endl;
        }
        // cout << inner;      // ERROR — inner ka scope khatam
    }

    cout << "\nEDGE CASES\n";
    // Anti-demo (comment me): uninitialized LOCAL ko read karna UB hai —
    // garbage value milti hai, kabhi 0 kabhi random. Isliye yahan deliberately
    // read NAHI kar rahe. Sirf GLOBAL/static .bss me auto-zero hoti hai.
    cout << "  static counter continue: " << persistentCount()
         << "  (6 — persist proof, 1 nahi aaya)\n";
    return 0;
}