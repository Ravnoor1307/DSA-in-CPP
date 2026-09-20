/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_symmetric_matrix.cpp
│
│ REAL-WORLD SCENARIO:
│ Mirror ke saamne left and right reflection same dikhta hai. Symmetric matrix me primary diagonal ke across mirror pairs equal hote hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Symmetric matrix square hoti hai.
│ 2. Condition: A[i][j] == A[j][i] for all i,j.
│ 3. Sirf upper triangle compare karna enough hai.
│ 4. Agar koi pair mismatch hua, matrix not symmetric.
│ 5. Diagonal elements apne aap equal hote hain.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ A:
│ 1 2 3
│ 2 5 6
│ 3 6 9
│
│ Mirror pairs:
│ A[0][1]=2 and A[1][0]=2
│ A[0][2]=3 and A[2][0]=3
│ A[1][2]=6 and A[2][1]=6
│
│ DRY RUN:
│ Check upper triangle:
│ (0,1) compare with (1,0): 2==2
│ (0,2) compare with (2,0): 3==3
│ (1,2) compare with (2,1): 6==6
│ all pass -> symmetric
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Upper triangle pairs count = n*(n-1)/2.
│ - This is approximately n²/2 comparisons.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only loop variables used.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isSymmetric(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Compare A[" << i << "][" << j << "] and A[" << j << "][" << i << "]\n";
            if (A[i][j] != A[j][i]) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{2,5,6},{3,6,9}};
    cout << "Symmetric? " << (isSymmetric(A) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Compare A[0][1] and A[1][0]
Compare A[0][2] and A[2][0]
Compare A[1][2] and A[2][1]
Symmetric? YES
*/

