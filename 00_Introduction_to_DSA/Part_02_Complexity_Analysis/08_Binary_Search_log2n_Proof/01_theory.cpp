/*
═══════════════════════════════════════════════
 BINARY SEARCH — LOG₂n PROOF  ⭐ STAR TOPIC
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine finding a name in a 1000-page telephone directory that is
 alphabetically sorted. Do you start from page 1? No! You open it in
 the middle — if your name comes later, you ignore the left half
 entirely, then open the middle of the RIGHT half, and repeat. In a
 few jumps you nail the exact page. A 1000-page book takes at most
 about 10 guesses (2¹⁰ = 1024). A 1000-entry linear scan would take
 up to 1000 checks. That phone-directory trick — "guess middle, throw
 away half" — is exactly Binary Search, and it is why log₂n is such
 a powerful number.

 📖 THEORY: (pure English, formal)

 - DEFINITION:
   Binary Search is a search algorithm for SORTED arrays. It repeatedly
   compares the target with the MIDDLE element and discards the half
   that cannot contain the target. Each step halves the search space.

 - REQUIREMENT: The array must be SORTED (ascending/descending).
   If unsorted, binary search gives wrong results.

 - KEY POINTS:
   1. Each step eliminates HALF of the remaining elements.
   2. Number of elements left after each step: n → n/2 → n/4 → ... → 1.
   3. After k steps the search space has n / 2^k elements.
   4. We STOP when 1 element is left:
        n / 2^k = 1  →  n = 2^k  →  k = log₂(n)
   5. Therefore the MAXIMUM number of steps = ⌈log₂(n)⌉
      (ceil because halving may not be perfectly even).
   6. For n = 1024:  log₂(1024) = 10 steps. For n = 1 billion:
      log₂(1,000,000,000) ≈ 30 steps. Incredible.

 - ASCII DIAGRAM — HALVING TABLE (the heart of the proof):

   Step 0: search space size = n
   Step 1: n / 2        (after 1 halving)
   Step 2: n / 4        (after 2 halvings)
   Step 3: n / 8        (after 3 halvings)
   ...
   Step k: n / 2^k      (after k halvings)
   Stop  : 1            (n / 2^k = 1)

   For n = 32 (worked example):

     Step 0 -> 32 elements
     Step 1 -> 16 elements
     Step 2 -> 8 elements
     Step 3 -> 4 elements
     Step 4 -> 2 elements
     Step 5 -> 1 element  = DONE

     Steps = 5 = log₂(32)  ✓   (2^5 = 32)

   Visual halving hunt for target 23 in a 32-element sorted array:

   [1 2 3 4 5 6 7 8 | 9 10 11 12 13 14 15 16 | 17 18 19 20 21 22 23 24 | ...]
    L           mid1=16          mid2=24            mid3=20   mid4=22
   23 > 16 → right    23 < 24 → left    23 > 20 → right  23 > 22 → right
                                                    mid5=23  FOUND in 5 steps

 - WHEN TO USE:
   * ONLY on sorted arrays/lists (static data — repeatedly queried).
   * Dictionary lookups, library catalogs, DB indexes.
   * When "log n" is acceptable — nearly always better than "n".
   * Use linear search for unsorted tiny arrays or one-off scans.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Take low = 0, high = n-1. Compute mid = (low+high)/2.
         WHY: mid is the middle position; we compare target with it.

 Step 2: If arr[mid] == target → FOUND. Stop immediately.
         WHY: exact match at middle.

 Step 3: If target < arr[mid] → go LEFT: high = mid-1.
         WHY: array is sorted, so target must be in left half.

 Step 4: If target > arr[mid] → go RIGHT: low = mid+1.
         WHY: target must be in the larger right half.

 Step 5: Repeat until low > high (not found) or found.
         WHY: low > high means the search space is empty.

 THE HALVING TABLE (n → n/2 → n/4 → ... → 1):

   k (steps done) | search space size
   ---------------|-------------------
   0              | n
   1              | n/2
   2              | n/4
   3              | n/8
   ...            | ...
   k              | n/2^k
   stop           | 1  (n/2^k = 1)

 VISUAL WALKTHROUGH:

 Hunting 23 in 16-element sorted array:

 indices: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
 values:  [ 2  5  8 11 14 17 20 23 26 29 32 35 38 41 44 47 ]
 target = 23

 Step 1: L=0 H=15 mid=7 → arr[7]=23 == 23 → FOUND! (3 checks
         effective: 1 mid)

 Actually let's force more steps by choosing target 41:

 Step 1: L=0 H=15 mid=7  arr[7]=23;  23 < 41 → L=8
 Step 2: L=8 H=15 mid=11 arr[11]=35; 35 < 41 → L=12
 Step 3: L=12 H=15 mid=13 arr[13]=41 == 41 → FOUND in 3 steps

 log₂(16) = 4 → max steps = 4, we took 3. ✓ never exceeds.

 DRY RUN:

 Search target = 7 in {2,5,7,10,15} (n=5):

 L=0 H=4 → mid = (0+4)/2 = 2 → arr[2]=7 == 7 → FOUND, steps=1.
 2³ = 8 ≥ 5 so ⌈log₂(5)⌉ = 3 max — we got lucky with 1 step.

 Search target = 1 in {2,5,7,10,15} (absent):
 L=0 H=4 → mid=2 arr[2]=7;  7 > 1 → H=1
 L=0 H=1 → mid=0 arr[0]=2;  2 > 1 → H=-1
 L=0 H=-1 → L > H → NOT FOUND, steps=3. (= ⌈log₂(5)⌉ = 3 ✓)

 TIME COMPLEXITY CALCULATION (THE PROOF):

   Iterative binary search — worst case:
   - After 1 step: n elements reduce to n/2.
   - After 2 steps: n/4.
   - After k steps: n/2^k.
   - The search must STOP when 1 element is left (or 0 = not found):
         n / 2^k  =  1
     Multiply both sides by 2^k:
         n = 2^k
     Take log₂ of both sides:
         log₂(n) = log₂(2^k) = k
         ⇒  k = log₂(n)
   - Therefore worst-case steps = log₂(n).
   - Each step does O(1) work (one comparison + pointer updates).
   - Total work = O(1) * log₂(n) = O(log n).

   → Time Complexity = O(log n)

 SPACE COMPLEXITY CALCULATION:

   - ITERATIVE binary search: uses only low, mid, high (fixed vars).
     No extra memory that grows with n.
     → Space = O(1)
   - RECURSIVE binary search: each recursive call pushes a stack frame
     (low, high, mid locals). In the worst case depth = log₂(n).
     → Space = O(log n) (due to call stack)

   → Iterative: O(1)   Recursive: O(log n)

 APPROACH COMPARISON (linear vs binary, n = 50):
 ┌──────────────────┬──────────────────┬──────────────────┬───────────────┐
 │   Metric         │ Linear Search    │ Binary Search    │ Winner        │
 ├──────────────────┼──────────────────┼──────────────────┼───────────────┤
 │ Best case        │ 1 comparison     │ 1 comparison     │ tie           │
 │ Average case     │ (n+1)/2 = 25.5   │ ≈ log₂(n) ≈ 5.6  │ Binary        │
 │ Worst case       │ n = 50           │ log₂(50) ≈ 6     │ Binary (8x)   │
 │ Sorted required  │ No               │ YES              │ —             │
 │ Extra space      │ O(1)             │ O(1) iterative   │ tie           │
 └──────────────────┴──────────────────┴──────────────────┴───────────────┘

   DEMO WILL SHOW: n = 50, linear worst = 50 comparisons vs
   binary worst = 6 steps.   (log₂(50) ≈ 5.64 → ceil = 6)
*/

