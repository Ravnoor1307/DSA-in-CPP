/*
═══════════════════════════════════════════════
 MATRIX POWER — REPEATED MULTIPLICATION
 ⏱️ TIME COMPLEXITY: O(k*n³); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Counting paths in a graph is done by raising the adjacency matrix to a
 power. Matrix power builds A², A³, ... by repeated multiplication.

 📖 THEORY:
 - Matrix power A^k is defined only when A is a square matrix.
 - A^1 = A.
 - A^k = A multiplied by itself k times.
 - Basic approach: start the result from the identity matrix.
 - Do result = result * A, k times.
 - Fast exponentiation is optimized in later DP/Math modules.

 ASCII VISUAL / MEMORY DIAGRAM:
 A = [1 1]
     [1 0]

 A² = A×A
 A³ = A²×A

 Repeated multiplication chain:
 I -> I*A = A -> A*A = A² -> A²*A = A³

 🧠 LOGIC — STEP BY STEP:
 Step 1: Initialize result to the identity matrix.
    WHY: identity is the multiplicative neutral element.
 Step 2: Repeat k times.
    WHY: each round multiplies by one more factor of A.
 Step 3: Multiply result by A using the O(n³) naive loop.
    WHY: each multiplication updates the accumulated power.
 Step 4: Print the matrix after every step.
    WHY: shows the progression A, A², A³, ...

 DRY RUN:
 A = [[1,1],[1,0]], power=3
 result starts identity [[1,0],[0,1]]
 step1 result=A
 step2 result=A²=[[2,1],[1,1]]
 step3 result=A³=[[3,2],[2,1]]

 FLOW OF EXECUTION:
 setup matrices -> validate condition -> nested loops/formula -> output matrix

 TIME COMPLEXITY CALCULATION:
 - One n*n matrix multiplication uses 3 loops: n*n*n = n³ scalar operations.
 - Repeated power runs the exponent k multiplications.
 - Total scalar operation groups = k*n³.
 -> Time Complexity = O(k*n³).

 SPACE COMPLEXITY CALCULATION:
 - Result and temporary matrices each store n*n values.
 -> Space Complexity = O(n²).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int x : row) cout << setw(4) << x;
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> A = {{1,1},{1,0}};
    int n = A.size();
    int power = 3;
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1; // identity start

    for (int step = 1; step <= power; step++) {
        result = multiply(result, A);
        cout << "After multiplying step " << step << ":\n";
        printMatrix(result);
    }
    return 0;
}

/*
OUTPUT:
After multiplying step 1:
   1   1
   1   0
After multiplying step 2:
   2   1
   1   1
After multiplying step 3:
   3   2
   2   1
*/

