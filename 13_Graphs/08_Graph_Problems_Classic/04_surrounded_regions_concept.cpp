/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_surrounded_regions_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Board game me O regions jo boundary se connected nahi hain, wo captured ho jaate hain. Boundary se connected O safe hote hain; baaki O ko X flip karo.
│
│ ASCII VISUAL / GRAPH-GRID STATE:
│ Board before:
│ X X X X
│ X O O X
│ X X O X
│ X O X X
│
│ Boundary-connected O:
│ (3,1) is on boundary -> safe
│
│ Inner O region:
│ (1,1),(1,2),(2,2) surrounded by X -> capture
│
│ Board after:
│ X X X X
│ X X X X
│ X X X X
│ X O X X
│
│ Trick:
│ 1. DFS all boundary O and mark '#'.
│ 2. Flip remaining O to X.
│ 3. Flip # back to O.

│
│ STEP-BY-STEP DRY RUN:
│ Scan boundaries: find (3,1), mark safe '#'.
│ Interior O remain O.
│ Full scan:
│ O -> X captured.
│ # -> O restored.

│
│ COMPLEXITY CALCULATION:
│ R*C cells.
│ Boundary DFS marks each safe O once, 4 directions each -> O(R*C).
│ Final scan R*C -> O(R*C).
│ Total = O(R*C).
│ Recursion stack worst O(R*C).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool inBoard(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void markSafe(vector<vector<char>>& board, int r, int c) {
    int R = board.size(), C = board[0].size();
    if (!inBoard(r, c, R, C) || board[r][c] != 'O') return;
    board[r][c] = '#'; // Boundary connected O safe marker.
    markSafe(board, r-1, c);
    markSafe(board, r+1, c);
    markSafe(board, r, c-1);
    markSafe(board, r, c+1);
}

void solve(vector<vector<char>>& board) {
    int R = board.size(), C = board[0].size();
    for (int r = 0; r < R; r++) {
        markSafe(board, r, 0);
        markSafe(board, r, C-1);
    }
    for (int c = 0; c < C; c++) {
        markSafe(board, 0, c);
        markSafe(board, R-1, c);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 'O') board[r][c] = 'X';
            else if (board[r][c] == '#') board[r][c] = 'O';
        }
    }
}

int main() {
    vector<vector<char>> board = {{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
    solve(board);
    for (auto row : board) {
        for (char ch : row) cout << ch << ' ';
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
X X X X
X X X X
X X X X
X O X X
*/

