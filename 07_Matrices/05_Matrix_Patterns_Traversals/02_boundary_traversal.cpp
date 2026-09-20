/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_boundary_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ School ground ke sirf boundary fence par walk karna hai, andar ke students ko skip karna hai. Boundary traversal matrix ke sirf border elements print karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Top row left to right.
│ 2. Right column top+1 to bottom.
│ 3. Bottom row right-1 to left if multiple rows.
│ 4. Left column bottom-1 to top+1 if multiple cols.
│ 5. Corners duplicate na ho isliye ranges carefully choose karo.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix 3x4:
│ 1 →  2 →  3 →  4
│ ↑             ↓
│ 5    6    7   8
│ ↑             ↓
│ 9 ← 10 ← 11 ←12
│
│ Boundary order: 1 2 3 4 8 12 11 10 9 5
│
│ DRY RUN:
│ top row: 1,2,3,4
│ right side excluding top: 8,12
│ bottom row reversed excluding right corner: 11,10,9
│ left side upward excluding corners: 5
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Boundary elements count at most 2R + 2C - 4.
│ - This is linear in matrix perimeter.
│ -> Time Complexity = O(R+C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Output vector stores boundary elements.
│ -> Extra Space Complexity = O(R+C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> boundaryTraversal(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<int> ans;
    for (int c = 0; c < cols; c++) ans.push_back(A[0][c]);
    for (int r = 1; r < rows; r++) ans.push_back(A[r][cols - 1]);
    if (rows > 1) {
        for (int c = cols - 2; c >= 0; c--) ans.push_back(A[rows - 1][c]);
    }
    if (cols > 1) {
        for (int r = rows - 2; r >= 1; r--) ans.push_back(A[r][0]);
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = boundaryTraversal(A);
    cout << "Boundary traversal: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Boundary traversal: 1 2 3 4 8 12 11 10 9 5
*/

