/*
═══════════════════════════════════════════════
 MATRIX ADDITION
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Two shops keep their daily sales tables in the same format. To get the
 total sales you add the cells that sit at the same row and column. Matrix
 addition is also element-wise.

 📖 THEORY:
 - Addition is possible only when A and B have the same dimensions.
 - For every cell C[i][j] = A[i][j] + B[i][j].
 - Nested loops traverse the rows and columns.
 - Every element is processed exactly once.
 - The result matrix keeps the same dimensions.

 ASCII VISUAL / MEMORY DIAGRAM:
 A =        B =        C = A+B
 1 2 3      10 20 30   11 22 33
 4 5 6      40 50 60   44 55 66

 Cell visual:
 C[1][2] = A[1][2] + B[1][2] = 6 + 60 = 66

 🧠 LOGIC — STEP BY STEP:
 Step 1: Check that A and B have equal dimensions.
    WHY: element-wise addition needs a matching cell for every position.
 Step 2: Loop i from 0 to rows-1.
    WHY: each iteration fixes one output row.
 Step 3: Loop j from 0 to cols-1.
    WHY: each iteration fixes one output column.
 Step 4: Compute C[i][j] = A[i][j] + B[i][j].
    WHY: the sum at matching positions gives the combined table.
 Step 5: Print the result matrix.
    WHY: verifies every cell of C.

 DRY RUN:
 r0 c0: 1+10=11
 r0 c1: 2+20=22
 r0 c2: 3+30=33
 r1 c0: 4+40=44
 r1 c1: 5+50=55
 r1 c2: 6+60=66

 FLOW OF EXECUTION:
 setup matrices -> validate condition -> nested loops/formula -> output matrix

 TIME COMPLEXITY CALCULATION:
 - Outer loop runs R times.
 - Inner loop runs C times per row.
 - Total additions = R*C.
 -> Time Complexity = O(R*C). For n*n, O(n²).

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
    vector<vector<int>> A = {{1,2,3},{4,5,6}};
    vector<vector<int>> B = {{10,20,30},{40,50,60}};
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> C(rows, vector<int>(cols));

    if (A.size() != B.size() || A[0].size() != B[0].size()) {
        cout << "Addition not possible: dimensions mismatch\n";
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j]; // same cell add karo
        }
    }

    cout << "A+B:\n";
    printMatrix(C);
    return 0;
}

/*
OUTPUT:
A+B:
  11  22  33
  44  55  66
*/

