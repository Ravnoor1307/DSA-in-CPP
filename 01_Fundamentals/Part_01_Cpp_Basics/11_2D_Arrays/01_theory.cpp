/*
═══════════════════════════════════════════════
 2D ARRAYS (Two-Dimensional Arrays)
 ⏱️ TIME COMPLEXITY: Traversal O(R*C), Transpose O(R*C), Row Sum O(C) per row
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you go to a cinema hall. Every seat is identified by a row number
 and a column number — Row 3, Seat 5. This is exactly a 2D array: a grid
 of data indexed by two coordinates. Movie ticket booking systems, Excel
 spreadsheets, chess boards, image pixels — all use this concept. When you
 open Google Maps, the tile grid is essentially a 2D array of map images.

 📖 THEORY: (pure English, beginner-level)
 - A 2D array is an array of arrays — a grid with R rows and C columns.
 - Declaration: int arr[R][C];
 - Initialization: arr[row][col] = value;
 - Memory is ROW-MAJOR: row 0 first, then row 1, etc. All elements are
   stored contiguously in a flat block of memory.
 - You can loop with nested for-loops: outer = rows, inner = columns.

 ASCII MEMORY LAYOUT — Row-Major (3x4 matrix):
 ┌──────────────────────────────────────────────────────────────────┐
 │  int matrix[3][4];  // 3 rows, 4 columns, 12 ints               │
 ├──────────────────────────────────────────────────────────────────┤
 │                                                                  │
 │  Logical View (Grid):          Flat Memory (Row-Major):          │
 │                                                                  │
 │      Col0  Col1  Col2  Col3    Index: 0  1  2  3  4  5  6  7   │
 │  ┌─────┬─────┬─────┬─────┐    ┌────┬────┬────┬────┬────┬────┐  │
 │  │  1  │  2  │  3  │  4  │    │  1 │  2 │  3 │  4 │  5 │  6 │  │
 │  ├─────┼─────┼─────┼─────┤    ├────┼────┼────┼────┼────┼────┤  │
 │  │  5  │  6  │  7  │  8  │    │  7 │  8 │  9 │ 10 │ 11 │ 12 │  │
 │  ├─────┼─────┼─────┼─────┤    └────┴────┴────┴────┴────┴────┘  │
 │  │  9  │ 10  │ 11  │ 12  │     Index: 8  9  10 11               │
 │  └─────┴─────┴─────┴─────┘                                      │
 │                                                                  │
 │  Address formula: addr(i,j) = base + (i*C + j) * sizeof(int)    │
 └──────────────────────────────────────────────────────────────────┘

 WHEN TO USE:
 - Grid/map data: chess, tic-tac-toe, maze solving
 - Matrix mathematics: image processing, physics simulations
 - Tables: student marks, timetable, spreadsheet

 🧠 LOGIC — STEP BY STEP (Traversal):
 Step 1: Loop i from 0 to R-1 (rows). WHY: we visit each row.
 Step 2: Loop j from 0 to C-1 (columns). WHY: inside each row, visit each cell.
 Step 3: Access arr[i][j]. WHY: this gives us the element at row i, col j.

 VISUAL WALKTHROUGH — Transpose:
 Input (2x3):           Output (3x2):
 ┌───┬───┬───┐          ┌───┬───┐
 │ 1 │ 2 │ 3 │          │ 1 │ 4 │
 ├───┼───┼───┤   ──►    ├───┼───┤
 │ 4 │ 5 │ 6 │          │ 2 │ 5 │
 └───┴───┴───┘          ├───┼───┤
                         │ 3 │ 6 │
 Rule: transpose[i][j] = original[j][i]

 DRY RUN — Row Sum (matrix 2x3):
 matrix = {{1,2,3}, {4,5,6}}

 i=0: sum=0
   j=0: sum += matrix[0][0] = 1  → sum=1
   j=1: sum += matrix[0][1] = 2  → sum=3
   j=2: sum += matrix[0][2] = 3  → sum=6
   → Row 0 sum = 6

 i=1: sum=0
   j=0: sum += matrix[1][0] = 4  → sum=4
   j=1: sum += matrix[1][1] = 5  → sum=9
   j=2: sum += matrix[1][2] = 6  → sum=15
   → Row 1 sum = 15

 TIME COMPLEXITY CALCULATION:
 - Traversal: outer loop runs R times, inner loop runs C times.
   Total element accesses = R * C
 - Transpose: same nested loops, R * C accesses.
 - Row Sum: for each row, C additions. For R rows: R * C additions.
 → Time Complexity = O(R * C)

 SPACE COMPLEXITY CALCULATION:
 - Original matrix: R * C integers.
 - Transpose matrix: C * R integers (new allocation).
 - Row sum: one int variable reused per row.
 → Space Complexity = O(R * C) for original, O(1) extra for traversal/sum

 APPROACH COMPARISON:
 ┌────────────────────┬──────────────────┬──────────────────────────────┐
 │ Operation          │ Complexity       │ Notes                        │
 ├────────────────────┼──────────────────┼──────────────────────────────┤
 │ Traversal          │ O(R*C)           │ Must visit every element     │
 │ Row Sum            │ O(R*C)           │ C adds per row, R rows       │
 │ Column Sum         │ O(R*C)           │ R adds per col, C columns    │
 │ Transpose          │ O(R*C)           │ Creates C x R matrix         │
 │ Diagonal Sum       │ O(min(R,C))      │ Only R or C elements          │
 └────────────────────┴──────────────────┴──────────────────────────────┘
*/

