/*
═══════════════════════════════════════════════
 SPIRAL TRAVERSAL
 ⏱️ TIME COMPLEXITY: O(R*C) — every cell printed exactly once
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A mall cleaner goes around the outer boundary clockwise, then
 moves inward in a spiral until the centre is clean. Matrix spiral
 traversal does the same: it shrinks four boundaries to peel the
 matrix ring by ring.

 📖 THEORY:
 - Spiral traversal reads the matrix in concentric rings: top row
   left→right, right column top→bottom, bottom row right→left,
   left column bottom→top, then all four boundaries shrink inward.
 - Four pointers encode the current ring: top, bottom, left, right.
 - Each cell is visited exactly once; the loop ends when the
   boundaries cross (top > bottom or left > right).

 ASCII DIAGRAM:
 3x3 matrix:
 1 → 2 → 3
 ↑       ↓
 4   5   6
 ↑       ↓
 7 ← 8 ← 9

 Spiral path: 1 → 2 → 3 → 6 → 9 → 8 → 7 → 4 → 5

 Boundaries:
 top=0, bottom=2, left=0, right=2
 after outer layer: top=1, bottom=1, left=1, right=1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Initialize top=0, bottom=R-1, left=0, right=C-1.
    WHY: The four pointers delimit the current outer ring.
 Step 2: Print the top row left→right, then top++.
    WHY: The whole top edge belongs to the ring; advancing top
    removes it for the next ring.
 Step 3: Print the right column top→bottom, then right--.
    WHY: The right edge is consumed and the boundary shrinks
    inward.
 Step 4: If top<=bottom, print the bottom row right→left, then
    bottom--.
    WHY: The guard prevents re-printing when only one row remains.
 Step 5: If left<=right, print the left column bottom→top, then
    left++.
    WHY: The guard prevents re-printing when only one column
    remains.
 Step 6: Repeat until the boundaries cross.
    WHY: When top>bottom or left>right, every cell is covered.

 DRY RUN:
 Layer 1 (top=0, bottom=2, left=0, right=2):
 top row:    1 2 3
 right col:  6 9
 bottom row: 8 7
 left col:   4
 Layer 2 (top=1, bottom=1, left=1, right=1):
 center: 5
 Answer: 1 2 3 6 9 8 7 4 5

 FLOW OF EXECUTION:
 matrix setup -> maintain 4 boundaries -> top row -> right col -> bottom row -> left col -> shrink -> output

 TIME COMPLEXITY CALCULATION:
 - Every matrix cell is printed exactly once.
 - Total cells = R*C.
 - Boundary updates are constant per layer.
 -> Time Complexity = O(R*C). For n*n, O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Output vector stores R*C elements.
 - Boundary variables are constant.
 -> Extra Space Complexity = O(R*C) if storing output, O(1) if directly printing
═══════════════════════════════════════════════
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

