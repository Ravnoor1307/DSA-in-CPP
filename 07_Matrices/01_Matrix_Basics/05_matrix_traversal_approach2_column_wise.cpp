/*
═══════════════════════════════════════════════
 COLUMN-WISE TRAVERSAL APPROACH
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A building lift visits flats column by column: first all floors of the first
 column, then all floors of the second column. Column-wise traversal of a
 matrix simply swaps the loop order.

 📖 THEORY:
 - The outer loop runs over the columns.
 - The inner loop runs over the rows.
 - Visit order: A[0][0] -> A[1][0] -> A[2][0], then the next column.
 - In C++ row-major memory this makes non-contiguous jumps.
 - Row-wise is usually cache friendly, column-wise may be slower for large
   arrays.

 ASCII VISUAL / MEMORY DIAGRAM:
 Column-wise arrows:

  1     2     3
  ↓     ↓     ↓
  4     5     6
  ↓     ↓     ↓
  7     8     9

 Visit order: 1,4,7,2,5,8,3,6,9

 Row-wise vs Column-wise cache note:
 C++ stores rows continuously, so row-wise accesses nearby memory locations.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop c from 0 to C-1.
    WHY: each iteration processes one complete column.
 Step 2: Loop r from 0 to R-1.
    WHY: each iteration processes one cell inside the current column.
 Step 3: Print A[r][c].
    WHY: with column fixed and row changing, cells flow top to bottom.
 Step 4: After the inner loop, move to the next column.
    WHY: the whole matrix is scanned one vertical strip at a time.
 Step 5: Stop after the last column.
    WHY: all R*C cells have been visited exactly once.

 Visually on the grid:
  1     2     3
  ↓     ↓     ↓   each column is walked top-to-bottom in turn.
  4     5     6
  ↓     ↓     ↓
  7     8     9

 DRY RUN:
 For 3x3:
 c=0: visit 1 4 7
 c=1: visit 2 5 8
 c=2: visit 3 6 9
 Total visits = 9

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Outer loop runs C times.
 - Inner loop runs R times for each column.
 - Total visits = C*R = R*C.
 -> Time Complexity = O(R*C). For square n*n, O(n²).
 - Cache behavior differs, asymptotical time is the same.

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
    cout << "Column-wise traversal: ";
    for (int c = 0; c < (int)A[0].size(); c++) {
        for (int r = 0; r < (int)A.size(); r++) {
            cout << A[r][c] << " "; // column fixed, row changes
        }
    }
    cout << "\n";
    cout << "Comparison: row-wise and column-wise both O(R*C), but row-wise is cache friendly in C++.\n";
    return 0;
}

/*
OUTPUT:
Column-wise traversal: 1 4 7 2 5 8 3 6 9
Comparison: row-wise and column-wise both O(R*C), but row-wise is cache friendly in C++.
*/

