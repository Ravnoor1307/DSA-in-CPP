/*
═══════════════════════════════════════════════
 BINARY EXPONENTIATION (FAST POWER)
 ⏱️ TIME COMPLEXITY: O(log b) — derived below. Naive loop is O(b).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are working in a bakery that must keep multiplying dough. One rule of
 thumb: to double your dough you just fold it once, and folding an already-folded
 batch doubles it instantly. To reach 2^13 folds worth of volume you need only
 loop over the 4 bits of 13 ("1101") and combine 4 pre-squared batches, instead of
 physically folding 13 separate times. This is exactly what fast power does: it
 "pre-squares" the base at each level so one squaring step covers double the work.
 In cryptography, servers compute a^b mod p for 300-digit exponents in a fraction
 of a second — the naive b-loop would never finish in a human lifetime.

 📖 THEORY: (pure English, beginner-level)
 - Definition: Binary Exponentiation computes a^b (or a^b mod m) in O(log b) time
   using the identity that squaring the base lets each step handle one bit of the
   exponent.
 - Core recurrence: for b >= 0,
      a^b = (a^(b/2))^2            when b is even
      a^b = a * (a^(b/2))^2        when b is odd
   which follows directly from exponent laws:
      a^(2k) = (a^k)^2   and   a^(2k+1) = a * (a^k)^2
 - Key insight: instead of b multiplications, we compute powers by halving the
   exponent each round, so the number of rounds = number of bits of b = log2(b)+1.
 - Mod property: (a * b) % m = ((a % m) * (b % m)) % m — multiplying two reduced
   numbers keeps everything small and free of overflow when using long long.
 - ASCII diagram — exponent 13 = 1101 in binary (bits read left→right, MSB first,
   but the iterative algorithm walks them from RIGHT to LEFT = LSB first):

        EXPONENT 13  =  1 1 0 1   (binary)
                        │ │ │ └─ 2^0 =  1  -> bit set: multiply result by base
                        │ │ └─── 2^1 =  2  -> bit clear: just square
                        │ └───── 2^2 =  4  -> bit set: multiply result by base
                        └─────── 2^3 =  8  -> bit set: multiply result by base

        Squaring chain of the base (each level = one loop iteration):
         base = 3                   (bit 0, value 3^1)
         base = 3^2 = 9             (bit 1, value 3^2)
         base = 9^2 = 81            (bit 2, value 3^4)
         base = 81^2 = 6561         (bit 3, value 3^8)

        Result picks only the bits that are 1:  3^13 = 3^1 * 3^4 * 3^8

 - When to use: big exponents (10^9+), exponentiation in modular arithmetic,
   Fibonacci/linear recurrences via matrix power, and any "repeat-and-square"
   counting problem.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Represent the exponent in binary. 13 = 8+4+1 = 1101, so
         x^13 = x^8 * x^4 * x^1. WHY: exponent laws turn one big exponent into a
         handful of pre-squarable pieces (only ~log2(b) of them).
 Step 2: Iteratively read exponent bits from the LSB side. In each iteration:
         if the current bit is 1, multiply the running result by the current base;
         then ALWAYS square the base for the next (more significant) bit.
         WHY: the base already equals x^(2^k) at the k-th step (1, x, x^2, x^4, x^8...),
         so multiplying `result` by `base` exactly adds that power into the product.
 Step 3: Shift the exponent right by 1 bit each round (exp /= 2). WHY: this drops
         the consumed LSB so the next loop reads the next bit — the loop naturally
         runs exactly as many times as there are bits (log2(b)+1).
 Step 4: (Modular version) take a % m and b % m wherever you multiply.
         WHY: (a*b)%m = ((a%m)*(b%m))%m keeps the numbers below m^2 so `long long`
         never overflows, even for exponents like 1000000007.

 VISUAL WALKTHROUGH: (ASCII showing 3^13 = (3^8)(3^4)(3^1) from bits 1101)

          13 in binary = 1 1 0 1
                        ↓ ↓ ↓
      3^8    3^4    3^0?  3^1   <- only set-bits survive
      │      │            │
    (3^8) × (3^4) × (3^1) = 3^(8+4+1) = 3^13
      │          │        │
     6561    ×   81   ×   3  =  1594323

     11 01  ← bit order, LSB on the right
     ^^ ^
     3^8 3^4 3^1   (bit=0 contributes 3^0 = 1, i.e. skipped)

 DRY RUN: (line-by-line trace of iterative bits for 3^13: exp=13, base=3, result=1)
   (13 in binary = 1101; we read from the RIGHT; base always squares)

   exp  base  base_value  exp&1?    action                     result
   ─────────────────────────────────────────────────────────────────────
   13   3     (3^1)       1 (1)     result *= 3   → 1 * 3         3
   6    9     (3^2)       0 (0)     square only                  3
   3    81    (3^4)       1 (1)     result *= 81  → 3 * 81      243
   1    6561  (3^8)       1 (1)     result *= 6561→ 243*6561  1594323
   0    -     -           0         exp==0 → STOP
   ─────────────────────────────────────────────────────────────────────
   result = 3*81*6561 = 1594323 = 3^13 ✓   (only 4 iterations, not 13)

 TIME COMPLEXITY CALCULATION:
 - Exponent b gets halved every iteration: b → floor(b/2) → ... → 0.
   After k iterations: b/2^k = 1  (last positive value)
   → b = 2^k  →  k = log2(b).  So the loop runs log2(b)+1 ≈ log2(b) times.
 - Each iteration does O(1) work: one `&`, one multiply (maybe), one square,
   one halving. Total = O(log2(b)) multiplications.
 - Naive loop multiplies b times: x * x * ... * x  →  O(b).
 → Time Complexity = O(log b)   vs   naive power  O(b)
   (recursive halving uses the same O(log b): T(n)=T(n/2)+O(1) → O(log b))

 SPACE COMPLEXITY CALCULATION:
 - Iterative (and modular) version keeps only `result`, `base`, `exp` → O(1).
 - Recursive version: T(n)=T(n/2)+O(1) creates one stack frame per halving step,
   and there are log2(b) steps → O(log b) call stack.
 → Space Complexity = O(1) iterative | O(log b) recursive

 APPROACH COMPARISON:
 ┌──────────────────┬─────────────┬──────────────┬──────────────┬──────────────┐
 │ Approach         │ Complexity  │ Overflow?    │ Modular?     │ Best for     │
 ├──────────────────┼─────────────┼──────────────┼──────────────┼──────────────┤
 │ Naive loop       │ O(b)        │ easy (big b) │ add %m       │ learning     │
 │ Recursive halve  │ O(log b)    │ easy          │ yes (same)   │ intuition    │
 │ Iterative bits   │ O(log b)    │ has mod safe  │ yes          │ production   │
 │ Modular fast pow │ O(log b)    │ safe w/ long  │ YES (main)   │ crypto/CP    │
 └──────────────────┴─────────────┴──────────────┴──────────────┴──────────────┘

 EDGE CASES:
 - exponent 0:  a^0 = 1 for any a (loop never multiplies, result stays 1).
 - exponent 1:  a^1 = a (single LSB bit=1 → result = base).
 - base 0:      0^k = 0 for k>0, and 0^0 is undefined (C++ gives 1).
 - negative exponent (a^-b) is a fraction 1/(a^b) — our loop only accepts
   non-negative b; handle sign separately with a double, or error out.

 CODE BELOW — compiles with C++17: g++ 01_theory.cpp -o theory
*/

