/*
═══════════════════════════════════════════════
 TASK SET — SORTING ALGORITHMS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: You manage a playlist of a thousand songs and need them in
 ascending play-count order, or a leaderboard of students' scores. Every sort you
 write here is a tool you will reach for over and over in interviews and in code —
 the harder the task, the closer it gets to production-grade sorting.
🧠 HOW TO SOLVE: Master the counting of loops and indices first. For bubble and
 selection, think windows: each pass shrinks by one. For insertion, think "play
 cards": shift, then insert. For merge and quick, draw the recursion tree before
 writing a single line. Always trace your code on a 4-element array by hand.
 8 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/

/*
───────────────────────────────────────────────
 TASK 1 (EASY) : BUBBLE SORT IMPLEMENTATION
───────────────────────────────────────────────
Write bubbleSort(vector<int>& a) using the classic naive version:
   - run n-1 passes
   - in pass i compare adjacent pairs a[j], a[j+1] for j in [0, n-i-1)
   - swap whenever a[j] > a[j+1]
Print the array after every pass to watch the largest element bubble to the end.
💡 HINT: after pass k the k largest elements are locked at the end, so the scan
 window length is n - k. The inner loop length is n - i - 1 exactly because of this.
✏️ STARTER CODE:
   void bubbleSort(vector<int>& a) {
       int n = a.size();
       for (int i = 0; i < n - 1; i++) {
           for (int j = 0; j < n - i - 1; j++) {
               // TODO: if a[j] > a[j+1] → swap and print the pass
           }
       }
   }
*/

/*
───────────────────────────────────────────────
 TASK 2 (EASY) : SELECTION SORT — MIN INDEX TRACKING
───────────────────────────────────────────────
Write selectionSort(vector<int>& a):
   - for index i = 0 .. n-2, treat a[i..n-1] as unsorted
   - find minIdx = index of smallest value in that range
   - swap a[i] with a[minIdx] only if they differ
💡 HINT: you must track the INDEX of the minimum, not the value, because swap
 needs both positions. The swap is a single long-distance swap per i — that is why
 selection sort is praised for tiny "swap counts".
✏️ STARTER CODE:
   void selectionSort(vector<int>& a) {
       int n = a.size();
       for (int i = 0; i < n - 1; i++) {
           int minIdx = i;                 // TODO: iterate j = i+1..n-1, update minIdx
           // TODO: swap a[i] and a[minIdx] only if minIdx != i
       }
   }
*/

/*
───────────────────────────────────────────────
 TASK 3 (EASY) : INSERTION SORT — SHIFT BACK
───────────────────────────────────────────────
Write insertionSort(vector<int>& a):
   - start from i = 1, keep prefix a[0..i-1] sorted
   - save key = a[i], shift every bigger element right, insert key at the gap
💡 HINT: shifting (a[j+1] = a[j]) is a copy, not a swap. You move leftwards
 (j-- ) while a[j] > key. When the while loop stops, the gap is at j+1.
✏️ STARTER CODE:
   void insertionSort(vector<int>& a) {
       for (int i = 1; i < (int)a.size(); i++) {
           int key = a[i];
           int j = i - 1;
           // TODO: while (j >= 0 && a[j] > key) { a[j+1] = a[j]; j--; }
           // TODO: a[j+1] = key;
       }
   }
*/

/*
───────────────────────────────────────────────
 TASK 4 (MEDIUM) : MERGE TWO SORTED ARRAYS
───────────────────────────────────────────────
Given two already-sorted vectors L and R, return ONE sorted vector out.
 Do NOT call sort() — use the two-pointer merge yourself.
💡 HINT: out.push_back(the smaller head of L[i] / R[j]); advance only the pointer
 that you took. One side drains first → append the remaining tail of the other.
✏️ STARTER CODE:
   vector<int> mergeTwo(const vector<int>& L, const vector<int>& R) {
       vector<int> out;
       int i = 0, j = 0;
       while (i < (int)L.size() && j < (int)R.size()) {
           // TODO: push smaller head, advance its pointer
       }
       // TODO: drain leftover L, then leftover R
       return out;
   }
*/

