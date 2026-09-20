/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_rotate_matrix_90_approach2_transpose_reverse.cpp
│
│ REAL-WORLD SCENARIO:
│ Phone gallery me image rotate karna hai, but memory limited hai. Trick: pehle matrix transpose karo, phir har row reverse karo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Step 1: Transpose matrix across primary diagonal.
│ 2. Step 2: Har row reverse karo.
│ 3. Transpose converts rows to columns.
│ 4. Row reverse columns ko clockwise final position me le aata hai.
│ 5. Extra matrix nahi chahiye, sirf swaps.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Original:
│ 1 2 3
│ 4 5 6
│ 7 8 9
│
│ Step 1 transpose:
│ 1 4 7
│ 2 5 8
│ 3 6 9
│
│ Step 2 reverse each row:
│ 7 4 1
│ 8 5 2
│ 9 6 3
│
│ DRY RUN:
│ Transpose swaps:
│ swap(0,1) with (1,0): 2 ↔ 4
│ swap(0,2) with (2,0): 3 ↔ 7
│ swap(1,2) with (2,1): 6 ↔ 8
│ Reverse rows gives final rotation.
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - Transpose swaps upper triangle: n*(n-1)/2 swaps.
│ - Row reverse across all rows: each row n/2 swaps, total n*n/2 swaps.
│ - Total ≈ n² swaps.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only temp swap variables used.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
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