#include <iostream>
using namespace std;

typedef long long ll;

// ---------- NAIVE: O(b) multiply loop (only for small b) ----------
ll naivePow(ll base, ll exp) {
    ll res = 1;
    for (ll i = 1; i <= exp; i++) res *= base;   // b multiply hote hain (slow)
    return res;
}

// ---------- RECURSIVE: O(log b), halving identity ----------
ll recPow(ll base, ll exp) {
    if (exp == 0) return 1;                       // base case: koi bhi ^0 = 1
    ll x = recPow(base, exp / 2);                 // half compute karo (n/2)
    ll y = x * x;                                 // (x^(n/2))^2
    if (exp % 2 == 1) y *= base;                  // odd ho to extra base se multiply
    return y;
}

// ---------- ITERATIVE BITS (LSB-first): O(log b), answer milta hai ----------
ll fastPow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;                 // bit set => multiply base
        base *= base;                             // har step pe base square karo
        exp >>= 1;                                // next bit pe jao (exp/2)
    }
    return res;
}

// ---------- MODULAR FAST POWER: koi overflow nahi (long long safe) ----------
ll modPow(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    base %= mod;                                  // pehle base ko mod kar lo
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;    // (a*b)%m = ((a%m)*(b%m))%m
        base = (base * base) % mod;               // square bhi mod mein rahe
        exp >>= 1;
    }
    return res;
}

