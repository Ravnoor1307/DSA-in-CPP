/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_josephus_problem.cpp
│
│ REAL-WORLD SCENARIO:
│ Circle game me log khade hain, har k-th person eliminate hota hai. Last survivor find karna Josephus problem hai, recursion ka fun classic example.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. People 0 to n-1 indexed in circle.
│ 2. After first elimination, problem n-1 people par reduce hota hai.
│ 3. Recurrence: J(n,k) = (J(n-1,k) + k) % n.
│ 4. Base case: J(1,k)=0.
│ 5. 1-indexed answer ke liye +1 karo.
│
│ ASCII VISUAL / NUMBER STATE:
│ n=5, k=2 circle:
│
│        1
│    5       2  X eliminate
│      4   3
│
│ order elimination (1-index idea): 2,4,1,5
│ survivor = 3
│
│ Recursive formula zero-index:
│ J(1)=0
│ J(2)=(0+2)%2=0
│ J(3)=(0+2)%3=2
│ J(4)=(2+2)%4=0
│ J(5)=(0+2)%5=2 -> one-index 3
│
│ DRY RUN:
│ J(1,2)=0
│ J(2,2)=0
│ J(3,2)=2
│ J(4,2)=0
│ J(5,2)=2
│ survivor position one-indexed = 2+1 = 3
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Function calls for n,n-1,...,1: n calls.
│ - Each call one addition and modulo.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth n.
│ -> Space Complexity = O(n).
│ APPROACH COMPARISON TABLE:
│ Simulation circle = physically remove every k-th person, can be O(n*k) or O(n²) depending structure.
│ Recursive formula = shrink circle mathematically, O(n) time/O(n) stack.
│ Iterative formula = same recurrence loop, O(n) time/O(1) space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int josephusZeroIndexed(int n, int k) {
    if (n == 1) return 0;
    return (josephusZeroIndexed(n - 1, k) + k) % n;
}

int main() {
    int n = 5, k = 2;
    int survivor = josephusZeroIndexed(n, k) + 1;
    cout << "Josephus survivor for n=5, k=2 is " << survivor << "\n";
    return 0;
}

/*
OUTPUT:
Josephus survivor for n=5, k=2 is 3
*/

