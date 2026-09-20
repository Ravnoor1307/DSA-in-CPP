/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_wave_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ Theme park me visitors column-wise queue lanes me wave pattern follow karte hain: first lane down, second lane up, third lane down. Matrix wave traversal aisa hi hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Columns left to right traverse karo.
│ 2. Even column: top to bottom.
│ 3. Odd column: bottom to top.
│ 4. Ye column-wise up-down wave pattern banata hai.
│ 5. Every element exactly once visit hota hai.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│ 1   2 ↑ 3
│ ↓   5 | ↓
│ 7 → 8   9
│
│ Column 0 down: 1,4,7
│ Column 1 up:   8,5,2
│ Column 2 down: 3,6,9
│ Output: 1 4 7 8 5 2 3 6 9
│
│ DRY RUN:
│ c=0 even -> r0,r1,r2 => 1,4,7
│ c=1 odd -> r2,r1,r0 => 8,5,2
│ c=2 even -> r0,r1,r2 => 3,6,9
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Outer loop runs C columns.
│ - Inner loop visits R rows each column.
│ - Total visits = R*C.
│ -> Time Complexity = O(R*C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Output vector stores R*C elements.
│ -> Extra Space Complexity = O(R*C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> waveTraversal(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<int> ans;
    for (int c = 0; c < cols; c++) {
        if (c % 2 == 0) {
            for (int r = 0; r < rows; r++) ans.push_back(A[r][c]);
        } else {
            for (int r = rows - 1; r >= 0; r--) ans.push_back(A[r][c]);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = waveTraversal(A);
    cout << "Wave traversal: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Wave traversal: 1 4 7 8 5 2 3 6 9
*/

