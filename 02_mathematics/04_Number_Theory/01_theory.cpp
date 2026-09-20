/*
═══════════════════════════════════════════════
 NUMBER THEORY — Prime Check, Sieve, GCD/LCM, Divisors, Factorization, Modular Arithmetic
 ⏱️ TIME COMPLEXITY: each algorithm fully derived in the TIME COMPLEXITY
    CALCULATION section below — NEVER a bare O(?).
───────────────────────────────────────────────
  prime check (naive)     : O(n)
  prime check (√n)        : O(√n)
  Sieve of Eratosthenes   : O(n log log n)     (derived: Σ n/p over primes = n log log n)
  GCD naive               : O(min(a,b))
  GCD Euclid rec / iter   : O(log min(a,b))
  LCM via gcd formula     : O(log min(a,b))
  Divisors naive          : O(n)
  Divisors pair loop      : O(√n)
  Prime factorization     : O(√n) worst
  Modular ops (+,-,*)     : O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You are the Security Officer of a digital kingdom. Every encrypted message,
 every login, and every online purchase is guarded by locks built from prime
 numbers — split a giant product back into its two prime factors and you can
 open any of them. The attacker's entire game reduces to "is this huge number
 prime?" and "what are its factors?". If that check tries every number up to n,
 the kingdom crawls; if it stops at √n, marks multiples once with a sieve, and
 runs Euclid for gcd, everything stays instant. Banks, chat apps, and every
 https:// page you open are fast precisely because these number-theory shortcuts
 let software test millions of numbers per second.

 📖 THEORY (pure English, beginner-level):

 1) PRIME CHECK
    A number n > 1 is PRIME when its only positive divisors are 1 and n. 0 and 1
    are NOT prime; 2 is the only even prime (every larger even number divides by
    2). KEY FACT: if n = a·b, we cannot have BOTH a > √n and b > √n, because
    then a·b > √n·√n = n. So every factor pair contains at least one member ≤ √n.
    That single fact turns a naive scan O(n) into a scan up to √n: O(√n).

 2) SIEVE OF ERATOSTHENES   (ASCII, up to 25)
       2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
       P   P   X   P   X   P   X   X   X   P   X   P   X   X   X   P   X   P   X   X   X   P   X   X
       i=2 marks 4,6,8,10,12,14,16,18,20,22,24
       i=3 marks 9,12,15,18,21,24         (3*3 onwards; 3*2=6 already marked by 2)
       i=5 marks 25
       survivors never marked = primes: 2 3 5 7 11 13 17 19 23
    Rule: start marking from i*i, because 2i, 3i, ..., (i-1)·i were already
    crossed out by smaller prime factors.

 3) GCD — EUCLID
    gcd(a,b) = the largest d that divides both a and b. Euclid's rule:
    gcd(a,b) = gcd(b, a%b). Proof sketch: if d | a and d | b then d | (a − b·q)
    = a%b. Conversely, if d | b and d | a%b then d | (b·q + a%b) = a. The two
    numbers share exactly the same divisor set, so the gcd is unchanged. When
    the remainder becomes 0, gcd(x,0) = x and we stop.
       gcd(48,36): 48 = 36·1 + 12  →  gcd(36,12)
       gcd(36,12): 36 = 12·3 +  0  →  gcd(12,0) = 12

 4) LCM
    lcm(a,b) = a / gcd(a,b) * b — divide FIRST so the product cannot overflow.
    WHY: a·b counts the shared prime powers twice; dividing by gcd removes the
    overlap, leaving the lowest common multiple.

 5) DIVISORS   (√n pair loop)
    If d | n then n/d | n as well, so divisors come in pairs (d, n/d), and at
    least one member of every pair is ≤ √n. Loop d = 1..√n and print both.
        36 → (1,36) (2,18) (3,12) (4,9) (6,6)  — stop at d = 6 = √36.

 6) PRIME FACTORIZATION (trial division)
    Repeatedly strip the smallest prime factor; any leftover n > 1 is itself prime.
        84 → 84/2=42 → 42/2=21 → 21/3=7 → 7  ⇒  84 = 2²·3·7

 7) MODULAR ARITHMETIC
    (a+b)%m = (a%m + b%m)%m ; (a·b)%m = (a%m · b%m)%m ; (a−b)%m = (a%m − b%m + m)%m.
    C++ % returns negative results for negative operands ((-3)%7 == −3), so for
    subtraction we add m once (+m) and take %m again to force the answer into
    0..m-1.

 WHEN TO USE: "is it prime?", "list all primes ≤ n", "gcd/lcm", "count or list
    divisors", "factorize", "keep huge numbers small under a modulus". These
    helpers power RSA/crypto, hashing, scheduler math and data-structure sizing.

 🧠 LOGIC — STEP BY STEP (pure English):

 isPrimeNaive(n):
  Step 1: if n < 2 → return false. WHY: 0 and 1 are not prime; negatives neither.
  Step 2: for i = 2 .. n/2 : if n % i == 0 → false. WHY: a single divisor proves
          composite; scanning every candidate is bullet-proof but O(n).
  Step 3: return true. WHY: nothing divided n, so it is prime.

 isPrimeSqrt(n):
  Step 1: if n < 2 → return false. WHY: same edge-case guard.
  Step 2: for i = 2 while i ≤ n/i : if n % i == 0 → false. WHY: a factor must sit
          in a pair (a,b) with a·b = n, and one of a,b is ≤ √n (both > √n is
          impossible). Probing up to √n is therefore enough; writing i ≤ n/i
          avoids i*i overflow on big ints.
  Step 3: return true. WHY: no factor ≤ √n implies no factor at all.

 sieve(n):
  Step 1: composite[0..n] = false. WHY: optimistically call everything prime.
  Step 2: for i = 2 while i*i ≤ n : if !composite[i] → mark i*i, i*i+i, ... .
          WHY: an unmarked i was never a multiple of any smaller prime ⇒ prime;
          start at i*i because smaller multiples are already marked.
  Step 3: return all i ≥ 2 still unmarked. WHY: the sieve crosses every composite
          exactly via its smallest prime factor, so unmarked = prime.

 gcdNaive(a,b):
  Step 1: best = 1. WHY: 1 divides every integer.
  Step 2: for d = 1 .. min(a,b) : if a%d==0 && b%d==0 → best = d. WHY: keep the
          largest common divisor encountered while scanning every candidate.
  Step 3: return best. WHY: the largest recorded common divisor is the gcd.
          Cost O(min(a,b)) — fine for small numbers only.

 gcdEuclid(a,b):  (recursive)
  Step 1: if b == 0 → return a. WHY: gcd(x,0) = x, since 0 is divisible by every d.
  Step 2: else return gcdEuclid(b, a%b). WHY: the divisor set of (a,b) equals the
          divisor set of (b,a%b) (proved above), so the gcd is preserved while
          the numbers shrink drastically — each new value is < b.

 gcdIterative(a,b):
  Step 1: while b != 0 : temp=b; b=a%b; a=temp. WHY: exactly the recursion above
          unrolled into a loop — no call stack, identical O(log min) steps.
  Step 2: return a. WHY: the final remainder was 0, so a holds the gcd.

 lcm(a,b):
  Step 1: return a / gcdIterative(a,b) * b. WHY: a·b counts shared prime powers
          twice; dividing by gcd removes the double-count; divide before
          multiplying to avoid integer overflow.

 printDivisorsNaive(n): for d = 1..n print d if n%d==0. WHY: definition applied
    directly — correct but O(n).
 printDivisorsPair(n):  for d = 1 while d*d ≤ n : if n%d==0 print d, and also
    n/d when d != n/d. WHY: divisors pair as (d, n/d); scanning to √n catches
    every pair exactly once, halving the work.

 primeFactors(n):
  Step 1: while n%2==0 → print 2, n /= 2. WHY: 2 is the smallest possible factor;
          strip all powers of two first.
  Step 2: for f = 3 while f ≤ n/f, step +2 : while n%f==0 → print f, n /= f.
          WHY: after step 1, n is odd, so only odd factors remain; the f ≤ n/f
          gate is the √n rule again — a composite leftover has a factor ≤ √n.
  Step 3: if n > 1 → print n. WHY: nothing divided it up to its √n, so the
          leftover is itself prime.

 modAdd(a,b,m): ((a%m) + (b%m)) % m.
 modMul(a,b,m): ((a%m) * (b%m)) % m.
 modSub(a,b,m): (((a%m) − (b%m)) % m + m) % m.
  WHY: reduce operands first so intermediate values stay tiny; for subtraction
  C++ % may be negative (-3%7 == −3), so add m once then %m to land in 0..m-1.

 VISUAL WALKTHROUGH (ASCII):

 (1) Sieve up to 30 — every composite crossed exactly once:
      i=2  →  marks  4  6  8 10 12 14 16 18 20 22 24 26 28 30
      i=3  →  marks  9 12 15 18 21 24 27 30
      i=5  →  marks 25 30
      unmarked (primes): 2 3 5 7 11 13 17 19 23 29
      2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30
      P   P   X   P   X   P   X   X   X   P   X   P   X   X   X   P   X   P   X   X   X   P   X   X   X   X   X   P   X

 (2) Euclid chain for gcd(48,36):
      48 % 36 = 12   ──>   gcd(48,36)  ==>  gcd(36,12)
      36 % 12 =  0   ──>   gcd(36,12)  ==>  gcd(12,0) = 12   ✓

 (3) Divisor pairs of 36 (√36 = 6):
      d:      1    2    3    4    5    6       7..36 all mirrored → STOP
      pair: (1,36) (2,18) (3,12) (4,9)   –    (6,6)
      print →  1 36 | 2 18 | 3 12 | 4 9 | 6

 DRY RUN — gcd(48,36), all three versions:

  NAIVE: best = 1; test d = 1..12 (= min(48,36))
    d=1 ✓→best=1 | d=2 ✓→2 | d=3 ✓→3 | d=4 ✓→4 | d=5 ✗ | d=6 ✓→6 | d=12 ✓→12
    → answer 12   (12 iterations)
  RECURSIVE EUCLID:
    gcd(48,36): b=36≠0 → gcd(36, 48%36=12)
    gcd(36,12): b=12≠0 → gcd(12, 36%12=0)
    gcd(12,0):  b=0    → return 12     (3 calls!)
  ITERATIVE EUCLID:
    a=48,b=36 → b=36%12... wait: temp=36, b=48%36=12, a=36
    a=36,b=12 → temp=12, b=36%12=0,  a=12  → loop ends → return 12.

  WHY so few steps? Each remainder a%b is strictly smaller than b, and the pair
  roughly halves every two steps (worst case = consecutive Fibonacci numbers),
  so gcd needs only O(log min(a,b)) ≈ 3 steps for 48.

 TIME COMPLEXITY CALCULATION:
 - naive prime: the loop reaches n/2, i.e. ~n operations → O(n).
 - √n prime: i runs while i ≤ n/i, i.e. i² ≤ n → √n iterations → O(√n).
   Derivation of the √n gate: factors of n come in pairs (a,b) with a·b = n.
   If BOTH a > √n and b > √n then a·b > n — contradiction. Hence at least one
   factor is ≤ √n, so a divisor search can legally stop at √n.
 - sieve: for each prime p ≤ n we mark n/p multiples. Total marks =
   n/2 + n/3 + n/5 + n/7 + ... = n · (Σ 1/p over primes p ≤ n). The sum of the
   reciprocals of primes up to n grows like log log n (Mertens' theorem), so
   sieving costs O(n log log n); adding the O(n) initialization keeps O(n log log n).
 - gcd naive: scans 1..min(a,b) → O(min(a,b)).
 - gcd Euclid: each step sends (a,b) → (b, a%b); the new value is < b and in the
   worst case (Fibonacci-number inputs) the sizes halve every two steps →
   O(log min(a,b)) iterations; the recursive version adds O(1) work per step.
 - lcm: one Euclid gcd + one multiply-divide → O(log min(a,b)).
 - divisors naive: loop 1..n → O(n). divisors pair loop: d*d ≤ n → O(√n).
 - factorization trial division: after stripping 2 first, the loop tests odd f
   while f ≤ n/f → worst O(√n) (when n is prime); left-over n>1 is prime.
 - modular +, −, * on two ints: constant work → O(1).
 → Time Complexity =  O(√n)         for prime check / divisors / factorization
                     O(n log log n) for the sieve
                     O(log min(a,b)) for Euclid gcd (and lcm)
                     O(n) / O(min)  only if naive scans are chosen.

 SPACE COMPLEXITY CALCULATION:
 - sieve: one bool array of size n+1 → O(n).
 - recursive Euclid: the call depth is ≤ the number of Euclid steps,
   O(log min(a,b)) stack frames → O(log min(a,b)).
 - iterative Euclid, naive gcd, prime checks, divisors, factorization, modular
   helpers, lcm: only a few ints live at a time → O(1).
 → Space Complexity = O(n) for the sieve; O(1) for almost everything else
                      (recursive Euclid's stack: O(log min(a,b))).

 APPROACH COMPARISON:
 ┌──────────────────┬────────────────────────────┬────────────────────────────────┬────────────────────────────┐
 │ Task             │ Naive                      │ Fast                           │ Why it wins                │
 ├──────────────────┼────────────────────────────┼────────────────────────────────┼────────────────────────────┤
 │ isPrime(n)       │ test i = 2..n       O(n)   │ test i = 2..√n      O(√n)      │ factor pair (a·b=n) has    │
 │                  │                            │                                │ one member ≤ √n            │
 │ all primes ≤ n   │ re-test every number O(n√n)│ sieve, cross from p² O(n loglogn)│ each composite marked once │
 │ gcd(a,b)         │ try every d=1..min  O(min) │ Euclid a%b chain    O(log min) │ remainder < b, halves     │
 │                  │                            │                                │ every ~2 steps             │
 │ divisors of n    │ loop d = 1..n       O(n)   │ pairs d, n/d to √n   O(√n)     │ mirror pair found together │
 │ factorize n      │ try every d = 2..n  O(n)   │ trial division to √n  O(√n)    │ leftover n>1 is prime;     │
 │                  │                            │                                │ small primes stripped first│
 └──────────────────┴────────────────────────────┴────────────────────────────────┴────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

// ==== PRIME CHECK: naive (O(n)) vs sqrt (O(sqrt n)) ====
bool isPrimeNaive(int n) {
    if (n < 2) return false;                 // 0, 1, negative prime nahi hote
    for (int i = 2; i <= n / 2; ++i)         // saare candidates try -> O(n)
        if (n % i == 0) return false;        // ek divisor mil gaya => composite
    return true;                             // koi divisor nahi => prime
}

bool isPrimeSqrt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; ++i)         // sirf sqrt tak; i <= n/i overflow se bachata hai
        if (n % i == 0) return false;        // pair (a,b) mein se ek factor <= sqrt(n)
    return true;
}

// ==== SIEVE OF ERATOSTHENES ====
vector<bool> sieve(int n) {
    vector<bool> composite(n + 1, false);    // shuru mein sab prime assume karo
    for (int i = 2; i * i <= n; ++i) {
        if (!composite[i]) {                 // i kisi chote prime ka multiple nahi => prime
            for (int j = i * i; j <= n; j += i)
                composite[j] = true;         // multiples composite mark karo (i*i se shuru)
        }
    }
    return composite;
}

// ==== GCD: naive + Euclid (recursive) + Euclid (iterative) ====
int gcdNaive(int a, int b) {
    a = abs(a); b = abs(b);                  // gcd negative ke liye magnitude use karo
    int best = 1;
    for (int d = 1; d <= min(a, b); ++d)     // har candidate try -> O(min)
        if (a % d == 0 && b % d == 0) best = d;  // dono divide => biggest jo mila
    return best;
}

int gcdEuclid(int a, int b) {
    a = abs(a); b = abs(b);
    if (b == 0) return a;                    // gcd(x,0) = x
    return gcdEuclid(b, a % b);              // gcd(a,b) = gcd(b, a%b) — proof upar
}

int gcdIterative(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {                         // recursion ko loop mein khol diya
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ==== LCM via gcd formula ====
int lcm(int a, int b) {
    return a / gcdIterative(a, b) * b;       // pehle divide => overflow ka khauf nahi
}

// ==== DIVISORS: naive (O(n)) vs pair loop (O(sqrt n)) ====
void printDivisorsNaive(int n) {
    for (int d = 1; d <= n; ++d)             // 1..n sab check -> O(n)
        if (n % d == 0) cout << d << " ";
    cout << endl;
}

void printDivisorsPair(int n) {
    for (int d = 1; d * d <= n; ++d) {       // sirf sqrt tak -> O(sqrt n)
        if (n % d == 0) {
            cout << d << " ";
            if (d != n / d) cout << n / d << " "; // mirror pair bhi print, duplicate na chhape
        }
    }
    cout << "   (note: sorted nahi, paar-wise order hai)" << endl;
}

// ==== PRIME FACTORIZATION (trial division) ====
void primeFactors(int n) {
    while (n % 2 == 0) { cout << 2 << " "; n /= 2; }   // saari 2 ki powers pehle
    for (int f = 3; f <= n / f; f += 2) {              // odd factors hi check -> aadha kaam
        while (n % f == 0) { cout << f << " "; n /= f; }
    }
    if (n > 1) cout << n << " ";                       // bacha hua bada factor prime hai
    cout << endl;
}

// ==== MODULAR ARITHMETIC (negative-safe, m = 7) ====
int modAdd(int a, int b, int m) { return ((a % m) + (b % m)) % m; }                    // (a+b) % m
int modMul(int a, int b, int m) { return ((a % m) * (b % m)) % m; }                    // (a*b) % m
int modSub(int a, int b, int m) { return (((a % m) - (b % m)) % m + m) % m; }          // +m => negative remainder fix

int main() {
    cout << "====== 1) PRIME CHECK (naive vs sqrt) | edge cases: 0, 1, negative ======\n";
    int nums[] = {0, 1, 2, 3, 4, 13, 25, 37, 97, -7};
    cout << setw(4) << "n" << setw(10) << "naive" << setw(10) << "sqrt\n";
    for (int n : nums)
        cout << setw(4) << n
             << setw(10) << (isPrimeNaive(n) ? "prime" : "not-prime")
             << setw(10) << (isPrimeSqrt(n) ? "prime" : "not-prime") << "\n";

    cout << "\n====== 2) SIEVE OF ERATOSTHENES up to 50 (marked boolean state) ======\n";
    const int N = 50;
    vector<bool> comp = sieve(N);
    cout << "      ";
    for (int i = 0; i <= N; ++i) cout << setw(3) << i;
    cout << "\nmask  ";
    for (int i = 0; i <= N; ++i) cout << setw(3) << (i < 2 ? '-' : (comp[i] ? 'X' : 'P'));
    cout << "\n   X = composite (marked), P = prime (unmarked), - = neither (0,1)\n";
    cout << "primes <= " << N << " : ";
    for (int i = 2; i <= N; ++i) if (!comp[i]) cout << i << " ";
    cout << "\n";

    cout << "\n====== 3) GCD (48, 36) — teeeno tareeke ======\n";
    cout << "gcdNaive    : " << gcdNaive(48, 36) << "\n";
    cout << "gcdEuclid   : " << gcdEuclid(48, 36) << "   (recursive)\n";
    cout << "gcdIterative: " << gcdIterative(48, 36) << "   (while loop)\n";

    cout << "\n====== 4) LCM via gcd formula ======\n";
    cout << "lcm(48,36) = " << lcm(48, 36) << "\n";

    cout << "\n====== 5) DIVISORS OF 36 — do loops ======\n";
    cout << "naive loop (1..36): "; printDivisorsNaive(36);
    cout << "pair  loop (1..6) : "; printDivisorsPair(36);

    cout << "\n====== 6) PRIME FACTORIZATION (trial division) ======\n";
    cout << "84 = "; primeFactors(84);

    cout << "\n====== 7) MODULAR ARITHMETIC (m = 7, negatives handled +m) ======\n";
    int a = 10, b = 20, m = 7;
    cout << "(10+20) % 7 = " << modAdd(a, b, m) << "   30 % 7 = 2\n";
    cout << "(10*20) % 7 = " << modMul(a, b, m) << "   200 % 7 = 4\n";
    cout << "(10-20) % 7 = " << modSub(a, b, m) << "   mathematically (-10) % 7 = 4\n";
    cout << "(20-10) % 7 = " << modSub(b, a, m) << "   10 % 7 = 3\n";
    cout << "C++ (-3) % 7 = " << (-3 % m) << "   => NEGATIVE (C++ ka behaviour)!\n";
    cout << "fixed ((-3%m)+m)%m = " << ((-3 % m) + m) % m << "   <= +m wala fix\n";
    return 0;
}