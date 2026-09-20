/*
═══════════════════════════════════════════════
 TASK SET — 2D Arrays
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: Cinema halls use seat grids (rows x columns),
    chess games use 8x8 boards, and Google Maps tiles are 2D arrays.
    Every grid-based problem maps to 2D arrays.
 🧠 HOW TO SOLVE: Use nested loops — outer for rows, inner for columns.
    Think of each cell as matrix[i][j]. Pattern: initialize, traverse, transform.
 MODES/TOPICS COVERED:
   1. Diagonal Sum
   2. Print Multiplication Table Grid
   3. Matrix Addition
   4. Matrix Multiplication
   5. Rotate Matrix 90° Clockwise
   6. Spiral Order Traversal

 TASK 1 (EASY): Diagonal Sum
    Given a square matrix, find sum of all diagonal elements.
    Hint: Diagonal elements satisfy i == j (primary) and i+j == n-1 (secondary).
    // STARTER CODE:
    // int diagSum(int mat[][N], int n) { ... }

 TASK 2 (EASY): Print Multiplication Table Grid
    Print an NxN multiplication table as a 2D grid.
    Hint: mat[i][j] = (i+1) * (j+1), indices are 0-based.
    // STARTER CODE:
    // void multTable(int n, int mat[][N]) { ... }

 TASK 3 (MEDIUM): Matrix Addition
    Given two matrices of same size, return their sum.
    Hint: sum[i][j] = a[i][j] + b[i][j] — add element-wise.
    // STARTER CODE:
    // void addMatrices(int a[][N], int b[][N], int res[][N], int r, int c) { ... }

 TASK 4 (MEDIUM): Matrix Multiplication
    Given two matrices A (R1xC) and B (CxR2), compute A*B.
    Hint: res[i][j] = sum of A[i][k] * B[k][j] for all k. A triple loop is needed.
    // STARTER CODE:
    // void multiply(int a[][N], int b[][N], int res[][N], int r1, int c1, int c2) { ... }

 TASK 5 (HARD): Rotate Matrix 90° Clockwise
    Rotate an NxN matrix 90 degrees clockwise in-place.
    Hint: First transpose, then reverse every row.
    // STARTER CODE:
    // void rotate90(int mat[][N], int n) { ... }

 TASK 6 (HARD): Spiral Order Traversal
    Print matrix in spiral order: top row → right col → bottom row → left col → inner.
    Hint: Use 4 boundaries: top, bottom, left, right. Shrink them on every pass.
    // STARTER CODE:
    // void spiralPrint(int mat[][N], int r, int c) { ... }

═══════════════════════════════════════════════
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;  // max size — global const to avoid VLA

// ═══════════════════════════════════════════
// TASK 1 SOLUTION: Diagonal Sum
// ═══════════════════════════════════════════
// Logic: Primary diagonal pe i==j, secondary pe i+j==n-1
// Dono ka sum nikalte hain, center element (odd n) ek baar count hota hai
int diagSum(int mat[][N], int n) {
    int primary = 0, secondary = 0;
    for (int i = 0; i < n; i++) {
        primary += mat[i][i];            // top-left to bottom-right
        secondary += mat[i][n - 1 - i];  // top-right to bottom-left
    }
    // agar n odd hai to center element twice count hua — subtract once
    if (n % 2 == 1)
        primary -= mat[n / 2][n / 2];
    return primary + secondary;
}

// ═══════════════════════════════════════════
// TASK 2 SOLUTION: Multiplication Table Grid
// ═══════════════════════════════════════════
// har cell (i,j) pe value = (i+1)*(j+1) — 1-based indexing
void multTable(int n, int mat[][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = (i + 1) * (j + 1);
        }
    }
}

// ═══════════════════════════════════════════
// TASK 3 SOLUTION: Matrix Addition
// ═══════════════════════════════════════════
// har cell pe element-wise addition
void addMatrices(int a[][N], int b[][N], int res[][N], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

// ═══════════════════════════════════════════
// TASK 4 SOLUTION: Matrix Multiplication
// ═══════════════════════════════════════════
// Classic triple loop — a ki row, b ki column, aur dot product
void multiply(int a[][N], int b[][N], int res[][N], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// ═══════════════════════════════════════════
// TASK 5 SOLUTION: Rotate 90° Clockwise
// ═══════════════════════════════════════════
// Trick: Transpose karo phir har row reverse karo
void rotate90(int mat[][N], int n) {
    // Step 1: Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Step 2: Har row ko reverse karo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(mat[i][j], mat[i][n - 1 - j]);
        }
    }
}

// ═══════════════════════════════════════════
// TASK 6 SOLUTION: Spiral Order Traversal
// ═══════════════════════════════════════════
// 4 boundaries maintain karte hain: top, bottom, left, right
void spiralPrint(int mat[][N], int r, int c) {
    int top = 0, bottom = r - 1, left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        // top row: left se right
        for (int j = left; j <= right; j++)
            cout << mat[top][j] << " ";
        top++;

        // right column: top se bottom
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        // bottom row: right se left (agar rows bachi hain)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << mat[bottom][j] << " ";
            bottom--;
        }

        // left column: bottom se top (agar cols bachi hain)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
    cout << endl;
}

// ═══════════════════════════════════════════
// DRIVER — saare tasks run karte hain
// ═══════════════════════════════════════════
int main() {

    // --- Task 1: Diagonal Sum ---
    cout << "=== TASK 1: Diagonal Sum ===" << endl;
    int mat1[4][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "Diagonal Sum = " << diagSum(mat1, 4) << endl;
    // 1+6+11+16 + 4+7+10+13 = 68
    cout << endl;

    // --- Task 2: Multiplication Table ---
    cout << "=== TASK 2: 5x5 Multiplication Table ===" << endl;
    int tbl[N][N];
    multTable(5, tbl);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << tbl[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // --- Task 3: Matrix Addition ---
    cout << "=== TASK 3: Matrix Addition ===" << endl;
    int a[N][N] = {{1, 2, 3}, {4, 5, 6}};
    int b[N][N] = {{7, 8, 9}, {10, 11, 12}};
    int sum[N][N];
    addMatrices(a, b, sum, 2, 3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            cout << sum[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // --- Task 4: Matrix Multiplication ---
    cout << "=== TASK 4: Matrix Multiplication ===" << endl;
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];
    multiply(A, B, C, 2, 2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }
    // Output: 19 22
    //         43 50
    cout << endl;

    // --- Task 5: Rotate 90° ---
    cout << "=== TASK 5: Rotate 90° Clockwise ===" << endl;
    int rot[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate90(rot, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << rot[i][j] << "\t";
        cout << endl;
    }
    // Output:
    // 7   4   1
    // 8   5   2
    // 9   6   3
    cout << endl;

    // --- Task 6: Spiral Print ---
    cout << "=== TASK 6: Spiral Traversal ===" << endl;
    int sp[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    spiralPrint(sp, 3, 4);
    // Output: 1 2 3 4 8 12 11 10 9 5 6 7

    // --- EDGE CASE: 1x1 matrix ---
    cout << "\n=== EDGE CASE: 1x1 Matrix ===" << endl;
    int single[N][N] = {{42}};
    cout << "Diagonal Sum = " << diagSum(single, 1) << endl;

    // --- EDGE CASE: Empty spiral (0 rows) ---
    cout << "Spiral of empty: ";
    spiralPrint(single, 0, 0);
    cout << "(nothing printed)" << endl;

    return 0;
}
