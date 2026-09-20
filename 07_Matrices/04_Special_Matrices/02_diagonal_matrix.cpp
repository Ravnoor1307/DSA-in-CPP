/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_diagonal_matrix.cpp
│
│ REAL-WORLD SCENARIO:
│ Lockers ki ek diagonal line active hai, baaki lockers empty hain. Diagonal matrix me sirf diagonal values meaningful hote hain, baaki zero.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Diagonal matrix square hoti hai.
│ 2. Non-diagonal elements zero hote hain.
│ 3. Sirf A[i][i] values store karne se kaam chal sakta hai.
│ 4. Full matrix storage n² hota hai.
│ 5. Optimized diagonal storage n hota hai.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ Full diagonal matrix:
│ 5 0 0
│ 0 7 0
│ 0 0 9
│
│ Compact storage:
│ diag = [5,7,9]
│
│ Get A[i][j]:
│ if i==j -> diag[i]
│ else -> 0
│
│ DRY RUN:
│ diag[0]=5 -> A[0][0]
│ diag[1]=7 -> A[1][1]
│ diag[2]=9 -> A[2][2]
│ A[0][2] is off-diagonal -> 0
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Printing full view visits n*n cells -> O(n²).
│ - Access using compact diag checks i==j -> O(1).
│ - Building diag array n assignments -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Full matrix would need n² storage.
│ - Compact diagonal stores only n values.
│ -> Optimized Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
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

