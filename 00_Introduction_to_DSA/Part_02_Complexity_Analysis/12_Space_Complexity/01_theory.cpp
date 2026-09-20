/*
═══════════════════════════════════════════════
 SPACE COMPLEXITY
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine sorting LEGO bricks into colour families. If you sort IN PLACE
 using just two hands and a small "swap" patch, you barely need extra
 table space (O(1) auxiliary). If instead you lay out a new row for
 every brick (a copy array), each new brick adds one more slot — table
 space grows linearly (O(n)). If you then build a colour×size comparison
 matrix for every pair of bricks, space explodes as the square of the
 count (O(n²)). Your table's area is that algorithm's space complexity.

 📖 THEORY: (pure English, formal)

 Space complexity = total memory an algorithm uses as a function of n.
   TOTAL SPACE = INPUT SPACE + AUXILIARY SPACE
   - Input space: storage for the input itself (usually O(n), often
     excluded from the "auxiliary" figure, since it's given).
   - Auxiliary space: EXTRA memory the algorithm allocates on top of
     the input — temp arrays, recursion stacks, memo tables, hash maps.

 SPACE CLASSES (auxiliary):
  ┌─────────┬──────────────────────────────────────────────┬───────────────┐
  │  Class  │ What it means                                │ Example       │
  ├─────────┼──────────────────────────────────────────────┼───────────────┤
  │ O(1)    │ few fixed variables; size doesn't depend on n│ sum of array  │
  │ O(log n)│ recursion stack of depth log n               │ recursive BS  │
  │ O(n)    │ one array/table of length n                  │ array copy    │
  │ O(n²)   │ a matrix of n×n                               │ adj matrix    │
  └─────────┴──────────────────────────────────────────────┴───────────────┘

 COMMON SPACE SOURCES:
  - Fixed local variables → O(1) each call.
  - One dynamic array of size n → O(n).
  - Recursion depth d with frame size f → O(d·f).
  - 2D matrix n×n → O(n²).
  - Also count: std::vector storage, strings, function-call return values.

 ASCII MEMORY ACCOUNT (n = 5, int array):

  O(1) auxiliary — SUM:
   ┌─────────────────────────────────────┐
   │ input[5] = {10,20,30,40,50}  (given)│
   │ extra:  sum(int64) + i(int)         │ ← fixed 12 bytes, size se free
   └─────────────────────────────────────┘
   Aux = O(1) ✓

  O(n) auxiliary — COPY:
   copy[] = {10,20,30,40,50}             │ ← 5×4 = 20 bytes, grows with n
   Aux = O(n) ✓

  O(n²) auxiliary — MATRIX:
     ┌───────┬──────────┐
     │ 4×4   │           │   n=4 matrix: 4 rows × 4 ints = 64 bytes
     └───────┴──────────┘   Aux = 4n² bytes → O(n²) ✓

 WHEN TO USE:
 - Always report SPACE together with TIME: "O(n) time, O(1) space".
 - Prefer in-place (O(1) aux) when input is huge or memory is tight.
 - Accept O(n) aux when it buys time (memoisation, merge sort).
 - NEVER design O(n²) aux without a serious reason.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Separate INPUT space from AUXILIARY space in your head.
   WHY: Interviewers usually mean auxiliary space when they ask
        "space complexity?" — say which one you're giving.

 Step 2: List every allocation: scalars, arrays, stacks, strings.
   WHY: Space is the SUM of all allocations, not the biggest one
        (though the biggest dominates asymptotically).

 Step 3: Convert each allocation to a function of n.
   WHY: C array of n ints → 4n bytes; 2D n×n → 4n² bytes;
        recursion depth n → n frames.

 Step 4: Drop constants & lower terms → the O() class.
   WHY: 4n + 12 bytes simplifies to O(n).

 Step 5: Empirically verify with sizeof() and printed byte counts.
   WHY: The demo prints exact bytes to prove the class.

 VISUAL WALKTHROUGH:

  (A) sumO1(arr, n):
      arr[]: 10 20 30 40 50          (input, given)
      aux:   sum=150 (8B)   i=5 (4B) → 12B total, ANY n
      bytes(n) = 12 → O(1)

  (B) copyOn(arr, n):
      arr[]: 10 20 30 40 50          (input, given)
      aux:   copy[] = 10 20 30 40 50 (5×4=20B) + i (4B) → 24B @ n=5
      bytes(n) = 4n + 4 → O(n)

  (C) matrixOn2(n):
      aux:   n row-pointers + n rows × n ints
      bytes(n) = 8n + 4n² (64-bit machine) → O(n²)

 DRY RUN (n = 5):
  step 1  sum=0 , i from 0..4
  step 2  sum += arr[0]=10 → 10
  step 3  sum += arr[1]=20 → 30
  step 4  sum += arr[2]=30 → 60
  step 5  sum += arr[3]=40 → 100
  step 6  sum += arr[4]=50 → 150
  Memory: sum(8) + i(4) = 12 bytes (n=5 ya n=500000, same) → O(1)
  copy:   copy[0..4] = arr[0..4] → 20 bytes + i(4) = 24 bytes → O(n)

 TIME COMPLEXITY CALCULATION:
  sumO1: loop iterates n times, O(1) work per iteration.
   T(n) = n · O(1) = O(n)   →  Time = O(n)
  copyOn: loop n times, one copy each.
   T(n) = n · O(1) = O(n)   →  Time = O(n)
  matrixOn2: allocating n×n cells = O(n²) cell writes.
   T(n) = n² · O(1) = O(n²) →  Time = O(n²)

 SPACE COMPLEXITY CALCULATION (byte-by-byte):
  sumO1   aux bytes = sizeof(long long) for sum (8) + sizeof(int) for i (4)
                     = 12 bytes, INDEPENDENT of n
   → Space = O(1)
  copyOn  aux bytes = n · sizeof(int)      (copy array)
                    + sizeof(int) for i  (4)
                    = 4n + 4 bytes
   → Space = 4n + 4 = O(n)
  matrixOn2 aux bytes = n · sizeof(int*)            (row pointers: 8n on 64-bit)
                      + n · n · sizeof(int)         (cells: 4n²)
                      = 4n² + 8n
   → Space = 4n² + 8n = O(n²)

 APPROACH COMPARISON:
  ┌───────────────────┬─────────────────────┬────────────────────┬───────────────────────┐
  │ Aspect            │ sumO1 (O(1) space)  │ copyOn (O(n) space)│ matrixOn2 (O(n²) space)│
  ├───────────────────┼─────────────────────┼────────────────────┼───────────────────────┤
  │ Auxiliary memory  │ 12 B fixed          │ 4n + 4 B           │ 4n² + 8n B             │
  │ n=1000 total      │ 12 B                │ ~4 KB               │ ~4 MB                  │
  │ Time              │ O(n)                │ O(n)                │ O(n²)                  │
  │ Allocates?        │ no                  │ yes (n ints)        │ yes (n×n)              │
  │ Best when         │ memory-tight        │ need a copy anyway  │ need a matrix          │
  └───────────────────┴─────────────────────┴────────────────────┴───────────────────────┘
*/

