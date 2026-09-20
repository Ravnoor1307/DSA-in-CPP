/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_set_matrix_zeros_approach1_bruteforce.cpp
│
│ REAL-WORLD SCENARIO:
│ Spreadsheet me agar koi cell defective zero ho, to uski full row and full column clear karni hai. Brute force har original zero ke liye row/column mark karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Original zeros ko identify karo.
│ 2. Har zero A[i][j] ke liye uski row and column result copy me zero karo.
│ 3. Copy use karne se naye zeros cascading effect create nahi karte.
│ 4. Ye simple hai but repeated row/column clearing costly hai.
│ 5. Better approaches marker arrays or first-row/first-column use karte hain.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Input:
│ 1 1 1
│ 1 0 1
│ 1 1 1
│
│ Zero at (1,1):
│ row1 -> all zero
│ col1 -> all zero
│
│ Output:
│ 1 0 1
│ 0 0 0
│ 1 0 1
│
│ DRY RUN:
│ Scan cells:
│ (0,0)=1 no action
│ (1,1)=0 found
│ clear row 1: 3 assignments
│ clear col 1: 3 assignments
│ continue scan original matrix only.
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - Scan all cells: R*C.
│ - For each zero, clearing row costs C and clearing column costs R.
│ - Worst case every cell zero: R*C*(R+C) operations.
│ - For n*n matrix: n²*(2n)=2n³.
│ -> Time Complexity = O(n³) for square matrices.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Copy/result matrix stores R*C cells.
│ -> Space Complexity = O(R*C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void printMatrix(const vector<vector<int>>& A) {
    for (const auto& row : A) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

vector<vector<int>> setZeroesBrute(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> result = A;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 0) {
                cout << "Original zero at (" << i << "," << j << ") -> clear row and column\n";
                for (int c = 0; c < cols; c++) result[i][c] = 0;
                for (int r = 0; r < rows; r++) result[r][j] = 0;
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> A = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> ans = setZeroesBrute(A);
    cout << "After set zeroes brute:\n";
    printMatrix(ans);
    return 0;
}

/*
OUTPUT:
Original zero at (1,1) -> clear row and column
After set zeroes brute:
1 0 1
0 0 0
1 0 1
*/

