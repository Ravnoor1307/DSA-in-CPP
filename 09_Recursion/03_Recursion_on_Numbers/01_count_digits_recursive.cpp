/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_count_digits_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Bank account number me digits count karne hain. Har step last digit hatao using n/10, aur smaller number ke digits count karo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: if n < 10 return 1.
│ 2. Recursive case: 1 + countDigits(n/10).
│ 3. Har call number ka last digit remove karta hai.
│ 4. n=0 special case: digits count 1.
│ 5. Calls digit count ke equal hote hain.
│
│ ASCII VISUAL / NUMBER STATE:
│ n=12345
│ count(12345) = 1 + count(1234)
│ count(1234)  = 1 + count(123)
│ count(123)   = 1 + count(12)
│ count(12)    = 1 + count(1)
│ count(1)     = 1 base
│ total = 5
│
│ DRY RUN:
│ 12345 -> 1234 -> 123 -> 12 -> 1
│ base at 1.
│ return chain: 1,2,3,4,5.
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Number divides by 10 each call.
│ - If d digits, calls = d.
│ - d = floor(log10(n)) + 1 for n>0.
│ -> Time Complexity = O(d) = O(log n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth d.
│ -> Space Complexity = O(d) = O(log n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

int main() {
    cout << "digits in 12345 = " << countDigits(12345) << "\n";
    cout << "digits in 0 = " << countDigits(0) << "\n";
    return 0;
}

/*
OUTPUT:
digits in 12345 = 5
digits in 0 = 1
*/

