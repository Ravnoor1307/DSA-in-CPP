/*
═══════════════════════════════════════════════
 TASK SET — MIXED MATH REVISION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: In an interview you get 8 rapid-fire math micro-tasks —
sum the digits of an invoice number, pick prime whitelist size, find the wedged
file chunk, predict the last digit of a huge power, count poker combos. Each is a
one-liner IF you recall which tool applies; this set drills exactly that.

🧠 HOW TO SOLVE: match the problem to its toolkit row BEFORE coding — digits → %10/10
loop, primes → sieve, gcd/lcm → Euclid + (a/g)*b, unique element → XOR, huge exponent
→ fast power mod, power of 2 → n&(n-1), digital root → mod 9. Then derive complexity
from the LOOP COUNT, never recite it.
 8 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

/*
--------------------------------------------------------------------
 TASK 1 (EASY) — sum of digits of n = 98765
 💡 HINT: pop last digit via n%10, add it, drop via n/=10, till n==0.
 ✏️ STARTER CODE:
     // int sum=0; while(n>0){ sum += n%10; n/=10; }
--------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void solveTask1() {
    // derivation: har pop n%10 ek digit deta hai, n/=10 aage badhata hai.
    // digits d = floor(log10 n)+1, to loop d times = O(log10 n), O(1) space.
    int n = 98765, sum = 0, t = n;
    while (t > 0) { sum += t % 10; t /= 10; }
    cout << "Task 1: sum of digits(" << n << ") = " << sum
         << " | loop ran " << (int)floor(log10((double)n)) + 1 << " times\n";
    cout << "   Complexity: O(log10 n) time, O(1) space (d pops, fixed vars)\n\n";
}

/*
--------------------------------------------------------------------
 TASK 2 (EASY) — LCM of 12 and 18 (using gcd)
 💡 HINT: lcm(a,b) = (a/gcd(a,b))*b — divide FIRST to avoid overflow.
 ✏️ STARTER CODE:
     // long long g = gcd(12,18); cout << (12/g)*18;   // = 36
--------------------------------------------------------------------
*/
long long gcdLL(long long a, long long b) {
    // Euclid: gcd(a,b)=gcd(b, a%b); remainder halves → O(log min(a,b)).
    while (b) { long long r = a % b; a = b; b = r; }
    return a;
}
void solveTask2() {
    // derivation: lcm*gcd = a*b identity se lcm = a* b/g.
    // b/g pehle divide karte hain taaki (a*b) overflow na ho → safe long long.
    long long a = 12, b = 18;
    long long g = gcdLL(a, b);
    long long lcm = (a / g) * b;
    cout << "Task 2: lcm(" << a << "," << b << ") = " << lcm
         << " (gcd was " << g << ")\n";
    cout << "   Complexity: gcd O(log min(a,b)), multiply O(1) -> O(log min) total\n\n";
}

/*
--------------------------------------------------------------------
 TASK 3 (EASY-MED) — count total primes ≤ n=100 using sieve
 💡 HINT: boolean array comp[size n+1]; mark multiples from p*p.
 ✏️ STARTER CODE:
     // comp[0]=comp[1]=true; for p=2..sqrt(n) if(!comp[p]) for m=p*p..n step p comp[m]=true
     // ab count karo !comp[i] wale elements.
--------------------------------------------------------------------
*/
int countPrimesUpTo(int n) {
    // derivation: for each prime p we mark n/p multiples; total Σ n/p ≈ n·ln ln n.
    if (n < 2) return 0;                       // 0,1 me koi prime nahi
    vector<bool> comp(n + 1, false);
    comp[0] = comp[1] = true;
    for (int p = 2; p * p <= n; p++)           // sqrt se aage zarurat nahi
        if (!comp[p])
            for (long long m = (long long)p * p; m <= n; m += p)
                comp[(int)m] = true;
    int cnt = 0;
    for (int i = 2; i <= n; i++) if (!comp[i]) cnt++;
    return cnt;
}
void solveTask3() {
    // derivation: sieve work = Σ_{p}(n/p) ≈ n·(ln ln n + M) → O(n log log n),
    // time; boolean array of size n+1 → O(n) space.
    int n = 100;
    cout << "Task 3: primes <= " << n << " = " << countPrimesUpTo(n) << "\n";
    cout << "   Complexity: O(n log log n) time [Σ n/p ≈ n ln ln n], O(n) space\n\n";
}

/*
--------------------------------------------------------------------
 TASK 4 (MED) — single non-repeating element in {4,1,2,1,2} via XOR
 💡 HINT: xor=0; for x: xor^=x. Pairs cancel (a^a=0), lone value bachta hai.
 ✏️ STARTER CODE:
     // int xo=0; for(auto v:v) xo^=v; return xo;
--------------------------------------------------------------------
*/
void solveTask4() {
    // derivation: XOR commutative + self-inverse → har duplicate pair 0 banata hai.
    // n elements ek baar visit → O(n) time; ek hi variable → O(1) space.
    vector<int> v = {4, 1, 2, 1, 2};
    int xo = 0;
    for (int x : v) xo ^= x;
    cout << "Task 4: single non-repeating in {4,1,2,1,2} = " << xo << "\n";
    cout << "   Complexity: O(n) time, O(1) space (kisi hashmap ki zarurat nahi)\n\n";
}

