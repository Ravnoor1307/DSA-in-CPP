/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_first_recursion_program.cpp
│
│ REAL-WORLD SCENARIO:
│ School assembly me roll numbers 1 se n tak announce karne hain. Function pehle chhote group ko print karwata hai, phir current number print karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Goal: print 1 to n.
│ 2. Base case: if n==0, return.
│ 3. Recursive call first: print1ToN(n-1).
│ 4. Print current n after recursive call.
│ 5. Calls neeche jaati hain, prints unwind par hoti hain.
│
│ ASCII VISUAL / CALL STACK STATE:
│ print1ToN(3)
│    ↓ call first
│ print1ToN(2)
│    ↓
│ print1ToN(1)
│    ↓
│ print1ToN(0) base returns
│    ↑ print 1
│    ↑ print 2
│    ↑ print 3
│ Output: 1 2 3
│
│ DRY RUN:
│ n=3 calls down: 3 -> 2 -> 1 -> 0
│ n=0 base returns.
│ unwind: print 1, print 2, print 3.
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Function called for n,n-1,...,0: n+1 calls.
│ - Printing happens n times.
│ - Total work proportional to n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Deepest call stack depth = n+1.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print1ToN(int n) {
    if (n == 0) return; // base case
    print1ToN(n - 1);  // pehle smaller numbers print honge
    cout << n << " ";  // unwind par print
}

int main() {
    print1ToN(5);
    cout << "\n";
    return 0;
}

/*
OUTPUT:
1 2 3 4 5
*/

