/*
═══════════════════════════════════════════════
 TASKS — SPACE COMPLEXITY
═══════════════════════════════════════════════

 THEORY RECAP (use it to guide your solutions):
   TOTAL space = INPUT space + AUXILIARY space.
   Interview "space" = auxiliary unless stated otherwise.
   Patterns: fixed locals → O(1); array of size n → O(n);
   2D matrix n×n → O(n²); recursion depth d → O(d).
   Byte formulas on this machine: sizeof(int)=4, sizeof(long long)=8.

   Ground rules for all tasks:
     (a) Derive auxiliary space byte-by-byte, then state O().
     (b) Never forget the recursion stack when the code recurses.

──────────────────────────────────────────
 TASK 1 — BUBBLE SORT: PROVE ITS AUX SPACE IS O(1)
──────────────────────────────────────────
 Problem:
   Given bubble-sort code (nested loops, one `swap` via a temp),
   count every variable that is ADDITIONAL to the input array, state
   its bytes on this machine, and prove the class. Then instrument
   the code to print the exact bytes you concluded. Also answer: what
   would happen to the space class if we kept a second copy `b[n]`?

 💡 HINT: `int temp`, loop indices `i`, `j`, bounds `n` — all scalars
          whose size is constant. No allocation inside the loops.

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   void bubble(int a[], int n) {
       // temp + i + j — all O(1) scalars
       for (int i = 0; i < n - 1; i++)
           for (int j = 0; j < n - 1 - i; j++)
               if (a[j] > a[j+1]) { int temp = a[j]; a[j] = a[j+1]; a[j+1] = temp; }
   }
   int main() {
       int a[] = {5,4,3,2,1};
       // sum of sizeof() of scalar temporaries print karo
       return 0;
   }

──────────────────────────────────────────
 TASK 2 — TWO-POINTER PALINDROME: WHY IS IT IN-PLACE?
──────────────────────────────────────────
 Problem:
   A palindrome check uses two indices `lo` and `hi` moving toward
   each other — no extra array. Derive its auxiliary space byte count
   and class. Then write the code, run it on "racecar" and "hello",
   and print the sizeof() accounting that proves O(1).

 💡 HINT: the string itself is INPUT space; the two int indices are
          auxiliary — constant bytes regardless of string length.

 ✏️ STARTER CODE:
   #include <iostream>
   #include <string>
   using namespace std;
   bool palindrome(const string& s) {
       // lo=0, hi=s.size()-1 ; jab tak lo<hi compare karke move
   }
   int main() {
       // "racecar" aur "hello" test karke result print
       return 0;
   }

──────────────────────────────────────────
 TASK 3 — EXTRA COPY & MATRIX: MEASURE n-CLOSED BYTES
──────────────────────────────────────────
 Problem:
   For these three routines, derive BYTES AS A FUNCTION of n, then the
   class:
     [I]  int* copyArray(const int a[], int n)   // new int[n], fill
     [II] int** identityMatrix(int n)            // n×n, diagonal=1
     [III] long long sumAll(const int a[], int n)// single accumulator
   Print a computed table for n = 10, 100, 1000 showing the bytes for
   [I], [II], [III] and confirm [III]'s row is FLAT (size-independent).

 💡 HINT: [I] bytes = 4n + sizeof(int)(for index);
          [II] bytes = n·sizeof(int*) + n²·sizeof(int);
          [III] bytes = sizeof(long long) + sizeof(int) — constant.
          Watch for 10×, 100× jumps — not 2× — square growth.

 ✏️ STARTER CODE:
   #include <iostream>
   #include <cstdio>
   using namespace std;
   int main() {
       long long sizes[] = {10, 100, 1000};
       for (long long n : sizes) {
           // bCopy = 4*n + 4
           // bMat  = n*sizeof(int*) + n*n*4
           // bSum  = 8 + 4  (flat)
           // print karo
       }
       return 0;
   }

-------------- SOLUTIONS --------------
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// ==================== TASK 1 — bubble sort space audit ====================
void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++)       // i → 4 bytes, scalar
        for (int j = 0; j < n - 1 - i; j++) { // j → 4 bytes, scalar
            if (a[j] > a[j + 1]) {
                int temp = a[j];          // temp → 4 bytes, scalar
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}

// ==================== TASK 2 — two-pointer palindrome ====================
bool palindrome(const string& s) {
    int lo = 0, hi = (int)s.size() - 1;   // 2 indices — fixed!
    while (lo < hi) {
        if (s[lo] != s[hi]) return false; // compare ends, move inward
        lo++;
        hi--;
    }
    return true;
}

// ==================== TASK 3 — the three routines ====================
int* copyArray(const int a[], int n) {    // O(n) auxiliary
    if (n <= 0) return nullptr;
    int* copy = new int[n];               // 4n bytes — the whole point
    for (int i = 0; i < n; i++) copy[i] = a[i];
    return copy;
}

int** identityMatrix(int n) {             // O(n²) auxiliary
    if (n <= 0) return nullptr;
    int** m = new int*[n];                // n pointers → 8n bytes (64-bit)
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];                // each row n ints → 4n bytes/row
        for (int j = 0; j < n; j++) m[i][j] = (i == j) ? 1 : 0; // diagonal
    }
    return m;
}
void delMatrix(int** m, int n) {
    if (!m) return;
    for (int i = 0; i < n; i++) delete[] m[i];
    delete[] m;
}

long long sumAll(const int a[], int n) {  // O(1) auxiliary
    long long sum = 0;                    // 8 bytes accumulator
    for (int i = 0; i < n; i++) sum += a[i];
    return sum;                           // i → 4 bytes
}

int main() {
    cout << "══════════════════════════════════════════════════" << endl;
    cout << "   SPACE COMPLEXITY — TASK SOLUTIONS" << endl;
    cout << "══════════════════════════════════════════════════" << endl;

    // ==================== TASK 1 ====================
    cout << "\n═══ TASK 1 — bubble sort aux space audit ═══" << endl;
    int a[] = {5, 4, 3, 2, 1};
    int n = 5;
    long long bytesTemp = sizeof(int);    // temp variable
    long long bytesI    = sizeof(int);    // outer index
    long long bytesJ    = sizeof(int);    // inner index
    long long bytesN    = sizeof(int);    // n (copied into function)
    printf(" scalar locals:  temp=%lld B,  i=%lld B,  j=%lld B,  n=%lld B\n",
           bytesTemp, bytesI, bytesJ, bytesN);
    printf(" aux total = %lld bytes — INDEPENDENT of n (n=5 ya n=10^6, same)\n",
           bytesTemp + bytesI + bytesJ + bytesN);
    printf(" → Space = O(1).  (Time = n(n−1)/2 = %d comparisons = O(n²))\n",
           n * (n - 1) / 2);
    bubble(a, n);                          // run karke sorted check
    printf(" sorted?   ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    cout << endl;
    printf(" IF we added int* b = new int[n]  → aux 4n+O(1) → class jumps to O(n).\n");

    // ==================== TASK 2 ====================
    cout << "\n═══ TASK 2 — two-pointer palindrome ═══" << endl;
    printf(" aux bytes = sizeof(lo)=%d + sizeof(hi)=%d = 8 bytes, string length se FREE\n",
           (int)sizeof(int), (int)sizeof(int));
    printf(" → Space = O(1) (in-place). INPUT string space = O(len) is untouched.\n");
    cout << " 'racecar' is palindrome?   " << (palindrome("racecar") ? "YES" : "NO") << endl;
    cout << " 'hello'   is palindrome?   " << (palindrome("hello")   ? "YES" : "NO") << endl;
    cout << " distinction: input (O(len)) is GIVEN; auxiliary (2 indices) is O(1).\n";

    // ==================== TASK 3 ====================
    cout << "\n═══ TASK 3 — byte-vs-n table for copy / matrix / sum ═══" << endl;
    long long sizes[] = {10, 100, 1000};
    printf("┌─────────┬────────────────┬──────────────────────┬───────────────┐\n");
    printf("│     n   │ copyArray (O(n))│ identityMatrix (O(n²))│ sumAll (O(1)) │\n");
    printf("├─────────┼────────────────┼──────────────────────┼───────────────┤\n");
    for (int k = 0; k < 3; k++) {
        long long n = sizes[k];
        long long bCopy = 4 * n + 4;                       // 4n + index
        long long bMat  = n * (long long)sizeof(int*)      // row pointers
                        + n * n * (long long)sizeof(int);  // cells
        long long bSum  = sizeof(long long) + sizeof(int); // flat 12 B
        printf("│ %7lld │ %14lld │ %20lld │ %13lld │\n", n, bCopy, bMat, bSum);
    }
    printf("└─────────┴────────────────┴──────────────────────┴───────────────┘\n");
    cout << " observations:\n"
         << "   copyArray row: 10→100→1000 = 44→404→4004 B (×10 each step) → O(n)\n"
         << "   matrix row:    10→100→1000 = ~4KB→~43KB→~4.1MB (×100!)  → O(n²)\n"
         << "   sumAll row:    12→12→12 B (FLAT)                            → O(1)\n";

    // verify classes empirically with the real routines (small n)
    {
        int arr[] = {1, 2, 3};
        int* cp = copyArray(arr, 3);
        int** id = identityMatrix(3);
        long long s = sumAll(arr, 3);
        printf(" spot checks: copy[2]=%d, matrix[1][1]=%d, sum=%lld\n", cp[2], id[1][1], s);
        delete[] cp;
        delMatrix(id, 3);
    }

    return 0;
}