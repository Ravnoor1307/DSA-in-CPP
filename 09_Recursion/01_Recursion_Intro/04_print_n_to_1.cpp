/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_print_n_to_1.cpp
│
│ REAL-WORLD SCENARIO:
│ Lift countdown me agar current floor pehle announce karo then neeche jao, output n to 1 aata hai. Agar call pehle karo, output ulta ho jata hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Print before recursive call => descending order n to 1.
│ 2. Recursive call before print => ascending order 1 to n.
│ 3. Recursion ka order counter-intuitive lag sakta hai.
│ 4. Call stack delayed work ko yaad rakhta hai.
│ 5. Same base case, sirf statement order change hota hai.
│
│ ASCII VISUAL / CALL STACK STATE:
│ Side-by-side for n=3:
│
│ print first version:       call first version:
│ print 3                   call f(2)
│ call f(2)                 call f(1)
│ print 2                   call f(0)
│ call f(1)                 print 1
│ print 1                   print 2
│ output 3 2 1              print 3 -> output 1 2 3
│
│ DRY RUN:
│ nTo1(3): print3 -> nTo1(2) print2 -> nTo1(1) print1.
│ oneToNByOrder(3): calls to 0 first, then prints 1,2,3 while returning.
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Both functions make n+1 calls.
│ - Both print n values.
│ -> Time Complexity = O(n) for each.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Both use call stack depth n+1.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printNTo1(int n) {
    if (n == 0) return;
    cout << n << " "; // print pehle => descending
    printNTo1(n - 1);
}

void print1ToNByCallFirst(int n) {
    if (n == 0) return;
    print1ToNByCallFirst(n - 1);
    cout << n << " "; // print baad me => ascending
}

int main() {
    cout << "Print before call: ";
    printNTo1(5);
    cout << "\nCall before print: ";
    print1ToNByCallFirst(5);
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Print before call: 5 4 3 2 1
Call before print: 1 2 3 4 5
*/

