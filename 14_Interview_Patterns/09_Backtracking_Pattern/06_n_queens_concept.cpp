/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_n_queens_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Chess board par queens place karni hain such that koi queen doosri ko attack na kare. Row-by-row choose column, unsafe hua to backtrack.
│
│ ASCII VISUAL / DECISION STATE:
│ 4-Queens board one solution:
│ . Q . .
│ . . . Q
│ Q . . .
│ . . Q .
│
│ Constraints:
│ same column not allowed
│ same diagonal not allowed
│ row-wise placement means same row automatically unique
│
│ Backtracking:
│ row0 try col0 -> later fail -> undo
│ row0 try col1 -> valid path -> solution
│
│ Diagonal ids:
│ diag1 = row - col + n - 1
│ diag2 = row + col

│
│ STEP-BY-STEP DRY RUN:
│ solve(row):
│ if row==n store board
│ for col 0..n-1:
│   if col/diags safe:
│      place Q
│      solve(row+1)
│      remove Q

│
│ COMPLEXITY CALCULATION:
│ Worst case tries many permutations of columns.
│ Upper bound O(n!) placements because one queen per row/column.
│ Safety with arrays is O(1).
│ Space = board O(n²) + recursion O(n) + helper arrays O(n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void solve(int row, int n, vector<string>& board, vector<int>& col, vector<int>& d1, vector<int>& d2, vector<vector<string>>& ans) {
    if (row == n) { ans.push_back(board); return; }
    for (int c = 0; c < n; c++) {
        int id1 = row - c + n - 1, id2 = row + c;
        if (col[c] || d1[id1] || d2[id2]) continue;
        board[row][c] = 'Q';
        col[c] = d1[id1] = d2[id2] = 1;
        solve(row + 1, n, board, col, d1, d2, ans);
        board[row][c] = '.'; // UNDO queen placement.
        col[c] = d1[id1] = d2[id2] = 0;
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<int> col(n, 0), d1(2*n-1, 0), d2(2*n-1, 0);
    vector<vector<string>> ans;
    solve(0, n, board, col, d1, d2, ans);
    cout << "Solutions = " << ans.size() << "\n";
    for (const string& row : ans[0]) cout << row << "\n";
    return 0;
}

/*
OUTPUT:
Solutions = 2
.Q..
...Q
Q...
..Q.
*/

