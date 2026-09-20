/*
═══════════════════════════════════════════════
 MATRIX BASICS — memory layout, declaration, access, traversal, sums
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A school's mark-sheet is a 2D grid: rows are students, columns are subjects.
 Looking at one cell = one student in one subject. Looking at row 3 = all
 subjects of student 3. Looking at column 2 = subject-2 marks of the whole
 class. And the seating chart of a hall (rows × columns of seats) is the same
 idea. In computing: images are grids of pixels, spreadsheets are matrices,
 game boards and graph adjacency matrices are matrices. A matrix is simply a
 grid of values indexed by (row, column).

 📖 THEORY: (pure English)
 - 2D ARRAY / MATRIX: R rows × C columns of elements; element at (i, j),
   where i ∈ [0,R), j ∈ [0,C). Row-major index 0 is the top row.
 - MEMORY: RAM is one-dimensional. A 2D array is flattened; C++ stores
   row-major: element (i,j) of an R×C array sits at offset i*C + j.
   Consecutive j's are adjacent in memory — moving along a row is fast
   (cache-friendly); moving down a column jumps C elements each time.
 - DECLARATION:
     int m[3][4];                       // fixed 3×4 static
     vector<vector<int>> m(R, vector<int>(C));   // dynamic
     int* flat = new int[R*C];          // manual flat storage, m[i*C+j]
 - ACCESS: m[i][j] reads/writes element. In flat form: flat[i*C + j].
 - TRAVERSAL:
     row-wise (outer i, inner j): visits (0,0),(0,1),... row by row —
       sequential in memory → cache-friendly and usually faster.
     column-wise (outer j, inner i): visits (0,0),(1,0),... column by column
       — stride-C jumps → cache-unfriendly but sometimes required (e.g. when
       the algorithm is naturally per-column).
 - ROW-WISE SUM: sum each row → R numbers.
   COLUMN-WISE SUM: sum each column → C numbers.
 - INPUT / OUTPUT: read R,C; read all R*C entries (usually row by row); print
   each row on its own line separated by spaces.
 - EDGE CASES: non-square matrices (R≠C), empty matrix (R=0 or C=0),
   1×1 matrix, single row (R=1), single column (C=1).

  ASCII — a 3×4 matrix and its row-major memory:
        col0 col1 col2 col3
   row0 [ 1    2    3    4 ]      memory: 1 2 3 4 | 5 6 7 8 | 9 10 11 12
   row1 [ 5    6    7    8 ]              └─ row 0 ─┘└─ row 1 ─┘ ...
   row2 [ 9   10   11   12 ]
   element (1,2) = 7 ; flat index = 1*4 + 2 = 6 → memory[6] = 7 ✓

  ASCII — traversal paths:
   row-wise:   →→→        column-wise:  ↓↓
              →→→                       ↓↓
              →→→                       ↓↓
   (row-wise hits memory sequentially; column-wise strides by C)

 🧠 LOGIC — STEP BY STEP:
 Step 1: Store the matrix in a flat buffer of R*C, indexed by i*C+j.
        WHY: multidimensional arrays don't exist in flat RAM; row-major
        flattening makes access O(1) arithmetic and row scans sequential.
 Step 2: Declare dimensions if known at compile time; otherwise use a
        dynamic vector-of-vectors or a flat allocation.
        WHY: fixed arrays are fast/stack-based; dynamic storage handles
        arbitrary R,C read at runtime.
 Step 3: For access use m[i][j] (or flat[i*C+j]); guard 0≤i<R, 0≤j<C.
        WHY: an out-of-range index writes into a neighbouring row/cell
        silently (no bounds check) — the guard prevents memory corruption.
 Step 4: Choose traversal order based on which dimension is the inner loop,
        and prefer row-wise when the task allows it.
        WHY: row-wise reads are contiguous → better cache usage → fewer
        memory stalls; column-wise jumps C elements → more cache misses.
 Step 5: Row/column sums: accumulate per row with i fixed, or per column
        with j fixed.
        WHY: each cell is visited exactly once, giving a single linear pass
        over R*C cells.

 VISUAL WALKTHROUGH: sum row-wise vs column-wise on 2×3
   M = [[1,2,3],
        [4,5,6]]
   row sums:    1+2+3=6 ; 4+5+6=15
   column sums: 1+4=5 ; 2+5=7 ; 3+6=9
   row-wise traversal order: (0,0)(0,1)(0,2)(1,0)(1,1)(1,2)
   column-wise order:        (0,0)(1,0)(0,1)(1,1)(0,2)(1,2)

 DRY RUN: (demo below, exact prints)
   matrix:
     1 2 3
     4 5 6
   access m[1][2] = 6
   flat index for (1,2) = 1*3+2 = 5 → flat[5] = 6
   row-wise print: 1 2 3 then 4 5 6
   column-wise print: 1 4 then 2 5 then 3 6
   row sums: 6 15 ; column sums: 5 7 9
 TIME COMPLEXITY CALCULATION:
 - Access (i,j): compute i*C+j then read → constant arithmetic → O(1).
 - Row-wise traversal: visits R*C cells once → O(R·C).
 - Column-wise traversal: visits R*C cells once → O(R·C) (same count, worse
   constant due to cache misses).
 - Row sums: R*C additions → O(R·C).
 - Column sums: R*C additions → O(R·C).
 - Input/output: R*C reads/writes → O(R·C).
 → Anything that touches every cell is O(R·C); we often write O(n²) for an
   n×n square and O(R·C) in general.

 SPACE COMPLEXITY CALCULATION:
 - Storing the matrix itself: R*C cells → O(R·C).
 - Row sums extra buffer: R → O(R); column sums buffer: C → O(C).
 - Traversal uses O(1) auxiliary (just loop indices).
 → Total space O(R·C) for the data, O(1)–O(max(R,C)) auxiliary depending on
   whether we materialise the sums.

 APPROACH COMPARISON:
 ┌────────────────────┬───────────────────┬───────────────────────────────┐
 │ Aspect             │ Row-wise          │ Column-wise                   │
 ├────────────────────┼───────────────────┼───────────────────────────────┤
 │ Memory stride      │ 1 (contiguous)    │ C (jump)                      │
 │ Cache behaviour    │ friendly          │ unfriendly                    │
 │ Natural for        │ row sums, printing│ column sums, transpose        │
 │ Big-O              │ O(R·C)            │ O(R·C) (higher constant)      │
 └────────────────────┴───────────────────┴───────────────────────────────┘
 */
