/*
═══════════════════════════════════════════════
 MATRIX DECLARATION AND INITIALIZATION
 ⏱️ TIME COMPLEXITY: full print O(R*C); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A marks register stores a table for 2 students and 2 subjects. In C++ this
 table is declared and initialized as `int A[2][2] = {{16,20},{30,50}}`.

 📖 THEORY:
 - `int A[2][2]` means 2 rows and 2 columns.
 - The outer braces represent the rows.
 - The first inner brace is row 0: {16,20}.
 - The second inner brace is row 1: {30,50}.
 - A value is accessed as A[row][col].

 ASCII VISUAL / MEMORY DIAGRAM:
 int A[2][2] = {{16,20},{30,50}}

        col0  col1
 row0    16    20
 row1    30    50

 A[0][0]=16, A[0][1]=20
 A[1][0]=30, A[1][1]=50

 🧠 LOGIC — STEP BY STEP:
 Step 1: Write `int A[2][2]`.
    WHY: it reserves 2 rows and 2 columns of ints.
 Step 2: Use the outer pair of braces.
    WHY: each inner brace lists the values of one row.
 Step 3: Put {16,20} as row 0.
    WHY: 16 goes to A[0][0] and 20 goes to A[0][1].
 Step 4: Put {30,50} as row 1.
    WHY: 30 goes to A[1][0] and 50 goes to A[1][1].
 Step 5: Print using nested loops with A[r][c].
    WHY: the row index and column index together address every cell.

 DRY RUN:
 After the declaration:
 A[0][0] prints 16.
 A[0][1] prints 20.
 A[1][0] prints 30.
 A[1][1] prints 50.

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Printing all elements uses nested loops.
 - Outer loop runs rows = 2 times.
 - Inner loop runs cols = 2 times per row.
 - Total visits = 2 * 2 = 4.
 -> For an R x C matrix, Time Complexity = O(R*C).

 SPACE COMPLEXITY CALCULATION:
 - The matrix itself stores R*C integers.
 - Extra variables r and c are constant.
 -> Extra Space Complexity = O(1), storage for matrix = O(R*C).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int A[2][2] = {{16, 20}, {30, 50}}; // Hinglish: notes wala example

    cout << "Matrix A:\n";
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            cout << "A[" << r << "][" << c << "]=" << setw(2) << A[r][c] << "  ";
        }
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
Matrix A:
A[0][0]=16  A[0][1]=20
A[1][0]=30  A[1][1]=50
*/

