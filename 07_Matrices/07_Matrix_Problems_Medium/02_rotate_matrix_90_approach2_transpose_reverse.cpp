/*
═══════════════════════════════════════════════
 ROTATE MATRIX 90° — APPROACH 2 (TRANSPOSE + REVERSE)
 ⏱️ TIME COMPLEXITY: O(n²) — ~n² swaps total
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A phone gallery must rotate the image, but memory is limited. The
 trick: first transpose the matrix, then reverse every row — the
 image rotates 90° clockwise with no extra matrix at all.

 📖 THEORY:
 - A 90° clockwise rotation equals two in-place operations:
   transpose across the primary diagonal, then reverse every row.
 - Transpose swaps A[i][j] with A[j][i] for j > i (upper triangle
   only), turning rows into columns.
 - Reversing each row completes the clockwise turn.
 - Only swaps are used -> O(1) extra space.

 ASCII DIAGRAM:
 Original:
 1 2 3
 4 5 6
 7 8 9

 Step 1 transpose:
 1 4 7
 2 5 8
 3 6 9

 Step 2 reverse each row:
 7 4 1
 8 5 2
 9 6 3

 🧠 LOGIC — STEP BY STEP:
 Step 1: Transpose — for i in 0..n-1, for j in i+1..n-1,
    swap(A[i][j], A[j][i]).
    WHY: Swapping only the upper triangle avoids swapping every pair
    twice and leaves the diagonal untouched.
 Step 2: Reverse every row in place.
    WHY: Reversal re-orders each transposed row into the rotated
    position.
 Step 3: The same matrix now holds the rotated result.
    WHY: No extra storage was needed.

 DRY RUN:
 Transpose swaps:
 swap (0,1) with (1,0): 2 <-> 4
 swap (0,2) with (2,0): 3 <-> 7
 swap (1,2) with (2,1): 6 <-> 8
 Reverse rows -> final rotated matrix

 FLOW OF EXECUTION:
 input matrix -> transpose (upper triangle swaps) -> reverse each row -> output

 TIME COMPLEXITY CALCULATION:
 - Transpose swaps upper triangle: n*(n-1)/2 swaps.
 - Row reverse across all rows: each row n/2 swaps, total n*n/2.
 - Total ≈ n² swaps.
 -> Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - Only temporary swap variables are used.
 -> Extra Space Complexity = O(1)
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

void rotate90InPlace(vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) swap(A[i][j], A[j][i]); // transpose
    }
    for (int i = 0; i < n; i++) reverse(A[i].begin(), A[i].end()); // row reverse
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    rotate90InPlace(A);
    cout << "Rotated in-place by transpose + reverse:\n";
    printMatrix(A);
    return 0;
}

/*
OUTPUT:
Rotated in-place by transpose + reverse:
  7  4  1
  8  5  2
  9  6  3
*/

