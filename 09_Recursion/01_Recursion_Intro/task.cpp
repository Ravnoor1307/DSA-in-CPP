/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_Recursion_Intro task.cpp
│
│ REAL-WORLD SCENARIO:
│ Recursion practice lab me Russian dolls, countdown, call-stack, and sum tasks solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. print n to 1 recursively.
│ 2. print 1 to n recursively.
│ 3. countdown with base case likho.
│ 4. factorial call stack for fact(3) comments me draw karo.
│ 5. loop sum 1..n implement karo.
│ 6. recursive sum 1..n implement karo.
│ 7. recursion vs iteration comparison table comments me likho.
│
│ HINTS:
│ - Base case: n==0 or n==1.
│ - Print before call => n to 1.
│ - Call before print => 1 to n.
│ - Recursive sum: n + sum(n-1).
│
│ STARTER CODE:
│ void f(int n){ if(n==0)return; f(n-1); cout<<n; }
│
│ SOLUTION: Neeche compiled solution diya hai.
│
│ ASCII VISUAL / CALL STACK STATE:
│ nTo1(3): print3 -> print2 -> print1
│ oneToN(3): call down to 0, then print1 -> print2 -> print3
│ sum(3): 3 + sum(2), sum(2)=2+sum(1), sum(1)=1
│
│ DRY RUN:
│ oneToN calls: 3 -> 2 -> 1 -> 0, prints while returning.
│ recursiveSum(5) makes calls 5,4,3,2,1,0 and returns 15.
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Print functions make n+1 calls -> O(n).
│ - Sum loop runs n iterations -> O(n).
│ - Recursive sum makes n+1 calls -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive print/sum stack depth n+1 -> O(n).
│ - Loop sum extra variables only -> O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void oneToN(int n) {
    if (n == 0) return;
    oneToN(n - 1);
    cout << n << " ";
}
void nTo1(int n) {
    if (n == 0) return;
    cout << n << " ";
    nTo1(n - 1);
}
int recursiveSum(int n) {
    if (n == 0) return 0;
    return n + recursiveSum(n - 1);
}

int main() {
    cout << "1 to 5: "; oneToN(5);
    cout << "\n5 to 1: "; nTo1(5);
    cout << "\nrecursive sum 5 = " << recursiveSum(5) << "\n";
    return 0;
}

/*
OUTPUT:
1 to 5: 1 2 3 4 5
5 to 1: 5 4 3 2 1
recursive sum 5 = 15
*/

