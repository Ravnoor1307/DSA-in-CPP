/*
═══════════════════════════════════════════════
 ROW-MAJOR vs COLUMN-MAJOR ORDER
 (Address Calculation Formulas + Derivation)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A warehouse has 10 cupboards, each with 15 shelves. The manager asks for
 a particular item's location: "3rd cupboard, 9th shelf". RAM is a similar
 warehouse — its memory is ONE LONG line (addresses 1000, 1004, 1008, ...).
 The items of a 2D array must be placed into this line in SOME order. If we
 put each cupboard's whole content in a row first and then move to the next
 cupboard (cupboard 0 fully, then cupboard 1 fully) — that is ROW-MAJOR. If
 we take every cupboard's same shelf together (cupboard0-shelf0,
 cupboard1-shelf0, ...) — that is COLUMN-MAJOR. The two orders give
 different addresses, and the compiler/language decides which one to use.

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: ROW-MAJOR and COLUMN-MAJOR are the two ways to "flatten" a
   2D array into RAM's single linear address line.
 - key points / properties:
   • RAM is linear: memory is one continuous address line.
   • A 2D array A[R][C] must be flattened into this line — this is the
     "ordering".
   • ROW-MAJOR    (used by C, C++, Java): first all C elements of ROW0,
                  then all of ROW1, and so on.
   • COLUMN-MAJOR (used by Fortran, MATLAB, R): first all R elements of
                  COL0, then all of COL1, and so on.
   • size = sizeof(element), B = base address (first byte of the array).
   • FORMULAS (0-based indexing — C/C++ style):
       Row-major    : Addr(A[i][j]) = B + (i*C + j) * size
       Column-major : Addr(A[i][j]) = B + (j*R + i) * size
   • FORMULAS (1-based indexing — exam/book style, GATE/BCA pattern):
       Row-major    : Addr(A[i][j]) = B + ((i-1)*C + (j-1)) * size   // rows 1..R
       Column-major : Addr(A[i][j]) = B + ((j-1)*R + (i-1)) * size   // cols 1..C

   VISUAL — A[2][3] flat in memory:

   ROW-MAJOR:      │ (0,0) │ (0,1) │ (0,2) │ (1,0) │ (1,1) │ (1,2) │
                   │   a   │   b   │   c   │   d   │   e   │   f   │

   COLUMN-MAJOR:   │ (0,0) │ (1,0) │ (0,1) │ (1,1) │ (0,2) │ (1,2) │
                   │   a   │   d   │   b   │   e   │   c   │   f   │

 - when to use:
   The question states "row-major" vs "column-major" explicitly. C/C++
   compilers use row-major — memorize BOTH formulas for interviews.

 🧠 LOGIC — STEP BY STEP (Formula DERIVATION): (pure English)
 Step 1: The first element A[0][0] sits at the base address B.
         WHY: B is the fixed starting point of the whole array.
 Step 2: ROW-MAJOR — to reach A[i][j] you must walk past the first "i"
         ROWS completely. Each row has C elements, so i rows mean i*C
         elements must be skipped.
         WHY: Every row holds exactly C items, and rows are contiguous
         in row-major order.
 Step 3: After those i rows, within the target row you count j more
         elements. Total skipped = i*C + j → offset = (i*C + j) * size.
         WHY: each element occupies 'size' bytes — elements × size = bytes.
 Step 4: So Addr(A[i][j]) = B + (i*C + j) * size   (row-major).
         WHY: base + offset is exactly what an address means.
 Step 5: COLUMN-MAJOR — you must first walk past "j" COLUMNS completely,
         each holding R elements. Skipped = j*R, then i more elements up
         the same column. Addr(A[i][j]) = B + (j*R + i) * size.
         WHY: in column-major, columns are contiguous — you count columns
         and then climb within one.
 Step 6: For 1-based indexing, subtract 1 from every index (i→i-1, j→j-1).
         WHY: books/exams start indexes from 1, so each one must drop to
         the 0-based offset math.

 VISUAL WALKTHROUGH (with addresses):
   A[3][4], int (size=4), base B=1000.
   Row-major — in the line: full row0, then full row1:

      Addr:  1000  1004  1008  1012 | 1016  1020  1024  1028 | 1032 ...
             ───── row0 ───────────  ───── row1 ────────────
             (0,0) (0,1) (0,2) (0,3)  (1,0) (1,1) (1,2) (1,3)
             A[1][2] = 1000 + (1*4 + 2)*4 = 1000 + 24 = 1024

   Column-major:
      Addr:  1000  1004  1008 | 1012  1016  1020 | 1024 ...
             ─── col0 ───────  ─── col1 ───────
             (0,0) (1,0) (2,0) (0,1) (1,1) (2,1)
             A[1][2] = 1000 + (2*3 + 1)*4 = 1000 + 28 = 1028

 DRY RUN (line-by-line on the demo):
   Example: A[10][15], int size=4, base=1000, target A[3][8].

   ROW-MAJOR:    offset = (3*15 + 8) * 4 = (45+8)*4 = 53*4 = 212
                 Addr   = 1000 + 212 = 1212

   COLUMN-MAJOR: offset = (8*10 + 3) * 4 = (80+3)*4 = 83*4 = 332
                 Addr   = 1000 + 332 = 1332

   Difference = 1332 - 1212 = 120 bytes — the two orders give DIFFERENT
   addresses!

   EDGE CASES:
     A[0][0]     → row: 1000 + 0 = 1000 ; col: 1000 + 0 = 1000  (both same = base)
     A[9][14]    → row: 1000 + (9*15+14)*4 = 1000+596=1596
                   col: 1000 + (14*10+9)*4 = 1000+596=1596     (both same = LAST cell!)
     A[3][15]    → invalid (col 15 does not exist, cols are 0..14)

 TIME COMPLEXITY CALCULATION:
   - 1 multiplication (i*C) + 1 addition (+j) + 1 multiply (*size) : 3 fixed steps
     f(n) = 3
   - column-major also takes exactly the same 3 fixed steps.
   → Time Complexity = O(1) — independent of array size; just constant
   arithmetic.

 SPACE COMPLEXITY CALCULATION:
   - The formula stores no array/table — only base, R, C, i, j, size
     variables. f(n) = 1
   → Space Complexity = O(1) — no extra memory at all.

 APPROACH COMPARISON:
 ┌───────────────────────┬────────────────────────────┬────────────────────────────┐
 │ Point                 │  ROW-MAJOR                 │  COLUMN-MAJOR              │
 ├───────────────────────┼────────────────────────────┼────────────────────────────┤
 │ Formula (0-based)     │ B + (i*C + j)*size          │ B + (j*R + i)*size          │
 │ Adjacent cells        │ horizontal — 1 element jump│ vertical — R elements jump  │
 │ Cache-friendly for    │ row access (C/C++ default) │ column access (Fortran/Matlab)│
 │ Matrix multiply       │ row access inside main loop│ transpose-based patterns    │
 │ Languages             │ C, C++, Java, Python(numpy)│ Fortran, MATLAB, R          │
 │ Visual                │ cupboard-by-cupboard        │ shelf-by-shelf              │
 └───────────────────────┴────────────────────────────┴────────────────────────────┘
 */
