/*
═══════════════════════════════════════════════
 TASK SET — NUMBER THEORY
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Your online payment is validated by RSA: the server multiplies two giant primes
 and your browser must run primality tests, factorization and gcd/lcm millions of
 times while the page loads. These 7 tasks are the exact building-blocks behind
 every https lock, hash table, and passcode system.

 🧠 HOW TO SOLVE:
 First decide WHICH tool each task needs — a √n loop for a single primality test,
 a sieve for "all primes up to / inside a range", Euclid for gcd (then the lcm
 formula), a pair-loop for divisors, and trial division for factorization. Second,
 guard 0, 1 and negatives before any loop. Third, verify your answer on the small
 sample printed in each task.

 ═══════════════════════════════════════════════
 TASK 1 (EASY) — COUNT DIVISORS
   Given n = 12, return how many divisors it has (expected 6: 1,2,3,4,6,12).
   💡 HINT: every d with n % d == 0 is a divisor. Loop d = 1..n and count.
     Later you can upgrade to the √n pair-loop, but the naive loop is fine here.
   ✏️ STARTER CODE:
     int countDivisors(int n) {
         // loop d = 1..n, count d where n % d == 0
     }

 ═══════════════════════════════════════════════
 TASK 2 (EASY) — IS PRIME (sqrt + WHY)
   Decide if 97 is prime using a loop that stops at i*i <= n.
   💡 HINT: if n were composite, n = a*b with BOTH a,b > √n is impossible —
     so one factor is always <= √n. Only test i = 2..√n (write i <= n/i).
   ✏️ STARTER CODE:
     bool isPrime(int n) {
         // n < 2 -> false; loop i = 2 while i <= n/i
     }

 ═══════════════════════════════════════════════
 TASK 3 (EASY) — LCM OF 4 AND 6
   Return lcm(4,6); expected 12.
   💡 HINT: lcm(a,b) = a / gcd(a,b) * b. Write Euclid gcd first, then one line.
   ✏️ STARTER CODE:
     int lcm(int a, int b) {
         // return a / gcd(a,b) * b;   (write gcd first)
     }

 ═══════════════════════════════════════════════
 TASK 4 (MEDIUM) — PRINT PRIMES ≤ n VIA SIEVE
   Print every prime up to n = 30.
   💡 HINT: keep a composite[] bool vector; for p = 2 while p*p <= n, if p is not
     marked, mark p*p, p*p+p, ... . Finally print all unmarked i >= 2.
   ✏️ STARTER CODE:
     void printPrimes(int n) {
         // vector<bool> composite(n+1, false); mark multiples from p*p
     }

 ═══════════════════════════════════════════════
 TASK 5 (MEDIUM) — GCD OF AN ARRAY
   Given {12, 18, 24}, return 6.
   💡 HINT: gcd over an array is a left-to-right reduction: g = gcd(g, next).
     gcd(12,18) = 6, then gcd(6,24) = 6.
   ✏️ STARTER CODE:
     int gcdArray(vector<int> v) {
         // g = v[0]; for each x in v[1..] : g = gcd(g, x)
     }

 ═══════════════════════════════════════════════
 TASK 6 (MEDIUM) — COUNT PRIMES IN RANGE [lo, hi]
   Count primes between 10 and 50 (expected 11: 11,13,17,19,23,29,31,37,41,43,47).
   💡 HINT: build the sieve ONCE up to hi, then count unmarked i in [lo, hi].
     Do not re-test every number individually.
   ✏️ STARTER CODE:
     int countPrimesInRange(int lo, int hi) {
         // sieve up to hi; count i in [lo,hi] with !composite[i]
     }

 ═══════════════════════════════════════════════
 TASK 7 (HARD) — PRIME FACTORIZATION COUNT
   Count the prime factors of 84 counting multiplicity: 84 = 2*2*3*7  →  4.
   💡 HINT: strip 2 first, then odd factors f while f*f <= n, counting each
     division; whatever is left with n > 1 is one more prime factor.
   ✏️ STARTER CODE:
     int countPrimeFactors(int n) {
         // strip 2s, strip odd f, count each division; also count leftover > 1
     }
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
// Niche har task ka full solved code + hinglish me samjhaaya gaya hai.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TASK 1 — count divisors (naive O(n))
int countDivisors(int n) {
    if (n <= 0) return 0;              // 0 / negative ke divisors undefined hain
    int cnt = 0;
    for (int d = 1; d <= n; ++d)       // har candidate divisor try karo
        if (n % d == 0) ++cnt;         // d divides n => count badhao
    return cnt;
}
// n=12: d=1,2,3,4,6,12 divide karte hain => 6. O(n) kyunki 1..n tak loop.

// helper — Euclid gcd (iterative), Tasks 3 aur 5 ke liye
int gcd(int a, int b) {
    while (b != 0) {                   // jab tak remainder bacha hai
        int temp = b;
        b = a % b;                     // gcd(a,b) = gcd(b, a%b)
        a = temp;
    }
    return a;
}

// TASK 2 — is prime with sqrt gate
bool isPrime(int n) {
    if (n < 2) return false;           // 0, 1 aur negatives prime nahi hote
    for (int i = 2; i <= n / i; ++i)   // i*i <= n likhne ke bajaye n/i => overflow safe
        if (n % i == 0) return false;  // koi factor mila => composite
    return true;                       // nahi mila => prime
}
// WHY sqrt: factors pairs mein aate hain (a*b = n) aur dono √n se bade nahi ho sakte,
// isliye sirf i = 2..√n check karna kaafi hai => O(√n).

// TASK 3 — lcm via gcd formula
int lcm(int a, int b) {
    return a / gcd(a, b) * b;          // pehle divide => overflow nahi hoga
}
// lcm(4,6): gcd(4,6)=2, 4/2*6 = 12. ✓

// TASK 4 helper — sieve
vector<bool> buildSieve(int n) {
    vector<bool> composite(n + 1, false);      // shuru mein sab prime maante hain
    for (int p = 2; p * p <= n; ++p) {
        if (!composite[p]) {                   // p prime hai (marked nahi ab tak)
            for (int j = p * p; j <= n; j += p)
                composite[j] = true;           // multiples ko composite mark karo
        }
    }
    return composite;
}

// TASK 4 — print all primes <= n
void printPrimes(int n) {
    vector<bool> c = buildSieve(n);
    for (int i = 2; i <= n; ++i)
        if (!c[i]) cout << i << " ";           // unmarked = prime
    cout << endl;
}

// TASK 5 — gcd of array (left-to-right reduction)
int gcdArray(const vector<int>& v) {
    if (v.empty()) return 0;           // safety guard
    int g = v[0];
    for (size_t i = 1; i < v.size(); ++i)
        g = gcd(g, v[i]);              // baari-baari gcd update karo
    return g;
}
// {12,18,24}: gcd(12,18)=6, gcd(6,24)=6. ✓

// TASK 6 — count primes in [lo, hi] using one sieve
int countPrimesInRange(int lo, int hi) {
    vector<bool> c = buildSieve(hi);   // ek hi sieve sab range ka kaam karegi
    int cnt = 0;
    for (int i = max(2, lo); i <= hi; ++i)
        if (!c[i]) ++cnt;
    return cnt;
}

// TASK 7 — count prime factors with multiplicity
int countPrimeFactors(int n) {
    if (n <= 1) return 0;              // 0/1 ke koi prime factors nahi
    int cnt = 0;
    while (n % 2 == 0) { ++cnt; n /= 2; }     // saari 2 ki powers factor karo
    for (int f = 3; f <= n / f; f += 2) {     // odd factors hi => aadha kaam
        while (n % f == 0) { ++cnt; n /= f; }
    }
    if (n > 1) ++cnt;                          // bacha hua n prime factor hai
    return cnt;
}
// 84: 2(1), 2(2) -> n=21; f=3 -> 3(3), n=7; f=5 -> 5*5<=7 nahi ruk jaao; n=7>1 => (4). ✓

int main() {
    cout << "T1 countDivisors(12)              = " << countDivisors(12) << "   (expect 6)\n";
    cout << "T2 isPrime(97) = " << isPrime(97) << ", isPrime(91) = " << isPrime(91)
         << "   (expect 1, 0)\n";
    cout << "T3 lcm(4,6)                       = " << lcm(4, 6) << "   (expect 12)\n";
    cout << "T4 primes <= 30 : ";
    printPrimes(30);
    cout << "T5 gcdArray({12,18,24})           = " << gcdArray({12, 18, 24}) << "   (expect 6)\n";
    cout << "T6 countPrimesInRange(10,50)      = " << countPrimesInRange(10, 50)
         << "   (expect 11)\n";
    cout << "T7 countPrimeFactors(84)          = " << countPrimeFactors(84)
         << "   (84 = 2*2*3*7 => 4)\n";
    return 0;
}