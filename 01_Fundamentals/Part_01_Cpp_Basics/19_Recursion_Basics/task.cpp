/*
═══════════════════════════════════════════════
 TASK SET — RECURSION BASICS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A librarian wants the total books. He asks the
    next stack, which asks the next... the LAST stack knows "there is 1
    book". Answers bubble back: 1, 1+1=2, 2+1=3... Each sub-answer is a
    recursive call returning to the caller. Base case = "last stack".
    Without it, the chain never stops (stack overflow crash).

 🧠 HOW TO SOLVE: Every recursive function needs TWO things:
    1. BASE CASE — smallest input, direct answer, no recursion.
    2. RECURSIVE STEP — reduce input size, call the function with the
       smaller problem, and combine the returned result.
    Trace small inputs by hand (n=3 or n=4) to see the pattern before
    coding. Always guard negative inputs so recursion never runs forever.

 MODES/TOPICS COVERED:
  1. Sum 1 to n recursively
  2. Compute a^b recursively
  3. GCD via Euclid's recursion
  4. Count digits recursively
  5. Fibonacci recursively (with base cases)
  6. Binary search using recursion
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════
// TASK 1: Sum 1..n
// ═══════════════════════════════════════════
long long sumN(int n) {
    if (n <= 0) return 0;        // negative/zero guard
    if (n == 1) return 1;        // base case: 1 ka sum 1
    return n + sumN(n - 1);      // n + chhote sum ka jawab
}

// ═══════════════════════════════════════════
// TASK 2: Power a^b (b >= 0)
// ═══════════════════════════════════════════
long long power(int a, int b) {
    if (b < 0) return -1;        // negative exponent guard
    if (b == 0) return 1;        // base case: koi bhi ^0 = 1
    return a * power(a, b - 1);  // a × (a^(b-1))
}

// ═══════════════════════════════════════════
// TASK 3: GCD via Euclid
// ═══════════════════════════════════════════
int gcd(int a, int b) {
    if (b == 0) return a;        // base case: b 0 ho gaya, a hai answer
    return gcd(b, a % b);        // Euclid: gcd(a,b)=gcd(b,a%b)
}

// ═══════════════════════════════════════════
// TASK 4: Count digits
// ═══════════════════════════════════════════
int countDigits(int n) {
    if (n < 0) n = -n;           // negative ko positive banao
    if (n < 10) return 1;        // base: ek digit
    return 1 + countDigits(n / 10);  // ek digit count + baaki
}

// ═══════════════════════════════════════════
// TASK 5: Fibonacci with trace
// ═══════════════════════════════════════════
long long fibRec(int n) {
    cout << "  fib(" << n << ") called" << endl;
    if (n < 0) return -1;        // guard
    if (n == 0) return 0;        // base case 1
    if (n == 1) return 1;        // base case 2
    return fibRec(n - 1) + fibRec(n - 2);   // do sub-calls
}

// ═══════════════════════════════════════════
// TASK 6: Binary search (recursive)
// ═══════════════════════════════════════════
int bSearch(int arr[], int lo, int hi, int key) {
    if (lo > hi) return -1;          // base: range khatam, nahi mila
    int mid = lo + (hi - lo) / 2;    // overflow-safe middle
    if (arr[mid] == key) return mid; // base: mil gaya
    if (key < arr[mid]) return bSearch(arr, lo, mid - 1, key);
    return bSearch(arr, mid + 1, hi, key);
}

int main() {
    cout << "=== TASK 1: sumN ===" << endl;
    cout << "  sumN(5) = " << sumN(5) << "   (expect 15)" << endl;
    cout << "  sumN(0) = " << sumN(0) << "   (edge case, expect 0)\n" << endl;

    cout << "=== TASK 2: power ===" << endl;
    cout << "  power(2,10) = " << power(2, 10) << "   (expect 1024)" << endl;
    cout << "  power(3,0)  = " << power(3, 0) << "   (expect 1)\n" << endl;

    cout << "=== TASK 3: gcd ===" << endl;
    cout << "  gcd(48, 18) = " << gcd(48, 18) << "   (expect 6)" << endl;
    cout << "  gcd(17, 5)  = " << gcd(17, 5)  << "   (expect 1)\n" << endl;

    cout << "=== TASK 4: countDigits ===" << endl;
    cout << "  countDigits(12345) = " << countDigits(12345) << "   (expect 5)" << endl;
    cout << "  countDigits(-987)  = " << countDigits(-987) << "   (expect 3)\n" << endl;

    cout << "=== TASK 5: fibRec(5) ===" << endl;
    cout << "  fibRec(5) = " << fibRec(5) << "   (expect 5)\n" << endl;

    cout << "=== TASK 6: binary search ===" << endl;
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = 10;
    cout << "  Searching 23 in sorted array..." << endl;
    int idx = bSearch(arr, 0, n - 1, 23);
    cout << "  Found at index: " << idx << "   (expect 5)" << endl;
    idx = bSearch(arr, 0, n - 1, 99);
    cout << "  Searching 99 (absent): " << idx << "   (expect -1)" << endl;

    cout << "\nAll recursion tasks done." << endl;
    return 0;
}