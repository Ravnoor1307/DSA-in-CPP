/*
═══════════════════════════════════════════════
 SUM OF DIAGONALS
 ⏱️ TIME COMPLEXITY: O(n) — one loop, at most 2 additions per row
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 At a cross-road intersection two diagonal roads cross each other.
 In a matrix, the primary and secondary diagonals must both be
 totalled, and the centre cell (where they meet) must not be
 counted twice.

 📖 THEORY:
 - Primary diagonal: A[i][i].
 - Secondary diagonal: A[i][n-1-i].
 - For odd n the centre cell satisfies i == n-1-i and belongs to
   both diagonals, so it is counted once.
 - A single loop over rows covers both diagonals in O(n) — no full
   matrix scan.

 ASCII DIAGRAM:
 Matrix:
 1 2 3
 4 5 6
 7 8 9

 Primary:   1 + 5 + 9
 Secondary: 3 + 5 + 7
 Centre 5 is common, count it once.
 Total = 1 + 5 + 9 + 3 + 7 = 25

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i from 0 to n-1.
    WHY: Each row contributes one primary and one secondary diagonal
    cell.
 Step 2: Add A[i][i] (primary).
 Step 3: If i != n-1-i, also add A[i][n-1-i] (secondary).
    WHY: When i equals n-1-i the two diagonals share the same
    centre cell; adding twice would double-count it.
 Step 4: Return the total.

 DRY RUN:
 i=0: add A[0][0]=1 and A[0][2]=3 -> sum = 4
 i=1: add A[1][1]=5 only           -> sum = 9
 i=2: add A[2][2]=9 and A[2][0]=7  -> sum = 25

 FLOW OF EXECUTION:
 matrix + n -> single loop -> add primary + secondary (skip if same cell) -> total

 TIME COMPLEXITY CALCULATION:
 - Loop runs n times.
 - Each iteration performs at most 2 additions.
 - Total additions <= 2n.
 -> Time Complexity = O(n)

 SPACE COMPLEXITY CALCULATION:
 - Only sum and index variables are used.
 -> Extra Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int diagonalSum(const vector<vector<int>>& A) {
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
        if (i != n - 1 - i) sum += A[i][n - 1 - i]; // center double count avoid
    }
    return sum;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Diagonal sum = " << diagonalSum(A) << "\n";
    return 0;
}

/*
OUTPUT:
Diagonal sum = 25
*/