/*
--------------------------------------------------------------------
 TASK 5 (MED) — last digit of 7^2023 via fast power mod 10
 💡 HINT: base%10 lene ke baad result = (result*base)%10; har step me square.
 ✏️ STARTER CODE:
     // long long r=1; while(e){ if(e&1) r=r*b%10; b=b*b%10; e>>=1; }
--------------------------------------------------------------------
*/
long long fastPowMod10(long long b, long long e) {
    // derivation: 2023 = binary ... ki har bit par ek square; loop log2(2023)≈11 baar.
    long long r = 1;
    b %= 10;
    while (e > 0) {
        if (e & 1) r = (r * b) % 10;           // odd bit → factor multiply
        b = (b * b) % 10;                      // square → exponent double
        e >>= 1;
    }
    return r;
}
void solveTask5() {
    // derivation: O(log2 2023) ≈ 11 iterations, each O(1) → O(log e) time, O(1) space.
    // verify: 7^1=7, 7^2=49→9, 7^3=343→3, 7^4=2401→1, pattern repeats 7,9,3,1.
    // 2023 mod 4 = 3 → 7^2023 ends with 7^3 pattern = 3. fast pow same answer.
    long long ans = fastPowMod10(7, 2023);
    cout << "Task 5: last digit of 7^2023 = " << ans
         << " (paper pattern 7,9,3,1; 2023%4=3 -> 3 ✓)\n";
    cout << "   Complexity: O(log2 2023) time = O(log e), O(1) space\n\n";
}

/*
--------------------------------------------------------------------
 TASK 6 (MED) — nCr(10,4) via multiplication loop (r small)
 💡 HINT: res=1; r=min(r,n-r); for i=1..r: res=res*(n-r+i)/i — integer exact.
 ✏️ STARTER CODE:
     // long long res=1,r2=min(r,n-r); for(i=1;i<=r2;i++) res=res*(n-r2+i)/i;
--------------------------------------------------------------------
*/
long long nCrSmallR(int n, int r) {
    // derivation: C(n,r) = Π_{i=1..r} (n-r+i)/i; har step me divide integer hota hai
    // kyunki pehle ke factors ka product already i se divisible hai. r iterations.
    if (r < 0 || r > n) return 0;
    long long res = 1;
    int r2 = min(r, n - r);                    // symmetrical: C(10,4)=C(10,6)
    for (int i = 1; i <= r2; i++)
        res = res * (n - r2 + i) / i;          // pehle multiply, phir divide (exact)
    return res;
}
void solveTask6() {
    // derivation: loop r2 = min(4,6)=4 baar → O(r) time; ek variable → O(1) space.
    long long c = nCrSmallR(10, 4);
    cout << "Task 6: C(10,4) = " << c << " (verify: 10!/(4!6!) = 210)\n";
    cout << "   Complexity: O(min(r, n-r)) time, O(1) space\n\n";
}

/*
--------------------------------------------------------------------
 TASK 7 (MED) — check if n=4096 is a power of 2 (bit trick)
 💡 HINT: power of 2 has exactly ONE set bit → n>0 && (n&(n-1))==0.
 ✏️ STARTER CODE:
     // return n>0 && (n & (n-1)) == 0   // 4096 = 1000000000000₂ → true
--------------------------------------------------------------------
*/
bool isPowerOfTwoBit(long long n) {
    // derivation: n-1 flips the single 1-bit and all lower bits to 1, so AND = 0
    // ONLY for powers of 2. Ek hi bitwise op → O(1) time and space.
    return n > 0 && (n & (n - 1)) == 0;
}
void solveTask7() {
    // derivation: n=4096 = 2^12 → ek hi set bit; 4095 flips; AND = 0 → true.
    cout << "Task 7: isPowerOfTwo(4096) = "
         << (isPowerOfTwoBit(4096) ? "YES" : "NO")
         << ", isPowerOfTwo(4095) = "
         << (isPowerOfTwoBit(4095) ? "YES" : "NO") << "\n";
    cout << "   Complexity: O(1) time, O(1) space (single AND + compare)\n\n";
}

/*
--------------------------------------------------------------------
 TASK 8 (HARD) — digital root of n=987654 (sum until single digit)
 💡 HINT: dr = 1 + (n-1) % 9 for n>0 (digit sum property); loop iteration bhi chalega.
 ✏️ STARTER CODE:
     // int dr=n%9; dr=(dr==0)? (n==0?0:9) : dr;   // formula version
--------------------------------------------------------------------
*/
int digitalRootLoop(int n) {
    // derivation (loop): har pass se digit count ≈ divide-by-10 up to length
    // shrinking — total d + (d-1) + ... ~ O((log n)²) worst loop version.
    while (n >= 10) {                            // jab tak 1 digit nahi
        int s = 0;
        while (n > 0) { s += n % 10; n /= 10; }  // iska digit sum
        n = s;
    }
    return n;
}
int digitalRootFormula(long long n) {
    // WHY formula: n mod 9 digit root deta hai kyunki 10 ≡ 1 (mod 9),
    // to n ≡ (digit sum) (mod 9). n=0 special, otherwise 9 becomes 0 → map.
    if (n == 0) return 0;
    int r = (int)(n % 9);
    return (r == 0) ? 9 : r;                     // 9 wale answer ko 9 dikhao
}
void solveTask8() {
    // derivation: formula O(1) steps; loop version O((log n)²); space O(1).
    cout << "Task 8: digitalRoot(987654) loop=" << digitalRootLoop(987654)
         << " formula=" << digitalRootFormula(987654) << "\n";
    // check by hand: 9+8+7+6+5+4=39 → 3+9=12 → 1+2=3 ✓  | 39%9=3 ✓
    cout << "   Complexity: formula O(1); loop O(digits²) ~ O((log n)^2); space O(1)\n\n";
}

int main() {
    solveTask1();
    solveTask2();
    solveTask3();
    solveTask4();
    solveTask5();
    solveTask6();
    solveTask7();
    solveTask8();
    return 0;
}