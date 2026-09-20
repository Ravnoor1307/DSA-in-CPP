/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_roton_oranges_multi_bfs.cpp
│
│ REAL-WORLD SCENARIO:
│ Fruit warehouse me rotten oranges infection ki tarah adjacent fresh oranges ko minute-by-minute rotten karte hain. Multiple rotten sources ek saath BFS wave start karte hain.
│
│ ASCII VISUAL / GRAPH-GRID STATE:
│ Grid legend:
│ 0 = empty, 1 = fresh, 2 = rotten
│
│ Initial:
│ 2 1 1
│ 1 1 0
│ 0 1 1
│
│ Minute 1:
│ 2 2 1
│ 2 1 0
│ 0 1 1
│
│ Minute 2:
│ 2 2 2
│ 2 2 0
│ 0 1 1
│
│ Minute 3:
│ 2 2 2
│ 2 2 0
│ 0 2 1
│
│ Minute 4:
│ 2 2 2
│ 2 2 0
│ 0 2 2
│
│ Answer = 4 minutes

│
│ STEP-BY-STEP DRY RUN:
│ Queue starts with all rotten cells: [(0,0,0)]
│ Pop (0,0,time0), rot neighbors (0,1),(1,0) with time1.
│ Next wave rots distance2 fresh cells.
│ Last fresh (2,2) rots at time4.

│
│ COMPLEXITY CALCULATION:
│ R*C total cells.
│ Each orange enters queue at most once.
│ For each queued cell, 4 directions checked.
│ Direction checks <= 4RC.
│ Time = O(R*C).
│ Space = queue O(R*C) worst.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool inside(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

int orangesRotting(vector<vector<int>> grid) {
    int R = grid.size(), C = grid[0].size();
    queue<pair<pair<int,int>, int>> q;
    int fresh = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 2) q.push({{r,c}, 0}); // All sources ek saath.
            if (grid[r][c] == 1) fresh++;
        }
    }
    int ans = 0;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int r = cur.first.first, c = cur.first.second, time = cur.second;
        ans = max(ans, time);
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (inside(nr, nc, R, C) && grid[nr][nc] == 1) {
                grid[nr][nc] = 2;
                fresh--;
                q.push({{nr,nc}, time + 1});
            }
        }
    }
    return fresh == 0 ? ans : -1;
}

int main() {
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    cout << "Minutes = " << orangesRotting(grid) << "\n";
    return 0;
}

/*
OUTPUT:
Minutes = 4
*/

