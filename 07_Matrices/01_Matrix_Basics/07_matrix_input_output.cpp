/*
═══════════════════════════════════════════════
 MATRIX INPUT AND OUTPUT
 ⏱️ TIME COMPLEXITY: O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 To fill an Excel sheet a user enters values row by row and column by column.
 Matrix input and output use nested loops to read a table and print it back.

 📖 THEORY:
 - First decide the number of rows and columns.
 - Fill A[i][j] using nested loops.
 - Print the matrix using the same nested loop shape.
 - Online judges use cin; this demo uses a deterministic simulated
   stringstream input so the output is reproducible.
 - The reading order is usually row-wise.

 ASCII VISUAL / MEMORY DIAGRAM:
 Simulated input:
 rows=2, cols=3
 values: 1 2 3 4 5 6

 Filled matrix:
 1 2 3
 4 5 6

 🧠 LOGIC — STEP BY STEP:
 Step 1: Read rows and cols.
    WHY: these determine the dimensions of the 2D vector.
 Step 2: Create the matrix A(rows, vector<int>(cols)).
    WHY: memory is reserved for all R*C cells in advance.
 Step 3: For each row r, for each column c, read into A[r][c].
    WHY: nested loops fill the grid row by row.
 Step 4: Print the rows.
    WHY: nested loops output the grid in the same row-wise shape.
 Step 5: End with a newline after each row.
    WHY: gives the visual 2D table layout.

 DRY RUN:
 read rows=2, cols=3
 r0 c0=1, r0 c1=2, r0 c2=3
 r1 c0=4, r1 c1=5, r1 c2=6
 print row0 then row1

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Input loop visits R*C cells.
 - Output loop visits R*C cells.
 - Total visits = 2*R*C.
 -> Time Complexity = O(R*C).

 SPACE COMPLEXITY CALCULATION:
 - Matrix stores R*C values.
 -> Space Complexity = O(R*C).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    istringstream input("2 3 1 2 3 4 5 6"); // demo input, cin jaisa behave karega
    int rows, cols;
    input >> rows >> cols;
    vector<vector<int>> A(rows, vector<int>(cols));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) input >> A[r][c];
    }

    cout << "Matrix output:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) cout << A[r][c] << " ";
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
Matrix output:
1 2 3
4 5 6
*/

