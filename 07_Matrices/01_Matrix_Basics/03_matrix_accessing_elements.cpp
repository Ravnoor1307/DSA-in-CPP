/*
═══════════════════════════════════════════════
 MATRIX ELEMENT ACCESS — A[i][j]
 ⏱️ TIME COMPLEXITY: access O(1); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a cinema hall, saying "Row 1, Column 2" instantly finds the exact seat.
 In a matrix, A[i][j] likewise gives the element at row i, column j.

 📖 THEORY:
 - Matrix indexing is generally 0-based.
 - A[i][j] means row i and column j.
 - The first index moves vertically (row), the second index moves
   horizontally (column).
 - Example: A[1][2] is the element at row 1, column 2.
 - Accessing an invalid index can give undefined behavior.

 ASCII VISUAL / MEMORY DIAGRAM:
 Matrix A[2][3]

        c0   c1   c2
 r0     10   20   30
 r1     40   50   60  ◄── A[1][2]

 A[1][2] = row 1, column 2 = 60

 🧠 LOGIC — STEP BY STEP:
 Step 1: Identify the target index A[i][j].
    WHY: i picks the row, j picks the column.
 Step 2: Move to row i.
    WHY: the row index selects the horizontal strip of elements.
 Step 3: Go to column j inside that row.
    WHY: the column index selects the exact element in the strip.
 Step 4: Read the value.
    WHY: the compiler computes the address using the row-major formula.
 Step 5: Print it.
    WHY: verifies the accessed element against the expected result.

 DRY RUN:
 Need A[1][2]
 Move to row 1: [40 50 60]
 Move to column 2: value 60
 Answer = 60

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Direct access A[i][j] converts to an address using a formula.
 - Fixed arithmetic and one memory read.
 -> Time Complexity = O(1).

 SPACE COMPLEXITY CALCULATION:
 - No extra array is required for access.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int A[2][3] = {{10, 20, 30}, {40, 50, 60}};
    int i = 1, j = 2;

    cout << "Matrix:\n";
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) cout << setw(4) << A[r][c];
        cout << "\n";
    }

    cout << "A[" << i << "][" << j << "] = row " << i
         << ", column " << j << " = " << A[i][j] << "\n";
    return 0;
}

/*
OUTPUT:
Matrix:
  10  20  30
  40  50  60
A[1][2] = row 1, column 2 = 60
*/

