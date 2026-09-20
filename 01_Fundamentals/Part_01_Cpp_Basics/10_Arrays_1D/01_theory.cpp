/*
═══════════════════════════════════════════════
 1-D ARRAYS (Declaration, Traversal, Search, Reverse)
 ⏱️ TIME COMPLEXITY: traverse/sum/max/min/reverse = O(n); index access = O(1) — derivations below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A teacher stores all 40 students' marks as one flat list — mark #1, #2, ... #40 —
 and walks down the list to compute the total and the topper's score. On a train,
 a coach has seats numbered 0..59, all in one long row: seat 25 is exactly 25
 positions from the front, found instantly. That flat list IS a 1-D array: one
 rectangular memory block, zero-based numbering, and instant "give me the k-th
 item" access.

 📖 THEORY: (pure English, beginner-level)
 - An ARRAY is a fixed-size collection of elements of the SAME type stored in ONE
   CONTIGUOUS block of memory.
 - DECLARATION:  type name[size];         e.g.  int marks[5];
   WITH INITIALIZATION:  int arr[5] = {10, 20, 30, 40, 50};
 - INDEXING STARTS AT 0: int arr[5] has valid indices 0..4. arr[n] does NOT exist.
 - CONTIGUOUS MEMORY: if the block starts at address A and sizeof(int) = 4, then
   element i lives at address A + i*4. That is why arr[i] is a single O(1) jump.
 - TRAVERSAL: visit every element once — for (int i = 0; i < n; i++) use arr[i].
 - SUM: accumulate total += arr[i] while traversing.
 - MAX/MIN: seed the answer with arr[0], then compare the remaining elements.
 - LINEAR SEARCH: walk 0 → n-1, comparing each element to the target; return the
   first matching index (or -1 if not found).
 - REVERSE: swap ends moving inward — arr[0]↔arr[n-1], arr[1]↔arr[n-2], ... stopping
   when i reaches n/2 (swapping past the middle would undo the reversal).
 - OUT-OF-BOUNDS: reading/writing arr[n] or arr[-1] is UNDEFINED BEHAVIOUR — C++
   performs no automatic bounds checking.

  ASCII — contiguous memory + zero-based indexing (int arr[5], sizeof(int)=4):
   address:   A      A+4     A+8     A+12    A+16
            ┌──────┬──────┬──────┬──────┬──────┐
   value:   │  10  │  20  │  30  │  40  │  50  │
            └──────┴──────┴──────┴──────┴──────┘
   index:      0      1      2      3      4
   formula:  arr[i] = *(A + i * 4)

  ASCII — reverse in-place (n = 5):
   before:  [10] [20] [30] [40] [50]
   swap 0↔4: [50] [20] [30] [40] [10]
   swap 1↔3: [50] [40] [30] [20] [10]
   middle index 2 stays — only i < n/2 iterations

 🧠 LOGIC — STEP BY STEP:
 Step 1: Pick the size up front and declare the array.
        WHY: arrays are static — the size is fixed at compile time.
 Step 2: Traverse with a 0-based loop: for (int i = 0; i < n; i++).
        WHY: valid indices run 0..n-1; this guards the classic off-by-one bug.
 Step 3: For max/min, seed the result with arr[0], then scan from index 1.
        WHY: seeding with the first element works correctly for every n ≥ 1.
 Step 4: For reverse, swap arr[i] with arr[n-1-i] while i < n/2.
        WHY: stopping halfway prevents re-swapping everything back to the original.

 VISUAL WALKTHROUGH: (sum + max, arr = {4, 9, 1, 7, 2})
  i=0: total = 0 + 4 = 4,  max = 4
  i=1: total = 4 + 9 = 13, max = 9
  i=2: total = 13 + 1 = 14, max = 9
  i=3: total = 14 + 7 = 21, max = 9
  i=4: total = 21 + 2 = 23, max = 9
  result: sum = 23, max = 9

 DRY RUN: (reverse, arr = {1, 2, 3, 4})
  n = 4, so i goes while i < 2
  i=0: swap arr[0]↔arr[3] → {4, 2, 3, 1}
  i=1: swap arr[1]↔arr[2] → {4, 3, 2, 1}
  done — array reversed ✓

 TIME COMPLEXITY CALCULATION:
 - Indexing arr[i]: one address computation (A + i*4) + one memory load — constant.
 - Traversing / summing / max / min: each visits all n elements exactly once —
   n additions or n comparisons → n steps.
 - Linear search: worst case the target is at the last position (or absent):
   n comparisons → n steps.
 - Reverse: n/2 swaps, each swap is 3 assignments → ~1.5n operations → order n.
 → Time Complexity = O(1) for indexing; O(n) for traversal/sum/max/min/
   linear-search/worst-case/reverse

 SPACE COMPLEXITY CALCULATION:
 - The array itself needs n × sizeof(element) bytes — that is required storage.
 - All algorithms add only a handful of counters (i, total, maxVal, temp) whose
   count does not grow with n.
 → Space Complexity = O(1) EXTRA (beyond the array's own O(n) storage)

 APPROACH COMPARISON:
 ┌────────────────┬──────────────────────────┬─────────────────────────────┐
 │ Aspect         │ Raw array (int arr[n])   │ std::vector<int>            │
 ├────────────────┼──────────────────────────┼─────────────────────────────┤
 │ Size           │ fixed at compile time    │ can grow at runtime         │
 │ Storage        │ stack or static segment  │ heap                        │
 │ Bounds check   │ none — UB when exceeded  │ .at(i) throws; [] unchecked │
 │ Speed          │ fastest, lowest level    │ nearly as fast              │
 │ Best for       │ fixed-size fast data     │ dynamic-size collections    │
 └────────────────┴──────────────────────────┴─────────────────────────────┘
*/
#include <iostream>
using namespace std;

