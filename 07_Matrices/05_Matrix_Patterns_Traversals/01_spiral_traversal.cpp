/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_spiral_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ Mall ke andar cleaner outer boundary se clockwise ghoomte hue andar ki taraf spiral me clean karta hai. Matrix spiral traversal bhi 4 boundaries ko shrink karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. top, bottom, left, right boundaries maintain karo.
│ 2. Top row left to right print karo, top++.
│ 3. Right column top to bottom print karo, right--.
│ 4. Bottom row right to left print karo if top<=bottom, bottom--.
│ 5. Left column bottom to top print karo if left<=right, left++.
│ 6. Repeat until boundaries cross.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ 3x3 matrix:
│ 1 → 2 → 3
│ ↑       ↓
│ 4   5   6
│ ↑       ↓
│ 7 ← 8 ← 9
│
│ Spiral path: 1→2→3→6→9→8→7→4→5
│
│ Boundaries:
│ top=0,bottom=2,left=0,right=2
│ after outer layer: top=1,bottom=1,left=1,right=1
│
│ DRY RUN:
│ Layer 1:
│ top row: 1 2 3
│ right col: 6 9
│ bottom row: 8 7
│ left col: 4
│ Layer 2:
│ center: 5
│ Answer: 1 2 3 6 9 8 7 4 5
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Every matrix cell is printed exactly once.
│ - Total cells = R*C.
│ - Boundary updates are constant per layer.
│ -> Time Complexity = O(R*C). For n*n, O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Output vector stores R*C elements.
│ - Boundary variables constant.
│ -> Extra Space Complexity = O(R*C) if storing output, O(1) if directly printing.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& A) {
    vector<int> ans;
    int top = 0, bottom = (int)A.size() - 1;
    int left = 0, right = (int)A[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; c++) ans.push_back(A[top][c]); // top row
        top++;
        for (int r = top; r <= bottom; r++) ans.push_back(A[r][right]); // right wall
        right--;
        if (top <= bottom) {
            for (int c = right; c >= left; c--) ans.push_back(A[bottom][c]);
            bottom--;
        }
        if (left <= right) {
            for (int r = bottom; r >= top; r--) ans.push_back(A[r][left]);
            left++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(A);
    cout << "Spiral traversal: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Spiral traversal: 1 2 3 6 9 8 7 4 5
*/

