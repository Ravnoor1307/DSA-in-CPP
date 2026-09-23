/*
═══════════════════════════════════════════════
 BOOLEAN MATRIX — ROW/COLUMN SET
 ⏱️ TIME COMPLEXITY: O(R*C) — two passes over all cells
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In an office access sheet, 1 means infected/active permission. If
 any cell is 1, its entire row and column must be set to active 1.

 📖 THEORY:
 - The matrix holds 0/1 values; if any cell is 1, its whole row and
   whole column must become 1.
 - Mutating in place directly would cascade (new 1s creating more
   1s), so marker arrays record which rows/columns must be set.
 - Two passes: mark from the original 1s, then fill the marked
   rows/columns.

 ASCII DIAGRAM:
 Input:
 1 0 0
 0 0 0
 0 0 1

 rowMark: row0, row2
 colMark: col0, col2

 Output:
 1 1 1
 1 0 1
 1 1 1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create rowMark[R] and colMark[C], all false.
    WHY: No row or column is marked yet.
 Step 2: First pass: if A[i][j]==1, set rowMark[i]=true and
    colMark[j]=true.
    WHY: Every original 1 demands its row and column become 1.
 Step 3: Second pass: set A[i][j]=1 if rowMark[i] or colMark[j].
    WHY: A marked row/column forces 1 in every cell it crosses.

 DRY RUN:
 First pass:
 (0,0)=1 -> row0=true, col0=true
 (2,2)=1 -> row2=true, col2=true
 Second pass:
 any cell whose rowMark or colMark is true becomes 1.

 FLOW OF EXECUTION:
 input matrix -> mark rows/cols from original 1s -> second pass fill -> output

 TIME COMPLEXITY CALCULATION:
 - First pass visits R*C cells.
 - Second pass visits R*C cells.
 - Total visits = 2*R*C.
 -> Time Complexity = O(R*C)

 SPACE COMPLEXITY CALCULATION:
 - rowMark stores R booleans.
 - colMark stores C booleans.
 -> Space Complexity = O(R+C)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void booleanMatrix(vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<bool> rowMark(rows, false), colMark(cols, false);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 1) {
                rowMark[i] = true;
                colMark[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowMark[i] || colMark[j]) A[i][j] = 1;
        }
    }
}

int main() {
    vector<vector<int>> A = {{1,0,0},{0,0,0},{0,0,1}};
    booleanMatrix(A);
    cout << "Boolean matrix after row/column set:\n";
    for (auto& row : A) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
Boolean matrix after row/column set:
1 1 1
1 0 1
1 1 1
*/