// print helper — sirf display ke liye
void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

// traversal + sum — har element ko ek baar touch
int arraySum(int arr[], int n) {
    int total = 0;                        // zero se start
    for (int i = 0; i < n; i++) {
        total += arr[i];                  // har element jodte jao
    }
    return total;
}

// max — arr[0] seed, aage compare karte jao
int arrayMax(int arr[], int n) {
    int maxVal = arr[0];                  // pehla element seed
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];   // bada mila to update
    }
    return maxVal;
}

// linear search — pehla matching index return, nahi mila to -1
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;   // milte hi index wapas
    }
    return -1;                            // nahi mila (konvention: -1)
}

// reverse in-place — aage-piche se swap, beech tak
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    int marks[6] = {10, 20, 30, 40, 50, 60};

    cout << "=== Traverse ===" << endl;
    cout << "marks = ";
    printArray(marks, 6);
    cout << endl;

    cout << "\n=== Sum & Max ===" << endl;
    cout << "sum = " << arraySum(marks, 6) << endl;
    cout << "max = " << arrayMax(marks, 6) << endl;

    cout << "\n=== Linear Search ===" << endl;
    cout << "index of 40  = " << linearSearch(marks, 6, 40) << endl;
    cout << "index of 100 = " << linearSearch(marks, 6, 100)
         << "  (not found -> -1)" << endl;

    cout << "\n=== Reverse (in-place) ===" << endl;
    reverseArray(marks, 6);
    cout << "after reverse -> ";
    printArray(marks, 6);
    cout << endl;
    reverseArray(marks, 6);               // wapas original kar diya

    cout << "\n=== EDGE CASES ===" << endl;
    int single[1] = {7};
    cout << "single-element {7}: sum = " << arraySum(single, 1)
         << ", max = " << arrayMax(single, 1) << endl;
    reverseArray(single, 1);
    cout << "reverse single -> ";
    printArray(single, 1);
    cout << "  (n/2 = 0 swaps — jaroori bhi nahi tha)" << endl;

    int empty[1];                          // n=0 concept: loop 0 baar chalega
    cout << "sum over n=0 = " << arraySum(empty, 0)
         << "  (loop kabhi chala hi nahi)" << endl;
    cout << "linearSearch empty array = " << linearSearch(empty, 0, 5)
         << "  (ek bhi compare nahi, -1)" << endl;
    return 0;
}