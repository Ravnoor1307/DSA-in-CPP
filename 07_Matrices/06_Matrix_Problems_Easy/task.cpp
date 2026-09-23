/*
═══════════════════════════════════════════════
 TASK SET — EASY MATRIX PROBLEMS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: The easy interview round often asks you to
    search a target in a sorted spreadsheet table, sum the diagonal
    roads of a city grid, and find the lecture hall row with the
    most present students.

 🧠 HOW TO SOLVE: Choose the fastest search the ordering allows:
    brute force needs no ordering; row-wise binary search needs each
    row sorted; the staircase method needs both rows and columns
    sorted. Diagonal sums use one loop with a centre double-count
    guard; max-ones uses the sorted-row pointer trick.

 MODES/TOPICS COVERED:
  1. Implement brute-force search
  2. Implement row-wise binary search
  3. Implement staircase search
  4. Calculate primary + secondary diagonal sum
  5. Find the row with the maximum number of ones
  6. Write the sorted condition required by each problem
  7. Write complexity calculations with loop counts
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int diagonalSum(const vector<vector<int>>& A) {
    int n = A.size(), sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
        if (i != n - 1 - i) sum += A[i][n - 1 - i];
    }
    return sum;
}

int main() {
    vector<vector<int>> A = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    int target = 9, r = 0, c = 3;
    while (r < 4 && c >= 0 && A[r][c] != target) {
        if (target < A[r][c]) c--; else r++;
    }
    cout << "Staircase found at: (" << r << "," << c << ")\n";
    vector<vector<int>> B = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Diagonal sum = " << diagonalSum(B) << "\n";
    cout << "Practice remaining solutions in files 01 to 05.\n";
    return 0;
}

/*
OUTPUT:
Staircase found at: (2,2)
Diagonal sum = 25
Practice remaining solutions in files 01 to 05.
*/

