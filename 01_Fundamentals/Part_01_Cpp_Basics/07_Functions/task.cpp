/*
═══════════════════════════════════════════════
 TASK SET — FUNCTIONS (value vs reference)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
  Kitchen recipe (photocopy = pass by value) vs ATM transaction (real account =
  pass by reference). Some functions just return a value, some modify the
  caller's data (swap, fill).

 🧠 HOW TO SOLVE:
  In every task first decide — does the function need a COPY of the argument
  (by value) or the caller's ACTUAL variable (by reference, add &). Writing
  the prototype above and the definition later is allowed.

  MODES/TOPICS COVERED:
   1. Function to add two integers (prototype + definition)
   2. Maximum number in an array (size as a parameter)
   3. isPrime(n) returning bool
   4. swap two numbers BY REFERENCE
   5. factorial (any approach)
   6. applyTax with a DEFAULT argument
   7. Prove pass-by-value is a copy

  ═══════════════════════════════════════════════
   TASK 1 (EASY) — Function to add two integers
   Prototype before main(), definition after main(). Call it and print the result.
   💡 HINT: returnType name(params); with the body added later.
   ✏️ STARTER CODE (description): above write "int sumTwo(int a, int b);" as the
       boundary; in main "cout << sumTwo(3, 7);" and later the definition
       "{ return a + b; }".

   TASK 2 (EASY) — max number in an array (function)
   int arr[] = {3, 9, 1, 7}; → max = 9. Make the array size a parameter too.
   💡 HINT: seed maxVal = arr[0], then keep comparing in a loop.
   ✏️ STARTER CODE (description): int maxOfArray(int arr[], int size) { int maxVal
       = arr[0]; for i=1..size-1 if arr[i] > maxVal then update; return maxVal; }

   TASK 3 (MEDIUM) — isPrime(n) return bool
   💡 HINT: check divisors from 2 to sqrt(n); for (n < 2) return false immediately.
   ✏️ STARTER CODE (description): for (int i=2; i*i<=n; i++) if n%i==0 then false.
       When the loop finishes, true.

   TASK 4 (MEDIUM) — swap two numbers BY REFERENCE
   💡 HINT: add & or the swap silently fails.
   ✏️ STARTER CODE: // void swapByRef(int &x, int &y) { int t = x; x = y; y = t; }

   TASK 5 (MEDIUM) — factorial (any approach)
   💡 HINT: 0! = 1. Keep multiplying in a loop i=2..n.
   ✏️ STARTER CODE (description): int fact = 1; for (int i = 2; i <= n; i++)
       fact *= i; return fact;

   TASK 6 (HARD) — applyTax with a DEFAULT argument
   applyTax(1000) must apply the default 5%; applyTax(1000, 18) must use 18%.
   💡 HINT: write the default only in the prototype/signature: "double rate = 0.05".
   ✏️ STARTER CODE (description): double applyTax(double amount, double rate =
       0.05) { return amount + amount * rate; }

   TASK 7 (HARD) — Prove pass-by-value is a copy
   A function changes an int inside (x = 999); in main check that the caller's
   value does NOT change.
   💡 HINT: a copy of the value parameter is created on the stack; the caller's
       variable stays untouched.
   ✏️ STARTER CODE (description): void tryModify(int x) { x = 999; } ... in main
       after "int a = 5; tryModify(a);" the value of a must still be 5.
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// Prototypes — sab functions ki signature ek jagah
int sumTwo(int a, int b);
int maxOfArray(int arr[], int size);
bool isPrime(int n);
void swapByRef(int &x, int &y);
int factorialLoop(int n);
double applyTax(double amount, double rate = 0.05);   // default yahi definition
void tryModify(int x);

int main() {
    cout << "TASK 1 — sumTwo(3, 7) = " << sumTwo(3, 7) << endl;

    int marks[] = {3, 9, 1, 7, 5};
    cout << "TASK 2 — max in {3,9,1,7,5} = " << maxOfArray(marks, 5) << endl;

    cout << "TASK 3 — isPrime(7) = " << (isPrime(7) ? "true" : "false")
         << ", isPrime(12) = " << (isPrime(12) ? "true" : "false")
         << ", isPrime(1) = " << (isPrime(1) ? "true" : "false") << endl;

    int p = 4, q = 8;
    cout << "TASK 4 — before swap: p=" << p << " q=" << q;
    swapByRef(p, q);
    cout << " | after swap: p=" << p << " q=" << q << "  (real swap!)" << endl;

    cout << "TASK 5 — factorial(5) = " << factorialLoop(5)
         << ", factorial(0) = " << factorialLoop(0) << endl;

    cout << "TASK 6 — applyTax(1000) = " << applyTax(1000)
         << " (5% default) | applyTax(1000, 0.18) = " << applyTax(1000, 0.18)
         << " (18% explicit)" << endl;

    int a = 5;
    tryModify(a);
    cout << "TASK 7 — tryModify(5) ke baad a = " << a
         << "  (by value = copy, caller 100% safe)" << endl;
    return 0;
}

// TASK 1 — definition (prototype upar tha, ab body)
int sumTwo(int a, int b) {
    return a + b;
}

// TASK 2 — array function (array decay hokar pointer ban jaata hai, isliye
//          size alag se pass karna padta hai)
int maxOfArray(int arr[], int size) {
    int maxVal = arr[0];                        // seed = pehla element
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];   // bada mila to update
    }
    return maxVal;
}

// TASK 3 — prime check (sqrt tak hi kaafi hai)
bool isPrime(int n) {
    if (n < 2) return false;                     // 0 aur 1 prime nahi hote
    for (int i = 2; i * i <= n; i++) {           // i*i <= n == i <= sqrt(n)
        if (n % i == 0) return false;            // divisor mil gaya
    }
    return true;
}

// TASK 4 — swap by reference (&) — original cells badalte hain
void swapByRef(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

// TASK 5 — factorial via loop
int factorialLoop(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

// TASK 6 — default argument: rate pass nahi kiya to 0.05 (5%)
double applyTax(double amount, double rate) {
    return amount + amount * rate;
}

// TASK 7 — by value: x ek COPY hai, caller ka 'a' nahi
void tryModify(int x) {
    x = 999;                                     // sirf copy badalti hai
}