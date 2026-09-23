/*
═══════════════════════════════════════════════
 WAVE TRAVERSAL
 ⏱️ TIME COMPLEXITY: O(R*C) — every cell visited exactly once
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a theme park, queuing lanes are taken column by column in a
 wave pattern: the first lane goes down, the second lane goes up,
 the third lane goes down again. Matrix wave traversal works the
 same way.

 📖 THEORY:
 - Wave traversal scans columns left → right, alternating direction
   per column.
 - Even columns (0-indexed) go top → bottom; odd columns go
   bottom → top.
 - This builds a column-wise up-down wave that visits every element
   exactly once.

 ASCII DIAGRAM:
 Matrix:
 1   2 ↑ 3
 ↓   5 | ↓
 7 → 8   9

 Column 0 down: 1, 4, 7
 Column 1 up:   8, 5, 2
 Column 2 down: 3, 6, 9
 Output: 1 4 7 8 5 2 3 6 9

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop c from 0 to C-1.
    WHY: Columns are consumed from left to right.
 Step 2: If c is even, loop r from 0 to R-1.
    WHY: Even columns are read downward.
 Step 3: If c is odd, loop r from R-1 down to 0.
    WHY: Odd columns are read upward.
 Step 4: Push A[r][c] on every visit.
    WHY: The alternating direction merges into one continuous wave.

 DRY RUN:
 c=0 even -> r0, r1, r2  => 1, 4, 7
 c=1 odd  -> r2, r1, r0  => 8, 5, 2
 c=2 even -> r0, r1, r2  => 3, 6, 9
 Output: 1 4 7 8 5 2 3 6 9

 FLOW OF EXECUTION:
 matrix -> loop columns left→right -> even column down, odd column up -> output

 TIME COMPLEXITY CALCULATION:
 - Outer loop runs C columns.
 - Inner loop visits R rows per column.
 - Total visits = R*C.
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

