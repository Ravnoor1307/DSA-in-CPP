/*
═══════════════════════════════════════════════
 MIXED MATH PROBLEMS — REVISION ALL-IN-ONE
 ⏱️ TIME COMPLEXITY: per-problem below. Combined best-case line:
     A: O(d)=O(log10 n); B: O(n log log n); C: O(n + log b). NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You have one last "mock interview" before the real one: the interviewer will
 fire 4 rapid-fire math puzzles — count digits, print primes, XOR finder, fast
 power — back to back. This is the mixed set: a kitchen timer (digit ops),
 a security key check (primes/gcd), a database recovery tool (XOR dedup), and
 an encryption exponent (fast power mod). Each uses old toolkit pieces but they
 must now work side by side, because in real interviews the trick is recognising
 WHICH tool fits WHICH problem in seconds.

 📖 THEORY: (pure English)
 - REVISION TOOLKIT TABLE (problem type → technique → complexity):
   | Problem          | Tool            | Time            | Space   |
   |------------------|-----------------|-----------------|---------|
   | digits           | %10 /10 loop    | O(d) = O(log n) | O(1)    |
   | reverse / sum    | extract digits  | O(d)            | O(1)    |
   | palindrome       | reverse compare | O(d)            | O(1)    |
   | primes ≤ n       | sieve           | O(n log log n)  | O(n)    |
   | gcd              | euclid          | O(log min)      | O(1)    |
   | lcm              | (a/g)*b         | O(log min)      | O(1)    |
   | single number    | XOR             | O(n)            | O(1)    |
   | a^b mod m        | fast pow        | O(log b)        | O(1)    |
   | nCr              | pascal / mult   | O(r) or O(R²)   | O(r)    |
   | power of 2       | n & (n-1)       | O(1)            | O(1)    |
   | digital root     | %9 formula      | O(d) or O(1)    | O(1)    |

 PROBLEM A — Given a large integer n, count its digits, sum the digits,
 reverse the digits and check whether n is a palindrome — all using one
 reusable digit-extraction routine.
 - real-world scenario (2-3 sentences): A billing system must verify credit-card
   numbers: it counts card digits (16), sums digits for checksum ("Luhn-like"),
   and a palindrome check is used in palindromic invoice-number prizes. One helper
   "pop last digit" serves all three checks.
 - LOGIC steps with WHY:
   1. Guard n = 0 → 1 digit, sum 0, reverse 0. WHY: the loop `while(n)` never runs.
   2. Take negative → work on |n| AND original sign does not affect digit arithmetic.
   3. Loop: pop last digit d = n % 10, drop it n /= 10. WHY: base-10 positional
      extraction; each pop removes the right-most place.
   4. Accumulate: digits++, sum += d, rev = rev*10 + d. WHY: building reverse as
      rev*10+d pushes the newest popped digit to the RIGHT, mirroring the input.
   5. Palindrome test: reversed number == original. WHY: a palindrome reads the
      same forwards and backwards so its reverse equals itself.
 - DRY RUN on n=12321:
   pop: d=1 → digit=1 sum=1 rev=1 | n=1232
   pop: d=2 → digit=2 sum=3 rev=12 | n=123
   pop: d=3 → digit=3 sum=6 rev=123 | n=12
   pop: d=2 → digit=4 sum=8 rev=1232 | n=1
   pop: d=1 → digit=5 sum=9 rev=12321 | n=0
   rev(12321)==12321 → PALINDROME ✓, digits=5, sum=9
   (contrast n=1234: rev=4321 ≠ 1234 → NOT palindrome)
 - TIME COMPLEXITY CALCULATION: full derivation. Each loop iteration removes one
   decimal digit. d = number of digits = floor(log10 n) + 1, so the loop runs d
   times with O(1) work each → O(d) = O(log10 n). For comparison, the digit count
   bound: numbers [10^(d-1), 10^d) all take exactly d pops.
 - SPACE: O(1) — only 3 running integers; no array, no string.

 PROBLEM B — Given n, (1) mark all primes ≤ n with a sieve and print them in
 order, (2) report the total count of primes ≤ n, and (3) independently compute
 the GCD of a whole array with Euclid's algorithm (a second number-theory tool).
 - real-world scenario: A network firewall releases a batch of n nodes only when
   their ID is prime (sieve), needs to know HOW MANY slots are whitelisted
   (count), and the firmware patch is shipped once the gcd of all version numbers
   equals the base version — two classic number-theory chores in one screen.
 - LOGIC + WHY:
   1. isComposite[l] = false for all, then isComposite[0]=isComposite[1]=true.
      WHY: 0,1 are not prime by definition.
   2. For p from 2 to √n, if still marked prime, mark p*p, p*p+p, ... composite.
      WHY: starting at p*p skips factors already handled by smaller primes; every
      composite ≤ n has a prime factor ≤ √n, so stopping at √n suffices.
   3. Collect primes in a vector in increasing p order → print + count.
   4. GCD: gcd(a,b) = b==0 ? a : gcd(b, a%b). WHY: Euclid — the gcd divides the
      remainder too; the remainder shrinks fast so the recursion is only O(log min).
 - DRY RUN on n=20 (sieve states, marking with p=2,3):
   initial: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
   p=2: mark 4,6,8,10,12,14,16,18,20 → 2 3 _ 5 _ 7 _ 9 _ 11 _ 13 _ 15 _ 17 _ 19 _
   p=3 (≤√20≈4.47): mark 9,15 (12,18 already done) → 2 3 _ 5 _ 7 _ _ _ 11 _ 13 _ _ _ 17 _ 19 _
   result: [2,3,5,7,11,13,17,19] → 8 primes, print them in order ✓
   gcd([12,18,24]): (12,18)→(18,12)→(12,6)→(6,0)→6
 - TIME: O(n log log n) derived: for each prime p ≤ √n we mark floor(n/p)−(p−1) ≈ n/p
   multiples, so total work Σ_{p≤√n} n/p ≈ n · Σ_{p≤√n} 1/p ≈ n · (ln ln √n + M)
   ≈ n log log n (Mertens). GCD recursion: each step a%b < a/2 → halves → O(log min).
 - SPACE: O(n) for the boolean sieve array; GCD itself is O(1).

 PROBLEM C — In an array where every number appears EXACTLY twice except ONE,
 find that single number using only XOR; then, separately, compute x^y mod m
 with binary fast power — two bit/binary tricks in one problem.
 - real-world scenario: A cloud backup stores file chunks; each chunk is written
   TWICE for safety, but one chunk was written once due to a crash. XOR recovers
   which chunk is missing in one pass with zero extra memory. Fast power mod backs
   RSA-style exponent c = m^e mod n: e has 2048 bits, so 2048 squarings beat
   2^2048 multiplications.
 - LOGIC + WHY (XOR properties: a^a=0, a^0=a, commutative/associative):
   running = 0; for each x: running ^= x. Every pair (a,a) cancels to 0 before the
   next element arrives; whatever remains is the unpaired number. WHY it works:
   XOR is its own inverse and order-independent, so all duplicates vanish.
   FAST POW: result = 1; while y>0: if y odd → result = result*x % m; x = x*x % m;
   y >>= 1. WHY: x^(2k+1) = x * (x²)^k splits off one x; each square doubles the
   exponent, so after ⌊log2 y⌋+1 iterations we have every power of two of the
   exponent consumed.
 - DRY RUN on {1,2,3,2,1}:
   running=0^1=1; 1^2=3; 3^3=0; 0^2=2; 2^1=3 → single = 3 ✓
   (Each duplicate pair 1^1=0, 2^2=0 cancelled inside the chain.)
   fastPow(2,5,1000): y=5odd r=2, x=4, y=2 | x=16, y=1 | y=1odd r=2*16=32, x=256, y=0 → 32 ✓
 - TIME: XOR pass visits all n elements once → O(n). Fast pow loops once per BIT of
   y → O(log2 y), each iteration constant time (two mults + one mod).
 - SPACE: O(1) — a single long long accumulator.

 APPROACH COMPARISON:
 ┌──────────────────────────────┬────────────────────────────┬────────────────┬───────────────┐
 │ Problem                      │ Best tool                 │ Time           │ Space         │
 ├──────────────────────────────┼────────────────────────────┼────────────────┼───────────────┤
 │ A digits/sum/reverse/palindr │ %10 /10 digit pop         │ O(log10 n)     │ O(1)          │
 │ B primes ≤ n + gcd of array  │ sieve + Euclid            │ O(n log log n) │ O(n)          │
 │ C single non-repeating + pow │ XOR + binary fast power   │ O(n + log y)   │ O(1)          │
 └──────────────────────────────┴────────────────────────────┴────────────────┴───────────────┘
 Morale: digit pops cost O(log n) not O(n); sieve is the only place we pay O(n)
 space; XOR and fast power are the champions of O(1) extra memory.
═══════════════════════════════════════════════
*/
// -------- CODE (3 problem solvers) --------
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ---------- PROBLEM A: digit ops on a big number ----------
struct DigitInfo {
    long long digits, digitSum, reverse;
};
// negative guard + n==0 guard: sirf |n| pe kaam karo
DigitInfo digitOps(long long n) {
    if (n < 0) n = -n;                       // sign ko ignore karo, digits same
    if (n == 0) return {1, 0, 0};            // 0 ki 1 digit, sum 0, reverse 0
    long long d = 0, sum = 0, rev = 0, t = n;
    while (t > 0) {                          // har iteration ek digit pop karta hai
        long long last = t % 10;
        sum += last;
        rev = rev * 10 + last;               // right side me push → reverse ban gaya
        d++;
        t /= 10;
    }
    return {d, sum, rev};
}
bool isPalindrome(long long n) {
    long long t = n < 0 ? -n : n;
    return t == digitOps(t).reverse;         // reverse == original ⇔ palindrome
}

