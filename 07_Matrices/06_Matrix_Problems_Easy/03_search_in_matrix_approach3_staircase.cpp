/*
═══════════════════════════════════════════════
 SEARCH IN MATRIX — APPROACH 3 (STAIRCASE SEARCH)
 ⏱️ TIME COMPLEXITY: O(R+C) — one row or column dropped per move
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A guard searches a sorted office building starting from the
 top-right corner. If the target is smaller than the current value
 he moves left; if it is bigger he moves down. This is the
 staircase search.

 📖 THEORY:
 - Requirement: rows sorted left→right AND columns sorted
   top→bottom.
 - Start at the top-right corner: row=0, col=C-1.
 - Moving left gives smaller values; moving down gives larger ones.
 - Each move eliminates an entire column (going left) or an entire
   row (going down).
 - At most R+C moves happen before the target is found or ruled out.

 ASCII DIAGRAM:
 Matrix:
  1   4   7  11
  2   5   8  12
  3   6   9  16
 10  13  14  17
 target = 9

 Start top-right 11
 9 < 11 -> left to 7
 9 > 7  -> down to 8
 9 > 8  -> down to 9 FOUND

 Path: (0,3) -> (0,2) -> (1,2) -> (2,2)

 🧠 LOGIC — STEP BY STEP:
 Step 1: Start at r=0, c=C-1 (top-right).
    WHY: From this corner one direction is guaranteed smaller and
    the other larger.
 Step 2: If A[r][c]==target, return (r,c).
 Step 3: If target < A[r][c], move left (c--).
    WHY: The same column below only gets bigger, so everything
    smaller is to the left.
 Step 4: If target > A[r][c], move down (r++).
    WHY: The same row to the left only gets smaller, so everything
    larger is below.
 Step 5: If r or c exits the matrix, the target is absent.
    WHY: Every miss has eliminated one full row or column.

 DRY RUN:
 r=0, c=3 value 11; target 9 is smaller -> c--
 r=0, c=2 value 7;  target 9 is larger  -> r++
 r=1, c=2 value 8;  target 9 is larger  -> r++
 r=2, c=2 value 9;  found at (2,2)

 FLOW OF EXECUTION:
 matrix + target -> start top-right -> compare -> left or down move -> found or out of bounds

 TIME COMPLEXITY CALCULATION:
 - Start at top-right.
 - Each move either increases the row or decreases the column.
 - Row can increase at most R times.
 - Column can decrease at most C times.
 - Total moves <= R + C.
 -> Time Complexity = O(R+C)

 SPACE COMPLEXITY CALCULATION:
 - Only row and col pointers are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

pair<int,int> staircaseSearch(const vector<vector<int>>& A, int target) {
    int rows = A.size(), cols = A[0].size();
    int r = 0, c = cols - 1;
    while (r < rows && c >= 0) {
        cout << "visit (" << r << "," << c << ") value=" << A[r][c] << "\n";
        if (A[r][c] == target) return {r, c};
        if (target < A[r][c]) c--; // target chhota -> left
        else r++;                  // target bada -> down
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> A = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    pair<int,int> pos = staircaseSearch(A, 9);
    cout << "Found at: (" << pos.first << "," << pos.second << ")\n";
    return 0;
}

/*
OUTPUT:
visit (0,3) value=11
visit (0,2) value=7
visit (1,2) value=8
visit (2,2) value=9
Found at: (2,2)
*/

