/*
═══════════════════════════════════════════════
 MATRIX MULTIPLICATION — RESULT DIMENSIONS
 ⏱️ TIME COMPLEXITY: dimension rule O(1); derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 At a factory the number of raw-material categories (n) must match across two
 tables. If A is a suppliers table of size m×n and B is a cost table of size
 n×p, the result will be m×p.

 📖 THEORY:
 - A has dimensions m*n.
 - B has dimensions n*p.
 - If the inner n does not match, the multiplication is invalid.
 - The result rows come from A: m.
 - The result columns come from B: p.
 - Rule: (m*n)(n*p) = (m*p).

 ASCII VISUAL / MEMORY DIAGRAM:
 Dimension diagram:

 A(m x n)  ×  B(n x p)  =  C(m x p)
    2 x 3  ×    3 x 4   =     2 x 4
       └──── match ────┘

 Result takes outer dimensions:
 left rows = 2, right cols = 4

 🧠 LOGIC — STEP BY STEP:
 Step 1: Read A rows and A columns.
    WHY: A is the left multiplicand.
 Step 2: Read B rows and B columns.
    WHY: B is the right multiplicand.
 Step 3: Compare A columns with B rows.
    WHY: the inner dimension must match for the product to exist.
 Step 4: If they match, form the result as A rows × B columns.
    WHY: rows of the product come from A, columns from B.
 Step 5: Otherwise report invalid multiplication.
    WHY: a dimension mismatch means no product matrix exists.

 DRY RUN:
 A: 2x3
 B: 3x4
 A cols = 3, B rows = 3 -> valid
 Result = A rows x B cols = 2x4

 FLOW OF EXECUTION:
 setup matrices -> validate condition -> nested loops/formula -> output matrix

 TIME COMPLEXITY CALCULATION:
 - Dimension check uses constant comparisons.
 -> Time Complexity for the dimension rule = O(1).
 - Actual multiplication would be O(m*n*p).

 SPACE COMPLEXITY CALCULATION:
 - The dimension rule uses only integers.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int m = 2, n = 3, bRows = 3, p = 4;
    cout << "A dimensions = " << m << "x" << n << "\n";
    cout << "B dimensions = " << bRows << "x" << p << "\n";
    if (n == bRows) {
        cout << "Valid because A columns == B rows\n";
        cout << "Result dimensions = " << m << "x" << p << "\n";
    } else {
        cout << "Invalid multiplication\n";
    }
    return 0;
}

/*
OUTPUT:
A dimensions = 2x3
B dimensions = 3x4
Valid because A columns == B rows
Result dimensions = 2x4
*/