#include <iostream>
using namespace std;

int main() {

    // ═══════════════════════════════════════════
    // DEMO 1: Declaration + Initialization + Print
    // ═══════════════════════════════════════════
    cout << "=== DEMO 1: Print Matrix ===" << endl;

    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    int R = 3, C = 4;

    // matrix print karte hain — row by row
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    // Output:
    // 1   2   3   4
    // 5   6   7   8
    // 9   10  11  12

    // ═══════════════════════════════════════════
    // DEMO 2: Sum of Each Row
    // ═══════════════════════════════════════════
    cout << "\n=== DEMO 2: Sum of Each Row ===" << endl;

    for (int i = 0; i < R; i++) {
        int rowSum = 0;
        for (int j = 0; j < C; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum << endl;
    }
    // Output:
    // Row 0 sum = 10
    // Row 1 sum = 26
    // Row 2 sum = 42

    // ═══════════════════════════════════════════
    // DEMO 3: Transpose (Square Matrix)
    // ═══════════════════════════════════════════
    cout << "\n=== DEMO 3: Transpose (3x3) ===" << endl;

    int sq[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int trans[3][3];

    // transpose[i][j] = sq[j][i] — row aur col swap karte hain
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans[i][j] = sq[j][i];
        }
    }

    cout << "Original:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << sq[i][j] << "\t";
        cout << endl;
    }

    cout << "Transpose:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << trans[i][j] << "\t";
        cout << endl;
    }
    // Output Transpose:
    // 1   4   7
    // 2   5   8
    // 3   6   9

    // ═══════════════════════════════════════════
    // EDGE CASE: Rectangular matrix transpose
    // ═══════════════════════════════════════════
    cout << "\n=== EDGE CASE: Rectangular Transpose (2x3 -> 3x2) ===" << endl;

    int rect[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int rectT[3][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            rectT[j][i] = rect[i][j];  // size change hoti hai
        }
    }

    cout << "Original (2x3):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) cout << rect[i][j] << "\t";
        cout << endl;
    }

    cout << "Transpose (3x2):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) cout << rectT[i][j] << "\t";
        cout << endl;
    }
    // Output:
    // 1   4
    // 2   5
    // 3   6

    // ═══════════════════════════════════════════
    // EDGE CASE: 1x1 matrix
    // ═══════════════════════════════════════════
    cout << "\n=== EDGE CASE: 1x1 Matrix ===" << endl;
    int single[1][1] = {{42}};
    cout << "Single element: " << single[0][0] << endl;

    return 0;
}
