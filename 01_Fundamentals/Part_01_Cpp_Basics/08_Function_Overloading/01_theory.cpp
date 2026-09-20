/*
═══════════════════════════════════════════════
 FUNCTION OVERLOADING (Compile-Time Polymorphism)
 ⏱️ TIME COMPLEXITY: resolution happens at COMPILE time — each call is one direct jump = O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A hospital help-desk works on one phone number. "Doctor, I have a headache" →
 general physician. "My kid has a high fever" → pediatrician. Same phrase
 "doctor visit", different specialist — chosen by what you bring with you.
 In C++, the same FUNCTION NAME is that help-desk number: print(42) routes to
 the int version, print(3.14) to the double version, print("Hi") to the string
 version. The compiler plays receptionist and picks the specialist from your
 ARGUMENTS — and does the entire routing at COMPILE TIME, so the running
 program pays zero overhead.

 📖 THEORY: (pure English, beginner-level)
 - FUNCTION OVERLOADING = multiple functions with the SAME NAME but DIFFERENT
   parameter lists (different number of parameters, or different types).
 - It is compile-time (static) polymorphism — the "right" version is locked in
   while the code is being compiled; no runtime switching happens.
 - RULE #1: name + parameter list must differ. The RETURN TYPE alone does NOT
   distinguish overloads — C++ refuses to compile two functions that differ
   only by return type.
 - RULE #2: the parameter COUNT or the parameter TYPES (or both) must differ.
 - RULE #3: matching order is — exact match > type promotion (int→long, float→double)
   > standard conversion (int→double) > user-defined conversion (const char*→string).
 - AMBIGUITY: when two matches are equally good, the compiler raises an ERROR.
   Fix it with an explicit cast (e.g. foo((long)x)) to force an exact match.

  ASCII — which version binds when?
   call print(5)      -> binds to print(int)
   call print(3.14)   -> binds to print(double)
   call print("abc")  -> binds to print(string)

                 ┌──────────────────────────┐
   print(42) ──► │ void print(int p)        │ selected: exact int
                 ├──────────────────────────┤
   print(2.5)──► │ void print(double p)     │ selected: exact double
                 ├──────────────────────────┤
   print("hi")►  │ void print(string p)     │ selected: string conversion
                 └──────────────────────────┘

  ASCII — ambiguity scenario:
   foo(long)  and  foo(float)  — both exist
   foo(5)  -> int can become long, and it can become float —
               both are standard conversions, equally good
               -> COMPILER ERROR: "call of overloaded foo(int) is ambiguous"

 WHEN TO USE:
 - One logical operation offered for different types: print, max, min, area, add.
 - Convenience overloads: add(a,b) and add(a,b,c) both express "sum".
 - Keep all overloads under the same name with the SAME MEANING — overloading
   unrelated logic confuses readers.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Design the overloads — one name, one meaning, different parameters.
        WHY: that is exactly what overloading is: one concept, many forms.
 Step 2: Just write the calls — the compiler chooses the version automatically.
        WHY: resolution is automatic and fixed at compile time.
 Step 3: For ambiguous calls, add an explicit cast such as foo((long)5).
        WHY: a cast makes the intended argument type an EXACT match, which wins.
 Step 4: Never create two overloads differing only by return type.
        WHY: the compiler cannot tell which one the caller wants from the call alone.

 VISUAL WALKTHROUGH: (the print family)
   Expression          Available overloads               Chosen version
   ----------------------------------------------------------------------
   print(7)            print(int), print(double),        print(int)
                       print(string)
   ----------------------------------------------------------------------
   print(7.5)          same set                          print(double)
   ----------------------------------------------------------------------
   print("hi")         same set                          print(string)

 DRY RUN: (add overloads)
   add(2, 3)       -> matches add(int, int)            -> 5
   add(2, 3, 4)    -> matches add(int, int, int)       -> 9
   add(1.5, 2.25)  -> matches add(double, double)      -> 3.75

 TIME COMPLEXITY CALCULATION:
 - Overloading resolution is entirely a compile-time activity; the executable
   contains one direct call per call site. Runtime work = one function call — no
   searching, no branching, no checking, no matter how many overloads exist.
   That is constant work for the executed code (zero work for the selection).
 → Time Complexity = O(1) per call (selection itself: 0 at runtime)

 SPACE COMPLEXITY CALCULATION:
 - No runtime memory is allocated for overload resolution. Each overload is
   ordinary machine code with a different mangled name in the binary.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌─────────────────┬────────────────────────────┬────────────────────────────┐
 │ Aspect          │ Function overloading       │ One function + if/else     │
 ├─────────────────┼────────────────────────────┼────────────────────────────┤
 │ Readability     │ clean — one name, logic    │ messy type checks inside   │
 │                 │ separated per version      │                            │
 │ Type safety     │ compile-time exact match   │ runtime casts, error-prone │
 │ Performance     │ zero runtime overhead      │ runtime type switching     │
 │ Extendability   │ add a version, all call    │ edit one big function      │
 │                 │ sites stay unchanged       │ (large bug surface)        │
 └─────────────────┴────────────────────────────┴────────────────────────────┘
*/
#include <iostream>
#include <string>
using namespace std;

// ---- Overloaded print(): same name, teen alag versions ----
void print(int value) {
    cout << "print(int)   : " << value << endl;
}
void print(double value) {
    cout << "print(double): " << value << endl;
}
void print(string value) {
    cout << "print(string): " << value << endl;
}

// ---- Overloaded add(): 2 args / 3 args / double-double ----
int add(int a, int b) {
    return a + b;
}
int add(int a, int b, int c) {
    return a + b + c;
}
double add(double a, double b) {
    return a + b;
}

int main() {
    cout << "=== print() overloads — compiler exact type se version chunta hai ===" << endl;
    print(42);              // int literal -> exact int version
    print(3.14);            // double literal -> exact double version
    print("Namaste!");      // const char[] -> string me user-conversion -> string version

    cout << "\n=== add() overloads ===" << endl;
    cout << "add(2, 3)      = " << add(2, 3) << endl;         // (int,int)
    cout << "add(2, 3, 4)   = " << add(2, 3, 4) << endl;      // (int,int,int)
    cout << "add(1.5, 2.25) = " << add(1.5, 2.25) << endl;    // (double,double)

    // EDGE CASES
    cout << "\n=== EDGE CASES ===" << endl;
    cout << "add(0, 0, 0) = " << add(0, 0, 0) << endl;        // sab zero bhi int,int,int
    print(-7);              // negative bhi exact int
    print(0);               // zero bhi exact int
    print("");              // empty string bhi string version
    return 0;
}