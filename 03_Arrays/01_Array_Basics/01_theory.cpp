/*
═══════════════════════════════════════════════
 ARRAY BASICS — Memory Layout, Indexing & Traversal
 ⏱️ TIME COMPLEXITY: derived step-by-step at the bottom. NEVER a bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a cinema hall. The front row has 8 seats numbered 0 to 7 from left to right.
 If the manager says "give the ticket to seat number 4", he walks DIRECTLY to that
 seat — he never checks seats 0, 1, 2, 3 first. A train coach is identical: berths
 are numbered 1..20 in one fixed strip, and you jump straight to berth 12. An array
 is exactly this — a fixed line of memory cells placed one after another, each with
 one value in it, and each so cheap to reach that we can jump to any cell instantly.

 📖 THEORY: (pure English, beginner-level)
 - DEFINITION: An array is a collection of elements of the SAME data type stored in
   CONTIGUOUS (neighbouring) memory locations. In C++, `int arr[5]` creates 5 integer
   cells laid side by side.
 - Every cell has an INDEX (0-based name: arr[0], arr[1] ... arr[n-1]) and an ADDRESS
   (the real memory location, printed as hex, e.g. 0x61fef0).
 - Each int occupies 4 bytes, so two neighbouring ints sit exactly 4 bytes apart:
   arr[1] is at base+4, arr[2] at base+8, and so on.
 - ADDRESS FORMULA:  address(arr[i]) = base_address + i * size_of_one_element.
   Because it is pure arithmetic (one multiply + one add), ACCESS IS O(1) — the
   superpower of arrays: we can reach ANY element instantly without scanning.

            INDEX    [0]      [1]      [2]      [3]      [4]
           ADDRESS  base     base+4   base+8   base+12  base+16
                    ┌────────┬────────┬────────┬────────┬────────┐
           VALUE    │   10   │   20   │   30   │   40   │   50   │
                    └────────┴────────┴────────┴────────┴────────┘
                  har box 4 bytes ka int; agla box hamesha +4 bytes door

 - 2D ARRAYS: int mat[2][3] is stored ROW-MAJOR — row 0 is laid down entirely
   (mat[0][0], mat[0][1], mat[0][2]), then row 1. So the flat/linear index of
   mat[r][c] inside the one big memory strip is:  LINEAR = r * cols + c.
   For a 2x3 matrix: mat[1][2] → 1*3 + 2 = 5 (the 6th cell).
 - WHEN TO USE: when size is fixed and you need the fastest possible random access —
   lookup tables, buffers, DP arrays, hash-table buckets.
 - WHEN NOT: frequent inserts/deletes in the middle call shifting (O(n) — studied in
   the next folder), or if elements have different data types (use struct/class).

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: DECLARE the array — the compiler reserves one continuous block of n*4 bytes
         and records the starting (base) address.
         WHY: contiguous memory is what makes the direct address formula possible.
 Step 2: ACCESS arr[i] — the compiler translates it to base + i*4 in one step.
         WHY: multiply + add, no loop, no search → O(1).
 Step 3: TRAVERSE — run i from 0 to n-1, visiting each element exactly once.
         WHY: we MUST touch all n cells, so this is unavoidably O(n).
 Step 4: UPDATE — write a new value at the computed address; same O(1) jump as access.
         WHY: a write is just access followed by an assignment.
 Step 5: 2D flat index — mat[r][c] maps to r*cols + c in the strip.
         WHY: row r begins at strip offset r*cols; column c adds c steps to the right.

 VISUAL WALKTHROUGH: (ASCII state diagram)
  Step A: array created with {10, 20, 30}
         addr:  base+0    base+4    base+8
                ┌────────┬────────┬────────┐
                │  10    │  20    │  30    │
                └────────┴────────┴────────┘
  Step B: update arr[1] = 99 → jump directly to base+4, overwrite
                ┌────────┬────────┬────────┐
                │  10    │  99    │  30    │
                └────────┴────────┴────────┘
  Step C: 2D mat[2][3] spread into one flat strip (row-major):
          ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
          │ mat[0][0]│ mat[0][1]│ mat[0][2]│ mat[1][0]│ mat[1][1]│ mat[1][2]│
          ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
          │   flat 0 │   flat 1 │   flat 2 │   flat 3 │   flat 4 │   flat 5 │
          └──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
          mat[1][2] → 1*3 + 2 = 5 ✔

 DRY RUN: arr = {10, 20, 30}, base address = 1000
   - arr[0] → 1000 + 0*4 = 1000 → value 10
   - arr[1] → 1000 + 1*4 = 1004 → value 20
   - arr[2] → 1000 + 2*4 = 1008 → value 30
   - Sum loop: sum=0; i=0→sum=10; i=1→sum=30; i=2→sum=60 → 3 iterations = O(n)
   - Update arr[1]=99 → one write at 1004 → O(1)
   - 2D check: mat[1][2] with cols=3 → 1*3 + 2 = 5 ✔

 TIME COMPLEXITY CALCULATION:
 - Access arr[i]: compute base + i*4 (one multiply + one add), constant work ⇒ O(1)
 - Update arr[i]: same address computation + one assignment ⇒ O(1)
 - Traversal (sum / print / find): one visit for each of the n elements ⇒ O(n)
 - 2D access mat[r][c]: single expression r*cols + c ⇒ O(1)
 → Time Complexity = Access O(1), Update O(1), Traversal O(n), 2D access O(1).

 SPACE COMPLEXITY CALCULATION:
 - The array itself stores n elements ⇒ O(n)
 - A few loop counters and the sum variable are constant ⇒ O(1) auxiliary
 → Space Complexity = O(n) for the array + O(1) extra work space.

 APPROACH COMPARISON: C-style array vs std::vector
 ┌─────────────────────┬────────────────────────────┬───────────────────────────┐
 │ Feature             │ int arr[n]                 │ std::vector<int>          │
 ├─────────────────────┼────────────────────────────┼───────────────────────────┤
 │ Random access       │ O(1) direct formula        │ O(1) via operator[]       │
 │ Size known at       │ compile time               │ runtime (grows/shrinks)   │
 │ Insert at end       │ manual, needs free slot    │ push_back (amortized O(1))│
 │ Range checking      │ none — programmer's job    │ .at() can throw           │
 │ Memory location     │ stack (or static)          │ heap by default           │
 └─────────────────────┴────────────────────────────┴───────────────────────────┘
*/

