/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_tower_of_hanoi.cpp
│
│ REAL-WORLD SCENARIO:
│ 3 rods aur disks puzzle me bade disk ko chhote disk ke upar nahi rakh sakte. Goal: saare disks source rod se destination rod par shift karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Move n-1 disks source se helper par.
│ 2. Move largest disk source se destination par.
│ 3. Move n-1 disks helper se destination par.
│ 4. Base case: n==0, no disk to move.
│ 5. Moves recurrence: T(n)=2*T(n-1)+1.
│ 6. Formula: total moves = 2^n - 1.
│
│ ASCII VISUAL / RECURSION TREE STATE:
│ n=3 rods: A(source), B(helper), C(destination)
│
│ Start:
│ A: [3][2][1]   B: []   C: []
│
│ Complete 7 moves:
│ 1. disk1 A->C
│ 2. disk2 A->B
│ 3. disk1 C->B
│ 4. disk3 A->C
│ 5. disk1 B->A
│ 6. disk2 B->C
│ 7. disk1 A->C
│
│ Formula check: 2^3 - 1 = 8 - 1 = 7
│
│ DRY RUN:
│ hanoi(3,A,C,B)
│ move hanoi(2,A,B,C)
│ move disk3 A->C
│ move hanoi(2,B,C,A)
│ total moves 7.
│
│ FLOW OF EXECUTION:
│ input/problem state -> recursive choices -> base cases -> undo/unwind/output
│
│ COMPLEXITY CALCULATION:
│ - Recurrence T(n)=2T(n-1)+1.
│ - Expand: T(n)=2(2T(n-2)+1)+1 = 4T(n-2)+3.
│ - Pattern gives T(n)=2^n-1.
│ -> Time Complexity = O(2^n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion depth n.
│ -> Space Complexity = O(n) call stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper, int& moveCount) {
    if (n == 0) return;
    towerOfHanoi(n - 1, source, helper, destination, moveCount);
    moveCount++;
    cout << moveCount << ". Move disk " << n << " from " << source << " to " << destination << "\n";
    towerOfHanoi(n - 1, helper, destination, source, moveCount);
}

int main() {
    int n = 3;
    int moves = 0;
    towerOfHanoi(n, 'A', 'C', 'B', moves);
    cout << "Total moves = " << moves << "\n";
    cout << "Formula 2^3 - 1 = 7\n";
    return 0;
}

/*
OUTPUT:
1. Move disk 1 from A to C
2. Move disk 2 from A to B
3. Move disk 1 from C to B
4. Move disk 3 from A to C
5. Move disk 1 from B to A
6. Move disk 2 from B to C
7. Move disk 1 from A to C
Total moves = 7
Formula 2^3 - 1 = 7
*/

