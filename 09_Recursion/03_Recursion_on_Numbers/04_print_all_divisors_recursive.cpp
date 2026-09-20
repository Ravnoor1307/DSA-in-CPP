/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_print_all_divisors_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ School factor chart me number ke all divisors tick karne hain. Recursion current candidate 1 se n tak check karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function printDivisors(n, current).
│ 2. Base case: current > n, stop.
│ 3. If n % current == 0, print current.
│ 4. Recursive call current+1.
│ 5. Simple method O(n), optimized sqrt method later possible.
│
│ ASCII VISUAL / NUMBER STATE:
│ n=12
│ candidates:
│ 1 yes
│ 2 yes
│ 3 yes
│ 4 yes
│ 5 no
│ 6 yes
│ 7 no ...
│ 12 yes
│ output: 1 2 3 4 6 12
│
│ DRY RUN:
│ current=1 divides -> print
│ current=2 divides -> print
│ current=3 divides -> print
│ current=4 divides -> print
│ current=5 no
│ ... current=12 divides -> print
│ current=13 base stop
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - current goes from 1 to n then n+1 base.
│ - Total n divisibility checks.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth n+1.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printDivisors(int n, int current) {
    if (current > n) return;
    if (n % current == 0) cout << current << " ";
    printDivisors(n, current + 1);
}

int main() {
    cout << "Divisors of 12: ";
    printDivisors(12, 1);
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Divisors of 12: 1 2 3 4 6 12
*/

