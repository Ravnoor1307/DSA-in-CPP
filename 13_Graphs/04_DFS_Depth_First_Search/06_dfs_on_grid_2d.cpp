/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_dfs_on_grid_2d.cpp
│
│ REAL-WORLD SCENARIO:
│ Paint bucket tool me ek pixel choose karte hi connected same-color area fill hota hai. Grid cells graph nodes hain, DFS flood fill connected cells change karta hai.
│
│ ASCII VISUAL / STACK-RECURSION STATE:
│ Grid before:
│ 1 1 1
│ 1 1 0
│ 1 0 1
│
│ Start (1,1), oldColor=1, newColor=2
│ DFS 4-direction:
│ (1,1) -> (0,1) -> (0,0) -> (1,0) -> (2,0)
│ also (0,2)
│
│ Grid after:
│ 2 2 2
│ 2 2 0
│ 2 0 1

│
│ STEP-BY-STEP DRY RUN:
│ dfs(1,1): color to2
│ go up (0,1): color to2
│ go left/right/down recursively
│ Boundary cells and different color cells stop recursion.

│
│ COMPLEXITY CALCULATION:
│ R*C total cells.
│ Each matching cell colored once.
│ For each colored cell, 4 directions checked.
│ Time = O(R*C).
│ Recursion stack worst all cells connected -> O(R*C).
│ No separate visited needed because color change marks visited.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

bool inside(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void floodFillDFS(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
    int R = image.size(), C = image[0].size();
    if (!inside(r, c, R, C) || image[r][c] != oldColor) return;
    image[r][c] = newColor; // Color change = visited mark.
    floodFillDFS(image, r - 1, c, oldColor, newColor);
    floodFillDFS(image, r + 1, c, oldColor, newColor);
    floodFillDFS(image, r, c - 1, oldColor, newColor);
    floodFillDFS(image, r, c + 1, oldColor, newColor);
}

int main() {
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int oldColor = image[1][1];
    floodFillDFS(image, 1, 1, oldColor, 2);
    for (auto row : image) {
        for (int x : row) cout << x << ' ';
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
2 2 2
2 2 0
2 0 1
*/

