/*
═══════════════════════════════════════════════
 2D ARRAY — INTRODUCTION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You book a ticket in a cinema hall: seat number "Row 3, Seat 5". One single
 number is not enough, because every seat is identified by TWO things — ROW
 and COLUMN. A school time-table is the same: day (row) × period (column).
 Sometimes data naturally comes shaped as a grid instead of one straight
 line — this grid is what we call a 2D array, which is really an "array of
 arrays".

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: A 2D ARRAY is an array whose EVERY ELEMENT is itself an
   array. It models data with two dimensions: rows and columns.
 - key points / properties:
   • Declare:   int mat[R][C];  → a grid with R rows and C columns.
   • Index:     mat[row][col] — row in 0..R-1, col in 0..C-1.
   • Memory is linear (flat); C/C++ stores it in ROW-MAJOR order — the
     whole first row, then the whole second row, and so on.
   • Address of mat[i][j] = base + (i*C + j) * sizeof(int)   (skip i rows,
     then j columns).
   • Useful whenever the data's natural shape is 2D: matrix, grid, image,
     chess board, table.

   Visual — 3x3 grid:
           col 0    col 1    col 2
      row0 ┌────────┬────────┬────────┐
           │  1     │  2     │  3     │
      row1 ├────────┼────────┼────────┤
           │  4     │  5     │  6     │
      row2 ├────────┼────────┼────────┤
           │  7     │  8     │  9     │
           └────────┴────────┴────────┘

   Flat memory (row-major):
   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │
      ^row0     ^row1 starts here

 - when to use:
   a) Data is naturally 2D (grid/matrix/spreadsheet).
   b) Images / game boards / mazes.
   c) Matrix arithmetic (add, multiply).
   d) Tables and grids in DP problems.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Decide the Rows (R) and Columns (C).
         WHY: mat[R][C] needs its shape known at compile time.
 Step 2: Fill/print with a nested loop — OUTER loop = ROW, INNER = COLUMN.
         WHY: Row-major order means memory and this loop visit the same
         sequence, which is cache-friendly.
 Step 3: ROW-MAJOR traversal — outer i (row), inner j (col).
         WHY: Go left-to-right inside each row; this is how row-major
         memory is laid out, so reads stay adjacent.
 Step 4: COLUMN-MAJOR traversal — outer j (col), inner i (row).
         WHY: To walk down a column, the COLUMN loop must be the outer one
         so the inner loop changes the row.
 Step 5: Access/update mat[i][j] — specify BOTH row and column.
         WHY: A cell's identity comes from two indices, not one.

 VISUAL WALKTHROUGH:
   mat[3][3] in row-major flat memory (base 1000, int = 4 bytes):

   Index pair   mat[0][0] mat[0][1] mat[0][2] mat[1][0] mat[1][1] mat[1][2] ...
   Flat offset    0         1         2         3         4         5
   Address       1000      1004      1008      1012      1016      1020
                  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   Value          │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │
                  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

 DRY RUN: (trace of the demo below)
   mat[2][3] = { {1,2,3}, {4,5,6} }  (R=2, C=3)

   ROW-MAJOR traversal order:
     mat[0][0]=1, mat[0][1]=2, mat[0][2]=3,   <- row 0 complete
     mat[1][0]=4, mat[1][1]=5, mat[1][2]=6    <- row 1 complete

   COLUMN-MAJOR traversal order:
     mat[0][0]=1, mat[1][0]=4,   <- column 0 complete
     mat[0][1]=2, mat[1][1]=5,   <- column 1 complete
     mat[0][2]=3, mat[1][2]=6    <- column 2 complete

   mat[2][1] access → flat index = 2*3 + 1 = 7 → value 6? NO — mat[2][1]
   is WRONG because there are only 2 rows (0..1). The correct access is
   mat[1][2] = 6. Always remember the bounds!

 TIME COMPLEXITY CALCULATION:
   - access mat[i][j]        : 1 mult (i*C) + 1 add → f(n) = 1
   - fill/print all R*C cells: nested loop, inner statement runs R*C times
                               f(R,C) = R*C
   - row-sum or column-sum   : full single traversal of R*C → f(R,C) = R*C
   → Time Complexity = O(1) for single access, O(R*C) for full traversal

 SPACE COMPLEXITY CALCULATION:
   - mat[R][C] storage       : R*C cells × 4 bytes → f(R,C) = R*C
   - no extra array needed   : traversal uses only loop counters → f(R,C) = 1
   → Space Complexity = O(R*C) for the matrix, O(1) extra

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Point                │  1D ARRAY                    │  2D ARRAY                    │
 ├──────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Shape                │ one line (0..n-1)            │ grid: rows × columns         │
 │ Index                │ a[i]                         │ a[i][j]                      │
 │ Nested loops?        │ no — one loop                │ yes — 2 loops (row, col)     │
 │ Flat address         │ base + i*size                │ base + (i*C + j)*size        │
 │ Represents           │ list, scores                 │ matrix, spreadsheet, image   │
 │ Traversal choice     │ single order                 │ row-major or column-major    │
 └──────────────────────┴──────────────────────────────┴──────────────────────────────┘
 */
#include <iostream>
using namespace std;

int main() {
    const int R = 3, C = 3;
    int mat[R][C] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "1) ROW-MAJOR traversal (row by row):\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n2) COLUMN-MAJOR traversal (column by column ke neeche):\n";
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n3) Single access mat[2][1] = " << mat[2][1]
         << "   (flat offset = 2*" << C << " + 1 = " << (2 * C + 1) << ")\n";

    cout << "4) Row 1 poori ek sath print (row view): ";
    for (int j = 0; j < C; j++) {
        cout << mat[1][j] << " ";
    }
    cout << "\n";

    cout << "5) Column 2 poori print (column view): ";
    for (int i = 0; i < R; i++) {
        cout << mat[i][2] << " ";
    }
    cout << "\n";

    cout << "Total elements = " << R * C
         << ", flat memory me last cell ka offset = " << R * C - 1 << "\n";
    return 0;
}