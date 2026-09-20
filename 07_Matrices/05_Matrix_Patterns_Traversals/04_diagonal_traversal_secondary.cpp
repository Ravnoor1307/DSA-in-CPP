/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_diagonal_traversal_secondary.cpp
│
│ REAL-WORLD SCENARIO:
│ Chess board par top-right se bottom-left diagonal line draw karo. Matrix secondary diagonal me i+j == n-1 hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Secondary diagonal condition: i + j == n - 1.
│ 2. For each row i, column j = n - 1 - i.
│ 3. Traverse i from 0 to n-1.
│ 4. Print/add A[i][n-1-i].
│ 5. Full matrix scan ki zarurat nahi.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│  1   2  [3]
│  4  [5]  6
│ [7]  8   9
│
│ Secondary diagonal: 3,5,7
│ Conditions: (0+2=2), (1+1=2), (2+0=2) for n=3
│
│ DRY RUN:
│ n=3
│ i=0 -> j=2 -> A[0][2]=3
│ i=1 -> j=1 -> A[1][1]=5
│ i=2 -> j=0 -> A[2][0]=7
│ sum=15
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Loop runs n times.
│ - Each iteration one computed column and access.
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
    cout << "Secondary diagonal: ";
    for (int i = 0; i < n; i++) {
        int j = n - 1 - i; // i+j=n-1
        cout << A[i][j] << " ";
        sum += A[i][j];
    }
    cout << "\nSum = " << sum << "\n";
    return 0;
}

/*
OUTPUT:
Secondary diagonal: 3 5 7
Sum = 15
*/

