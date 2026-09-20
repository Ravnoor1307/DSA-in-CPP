/*
┌────────────────────────────────────────────────────────────┐
│ FILE: task.cpp
│
│ REAL-WORLD SCENARIO:
│ Photo editor, spreadsheet cleaner, and factory optimizer practice ke liye medium matrix tasks solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Rotate 3x3 matrix 90 clockwise using extra matrix.
│ 2. Rotate 3x3 matrix 90 clockwise using transpose + reverse.
│ 3. Set Matrix Zeroes brute force approach likho.
│ 4. Set Matrix Zeroes O(1) space approach likho.
│ 5. Matrix chain multiplication cost for dims array solve karo.
│ 6. Boolean matrix row/column set implement karo.
│ 7. Har problem ka before->after ASCII state draw karo.
│ 8. Approach comparison table comments me likho.
│
│ HINTS:
│ - Rotate extra: new[j][n-1-i]=old[i][j].
│ - Rotate in-place: transpose then reverse rows.
│ - Set zeroes: first row/col markers carefully handle karo.
│ - Boolean matrix: marker arrays use karo to avoid cascading.
│
│ STARTER CODE IDEA:
│ vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
│
│ SOLUTION: Neeche compiled starter solution hai.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Rotate before:
│ 1 2 3
│ 4 5 6
│ 7 8 9
│ After clockwise:
│ 7 4 1
│ 8 5 2
│ 9 6 3
│
│ DRY RUN:
│ Set zeroes:
│ 1 1 1      1 0 1
│ 1 0 1  ->  0 0 0
│ 1 1 1      1 0 1
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - Rotate approaches visit n² cells/swaps -> O(n²).
│ - Brute zeroes worst n² zeros * 2n clearing = O(n³).
│ - In-place zeroes scans RC cells constant times = O(R*C).
│ - DP chain has n choices for length, i, split = O(n³).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Extra rotate uses O(n²), in-place rotate uses O(1).
│ - In-place zeroes uses O(1), boolean matrix markers use O(R+C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

void rotate90(vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) swap(A[i][j], A[j][i]);
    for (int i = 0; i < n; i++) reverse(A[i].begin(), A[i].end());
}

int main() {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    rotate90(A);
    cout << "Rotated matrix first row: ";
    for (int x : A[0]) cout << x << " ";
    cout << "\nSet zeroes hint: use first row and first column as markers.\n";
    cout << "MCM hint: dp[i][j] tries all split k.\n";
    return 0;
}

/*
OUTPUT:
Rotated matrix first row: 7 4 1
Set zeroes hint: use first row and first column as markers.
MCM hint: dp[i][j] tries all split k.
*/

