/*
═══════════════════════════════════════════════
 SEARCH IN MATRIX — APPROACH 1 (BRUTE FORCE)
 ⏱️ TIME COMPLEXITY: O(R*C) — worst case checks every cell
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The simplest way to find a book in a library is to check every
 shelf and every row, one by one. Brute-force matrix search does
 the same: every cell is scanned until the target is found.

 📖 THEORY:
 - Brute-force search compares every cell against the target until
   a match is found.
 - It needs NO sorted-order property — it works on any matrix.
 - Worst case (target absent or in the last cell) compares all
   R*C cells.

 ASCII DIAGRAM:
 Matrix:
 1  4  7
 2  5  8
 3  6  9
 target = 5
 Scan order row-wise:
 1 -> 4 -> 7 -> 2 -> 5 FOUND

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop through every row i.
    WHY: Rows are the outer dimension of the scan.
 Step 2: Loop through every column j of the current row.
    WHY: Each row has C cells that must be tested.
 Step 3: If A[i][j] == target, return position (i, j).
    WHY: The first match is the answer.
 Step 4: If both loops finish, return (-1, -1).
    WHY: No cell matched the target, so it is absent.

 DRY RUN:
 compare A[0][0]=1 no
 compare A[0][1]=4 no
 compare A[0][2]=7 no
 compare A[1][0]=2 no
 compare A[1][1]=5 yes -> position (1,1)

 FLOW OF EXECUTION:
 matrix + target -> nested row/col scan -> A[i][j]==target? -> (i,j), else not found

 TIME COMPLEXITY CALCULATION:
 - In the worst case, the target is in the last cell or absent.
 - Rows = R, columns = C.
 - Total comparisons = R*C.
 -> Time Complexity = O(R*C)

 SPACE COMPLEXITY CALCULATION:
 - No extra data structure is used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

pair<int,int> bruteSearch(const vector<vector<int>>& A, int target) {
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A[0].size(); j++) {
            cout << "compare " << A[i][j] << "\n";
            if (A[i][j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> A = {{1,4,7},{2,5,8},{3,6,9}};
    pair<int,int> pos = bruteSearch(A, 5);
    cout << "Found at: (" << pos.first << "," << pos.second << ")\n";
    return 0;
}

/*
OUTPUT:
compare 1
compare 4
compare 7
compare 2
compare 5
Found at: (1,1)
*/

