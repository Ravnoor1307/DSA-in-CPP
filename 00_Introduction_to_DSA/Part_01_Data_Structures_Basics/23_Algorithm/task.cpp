/*
═══════════════════════════════════════════════
 TASK SET — ALGORITHM
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Every routine — from calculating a grocery bill to
 checking whether a number is prime — is an algorithm. A good algorithm must have
 clear input, clear output, terminate, be unambiguous and be effective. These
 tasks make you convert everyday problems into precise step sequences.
🧠 HOW TO SOLVE: First write PSEUDO-CODE (what to do) on paper, check the five
 properties, then translate into C++. Always test small edge cases.

 TASK 1 (EASY): Write an algorithm (function) to compute the FACTORIAL of a
   number n: n! = 1*2*...*n. Use a loop. Test with n=0 (0! = 1) and n=5 (120).
 💡 HINT: start result = 1, multiply i from 2 up to n; 0! special-case.
 ✏️ STARTER CODE:
   int factorial(int n) {
       int result = 1;
       // TODO: multiply result by 2,3,...,n
       return result;
   }
   int main(){ cout << factorial(5) << " " << factorial(0); return 0; }

 TASK 2 (EASY): Write GCD (Greatest Common Divisor) using Euclid's algorithm:
   while (b != 0) { temp = b; b = a % b; a = temp; } return a;  Test 48,18 -> 6.
 💡 HINT: keep swapping a and b; the remainder keeps shrinking until zero.
 ✏️ STARTER CODE:
   int gcd(int a, int b) {
       while (b != 0) {
           int t = b;
           b = a % b;
           a = t;
       }
       // TODO: return the right value
       return 0;
   }

 TASK 3 (MEDIUM): Find the MAXIMUM element of an int array. State the algorithm:
   assume first element is max, compare with all, update when bigger.
 💡 HINT: initialize max with arr[0], loop from i=1.
 ✏️ STARTER CODE:
   int maxOfArray(int arr[], int n) {
       // TODO: max = arr[0]; for i=1..n-1 if arr[i]>max update
       return 0;
   }
   // test: {3, 9, 2, 7} -> 9

 TASK 4 (MEDIUM): PRIME check — return true if n is prime. Only divisors from 2
   up to sqrt(n) need checking.
 💡 HINT: n<=1 -> not prime; loop i=2 while i*i<=n.
 ✏️ STARTER CODE:
   bool isPrime(int n) {
       if (n <= 1) return false;
       for (int i = 2; i * i <= n; i++)
           // TODO: if n % i == 0 return false
       return true;
   }
   // test 7 -> true, 8 -> false, 1 -> false

 TASK 5 (HARD): REVERSE a number. Given 1234, return 4321. Algorithm: take
   last digit (n%10), append to result (result = result*10 + digit), drop digit
   (n /= 10) until n == 0.
 💡 HINT: handle the digit extraction order; 0 -> 0; 100 -> 1 not 001.
 ✏️ STARTER CODE:
   int reverseNumber(int n) {
       int result = 0;
       // TODO: while (n > 0) { digit = n%10; result = result*10+digit; n/=10; }
       return result;
   }

 TASK 6 (HARD): COUNT DIGITS of a number AND check if it is a palindrome
   (reverse number == original). Print both answers.
 💡 HINT: count = 0; while(n>0){ count++; n/=10; } palindrome via reversed var.
 ✏️ STARTER CODE:
   int digits(int n){ return 0; }          // TODO: count digits
   bool isPalindrome(int n){ return false; } // TODO: reuse reverse
   // test 121 -> true, 12345 -> 5 digits & false

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

// ---------- SOLUTION TASK 1 ----------
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;   // 1*2*3*...*n
    return result;                              // n=0 loop nahi chalega -> 1
}

// ---------- SOLUTION TASK 2 ----------
int gcd(int a, int b) {
    while (b != 0) {           // jab tak remainder bacha hai
        int t = b;
        b = a % b;             // naya remainder
        a = t;
    }
    return a;                  // jab b=0 hua, a hi GCD hai
}

// ---------- SOLUTION TASK 3 ----------
int maxOfArray(int arr[], int n) {
    int max = arr[0];          // pehla element abhi max
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// ---------- SOLUTION TASK 4 ----------
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;   // koi divisor mil gaya -> not prime
    return true;
}

// ---------- SOLUTION TASK 5 ----------
int reverseNumber(int n) {
    int result = 0;
    while (n > 0) {
        int digit = n % 10;              // aakhri digit
        result = result * 10 + digit;    // aage shift karke digit chipka do
        n /= 10;                         // aakhri digit hata do
    }
    return result;
}

// ---------- SOLUTION TASK 6 ----------
int countDigits(int n) {
    int count = 0;
    if (n == 0) return 1;                // edge case
    while (n > 0) { count++; n /= 10; }
    return count;
}

bool isPalindrome(int n) {
    return reverseNumber(n) == n;        // reverse mil gaya to compare karo
}

int main() {
    cout << "factorial(5)=" << factorial(5) << " factorial(0)=" << factorial(0) << "\n";
    cout << "gcd(48,18)=" << gcd(48, 18) << "\n";

    int arr[] = {3, 9, 2, 7};
    cout << "maxOfArray=" << maxOfArray(arr, 4) << "\n";

    cout << "isPrime(7)=" << isPrime(7) << " isPrime(8)=" << isPrime(8)
         << " isPrime(1)=" << isPrime(1) << "\n";

    cout << "reverse(1234)=" << reverseNumber(1234) << "\n";

    cout << "countDigits(12345)=" << countDigits(12345)
         << " isPalindrome(121)=" << isPalindrome(121)
         << " isPalindrome(123)=" << isPalindrome(123) << "\n";
    return 0;
}