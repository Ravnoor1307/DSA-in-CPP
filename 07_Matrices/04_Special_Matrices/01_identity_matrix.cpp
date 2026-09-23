/*
═══════════════════════════════════════════════
 IDENTITY MATRIX
 ⏱️ TIME COMPLEXITY: O(n²) to build all n² cells
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The multiplicative identity 1 does not change a number. In the
 matrix world the identity matrix I also does not change a matrix:
 I × A = A. It plays the role of the number 1 for matrices — used
 in solving systems, inverses, and computer graphics.

 📖 THEORY:
 - An identity matrix I is square: every primary diagonal element
   (i == j) is 1 and every off-diagonal element (i != j) is 0.
 - It is the multiplicative identity of matrices: I × A = A and
   A × I = A for any compatible matrix A.
 - Building it is a pure fill task: nested loops write 1 on the
   diagonal and leave 0 everywhere else.

 ASCII DIAGRAM:
 I3:
 1 0 0
 0 1 0
 0 0 1

 Diagonal: i==j positions are 1.
 Off-diagonal: i!=j positions are 0.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create an n×n matrix initialized to 0.
    WHY: We need storage for all n² cells; starting from 0 means
    every off-diagonal cell is already correct.
 Step 2: Set I[i][i] = 1 for every row i.
    WHY: This writes 1 onto the primary diagonal in a single pass;
    index equality i==j is exactly the diagonal condition.
 Step 3: Print the matrix.
    WHY: Off-diagonal cells still hold their initial 0, matching the
    identity definition.

 DRY RUN:
 n=3
 i=0: I[0][0]=1, columns 1 and 2 stay 0   -> 1 0 0
 i=1: I[1][1]=1                           -> 0 1 0
 i=2: I[2][2]=1                           -> 0 0 1

 FLOW OF EXECUTION:
 create n×n matrix (all 0) -> write I[i][i]=1 on the diagonal -> print matrix -> output

 TIME COMPLEXITY CALCULATION:
 - Two nested loops visit all n*n cells.
 - Each cell is written/checked once.
 -> Time Complexity = O(n²)

 SPACE COMPLEXITY CALCULATION:
 - The matrix stores n*n elements.
 -> Space Complexity = O(n²)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n = 3;
    vector<vector<int>> I(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) I[i][i] = 1; // diagonal 1
    cout << "Identity matrix:\n";
    for (auto& row : I) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "Property: I x A = A\n";
    return 0;
}

/*
OUTPUT:
Identity matrix:
1 0 0
0 1 0
0 0 1
Property: I x A = A
*/

