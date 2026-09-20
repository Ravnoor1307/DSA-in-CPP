/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_flood_fill.cpp
│
│ REAL-WORLD SCENARIO:
│ Paint app bucket tool me selected pixel ke connected same-color region ko new color se fill karna hai. Ye graph traversal on grid hai.
│
│ ASCII VISUAL / GRAPH-GRID STATE:
│ Image before:
│ 1 1 1
│ 1 1 0
│ 1 0 1
│
│ Start (1,1), newColor=2
│ Old color = 1
│ Connected same-color region:
│ (1,1),(0,1),(0,0),(0,2),(1,0),(2,0)
│
│ Image after:
│ 2 2 2
│ 2 2 0
│ 2 0 1

│
│ STEP-BY-STEP DRY RUN:
│ DFS start (1,1) -> color 2.
│ Explore up/down/left/right.
│ Stop when out of boundary or color != oldColor.
│ Color change also works as visited mark.

│
│ COMPLEXITY CALCULATION:
│ R*C cells total.
│ Each same-color reachable cell colored once.
│ For each, 4 directions checked -> O(4RC) = O(R*C).
│ Recursion stack worst all cells same color -> O(R*C).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool valid(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void fillDFS(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
    int R = image.size(), C = image[0].size();
    if (!valid(r, c, R, C) || image[r][c] != oldColor) return;
    image[r][c] = newColor; // Mark visited by repainting.
    fillDFS(image, r-1, c, oldColor, newColor);
    fillDFS(image, r+1, c, oldColor, newColor);
    fillDFS(image, r, c-1, oldColor, newColor);
    fillDFS(image, r, c+1, oldColor, newColor);
}

int main() {
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    int oldColor = image[sr][sc];
    if (oldColor != newColor) fillDFS(image, sr, sc, oldColor, newColor);
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

