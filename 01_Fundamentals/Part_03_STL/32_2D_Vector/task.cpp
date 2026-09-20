/*
═══════════════════════════════════════════════
 TASK SET — 2D VECTOR / JAGGED ARRAY
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A school needs a class-wise seating chart, a
   height table transposed for the sports meet, diagonal sums for a
   badge-count grid, and a sales table per shop per month.

🧠 HOW TO SOLVE: Write row-major loops; remember g[r].size() is the
   row length; for transposes swap r/c roles; diagonals use r==c.

 TASKS (EASY → HARD):

 5) EASY — "Print The Seating Chart"
    Given a 2D vector of bench numbers, print every row on its own
    line using nested loops.
    💡 HINT: outer loop rows, inner loop g[r].size() columns.
    ✏️ STARTER CODE:
    // vector<vector<int>> g = {{1,2,3},{4,5},{6}};
    // TODO: print each row on its own line

 6) EASY — "Identity Matrix"
    Build an n x n matrix where every diagonal cell (i,i) is 1 and
    all other cells are 0. Print it.
    💡 HINT: vector<vector<int>> m(n, vector<int>(n,0)); then m[i][i]=1.
    ✏️ STARTER CODE:
    // int n = 4;
    // TODO: build and print the n x n identity matrix

 4) MEDIUM — "Transpose The Table"
    Given a 3x3 matrix, print its transpose (swap rows and columns).
    💡 HINT: transpose[r][c] = original[c][r].
    ✏️ STARTER CODE:
    // vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    // TODO: build transposed matrix and print it

 3) MEDIUM — "Diagonal Sum"
    Given an n x n square matrix, print the sum of the main diagonal
    and the sum of the anti-diagonal.
    💡 HINT: main diag runs r==c; anti diag runs r+c == n-1.
    ✏️ STARTER CODE:
    // vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    // TODO: sum main diag and anti diag, print both

 2) HARD — "Sales Table By Month"
    A shop records sales as a jagged table: shop i made a sale per
    day, but shops are open different numbers of days. Print shop
    number, each day's sale, and the shop TOTal.
    💡 HINT: total = 0; add g[i][j] in inner loop.
    ✏️ STARTER CODE:
    // vector<vector<int>> sales = {{120,80},{50,90,110},
    //                              {300}};
    // TODO: per row print day sales + row total

 1) HARD — "Class Rows Tallest Student"
    Given a jagged grid of student heights per class row, find and
    print the tallest height in EACH row (your own inner loop scan,
    no std::max).
    💡 HINT: mx = g[r][0]; compare every cell, update mx.
    ✏️ STARTER CODE:
    // vector<vector<int>> h = {{150,168},{172,155,180},{160}};
    // TODO: tallest per row, print "Row r: X cm"
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ========== TASK 5 — Print The Seating Chart ==========
    // EASY: row-major nested loops
    vector<vector<int>> g = {{1, 2, 3}, {4, 5}, {6}};
    cout << "T5 Seating chart:\n";
    for (size_t r = 0; r < g.size(); ++r) {
        cout << "  Row " << r << ": ";
        for (size_t c = 0; c < g[r].size(); ++c)
            cout << g[r][c] << " ";
        cout << "\n";
    }

    // ========== TASK 6 — Identity Matrix ==========
    // EASY: constructor se zeros, diagonal pe 1
    int n = 4;
    vector<vector<int>> id(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) id[i][i] = 1;      // main diag = 1
    cout << "\nT6 Identity " << n << "x" << n << ":\n";
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) cout << id[r][c] << " ";
        cout << "\n";
    }

    // ========== TASK 4 — Transpose The Table ==========
    // MEDIUM: 3x3 ka transpose
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> t(3, vector<int>(3));
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            t[r][c] = a[c][r];                     // swap roles
    cout << "\nT4 Transpose:\n";
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) cout << t[r][c] << " ";
        cout << "\n";
    }

    // ========== TASK 3 — Diagonal Sum ==========
    // MEDIUM: main r==c, anti r+c==n-1
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mainSum = 0, antiSum = 0;
    int sz = (int)m.size();
    for (int r = 0; r < sz; ++r) {
        mainSum += m[r][r];                        // main diagonal
        antiSum += m[r][sz - 1 - r];               // anti diagonal
    }
    cout << "\nT3 main diag sum = " << mainSum
         << ", anti diag sum = " << antiSum << "\n"; // 15 / 15

    // ========== TASK 2 — Sales Table By Month ==========
    // HARD: jagged rows, har row pe total
    vector<vector<int>> sales = {{120, 80}, {50, 90, 110}, {300}};
    cout << "\nT2 Sales per shop:\n";
    for (size_t r = 0; r < sales.size(); ++r) {
        int total = 0;
        cout << "  Shop " << r << ": ";
        for (size_t c = 0; c < sales[r].size(); ++c) {
            cout << sales[r][c] << " ";
            total += sales[r][c];                  // row total accumulate
        }
        cout << "| total = " << total << "\n";
    }

    // ========== TASK 1 — Class Rows Tallest Student ==========
    // HARD: har row ka max apne loop se
    vector<vector<int>> h = {{150, 168}, {172, 155, 180}, {160}};
    cout << "\nT1 Tallest per row:\n";
    for (size_t r = 0; r < h.size(); ++r) {
        int mx = h[r][0];                          // pehla student base
        for (size_t c = 1; c < h[r].size(); ++c)
            if (h[r][c] > mx) mx = h[r][c];        // naya max mila?
        cout << "  Row " << r << ": " << mx << " cm\n";
    }

    return 0;
}