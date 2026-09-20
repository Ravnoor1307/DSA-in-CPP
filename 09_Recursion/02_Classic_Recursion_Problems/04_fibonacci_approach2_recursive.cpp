/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_fibonacci_approach2_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Family tree me har person ke do parents trace karte karte repeated ancestors baar-baar visit ho sakte hain. Naive Fibonacci recursion bhi same calls repeat karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base cases: fib(0)=0, fib(1)=1.
│ 2. Recursive case: fib(n)=fib(n-1)+fib(n-2).
│ 3. Har non-base call 2 aur calls banata hai.
│ 4. Same values repeated calculate hote hain.
│ 5. fib(5) me fib(3), fib(2) multiple times aate hain.
│ 6. Isliye time exponential hota hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ fib(5) recursion tree:
│
│                 fib(5)
│              /          \
│          fib(4)          fib(3)
│        /      \         /      \
│    fib(3)   fib(2)   fib(2)   fib(1)
│    /   \     /   \    /   \
│ fib(2) fib(1) ... repeated calls ...
│
│ Repetition:
│ fib(3) appears 2 times
│ fib(2) appears 3 times
│
│ DRY RUN:
│ fib(5)=fib(4)+fib(3)
│ fib(4)=fib(3)+fib(2)
│ fib(3)=fib(2)+fib(1)
│ repeated fib(3) and fib(2) recalculate hote hain.
│ answer=5.
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Each non-base call branches into 2 calls.
│ - Tree level 0 has 1 call, level 1 has up to 2, level 2 up to 4.
│ - Level k up to 2^k calls.
│ - Height about n, total calls bounded by 1+2+4+...+2^n = 2^(n+1)-1.
│ -> Time Complexity = O(2^n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Deepest path length is n.
│ -> Space Complexity = O(n) call stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    cout << "fib(5) naive recursion = " << fibRecursive(5) << "\n";
    cout << "Warning: repeated calls make it O(2^n).\n";
    return 0;
}

/*
OUTPUT:
fib(5) naive recursion = 5
Warning: repeated calls make it O(2^n).
*/

