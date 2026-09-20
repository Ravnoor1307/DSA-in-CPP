/*
═══════════════════════════════════════════════
 ADDRESS CALCULATION — ROW-MAJOR
 ⏱️ TIME COMPLEXITY: O(1); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Books on a library shelf are arranged in rows. To find the exact address of
 a book, first skip the previous rows, then add the column offset inside the
 current row.

 📖 THEORY:
 - Row-major formula: Address(A[i][j]) = base + (i*nCols + j)*sizeof.
 - Skipping i rows means i*nCols elements are skipped.
 - Inside the same row, j more columns are skipped.
 - Total element offset = i*nCols + j.
 - Byte offset = element offset * sizeof(datatype).

 ASCII VISUAL / MEMORY DIAGRAM:
 Example matrix dimensions: 3 rows x 4 cols
 Target A[2][1]

 rows before target = row0 + row1 = 2 rows
 elements skipped by rows = 2 * 4 = 8
 columns skipped in target row = 1
 total offset = 8 + 1 = 9
 base=1000, sizeof(int)=4
 address = 1000 + 9*4 = 1036

 🧠 LOGIC — STEP BY STEP:
 Step 1: Count the rows before row i.
    WHY: in row-major order those full rows come first.
 Step 2: Multiply by nCols to convert rows to elements.
    WHY: every complete row holds nCols elements.
 Step 3: Add j for the columns before the target in its own row.
    WHY: the target is the (j+1)th cell of that row.
 Step 4: Multiply the element offset by sizeof to get bytes.
    WHY: the base address counts bytes, not elements.
 Step 5: Add the byte offset to base.
    WHY: this yields the final memory address of A[i][j].

 DRY RUN:
 i=2, j=1, nCols=4
 offset = i*nCols+j = 2*4+1 = 9
 byteOffset = 9*4 = 36
 address = 1000+36 = 1036

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

long long rowMajorAddress(long long base, int i, int j, int nCols, int size) {
    return base + 1LL * (i * nCols + j) * size;
}

int main() {
    long long base = 1000;
    int i = 2, j = 1, nCols = 4, size = sizeof(int);
    long long address = rowMajorAddress(base, i, j, nCols, size);
    cout << "Row-major formula: base + (i*nCols + j)*sizeof\n";
    cout << "Address = " << base << " + (" << i << "*" << nCols << " + " << j << ")*" << size << "\n";
    cout << "Address = " << address << "\n";
    return 0;
}

/*
OUTPUT:
Row-major formula: base + (i*nCols + j)*sizeof
Address = 1000 + (2*4 + 1)*4
Address = 1036
*/

