/*
═══════════════════════════════════════════════
 TASK SET — BINARY EXPONENTIATION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A password-hashing server must compute key^token mod p
   for 10^9-sized tokens. A naive b-time loop would take seconds; O(log b) fast
   power finishes in ~30 steps — that's the speed difference between a web login
   and a timeout.
🧠 HOW TO SOLVE: Remember 3 pillars — (1) square base each step, (2) multiply
   result only when the current exponent bit is 1, (3) halve exponent each loop.
   For modular questions, take %mod after every multiplication to stay small.
   Always verify complexity: b/2^k = 1 → k = log2(b) → O(log b).
 5 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE.
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;
typedef long long ll;

// ================= TASK 1 (EASY) =================
// TASK: Naive power loop for small exp — compute 4^6 using a simple multiply
//       loop, count how many multiplications the loop does.
// 💡 HINT: result start 1, loop exp times: result = result * base. Count = exp.
// ✏️ STARTER CODE:
//   ll naivePow(ll base, ll exp) {
//       ll res = 1;
//       ll mults = 0;
//       for (ll i = 0; i < exp; i++) { res *= base; mults++; }
//       cout << "multiplications used: " << mults << "\n";
//       return res;
//   }
ll naivePowTask1(ll base, ll exp) {
    ll res = 1;
    ll mults = 0;
    for (ll i = 0; i < exp; i++) { res *= base; mults++; }
    cout << "multiplications used: " << mults << "\n";
    return res;
}
// DERIVATION: loop b times, har iteration O(1) → O(b). b=6 to 6 multiply.
// EXPLANATION: 4^6 = 4*4*4*4*4*4 = 4096. Pehle 1*, then 6 baar base se guna.

// ================= TASK 2 (EASY-MEDIUM) =================
// TASK: Recursive halving power — code recPow(base, exp) using the identity
//       x^n = (x^(n/2))^2 for even, x * (x^(n/2))^2 for odd. Print trace for 2^10.
// 💡 HINT: base case exp==0 → 1. Compute half = power(base, exp/2) recursively,
//          then y = half*half; if odd multiply extra base once.
// ✏️ STARTER CODE:
//   ll recPow(ll base, ll exp) {
//       if (exp == 0) return 1;
//       ll half = recPow(base, exp / 2);
//       ll y = half * half;
//       if (exp % 2 == 1) y *= base;
//       return y;
//   }
ll recPow2(ll base, ll exp) {
    if (exp == 0) return 1;
    ll half = recPow2(base, exp / 2);
    ll y = half * half;
    if (exp % 2 == 1) y *= base;
    return y;
}
// DERIVATION: T(n) = T(n/2) + O(1). Solve: n/2^k = 1 → k = log2(n) → O(log n).
// EXPLANATION: 2^10 → 10 even → (2^5)^2; 2^5 odd → 2*(2^2)^2; levels: 10→5→2→1→0.

// ================= TASK 3 (MEDIUM) =================
// TASK: Iterative fast power — code fastPow(base, exp) reading exponent bits
//       LSB-first. Show trace table for 5^7 (7 = 111 binary).
// 💡 HINT: res=1; while exp: if (exp&1) res*=base; base*=base; exp>>=1.
//          Bits of 7 = 111 → ALL set → har step multiply hota hai.
// ✏️ STARTER CODE:
//   ll fastPow(ll base, ll exp) {
//       ll res = 1;
//       while (exp > 0) {
//           if (exp & 1) res *= base;
//           base *= base;
//           exp >>= 1;
//       }
//       return res;
//   }
ll fastPow3(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}
// TRACE for 5^7 (exp=111):
//   exp  base   bit  action          result
//   7    5      1    res*=5  →1*5      5
//   3    25     1    res*=25 →5*25   125
//   1    625    1    res*=625→125*625 78125
//   0    -      stop → 5^7 = 78125. Bits 4+2+1 = 7 ✓ (3 iterations, not 7).
// DERIVATION: exp halves per iteration → log2(7)+1 ≈ 3 steps → O(log exp).

// ================= TASK 4 (MEDIUM-HARD) =================
// TASK: Modular fast power — compute 5^100 % 13 using (a*b)%m = ((a%m)*(b%m))%m.
//       Use long long and taking %mod everywhere.
// 💡 HINT: res start 1 % mod, base %= mod first, then res=(res*base)%mod and
//          base=(base*base)%mod. Verify: 5^100 is enormous → MUST use mod in loop.
// ✏️ STARTER CODE:
//   ll modPow(ll base, ll exp, ll mod) {
//       ll res = 1;
//       base %= mod;
//       while (exp > 0) {
//           if (exp & 1) res = (res * base) % mod;
//           base = (base * base) % mod;
//           exp >>= 1;
//       }
//       return res;
//   }
ll modPow4(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
// DERIVATION: 100 = 64+32+4 = 1100100₂ (7 bits) → loop 7 iterations O(log 100).
//             5^100 is 70 digits — kabhi bhi direct na banaya jaye; har multiply
//             ke baad %13 karo, numbers hamesha < 13^2 = 169, overflow impossible.
// EXPLANATION: (a*b)%m same as ((a%m)*(b%m))%m — modular product property.

// ================= TASK 5 (HARD) =================
// TASK: Last digit of 7^2023 — since last digit = value % 10, compute
//       7^2023 % 10 with fast mod power. Derive the full answer.
// 💡 HINT: remainder mod 10 hi last digit hai. 7^1=7,7^2=49%10=9,7^3=343%10=3,
//          7^4=2401%10=1 — cycle 7,9,3,1 repeat. 2023 % 4 = 3 → same as 7^3 → 3.
//          Phir bhi fast power se check karo (agar zamana cycle na dikhe).
// ✏️ STARTER CODE:
//   ll lastDigit = modPow4(7, 2023, 10);   // bas yahi line chahiye
//   cout << lastDigit;                     // → 3
// DERIVATION: 2023 = 11111100111₂ (11 bits) → modPow runs 11 iterations O(log 2023).
//             7^2023 % 10 = 3 (kyunki 7^k cycle {7,9,3,1} aur 2023%4 = 3).
// EXPLANATION: kisi bhi number ka last digit = number % 10. Fast power se bada
//              exponent bhi microseconds me solve ho jata hai bina number banaye.

int main() {
    cout << "== TASK 1: 4^6 (naive loop) ==\n";
    cout << "4^6 = " << naivePowTask1(4, 6) << "\n\n";

    cout << "== TASK 2: 2^10 (recursive halving) ==\n";
    cout << "2^10 = " << recPow2(2, 10) << "\n\n";

    cout << "== TASK 3: 5^7 (iterative bits, 7=111) ==\n";
    cout << "5^7 = " << fastPow3(5, 7) << "\n\n";

    cout << "== TASK 4: 5^100 % 13 (modular fast power) ==\n";
    cout << "5^100 mod 13 = " << modPow4(5, 100, 13) << "\n\n";

    cout << "== TASK 5: last digit of 7^2023 (== 7^2023 mod 10) ==\n";
    ll last = modPow4(7, 2023, 10);
    cout << "7^2023 mod 10 = " << last
         << "   (cycle {7,9,3,1}: 2023 % 4 = 3, isliye 7^3 → 3) ✓\n";
    return 0;
}