#include <iostream>
#include <cstdio>
using namespace std;

// ============ THREE SPACE-PATTERN DEMOS ============

// sumO1 — SIRF 1 accumulator + 1 loop index → fixed bytes, O(1) auxiliary
long long sumO1(const int arr[], int n) {
    long long sum = 0;               // 8 bytes — accumulator
    for (int i = 0; i < n; i++)      // i → 4 bytes
        sum += arr[i];               // koi array allocate nahi
    return sum;
}

// copyOn — naya int array of size n → 4n bytes, O(n) auxiliary
int* copyOn(const int arr[], int n) {
    if (n <= 0) return nullptr;      // edge case: khaali input → khaali copy
    int* copy = new int[n];          // 4·n bytes — THE extra allocation
    for (int i = 0; i < n; i++)
        copy[i] = arr[i];            // har element copy
    return copy;                     // caller free karega
}

// matrixOn2 — n×n int matrix → 4n² + n·ptr bytes, O(n²) auxiliary
int** matrixOn2(int n) {
    if (n <= 0) return nullptr;      // edge case
    int** m = new int*[n];           // n row pointers (8n bytes on 64-bit)
    for (int i = 0; i < n; i++)
        m[i] = new int[n];           // har row = n ints (4n bytes) → total 4n²
    return m;
}

void freeMatrix(int** m, int n) {
    if (m == nullptr) return;
    for (int i = 0; i < n; i++) delete[] m[i];
    delete[] m;
}

