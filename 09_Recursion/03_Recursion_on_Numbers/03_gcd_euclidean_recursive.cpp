/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_gcd_euclidean_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ 48 laddus aur 18 boxes ko equal groups me baantne ka biggest common group size GCD hai. Euclidean recursion remainder se problem chhoti karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Euclidean formula: gcd(a,b) = gcd(b, a%b).
│ 2. Base case: if b==0 return a.
│ 3. Remainder previous number se smaller hota hai.
│ 4. gcd(48,18) notes-style classic recursion example hai.
│ 5. Final non-zero value answer hota hai.
│
│ ASCII VISUAL / NUMBER STATE:
│ gcd(48,18)
│ 48 % 18 = 12  -> gcd(18,12)
│ 18 % 12 = 6   -> gcd(12,6)
│ 12 % 6  = 0   -> gcd(6,0)
│ b==0, answer=6
│
│ Call chain: 48,18 -> 18,12 -> 12,6 -> 6,0
│
│ DRY RUN:
│ gcd(48,18)
│ = gcd(18,12)
│ = gcd(12,6)
│ = gcd(6,0)
│ = 6
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Each call replaces (a,b) by (b, a%b).
│ - Values shrink fast; worst case occurs for Fibonacci-like pairs.
│ - Number of calls is O(log min(a,b)).
│ - Log shrink intuition: after constant few steps number at least halves.
│ -> Time Complexity = O(log min(a,b)).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive stack has O(log min(a,b)) frames.
│ -> Space Complexity = O(log min(a,b)).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gcdRecursive(int a, int b) {
    if (b == 0) return a;
    cout << "gcd(" << a << "," << b << ") -> gcd(" << b << "," << (a % b) << ")\n";
    return gcdRecursive(b, a % b);
}

int main() {
    cout << "GCD = " << gcdRecursive(48, 18) << "\n";
    return 0;
}

/*
OUTPUT:
GCD = gcd(48,18) -> gcd(18,12)
gcd(18,12) -> gcd(12,6)
gcd(12,6) -> gcd(6,0)
6
*/

