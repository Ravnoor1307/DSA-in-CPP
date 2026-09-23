/*
═══════════════════════════════════════════════
 TASK SET — MATRIX OPERATIONS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: An Excel/calculator lab needs the same
    tables added, subtracted, multiplied, and flipped about the
    diagonal. These tasks build the exact logic used in
    spreadsheets, image transforms, and linear-algebra libraries.

 🧠 HOW TO SOLVE: Add/subtract require identical sizes; multiply
    only when A's columns equal B's rows, computing
    C[i][j] += A[i][k]*B[k][j]; transpose mirrors cells with
    T[j][i] = A[i][j] (in-place square: swap only when j>i); matrix
    power repeats multiplication k times.

 MODES/TOPICS COVERED:
  1. Add two same-size 2x3 matrices
  2. Subtract two same-size 2x2 matrices
  3. Build a dimension validation function
  4. Implement 2x2 matrix multiplication
  5. Implement transpose for a rectangular matrix
  6. Implement in-place transpose for a square matrix
  7. Implement matrix power via repeated multiplication
  8. Write the complexity calculation of each operation in comments
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> multiply2(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> C(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) C[i][j] += A[i][k] * B[k][j];
    return C;
}

int main() {
    vector<vector<int>> A = {{1,2},{3,4}};
    vector<vector<int>> B = {{5,6},{7,8}};
    vector<vector<int>> C = multiply2(A, B);
    cout << "2x2 multiplication result:\n";
    for (const auto& row : C) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "Condition: A columns must equal B rows.\n";
    cout << "Transpose trick: T[j][i] = A[i][j].\n";
    return 0;
}

/*
OUTPUT:
2x2 multiplication result:
19 22
43 50
Condition: A columns must equal B rows.
Transpose trick: T[j][i] = A[i][j].
*/