int main() {
    cout << "══════════════════════════════════════════════════════════════" << endl;
    cout << "   SPACE COMPLEXITY — sizeof() ACCOUNTING: O(1), O(n), O(n²)" << endl;
    cout << "══════════════════════════════════════════════════════════════" << endl;

    cout << "\n sizeof() on this machine:" << endl;
    printf("   sizeof(int)     = %zu bytes\n", sizeof(int));
    printf("   sizeof(long long) = %zu bytes\n", sizeof(long long));
    printf("   sizeof(bool)    = %zu bytes\n", sizeof(bool));
    printf("   sizeof(int*)    = %zu bytes (pointer)\n", sizeof(int*));

    // ---------------- demo 1: O(1) ----------------
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    long long s = sumO1(arr, n);
    long long sumBytes   = sizeof(long long);  // accumulator
    long long indexBytes = sizeof(int);        // loop index
    printf("\n[1] sumO1: sum = %lld\n", s);
    printf("    auxiliary bytes = sizeof(sum)=%lld + sizeof(i)=%lld = %lld bytes, ANY n\n",
           sumBytes, indexBytes, sumBytes + indexBytes);
    printf("    → Space = O(1)   (Time = O(n) : %d additions)\n", n);

    // ---------------- demo 2: O(n) ----------------
    int* copy = copyOn(arr, n);
    long long copyBytes = (long long)sizeof(int) * n;
    printf("\n[2] copyOn: copied n=%d elements\n", n);
    printf("    auxiliary bytes = n·sizeof(int) + sizeof(i)\n");
    printf("                     = %d·%zu + %zu = %lld bytes\n",
           n, sizeof(int), sizeof(int), copyBytes + sizeof(int));
    printf("    edge case n=0 → copyOn returns nullptr (0 bytes allocated)\n");
    printf("    → Space = 4n + 4 = O(n)\n");
    printf("    copy content: ");
    for (int i = 0; i < n; i++) printf("%d ", copy[i]);
    cout << endl;

    int depth = 6;                   // matrix size n=6 (demo mein chhota)
    int** m = matrixOn2(depth);
    long long matBytes = (long long)depth * depth * (long long)sizeof(int)
                       + (long long)depth * (long long)sizeof(int*);
    printf("\n[3] matrixOn2(%d): %d×%d matrix allocated\n", depth, depth, depth);
    printf("    auxiliary bytes = n·sizeof(int*) + n²·sizeof(int)\n");
    printf("                     = %d·%zu + %d·%zu = %lld bytes\n",
           depth, sizeof(int*), depth * depth, sizeof(int), matBytes);
    printf("    → Space = 4n² + 8n = O(n²)\n");

    // quick fill + spot check of matrix
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < depth; j++) m[i][j] = i * depth + j;
    printf("    m[2][3] = %d (spot check)\n", m[2][3]);

    // ---------------- comparison table ----------------
    printf("\n═══════════ SCALING TABLE — auxiliary bytes for various n ═══════════\n");
    printf("┌──────────┬──────────────────┬──────────────────────┬─────────────────────────┐\n");
    printf("│    n     │  sumO1 (O(1))    │   copyOn (O(n))      │   matrixOn2 (O(n²))     │\n");
    printf("├──────────┼──────────────────┼──────────────────────┼─────────────────────────┤\n");
    long long sizes[] = {1, 10, 100, 1000, 10000};
    for (int i = 0; i < 5; i++) {
        long long n_ = sizes[i];
        long long b1 = sumBytes + indexBytes;                       // constant 12
        long long b2 = sizeof(int) * n_ + sizeof(int);              // 4n+4
        long long b3 = n_ * n_ * (long long)sizeof(int)             // 4n²
                     + n_ * (long long)sizeof(int*);                // 8n
        if (b2 > 1024 && b3 > 1024*1024) {
            printf("│ %8lld │ %16lld │ %16lld KB │ %16.2f MB │\n", n_, b1, b2/1024, (double)b3/(1024.0*1024.0));
        } else if (b2 > 1024) {
            printf("│ %8lld │ %16lld │ %16lld │ %16.2f KB │\n", n_, b1, b2, (double)b3/1024.0);
        } else {
            printf("│ %8lld │ %16lld │ %16lld │ %16lld │\n", n_, b1, b2, b3);
        }
    }
    printf("└──────────┴──────────────────┴──────────────────────┴─────────────────────────┘\n");
    printf(" sumO1 flat 12B; copyOn doubles→×2 bytes; matrix n=10000 alone ≈ %.1f MB.\n",
           10000.0*10000.0*4.0/(1024.0*1024.0));

    // cleanup
    delete[] copy;
    freeMatrix(m, depth);

    return 0;
}