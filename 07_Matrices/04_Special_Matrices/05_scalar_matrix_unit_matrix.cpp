/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_scalar_matrix_unit_matrix.cpp
│
│ REAL-WORLD SCENARIO:
│ Identity card ka same stamp diagonal par repeat ho aur baaki empty ho to scalar matrix banti hai. Agar diagonal values 1 ho, unit/identity matrix banti hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Scalar matrix diagonal matrix ka special case hai.
│ 2. All diagonal values same scalar k hoti hain.
│ 3. Off-diagonal values zero hoti hain.
│ 4. Unit matrix / identity matrix me k = 1.
│ 5. Check: diagonal same and off-diagonal zero.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ Scalar matrix k=5:
│ 5 0 0
│ 0 5 0
│ 0 0 5
│
│ Unit matrix k=1:
│ 1 0 0
│ 0 1 0
│ 0 0 1
│
│ DRY RUN:
│ Check scalar:
│ choose k=A[0][0]
│ if i==j -> A[i][j] must equal k
│ if i!=j -> A[i][j] must equal 0
│ For k=5 matrix all checks pass.
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Two nested loops visit n*n cells.
│ - Each cell one condition check.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only scalar k and loop variables used.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isScalarMatrix(const vector<vector<int>>& A) {
    int n = A.size();
    int k = A[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && A[i][j] != k) return false;
            if (i != j && A[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> scalar = {{5,0,0},{0,5,0},{0,0,5}};
    vector<vector<int>> unit = {{1,0,0},{0,1,0},{0,0,1}};
    cout << "scalar matrix? " << (isScalarMatrix(scalar) ? "YES" : "NO") << "\n";
    cout << "unit matrix is scalar? " << (isScalarMatrix(unit) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
scalar matrix? YES
unit matrix is scalar? YES
*/

