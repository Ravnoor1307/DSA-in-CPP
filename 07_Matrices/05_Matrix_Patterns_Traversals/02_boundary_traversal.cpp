/*
═══════════════════════════════════════════════
 BOUNDARY TRAVERSAL
 ⏱️ TIME COMPLEXITY: O(R+C) — linear in the perimeter
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You walk only along the boundary fence of a school ground and skip
 all the students standing inside. Boundary traversal prints only
 the border elements of a matrix — never the interior.

 📖 THEORY:
 - Boundary traversal outputs only the border cells, skipping every
   interior cell.
 - Corners belong to both a row edge and a column edge, so the
   ranges must exclude them to avoid duplicates.
 - The boundary holds at most 2R + 2C - 4 elements.

 ASCII DIAGRAM:
 Matrix 3x4:
 1 →  2 →  3 →  4
 ↑             ↓
 5    6    7   8
 ↑             ↓
 9 ← 10 ← 11 ←12

 Boundary order: 1 2 3 4 8 12 11 10 9 5

 🧠 LOGIC — STEP BY STEP:
 Step 1: Print the top row left→right (all columns).
    WHY: It is a full border edge and covers the two top corners.
 Step 2: Print the right column from row 1 to the last row.
    WHY: The top-right corner was already printed by the top row.
 Step 3: If rows>1, print the bottom row right→left skipping the
    right corner.
    WHY: The bottom-left must be included while bottom-right was
    already printed.
 Step 4: If cols>1, print the left column bottom→top skipping both
    corners.
    WHY: Only the interior border cells of the left edge are new;
    the corners are already printed.

 DRY RUN:
 top row: 1,2,3,4
 right side excluding top: 8,12
 bottom row reversed excluding right corner: 11,10,9
 left side upward excluding corners: 5
 -> Boundary order: 1 2 3 4 8 12 11 10 9 5

 FLOW OF EXECUTION:
 matrix -> print top row -> print right column -> print bottom row -> print left column -> output

 TIME COMPLEXITY CALCULATION:
 - Boundary elements count at most 2R + 2C - 4.
 - This is linear in the matrix perimeter.
 -> Time Complexity = O(R+C)

 SPACE COMPLEXITY CALCULATION:
 - Output vector stores boundary elements.
 -> Extra Space Complexity = O(R+C)
═══════════════════════════════════════════════
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

