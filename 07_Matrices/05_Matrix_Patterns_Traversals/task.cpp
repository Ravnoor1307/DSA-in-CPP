/*
┌────────────────────────────────────────────────────────────┐
│ FILE: task.cpp
│
│ REAL-WORLD SCENARIO:
│ Maze route practice me same matrix ko alag-alag routes se traverse karna hai: spiral, boundary, diagonal, zigzag, wave.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Primary diagonal print karo.
│ 2. Secondary diagonal print karo.
│ 3. Boundary traversal implement karo.
│ 4. Wave traversal implement karo.
│ 5. Spiral traversal implement karo.
│ 6. Zigzag diagonal traversal implement karo.
│ 7. Har traversal ka path ASCII arrows me draw karo.
│ 8. Complexity calculation likho.
│
│ HINTS:
│ - Spiral: four boundaries.
│ - Boundary: top row, right col, bottom row, left col.
│ - Diagonal: `i==j` and `i+j==n-1`.
│ - Wave: even columns down, odd columns up.
│
│ STARTER CODE IDEA:
│ vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
│
│ SOLUTION: Neeche short demo solution hai.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ 3x3 matrix:
│ 1 2 3
│ 4 5 6
│ 7 8 9
│ Spiral: 1 2 3 6 9 8 7 4 5
│ Wave:   1 4 7 8 5 2 3 6 9
│
│ DRY RUN:
│ Primary: 1,5,9
│ Secondary: 3,5,7
│ Boundary: 1,2,3,6,9,8,7,4
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - Diagonal tasks visit n elements = O(n).
│ - Spiral/wave/zigzag visit all R*C cells = O(R*C).
│ - Boundary visits 2R+2C-4 = O(R+C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - If printing directly, O(1) extra space.
│ - If storing output, O(number of output elements).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Primary diagonal: ";
    for (int i = 0; i < 3; i++) cout << A[i][i] << " ";
    cout << "\nSecondary diagonal: ";
    for (int i = 0; i < 3; i++) cout << A[i][2 - i] << " ";
    cout << "\nWave traversal: ";
    for (int c = 0; c < 3; c++) {
        if (c % 2 == 0) for (int r = 0; r < 3; r++) cout << A[r][c] << " ";
        else for (int r = 2; r >= 0; r--) cout << A[r][c] << " ";
    }
    cout << "\nStudy hint: complete spiral and zigzag from lesson files.\n";
    return 0;
}

/*
OUTPUT:
Primary diagonal: 1 5 9
Secondary diagonal: 3 5 7
Wave traversal: 1 4 7 8 5 2 3 6 9
Study hint: complete spiral and zigzag from lesson files.
*/

