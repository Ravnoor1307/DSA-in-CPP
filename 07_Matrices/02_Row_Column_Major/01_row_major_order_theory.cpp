/*
═══════════════════════════════════════════════
 ROW-MAJOR ORDER
 ⏱️ TIME COMPLEXITY: flattening O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You write rows of a notebook left to right. C++ flattens a matrix in memory
 like a notebook, row by row: that is the row-major order.

 📖 THEORY:
 - Row-major means row 0 is stored completely, then row 1 completely.
 - A 2D array is stored in memory like one single continuous array.
 - A[2][2] = {{16,20},{30,50}} flattens to [16,20,30,50].
 - Index formula: flatIndex = i*nCols + j.
 - C/C++ follows row-major order.

 ASCII VISUAL / MEMORY DIAGRAM:
 2D view:
 [16] [20]
 [30] [50]

 Row-major storage:
 [16] -> [20] -> [30] -> [50]
  r0c0    r0c1    r1c0    r1c1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Start at row 0.
    WHY: row-major begins filling memory from the first row.
 Step 2: Copy each cell of the current row to the flat array.
    WHY: all elements of a row are stored back to back.
 Step 3: Move to the next row.
    WHY: after row 0 the next block belongs to row 1.
 Step 4: Continue until all rows are copied.
    WHY: every cell must appear exactly once in the flat array.
 Step 5: Read flat[flatIndex] to recover any cell.
    WHY: the formula flatIndex = i*nCols + j maps back to the 2D position.

 DRY RUN:
 A[1][0]
 flatIndex = 1*2 + 0 = 2
 flat[2] = 30
 So A[1][0] is at row-major memory position 2.

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Flattening visits each matrix cell once.
 - R*C cells in total.
 -> Time Complexity = O(R*C).

 SPACE COMPLEXITY CALCULATION:
 - Flat vector stores R*C values.
 -> Space Complexity = O(R*C).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int A[2][2] = {{16, 20}, {30, 50}};
    vector<int> flat;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) flat.push_back(A[r][c]); // row-major push
    }
    cout << "Row-major flat storage: ";
    for (int x : flat) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Row-major flat storage: 16 20 30 50
*/

