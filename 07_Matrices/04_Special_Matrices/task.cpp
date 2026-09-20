/*
┌────────────────────────────────────────────────────────────┐
│ FILE: task.cpp
│
│ REAL-WORLD SCENARIO:
│ Pattern-recognition practice lab me tumhe identity, diagonal, symmetric, triangular, scalar matrices detect karni hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. n=3 identity matrix generate karo.
│ 2. Diagonal matrix compact array se print karo.
│ 3. Symmetric matrix check karo.
│ 4. Upper triangular matrix check karo.
│ 5. Lower triangular matrix check karo.
│ 6. Scalar matrix check karo.
│ 7. Unit matrix identify karo.
│ 8. Storage optimization formulas comment me likho.
│
│ HINTS:
│ - i==j diagonal.
│ - i>j below diagonal.
│ - i<j above diagonal.
│ - symmetric ke liye only j>i compare enough.
│
│ STARTER CODE IDEA:
│ for i -> for j -> apply condition.
│
│ SOLUTION: Neeche compact checks hain.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ Identity 3x3:
│ 1 0 0
│ 0 1 0
│ 0 0 1
│ Symmetric mirror pair: A[0][2] with A[2][0]
│
│ DRY RUN:
│ Upper triangular checks below diagonal:
│ (1,0),(2,0),(2,1) all zero.
│ Lower triangular checks above diagonal:
│ (0,1),(0,2),(1,2) all zero.
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Most special matrix checks visit n² or half n² cells.
│ - n(n-1)/2 comparisons simplifies to O(n²).
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Checks use constant extra variables.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isSym(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (A[i][j] != A[j][i]) return false;
    return true;
}

int main() {
    vector<vector<int>> I(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) I[i][i] = 1;
    vector<vector<int>> S = {{1,2,3},{2,5,6},{3,6,9}};
    cout << "Identity generated first row: ";
    for (int x : I[0]) cout << x << " ";
    cout << "\nSymmetric? " << (isSym(S) ? "YES" : "NO") << "\n";
    cout << "Diagonal compact space O(n), full matrix O(n^2).\n";
    cout << "Triangular compact cells n(n+1)/2.\n";
    return 0;
}

/*
OUTPUT:
Identity generated first row: 1 0 0
Symmetric? YES
Diagonal compact space O(n), full matrix O(n^2).
Triangular compact cells n(n+1)/2.
*/

