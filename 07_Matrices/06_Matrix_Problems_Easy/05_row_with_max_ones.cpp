/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_row_with_max_ones.cpp
│
│ REAL-WORLD SCENARIO:
│ Class attendance sheet me 1 means present. Hume woh row dhundhni hai jisme maximum present students hain. Binary sorted rows me optimized top-right method kaam karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Matrix binary hai and each row sorted: 0s then 1s.
│ 2. Start top-right cell.
│ 3. Agar value 1 hai, current row candidate hai; left jao to aur 1s count improve ho sakta hai.
│ 4. Agar value 0 hai, niche jao because current row me left side bhi 0 hi honge.
│ 5. Last candidate row max ones wali hoti hai.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│ 0 0 1 1
│ 0 1 1 1
│ 0 0 0 1
│
│ start (0,3)=1 -> ans row0, left
│ (0,2)=1 -> ans row0, left
│ (0,1)=0 -> down
│ (1,1)=1 -> ans row1, left
│ (1,0)=0 -> down
│ (2,0)=0 -> down end
│ Answer row1 has 3 ones.
│
│ DRY RUN:
│ r0c3=1: ans=0, c=2
│ r0c2=1: ans=0, c=1
│ r0c1=0: r=1
│ r1c1=1: ans=1, c=0
│ r1c0=0: r=2
│ r2c0=0: r=3 stop
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Row pointer can move down at most R times.
│ - Column pointer can move left at most C times.
│ - Total moves <= R+C.
│ -> Time Complexity = O(R+C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only row, col, answer variables.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int rowWithMaxOnes(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    int r = 0, c = cols - 1, ans = -1;
    while (r < rows && c >= 0) {
        cout << "visit (" << r << "," << c << ") value=" << A[r][c] << "\n";
        if (A[r][c] == 1) {
            ans = r;
            c--; // aur left me 1 mile to count aur zyada
        } else {
            r++; // row me is column tak 0, next row try karo
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{0,0,1,1},{0,1,1,1},{0,0,0,1}};
    cout << "Row with max ones = " << rowWithMaxOnes(A) << "\n";
    return 0;
}

/*
OUTPUT:
visit (0,3) value=1
visit (0,2) value=1
visit (0,1) value=0
visit (1,1) value=1
visit (1,0) value=0
visit (2,0) value=0
Row with max ones = 1
*/

