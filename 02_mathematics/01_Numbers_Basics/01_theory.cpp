/*
═══════════════════════════════════════════════
 NUMBERS BASICS (DIGIT OPERATIONS)
 ⏱️ TIME COMPLEXITY: every digit loop runs O(d) times (= O(log₁₀ n) iterations);
 the log10 trick runs in O(1). Fully derived below — never a bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A delivery app reads a 10-digit mobile number before confirming an order; it must
 first count the digits (reject 9-digit mistyped numbers), then sum them to award
 loyalty points, and finally reverse the tracking ID so the label printer shows a
 mirrored barcode. Banks silently do the same math every day: they add up the digits
 of an account number to compute a "check digit" that catches typing mistakes, and
 palindrome/Armstrong-style checks are used to mint tamper-proof lucky-coupon IDs.
 The tiny pair n%10 and n/10 is the engine behind validation, billing, and security
 code everywhere.

 📖 THEORY:  (pure English, beginner-level)
 - definition: digit extraction is the skill of pulling the units digit off a number,
   shrinking the number by one digit, and repeating until nothing is left. There are
   only TWO magic operations:
     n % 10  → returns the LAST (units) digit     e.g. 1234 % 10 = 4
     n / 10  → removes the LAST digit            e.g. 1234 / 10 = 123
   Integer division drops the decimal part, so n/10 physically chops off one digit.
 - key points / properties:
   * Every digit-loop consumes exactly one digit per iteration; the loop ends when
     n becomes 0, so the number of iterations equals the digit count.
   * Digit-count formula: d = floor(log10(n)) + 1, because 10^(d-1) ≤ n < 10^d.
   * 0 is special: it has exactly 1 digit, but the loop's condition n > 0 skips it —
     always handle n == 0 explicitly.
   * Negatives in C++: (-123) % 10 = -3 and (-123) / 10 = -12 (rounded toward zero),
     which breaks digit logic → FIRST take abs(n) (done in the code below).
   * Reversing 100 gives 1, not 001 — leading zeros are lost in integers; count them
     separately if the problem needs them.
 - when to use:
   * count digits  → input validation (9- vs 10-digit phone number)
   * sum of digits → check digits, digital root, digit-sum puzzles
   * reverse number→ mirrored barcodes, encrypted order IDs
   * palindrome / Armstrong → security questions, lottery coupons

 🌐 SPECIAL NUMBERS (BRIEF):
 - Perfect number    : n equals the sum of its proper divisors.     6 → 1+2+3 = 6
 - Automorphic number: n² ends with the digits of n itself.         5 → 25 ends in 5,
                                                                    6 → 36 ends in 6
 - Happy number      : keep replacing n by the sum of squares of its digits; if the
   chain reaches 1 it is happy, otherwise it falls into a cycle.    19 → 82 → 68 → 100 → 1

 🧠 LOGIC — STEP BY STEP:   (reverse a number — the master pattern)
 Step 1: grab the unit digit → last = n % 10.
         WHY: when you divide by 10, the REMAINDER is always the rightmost digit.
 Step 2: strip that digit off the number → n = n / 10.
         WHY: integer division discards the decimal, so the number shrinks by the
         digit we just recorded.
 Step 3: push the digit at the END of the result → rev = rev * 10 + last.
         WHY: multiplying rev by 10 makes room for the new digit on the right —
         this is how we rebuild the number in reversed order.
 Step 4: repeat Steps 1–3 until n == 0.
         WHY: each iteration consumes one digit; when none remain, all digits are
         safely moved into rev.
   (count/sum of digits are the same loop with a different accumulator:
    cnt++  or  sum += last.)

 VISUAL WALKTHROUGH:   (n = 1234)
     ┌─────┐         ┌─────┐         ┌─────┐         ┌─────┐
     │1234 │   %10   │123  │   %10   │12   │   %10   │1    │   %10
     │%10=4│ ──────► │%10=3│ ──────► │%10=2│ ──────► │%10=1│ ──────► n=0 STOP
     │/10=123      │/10=12       │/10=1        │/10=0
     └─────┘         └─────┘         └─────┘        └─────┘
           4              3              2              1          ← digits consumed
   digits gaaye right-to-left: 4,3,2,1   |   rev bana left-to-right: 0→4→43→432→4321

 DRY RUN:   (n = 1234, target: reverse)
   Iter | n    | last = n%10 | rev = rev*10 + last | n = n/10
   1    | 1234 | 4           | 0*10 + 4 = 4        | 123
   2    | 123  | 3           | 4*10 + 3 = 43       | 12
   3    | 12   | 2           | 43*10 + 2 = 432     | 1
   4    | 1    | 1           | 432*10 + 1 = 4321   | 0  → loop ends
   Result: rev = 4321  |  count digits = 4 iterations  |  sum digits = 4+3+2+1 = 10

 TIME COMPLEXITY CALCULATION:
 - [derive: each iteration performs n = n/10, i.e. removes exactly one digit, and the
   loop stops when n = 0. So iterations = number of digits = d. Every natural number
   n satisfies 10^(d-1) ≤ n < 10^d, therefore d = floor(log10(n)) + 1 ≈ log10(n).
   Hence iterations = Θ(log n) for the loop-based count/sum/reverse/palindrome/Armstrong.
   The log trick itself is one log10 call + one floor → constant Θ(1).]
 → Time Complexity: loop-based operations = O(d) = O(log₁₀ n);   log-trick count = O(1).

 SPACE COMPLEXITY CALCULATION:
 - [no arrays or recursion are used; each loop keeps only a few scalar variables
   (n, rev, cnt, sum). Memory usage never grows with the size of n — it is constant.]
 → Space Complexity = O(1).

 APPROACH COMPARISON:
 (1) count digits — loop vs log10 trick
 ┌─────────────┬───────────────────────────────────┬───────────────────────────────────┐
 │ Criterion   │ Loop (n = n/10)                   │ log10 trick                       │
 ├─────────────┼───────────────────────────────────┼───────────────────────────────────┤
 │ Mechanism   │ physically divide until n == 0    │ d = floor(log10(n)) + 1           │
 │ Time        │ O(d) = O(log n)                   │ O(1)                              │
 │ n = 0 case  │ explicit if (n == 0) return 1     │ explicit if (n == 0) return 1     │
 │ Float error │ none (pure integer math)          │ rare, only astronomically big n   │
 │ Best for    │ any digit-by-digit loop           │ quick length check only           │
 └─────────────┴───────────────────────────────────┴───────────────────────────────────┘

 (2) palindrome — full reverse vs half reverse
 ┌─────────────┬───────────────────────────────────┬───────────────────────────────────┐
 │ Criterion   │ Full reverse & compare            │ Half reverse                       │
 ├─────────────┼───────────────────────────────────┼───────────────────────────────────┤
 │ Mechanism   │ rev = reverse(n); rev == n        │ reverse only the right half        │
 │ Overflow    │ YES — rev*10 can overflow         │ NO — rev ≤ n always               │
 │ n%10 == 0   │ fine as-is                       │ MUST filter (10, 100, 110, …)      │
 │ Extra memory│ one extra integer (rev)           │ one extra integer (revHalf)        │
 │ Best for    │ small/demo ranges                │ huge numbers / LeetCode constraints│
 └─────────────┴───────────────────────────────────┴───────────────────────────────────┘
*/

