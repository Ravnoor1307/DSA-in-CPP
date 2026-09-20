/*
┌────────────────────────────────────────────────────────────┐
│ FILE: task.cpp
│
│ REAL-WORLD SCENARIO:
│ Interview easy round me sorted library table search, diagonal road sum, and attendance max-ones row poochha ja sakta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Brute-force search implement karo.
│ 2. Row-wise binary search implement karo.
│ 3. Staircase search implement karo.
│ 4. Primary + secondary diagonal sum calculate karo.
│ 5. Row with maximum ones find karo.
│ 6. Har problem ke required sorted condition comments me likho.
│ 7. Complexity calculation with loop count likho.
│
│ HINTS:
│ - Brute force: nested loops.
│ - Row-wise BS: each row sorted.
│ - Staircase: top-right pointer.
│ - Diagonal center skip: if i != n-1-i.
│
│ STARTER CODE IDEA:
│ pair<int,int> search(vector<vector<int>>& A, int target)
│
│ SOLUTION: Neeche compact combined demo hai.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Search path target=9:
│ 11 -> left to 7 -> down to 8 -> down to 9 found.
│ Diagonal sum 3x3 = 25.
│ Row max ones answer row1.
│
│ DRY RUN:
│ Brute force compares cells one by one.
│ Binary search halves row each time.
│ Staircase removes one row/column per move.
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Brute force: R*C comparisons.
│ - Row-wise BS: R*log C, because C/2^k=1 => k=log₂C.
│ - Staircase: <=R+C moves.
│ - Diagonal sum: n iterations.
│
│ SPACE COMPLEXITY CALCULATION:
│ - All listed easy solutions use O(1) extra space.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int diagonalSum(const vector<vector<int>>& A) {
    int n = A.size(), sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
        if (i != n - 1 - i) sum += A[i][n - 1 - i];
    }
    return sum;
}

int main() {
    vector<vector<int>> A = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    int target = 9, r = 0, c = 3;
    while (r < 4 && c >= 0 && A[r][c] != target) {
        if (target < A[r][c]) c--; else r++;
    }
    cout << "Staircase found at: (" << r << "," << c << ")\n";
    vector<vector<int>> B = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Diagonal sum = " << diagonalSum(B) << "\n";
    cout << "Practice remaining solutions in files 01 to 05.\n";
    return 0;
}

/*
OUTPUT:
Staircase found at: (2,2)
Diagonal sum = 25
Practice remaining solutions in files 01 to 05.
*/

