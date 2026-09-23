/*
═══════════════════════════════════════════════
 SYMMETRIC MATRIX
 ⏱️ TIME COMPLEXITY: O(n²) — n(n-1)/2 mirror comparisons
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Look into a mirror placed along a line: the left and right
 reflections look identical. A symmetric matrix has the same
 property — mirror pairs across the primary diagonal are equal.

 📖 THEORY:
 - A symmetric matrix is square and satisfies A[i][j] == A[j][i]
   for every pair of indices.
 - The primary diagonal mirrors onto itself, so diagonal elements
   never cause a mismatch.
 - Optimization: only the upper triangle (j > i) needs comparing;
   each mirror pair is then checked exactly once.

 ASCII DIAGRAM:
 A:
 1 2 3
 2 5 6
 3 6 9

 Mirror pairs:
 A[0][1]=2 and A[1][0]=2
 A[0][2]=3 and A[2][0]=3
 A[1][2]=6 and A[2][1]=6

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop over the upper triangle: i from 0..n-1, j from i+1..n-1.
    WHY: Pair (i,j) and (j,i) are mirrors; checking one side of the
    diagonal covers both.
 Step 2: Compare A[i][j] with A[j][i].
    WHY: Any mismatch means the mirror condition fails.
 Step 3: If all pairs match, return true (symmetric); otherwise
    return false.
    WHY: Symmetry requires equality for ALL pairs.

 DRY RUN:
 Check upper triangle:
 (0,1) compare with (1,0): 2 == 2  ✓
 (0,2) compare with (2,0): 3 == 3  ✓
 (1,2) compare with (2,1): 6 == 6  ✓
 all pairs pass -> Symmetric = YES

 FLOW OF EXECUTION:
 matrix -> upper triangle loop -> A[i][j]==A[j][i]? -> any mismatch -> NO, else YES

 TIME COMPLEXITY CALCULATION:
 - Upper triangle pairs count = n*(n-1)/2.
 - This is approximately n²/2 comparisons.
 -> Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Only loop variables are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isSymmetric(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Compare A[" << i << "][" << j << "] and A[" << j << "][" << i << "]\n";
            if (A[i][j] != A[j][i]) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{2,5,6},{3,6,9}};
    cout << "Symmetric? " << (isSymmetric(A) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Compare A[0][1] and A[1][0]
Compare A[0][2] and A[2][0]
Compare A[1][2] and A[2][1]
Symmetric? YES
*/

