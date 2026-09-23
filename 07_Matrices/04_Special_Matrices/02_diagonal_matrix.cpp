/*
═══════════════════════════════════════════════
 DIAGONAL MATRIX
 ⏱️ TIME COMPLEXITY: O(n) to build compact storage, O(1) per
 lookup, O(n²) to print the full view
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a row of lockers only one diagonal line of lockers is active;
 all the other lockers are empty. A diagonal matrix is the same:
 only the diagonal values are meaningful, everything else is zero.

 📖 THEORY:
 - A diagonal matrix is square: all non-diagonal entries are zero,
   so only A[i][i] holds meaningful values.
 - Full matrix storage costs n² cells, but a diagonal matrix has
   only n useful numbers — most of the storage is wasted zeros.
 - Compact optimization: store just the diagonal in a 1D array
   diag of size n; read A[i][j] = diag[i] if i==j, else 0.

 ASCII DIAGRAM:
 Full diagonal matrix:
 5 0 0
 0 7 0
 0 0 9

 Compact storage:
 diag = [5, 7, 9]

 Get A[i][j]:
 if i==j -> diag[i]
 else    -> 0

 🧠 LOGIC — STEP BY STEP:
 Step 1: Store only the diagonal values in a 1D array diag of size n.
    WHY: Every off-diagonal value is guaranteed 0, so storing them
    would waste n²-n cells.
 Step 2: Reconstruct A[i][j] with the rule: if i==j return diag[i],
    else return 0.
    WHY: This rule exactly reproduces the definition of a diagonal
    matrix.
 Step 3: Print the full matrix by calling the rule for every (i,j).
    WHY: This is for visual verification only; real use reads single
    cells in O(1).

 DRY RUN:
 diag = [5, 7, 9], n=3
 diag[0]=5 -> A[0][0]=5
 diag[1]=7 -> A[1][1]=7
 diag[2]=9 -> A[2][2]=9
 A[0][2]: i!=j -> 0
 A[1][0]: i!=j -> 0

 FLOW OF EXECUTION:
 compact diag array -> for each (i,j): i==j ? diag[i] : 0 -> print full matrix

 TIME COMPLEXITY CALCULATION:
 - Building the diag array takes n assignments -> O(n).
 - A single lookup takes one i==j check -> O(1).
 - Printing the full view visits all n*n cells -> O(n²).

 SPACE COMPLEXITY CALCULATION:
 - Full matrix would need n² storage.
 - Compact diagonal stores only n values.
 -> Space Complexity = O(n) (optimized)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int getDiagonalValue(const vector<int>& diag, int i, int j) {
    return (i == j) ? diag[i] : 0;
}

int main() {
    vector<int> diag = {5, 7, 9}; // sirf diagonal store kiya
    int n = diag.size();
    cout << "Diagonal matrix full view from compact storage:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << getDiagonalValue(diag, i, j) << " ";
        cout << "\n";
    }
    cout << "Compact storage size = " << diag.size() << " instead of " << n*n << "\n";
    return 0;
}

/*
OUTPUT:
Diagonal matrix full view from compact storage:
5 0 0
0 7 0
0 0 9
Compact storage size = 3 instead of 9
*/

