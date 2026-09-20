/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_search_in_matrix_approach1_bruteforce.cpp
│
│ REAL-WORLD SCENARIO:
│ Library me book dhundhne ka simplest tareeka hai har shelf aur har row check karna. Matrix brute-force search bhi every cell scan karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Target value define karo.
│ 2. Row 0 se last row tak jao.
│ 3. Har row me col 0 se last col tak compare karo.
│ 4. Agar A[i][j] == target, found return karo.
│ 5. Sorted property ki zarurat nahi.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│ 1  4  7
│ 2  5  8
│ 3  6  9
│ target=5
│ Scan order row-wise:
│ 1 -> 4 -> 7 -> 2 -> 5 FOUND
│
│ DRY RUN:
│ Compare A[0][0]=1 no
│ Compare A[0][1]=4 no
│ Compare A[0][2]=7 no
│ Compare A[1][0]=2 no
│ Compare A[1][1]=5 yes -> position (1,1)
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - In worst case target last cell/not present.
│ - Rows = R, columns = C.
│ - Total comparisons = R*C.
│ -> Time Complexity = O(R*C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - No extra data structure.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

pair<int,int> bruteSearch(const vector<vector<int>>& A, int target) {
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A[0].size(); j++) {
            cout << "compare " << A[i][j] << "\n";
            if (A[i][j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> A = {{1,4,7},{2,5,8},{3,6,9}};
    pair<int,int> pos = bruteSearch(A, 5);
    cout << "Found at: (" << pos.first << "," << pos.second << ")\n";
    return 0;
}

/*
OUTPUT:
compare 1
compare 4
compare 7
compare 2
compare 5
Found at: (1,1)
*/

