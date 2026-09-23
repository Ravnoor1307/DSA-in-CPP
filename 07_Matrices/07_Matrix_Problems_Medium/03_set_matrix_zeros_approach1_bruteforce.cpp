/*
═══════════════════════════════════════════════
 SET MATRIX ZEROES — APPROACH 1 (BRUTE FORCE)
 ⏱️ TIME COMPLEXITY: O(n³) for n×n — worst case R*C*(R+C)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a spreadsheet, if one cell is a defective zero, its whole row
 and whole column must be cleared. The brute-force method marks the
 row and column of every original zero in a result copy.

 📖 THEORY:
 - The problem: if a cell is 0, its entire row and column become 0.
 - Brute force writes into a COPY and reads zeros only from the
   original, so freshly created zeros never cascade.
 - It is simple and correct but very wasteful: every zero re-clears
   an entire row and column.

 ASCII DIAGRAM:
 Input:
 1 1 1
 1 0 1
 1 1 1

 Zero at (1,1):
 row1 -> all zero
 col1 -> all zero

 Output:
 1 0 1
 0 0 0
 1 0 1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Copy matrix A into result.
    WHY: The result is modified, but zero-detection reads the
    untouched original.
 Step 2: Scan every cell of the ORIGINAL.
    WHY: Only original zeros decide the outcome; generated zeros
    must not trigger new clearings.
 Step 3: For each original zero (i,j), zero out result row i and
    result column j.
    WHY: A single zero mandates clearing its entire row and column.
 Step 4: Return result.
    WHY: It holds the completed state.

 DRY RUN:
 Scan cells:
 (0,0)=1 -> no action
 (1,1)=0 -> found
 clear row1: 3 assignments
 clear col1: 3 assignments
 continue scanning original matrix only

 FLOW OF EXECUTION:
 input matrix -> copy to result -> scan original for zeros -> clear row+col in copy -> print result

 TIME COMPLEXITY CALCULATION:
 - Scan all cells: R*C.
 - For each zero, clearing a row costs C and clearing a column
   costs R.
 - Worst case every cell is zero: R*C*(R+C) operations.
 - For an n*n matrix: n²*(2n) = 2n³.
 -> Time Complexity = O(n³) for square matrices

 SPACE COMPLEXITY CALCULATION:
 - Copy/result matrix stores R*C cells.
 -> Space Complexity = O(R*C)
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

vector<vector<int>> setZeroesBrute(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> result = A;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 0) {
                cout << "Original zero at (" << i << "," << j << ") -> clear row and column\n";
                for (int c = 0; c < cols; c++) result[i][c] = 0;
                for (int r = 0; r < rows; r++) result[r][j] = 0;
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> A = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> ans = setZeroesBrute(A);
    cout << "After set zeroes brute:\n";
    printMatrix(ans);
    return 0;
}

/*
OUTPUT:
Original zero at (1,1) -> clear row and column
After set zeroes brute:
1 0 1
0 0 0
1 0 1
*/

