/*
═══════════════════════════════════════════════
 SEARCH IN MATRIX — APPROACH 2 (ROW-WISE BINARY SEARCH)
 ⏱️ TIME COMPLEXITY: O(R log C) — binary search per row
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Every shelf in the library is sorted. If you binary search each
 shelf instead of scanning it linearly, finding a book becomes much
 faster.

 📖 THEORY:
 - Requirement: each row must be individually sorted (left→right).
 - Apply standard binary search to every row independently.
 - Binary search halves the search window each step, so one row of
   C elements needs log₂C comparisons.
 - Rows need not be globally sorted — each row is searched alone.

 ASCII DIAGRAM:
 Matrix rows sorted:
 1  3  5  7
 10 11 16 20
 23 30 34 60
 target = 16

 Row 0 BS -> not found
 Row 1 BS -> mid values lead to 16 FOUND

 🧠 LOGIC — STEP BY STEP:
 Step 1: For each row r, run binary search.
    WHY: We do not know which row holds the target, so each must
    be checked.
 Step 2: Set low=0, high=C-1, mid=low+(high-low)/2.
    WHY: Mid splits the sorted row into two halves.
 Step 3: If A[r][mid]==target, found.
 Step 4: If target < A[r][mid], set high=mid-1.
    WHY: All larger elements live to the right of mid.
 Step 5: If target > A[r][mid], set low=mid+1.
    WHY: All smaller elements live to the left of mid.
 Step 6: Repeat until low > high; if no row matches, not found.

 DRY RUN:
 Row1 = [10, 11, 16, 20]
 low=0, high=3, mid=1 -> 11 < 16, so low = 2
 low=2, high=3, mid=2 -> 16 found
 -> Found? YES

 FLOW OF EXECUTION:
 matrix -> for each row -> binary search (low/high/mid) -> target found -> YES, else next row -> NO

 TIME COMPLEXITY CALCULATION:
 - There are R rows.
 - Binary search on one row of C elements halves the search space
   each step.
 - C/2^k = 1 -> C = 2^k -> k = log₂C.
 - Total = R * log₂C.
 -> Time Complexity = O(R log C)

 SPACE COMPLEXITY CALCULATION:
 - Only iterative variables low/high/mid are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool binarySearchRow(const vector<int>& row, int target) {
    int low = 0, high = (int)row.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "mid value " << row[mid] << "\n";
        if (row[mid] == target) return true;
        if (row[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> A = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 16;
    bool found = false;
    for (int r = 0; r < (int)A.size(); r++) {
        cout << "Search row " << r << "\n";
        if (binarySearchRow(A[r], target)) {
            found = true;
            break;
        }
    }
    cout << "Found? " << (found ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Search row 0
mid value 3
mid value 5
mid value 7
Search row 1
mid value 11
mid value 16
Found? YES
*/

