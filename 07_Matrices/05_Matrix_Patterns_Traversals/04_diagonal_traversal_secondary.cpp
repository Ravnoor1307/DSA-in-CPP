/*
═══════════════════════════════════════════════
 SECONDARY DIAGONAL TRAVERSAL
 ⏱️ TIME COMPLEXITY: O(n) — single loop, one access per row
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Draw a diagonal line from the top-right to the bottom-left of a
 chess board. The secondary diagonal of a matrix is exactly those
 cells where i + j == n - 1.

 📖 THEORY:
 - Secondary diagonal condition: i + j == n - 1.
 - For each row i, the diagonal column is j = n - 1 - i.
 - Traverse i from 0 to n-1 and print/read A[i][n-1-i]; a full
   matrix scan is not needed.
 - The diagonal sum is computed the same way: add A[i][n-1-i].

 ASCII DIAGRAM:
 Matrix:
  1   2  [3]
  4  [5]  6
 [7]  8   9

 Secondary diagonal: 3, 5, 7
 Conditions: (0+2=2), (1+1=2), (2+0=2) for n=3

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i from 0 to n-1.
    WHY: The diagonal has exactly one cell per row — n cells total.
 Step 2: Compute j = n - 1 - i.
    WHY: This value satisfies i + j == n - 1 by construction.
 Step 3: Access and print A[i][j].
    WHY: Directly visits only the diagonal cells, avoiding a full
    matrix scan.

 DRY RUN:
 n=3
 i=0 -> j=2 -> A[0][2] = 3
 i=1 -> j=1 -> A[1][1] = 5
 i=2 -> j=0 -> A[2][0] = 7
 sum = 3 + 5 + 7 = 15

 FLOW OF EXECUTION:
 matrix -> single loop i=0..n-1 -> j=n-1-i -> print/sum A[i][j] -> output

 TIME COMPLEXITY CALCULATION:
 - Loop runs n times.
 - Each iteration computes one column and does one access.
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
    cout << "Secondary diagonal: ";
    for (int i = 0; i < n; i++) {
        int j = n - 1 - i; // i+j=n-1
        cout << A[i][j] << " ";
        sum += A[i][j];
    }
    cout << "\nSum = " << sum << "\n";
    return 0;
}

/*
OUTPUT:
Secondary diagonal: 3 5 7
Sum = 15
*/