#include <iostream>
#include <cmath>
using namespace std;

// har function negative numbers ko pehle positive banata hai (abs)
// kyunki C++ me (-123) % 10 = -3 deta hai jo digit logic tod deta hai.

int countDigitsLoop(int n) {
    if (n == 0) return 1;              // 0 ka loop n > 0 false karega → special case
    if (n < 0) n = -n;                 // negative ka sign hatao
    int cnt = 0;
    while (n > 0) {
        n /= 10;                       // ek digit kat gaya
        cnt++;                         // counter badhao
    }
    return cnt;
}

int countDigitsLog(int n) {
    if (n == 0) return 1;              // log10(0) undefined hai → special case
    if (n < 0) n = -n;
    return (int)floor(log10((double)n)) + 1;  // d = floor(log10 n) + 1
}

int sumDigits(int n) {
    if (n < 0) n = -n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;                 // last digit add karo
        n /= 10;                       // us digit ko hatao
    }
    return sum;
}

int reverseNumber(int n) {
    if (n < 0) n = -n;
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);     // digit right side pe chipkao
        n /= 10;
    }
    return rev;                        // leading zeroes (100 → 1) khud gayab
}

bool isPalindromeFull(int n) {
    if (n < 0) return false;           // negative palindrome nahi maante
    return reverseNumber(n) == n;      // poora number reverse + compare
}

bool isPalindromeHalf(int n) {
    if (n < 0) return false;
    if (n != 0 && n % 10 == 0) return false;   // 10, 100, 110 → false
    int revHalf = 0;
    while (n > revHalf) {              // tab tak half reverse karo
        revHalf = revHalf * 10 + (n % 10);
        n /= 10;
    }
    // even length → revHalf == n | odd length → n == revHalf/10
    return (revHalf == n) || (n == revHalf / 10);
}

// integer power loop — pow() floating error de sakta hai (5^3 = 124.999…)
long long powerInt(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++)
        res *= base;                   // base ko exp baar multiply
    return res;
}

bool isArmstrong(int n) {
    if (n < 0) return false;
    int k = countDigitsLog(n);         // kitne digits hain = power
    int original = n;
    long long sum = 0;
    while (n > 0) {
        int last = n % 10;
        sum += powerInt(last, k);      // har digit ^ k (integer power)
        n /= 10;
    }
    return sum == original;
}

int main() {
    cout << "=========== NUMBERS BASICS — DEMO ===========\n\n";

    // edge cases cover: 0 (ek digit), 7 (single digit), -987 (negative ka note),
    // 1234 & 2025 (normal numbers)
    int nums[] = {1234, 0, 7, -987, 2025};
    for (int x : nums) {
        cout << "n = " << x << "\n";
        cout << "  Count (loop)  : " << countDigitsLoop(x) << "\n";
        cout << "  Count (log10) : " << countDigitsLog(x) << "\n";
        cout << "  Sum of digits : " << sumDigits(x) << "\n";
        cout << "  Reverse (abs) : " << reverseNumber(x) << "\n\n";
    }
    // NOTE: negative numbers par hum abs() leke kaam karte hain; sign ko
    // alag store kar sakte ho agar problem ko use karna ho.

    cout << "----------- PALINDROME CHECKS -----------\n";
    int pals[] = {121, 12321, 1221, 12345, 0, 11, 10, 5};
    for (int p : pals) {
        cout << "  " << p << " -> full-reverse : "
             << (isPalindromeFull(p) ? "YES" : "NO ")
             << " | half-reverse : "
             << (isPalindromeHalf(p) ? "YES" : "NO ") << "\n";
    }

    cout << "\n----------- ARMSTRONG CHECKS -----------\n";
    int arms[] = {0, 1, 153, 371, 407, 123, 9474, 1634, 370};
    for (int a : arms) {
        if (isArmstrong(a))
            cout << "  " << a << " is Armstrong\n";
        else
            cout << "  " << a << " is NOT Armstrong\n";
    }

    cout << "\n---------------------------------------\n";
    return 0;
}