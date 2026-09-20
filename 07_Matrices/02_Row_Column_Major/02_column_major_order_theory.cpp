/*
═══════════════════════════════════════════════
 COLUMN-MAJOR ORDER
 ⏱️ TIME COMPLEXITY: flattening O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 If a building directory is maintained in floor-column order, you record all
 floors of column 0 first, then column 1, and so on. That is column-major
 order.

 📖 THEORY:
 - Column-major means column 0 is stored completely, then column 1 completely.
 - The flat order of the same 2D matrix can depend on the language/system
   layout.
 - A[2][2] = {{16,20},{30,50}} in column-major flattens to [16,30,20,50].
 - Formula: flatIndex = j*nRows + i.
 - Fortran/MATLAB traditionally use column-major order.

 ASCII VISUAL / MEMORY DIAGRAM:
 2D view:
 [16] [20]
 [30] [50]

 Column-major storage:
 [16] -> [30] -> [20] -> [50]
  r0c0    r1c0    r0c1    r1c1

 Row-major vs Column-major:
 Row-major:    [16,20,30,50]
 Column-major: [16,30,20,50]

 🧠 LOGIC — STEP BY STEP:
 Step 1: Start at column 0.
    WHY: column-major begins filling memory from the first column.
 Step 2: Copy each cell of the current column to the flat array.
    WHY: all elements of a column are stored back to back.
 Step 3: Move to the next column.
    WHY: after column 0 the next block belongs to column 1.
 Step 4: Continue until all columns are copied.
    WHY: every cell must appear exactly once in the flat array.
 Step 5: Read flat[flatIndex] to recover any cell.
    WHY: the formula flatIndex = j*nRows + i maps back to the 2D position.

 DRY RUN:
 A[0][1]
 flatIndex = j*nRows + i = 1*2 + 0 = 2
 flat[2] = 20

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Flattening column-wise also visits every cell once.
 - R*C total visits.
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
    for (int c = 0; c < 2; c++) {
        for (int r = 0; r < 2; r++) flat.push_back(A[r][c]); // column-major style
    }
    cout << "Column-major flat storage: ";
    for (int x : flat) cout << x << " ";
    cout << "\n";
    cout << "Table: C++ row-major, Fortran/MATLAB column-major.\n";
    return 0;
}

/*
OUTPUT:
Column-major flat storage: 16 30 20 50
Table: C++ row-major, Fortran/MATLAB column-major.
*/

