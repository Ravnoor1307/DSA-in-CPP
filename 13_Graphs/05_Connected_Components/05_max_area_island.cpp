/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_max_area_island.cpp
│
│ REAL-WORLD SCENARIO:
│ Disaster map me largest land cluster ka area chahiye. Har island traverse karke uska size count karo, maximum track karo.
│
│ ASCII VISUAL / COMPONENT STATE:
│ Grid:
│ 1 1 0 0
│ 0 1 0 1
│ 1 0 0 1
│ 0 0 1 1
│
│ Island sizes:
│ A size = 3
│ B size = 4
│ C size = 1
│ Max area = 4
│
│ DFS returns area:
│ if outside/water/visited -> 0
│ mark cell visited
│ area = 1 + up + down + left + right

│
│ STEP-BY-STEP DRY RUN:
│ Start (0,0): area cells (0,0),(0,1),(1,1) -> 3.
│ Start (1,3): area cells (1,3),(2,3),(3,3),(3,2) -> 4.
│ Start (2,0): area = 1.
│ max = 4.

│
│ COMPLEXITY CALCULATION:
│ All cells scanned once -> R*C.
│ DFS visits each land cell once and checks 4 neighbors -> 4RC worst.
│ Time = O(R*C).
│ visited matrix O(R*C), recursion stack O(R*C) worst connected land.
│ Space = O(R*C).

│ APPROACH COMPARISON TABLE:
│ | Problem | Pattern | Real-world analogy | Time | Space |
│ | Count components | BFS/DFS from unvisited | friend circles | O(V+E) | O(V) |
│ | Number of islands | grid BFS/DFS | land clusters | O(R*C) | O(R*C) |
│ | Max area island | DFS returns size | largest island | O(R*C) | O(R*C) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool validCell(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

int dfsArea(int r, int c, const vector<vector<int>>& grid, vector<vector<int>>& visited) {
    int R = grid.size(), C = grid[0].size();
    if (!validCell(r, c, R, C) || grid[r][c] == 0 || visited[r][c]) return 0;
    visited[r][c] = 1;
    int area = 1; // Current land cell count.
    area += dfsArea(r - 1, c, grid, visited);
    area += dfsArea(r + 1, c, grid, visited);
    area += dfsArea(r, c - 1, grid, visited);
    area += dfsArea(r, c + 1, grid, visited);
    return area;
}

int maxAreaIsland(const vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> visited(R, vector<int>(C, 0));
    int best = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 1 && !visited[r][c]) {
                int area = dfsArea(r, c, grid, visited);
                cout << "Island area = " << area << "\n";
                best = max(best, area);
            }
        }
    }
    return best;
}

int main() {
    vector<vector<int>> grid = {{1,1,0,0}, {0,1,0,1}, {1,0,0,1}, {0,0,1,1}};
    cout << "Max area = " << maxAreaIsland(grid) << "\n";
    return 0;
}

/*
OUTPUT:
Island area = 3
Island area = 4
Island area = 1
Max area = 4
*/

