/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_set_matrix_zeros_approach2_inplace.cpp
│
│ REAL-WORLD SCENARIO:
│ Spreadsheet huge hai aur extra memory allowed nahi. Isi sheet ki first row and first column ko sticky-note markers ki tarah use karenge.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. First row and first column marker arrays ki tarah use karo.
│ 2. Pehle check karo first row/first col me original zero hai ya nahi.
│ 3. Inner cells me zero mile to A[i][0]=0 and A[0][j]=0 mark karo.
│ 4. Marker ke basis par inner cells zero set karo.
│ 5. End me first row/first column ko stored flags ke according zero karo.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Input:
│ 1 1 1
│ 1 0 1
│ 1 1 1
│
│ zero at (1,1) marks:
│ A[1][0]=0, A[0][1]=0
│
│ Marker state:
│ 1 0 1
│ 0 0 1
│ 1 1 1
│
│ Final:
│ 1 0 1
│ 0 0 0
│ 1 0 1
│
│ DRY RUN:
│ firstRowZero=false, firstColZero=false
│ scan inner: A[1][1]=0 -> mark row1 and col1
│ inner update:
│ if A[i][0]==0 or A[0][j]==0 then A[i][j]=0
│ final row/col flags false, so keep first row/col except markers impact.
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - First row scan C cells.
│ - First col scan R cells.
│ - Marker scan inner (R-1)*(C-1).
│ - Update scan inner (R-1)*(C-1).
│ - Total = C + R + 2(R-1)(C-1), dominated by R*C.
│ -> Time Complexity = O(R*C). For n*n, O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only two boolean flags used.
│ -> Extra Space Complexity = O(1).
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

void setZeroesInPlace(vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    bool firstRowZero = false, firstColZero = false;

    for (int c = 0; c < cols; c++) if (A[0][c] == 0) firstRowZero = true;
    for (int r = 0; r < rows; r++) if (A[r][0] == 0) firstColZero = true;

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (A[r][c] == 0) {
                A[r][0] = 0; // row marker
                A[0][c] = 0; // column marker
            }
        }
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (A[r][0] == 0 || A[0][c] == 0) A[r][c] = 0;
        }
    }

    if (firstRowZero) for (int c = 0; c < cols; c++) A[0][c] = 0;
    if (firstColZero) for (int r = 0; r < rows; r++) A[r][0] = 0;
}

int main() {
    vector<vector<int>> A = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroesInPlace(A);
    cout << "After set zeroes in-place:\n";
    printMatrix(A);
    return 0;
}

/*
OUTPUT:
After set zeroes in-place:
1 0 1
0 0 0
1 0 1
*/

