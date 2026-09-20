/*
═══════════════════════════════════════════════
 ADDRESS CALCULATION — COLUMN-MAJOR
 ⏱️ TIME COMPLEXITY: O(1); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 If library shelves are stored in column sequence, reaching a target book
 requires skipping the previous columns first. This is the column-major
 address formula.

 📖 THEORY:
 - Column-major formula: Address(A[i][j]) = base + (j*nRows + i)*sizeof.
 - Skipping j previous columns means j*nRows elements are skipped.
 - Inside the target column, i more rows are skipped.
 - The same A[i][j] can have a different address than in row-major.
 - The formula depends on the language/storage layout context.

 ASCII VISUAL / MEMORY DIAGRAM:
 Example dimensions: 3 rows x 4 cols
 Target A[2][1]

 previous columns skipped = 1
 elements skipped by columns = 1 * 3 = 3
 rows skipped in target column = 2
 total offset = 3 + 2 = 5
 base=1000, sizeof(int)=4
 address = 1000 + 5*4 = 1020

 Same target row-major address was 1036.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Count the columns before column j.
    WHY: in column-major order those full columns come first.
 Step 2: Multiply by nRows to convert columns to elements.
    WHY: every complete column holds nRows elements.
 Step 3: Add i for the rows before the target in its own column.
    WHY: the target is the (i+1)th cell of that column.
 Step 4: Multiply the element offset by sizeof to get bytes.
    WHY: the base address counts bytes, not elements.
 Step 5: Add the byte offset to base.
    WHY: this yields the final memory address of A[i][j].

 DRY RUN:
 i=2, j=1, nRows=3
 offset = j*nRows+i = 1*3+2 = 5
 byteOffset = 5*4 = 20
 address = 1000+20 = 1020

 FLOW OF EXECUTION:
 input/setup matrix -> choose row/column/index -> apply formula/loops -> print visual result

 TIME COMPLEXITY CALCULATION:
 - Formula uses constant arithmetic operations.
 - No loop is required.
 -> Time Complexity = O(1).

 SPACE COMPLEXITY CALCULATION:
 - Only a few numeric variables are used.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

long long columnMajorAddress(long long base, int i, int j, int nRows, int size) {
    return base + 1LL * (j * nRows + i) * size;
}

int main() {
    long long base = 1000;
    int i = 2, j = 1, nRows = 3, size = sizeof(int);
    long long address = columnMajorAddress(base, i, j, nRows, size);
    cout << "Column-major formula: base + (j*nRows + i)*sizeof\n";
    cout << "Address = " << base << " + (" << j << "*" << nRows << " + " << i << ")*" << size << "\n";
    cout << "Address = " << address << "\n";
    return 0;
}

/*
OUTPUT:
Column-major formula: base + (j*nRows + i)*sizeof
Address = 1000 + (1*3 + 2)*4
Address = 1020
*/

