/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_bfs_on_grid_2d.cpp
│
│ REAL-WORLD SCENARIO:
│ City grid me har cell ek node hai, aur up/down/left/right moves edges hain. 2D matrix problems ko graph BFS se solve kar sakte hain.
│
│ ASCII VISUAL / QUEUE STATE:
│ Grid as graph:
│ 1 1 0
│ 0 1 1
│ 0 0 1
│
│ Cell (r,c) is a vertex.
│ 4-direction edges:
│ up    = (r-1,c)
│ down  = (r+1,c)
│ left  = (r,c-1)
│ right = (r,c+1)
│
│ BFS from (0,0):
│ q=[(0,0)]
│ pop(0,0) -> push(0,1)
│ pop(0,1) -> push(1,1)
│ pop(1,1) -> push(1,2)
│ pop(1,2) -> push(2,2)

│
│ STEP-BY-STEP DRY RUN:
│ visited matrix before:
│ 0 0 0
│ 0 0 0
│ 0 0 0
│
│ after BFS reachable land:
│ 1 1 0
│ 0 1 1
│ 0 0 1

│
│ COMPLEXITY CALCULATION:
│ Grid rows R, cols C, total cells = R*C.
│ Each cell enqueued at most once.
│ For each cell, 4 directions checked -> 4RC checks.
│ Time = O(R*C).
│ Space = visited R*C + queue R*C worst -> O(R*C).

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

int main() {
    vector<vector<int>> grid = {
        {1,1,0},
        {0,1,1},
        {0,0,1}
    };
    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> visited(R, vector<int>(C, 0));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    cout << "BFS cells: ";
    while (!q.empty()) {
        auto cell = q.front(); q.pop();
        int r = cell.first, c = cell.second;
        cout << "(" << r << "," << c << ") ";
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (inside(nr, nc, R, C) && grid[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = 1; // Cell ko ek hi baar queue me daalte hain.
                q.push({nr, nc});
            }
        }
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
BFS cells: (0,0) (0,1) (1,1) (1,2) (2,2)
*/