// ---------- recursive trace for 3^13, har step print karta hai ----------
ll recPowTrace(ll base, ll exp, int depth) {
    cout << string(depth*2, ' ') << "call(" << base << "^" << exp << ")" << endl;
    if (exp == 0) { cout << string(depth*2, ' ') << "return 1" << endl; return 1; }
    ll half = recPowTrace(base, exp / 2, depth + 1);   // pehle half bulao
    ll res = half * half;                               // phir square karo
    if (exp & 1) { res *= base; cout << string(depth*2, ' ') << "odd -> extra *" << base << " -> " << res << endl; }
    else         { cout << string(depth*2, ' ') << "even -> square = " << res << endl; }
    cout << string(depth*2, ' ') << "return " << res << endl;
    return res;
}

int main() {
    // 1) naive vs fast — chhote values par same answer (proof of correctness)
    cout << "=== 1) SMALL VALUES: naive vs fast (same result hone chahiye) ===\n";
    for (ll b = 3; b <= 5; b++) {
        cout << "  2^" << b << ": naive=" << naivePow(2, b)
             << "  fast=" << fastPow(2, b)
             << "  rec=" << recPow(2, b) << "\n";
    }

    // 2) recursive trace for 3^13 — pura call tree dikhata hai
    cout << "\n=== 2) RECURSIVE TRACE for 3^13 ===\n";
    cout << "3^13 = " << recPowTrace(3, 13, 1) << "\n";

    // 3) iterative bits version result
    cout << "\n=== 3) ITERATIVE BITS: 3^13 (bits 1101 -> set bits 1,4,8) ===\n";
    cout << "3^13 = " << fastPow(3, 13) << "\n";

    // 4) huge mod power: 3^1000000007 % (1e9+7) — naive kabhi nahi, fast O(log b)
    cout << "\n=== 4) HUGE MOD POWER: 3^1000000007 % 1'000'000'007 ===\n";
    const ll MOD = 1000000007LL;
    cout << "fast  : " << modPow(3, 1000000007LL, MOD) << "\n";

    // 5) naive comparison — sirf chhota exponent (3^10), kyunki bada ho to hang ho jayega
    cout << "\n=== 5) NAIVE (SMALL ONLY) vs FAST: 3^10 ===\n";
    ll v1 = naivePow(3, 10);
    ll v2 = fastPow(3, 10);
    cout << "naive 3^10 = " << v1 << "\nfast  3^10 = " << v2 << "\n";
    cout << (v1 == v2 ? "same ✓" : "MISMATCH ✗") << "\n";

    // 6) edge cases
    cout << "\n=== 6) EDGE CASES ===\n";
    cout << "5^0  = " << fastPow(5, 0)   << "   (exponent 0 → 1)\n";
    cout << "7^1  = " << fastPow(7, 1)   << "   (exponent 1 → base)\n";
    cout << "0^5  = " << fastPow(0, 5)   << "   (base 0 → 0)\n";
    cout << "0^0  = " << fastPow(0, 0)   << "   (undefined in math; C++ loop gives 1)\n";
    cout << "NOTE: negative exponent like 3^-2 = 1/(3^2) fraction hota hai,\n"
            "      isliye loop me exp negative nahi dena — sign alag handle karo.\n";
    return 0;
}