// ---------- PROBLEM B: sieve primes ≤ n + count + gcd of array ----------
vector<int> sievePrimes(int n) {
    vector<bool> comp(n + 1, false);
    if (n >= 0) comp[0] = true;
    if (n >= 1) comp[1] = true;              // 0 aur 1 prime nahi hain
    int root = (int)sqrt((double)n);
    for (int p = 2; p <= root; p++) {
        if (!comp[p]) {                      // p abhi prime hai to uske multiples
            for (long long m = (long long)p * p; m <= n; m += p)
                comp[(int)m] = true;         // p*p se shuru: chote factors already
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (!comp[i]) primes.push_back(i);   // increasing order me collect karo
    return primes;
}
int gcdEuclid(int a, int b) {
    while (b != 0) { int r = a % b; a = b; b = r; } // O(log min a,b) steps
    return a;
}
int gcdOfArray(const vector<int>& arr) {
    if (arr.empty()) return 0;               // empty array guard: gcd undefined → 0
    int g = arr[0];
    for (size_t i = 1; i < arr.size(); i++) g = gcdEuclid(g, arr[i]);
    return g;
}

// ---------- PROBLEM C: XOR single number + fast power mod ----------
long long singleNumberXOR(const vector<int>& arr) {
    long long x = 0;
    for (int v : arr) x ^= v;                // a^a=0 cancels pairs; lone value rehta
    return x;                                // empty array → returns 0 (note in output)
}
long long fastPowMod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {                        // exp ke bits par loop
        if (exp & 1) res = (res * base) % mod;  // odd bit → factor multiply
        base = (base * base) % mod;          // square: exponent double ho gaya
        exp >>= 1;                           // agla bit
    }
    return res;
}

int main() {
    cout << "===== PROBLEM A: digits | sum | reverse | palindrome =====\n";
    DigitInfo a1 = digitOps(12321);
    cout << "n=12321 -> digits=" << a1.digits << " sum=" << a1.digitSum
         << " reverse=" << a1.reverse
         << " palindrome=" << (isPalindrome(12321) ? "YES" : "NO") << "\n";
    DigitInfo a2 = digitOps(-1234);                  // negative guarded
    cout << "n=-1234 (negative guard) -> digits=" << a2.digits
         << " sum=" << a2.digitSum << " reverse=" << a2.reverse
         << " palindrome=" << (isPalindrome(-1234) ? "YES" : "NO") << "\n";
    DigitInfo a3 = digitOps(0);                      // zero edge case
    cout << "n=0 -> digits=" << a3.digits << " sum=" << a3.digitSum
         << " reverse=" << a3.reverse
         << " palindrome=" << (isPalindrome(0) ? "YES" : "NO") << "\n";

    cout << "\n===== PROBLEM B: sieve <= 20 | count | gcd of array =====\n";
    int nB = 20;                                     // n small ke liye example
    vector<int> primes = sievePrimes(nB);
    cout << "primes <= " << nB << ": ";
    for (size_t i = 0; i < primes.size(); i++) cout << primes[i] << " ";
    cout << "\ncount of primes <= " << nB << ": " << primes.size() << "\n";
    vector<int> arrB = {12, 18, 24};
    cout << "gcd(";
    for (size_t i = 0; i < arrB.size(); i++) cout << arrB[i] << (i + 1 < arrB.size() ? "," : "");
    cout << ") = " << gcdOfArray(arrB) << "\n";

    cout << "\n===== PROBLEM C: XOR single + fast pow x^y mod m =====\n";
    vector<int> arrC = {1, 2, 3, 2, 1};
    cout << "single non-repeating in {1,2,3,2,1}: " << singleNumberXOR(arrC) << "\n";
    vector<int> empty;
    cout << "note: empty array -> singleNumberXOR returns 0 (no unique element): "
         << singleNumberXOR(empty) << "\n";
    cout << "2^5 mod 1000 = " << fastPowMod(2, 5, 1000) << "\n";
    cout << "7^2023 mod 10 (last digit) = " << fastPowMod(7, 2023, 10) << "\n";
    cout << "big: 3^100 mod 17 = " << fastPowMod(3, 100, 17) << "\n";

    cout << "\nEdge cases verified: negative guarded (A), zero digits=1 (A),\n"
         << "prime list for small n empty-safe (B), empty-array note (C).\n";
    return 0;
}