/*
───────────────────────────────────────────────
 TASK 5 (MEDIUM) : MERGE SORT — FULL RECURSIVE
───────────────────────────────────────────────
Write mergeSort(a, lo, hi) using TASK 4's merge ideas on a single array:
   - base case when lo >= hi → return
   - mid = lo + (hi - lo) / 2
   - recurse left, recurse right, then merge a[lo..mid] and a[mid+1..hi]
💡 HINT: copy the two halves into temp vectors L and R before merging (cleaner),
 then write back into a. Use lo + (hi-lo)/2, NOT (lo+hi)/2, to avoid overflow.
 Also derive its complexity: T(n) = 2T(n/2) + O(n).
✏️ STARTER CODE:
   void merge(vector<int>& a, int lo, int mid, int hi) { // TODO: reuse mergeTwo logic
   }
   void mergeSort(vector<int>& a, int lo, int hi) {
       if (lo >= hi) return;
       int mid = lo + (hi - lo) / 2;
       // TODO: recurse both halves, then call merge(a, lo, mid, hi)
   }
*/

/*
───────────────────────────────────────────────
 TASK 6 (HARD) : QUICK SORT — LO MUTO PARTITION
───────────────────────────────────────────────
Write lomutoPartition(a, lo, hi): pick pivot = a[hi], pivot i = lo-1, scan j = lo..hi-1;
 anything ≤ pivot swaps into the "small" zone. Put pivot at i+1 and return i+1.
 Then write quickSort(a, lo, hi) and recurse on p-1 and p+1.
💡 HINT: the pivot ends up in its FINAL position — that is the whole trick of
 quick sort. Trace [10,7,8,9,1,5] before coding. ALSO: explain why a fixed pivot is
 O(n²) on sorted input, and why a random pivot fixes it.
✏️ STARTER CODE:
   int lomutoPartition(vector<int>& a, int lo, int hi) {
       int pivot = a[hi]; int i = lo - 1;
       // TODO: for (j = lo; j < hi; j++) if (a[j] <= pivot) { i++; swap(a[i], a[j]); }
       // TODO: swap(a[i+1], a[hi]); return i + 1;
   }
   void quickSort(vector<int>& a, int lo, int hi) {
       if (lo >= hi) return;
       // TODO: int p = lomutoPartition(...); recurse [lo, p-1] and [p+1, hi]
   }
*/

/*
───────────────────────────────────────────────
 TASK 7 (MEDIUM) : COUNTING SORT FOR NUMBERS 0..9
───────────────────────────────────────────────
Given digits in [0,9], sort them WITHOUT any comparison-based algorithm:
   - count frequencies into freq[10]
   - build prefix sums, then fill an output array right → left (stable)
💡 HINT: prefix sum freq[i] += freq[i-1] turns "how many of each digit" into
 "where the last occurrence of digit i must go". Answer: what happens to
 complexity if a value range is 0..10⁶ for only 10 numbers? (O(n+k) with k huge.)
✏️ STARTER CODE:
   void countingSort10(vector<int>& a) {
       vector<int> freq(10, 0);
       // TODO: tally each digit
       // TODO: prefix sums
       // TODO: output buffer, place from right to left
   }
*/

