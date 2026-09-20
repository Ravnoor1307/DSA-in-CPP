/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_rotate_matrix_90_approach1_extra.cpp
│
│ REAL-WORLD SCENARIO:
│ Photo gallery app me image ko 90 degree clockwise rotate karna hai. Image pixels matrix hote hain; easiest method ek extra matrix banana hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. n*n matrix required for in-place style rotation problem.
│ 2. Extra matrix rotated[n][n] banao.
│ 3. Old cell A[i][j] new position rotated[j][n-1-i] me jayega.
│ 4. Har cell exactly once copy hota hai.
│ 5. Simple and safe approach, but extra space use karta hai.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Original:
│ 1 2 3
│ 4 5 6
│ 7 8 9
│
│ Mapping examples:
│ A[0][0]=1 -> R[0][2]
│ A[0][1]=2 -> R[1][2]
│ A[0][2]=3 -> R[2][2]
│ A[1][0]=4 -> R[0][1]
│
│ Rotated clockwise:
│ 7 4 1
│ 8 5 2
│ 9 6 3
│
│ DRY RUN:
│ n=3
│ i0j0: R[0][2]=1
│ i0j1: R[1][2]=2
│ i0j2: R[2][2]=3
│ i1j0: R[0][1]=4
│ i2j0: R[0][0]=7
│ Final first row: 7 4 1
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - Outer loop i runs n times.
│ - Inner loop j runs n times for each i.
│ - Total assignments = n*n = n².
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Extra rotated matrix stores n*n cells.
│ -> Space Complexity = O(n²).
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

