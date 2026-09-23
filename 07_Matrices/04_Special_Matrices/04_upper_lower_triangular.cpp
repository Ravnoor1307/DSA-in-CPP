/*
═══════════════════════════════════════════════
 UPPER & LOWER TRIANGULAR MATRICES
 ⏱️ TIME COMPLEXITY: O(n²) — n(n-1)/2 region checks
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a building only the upper floors may be occupied while the
 lower region stays empty — or the opposite. A triangular matrix
 is the same idea: whole slices of the matrix are forced to zero.

 📖 THEORY:
 - Upper triangular: every entry BELOW the primary diagonal
   (i > j) is zero; the diagonal and everything above is free.
 - Lower triangular: every entry ABOVE the primary diagonal
   (i < j) is zero.
 - Check conditions: upper needs A[i][j]==0 for i>j; lower needs
   A[i][j]==0 for i<j.
 - Space optimization: only the non-zero triangle is meaningful,
   storing n(n+1)/2 values instead of n².

 ASCII DIAGRAM:
 Upper triangular zero region:
 1 2 3
 0 5 6
 0 0 9

 Lower triangular zero region:
 1 0 0
 4 5 0
 7 8 9

 Shaded concept:
 Upper -> below diagonal zero
 Lower -> above diagonal zero

 🧠 LOGIC — STEP BY STEP:
 Step 1: For upper: loop i from 1..n-1, j from 0..i-1 and require
    A[i][j]==0.
    WHY: Condition i>j describes exactly the below-diagonal region.
 Step 2: For lower: loop i from 0..n-1, j from i+1..n-1 and require
    A[i][j]==0.
    WHY: Condition i<j describes exactly the above-diagonal region.
 Step 3: Any non-zero cell inside the checked region fails the test.
    WHY: A single violation breaks the triangular property.

 DRY RUN:
 Upper check:
 A[1][0]=0 pass
 A[2][0]=0 pass
 A[2][1]=0 pass
 -> upper triangular = YES
 Lower check:
 A[0][1]=0 pass
 A[0][2]=0 pass
 A[1][2]=0 pass
 -> lower triangular = YES

 FLOW OF EXECUTION:
 matrix -> loop over i>j / i<j region -> any A[i][j]!=0? -> NO, else YES

 TIME COMPLEXITY CALCULATION:
 - Checks visit roughly n*(n-1)/2 off-diagonal cells.
 - This is O(n²) comparisons.
 -> Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Only variables used for checking.
 -> Extra Space Complexity = O(1)
 - Optimized triangular storage can use n(n+1)/2 values.
═══════════════════════════════════════════════
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

