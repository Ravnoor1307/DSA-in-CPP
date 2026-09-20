/*
═══════════════════════════════════════════════
 FUNCTIONS (Pass by Value vs Pass by Reference)
 ⏱️ TIME COMPLEXITY: add/swap = O(1); factorial loop = O(n); complexity derived below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A restaurant recipe is the perfect analogy. A chef (the caller) hands an
 instruction card (the function) some ingredients (arguments). The recipe card
 never touches the real ingredients — the butter you hand over is a photocopy,
 not the original block. An ATM, on the other hand, works on YOUR REAL ACCOUNT:
 the withdrawal method gets the actual account object (a reference) and changes
 its balance, and every bank in the network sees the update instantly. That is
 the exact difference between pass by value (photocopy) and pass by reference
 (the original file).

 📖 THEORY: (pure English, beginner-level)
 - A FUNCTION is a named, reusable block of code with inputs (parameters) and an
   optional output (return value).
 - SYNTAX:
     returnType functionName(parameterList) {
         // body
         return value;    // optional — required when returnType is not void
     }
 - FUNCTION PROTOTYPE: a declaration of only the signature (return type + name +
   parameters) placed BEFORE main, so the compiler knows the function exists even
   if its definition appears later in the file.
 - PARAMETER vs ARGUMENT: a parameter is the variable name in the signature (the
   slot); an argument is the value handed over at the call site (what fills the slot).
 - PASS BY VALUE: a COPY of the argument is made on the stack. Changes inside the
   function never reach the caller's variable.
 - PASS BY REFERENCE (&): no copy — the parameter becomes an ALIAS of the caller's
   variable. Changes inside DO reach the caller.
 - DEFAULT ARGUMENTS: parameters that carry a default value, used whenever the
   caller omits that argument. Defaults are written ONLY in the prototype/signature.
 - CALL STACK: every call pushes a frame (params + locals) onto the stack; the
   frame is popped when the function returns, which frees its memory.

  ASCII — pass by value = photocopy (stack diagram):
          STACK
   ┌─────────────────────────────┐
   │ caller locals: a=10,  b=20  │
   ├─────────────────────────────┤
   │ add frame:   x=10  <- copy  │
   │              y=20  <- copy  │
   └─────────────────────────────┘
   any change to x/y does NOT touch a/b at all

  ASCII — pass by reference = alias (stack diagram):
          STACK
   ┌─────────────────────────────┐
   │ caller locals: p=7,   q=9   │
   ├─────────────────────────────┤
   │ swap frame:   x ──► p (same cell)
   │              y ──► q (same cell)
   └─────────────────────────────┘
   swapping x,y changes p,q directly

  ASCII — call / return flow for result = add(3, 5):
   main: result = add(3, 5)
     │
     ▼  (1) arguments 3,5 pushed — add frame is created (x=3, y=5)
   body runs, computes 3+5 = 8
     │  (2) return 8 — the value is copied up to the caller
     ▼  (3) add frame popped (gone), memory freed
   result = 8  (in main)

 WHEN TO USE:
 - PASS BY VALUE: when the function must NOT modify the caller's data — calculators,
   read-only checks, pure computations.
 - PASS BY REFERENCE: when the function MUST modify the caller's data (swap, fill,
   increment) OR when copying the argument is expensive (big structs).
 - DEFAULT ARGUMENTS: optional settings — tax rate defaults to 5% unless the
   caller passes something else.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Declare a prototype so definitions can come after main.
        WHY: the compiler needs the signature at every call site.
 Step 2: Pass by value for read-only computation.
        WHY: the function gets a private copy — zero side effects on caller data.
 Step 3: Use "&" for parameters that must modify the caller's variable.
        WHY: & means "this parameter IS the caller's variable (an alias)".
 Step 4: Return results with return, or send outputs through reference params.
        WHY: return is the cleanest channel; references are for multi-output cases.

 VISUAL WALKTHROUGH: (swap by reference)
  start:  p = 7,  q = 9        x aliases p, y aliases q
  call:   swapByRef(p, q)
  frame:  x = p = 7,  y = q = 9
    temp = 7;  x becomes 9;  y becomes 7
  after:  p = 9,  q = 7     (original memory cells changed!)

 DRY RUN: (factorialByLoop(5))
  n=5, fact=1
    loop i=2: fact *= 2  ->  2
    loop i=3: fact *= 3  ->  6
    loop i=4: fact *= 4  -> 24
    loop i=5: fact *= 5  -> 120
  return 120

 TIME COMPLEXITY CALCULATION:
 - add(a,b): ~3 fixed operations (copy params, add, return) regardless of input → constant.
 - swapByRef(a,b): 3 assignments, fixed → constant.
 - factorialByLoop(n): loop runs (n-1) times (i=2..n); each iteration = 1 multiply
   → about n steps proportional to input.
 → Time Complexity = O(1) for add/swap; O(n) for factorial

 SPACE COMPLEXITY CALCULATION:
 - Every call pushes one fixed-size frame (a few ints) onto the stack; frame size
   does not grow with n, and frames pop on return.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌───────────────────┬────────────────────────┬──────────────────────┐
 │ Aspect            │ Pass by value          │ Pass by reference    │
 ├───────────────────┼────────────────────────┼──────────────────────┤
 │ Copy made?        │ Yes (photocopy)        │ No (alias of original)│
 │ Caller data safe? │ Yes — cannot be changed│ No — it CAN change  │
 │ Syntax            │ void f(int a)          │ void f(int &a)       │
 │ Memory cost       │ O(size of the copy)    │ O(1) reference       │
 │ Use when          │ read-only computation  │ must modify / huge   │
 │                   │                        │ argument             │
 └───────────────────┴────────────────────────┴──────────────────────┘
*/
#include <iostream>
using namespace std;

