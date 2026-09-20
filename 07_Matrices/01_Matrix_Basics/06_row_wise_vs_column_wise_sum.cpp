/*
═══════════════════════════════════════════════
 ROW-WISE VS COLUMN-WISE SUM
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 On a school report card you sometimes need a student-wise total and
 sometimes a subject-wise total. Row-wise and column-wise sums in a matrix
 capture exactly the same idea.

 📖 THEORY:
 - Row-wise sum: keep one row fixed and add up its columns.
 - Column-wise sum: keep one column fixed and add up its rows.
 - In both cases every element contributes exactly once.
 - Changing the loop direction changes the meaning of the output.
 - Time is the same O(R*C), but the two result arrays differ in size.

 ASCII VISUAL / MEMORY DIAGRAM:
 Matrix:
  1  2  3   row0 sum = 6
  4  5  6   row1 sum = 15

 col sums:
 c0: 1+4=5, c1: 2+5=7, c2: 3+6=9

 🧠 LOGIC — STEP BY STEP:
 Step 1: Allocate rowSum[] of size R and colSum[] of size C.
    WHY: one counter is needed per row and per column.
 Step 2: For each row r, loop each column c and add A[r][c] to rowSum[r].
    WHY: walking row by row accumulates the total of each row.
 Step 3: For each column c, loop each row r and add A[r][c] to colSum[c].
    WHY: walking column by column accumulates the total of each column.
 Step 4: Print both arrays.
    WHY: rowSum shows per-student totals, colSum shows per-subject totals.

 DRY RUN:
 Row sums:
 r0: 0+1+2+3 = 6
 r1: 0+4+5+6 = 15
 Column sums:
 c0: 0+1+4 = 5
 c1: 0+2+5 = 7
 c2: 0+3+6 = 9

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Row sum visits R*C elements.
 - Column sum also visits R*C elements.
 - If both are computed separately, visits = 2*R*C.
 -> Time Complexity = O(R*C).

 SPACE COMPLEXITY CALCULATION:
 - Row sums array size R.
 - Column sums array size C.
 -> Extra Space Complexity = O(R+C).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6}};
    int rows = A.size(), cols = A[0].size();
    vector<int> rowSum(rows, 0), colSum(cols, 0);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) rowSum[r] += A[r][c];
    }
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) colSum[c] += A[r][c];
    }

    cout << "Row sums: ";
    for (int x : rowSum) cout << x << " ";
    cout << "\nColumn sums: ";
    for (int x : colSum) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Row sums: 6 15
Column sums: 5 7 9
*/