#include <iostream>
using namespace std;

// Calculator — dono order ki address nikal kar bata deta hai
void calcAddress(long long base, int R, int C, int i, int j, int size) {
    if (i < 0 || i >= R || j < 0 || j >= C) {          // edge case: out of bounds
        cout << "   ERROR: A[" << i << "][" << j << "] array ke bahar hai (R="
             << R << ", C=" << C << ")\n";
        return;
    }
    long long rm = base + ((long long)i * C + j) * size;   // row-major
    long long cm = base + ((long long)j * R + i) * size;   // column-major
    cout << "   A[" << i << "][" << j << "]\n";
    cout << "     Row-major    (B + (i*C + j)*size)     = " << rm << "\n";
    cout << "     Column-major (B + (j*R + i)*size)     = " << cm << "\n";
    cout << "     Difference                             = "
         << (rm > cm ? rm - cm : cm - rm) << " bytes\n";
}

int main() {
    cout << "MAIN EXAMPLE: A[10][15] int (size=4), base=1000, find A[3][8]\n";
    calcAddress(1000, 10, 15, 3, 8, 4);

    cout << "\nEDGE CASES (A[10][15]):\n";
    cout << " 1) First cell A[0][0]:\n";
    calcAddress(1000, 10, 15, 0, 0, 4);
    cout << " 2) Last cell A[9][14] (dono formula base+last offset de):\n";
    calcAddress(1000, 10, 15, 9, 14, 4);

    cout << "\nINTERACTIVE CALCULATOR MODE:\n";
    cout << "   Enter: base R C i j size  (e.g. 1000 10 15 3 8 4)\n   -> ";
    long long base;
    int R, C, i, j, size;
    cin >> base >> R >> C >> i >> j >> size;
    calcAddress(base, R, C, i, j, size);

    cout << "\n1-BASED INDEXING (book pattern), A[1..10][1..15], base=1000, A[3][8]:\n";
    long long rm1 = 1000 + ((long long)(3 - 1) * 15 + (8 - 1)) * 4;
    long long cm1 = 1000 + ((long long)(8 - 1) * 10 + (3 - 1)) * 4;
    cout << "   Row-major     = " << rm1 << "\n";
    cout << "   Column-major  = " << cm1 << "\n";
    return 0;
}