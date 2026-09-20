/*
═══════════════════════════════════════════════
 VECTOR OF VECTORS — 2D VECTOR / JAGGED ARRAY
 ⏱️ TIME COMPLEXITY: access v[i][j] O(1), building O(rows×cols),
     reading all cells O(rows × cols).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A school building's seating chart: the outer register holds one row
 per classroom, and each classroom row shows its own students. The
 classrooms do not all have the same number of benches — Class 6 has
 4 students, Class 7 has 6, Class 8 has 3. This exact structure is a
 vector of vectors: the OUTER vector stores pointers to rows, and each
 INNER vector is an independent row with its own length. When the
 principal asks "who sits in row 2, bench 0?", you point at the outer
 register, jump to row 2, then the first bench — O(1).

 📖 THEORY:

 - A 2D vector is mathematically like a matrix but physically it is a
   vector whose elements are THEMSELVES vectors.
   vector<vector<int>> grid;   // matrix (square/rectangular)
   vector<vector<int>> jagged; // rows may differ in length

 - Memory picture: the outer vector block holds pointers/headers to
   inner vectors; each inner vector is a separate contiguous block:

              OUTER vector<int, vector<int>>
              ┌─────────┬─────────┬─────────┐
              │ row[0]——┼─► ┌─┬─┬─┐         │
              │ row[1]──┼──► │4│5│6│7│      │
              │ row[2]──┼───► └─┴─┴─┘        │
              └─────────┴─────────┴─────────┘
                 │         │
                 ▼         ▼
              ┌─┬─┬─┐   ┌─┬─┐
              │1│2│3│   │8│9│   <-- each inner vector = 1 row
              └─┴─┴─┘   └─┴─┘

 - DECLARATION:
   vector<vector<int>> sq(3, vector<int>(3));      // 3x3 zero matrix
   vector<vector<int>> sq2(3, vector<int>(3, 7));  // 3x3 all 7

 - JAGGED / RAGGED array: rows of different lengths. Build each row
   separately:
   vector<vector<int>> jag;
   jag.push_back(vector<int>{1,2,3});
   jag.push_back(vector<int>{4,5});
   jag.push_back(vector<int>{6,7,8,9});

 - INNER RESIZE: resize each inner row independently:
   vector<vector<int>> g(3);       // 3 rows, all empty
   g[0].resize(2);                 // row0 gets 2 columns
   g[1].resize(4);                 // row1 gets 4 columns

 - ACCESS: v[i][j]  → first [i] selects the row vector,
   second [j] indexes that row; O(1) both times.

 - PRINT LOOP ORDER: rows on the outside, columns inside (row-major).
   for (size_t r = 0; r < g.size(); ++r) {
       for (size_t c = 0; c < g[r].size(); ++c) cout << g[r][c];
   }

 - WHEN TO USE: matrices, grids, tables, seating charts, image pixels,
   adjacency lists of graphs.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Decide shape. Square matrix → build all rows with the same inner
         size. Jagged → push each row separately.
         WHY: vector<vector<int>> lets every row be its own vector.

 Step 2: Create outer vectors first, then fill.
         WHY: g[r].size() must exist before we access g[r][c],
         so every row needs at least an empty (or resized) vector.

 Step 3: Build the square matrix with constructor form.
         vector<vector<int>> a(3, vector<int>(3));
         WHY: this constructs all 9 cells to 0 in one line.

 Step 4: Fill jagged rows one by one with push_back on each inner row.
         WHY: different class sizes need different row lengths.

 Step 5: Print row-major (outer row, inner column).
         WHY: each row prints on its own line — matches our mental model.

 Step 6: Guard empty rows. If jag[r].size()==0 the inner loop just
         doesn't run — but never write v[r][0] blindly.
         WHY: indexing a row vector that has no elements is UB.

 VISUAL WALKTHROUGH:

   Build jagged:  {} then push_back row {1,2,3}, {4,5}, {6,7,8,9}
     outer index  0       1       2
     row0        ┌─┬─┬─┐
                 │1│2│3│
     row1        ┌─┬─┐
                 │4│5│
     row2        ┌─┬─┬─┬─┐
                 │6│7│8│9│
   jag[2][1] == 7   (row 2, column 1)

   Square 3x3 all 7:
     ┌─┬─┬─┐  ┌─┬─┬─┐  ┌─┬─┬─┐
     │7│7│7│  │7│7│7│  │7│7│7│
     └─┴─┴─┘  └─┴─┴─┘  └─┴─┴─┘

 DRY RUN (demo):
   jag rows lengths: 3, 2, 4 (jagged) printed row by row:
     Row 0: 1 2 3
     Row 1: 4 5
     Row 2: 6 7 8 9
   square (3x3, first row ++): 
     Row 0: 1 0 0
     Row 1: 0 1 0
     Row 2: 0 0 1   (identify matrix demo)
   empty row edge: row3 empty → inner loop prints nothing, size 0 shown.

 TIME COMPLEXITY CALCULATION:
 - Build of j rows with total n cells: each cell costs 1 push.
   Total = n operations → O(n). For a square m×m: m² cells → O(m²).
 - Access v[i][j]: outer index O(1) + inner index O(1) = 1 + 1 → O(1).
 - Full print: every cell visited exactly once → number of cells →
   O(total cells) = O(r×c) for a rectangle, O(n) for n total cells.
 → Time Complexity = O(total number of cells)

 SPACE COMPLEXITY CALCULATION:
 - Storage = sum over rows of (row length) cells + outer metadata
   (j pointers). With n total elements stored: n + j extra → O(n).
 - Capacity doubling may double ONE row at a time (2× a single row)
   and doubles the outer vector (2j pointers) → still O(n + j) → O(n).
 → Space Complexity = O(n total cells)

 APPROACH COMPARISON:
 ┌───────────────────┬──────────────────┬──────────────────┬──────────────────┐
 │  Representation   │  Access v[i][j]  │  Rows vary size  │  Build time      │
 ├───────────────────┼──────────────────┼──────────────────┼──────────────────┤
 │ int a[m][n]       │ O(1)             │ no (fixed shape) │ fixed at compile │
 │ vector<int> flattened |             │                  │                  │
 │ (row-major)       │ O(1) with index  │ awkward          │ O(m×n)           │
 │ vector<vector<int>>│ O(1)            │ yes (jagged)     │ O(rows×cols)     │
 │ vector<list<int>> │ O(row walk)      │ yes              │ O(rows)          │
 └───────────────────┴──────────────────┴──────────────────┴──────────────────┘
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ======= DEMO 1: JAGGED array =======
    vector<vector<int>> jag;                       // outer vector
    jag.push_back(vector<int>{1, 2, 3});           // row 0: 3 benches
    jag.push_back(vector<int>{4, 5});              // row 1: 2 benches
    jag.push_back(vector<int>{6, 7, 8, 9});        // row 2: 4 benches

    cout << "=== JAGGED seating chart ===\n";
    for (size_t r = 0; r < jag.size(); ++r) {      // outer loop = row
        cout << "Row " << r << " (len " << jag[r].size() << "): ";
        for (size_t c = 0; c < jag[r].size(); ++c) // inner loop = col
            cout << jag[r][c] << " ";
        cout << "\n";
    }
    cout << "jag[2][1] = " << jag[2][1] << "\n\n"; // row2 index 1 → 7

    // ======= DEMO 2: SQUARE 3x3 matrix (identity) =======
    vector<vector<int>> sq(3, vector<int>(3, 0));  // 3x3 zero matrix
    for (int i = 0; i < 3; ++i) sq[i][i] = 1;      // diagonal = 1

    cout << "=== 3x3 identity matrix ===\n";
    for (size_t r = 0; r < sq.size(); ++r) {
        for (size_t c = 0; c < sq[r].size(); ++c)
            cout << sq[r][c] << " ";
        cout << "\n";
    }
    cout << "sq[1][1] = " << sq[1][1] << "\n\n";

    // ======= EDGE CASE: EMPTY rows inside jagged =======
    vector<vector<int>> withEmpty;
    withEmpty.push_back(vector<int>{10, 20});      // filled row
    withEmpty.push_back(vector<int>());            // EMPTY row
    withEmpty.push_back(vector<int>{30});          // single cell row
    cout << "=== jagged with an EMPTY row ===\n";
    for (size_t r = 0; r < withEmpty.size(); ++r) {
        cout << "Row " << r << " has size " << withEmpty[r].size();
        if (!withEmpty[r].empty()) {               // guard: no blind [0]
            cout << "  first = " << withEmpty[r][0];
        }
        cout << "\n";
    }

    return 0;
}