/*
───────────────────────────────────────────────
 TASK 8 (HARD) : SORT 0s, 1s, 2s — DUTCH NATIONAL FLAG
───────────────────────────────────────────────
Sort an array containing only 0, 1, 2 in ONE pass, O(n) time and O(1) space,
 WITHOUT counting sort or sort(). Use three pointers low, mid, high.
💡 HINT: invariant — [0..low-1] are 0s, [mid..high-1] are unexplored, [high+1..end]
 are 2s. Look at a[mid]: if 0 swap with low and advance both; if 1 just mid++;
 if 2 swap with high and DON'T advance mid (the swapped-in value is unseen yet).
✏️ STARTER CODE:
   void dutchFlag(vector<int>& a) {
       int low = 0, mid = 0, high = (int)a.size() - 1;
       while (mid <= high) {
           // TODO: three cases on a[mid]
       }
   }
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <vector>
using namespace std;

// helper — array print karne ke liye
void printArr(const vector<int>& a) {
    cout << "[";
    for (size_t i = 0; i < a.size(); i++) {
        if (i > 0) cout << ", ";
        cout << a[i];
    }
    cout << "]";
}

// ---------- SOLUTION TASK 1 : bubble sort (naive) ----------
void bubbleSort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {           // n-1 passes har element final hone ke liye
        for (int j = 0; j < n - i - 1; j++) {   // window shrink: last i elements already sorted
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);           // badi value ko aage bubble karte jao
            }
        }
        cout << "  pass " << i + 1 << ": ";
        printArr(a);
        cout << "\n";
    }
}

// ---------- SOLUTION TASK 2 : selection sort (min index) ----------
void selectionSort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;                         // abhi current head ko min maan lo
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;   // sahi min ka INDEX track karo
        }
        if (minIdx != i) swap(a[i], a[minIdx]); // min ko unsorted part ke front pe dalo
    }
}

// ---------- SOLUTION TASK 3 : insertion sort ----------
void insertionSort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int key = a[i];                         // current card hatayenge
        int j = i - 1;
        while (j >= 0 && a[j] > key) {          // bade elements ko right shift karo
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;                         // gap mein key insert karo
    }
}

// ---------- SOLUTION TASK 4 : merge two sorted arrays ----------
vector<int> mergeTwo(const vector<int>& L, const vector<int>& R) {
    vector<int> out;
    int i = 0, j = 0;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) out.push_back(L[i++]); // chota head pehle — <= se stable rahega
        else              out.push_back(R[j++]);
    }
    while (i < (int)L.size()) out.push_back(L[i++]); // L ka bacha hua tail copy karo
    while (j < (int)R.size()) out.push_back(R[j++]); // R ka bacha hua tail copy karo
    return out;
}

// ---------- SOLUTION TASK 5 : merge sort (full recursive) ----------
// merge helper — array ke ek segment ke do sorted halves ko jodta hai
void merge(vector<int>& a, int lo, int mid, int hi) {
    vector<int> L(a.begin() + lo, a.begin() + mid + 1); // left half copy
    vector<int> R(a.begin() + mid + 1, a.begin() + hi + 1); // right half copy
    int i = 0, j = 0, k = lo;                   // two-pointer + write pointer
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) a[k++] = L[i++];      // chota head chuna
        else              a[k++] = R[j++];
    }
    while (i < (int)L.size()) a[k++] = L[i++];  // leftover copy
    while (j < (int)R.size()) a[k++] = R[j++];
}

/**
 * Merge sort — complexity derivation (interview answer):
 *   T(n) = 2T(n/2) + O(n)     (split in half + O(n) merge)
 *   Recursion tree ke level har baar half होते हैं → total levels = log2(n)
 *   Har level pe total merge work = O(n)  (n elements merge hote hain overall)
 *   ⇒ T(n) = n · log2(n) → O(n log n)  (best/average/worst sab same)
 */
void mergeSort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;                       // base case: 1 ya 0 element = sorted
    int mid = lo + (hi - lo) / 2;               // overflow-safe mid
    mergeSort(a, lo, mid);                      // left half sort
    mergeSort(a, mid + 1, hi);                  // right half sort
    merge(a, lo, mid, hi);                      // conquer — do halves merge
}

// ---------- SOLUTION TASK 6 : quick sort (Lomuto) ----------
int lomutoPartition(vector<int>& a, int lo, int hi) {
    int pivot = a[hi];                          // Lomuto convention: last element pivot
    int i = lo - 1;                             // i = "small zone" ka last index
    for (int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {                    // pivot se chhota/equal → left zone
            i++;
            swap(a[i], a[j]);                   // small zone ko grow karo
        }
    }
    swap(a[i + 1], a[hi]);                      // pivot ko do zones ke beech rakho
    return i + 1;                               // pivot ab har jagah par FINAL hai
}

/**
 * Worst vs average — interview answer:
 *   Sorted array pe fixed pivot (first/last) → har split mein ek side khali hoti hai
 *   ⇒ T(n) = T(n-1) + O(n) = O(n²)   (n divides ho jaata hai, sirf 1 chhoti problem)
 *   Balanced split → T(n) = 2T(n/2) + O(n) = O(n log n)
 *   RANDOM pivot: har element ki pivot banne ki chance barabar → unbalanced split
 *   ki probability बहुत kam → expected O(n log n). Isliye sorted input pe bhi fast.
 */