#include <iostream>
using namespace std;

int main() {
    // ---------- PART 1: memory layout — addresses 4 bytes apart ----------
    int arr[5] = {10, 20, 30, 40, 50};   // 5 ints = 5*4 = 20 bytes ka continuous block

    cout << "=== MEMORY LAYOUT (har int 4 bytes, addresses +4 diff) ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] value=" << arr[i]
             << "  address=" << &arr[i] << "\n";
        // har agla address pichhle wale se exactly +4 bytes aage milega
    }
    cout << "base address of array = " << arr << "\n\n";

    // ---------- PART 2: traversal + sum ----------
    cout << "=== TRAVERSAL (ek full loop) ===\n";
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
        sum += arr[i];                  // sab elements ek-ek karke visit ho rahe hain
    }
    cout << "\nSum = " << sum << "\n\n";

    // ---------- PART 3: update (O(1) direct jump) ----------
    cout << "=== UPDATE ===\n";
    cout << "before update arr[1] = " << arr[1] << "\n";
    arr[1] = 99;                        // seedha index 1 par jaa kar overwrite kiya
    cout << "after  update arr[1] = " << arr[1] << "\n\n";

    // ---------- PART 4: 2D matrix + flat linear indices (row-major) ----------
    const int R = 2, C = 3;
    int mat[R][C] = {{1, 2, 3}, {4, 5, 6}};

    cout << "=== 2D MATRIX: har cell + uska flat linear index (r*cols+c) ===\n";
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int flat = r * C + c;       // ROW-MAJOR flat index formula
            cout << "mat[" << r << "][" << c << "] = " << mat[r][c]
                 << "  flat = " << flat << "\n";
        }
    }
    cout << "\n";

    // ---------- PART 5: edge cases ----------
    cout << "=== EDGE CASES ===\n";

    // 1) empty array: size 0 → loop 0 iterations, bilkul safe
    int nEmpty = 0;
    if (nEmpty == 0) {
        cout << "Empty (size 0): traversal loop runs 0 times — no crash, no output.\n";
    }

    // 2) single element: n=1, sirf arr[0] valid
    int singleArr[1] = {42};
    cout << "Single element: singleArr[0] = " << singleArr[0]
         << "  address = " << &singleArr[0] << "\n";

    // 3) negative index guard — C arrays kabhi automatically check nahi karte
    int idx = -3;
    if (idx < 0 || idx >= 5) {
        cout << "Index " << idx << " REJECTED (negative/out of range) — guard ne bacha liya.\n";
    } else {
        cout << "value at index " << idx << " = " << arr[idx] << "\n";
    }

    return 0;
}