#include <iostream>
using namespace std;

int main() {
    const int R = 2, C = 3;
    int m[R][C] = {{1, 2, 3}, {4, 5, 6}};
    int flat[R * C];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            flat[i * C + j] = m[i][j];          // row-major flatten

    cout << "===== matrix =====" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cout << m[i][j] << " ";
        cout << endl;
    }

    cout << "===== access =====" << endl;
    cout << "m[1][2] = " << m[1][2] << endl;                       // 6
    cout << "flat[1*3+2] = flat[5] = " << flat[1 * C + 2] << endl; // 6

    cout << "===== row-wise print =====" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cout << m[i][j] << " ";
        cout << endl;
    }

    cout << "===== column-wise print =====" << endl;
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++) cout << m[i][j] << " ";
        cout << endl;
    }

    cout << "===== row sums =====" << endl;
    for (int i = 0; i < R; i++) {
        int sum = 0;
        for (int j = 0; j < C; j++) sum += m[i][j];
        cout << sum << " ";
    }
    cout << endl;                                                  // 6 15

    cout << "===== column sums =====" << endl;
    for (int j = 0; j < C; j++) {
        int sum = 0;
        for (int i = 0; i < R; i++) sum += m[i][j];
        cout << sum << " ";
    }
    cout << endl;                                                  // 5 7 9
    return 0;
}
