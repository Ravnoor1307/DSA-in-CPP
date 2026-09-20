/*
═══════════════════════════════════════════════
 MATRIX TRANSPOSE
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In an Excel sheet, turning the rows into columns is called transposing.
 Whenever student-wise data must be flipped into a subject-wise view, you
 use the transpose operation.

 📖 THEORY:
 - Transpose means T[j][i] = A[i][j].
 - Rows become columns, columns become rows.
 - For a non-square matrix an extra result matrix is the easy way.
 - For a square matrix use the in-place trick: swap pairs above the diagonal.
 - Remember the visual: mirror across the primary diagonal.

 ASCII VISUAL / MEMORY DIAGRAM:
 A =        Transpose =
 1 2 3      1 4
 4 5 6      2 5
            3 6

 Square in-place swap:
 swap A[0][1] with A[1][0]
 swap A[0][2] with A[2][0]
 swap A[1][2] with A[2][1]

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i over the rows.
    WHY: each row of A produces one column of the result.
 Step 2: Loop j over the columns.
    WHY: each column of A produces one row of the result.
 Step 3: Assign T[j][i] = A[i][j].
    WHY: swapping the indices mirrors the grid across the diagonal.
 Step 4: For the square in-place version, only swap j > i pairs.
    WHY: swapping below the diagonal again would undo the transposition.
 Step 5: Print the result.
    WHY: verifies rows became columns.

 DRY RUN:
 For A 2x3:
 A[0][0]=1 -> T[0][0]=1
 A[0][1]=2 -> T[1][0]=2
 A[0][2]=3 -> T[2][0]=3
 A[1][0]=4 -> T[0][1]=4

 FLOW OF EXECUTION:
 setup matrices -> validate condition -> nested loops/formula -> output matrix

 TIME COMPLEXITY CALCULATION:
 - Extra matrix transpose visits R*C cells.
 -> Time Complexity = O(R*C). For n*n, O(n²).
 - In-place square transpose swaps only the upper triangle.
 - Number of swaps = n*(n-1)/2 -> O(n²).

 SPACE COMPLEXITY CALCULATION:
 - Non-square result stores R*C values.
 -> Space Complexity = O(R*C).
 - Square in-place uses only a temp variable.
 -> Extra Space Complexity = O(1).
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

vector<vector<int>> transpose(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> T(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) T[j][i] = A[i][j];
    }
    return T;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6}};
    vector<vector<int>> T = transpose(A);
    cout << "Transpose of 2x3:\n";
    printMatrix(T);

    vector<vector<int>> S = {{1,2,3},{4,5,6},{7,8,9}};
    int n = S.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) swap(S[i][j], S[j][i]); // diagonal mirror swap
    }
    cout << "In-place square transpose:\n";
    printMatrix(S);
    return 0;
}

/*
OUTPUT:
Transpose of 2x3:
   1   4
   2   5
   3   6
In-place square transpose:
   1   4   7
   2   5   8
   3   6   9
*/

