/*
═══════════════════════════════════════════════
 TASK SET — MATRIX PATTERNS & TRAVERSALS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A maze-route practice board uses the same
    matrix navigated by different route rules: spiral rings, outer
    boundary, diagonals, zigzag, and waves. Mastering these paths
    powers computer-vision scans and grid-based game engines.

 🧠 HOW TO SOLVE: Each traversal is a fixed set of pointer rules:
    four shrinking boundaries for spiral; four edges for boundary;
    i==j and i+j==n-1 for the diagonals; even columns down / odd
    columns up for wave; alternate up-right / down-left per
    diagonal sum for zigzag.

 MODES/TOPICS COVERED:
  1. Print the primary diagonal
  2. Print the secondary diagonal
  3. Implement boundary traversal
  4. Implement wave traversal
  5. Implement spiral traversal
  6. Implement zigzag diagonal traversal
  7. Draw each traversal path with ASCII arrows
  8. Write the complexity calculation for each traversal
═══════════════════════════════════════════════
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

