/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_identity_matrix.cpp
│
│ REAL-WORLD SCENARIO:
│ Multiplication identity 1 number ko change nahi karta. Matrix world me identity matrix I bhi A ko change nahi karta: I×A = A.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Identity matrix square hoti hai.
│ 2. Primary diagonal elements 1 hote hain.
│ 3. Baaki all elements 0 hote hain.
│ 4. Condition: if i==j then 1 else 0.
│ 5. Property: I × A = A and A × I = A.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ I3:
│ 1 0 0
│ 0 1 0
│ 0 0 1
│
│ Diagonal: i==j positions are 1.
│ Off-diagonal: i!=j positions are 0.
│
│ DRY RUN:
│ n=3
│ i0 j0 -> 1, j1/j2 -> 0
│ i1 j1 -> 1
│ i2 j2 -> 1
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Two nested loops n*n cells fill karte hain.
│ - Each cell one if check.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Matrix stores n*n elements.
│ -> Space Complexity = O(n²).
└────────────────────────────────────────────────────────────┘
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

