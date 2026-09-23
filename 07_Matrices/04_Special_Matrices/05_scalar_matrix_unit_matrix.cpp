/*
═══════════════════════════════════════════════
 SCALAR MATRIX & UNIT MATRIX
 ⏱️ TIME COMPLEXITY: O(n²) — single pass over all cells
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The same official stamp is applied repeatedly down the diagonal of
 an attendance sheet and every other cell is left blank — that is a
 scalar matrix. If the repeated diagonal stamp happens to be the
 value 1, the result is the unit/identity matrix.

 📖 THEORY:
 - A scalar matrix is a diagonal matrix where every diagonal entry
   equals the same constant k and every off-diagonal entry is 0.
 - When k = 1 the scalar matrix becomes the unit/identity matrix.
 - Checking is one pass: verify A[i][i]==k for the diagonal and
   A[i][j]==0 for all off-diagonal cells.

 ASCII DIAGRAM:
 Scalar matrix k=5:
 5 0 0
 0 5 0
 0 0 5

 Unit matrix k=1:
 1 0 0
 0 1 0
 0 0 1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Read k = A[0][0].
    WHY: In a scalar matrix every diagonal value must equal k, so
    the first diagonal cell is the reference constant.
 Step 2: For each cell, if i==j check A[i][j]==k; otherwise check
    A[i][j]==0.
    WHY: These are exactly the two rules that define a scalar matrix.
 Step 3: Any violation means not scalar; if all pass it is scalar,
    and if k==1 it is also the unit matrix.

 DRY RUN:
 Check scalar:
 choose k = A[0][0]
 Scalar candidate k=5:
 5 0 0
 0 5 0
 0 0 5
 i==j: A[0][0]=5 ✓ A[1][1]=5 ✓ A[2][2]=5 ✓
 i!=j: all off-diagonal cells are 0 ✓
 -> scalar matrix = YES
 Unit candidate k=1:
 1 0 0
 0 1 0
 0 0 1
 diagonal vs k=1 ✓, off-diagonal all 0 ✓
 -> unit matrix is also scalar = YES

 FLOW OF EXECUTION:
 read k=A[0][0] -> nested loop cell checks -> any mismatch? -> NO, else YES

 TIME COMPLEXITY CALCULATION:
 - Two nested loops visit n*n cells.
 - Each cell needs one condition check.
 -> Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Only scalar k and loop variables are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isScalarMatrix(const vector<vector<int>>& A) {
    int n = A.size();
    int k = A[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && A[i][j] != k) return false;
            if (i != j && A[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> scalar = {{5,0,0},{0,5,0},{0,0,5}};
    vector<vector<int>> unit = {{1,0,0},{0,1,0},{0,0,1}};
    cout << "scalar matrix? " << (isScalarMatrix(scalar) ? "YES" : "NO") << "\n";
    cout << "unit matrix is scalar? " << (isScalarMatrix(unit) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
scalar matrix? YES
unit matrix is scalar? YES
*/

