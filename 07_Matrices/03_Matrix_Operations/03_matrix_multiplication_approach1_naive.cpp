/*
═══════════════════════════════════════════════
 MATRIX MULTIPLICATION — NAIVE APPROACH
 ⏱️ TIME COMPLEXITY: O(m*n*p); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 On a shopping bill, multiplying the quantity row and the price column gives
 the total cost. Matrix multiplication is exactly that row × column dot
 product.

 📖 THEORY:
 - Condition: for A(m*n) and B(n*p) the inner dimension n must match.
 - The result C has dimensions m*p.
 - C[i][j] = sum over k: A[i][k] * B[k][j].
 - Three loops: i over rows, j over columns, k over the dot-product.
 - The naive multiplication is important for interview fundamentals.

 ASCII VISUAL / MEMORY DIAGRAM:
 A row × B column visual:

 A = [1 2]      B = [5 6]
     [3 4]          [7 8]

 C[0][0] = row0(A) dot col0(B)
         = [1 2] · [5 7]
         = 1*5 + 2*7 = 19

 C[0][1] = [1 2] · [6 8] = 22
 C[1][0] = [3 4] · [5 7] = 43
 C[1][1] = [3 4] · [6 8] = 50

 🧠 LOGIC — STEP BY STEP:
 Step 1: Verify inner dimensions n match.
    WHY: otherwise the dot product is not defined.
 Step 2: Loop i over the rows of A.
    WHY: each output row comes from one row of A.
 Step 3: Loop j over the columns of B.
    WHY: each output column comes from one column of B.
 Step 4: Loop k from 0 to n-1 and add A[i][k] * B[k][j].
    WHY: this accumulates the row × column dot product.
 Step 5: Print C.
    WHY: shows every correctly computed cell.

 DRY RUN:
 2x2 dry run:
 C00: k0 1*5=5, k1 2*7=14, sum=19
 C01: k0 1*6=6, k1 2*8=16, sum=22
 C10: k0 3*5=15, k1 4*7=28, sum=43
 C11: k0 3*6=18, k1 4*8=32, sum=50

 FLOW OF EXECUTION:
 setup matrices -> validate condition -> nested loops/formula -> output matrix

 TIME COMPLEXITY CALCULATION:
 - Outer i loop runs m times.
 - Middle j loop runs p times for every i.
 - Inner k loop runs n times for every (i,j).
 - Multiplications/additions = m*p*n.
 -> Time Complexity = O(m*n*p). For n*n matrices, O(n³).

 SPACE COMPLEXITY CALCULATION:
 - Result matrix C stores m*p values.
 -> Space Complexity = O(m*p).
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
    vector<vector<int>> A = {{1,2},{3,4}};
    vector<vector<int>> B = {{5,6},{7,8}};
    int m = A.size(), n = A[0].size(), p = B[0].size();
    if (n != (int)B.size()) {
        cout << "Multiplication not possible\n";
        return 0;
    }
    vector<vector<int>> C(m, vector<int>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << "C[" << i << "][" << j << "] trace: ";
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j]; // row-column multiply
                cout << A[i][k] << "*" << B[k][j];
                if (k + 1 < n) cout << " + ";
            }
            cout << " = " << C[i][j] << "\n";
        }
    }
    cout << "Result:\n";
    printMatrix(C);
    return 0;
}

/*
OUTPUT:
C[0][0] trace: 1*5 + 2*7 = 19
C[0][1] trace: 1*6 + 2*8 = 22
C[1][0] trace: 3*5 + 4*7 = 43
C[1][1] trace: 3*6 + 4*8 = 50
Result:
  19  22
  43  50
*/

