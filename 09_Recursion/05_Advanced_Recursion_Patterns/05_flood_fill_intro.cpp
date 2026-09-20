/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_flood_fill_intro.cpp
│
│ REAL-WORLD SCENARIO:
│ Paint bucket tool image me ek cell se same color area me color spread karta hai. Flood fill 2D recursion ka intro hai aur graphs/DFS ka preview hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Start cell (sr,sc) choose karo.
│ 2. Old color store karo.
│ 3. Agar cell boundary ke bahar hai, return.
│ 4. Agar cell old color ka nahi hai, return.
│ 5. Cell ko new color set karo.
│ 6. 4 directions me recurse: up, down, left, right.
│ 7. Same color connected area fill hota hai.
│
│ ASCII VISUAL / RECURSION TREE STATE:
│ Grid before (old color 1, new color 2, start at center):
│ 1 1 0
│ 1 1 0
│ 0 0 1
│
│ Spread from (1,1):
│ (1,1) -> (0,1) -> (0,0) -> (1,0)
│ right side zeros block spread.
│ bottom-right 1 disconnected, unchanged.
│
│ Grid after:
│ 2 2 0
│ 2 2 0
│ 0 0 1
│
│ DRY RUN:
│ start (1,1)=1 fill 2
│ recurse up (0,1) fill
│ recurse left (0,0) fill
│ recurse down (1,0) fill
│ zeros and boundaries stop recursion.
│
│ FLOW OF EXECUTION:
│ input/problem state -> recursive choices -> base cases -> undo/unwind/output
│
│ COMPLEXITY CALCULATION:
│ - Each cell can be colored at most once.
│ - For R*C grid, visits/checks bounded by constant directions per cell.
│ - Total work <= 4*R*C checks.
│ -> Time Complexity = O(R*C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack in worst case can include all connected cells.
│ -> Space Complexity = O(R*C) worst-case stack.
│ APPROACH COMPARISON TABLE:
│ Recursive DFS = paint spreads through neighbors, O(R*C) time/O(R*C) stack worst.
│ Iterative BFS/DFS = queue/stack container, O(R*C) time/O(R*C) container space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

void floodFill(vector<vector<int>>& grid, int r, int c, int oldColor, int newColor) {
    int rows = grid.size(), cols = grid[0].size();
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (grid[r][c] != oldColor) return;
    grid[r][c] = newColor; // paint current cell
    floodFill(grid, r - 1, c, oldColor, newColor);
    floodFill(grid, r + 1, c, oldColor, newColor);
    floodFill(grid, r, c - 1, oldColor, newColor);
    floodFill(grid, r, c + 1, oldColor, newColor);
}

int main() {
    vector<vector<int>> grid = {{1,1,0},{1,1,0},{0,0,1}};
    cout << "Before:\n";
    printGrid(grid);
    int sr = 1, sc = 1, newColor = 2;
    int oldColor = grid[sr][sc];
    if (oldColor != newColor) floodFill(grid, sr, sc, oldColor, newColor);
    cout << "After flood fill:\n";
    printGrid(grid);
    return 0;
}

/*
OUTPUT:
Before:
1 1 0
1 1 0
0 0 1
After flood fill:
2 2 0
2 2 0
0 0 1
*/

