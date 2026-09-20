/*
═══════════════════════════════════════════════
 MATRIX MEMORY LAYOUT — ROW-MAJOR STORAGE
 ⏱️ TIME COMPLEXITY: address computation O(1); full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A classroom seating chart is a 2D grid, but an attendance register is a
 linear list. A matrix also looks 2D on the screen, yet in memory it is
 stored as one continuous 1D block in row-major order.

 📖 THEORY:
 - Think of the matrix A[rows][cols] like a grid.
 - C/C++ uses the row-major layout: first all elements of row 0, then row 1.
 - The offset of element A[i][j] = i * cols + j.
 - Address = base + offset * sizeof(datatype).
 - Solve the formula with actual numbers instead of just memorizing it.

 ASCII VISUAL / MEMORY DIAGRAM:
 Matrix A[2][2]

       col0  col1
 row0   16    20
 row1   30    50

 Row-major flat memory:
 index:     0     1     2     3
 value:   [16]  [20]  [30]  [50]
 address: 1000  1004  1008  1012   (sizeof(int)=4)

 A[1][1] offset = 1*2 + 1 = 3
 address = 1000 + 3*4 = 1012

 🧠 LOGIC — STEP BY STEP:
 Step 1: Visualize the matrix A[rows][cols] as a grid.
    WHY: Keeps the row/column addressing obvious.
 Step 2: Lay the grid out in row-major order in memory.
    WHY: C/C++ stores row 0 fully, then row 1, and so on.
 Step 3: Compute the offset of A[i][j] = i * cols + j.
    WHY: i full rows (each of `cols` elements) are skipped, then j columns.
 Step 4: Convert the element offset to a byte offset using the element size.
    WHY: the base is a byte address, so every element occupies sizeof bytes.
 Step 5: Add the byte offset to the base address.
    WHY: base + offset * size gives the exact memory address of the cell.

 DRY RUN:
 For A[1][1]:
 rows=2, cols=2, base=1000, size=4
 offset = i*cols + j = 1*2 + 1 = 3
 bytes  = offset*size = 3*4 = 12
 final address = 1000 + 12 = 1012

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Address calculation does fixed arithmetic: multiply, add, multiply, add.
 - Number of arithmetic operations does not depend on rows or cols.
 -> Time Complexity = O(1).

 SPACE COMPLEXITY CALCULATION:
 - Only variables base, i, j, cols, size are used.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int A[2][2] = {{16, 20}, {30, 50}};
    int rows = 2, cols = 2;
    long long base = 1000;
    int elementSize = sizeof(int);
    int i = 1, j = 1;

    cout << "2D grid:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) cout << setw(4) << A[r][c];
        cout << "\n";
    }

    cout << "\nRow-major flat memory: ";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) cout << A[r][c] << " "; // row-wise memory order
    }
    cout << "\n";

    int offset = i * cols + j; // Hinglish: row skip karke column add
    long long address = base + 1LL * offset * elementSize;
    cout << "Address of A[" << i << "][" << j << "] = " << base
         << " + (" << i << "*" << cols << " + " << j << ")*" << elementSize
         << " = " << address << "\n";
    return 0;
}

/*
OUTPUT:
2D grid:
  16  20
  30  50

Row-major flat memory: 16 20 30 50
Address of A[1][1] = 1000 + (1*2 + 1)*4 = 1012
*/

