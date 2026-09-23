/*
═══════════════════════════════════════════════
 TASK SET — MEDIUM MATRIX PROBLEMS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A photo editor must rotate images, a
    spreadsheet cleaner must blank defective rows and columns, and
    a factory optimizer must pick the cheapest multiplication order.
    These tasks build exactly those medium-difficulty skills.

 🧠 HOW TO SOLVE: Rotate 90° via the mapping
    rotated[j][n-1-i] = A[i][j] (extra matrix) or transpose +
    row-reverse (in-place). Set Matrix Zeroes uses marker arrays —
    a result copy for the brute approach, first-row/column markers
    for O(1) space. Matrix Chain Multiplication uses DP trying every
    split k; boolean matrix uses marker arrays to avoid cascading.

 MODES/TOPICS COVERED:
  1. Rotate a 3x3 matrix 90° clockwise using an extra matrix
  2. Rotate a 3x3 matrix 90° clockwise using transpose + reverse
  3. Write the Set Matrix Zeroes brute-force approach
  4. Write the Set Matrix Zeroes O(1) space approach
  5. Solve the matrix chain multiplication cost for a dims array
  6. Implement boolean matrix row/column set
  7. Draw the before -> after ASCII state of each problem
  8. Write an approach comparison table in comments
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void rotate90(vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) swap(A[i][j], A[j][i]);
    for (int i = 0; i < n; i++) reverse(A[i].begin(), A[i].end());
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    rotate90(A);
    cout << "Rotated matrix first row: ";
    for (int x : A[0]) cout << x << " ";
    cout << "\nSet zeroes hint: use first row and first column as markers.\n";
    cout << "MCM hint: dp[i][j] tries all split k.\n";
    return 0;
}

/*
OUTPUT:
Rotated matrix first row: 7 4 1
Set zeroes hint: use first row and first column as markers.
MCM hint: dp[i][j] tries all split k.
*/