void quickSort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int p = lomutoPartition(a, lo, hi);         // pivot ko fina; position par bithao
    quickSort(a, lo, p - 1);                    // left segment sort karo
    quickSort(a, p + 1, hi);                    // right segment sort karo
}
void quickSort(vector<int>& a) { if (!a.empty()) quickSort(a, 0, (int)a.size() - 1); }

// ---------- SOLUTION TASK 7 : counting sort for digits 0..9 ----------
void countingSort10(vector<int>& a) {
    if (a.empty()) return;
    vector<int> freq(10, 0);
    for (int x : a) freq[x]++;                  // har digit ka frequency tally

    for (int i = 1; i < 10; i++) freq[i] += freq[i - 1]; // prefix sum → last index info

    vector<int> out(a.size());
    for (int i = (int)a.size() - 1; i >= 0; i--) {       // right→left = stable placement
        out[--freq[a[i]]] = a[i];               // --freq gives final position, then insert
    }
    a = out;
}

/**
 * Complexity — interview answer:
 *   Tally O(n) + prefix O(k) + output O(n) ⇒ T(n) = O(n + k)
 *   Agar range sirf 10 hai → O(n). Agar range 0..10^6 for n=10 → O(10^6) `mehanga`
 *   ⇒ counting sort tabhi use karo jab k ≈ n ho (small known integer range).
 */

// ---------- SOLUTION TASK 8 : Dutch national flag (0s,1s,2s) ----------
void dutchFlag(vector<int>& a) {
    int low = 0, mid = 0, high = (int)a.size() - 1;
    while (mid <= high) {                       // mid window unexplored zone ko point karta hai
        if (a[mid] == 0) {                      // 0 → front zone
            swap(a[low], a[mid]);
            low++; mid++;                       // dono aage badho — 0 ab final hai
        } else if (a[mid] == 1) {
            mid++;                              // 1 apni jagah par hai, bas explore aage badho
        } else {                                // a[mid] == 2 → back zone
            swap(a[mid], a[high]);
            high--;                             // mid aage NA badhao — naya swapped value decodge karo
        }
    }
}
// complexity: O(n) time, O(1) space — ek hi pass mein teeno groups sort

// ---------- DEMO: sab solutions ek saath run karo ----------
int main() {
    printArr({}); cout << "\n";

    cout << "TASK 1 — Bubble sort, pass-by-pass:\n";
    vector<int> a1 = {5, 1, 4, 2, 8};
    bubbleSort(a1); cout << "  final: "; printArr(a1); cout << "\n\n";

    cout << "TASK 2 — Selection sort:\n";
    vector<int> a2 = {5, 1, 4, 2, 8};
    selectionSort(a2); cout << "  "; printArr(a2); cout << "\n\n";

    cout << "TASK 3 — Insertion sort:\n";
    vector<int> a3 = {5, 1, 4, 2, 8};
    insertionSort(a3); cout << "  "; printArr(a3); cout << "\n\n";

    cout << "TASK 4 — Merge two sorted arrays:\n";
    vector<int> m = mergeTwo({1, 3, 5}, {2, 4, 6, 8});
    cout << "  merge([1,3,5],[2,4,6,8]) = "; printArr(m); cout << "\n\n";

    cout << "TASK 5 — Merge sort:\n";
    vector<int> a5 = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(a5, 0, (int)a5.size() - 1);
    cout << "  "; printArr(a5); cout << "\n\n";

    cout << "TASK 6 — Quick sort (Lomuto):\n";
    vector<int> a6 = {10, 7, 8, 9, 1, 5};
    quickSort(a6); cout << "  "; printArr(a6); cout << "\n\n";

    cout << "TASK 7 — Counting sort (digits 0..9):\n";
    vector<int> a7 = {4, 2, 2, 8, 9, 1, 0, 3, 3};
    countingSort10(a7); cout << "  "; printArr(a7); cout << "\n\n";

    cout << "TASK 8 — Dutch flag (0s,1s,2s):\n";
    vector<int> a8 = {2, 0, 1, 2, 1, 0, 2, 1, 0};
    dutchFlag(a8); cout << "  "; printArr(a8); cout << "\n";

    return 0;
}