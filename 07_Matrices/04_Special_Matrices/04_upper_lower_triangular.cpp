/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_upper_lower_triangular.cpp
│
│ REAL-WORLD SCENARIO:
│ Building ke upper floors occupied aur lower region empty ho sakta hai. Triangular matrix me diagonal ke ek side zeros hote hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Upper triangular: primary diagonal ke neeche all zeros.
│ 2. Lower triangular: primary diagonal ke upar all zeros.
│ 3. Upper condition: if i > j, A[i][j] must be 0.
│ 4. Lower condition: if i < j, A[i][j] must be 0.
│ 5. Space optimization: non-zero triangle values store kar sakte hain.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ Upper triangular zero region:
│ 1 2 3
│ 0 5 6
│ 0 0 9
│
│ Lower triangular zero region:
│ 1 0 0
│ 4 5 0
│ 7 8 9
│
│ Shaded concept:
│ Upper -> below diagonal zero
│ Lower -> above diagonal zero
│
│ DRY RUN:
│ Upper check:
│ A[1][0]=0 pass
│ A[2][0]=0 pass
│ A[2][1]=0 pass
│ Lower check:
│ A[0][1], A[0][2], A[1][2] should be 0
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Check visits roughly n*(n-1)/2 off-diagonal cells.
│ - This is O(n²) comparisons.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only variables used for checking.
│ -> Extra Space Complexity = O(1).
│ - Optimized triangular storage can use n(n+1)/2 values.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isUpperTriangular(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) if (A[i][j] != 0) return false;
    }
    return true;
}

bool isLowerTriangular(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (A[i][j] != 0) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> upper = {{1,2,3},{0,5,6},{0,0,9}};
    vector<vector<int>> lower = {{1,0,0},{4,5,0},{7,8,9}};
    cout << "upper matrix is upper triangular? " << (isUpperTriangular(upper) ? "YES" : "NO") << "\n";
    cout << "lower matrix is lower triangular? " << (isLowerTriangular(lower) ? "YES" : "NO") << "\n";
    cout << "Triangular compact storage count for n=3 = " << 3 * (3 + 1) / 2 << "\n";
    return 0;
}

/*
OUTPUT:
upper matrix is upper triangular? YES
lower matrix is lower triangular? YES
Triangular compact storage count for n=3 = 6
*/

