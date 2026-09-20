/*
═══════════════════════════════════════════════
 TASK SET — ROW-MAJOR vs COLUMN-MAJOR
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: In exam practice the teacher gives a base address
    and asks you to find the address of A[i][j]. In this task file you
    solve both row-major and column-major address problems.

 🧠 HOW TO SOLVE: Remember the two flat-index formulas — row-major gives
    i*cols+j, column-major gives j*rows+i. Flatten prints visit every cell
    exactly once; address functions are pure O(1) arithmetic.
 
 MODES/TOPICS COVERED:
   1. Print {{16,20},{30,50}} in row-major flat order
   2. Print the same matrix in column-major flat order
   3. Write a row-major address formula function
   4. Write a column-major address formula function
   5. Solve base=1000, A[2][1], rows=3, cols=4, size=4
   6. Note the row-major vs column-major difference in a comment
   7. Explain why C++ row-wise traversal is cache friendly
   ASCII/BEFORE-AFTER: 2x2 matrix flat in both orders + address outputs
   DRY RUN: row-major 1000+(2*4+1)*4=1036, column-major 1000+(1*3+2)*4=1020
   BEST COMPLEXITY: print O(R*C), address O(1), space O(R*C)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

long long rowMajor(long long base, int i, int j, int cols, int size) {
    return base + 1LL * (i * cols + j) * size;
}
long long colMajor(long long base, int i, int j, int rows, int size) {
    return base + 1LL * (j * rows + i) * size;
}

int main() {
    int A[2][2] = {{16,20},{30,50}};
    cout << "Row-major flat: ";
    for (int r = 0; r < 2; r++) for (int c = 0; c < 2; c++) cout << A[r][c] << " ";
    cout << "\nColumn-major flat: ";
    for (int c = 0; c < 2; c++) for (int r = 0; r < 2; r++) cout << A[r][c] << " ";
    cout << "\nRow-major address = " << rowMajor(1000, 2, 1, 4, 4) << "\n";
    cout << "Column-major address = " << colMajor(1000, 2, 1, 3, 4) << "\n";
    return 0;
}

/*
OUTPUT:
Row-major flat: 16 20 30 50
Column-major flat: 16 30 20 50
Row-major address = 1036
Column-major address = 1020
*/

