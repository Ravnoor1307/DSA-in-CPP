/*
═══════════════════════════════════════════════
 ZIGZAG DIAGONAL TRAVERSAL
 ⏱️ TIME COMPLEXITY: O(R*C) — every cell visited exactly once
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An elevator visits floors diagonal by diagonal, alternating the
 travel direction: one diagonal up-right, the next down-left. This
 is the LeetCode-style zigzag diagonal traversal of a matrix.

 📖 THEORY:
 - Every cell belongs to exactly one diagonal identified by
   s = row + col.
 - There are R + C - 1 diagonals in an R×C matrix.
 - Even diagonals (s) are traversed upward (up-right), odd ones
   downward (down-left).
 - Each diagonal is visited once, so every cell is output exactly
   once.

 ASCII DIAGRAM:
 Matrix:
 1 2 3
 4 5 6
 7 8 9

 Diagonals by row+col:
 s0: 1           -> up order: 1
 s1: 2, 4        -> down order: 2, 4
 s2: 3, 5, 7     -> up order from bottom: 7, 5, 3
 s3: 6, 8        -> down order: 6, 8
 s4: 9           -> up order: 9

 Output: 1 2 4 7 5 3 6 8 9

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop s from 0 to R+C-2 (all diagonals).
    WHY: s ranges over every parallel diagonal of the matrix.
 Step 2: For even s, start at the bottom edge
    (r = min(s, R-1)) and walk up-right (r--, c++).
    WHY: Up-right movement preserves r+c = s, keeping us on the
    same diagonal.
 Step 3: For odd s, start at the right edge
    (c = min(s, C-1)) and walk down-left (r++, c--).
    WHY: Down-left movement also preserves r+c = s.
 Step 4: Only push cells whose r and c stay inside the matrix.
    WHY: Near the corners the diagonal is clipped by the boundary.

 DRY RUN:
 s=0 even: start (0,0) -> 1
 s=1 odd:  start (0,1) -> 2, 4
 s=2 even: start (2,0) -> 7, 5, 3
 s=3 odd:  start (1,2) -> 6, 8
 s=4 even: start (2,2) -> 9
 Output: 1 2 4 7 5 3 6 8 9

 FLOW OF EXECUTION:
 matrix -> for each diagonal s -> even: up-right / odd: down-left -> output

 TIME COMPLEXITY CALCULATION:
 - Every cell belongs to exactly one diagonal.
 - Total visited cells = R*C.
 - Direction checks happen once per diagonal = R+C-1.
 -> Time Complexity = O(R*C)

 SPACE COMPLEXITY CALCULATION:
 - Output vector stores R*C elements.
 -> Extra Space Complexity = O(R*C)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> findDiagonalOrder(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<int> ans;
    for (int s = 0; s <= rows + cols - 2; s++) {
        if (s % 2 == 0) {
            int r = min(s, rows - 1);
            int c = s - r;
            while (r >= 0 && c < cols) {
                ans.push_back(A[r][c]); // up-right
                r--;
                c++;
            }
        } else {
            int c = min(s, cols - 1);
            int r = s - c;
            while (c >= 0 && r < rows) {
                ans.push_back(A[r][c]); // down-left
                r++;
                c--;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = findDiagonalOrder(A);
    cout << "Zigzag diagonal traversal: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Zigzag diagonal traversal: 1 2 4 7 5 3 6 8 9
*/

