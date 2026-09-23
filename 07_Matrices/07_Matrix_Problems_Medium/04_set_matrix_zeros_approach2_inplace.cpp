/*
═══════════════════════════════════════════════
 SET MATRIX ZEROES — APPROACH 2 (IN-PLACE, O(1) SPACE)
 ⏱️ TIME COMPLEXITY: O(R*C) — constant number of passes
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The spreadsheet is huge and no extra memory is allowed. The
 solution reuses the sheet itself: the first row and first column
 act like sticky-note markers telling which rows and columns must
 be cleared.

 📖 THEORY:
 - Use the first row and first column of the matrix itself as
   marker arrays.
 - First record whether the real first row / first column
   originally contain a zero (two flags).
 - Each inner zero marks A[i][0] and A[0][j]; then the markers
   drive the update.
 - Finally, the two flags decide whether the first row/column are
   themselves zeroed.

 ASCII DIAGRAM:
 Input:
 1 1 1
 1 0 1
 1 1 1

 zero at (1,1) marks:
 A[1][0]=0, A[0][1]=0

 Marker state:
 1 0 1
 0 0 1
 1 1 1

 Final:
 1 0 1
 0 0 0
 1 0 1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Record firstRowZero / firstColZero flags.
    WHY: The markers occupy the first row/column, so their original
    state must be saved before it is overwritten.
 Step 2: Scan inner cells; when A[r][c]==0, set A[r][0]=0 and
    A[0][c]=0.
    WHY: The first row/column act as sticky-note markers for every
    zero found.
 Step 3: Re-scan inner cells and zero any cell whose row marker or
    column marker is 0.
    WHY: A marker fires exactly when that row/column must be
    cleared.
 Step 4: Apply the flags to the first row and first column.
    WHY: The markers encoded only inner-cell information; the real
    first row/col state came from the flags.

 DRY RUN:
 firstRowZero=false, firstColZero=false
 scan inner: A[1][1]=0 -> mark row1 and col1
 inner update: if A[i][0]==0 or A[0][j]==0 then A[i][j]=0
 flags are false, so first row/col keep their values except marker
 impact.

 FLOW OF EXECUTION:
 input matrix -> save first-row/col flags -> mark from inner zeros -> update inner cells -> apply flags -> output

 TIME COMPLEXITY CALCULATION:
 - First row scan: C cells.
 - First col scan: R cells.
 - Marker scan of inner: (R-1)*(C-1).
 - Update scan of inner: (R-1)*(C-1).
 - Total = C + R + 2(R-1)(C-1), dominated by R*C.
 -> Time Complexity = O(R*C). For n*n, O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Only two boolean flags are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void printMatrix(const vector<vector<int>>& A) {
    for (const auto& row : A) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

void setZeroesInPlace(vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    bool firstRowZero = false, firstColZero = false;

    for (int c = 0; c < cols; c++) if (A[0][c] == 0) firstRowZero = true;
    for (int r = 0; r < rows; r++) if (A[r][0] == 0) firstColZero = true;

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (A[r][c] == 0) {
                A[r][0] = 0; // row marker
                A[0][c] = 0; // column marker
            }
        }
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (A[r][0] == 0 || A[0][c] == 0) A[r][c] = 0;
        }
    }

    if (firstRowZero) for (int c = 0; c < cols; c++) A[0][c] = 0;
    if (firstColZero) for (int r = 0; r < rows; r++) A[r][0] = 0;
}

int main() {
    vector<vector<int>> A = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroesInPlace(A);
    cout << "After set zeroes in-place:\n";
    printMatrix(A);
    return 0;
}

/*
OUTPUT:
After set zeroes in-place:
1 0 1
0 0 0
1 0 1
*/

