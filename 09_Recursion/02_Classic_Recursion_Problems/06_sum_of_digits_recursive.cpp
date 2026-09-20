/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_sum_of_digits_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Cashier number ke digits ko right se left tod kar sum karta hai. Last digit n%10 se milta hai, baaki number n/10 se chhota problem banta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Last digit = n % 10.
│ 2. Remaining number = n / 10.
│ 3. Recursive formula: sumDigits(n)=n%10 + sumDigits(n/10).
│ 4. Base case: if n==0 return 0.
│ 5. Number har call me 10 se divide hota hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ n=1234
│ 1234%10=4, call 123
│ 123%10=3, call 12
│ 12%10=2, call 1
│ 1%10=1, call 0 base
│ unwind: 1+2+3+4=10
│
│ DRY RUN:
│ sum(1234)=4+sum(123)
│ sum(123)=3+sum(12)
│ sum(12)=2+sum(1)
│ sum(1)=1+sum(0)
│ sum(0)=0 -> total 10
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Number of calls equals number of digits d plus base call.
│ - d = floor(log10(n)) + 1 for n>0.
│ - Each call constant modulo/division/addition.
│ -> Time Complexity = O(d), i.e. O(log10 n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth d+1.
│ -> Space Complexity = O(d) = O(log n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    cout << "sumDigits(1234) = " << sumDigits(1234) << "\n";
    return 0;
}

/*
OUTPUT:
sumDigits(1234) = 10
*/

