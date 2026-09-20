/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_search_in_matrix_approach3_staircase.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted office building me top-right corner se guard search karta hai. Agar target current se chhota hai to left jao; agar target bada hai to down jao. Ye staircase search hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Condition: rows sorted left-to-right and columns sorted top-to-bottom.
│ 2. Start top-right: row=0, col=C-1.
│ 3. If current == target, found.
│ 4. If target < current, left move because same column me neeche values aur bade honge.
│ 5. If target > current, down move because same row me left values aur chhote honge.
│ 6. Har step me one row ya one column eliminate hota hai.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│  1   4   7  11
│  2   5   8  12
│  3   6   9  16
│ 10  13  14  17
│ target=9
│
│ Start top-right 11
│ 9 < 11 -> left to 7
│ 9 > 7  -> down to 8
│ 9 > 8  -> down to 9 FOUND
│
│ Path: (0,3)->(0,2)->(1,2)->(2,2)
│
│ DRY RUN:
│ r=0,c=3 value11; target chhota -> c--
│ r=0,c=2 value7; target bada -> r++
│ r=1,c=2 value8; target bada -> r++
│ r=2,c=2 value9; found
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Start at top-right.
│ - Each move either row increases or column decreases.
│ - Row can increase at most R times.
│ - Column can decrease at most C times.
│ - Total moves <= R + C.
│ -> Time Complexity = O(R+C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only row and col pointers used.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

pair<int,int> staircaseSearch(const vector<vector<int>>& A, int target) {
    int rows = A.size(), cols = A[0].size();
    int r = 0, c = cols - 1;
    while (r < rows && c >= 0) {
        cout << "visit (" << r << "," << c << ") value=" << A[r][c] << "\n";
        if (A[r][c] == target) return {r, c};
        if (target < A[r][c]) c--; // target chhota -> left
        else r++;                  // target bada -> down
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> A = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    pair<int,int> pos = staircaseSearch(A, 9);
    cout << "Found at: (" << pos.first << "," << pos.second << ")\n";
    return 0;
}

/*
OUTPUT:
visit (0,3) value=11
visit (0,2) value=7
visit (1,2) value=8
visit (2,2) value=9
Found at: (2,2)
*/

