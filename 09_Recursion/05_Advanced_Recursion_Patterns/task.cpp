/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_Advanced_Recursion_Patterns task.cpp
│
│ REAL-WORLD SCENARIO:
│ Advanced recursion practice lab me rods puzzle, arrangements, staircase paths, recursive binary search, and paint bucket fill solve karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Tower of Hanoi n=3 moves print karo.
│ 2. Hanoi moves formula 2^n-1 comments me calculate karo.
│ 3. Print all permutations of "abc" using swap/backtracking.
│ 4. Staircase paths for n=4 using 1/2 steps.
│ 5. Recursive binary search implement karo.
│ 6. Flood fill 2D recursion implement karo.
│ 7. Recursion trees for Hanoi/permutation/staircase draw karo.
│ 8. Approach comparison table likho.
│
│ HINTS:
│ - Hanoi: move n-1 source->helper, disk n source->dest, n-1 helper->dest.
│ - Permutation: swap, recurse, swap back.
│ - Binary search: sorted array required.
│ - Flood fill: boundary and color checks first.
│
│ STARTER CODE:
│ void solve(int n){ if(base)return; solve(smaller); }
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / RECURSION TREE STATE:
│ Hanoi n=3 moves = 2^3-1=7.
│ Permutation abc has 3! = 6 outputs.
│ Staircase ways(4)=5.
│
│ DRY RUN:
│ Binary search: n -> n/2 -> n/4 -> 1.
│ Flood fill spreads from start cell to same-color neighbors.
│
│ FLOW OF EXECUTION:
│ input/problem state -> recursive choices -> base cases -> undo/unwind/output
│
│ COMPLEXITY CALCULATION:
│ - Hanoi recurrence gives 2^n-1 moves -> O(2^n).
│ - Permutation leaves n! and print n chars -> O(n*n!).
│ - Binary search n/2^k=1 -> k=log₂n.
│ - Flood fill visits R*C cells -> O(R*C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack: Hanoi/permutation/staircase O(n), binary search O(log n), flood fill O(R*C) worst.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int binarySearchRec(const vector<int>& a,int l,int r,int target){
    if(l>r) return -1;
    int mid=l+(r-l)/2;
    if(a[mid]==target) return mid;
    if(target<a[mid]) return binarySearchRec(a,l,mid-1,target);
    return binarySearchRec(a,mid+1,r,target);
}
int ways(int n){ if(n==0)return 1; if(n<0)return 0; return ways(n-1)+ways(n-2); }

int main() {
    vector<int> a={2,4,6,8,10};
    cout << "binary search 8 index = " << binarySearchRec(a,0,(int)a.size()-1,8) << "\n";
    cout << "staircase ways(4) = " << ways(4) << "\n";
    cout << "Hanoi/permutation/flood-fill complete solutions are in files 01,02,05.\n";
    return 0;
}

/*
OUTPUT:
binary search 8 index = 3
staircase ways(4) = 5
Hanoi/permutation/flood-fill complete solutions are in files 01,02,05.
*/