// ---- Prototypes: signature pehle, ek baar main() se pehle ----
int add(int x, int y);                // pass by value — copy banegi
void swapByRef(int &x, int &y);       // pass by reference — alias milega
int factorialByLoop(int n);           // loop se factorial
double applyTax(double amount, double rate = 0.05); // default argument sirf yahan

int main() {
    // ---- pass by value: caller ka data 100% safe ----
    int a = 10, b = 20;
    cout << "add(" << a << ", " << b << ") = " << add(a, b) << endl;
    cout << "after add(): a = " << a << ", b = " << b
         << "  (copy tha, caller unchanged)" << endl;

    // ---- pass by reference: real cells swap ho gaye ----
    int p = 7, q = 9;
    cout << "\nBefore swap: p = " << p << ", q = " << q << endl;
    swapByRef(p, q);
    cout << "After  swap: p = " << p << ", q = " << q
         << "  (real swap hua!)" << endl;

    // ---- factorial ----
    cout << "\nfactorial(5) = " << factorialByLoop(5) << endl;

    // ---- default argument demo ----
    cout << "applyTax(1000)          = " << applyTax(1000)
         << "  (5% default use hua)" << endl;
    cout << "applyTax(1000, 0.18)    = " << applyTax(1000, 0.18)
         << "  (18% explicit — rate as fraction)" << endl;

    // ---- EDGE CASES ----
    cout << "\n=== EDGE CASES ===" << endl;
    cout << "factorial(0) = " << factorialByLoop(0)
         << "  (0! = 1 hota hai)" << endl;
    cout << "factorial(1) = " << factorialByLoop(1) << endl;
    cout << "factorial(-3) = " << factorialByLoop(-3)
         << "  (negative pe loop 0 baar -> 1)" << endl;
    cout << "add(0, 0) = " << add(0, 0) << endl;
    return 0;
}

// ---- Definitions (body ab, signature upar thi) ----
int add(int x, int y) {
    int sum = x + y;                  // x,y copies hain — a,b ko lena-dena nahi
    return sum;                       // sum ki COPY caller tak return hoti hai
}

void swapByRef(int &x, int &y) {
    int temp = x;                     // temp me x ki value
    x = y;                            // x ke ASLI cell me y ki value
    y = temp;                         // y ke ASLI cell me purani x
}

int factorialByLoop(int n) {
    int fact = 1;                     // 0! aur 1! dono = 1 ke liye seed 1
    for (int i = 2; i <= n; i++) {    // 2 se n tak multiply
        fact *= i;
    }
    return fact;
}

double applyTax(double amount, double rate) {
    return amount + amount * rate;    // rate default abhi bhi prototype se aata
}