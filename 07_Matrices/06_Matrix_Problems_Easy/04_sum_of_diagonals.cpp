/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_sum_of_diagonals.cpp
│
│ REAL-WORLD SCENARIO:
│ Cross-road intersection me do diagonal roads cross karti hain. Matrix diagonal sum me primary and secondary diagonals ka total chahiye, center ko double count nahi karna.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Primary diagonal: A[i][i].
│ 2. Secondary diagonal: A[i][n-1-i].
│ 3. For odd n, center element dono diagonals me common hota hai.
│ 4. If i == n-1-i, secondary add skip karo.
│ 5. Loop only n times.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│ 1 2 3
│ 4 5 6
│ 7 8 9
│
│ Primary: 1 + 5 + 9
│ Secondary: 3 + 5 + 7
│ Center 5 common, count once.
│ Total = 1+5+9+3+7 = 25
│
│ DRY RUN:
│ i=0: add A[0][0]=1 and A[0][2]=3 -> sum4
│ i=1: add A[1][1]=5 once -> sum9
│ i=2: add A[2][2]=9 and A[2][0]=7 -> sum25
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Loop runs n times.
│ - Each iteration has at most 2 additions.
│ - Total additions <= 2n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only sum and index variables.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int diagonalSum(const vector<vector<int>>& A) {
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
        if (i != n - 1 - i) sum += A[i][n - 1 - i]; // center double count avoid
    }
    return sum;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Diagonal sum = " << diagonalSum(A) << "\n";
    return 0;
}

/*
OUTPUT:
Diagonal sum = 25
*/

