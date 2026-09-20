/*
═══════════════════════════════════════════════
 TASK SET — FUNCTION OVERLOADING
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
  Help-desk: one shared phone number, a different specialist for each problem.
  In C++ too, the same function name with different parameter types — the
  compiler sees the type and selects the right version at compile time itself.

 🧠 HOW TO SOLVE:
  Keep the same name, but make the parameters different (count or type).
  Remember: overloading is NOT done by RETURN TYPE. Each version has its own
  distinct body.

  MODES/TOPICS COVERED:
   1. Overloaded print()
   2. area(): circle vs rectangle
   3. area(): triangle, using 2-param version
   4. min(): two ints, three ints, two doubles
   5. add(): int 2-arg, int 3-arg, double 2-arg
   6. greeting() overloads (0, 1, 2 params)
   7. Fix the AMBIGUITY

  ═══════════════════════════════════════════════
   TASK 1 (EASY) — Overloaded print()
   print(int), print(double), print(string) — all three have a different
   output line.
   💡 HINT: Three versions, name same "print", parameter type different each time.
   ✏️ STARTER CODE (description): void print(int v) { cout << "int: " << v; }
       All three versions look like this, only the tag changes.

   TASK 2 (EASY) — area(): circle vs rectangle
   area(double radius) -> circle; area(double length, double width) -> rectangle.
   💡 HINT: One param = circle, two params = rectangle — the param COUNT makes
       the difference.
   ✏️ STARTER CODE (description): double area(double r) { return 3.14159*r*r; }
       double area(double l, double w) { return l*w; }

   TASK 3 (MEDIUM) — area(): triangle, using 2-param version
   area(double base, double height) as triangle (0.5*b*h) AND a 1-param square
   area(double side) -> side*side.
   💡 HINT: Triangle = two numbers, Square = one number.
   ✏️ STARTER CODE (description): double area(double side); and
       double area(double base, double height); — each has its own body.

   TASK 4 (MEDIUM) — min(): two ints, three ints, two doubles
   💡 HINT: 3 kinds of params = 3 overloads.
   ✏️ STARTER CODE (description): min(int a,int b); min(int,int,int);
       min(double a,double b) — all three return the smallest.

   TASK 5 (MEDIUM) — add(): int 2-arg, int 3-arg, double 2-arg
   💡 HINT: Flexibility in both count and type.
   ✏️ STARTER CODE (description): add(int,int), add(int,int,int),
       add(double,double) — bodies are simple sums.

   TASK 6 (HARD) — greeting() overloads (0, 1, 2 params)
   greeting() -> "Hello!"; greeting("Ritu") -> "Hello Ritu!";
   greeting("Ritu", "morning") -> "Good morning Ritu!".
   💡 HINT: 0 params, 1 param, 2 params — a typical case of three overloads.
   ✏️ STARTER CODE (description): void greeting(); void greeting(string name);
       void greeting(string name, string timeOfDay).

   TASK 7 (HARD) — Fix the AMBIGUITY
   Both foo(long) and foo(float) exist. The call foo(5) will be ambiguous
   because an int can go into both via "standard conversion". Fix it with a
   cast.
   💡 HINT: foo((long)5) becomes an exact long — ambiguity gone.
   ✏️ STARTER CODE (description): Toggle the ambiguous line and see; you will
       get a compile error. Fix: foo((long)x) and foo((float)x) are exact
       matches. Leave the ambiguous line commented out.
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <string>
using namespace std;

// TASK 1 — print overloads (same naam, alag types)
void print(int v)   { cout << "print(int)   : " << v << endl; }
void print(double v){ cout << "print(double): " << v << endl; }
void print(string v){ cout << "print(string): " << v << endl; }

// TASK 2 & 3 — area overloads (1 param, 2 params, 3 params)
double area(double radius) {                 // 1 param = circle
    return 3.14159265358979 * radius * radius;
}
double area(double length, double width) {   // 2 params = rectangle / triangle base-h
    return length * width;
}
double triangleArea(double base, double height) { // aapka 0.5-wala kaam
    return 0.5 * base * height;
}
double area(double a, double b, bool isTriangle) {// 3 params: alternate triangle/side
    return isTriangle ? 0.5 * a * b : a * b;
}
double squareArea(double side) {             // square = 1 param
    return side * side;
}

// TASK 4 — min overloads
int min(int a, int b) { return (a < b) ? a : b; }
int min(int a, int b, int c) { return min(min(a, b), c); }
double min(double a, double b) { return (a < b) ? a : b; }

// TASK 5 — add overloads
int add(int a, int b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
double add(double a, double b) { return a + b; }

// TASK 6 — greeting overloads (0/1/2 params)
void greeting() { cout << "Hello!" << endl; }
void greeting(string name) { cout << "Hello " << name << "!" << endl; }
void greeting(string name, string timeOfDay) {
    cout << "Good " << timeOfDay << " " << name << "!" << endl;
}

// TASK 7 — ambiguity: foo(long) aur foo(float)
void foo(long x)  { cout << "foo(long)  => " << x << endl; }
void foo(float x) { cout << "foo(float) => " << x << endl; }

int main() {
    cout << "TASK 1 — print overloads\n";
    print(42);
    print(3.14);
    print("Hello");

    cout << "\nTASK 2 — area(circle/rectangle)\n";
    cout << "area(2.0) [circle]    = " << area(2.0) << endl;
    cout << "area(3,4)  [rect]     = " << area(3.0, 4.0) << endl;

    cout << "\nTASK 3 — square & triangle area\n";
    cout << "squareArea(5)          = " << squareArea(5.0) << endl;
    cout << "triangleArea(4, 6)     = " << triangleArea(4.0, 6.0) << endl;
    cout << "area(4, 6, true) [tri] = " << area(4.0, 6.0, true) << endl;

    cout << "\nTASK 4 — min overloads\n";
    cout << "min(8,3) = " << min(8, 3)
         << " | min(8,3,5) = " << min(8, 3, 5)
         << " | min(2.5,1.9) = " << min(2.5, 1.9) << endl;

    cout << "\nTASK 5 — add overloads\n";
    cout << "add(2,3) = " << add(2, 3)
         << " | add(2,3,4) = " << add(2, 3, 4)
         << " | add(1.5,2.5) = " << add(1.5, 2.5) << endl;

    cout << "\nTASK 6 — greeting overloads\n";
    greeting();
    greeting("Ritu");
    greeting("Ritu", "morning");

    cout << "\nTASK 7 — ambiguity fix\n";
    foo((long)5);      // exact long -> long wali chali
    foo((float)5);     // exact float -> float wali chali
    // foo(5);         // AMBIGUOUS! int -> long aur int -> float dono standard
    //                  // conversions, barabar achhe. Compile error:
    //                  // 'call of overloaded foo(int)' is ambiguous
    cout << "(ambiguous call foo(5) comment me hai — kabhi compile nahi hota)\n";

    cout << "\nEDGE CASES\n";
    cout << "area(0) [zero radius] = " << area(0.0) << endl;
    cout << "min(5,5) [equal]      = " << min(5, 5) << endl;
    print("");
    return 0;
}