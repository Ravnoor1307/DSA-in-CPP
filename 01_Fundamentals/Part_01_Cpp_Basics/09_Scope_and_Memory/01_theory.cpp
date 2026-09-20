/*
═══════════════════════════════════════════════
 SCOPE, LIFETIME & MEMORY LAYOUT
 ⏱️ TIME COMPLEXITY: scope rules are compile-time (zero runtime cost); each static-counter call = O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A company office is a perfect model. The RECEPTION NOTICE BOARD (global scope)
 is visible to every employee — anyone can read it anywhere. A MANAGER'S
 CREDENTIALS (local scope) exist only inside her cabin; the moment she leaves,
 her files are locked away and gone from sight. But the OFFICE REGISTER (static
 local) sits in a locked drawer: every visitor to that counter sees the SAME
 running total, and the count survives even after each visit ends. That is
 exactly: global = office-wide, local within {} = cabin-only, static = the same
 drawer that remembers its value across every visit.

 📖 THEORY: (pure English, beginner-level)
 - SCOPE: the region of the program where a NAME is visible. Determined by
   curly-brace blocks { }.
 - LIFETIME: the time period during which the variable's MEMORY actually exists.
   Scope ≠ Lifetime — a static local can be out of scope yet still alive in memory.
 - LOCAL variable: declared inside a function/block. Scope = that block. Lifetime =
   from its declaration to the end of the block. Stored on the STACK.
 - GLOBAL variable: declared outside all functions. Scope = the whole file after
   the declaration point. Lifetime = the whole program. Stored in the STATIC/DATA
   segment (initialized globals → .data, uninitialized → .bss, which is zero-filled).
 - BLOCK SCOPE: every pair of braces can hold variables invisible to the outside.
 - SHADOWING: an inner variable with the same name hides the outer one inside its
   block ("nearest declaration wins").
 - STATIC LOCAL: `static int c = 0;` inside a function — scope is still the
   function block, but LIFETIME is the whole program. It is initialized ONCE
   (first time execution reaches the declaration) and keeps its value across
   every later call. Stored in the STATIC/DATA segment.
 - STORAGE CLASSES in C++:
     auto        → default storage for locals (stack)
     register    → hint to keep value in a CPU register (mostly ignored now)
     static      → data segment, life = whole program
     extern      → "this global is defined elsewhere" — just declares it
     thread_local/ mutable → advanced (per-thread / const-object member)

 - PROCESS MEMORY LAYOUT (low address → high):
     CODE (text)     → machine instructions (read-only)
     STATIC / DATA   → globals + statics (.data initialized, .bss zeroed)
     HEAP            → new / malloc allocations; grows UP
     STACK           → function frames + locals; grows DOWN
     (space between heap and stack is shared free memory)

  ASCII — memory layout of a running program:
   high addr  ┌─────────────────────┐
              │       STACK         │ <- local vars, function frames (grows down)
              │        ...          │
              │       (free)        │
              │        ...          │
              │       HEAP          │ <- new / delete (grows up)
              │  STATIC / DATA      │ <- globals + statics (.data / .bss)
              │   CODE (TEXT)       │ <- machine instructions
   low addr   └─────────────────────┘

  ASCII — shadowing (nearest declaration wins):
   int x = 100;            // global — visible almost everywhere in the file

   void f() {
       int x = 5;          // LOCAL x — shadows the global x=100
       cout << x;          // prints 5 (the nearest declaration wins)
   }                        // local x's scope ends here

   cout << x;               // (outside f) — the global x = 100 is found

 WHEN TO USE:
 - Globals: genuine shared configuration/state that the whole program needs.
 - Locals: temporary data inside one function — keep scope as tight as possible.
 - Static locals: state a function must REMEMBER between calls (counters, caches).
 - Avoid shadowing: pick distinct names so the hidden variable never surprises you.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Declare locals as close to the code that uses them as possible.
        WHY: tight scope = fewer surprises and lower memory pressure.
 Step 2: Prefer locals over globals for temporary data.
        WHY: globals live the whole program and create hidden coupling/bugs.
 Step 3: Use `static` for state that must persist between calls.
        WHY: static gives program lifetime while keeping the name private to the block.
 Step 4: Avoid shadowing by choosing different names for inner blocks.
        WHY: shadowing is legal but silently hides outer data and confuses readers.

 VISUAL WALKTHROUGH: (nextCounter with static)
  call #1 -> static counter 0 -> increment -> 1 (counter is now 1)
  call #2 -> static counter 1 -> increment -> 2 (persist!)
  call #3 -> static counter 2 -> increment -> 3
  (a NON-static local counter reset to 0 each call and returns 1 every time)

 DRY RUN: (shadowing demo program)
  main:  g = 10           (global g)
  f:     g = 25 -> prints 25   (local g shadows global)
  main:  prints g -> 10   (global visible in main again, untouched)

 TIME COMPLEXITY CALCULATION:
 - Scope/lifetime decisions happen entirely at COMPILE time; the running code
   does zero work for them.
 - A static-counter call: one increment + one return = constant instructions
   regardless of how many calls have happened so far.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - Globals and statics occupy ONE fixed chunk in the static/data segment — constant.
 - Each function call adds one small stack frame; that frame is freed on return.
 → Space Complexity = O(1) per call (fixed global/static area + transient frames)

 APPROACH COMPARISON:
 ┌────────────────┬────────────────────┬─────────────────────┬────────────────────┐
 │ Aspect         │ Global variable    │ Local variable      │ Static local       │
 ├────────────────┼────────────────────┼─────────────────────┼────────────────────┤
 │ Scope          │ whole file         │ block only          │ block only         │
 │ Lifetime       │ whole program      │ till block ends     │ whole program      │
 │ Storage        │ data segment       │ stack               │ data segment       │
 │ Auto reset?    │ no                 │ yes, each block     │ no — persists      │
 │ Use when       │ shared config      │ temporary work data │ stateful counters  │
 └────────────────┴────────────────────┴─────────────────────┴────────────────────┘
*/
#include <iostream>
using namespace std;

