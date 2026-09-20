/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_word_search_grid.cpp
│
│ REAL-WORLD SCENARIO:
│ Word puzzle grid me word adjacent letters se banana hai. Cell use karke visited mark karo, 4 directions explore karo, then undo so next path use kar sake.
│
│ ASCII VISUAL / DECISION STATE:
│ Board:
│ A B C E
│ S F C S
│ A D E E
│ Word = ABCCED
│
│ Path:
│ A(0,0) -> B(0,1) -> C(0,2) -> C(1,2) -> E(2,2) -> D(2,1)
│
│ Backtracking:
│ choose cell -> mark visited '#'
│ explore 4 directions
│ undo cell char restore

│
│ STEP-BY-STEP DRY RUN:
│ dfs(r,c,index):
│ if index == word.size -> true
│ if out/visited/wrong char -> false
│ mark current
│ try up/down/left/right
│ restore current

│
│ COMPLEXITY CALCULATION:
│ R*C starting cells.
│ From each cell, first step up to 4 choices, then at most 3 choices because cannot immediately go back visited.
│ Time upper bound = O(R*C*4*3^(L-1)) where L word length.
│ Space recursion depth O(L).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx) {
    int R = board.size(), C = board[0].size();
    if (idx == (int)word.size()) return true;
    if (r < 0 || r >= R || c < 0 || c >= C || board[r][c] != word[idx]) return false;

    char saved = board[r][c];
    board[r][c] = '#'; // CHOOSE + visited mark.
    bool found = dfs(board, word, r-1, c, idx+1) || dfs(board, word, r+1, c, idx+1) ||
                 dfs(board, word, r, c-1, idx+1) || dfs(board, word, r, c+1, idx+1);
    board[r][c] = saved; // UNDO.
    return found;
}

bool exist(vector<vector<char>> board, string word) {
    for (int r = 0; r < (int)board.size(); r++)
        for (int c = 0; c < (int)board[0].size(); c++)
            if (dfs(board, word, r, c, 0)) return true;
    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCCED";
    cout << "Exists? " << (exist(board, word) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Exists? YES
*/

