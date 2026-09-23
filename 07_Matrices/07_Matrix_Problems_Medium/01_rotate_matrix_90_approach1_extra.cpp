/*
═══════════════════════════════════════════════
 ROTATE MATRIX 90° — APPROACH 1 (EXTRA MATRIX)
 ⏱️ TIME COMPLEXITY: O(n²) — every cell copied exactly once
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A photo-gallery app must rotate an image 90° clockwise. Image
 pixels form a matrix, and the easiest way to rotate is to build a
 brand-new matrix and copy every pixel into its rotated position.

 📖 THEORY:
 - Clockwise 90° rotation sends each cell A[i][j] to
   rotated[j][n-1-i].
 - An extra matrix makes the mapping trivially safe: the source
   matrix is only read, never overwritten, so there is no error
   from cascading changes.
 - Every cell is copied exactly once.

 ASCII DIAGRAM:
 Original:
 1 2 3
 4 5 6
 7 8 9

 Mapping examples:
 A[0][0]=1 -> R[0][2]
 A[0][1]=2 -> R[1][2]
 A[0][2]=3 -> R[2][2]
 A[1][0]=4 -> R[0][1]

 Rotated clockwise:
 7 4 1
 8 5 2
 9 6 3

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create rotated[n][n].
    WHY: A fresh n×n target grid is needed for the result.
 Step 2: For every (i,j), set rotated[j][n-1-i] = A[i][j].
    WHY: This formula is the geometric mapping of a 90° clockwise
    turn.
 Step 3: Return rotated.
    WHY: The original matrix stays untouched; the new one holds the
    rotated image.

 DRY RUN:
 n=3
 i=0,j=0: R[0][2] = 1
 i=0,j=1: R[1][2] = 2
 i=0,j=2: R[2][2] = 3
 i=1,j=0: R[0][1] = 4
 i=2,j=0: R[0][0] = 7
 Final first row: 7 4 1

 FLOW OF EXECUTION:
 input matrix -> create rotated grid -> rotated[j][n-1-i] = A[i][j] -> print rotated

 TIME COMPLEXITY CALCULATION:
 - Outer loop i runs n times.
 - Inner loop j runs n times for each i.
 - Total assignments = n*n = n².
 -> Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Extra rotated matrix stores n*n cells.
 -> Space Complexity = O(n²)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void printMatrix(const vector<vector<int>>& A) {
    for (const auto& row : A) {
        for (int x : row) cout << setw(3) << x;
        cout << "\n";
    }
}

vector<vector<int>> rotate90Extra(const vector<vector<int>>& A) {
    int n = A.size();
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = A[i][j]; // old row becomes new column
        }
    }
    return rotated;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> R = rotate90Extra(A);
    cout << "Rotated using extra matrix:\n";
    printMatrix(R);
    return 0;
}

/*
OUTPUT:
Rotated using extra matrix:
  7  4  1
  8  5  2
  9  6  3
*/