int g = 100;                 // GLOBAL variable — static/data segment me rehta hai
int g_autoZero;              // uninitialized global -> .bss -> automatically 0

// static local counter: value har call ke beech YAAD rehti hai
int nextCounter() {
    static int counter = 0;  // ek baar initialize; agle calls me purani value
    counter++;               // increment
    return counter;
}

// NON-static local counter: har call pe fresh 0 banti hai
int plainCounter() {
    int counter = 0;         // har call pe nayi variable
    counter++;
    return counter;
}

// shadowing demo: local g GLOBAL g=100 ko block ke andar chhupa deta hai
void shadowDemo() {
    int g = 5;               // local g — global g ka naam shadow
    cout << "  function ke andar local g = " << g << endl;
}

int main() {
    cout << "=== 1) Global vs Local (Shadowing) ===" << endl;
    cout << "main me global g = " << g << endl;
    shadowDemo();
    cout << "main me wapas g = " << g << "  (global untouched)" << endl;

    cout << "\n=== 2) Block scope {} ===" << endl;
    {
        int x = 42;                       // x ka scope sirf is block tak
        cout << "  block ke andar x = " << x << endl;
    }
    // cout << x;   // ERROR dega: 'x' not declared in this scope
    cout << "  (block khatam -> x gayab. Uncomment karke dekh sakte ho error)" << endl;

    cout << "\n=== 3) Static counter vs local counter (5 calls) ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  call " << i + 1 << " -> static = " << nextCounter()
             << "   |   local = " << plainCounter() << endl;
    }

    cout << "\n=== 4) Memory segments: globals & statics ===" << endl;
    cout << "  g_autoZero (global, no init) = " << g_autoZero
         << "  (.bss zero-fill)" << endl;

    cout << "\n=== 5) EDGE CASES ===" << endl;
    cout << "  static counter ek aur call par continue: " << nextCounter()
         << "  (6 — reset NAHI hua, persist proof)" << endl;
    cout << "  plainCounter khud ka alag instance: " << plainCounter()
         << "  (hamesha 1)" << endl;
    return 0;
}