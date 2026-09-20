/*
═══════════════════════════════════════════════
 TASK SET — LOOPS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
 A school attendance system loops through all students one by one and marks
 present/absent. The same structure powers every repeating task: computing
 class averages, printing calendars, processing bank transactions, or
 reversing a roll call list. Choosing the RIGHT loop and knowing when to
 break out makes the difference between correct output and infinite hangs.

🧠 HOW TO SOLVE:
 Identify HOW MANY times you need to repeat (known → for, unknown → while,
 at-least-once → do-while). Keep a guard variable or input check to avoid
 infinite loops. Edge cases: empty input (n=0), negatives, very large n.

 5 TASKS (EASY → HARD):

 ═══════════════════════════════════════════════
 TASK 1: SUM OF DIGITS
 ═══════════════════════════════════════════════
 Statement:
   Read an integer. Compute sum of its digits using a while loop.
   Example: 9254 → 9+2+5+4 = 20.

 💡 HINT:
   digit = n % 10; sum += digit; n /= 10; repeat while n > 0.
   Edge case: n = 0 → sum = 0. Negative? use abs(n).

 // TODO: Read n; handle n < 0 with n = -n
 // TODO: while (n > 0) { sum += n%10; n /= 10; }
 // TODO: Print sum

 ═══════════════════════════════════════════════
 TASK 2: REVERSE A NUMBER (using while)
 ═══════════════════════════════════════════════
 Statement:
   Read an integer. Reverse its digits. 1234 → 4321.
   Handle negative numbers: -567 → -765.

 💡 HINT:
   Same structure as Task 1 but rev = rev*10 + digit.
   Use long long to prevent overflow on very large inputs.

 // TODO: Read n; track negative; use long long
 // TODO: while (n != 0) { rev = rev*10 + n%10; n /= 10; }
 // TODO: Print reversed

 ═══════════════════════════════════════════════
 TASK 3: MULTIPLICATION TABLE
 ═══════════════════════════════════════════════
 Statement:
   Read a number and print its multiplication table from 1 to 10.
   Example: n=7 → 7x1=7, 7x2=14, ... 7x10=70.

 💡 HINT:
   for loop i=1..10: print n << " x " << i << " = " << n*i

 // TODO: Read n
 // TODO: for (int i=1; i<=10; i++) print n*i

 ═══════════════════════════════════════════════
 TASK 4: PRIME CHECKER
 ═══════════════════════════════════════════════
 Statement:
   Read an integer n. Check if it is PRIME (divisible only by 1 and
   itself). Use a for loop from 2 to sqrt(n).

 💡 HINT:
   Prime: not divisible by any number from 2 to n-1.
   Optimization: only check up to sqrt(n) (since if n=a*b, at least
   one of a,b ≤ sqrt(n)).
   Edge case: n <= 1 → NOT prime.

 // TODO: Read n; handle n<=1 → not prime
 // TODO: for (i=2; i*i <= n; i++) if n%i==0 → not prime, break
 // TODO: if no divisor found → prime

 ═══════════════════════════════════════════════
 TASK 5: FIBONACCI PRINTER (do-while version)
 ═══════════════════════════════════════════════
 Statement:
   Read how many terms to print. Print first n terms of Fibonacci
   sequence: 0, 1, 1, 2, 3, 5, 8, 13, ...
   Use a do-while loop; handle n=0 and n=1 as edge cases.

 💡 HINT:
   Fibonacci: fib = fibPrev + fibCurr.
   0, 1 are the first two (given). For n=0 print nothing; n=1 print 0.
   Use long long to avoid overflow for large n.

 // TODO: Read n; handle n=0 early return
 // TODO: a=0, b=1; print a (first term)
 // TODO: for i=2 to n: c=a+b, print c, shift: a=b, b=c

═══════════════════════════════════════════════
*/

// ==================== SOLUTIONS ====================
#include <iostream>
#include <cmath>    // for sqrt()
using namespace std;

// -------- TASK 1: Sum of Digits --------
void task1_digit_sum() {
    cout << "===== TASK 1: Sum of Digits =====" << endl;

    long long n;
    cout << "Enter an integer: ";
    cin >> n;

    long long original = n;
    bool negative = (n < 0);
    if (negative) n = -n;

    long long sum = 0;
    // edge case: n=0 → loop nahi chalega, sum = 0 sahi hai
    while (n > 0) {
        sum += n % 10;      // last digit jod lo
        n /= 10;            // last digit hatao
    }

    cout << "Sum of digits of " << original << " = " << sum << endl;
    cout << endl;
}

// -------- TASK 2: Reverse a Number --------
void task2_reverse_number() {
    cout << "===== TASK 2: Reverse a Number =====" << endl;

    long long n;
    cout << "Enter an integer: ";
    cin >> n;

    bool negative = (n < 0);
    long long num = negative ? -n : n;
    long long rev = 0;

    while (num != 0) {
        rev = rev * 10 + num % 10;   // rev ko 10 se multiply karke last digit jodo
        num /= 10;
    }

    if (negative) rev = -rev;
    cout << "Original : " << n << endl;
    cout << "Reversed : " << rev << endl;

    // palindrome check bonus!
    if (!negative && n == rev && n != 0) {
        cout << "BONUS: This is a PALINDROME!" << endl;
    }
    cout << endl;
}

// -------- TASK 3: Multiplication Table --------
void task3_multiplication_table() {
    cout << "===== TASK 3: Multiplication Table =====" << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\n--- Table of " << n << " ---" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << (long long)n * i << endl;
        // n*i ko long long me cast kiya — bada number na overflow kare
    }
    cout << endl;
}

// -------- TASK 4: Prime Checker --------
void task4_prime_checker() {
    cout << "===== TASK 4: Prime Checker =====" << endl;

    long long n;
    cout << "Enter an integer: ";
    cin >> n;

    if (n <= 1) {
        cout << n << " is NOT prime (must be > 1)" << endl;
    } else if (n == 2) {
        cout << "2 is PRIME" << endl;
    } else {
        bool is_prime = true;

        // optimization: only check up to sqrt(n)
        // kyunki agar n=a*b hai to at least one factor <= sqrt(n)
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = false;
                cout << n << " is NOT prime (divisible by " << i << ")" << endl;
                break;
            }
        }

        if (is_prime)
            cout << n << " is PRIME" << endl;
    }
    cout << endl;
}

// -------- TASK 5: Fibonacci Sequence --------
void task5_fibonacci() {
    cout << "===== TASK 5: Fibonacci Sequence =====" << endl;

    int n;
    cout << "How many Fibonacci terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
    } else {
        long long a = 0, b = 1, c;

        cout << "Fibonacci (" << n << " terms): " << endl;

        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                cout << a;         // first term = 0
            } else if (i == 2) {
                cout << ", " << b; // second term = 1
            } else {
                c = a + b;         // next term
                cout << ", " << c;
                a = b;             // shift window forward
                b = c;
            }
        }
        cout << endl;

        // edge case: check overflow warning for large n
        if (n > 93) {
            cout << "(Warning: Fibonacci > 93 overflows long long!)" << endl;
        }
    }
    cout << endl;
}

int main() {
    task1_digit_sum();
    task2_reverse_number();
    task3_multiplication_table();
    task4_prime_checker();
    task5_fibonacci();

    cout << "All tasks completed!" << endl;
    return 0;
}