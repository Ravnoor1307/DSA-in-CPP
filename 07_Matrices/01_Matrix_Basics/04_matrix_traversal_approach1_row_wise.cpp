/*
═══════════════════════════════════════════════
 ROW-WISE TRAVERSAL APPROACH
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A teacher checks the attendance register row by row: first all students of
 the first bench, then all students of the second bench. Row-wise traversal
 of a matrix works exactly the same way.

 📖 THEORY:
 - The outer loop runs over the rows.
 - The inner loop runs over the columns.
 - Visit order: A[0][0] -> A[0][1] -> A[0][2], then the next row.
 - With C++ row-major memory this is cache friendly.
 - Every element is visited exactly once.

 ASCII VISUAL / MEMORY DIAGRAM:
 Row-wise arrows:

  1  →  2  →  3
              ↓
  4  →  5  →  6
              ↓
  7  →  8  →  9

 Visit order: 1,2,3,4,5,6,7,8,9

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop r from 0 to R-1.
    WHY: each iteration processes one complete row.
 Step 2: Loop c from 0 to C-1.
    WHY: each iteration processes one cell inside the current row.
 Step 3: Print A[r][c].
    WHY: with row fixed and column changing, cells flow left to right.
 Step 4: After the inner loop, move to the next row.
    WHY: the row index advancing matches the row-major memory order.
 Step 5: Stop after the last row.
    WHY: all R*C cells have been visited exactly once.

 DRY RUN:
 For 3x3:
 r=0: visit 1 2 3
 r=1: visit 4 5 6
 r=2: visit 7 8 9
 Total visits = 9

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Outer loop runs R times.
 - Inner loop runs C times for each row.
 - Total visits = R*C.
 -> Time Complexity = O(R*C). For square n*n, O(n²).

 SPACE COMPLEXITY CALCULATION:
 - Only loop variables are used.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Row-wise traversal: ";
    for (int r = 0; r < (int)A.size(); r++) {
        for (int c = 0; c < (int)A[0].size(); c++) {
            cout << A[r][c] << " "; // row fixed, column changes
        }
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Row-wise traversal: 1 2 3 4 5 6 7 8 9
*/