#include <iostream>
using namespace std;

// iterative binary search, counts steps
int binarySearchCount(int arr[], int n, int target, int &steps) {
    int low = 0, high = n - 1;
    steps = 0;
    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2; // overflow-safe mid
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1; // right half
        } else {
            high = mid - 1; // left half
        }
    }
    return -1; // not found
}

// linear search with comparison count (for compare demo)
int linearSearchCount(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// recursive binary search with step counter (parameter by reference)
int binarySearchRecursive(int arr[], int low, int high, int target, int &steps) {
    steps++; // har recursive call ek step
    if (low > high) {
        return -1; // base case: not found
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target, steps);
    }
    return binarySearchRecursive(arr, low, mid - 1, target, steps);
}

// ------------------------------------------------------------------
int main() {
    cout << "============================================================" << endl;
    cout << "   BINARY SEARCH — LOG₂n PROOF   DEMO" << endl;
    cout << "============================================================" << endl;

    // --- Demo 1: n=32 halving table ---
    cout << "\n--- DEMO 1: The Halving Table (n = 32) ---" << endl;
    int n = 32;
    cout << "Step 0: search size = " << n << endl;
    int size = n;
    int step = 0;
    for (step = 1; size > 1; step++) {
        size = (size + 1) / 2; // ceil halving
        cout << "Step " << step << ": search size = " << size << endl;
    }
    cout << "Total steps to reduce 32 -> 1 = " << step - 1 << endl;
    cout << "log2(32) = " << 5 << " -> steps = 5 = log2(n) ✓" << endl;
    // wait: ceil halving for 32: 32->16->8->4->2->1 = 5 halvings.
    // Loop printed step1..step5 with sizes 16,8,4,2,1 — step ends at 5+1,
    // so step-1 = 5. Correct.

    // --- Demo 2: n=32 actual search ---
    cout << "\n--- DEMO 2: Search in 32-element sorted array ---" << endl;
    int arr32[32];
    for (int i = 0; i < 32; i++) arr32[i] = 2 * i; // evens 0..62
    int target32 = 46; // will be found
    int steps32 = 0;
    int pos32 = binarySearchCount(arr32, 32, target32, steps32);
    cout << "Array[32] = evens 0..62, target = " << target32 << endl;
    cout << "Found at index " << pos32 << " in " << steps32 << " steps." << endl;
    cout << "check value: arr32[" << pos32 << "] = " << arr32[pos32] << endl;
    cout << "Max steps allowed log2(32) = 5 -> taken " << steps32
         << " ≤ 5 ✓" << endl;

    // --- Demo 3: THE n=50 show — linear vs binary (WORST CASE) ---
    cout << "\n--- DEMO 3: n = 50 — Linear vs Binary (WORST CASE) ---" << endl;
    int n50 = 50;
    int arr50[50];
    for (int i = 0; i < 50; i++) arr50[i] = 5 * (i + 1); // 5,10,...,250
    int target50 = 9999; // ABSENT -> worst case for both
    int linearCmp = 0, binSteps = 0;
    linearSearchCount(arr50, n50, target50, linearCmp);
    binarySearchCount(arr50, n50, target50, binSteps);
    cout << "Sorted array of " << n50 << " elements (5,10,...,250)." << endl;
    cout << "Target " << target50 << " is ABSENT -> worst case." << endl;
    cout << "LINEAR SEARCH comparisons = " << linearCmp << endl;
    cout << "BINARY SEARCH  steps      = " << binSteps << endl;
    cout << "log2(50) = " << 5.64 << " -> binary worst = ceil = 6 ✓" << endl;
    cout << "Binary used " << linearCmp << " / " << binSteps << " = "
         << (linearCmp / (double)binSteps) << "x fewer steps!" << endl;

    // --- Demo 4: Edge cases ---
    cout << "\n--- DEMO 4: Edge Cases ---" << endl;
    // empty array
    int stepsE = 0;
    int resE = binarySearchCount(arr50, 0, 5, stepsE);
    cout << "Empty array search 5: result=" << resE << ", steps=" << stepsE << endl;
    // single element found
    int singleArr[] = {7};
    int stepsS = 0;
    int resS = binarySearchCount(singleArr, 1, 7, stepsS);
    cout << "Single[7] search 7: result=" << resS << ", steps=" << stepsS
         << " (log2(1)=0, but 1 comparison needed)" << endl;
    // recursive version steps
    int stepsR = 0;
    int resR = binarySearchRecursive(arr50, 0, 49, 125, stepsR);
    cout << "RECURSIVE search 125 in n=50: found at " << resR
         << " in " << stepsR << " recursive steps." << endl;
    // large n: log2 grows extremely slowly
    cout << "Feeling log2: log2(1,000,000)=" << 19.93 << " steps, " << endl;
    cout << "log2(1,000,000,000)=" << 29.90 << " steps only!" << endl;

    cout << "\n============================================================" << endl;
    cout << " SUMMARY: Binary Search = O(log n). Proof: n/2^k = 1" << endl;
    cout << " => n = 2^k => k = log2(n). Iterative space O(1)." << endl;
    cout << " n=50: linear worst 50 vs binary worst 6 steps." << endl;
    cout << "============================================================" << endl;
    return 0;
}