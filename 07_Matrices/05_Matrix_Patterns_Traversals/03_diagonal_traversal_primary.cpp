/*
═══════════════════════════════════════════════
 PRIMARY DIAGONAL TRAVERSAL
 ⏱️ TIME COMPLEXITY: O(n) — single loop, one access per row
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Draw a straight diagonal line from the top-left to the bottom-right
 of a chess board. The primary diagonal of a matrix is exactly
 those cells where the row index and the column index are equal.

 📖 THEORY:
 - Primary diagonal condition: i == j.
 - In a square matrix there are exactly n primary-diagonal cells.
 - Traverse i from 0 to n-1 and print/read A[i][i]; a full matrix
   scan is not needed.
 - The diagonal sum is computed the same way: add A[i][i].

 ASCII DIAGRAM:
 Matrix:
 [1]  2   3
  4  [5]  6
  7   8  [9]

 Primary diagonal: 1, 5, 9

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i from 0 to n-1.
    WHY: The diagonal has exactly one cell per row — n cells total.
 Step 2: Access and print A[i][i].
    WHY: The single-index rule i==j selects the diagonal cell of
    each row.
 Step 3: Optionally add A[i][i] to a sum.
    WHY: Summing inside the same loop costs O(n) with no extra pass.

 DRY RUN:
 n=3
 i=0 -> A[0][0] = 1
 i=1 -> A[1][1] = 5
 i=2 -> A[2][2] = 9
 sum = 1 + 5 + 9 = 15

 FLOW OF EXECUTION:
 matrix -> single loop i=0..n-1 -> print/sum A[i][i] -> output

 TIME COMPLEXITY CALCULATION:
 - Loop runs n times.
 - Each iteration does one access and an optional addition.
 -> Time Complexity = O(n)

 SPACE COMPLEXITY CALCULATION:
 - Output vector stores n elements.
 -> Extra Space Complexity = O(n), O(1) if direct print/sum
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    int n = A.size();
    int sum = 0;
    cout << "Primary diagonal: ";
    for (int i = 0; i < n; i++) {
        cout << A[i][i] << " "; // i==j
        sum += A[i][i];
    }
    cout << "\nSum = " << sum << "\n";
    return 0;
}

/*
OUTPUT:
Primary diagonal: 1 5 9
Sum = 15
*/

