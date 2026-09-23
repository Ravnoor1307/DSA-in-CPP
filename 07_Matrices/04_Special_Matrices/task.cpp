/*
═══════════════════════════════════════════════
 TASK SET — SPECIAL MATRICES
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: In a pattern-recognition lab you must
    detect which of the classic matrices an input is: identity,
    diagonal, symmetric, upper/lower triangular, or scalar. These
    special patterns show up in image processing, graph theory,
    and linear-algebra libraries.

 🧠 HOW TO SOLVE: Apply one index rule per matrix type: i==j for
    the diagonal, A[i][j]==A[j][i] checked over the upper triangle
    only for symmetric, i>j zeros for upper triangular, i<j zeros
    for lower triangular, and constant diagonal + zero off-diagonal
    for scalar. The identity matrix is the diagonal matrix whose
    diagonal entries all equal 1.

 MODES/TOPICS COVERED:
  1. Generate an n=3 identity matrix
  2. Print a diagonal matrix from its compact array
  3. Check a symmetric matrix
  4. Check an upper triangular matrix
  5. Check a lower triangular matrix
  6. Check a scalar matrix
  7. Identify a unit matrix
  8. Write storage optimization formulas in comments
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isSym(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (A[i][j] != A[j][i]) return false;
    return true;
}

int main() {
    vector<vector<int>> I(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) I[i][i] = 1;
    vector<vector<int>> S = {{1,2,3},{2,5,6},{3,6,9}};
    cout << "Identity generated first row: ";
    for (int x : I[0]) cout << x << " ";
    cout << "\nSymmetric? " << (isSym(S) ? "YES" : "NO") << "\n";
    cout << "Diagonal compact space O(n), full matrix O(n^2).\n";
    cout << "Triangular compact cells n(n+1)/2.\n";
    return 0;
}

/*
OUTPUT:
Identity generated first row: 1 0 0
Symmetric? YES
Diagonal compact space O(n), full matrix O(n^2).
Triangular compact cells n(n+1)/2.
*/

