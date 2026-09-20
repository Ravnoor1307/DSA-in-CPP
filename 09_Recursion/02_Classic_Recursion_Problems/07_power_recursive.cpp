/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_power_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Agar 2 ki 4 copies multiply karni hain, to 2^4 = 2 * 2^3. Power recursion same smaller exponent problem solve karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: a^0 = 1.
│ 2. Recursive case: a^n = a * a^(n-1).
│ 3. Exponent har call me 1 kam hota hai.
│ 4. Simple approach O(n) hai.
│ 5. Preview: Binary Exponentiation exponent half karke O(log n) banata hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ power(2,4)
│ = 2 * power(2,3)
│ = 2 * 2 * power(2,2)
│ = 2 * 2 * 2 * power(2,1)
│ = 2 * 2 * 2 * 2 * power(2,0)
│ = 16
│
│ DRY RUN:
│ p(2,4)->p(2,3)->p(2,2)->p(2,1)->p(2,0)=1
│ unwind: 2,4,8,16
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Exponent reduces by 1 each call.
│ - Calls: n,n-1,...,0 = n+1 calls.
│ - Each call one multiplication.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Call stack depth n+1.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long powerSimple(int a, int n) {
    if (n == 0) return 1;
    return 1LL * a * powerSimple(a, n - 1);
}

int main() {
    cout << "2^4 = " << powerSimple(2, 4) << "\n";
    cout << "Preview: binary exponentiation can reduce this to O(log n).\n";
    return 0;
}

/*
OUTPUT:
2^4 = 16
Preview: binary exponentiation can reduce this to O(log n).
*/

