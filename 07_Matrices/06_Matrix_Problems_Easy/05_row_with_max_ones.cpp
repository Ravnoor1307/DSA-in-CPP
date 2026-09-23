/*
═══════════════════════════════════════════════
 ROW WITH MAXIMUM ONES
 ⏱️ TIME COMPLEXITY: O(R+C) — one row or column dropped per move
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a class attendance sheet, 1 means present. We need the row with
 the maximum number of present students. Because every row is
 binary-sorted (0s then 1s), a top-right pointer trick answers it
 optimally.

 📖 THEORY:
 - The matrix is binary (0/1) and each row is sorted: all 0s
   followed by all 1s.
 - Starting at top-right, a 1 means the current row has at least
   this many ones, so it becomes the current best; moving left
   counts how far the ones extend.
 - A 0 means the whole row from here leftwards is 0 — no better
   candidate in this row, so move down.
 - Each step eliminates one column or one row -> at most R+C steps.

 ASCII DIAGRAM:
 Matrix:
 0 0 1 1
 0 1 1 1
 0 0 0 1

 start (0,3)=1 -> candidate row0, go left
 (0,2)=1 -> candidate row0, go left
 (0,1)=0 -> move down
 (1,1)=1 -> candidate row1, go left
 (1,0)=0 -> move down
 (2,0)=0 -> move down, end

 Answer: row1 has 3 ones.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Start at r=0, c=C-1, ans=-1.
    WHY: Top-right sits on the boundary between the 0s and 1s zones.
 Step 2: If A[r][c]==1, set ans=r and move left (c--).
    WHY: A 1 confirms this row has ones; going left counts how many,
    improving the candidate while further 1s exist.
 Step 3: Else (value 0) move down (r++).
    WHY: Since a row is 0s then 1s, everything left of a 0 is also 0
    — no more ones in this row.
 Step 4: When the pointers exit, ans holds the row with the most
    ones.
    WHY: The last row marked as candidate is the one whose ones
    extended furthest left.

 DRY RUN:
 r=0, c=3 value 1: ans=0, c=2
 r=0, c=2 value 1: ans=0, c=1
 r=0, c=1 value 0: r=1
 r=1, c=1 value 1: ans=1, c=0
 r=1, c=0 value 0: r=2
 r=2, c=0 value 0: r=3, stop
 -> Row with max ones = 1

 FLOW OF EXECUTION:
 matrix -> top-right start -> 1: candidate + move left, 0: move down -> answer = last candidate row

 TIME COMPLEXITY CALCULATION:
 - Row pointer can move down at most R times.
 - Column pointer can move left at most C times.
 - Total moves <= R+C.
 -> Time Complexity = O(R+C)

 SPACE COMPLEXITY CALCULATION:
 - Only row, col, and answer variables are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int rowWithMaxOnes(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    int r = 0, c = cols - 1, ans = -1;
    while (r < rows && c >= 0) {
        cout << "visit (" << r << "," << c << ") value=" << A[r][c] << "\n";
        if (A[r][c] == 1) {
            ans = r;
            c--; // aur left me 1 mile to count aur zyada
        } else {
            r++; // row me is column tak 0, next row try karo
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{0,0,1,1},{0,1,1,1},{0,0,0,1}};
    cout << "Row with max ones = " << rowWithMaxOnes(A) << "\n";
    return 0;
}

/*
OUTPUT:
visit (0,3) value=1
visit (0,2) value=1
visit (0,1) value=0
visit (1,1) value=1
visit (1,0) value=0
visit (2,0) value=0
Row with max ones = 1
*/

