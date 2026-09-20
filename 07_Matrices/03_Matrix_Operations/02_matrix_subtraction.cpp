/*
═══════════════════════════════════════════════
 MATRIX SUBTRACTION
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a monthly expense table you subtract the previous month from the current
 month to get the change. Matrix subtraction works on same-position cells.

 📖 THEORY:
 - Subtraction requires equal dimensions.
 - C[i][j] = A[i][j] - B[i][j].
 - Every row-column pair is processed exactly once.
 - The result matrix keeps the same dimensions.
 - Negative results are allowed.

 ASCII VISUAL / MEMORY DIAGRAM:
 A =       B =       C=A-B
 10 20     1  2      9 18
 30 50     3  5     27 45

 C[1][1] = 50 - 5 = 45

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i from 0 to rows-1.
    WHY: each iteration fixes one output row.
 Step 2: Loop j from 0 to cols-1.
    WHY: each iteration fixes one output column.
 Step 3: Compute C[i][j] = A[i][j] - B[i][j].
    WHY: the difference at matching positions gives the change table.
 Step 4: Print the result matrix.
    WHY: verifies every cell of C.

 DRY RUN:
 r0 c0: 10-1=9
 r0 c1: 20-2=18
 r1 c0: 30-3=27
 r1 c1: 50-5=45

 FLOW OF EXECUTION:
 setup matrices -> validate condition -> nested loops/formula -> output matrix

 TIME COMPLEXITY CALCULATION:
 - Rows R and columns C.
 - Nested loops visit R*C cells.
 - One subtraction per cell.
 -> Time Complexity = O(R*C).

 SPACE COMPLEXITY CALCULATION:
 - Result matrix stores R*C values.
 -> Space Complexity = O(R*C).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int x : row) cout << setw(4) << x;
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> A = {{10,20},{30,50}};
    vector<vector<int>> B = {{1,2},{3,5}};
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> C(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) C[i][j] = A[i][j] - B[i][j];
    }

    cout << "A-B:\n";
    printMatrix(C);
    return 0;
}

/*
OUTPUT:
A-B:
   9  18
  27  45
*/

