/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_factorial_approach2_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Permutation counting me 4! ko 4 * 3! maana ja sakta hai. Same problem ka smaller version call karna recursion ka natural use hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: if n==0 or n==1 return 1.
│ 2. Recursive case: fact(n) = n * fact(n-1).
│ 3. Calls down jaati hain until fact(1).
│ 4. Return hote waqt multiplication hoti hai.
│ 5. Har call ka apna n value stack frame me hota hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ fact(4) complete call stack journey:
│
│ PUSH fact(4) needs 4*fact(3)
│ PUSH fact(3) needs 3*fact(2)
│ PUSH fact(2) needs 2*fact(1)
│ PUSH fact(1) returns 1
│
│ UNWIND:
│ fact(2)=2*1=2
│ fact(3)=3*2=6
│ fact(4)=4*6=24
│
│ DRY RUN:
│ 4! -> 4 * 3!
│ 3! -> 3 * 2!
│ 2! -> 2 * 1!
│ 1! -> 1
│ values back: 2, 6, 24.
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Calls: fact(n), fact(n-1), ..., fact(1): n calls.
│ - Each call constant multiplication/condition.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Deepest stack has n frames.
│ -> Space Complexity = O(n) call stack.
│ APPROACH COMPARISON TABLE:
│ Loop = cashier multiplies in one notebook, O(n) time/O(1) space.
│ Recursion = assistant asks smaller factorial, O(n) time/O(n) stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1); // smaller factorial
}

int main() {
    cout << "4! recursive = " << factorialRecursive(4) << "\n";
    cout << "Comparison: loop O(n)/O(1), recursion O(n)/O(n) stack.\n";
    return 0;
}

/*
OUTPUT:
4! recursive = 24
Comparison: loop O(n)/O(1), recursion O(n)/O(n) stack.
*/

