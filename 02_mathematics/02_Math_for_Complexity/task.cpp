/*
═══════════════════════════════════════════════
 TASK SET — MATH FOR COMPLEXITY
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: You start with one email forward; every day it
doubles. The log of that growth tells you "how many days have passed" just
from the count — that is the doubling/decoding skill every interview question
about logs is really testing.

🧠 HOW TO SOLVE: think in terms of "how many times to halve/double" for logs
(binary exponent), count digits via log10 vs division loop, replace summation
loops with closed formulas (n(n+1)/2, 2^k − 1) for O(1) answers, and compare
growth rates by printing tables.
 5 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

/*
--------------------------------------------------------------------
 TASK 1 (EASY) — find k such that 2^k = 1024, by hand reasoning.
 💡 HINT: 2^10 = 1024 is the classic KB value. Derive via doubling
    1→2→4→8→16→32→64→128→256→512→1024 = 10 steps, so k = 10.
 ✏️ STARTER CODE:
    // nhade hum 2^k = 1024, k = log2(1024) = ?
--------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
using namespace std;

void solveTask1() {
    // derivation: 2^10 = 1024  →  k = 10
    // Why: log2(1024) = 10 because 1024 / 2 repeated 10 times reaches 1.
    int n = 1024;
    int k = (int)floor(log2((double)n));          // 10
    // verification via doubling loop
    int v = 1, count = 0;
    while (v < n) { v *= 2; count++; }            // runs exactly 10 times
    cout << "Task 1: 2^" << k << " = " << n << " | loop-derived k = " << count << "\n";
    cout << "   Complexity: 1 formula step -> O(1); doubling loop -> O(k) = O(log2 n)\n\n";
}

/*
--------------------------------------------------------------------
 TASK 2 (EASY-MED) — count digits of any n using the log10 trick.
 💡 HINT: digits = floor(log10(n)) + 1. Test edge n = 0.
 ✏️ STARTER CODE:
    // log10(n) + 1? careful for n == 0 (1 digit)
--------------------------------------------------------------------
*/
void solveTask2() {
    // derivation: numbers in [10^(d-1), 10^d) have d digits.
    // log10(999) = 2.99 → floor = 2 → +1 = 3 digits. Correct.
    long long n = 987654321;
    long long digits = (n == 0) ? 1 : (long long)floor(log10((double)n)) + 1;
    long long loop = (n == 0) ? 1 : 0, t = n;
    while (t > 0) { loop++; t /= 10; }
    cout << "Task 2: digits of " << n << " = log trick " << digits
         << ", loop " << loop << ", edge n=0 -> " << ((0 == 0) ? 1 : 0) << "\n";
    cout << "   Complexity: loop versions O(log10 n); the log10 call itself is O(1)\n\n";
}

/*
--------------------------------------------------------------------
 TASK 3 (MED) — verify sum 1..n = n(n+1)/2 for n = 100 against a loop.
 💡 HINT: 100*101/2 = 5050 — classic Gauss trick.
 ✏️ STARTER CODE:
    // loop sum vs n*(n+1)/2, print EQUAL
--------------------------------------------------------------------
*/
void solveTask3() {
    // derivation: loop adds 1..100 → 5050; formula 100*101/2 = 5050.
    int n = 100;
    long long loopSum = 0;
    for (int i = 1; i <= n; i++) loopSum += i;          // O(n) work
    long long formula = (long long)n * (n + 1) / 2;     // O(1) work
    cout << "Task 3: sum 1.." << n << " loop=" << loopSum
         << " formula=" << formula
         << " -> " << (loopSum == formula ? "EQUAL (Gauss was right)" : "WRONG!") << "\n";
    cout << "   Complexity: loop O(n) vs formula O(1) — formula wins for big n\n\n";
}

/*
--------------------------------------------------------------------
 TASK 4 (MED) — geometric sum 1+2+4+...+1024: value and complexity.
 💡 HINT: 1+2+4+..+2^10 = 2^11 − 1 = 2047. Formula 2^(k+1) − 1.
 ✏️ STARTER CODE:
    // sum = 2^(exponent+1) - 1; last term 1024 = 2^10
--------------------------------------------------------------------
*/
void solveTask4() {
    // derivation: terms are 2^0..2^10 (last 1024). Neutral formula:
    // 1 + 2 + 4 + ... + 2^10 = 2^11 − 1 = 2048 − 1 = 2047.
    int lastExp = 10;                       // 1024 = 2^10
    long long loopSum = 0, term = 1;
    for (int i = 0; i <= lastExp; i++) { loopSum += term; term *= 2; }  // O(k)
    long long formula = (1LL << (lastExp + 1)) - 1;                     // O(1)
    cout << "Task 4: 1+2+4+...+1024 loop=" << loopSum
         << " formula=" << formula
         << " -> " << (loopSum == formula ? "EQUAL (2^11-1)" : "WRONG!") << "\n";
    cout << "   Complexity: loop O(k)=O(log lastTerm); formula O(1);\n";
    cout << "   (doubling k terms totals ~2^k = exponential value but linear add count)\n\n";
}

/*
--------------------------------------------------------------------
 TASK 5 (HARD) — 2^n vs n^3: print table n=5..20, show who wins.
 💡 HINT: 2^n eventually crushes n^3; long long safe until 2^62 approx, so
    2^20 = 1048576 is safe. Print ratio too.
 ✏️ STARTER CODE:
    // for n 5..20: print n, 2^n (1LL<<n), n^3, ratio
--------------------------------------------------------------------
*/
void solveTask5() {
    // derivation: compare growth — doubling each +1 vs cubic already large.
    // At n=5: 32 vs 125 (cube WINS). At n=20: 1048576 vs 8000 (2^n WINS).
    // Crossing point ~ n=10: 1024 vs 1000 — after that 2^n dominates forever.
    cout << "Task 5: 2^n vs n^3 table (long long safe till n=30)\n";
    cout << "   n       2^n           n^3        ratio(2^n/n^3)\n";
    for (int n = 5; n <= 20; n++) {
        long long p2 = 1LL << n;
        long long cube = (long long)n * n * n;
        double ratio = (double)p2 / cube;
        cout << "   " << n << "        " << p2 << "      " << cube
             << "      " << ratio << "\n";
    }
    cout << "   Conclusion: 2^n is brutal — beyond n≈10 it leaves n^3 in dust.\n";
    cout << "   Complexity: each row O(1); table prints 16 rows → O(n) output.\n\n";
}

int main() {
    solveTask1();
    solveTask2();
    solveTask3();
    solveTask4();
    solveTask5();
    return 0;
}