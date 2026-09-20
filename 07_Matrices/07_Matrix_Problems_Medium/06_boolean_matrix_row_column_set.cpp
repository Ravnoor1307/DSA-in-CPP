/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_boolean_matrix_row_column_set.cpp
│
│ REAL-WORLD SCENARIO:
│ Office access sheet me 1 means infected/active permission. Agar kisi cell me 1 hai, to uski full row and column active 1 set karni hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Boolean matrix has 0/1 values.
│ 2. Original 1s ki rows and columns mark karo.
│ 3. Directly mutate karne se new 1s cascade kar sakte hain, isliye marker arrays use karo.
│ 4. rowMark[i]=true if row i should become 1.
│ 5. colMark[j]=true if column j should become 1.
│ 6. Second pass me marked row/col cells ko 1 set karo.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Input:
│ 1 0 0
│ 0 0 0
│ 0 0 1
│
│ rowMark: row0,row2
│ colMark: col0,col2
│
│ Output:
│ 1 1 1
│ 1 0 1
│ 1 1 1
│
│ DRY RUN:
│ First pass:
│ (0,0)=1 -> row0=true, col0=true
│ (2,2)=1 -> row2=true, col2=true
│ Second pass:
│ any cell with rowMark or colMark true becomes 1.
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - First pass visits R*C cells.
│ - Second pass visits R*C cells.
│ - Total visits = 2*R*C.
│ -> Time Complexity = O(R*C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - rowMark stores R booleans.
│ - colMark stores C booleans.
│ -> Space Complexity = O(R+C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void booleanMatrix(vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<bool> rowMark(rows, false), colMark(cols, false);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 1) {
                rowMark[i] = true;
                colMark[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowMark[i] || colMark[j]) A[i][j] = 1;
        }
    }
}

int main() {
    vector<vector<int>> A = {{1,0,0},{0,0,0},{0,0,1}};
    booleanMatrix(A);
    cout << "Boolean matrix after row/column set:\n";
    for (auto& row : A) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
Boolean matrix after row/column set:
1 1 1
1 0 1
1 1 1
*/

