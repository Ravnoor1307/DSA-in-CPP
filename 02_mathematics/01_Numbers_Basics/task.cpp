/*
═══════════════════════════════════════════════
 TASK SET — NUMBERS BASICS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: a courier office types in a customer ID that may be
corrupted. First you count the digits to validate the format, then you sum them to
compute a check digit, reverse them to regenerate a lost order code, and finally run
palindrome/Armstrong checks to reject fake lucky coupons.
🧠 HOW TO SOLVE: every problem uses the same one-line engine —
   int last = n % 10;  n = n / 10;   inside a while (n > 0) loop,
plus ONE accumulator updated each round: cnt++, sum += last,
rev = rev*10 + last, or freq[last]++. Read each task, fill its starter, then
peek at the SOLUTIONS section below to verify.
═══════════════════════════════════════════════

 TASK 1 — COUNT DIGITS   [EASY]
 Given a positive integer n, print how many digits it contains.
   n = 1234  →  4        n = 0  →  1
 💡 HINT: each iteration removes one digit (n /= 10); increase the counter.
    Remember the special case n = 0 — the loop will not run at all!
 ✏️ STARTER CODE:
 // #include <iostream>
 // using namespace std;
 // int main() {
 //     int n; cin >> n;
 //     int cnt = 0;
 //     while (n > 0) {
 //         // write your code here
 //     }
 //     if (nWasZero) cnt = 1;   // edge case
 //     cout << cnt;
 // }

 TASK 2 — SUM OF DIGITS  [EASY]
 Given n, print the sum of all its digits.
   n = 1234  →  1+2+3+4 = 10        n = 909  →  18
 💡 HINT: get last = n % 10; add it with sum += last; shrink the loop with n /= 10.
 ✏️ STARTER CODE:
 // int n; cin >> n;
 // int sum = 0;
 // while (n > 0) {
 //     int last = n % 10;
 //     // update sum here
 //     n /= 10;
 // }
 // cout << sum;

 TASK 3 — REVERSE A NUMBER  [MEDIUM]
 Given n, print the number formed by its digits in reverse order.
   1234 → 4321      100 → 1 (trailing zeroes vanish!)      0 → 0
 💡 HINT: rev = rev * 10 + last; this formula attaches the digit on the RIGHT side.
 ✏️ STARTER CODE:
 // int n; cin >> n;
 // int rev = 0;
 // while (n > 0) {
 //     int last = n % 10;
 //     // rev = rev * 10 + last;
 //     n /= 10;
 // }
 // cout << rev;

 TASK 4 — PALINDROME CHECK  [MEDIUM]
 Print "yes" if n reads the same forwards and backwards, else "no".
   121 → yes    12321 → yes    12345 → no    10 → no
 💡 HINT: build the reverse (like Task 3), then compare it with the original n.
 ✏️ STARTER CODE:
 // int n; cin >> n;
 // int temp = n, rev = 0;
 // while (temp > 0) {
 //     // keep building the reverse
 // }
 // if (rev == n) cout << "yes"; else cout << "no";

 TASK 5 — ARMSTRONG (3-DIGIT)  [MEDIUM]
 A 3-digit number abc is called Armstrong if a³ + b³ + c³ == n.
   153 → yes (1 + 125 + 27 = 153)    370 → yes    123 → no
 💡 HINT: take each digit and add its cube (last*last*last) to the sum.
 ✏️ STARTER CODE:
 // int n; cin >> n;
 // int temp = n, sum = 0;
 // while (temp > 0) {
 //     int last = temp % 10;
 //     // sum += last * last * last;
 //     temp /= 10;
 // }
 // if (sum == n) cout << "Armstrong"; else cout << "Not";

 TASK 6 — COUNT ZEROES  [MEDIUM]
 Print how many zero digits appear inside n.
   1000 → 3     101 → 1     0 → 1     1234 → 0
 💡 HINT: every time n % 10 == 0 is found, increase the counter; n == 0 itself is one zero.
 ✏️ STARTER CODE:
 // int n; cin >> n;
 // int cnt = 0;
 // while (n > 0) {
 //     if (n % 10 == 0) cnt++;   // found a zero digit?
 //     n /= 10;
 // }
 // // handle the special case n == 0 separately
 // cout << cnt;

 TASK 7 — DIGIT FREQUENCY  [HARD]
 Given n, print how many times each digit 0–9 appears inside it.
   112211  →  0:0  1:4  2:2  3:0  4:0  5:0  6:0  7:0  8:0  9:0
 💡 HINT: take int freq[10] = {0}, then do freq[n % 10]++ — the index itself is the digit.
 ✏️ STARTER CODE:
 // int n; cin >> n;
 // int freq[10] = {0};
 // while (n > 0) {
 //     // freq[n % 10]++;
 //     n /= 10;
 // }
 // for (int i = 0; i < 10; i++)
 //     cout << i << ":" << freq[i] << " ";

═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// ---------- Task 1: count digits ----------
long long countDigits(long long n) {
    if (n == 0) return 1;          // 0 par loop nahi chalega → special case
    if (n < 0) n = -n;             // negative ka sign hatao
    long long cnt = 0;
    while (n > 0) {
        n /= 10;                   // har round me ek digit kat gayi
        cnt++;                     // ek digit count ho gaya
    }
    return cnt;                    // iterations = number of digits
}
// TIME: O(d) = O(log n) iterations | SPACE: O(1)

// ---------- Task 2: sum of digits ----------
long long sumDigits(long long n) {
    if (n < 0) n = -n;             // abs, warna negative aadha kaam karega
    long long sum = 0;
    while (n > 0) {
        int last = n % 10;         // aakhri digit
        sum += last;               // accumulator me jodo
        n /= 10;                   // digit utar do
    }
    return sum;                    // n = 1234 → 4 + 3 + 2 + 1 = 10
}
// TIME: O(log n) | SPACE: O(1)

// ---------- Task 3: reverse number ----------
long long reverseNumber(long long n) {
    if (n < 0) n = -n;
    long long rev = 0;
    while (n > 0) {
        int last = n % 10;
        rev = rev * 10 + last;     // digit RIGHT side pe chipkao
        n /= 10;
    }
    // leading zeroes (100 → 1) integer me khud vanish — expected behaviour
    return rev;
}
// TIME: O(log n) | SPACE: O(1)

// ---------- Task 4: palindrome ----------
bool isPalindrome(long long n) {
    if (n < 0) return false;       // negative ko palindrome nahi maante
    return reverseNumber(n) == n;  // Task 3 ka reverse reuse karo
}
// TIME: O(log n) | SPACE: O(1)

// ---------- Task 5: Armstrong (3-digit) ----------
bool isArmstrong3(long long n) {
    if (n < 100 || n > 999) return false;  // sirf 3-digit numbers allowed
    long long temp = n, sum = 0;
    while (temp > 0) {
        int last = temp % 10;          // digit uthao
        sum += last * last * last;     // cube daalo (a³ + b³ + c³)
        temp /= 10;
    }
    return sum == n;                   // 153: 1 + 125 + 27 = 153 ✓
}
// TIME: fixed 3 iterations = O(1) | SPACE: O(1)

// ---------- Task 6: count zeroes ----------
long long countZeroes(long long n) {
    if (n == 0) return 1;          // "0" khud ek zero-digit hai
    if (n < 0) n = -n;
    long long cnt = 0;
    while (n > 0) {
        if (n % 10 == 0) cnt++;    // digit 0 dikha?
        n /= 10;
    }
    return cnt;                    // 1000 → 3,  101 → 1
}
// TIME: O(log n) | SPACE: O(1)

// ---------- Task 7: digit frequency ----------
void digitFrequency(long long n) {
    int freq[10] = {0};            // index = digit, value = kitni baar
    if (n < 0) n = -n;
    if (n == 0) { freq[0] = 1; }   // 0 me sirf ek zero-hot digit
    while (n > 0) {
        freq[n % 10]++;            // jo digit aayi usi ki count badhao
        n /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << i << ":" << freq[i] << "  ";
    cout << endl;
}
// TIME: O(log n) | SPACE: O(1) fixed array size 10

int main() {
    cout << "--- Task 1: countDigits ---\n";
    cout << "1234 -> " << countDigits(1234) << "\n";
    cout << "0    -> " << countDigits(0) << "\n\n";

    cout << "--- Task 2: sumDigits ---\n";
    cout << "1234 -> " << sumDigits(1234) << "\n";
    cout << "909  -> " << sumDigits(909) << "\n\n";

    cout << "--- Task 3: reverseNumber ---\n";
    cout << "1234 -> " << reverseNumber(1234) << "\n";
    cout << "100  -> " << reverseNumber(100) << "\n\n";

    cout << "--- Task 4: isPalindrome ---\n";
    cout << "121 (yes?)   -> " << (isPalindrome(121) ? "yes" : "no") << "\n";
    cout << "12321 (yes?) -> " << (isPalindrome(12321) ? "yes" : "no") << "\n";
    cout << "12345 (no?)  -> " << (isPalindrome(12345) ? "yes" : "no") << "\n\n";

    cout << "--- Task 5: isArmstrong3 ---\n";
    cout << "153 -> " << (isArmstrong3(153) ? "Armstrong" : "Not") << "\n";
    cout << "370 -> " << (isArmstrong3(370) ? "Armstrong" : "Not") << "\n";
    cout << "123 -> " << (isArmstrong3(123) ? "Armstrong" : "Not") << "\n\n";

    cout << "--- Task 6: countZeroes ---\n";
    cout << "1000 -> " << countZeroes(1000) << "\n";
    cout << "0    -> " << countZeroes(0) << "\n\n";

    cout << "--- Task 7: digitFrequency ---\n";
    cout << "112211 -> ";
    digitFrequency(112211);
    return 0;
}