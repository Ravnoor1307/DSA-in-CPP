/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_number_of_islands_grid.cpp
│
│ REAL-WORLD SCENARIO:
│ Map grid me 1 land hai aur 0 water. Connected land cells milkar island banate hain. Har unvisited land se BFS/DFS launch = one island.
│
│ ASCII VISUAL / COMPONENT STATE:
│ 4x4 grid:
│ 1 1 0 0
│ 0 1 0 1
│ 1 0 0 1
│ 0 0 1 1
│
│ 4-direction connection only.
│ Island A: (0,0),(0,1),(1,1)
│ Island B: (1,3),(2,3),(3,3),(3,2)
│ Island C: (2,0)
│ Total islands = 3
│
│ Grid traversal:
│ Scan row-wise. Jab unvisited land mile, count++ and BFS us island ko mark.

│
│ STEP-BY-STEP DRY RUN:
│ scan (0,0) land unvisited -> island1, mark A.
│ scan (1,3) land unvisited -> island2, mark B.
│ scan (2,0) land unvisited -> island3, mark C.
│ Remaining land already visited.

│
│ COMPLEXITY CALCULATION:
│ R rows, C cols -> total cells = R*C.
│ Scan all cells once -> R*C checks.
│ BFS marks each land cell once and checks 4 directions -> at most 4RC direction checks.
│ Time = O(R*C).
│ Space = visited O(R*C) + queue O(R*C) worst = O(R*C).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool inside(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void bfsIsland(int sr, int sc, const vector<vector<int>>& grid, vector<vector<int>>& visited) {
    int R = grid.size(), C = grid[0].size();
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc] = 1;

    while (!q.empty()) {
        auto cell = q.front(); q.pop();
        int r = cell.first, c = cell.second;
        cout << "(" << r << "," << c << ") ";
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (inside(nr, nc, R, C) && grid[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = 1; // Land cell same island me mark.
                q.push({nr, nc});
            }
        }
    }
}

int numIslands(const vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> visited(R, vector<int>(C, 0));
    int islands = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 1 && !visited[r][c]) {
                islands++;
                cout << "Island " << islands << ": ";
                bfsIsland(r, c, grid, visited);
                cout << "\n";
            }
        }
    }
    return islands;
}

int main() {
    vector<vector<int>> grid = {{1,1,0,0}, {0,1,0,1}, {1,0,0,1}, {0,0,1,1}};
    cout << "Total islands = " << numIslands(grid) << "\n";
    return 0;
}

/*
OUTPUT:
Island 1: (0,0) (0,1) (1,1)
Island 2: (1,3) (2,3) (3,3) (3,2)
Island 3: (2,0)
Total islands = 3
*/

