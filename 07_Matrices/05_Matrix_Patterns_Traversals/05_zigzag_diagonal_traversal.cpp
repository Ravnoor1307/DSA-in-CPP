/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_zigzag_diagonal_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ Elevator diagonals me alternate direction se floors visit kar raha hai: ek diagonal up-right, next down-left. Ye LeetCode style zigzag diagonal traversal hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Diagonal number s = row + col.
│ 2. Total diagonals = rows + cols - 1.
│ 3. Even s diagonal ko upward direction me traverse karo.
│ 4. Odd s diagonal ko downward direction me traverse karo.
│ 5. Boundaries ensure karo ki row/col valid rahe.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix:
│ 1 2 3
│ 4 5 6
│ 7 8 9
│
│ Diagonals by row+col:
│ s0: 1              -> up order: 1
│ s1: 2,4            -> down order: 2,4
│ s2: 3,5,7          -> up order from bottom: 7,5,3
│ s3: 6,8            -> down order: 6,8
│ s4: 9              -> up order: 9
│
│ Output: 1 2 4 7 5 3 6 8 9
│
│ DRY RUN:
│ s=0 even: start (0,0), output 1.
│ s=1 odd: start (0,1), move down-left: 2,4.
│ s=2 even: start (2,0), move up-right: 7,5,3.
│ s=3 odd: start (1,2), move down-left: 6,8.
│ s=4 even: output 9.
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Every cell belongs to exactly one diagonal.
│ - Total visited cells = R*C.
│ - Direction checks per diagonal = R+C-1.
│ -> Time Complexity = O(R*C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Output vector stores R*C elements.
│ -> Extra Space Complexity = O(R*C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> findDiagonalOrder(const vector<vector<int>>& A) {
    int rows = A.size(), cols = A[0].size();
    vector<int> ans;
    for (int s = 0; s <= rows + cols - 2; s++) {
        if (s % 2 == 0) {
            int r = min(s, rows - 1);
            int c = s - r;
            while (r >= 0 && c < cols) {
                ans.push_back(A[r][c]); // up-right
                r--;
                c++;
            }
        } else {
            int c = min(s, cols - 1);
            int r = s - c;
            while (c >= 0 && r < rows) {
                ans.push_back(A[r][c]); // down-left
                r++;
                c--;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = findDiagonalOrder(A);
    cout << "Zigzag diagonal traversal: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Zigzag diagonal traversal: 1 2 4 7 5 3 6 8 9
*/

