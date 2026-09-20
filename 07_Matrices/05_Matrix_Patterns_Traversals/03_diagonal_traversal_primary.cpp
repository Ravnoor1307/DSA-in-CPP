/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_diagonal_traversal_primary.cpp
│
│ REAL-WORLD SCENARIO:
│ Chess board par top-left se bottom-right diagonal line draw karo. Matrix primary diagonal wahi cells hain jahan row index aur column index equal hote hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Primary diagonal condition: i == j.
│ 2. Square matrix me n primary diagonal elements hote hain.
│ 3. Traverse i from 0 to n-1 and print A[i][i].
│ 4. Full matrix scan ki zarurat nahi.
│ 5. Diagonal sum similarly add A[i][i].
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│ [1]  2   3
│  4  [5]  6
│  7   8  [9]
│
│ Primary diagonal: 1,5,9
│
│ DRY RUN:
│ i=0 -> A[0][0]=1
│ i=1 -> A[1][1]=5
│ i=2 -> A[2][2]=9
│ sum=15
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Loop runs n times.
│ - Each iteration one access and optional addition.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Output vector stores n elements.
│ -> Extra Space Complexity = O(n), O(1) if direct print/sum.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    int n = A.size();
    int sum = 0;
    cout << "Primary diagonal: ";
    for (int i = 0; i < n; i++) {
        cout << A[i][i] << " "; // i==j
        sum += A[i][i];
    }
    cout << "\nSum = " << sum << "\n";
    return 0;
}

/*
OUTPUT:
Primary diagonal: 1 5 9
Sum = 15
*/

