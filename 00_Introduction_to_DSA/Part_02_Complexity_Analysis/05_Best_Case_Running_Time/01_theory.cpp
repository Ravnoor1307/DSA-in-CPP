/*
═══════════════════════════════════════════════
 BEST CASE RUNNING TIME
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you walk into a huge library with thousands of books lined up
 on shelves. You need to find a specific novel. The BEST thing that
 could happen is — the very first book you pick up IS the one you
 wanted. You spent almost zero effort. That is "Best Case Running
 Time" — the absolute minimum work the algorithm must do for a given
 input size. It is NOT about the algorithm being "lucky" once; it
 describes the theoretical floor of operations for the fastest
 possible input arrangement.

 📖 THEORY: (pure English, formal)

 - DEFINITION:
   The Best Case Running Time of an algorithm is the MINIMUM number
   of operations it performs over ALL possible inputs of a given size n.
   It represents the most favorable arrangement of input data.

 - KEY POINTS:
   1. Best case is a THEORETICAL lower bound — it tells you the
      absolute minimum time an algorithm needs.
   2. It is NOT the same as "fastest real-world performance" because
      the best-case input may never actually occur in practice.
   3. Best case is useful for establishing the RANGE of an algorithm's
      performance alongside Average and Worst case.
   4. For Linear Search: best case = target is the FIRST element.
   5. For Insertion Sort: best case = array is already sorted.
   6. Best case is expressed using Big-Omega notation: Ω(f(n)).

 - ASCII DIAGRAM:

   Input of size n = 5: [ TARGET | ? | ? | ? | ? ]
                         ^
                         Found in 1 comparison!
                         This is BEST CASE.

   Compare with other cases:

   BEST CASE:    [ X |   |   |   |   ]  → 1 comparison  (X at index 0)
   AVERAGE CASE: [   |   | X |   |   ]  → ~3 comparisons
   WORST CASE:   [   |   |   |   | X ]  → 5 comparisons  (X at index 4)
                                    or not found → 5 comparisons

 - WHEN TO USE / WHY IT MATTERS:
   * Best case analysis is used in adversarial analysis and
     competitive programming (input can be crafted to be favorable).
   * It helps you understand the full spectrum of performance:
     Best ≤ Average ≤ Worst.
   * Some algorithms have best case much better than worst case
     (e.g., Insertion Sort: best = O(n), worst = O(n²)).

 🧠 LOGIC — STEP BY STEP:

 Step 1: Identify the operation that gets repeated.
         WHY: For linear search, the repeated operation is a comparison
         between the current element and the target.

 Step 2: Determine the BEST possible input arrangement.
         WHY: For linear search, the target sitting at index 0 means
         we compare once and return immediately.

 Step 3: Count the number of operations in that best arrangement.
         WHY: One comparison = constant work = O(1). This is the
         absolute minimum the algorithm can do.

 Step 4: Express as a function of n.
         WHY: Best case for linear search = 1 comparison regardless
         of n → constant time → O(1).

 VISUAL WALKTHROUGH:

 Array: [10, 20, 30, 40, 50], Target = 10

 Step 1: Compare arr[0] with target
         10 == 10?  YES! → Return index 0
         Comparisons so far: 1

         [10 | 20 | 30 | 40 | 50]
          ^
         Match! Done in 1 step.

 No further steps needed. Best case achieved.

 DRY RUN (full trace):

 Searching for 10 in {10, 20, 30, 40, 50}

 i=0: arr[0]=10, target=10 → MATCH → comparisons=1 → RETURN 0

 Total comparisons = 1
 This is the minimum possible for any search.

 TIME COMPLEXITY CALCULATION:

   For linear search, best case:
   - The target is at index 0.
   - Number of comparisons = 1.
   - 1 is a constant → does NOT grow with n.
   - Therefore: Best Case = Ω(1) = constant time.

   General pattern for best case:
   - If algorithm does c comparisons where c is a fixed constant
     regardless of n → best case = O(1).
   - If best case depends on n (e.g., binary search on sorted array
     first element → still O(1) because comparison is O(1)).

   → Best Case Time Complexity = Ω(1)

 SPACE COMPLEXITY CALCULATION:

   - Linear search uses a fixed number of variables (index i,
     comparison count).
   - No extra memory that scales with n.
   - → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────┬────────────┬────────────┬────────────┐
 │    Algorithm      │ Best Case  │ Avg Case   │ Worst Case │
 ├──────────────────┼────────────┼────────────┼────────────┤
 │ Linear Search    │ Ω(1)       │ Θ(n)       │ O(n)       │
 │ Insertion Sort   │ Ω(n)       │ Θ(n²)      │ O(n²)      │
 │ Binary Search    │ Ω(1)       │ Θ(log n)   │ O(log n)   │
 │ Bubble Sort      │ Ω(n)       │ Θ(n²)      │ O(n²)      │
 └──────────────────┴────────────┴────────────┴────────────┘
*/

#include <iostream>
using namespace std;

// linear search with comparison counter
int linearSearchBestCase(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// insert at end vs insert at front demo
void insertAtEnd(int arr[], int &n, int value, int &ops) {
    // best case: insert at end — no shifting needed
    ops = 1; // sirf ek assignment
    arr[n] = value;
    n++;
}

void insertAtFront(int arr[], int &n, int value, int &ops) {
    // worst case: insert at front — shift everything right
    ops = 0;
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
        ops++;
    }
    arr[0] = value;
    n++;
    ops++; // final assignment bhi count karo
}

int main() {
    cout << "============================================================" << endl;
    cout << "   BEST CASE RUNNING TIME — DEMO" << endl;
    cout << "============================================================" << endl;

    // --- Demo 1: Linear Search Best Case ---
    cout << "\n--- DEMO 1: Linear Search — Target at Index 0 ---" << endl;
    int arr1[] = {7, 14, 21, 28, 35};
    int n1 = 5;
    int comparisons = 0;

    cout << "Array: [";
    for (int i = 0; i < n1; i++) {
        if (i > 0) cout << ", ";
        cout << arr1[i];
    }
    cout << "]" << endl;

    int target1 = 7; // target is at index 0 — best case!
    cout << "Target: " << target1 << " (at index 0 — BEST CASE)" << endl;

    int result1 = linearSearchBestCase(arr1, n1, target1, comparisons);
    cout << "Found at index: " << result1 << endl;
    cout << "Comparisons made: " << comparisons << " (constant!)" << endl;
    cout << "Best Case = O(1) → constant time" << endl;

    // --- Demo 2: Insert at End vs Insert at Front ---
    cout << "\n--- DEMO 2: Array Insertion — Best Case vs Worst Case ---" << endl;
    int arr2[10] = {10, 20, 30, 40, 50};
    int n2 = 5;
    int ops = 0;

    // best case: insert at end
    cout << "\nBefore: [";
    for (int i = 0; i < n2; i++) {
        if (i > 0) cout << ", ";
        cout << arr2[i];
    }
    cout << "]" << endl;

    insertAtEnd(arr2, n2, 60, ops);
    cout << "Insert 60 at END:" << endl;
    cout << "After:  [";
    for (int i = 0; i < n2; i++) {
        if (i > 0) cout << ", ";
        cout << arr2[i];
    }
    cout << "]" << endl;
    cout << "Operations: " << ops << " (BEST CASE — no shifting needed!)" << endl;

    // worst case: insert at front
    int arr3[10] = {10, 20, 30, 40, 50};
    int n3 = 5;
    insertAtFront(arr3, n3, 5, ops);
    cout << "\nInsert 5 at FRONT:" << endl;
    cout << "After:  [";
    for (int i = 0; i < n3; i++) {
        if (i > 0) cout << ", ";
        cout << arr3[i];
    }
    cout << "]" << endl;
    cout << "Operations: " << ops << " (WORST CASE — all elements shifted!)" << endl;

    // --- Demo 3: Edge cases ---
    cout << "\n--- DEMO 3: Edge Cases ---" << endl;

    // empty array
    int emptyArr[5];
    int emptyN = 0;
    int emptyComp = 0;
    int emptyResult = linearSearchBestCase(emptyArr, emptyN, 5, emptyComp);
    cout << "Empty array search: result=" << emptyResult << ", comparisons=" << emptyComp << endl;

    // single element — best case IS also worst case
    int singleArr[] = {42};
    int singleN = 1;
    int singleComp = 0;
    int singleTarget = 42;
    int singleResult = linearSearchBestCase(singleArr, singleN, singleTarget, singleComp);
    cout << "Single element [42], search 42: result=" << singleResult
         << ", comparisons=" << singleComp << " (only possible case)" << endl;

    // element not found — not best case
    int notFoundArr[] = {1, 2, 3, 4, 5};
    int nfComp = 0;
    int nfResult = linearSearchBestCase(notFoundArr, 5, 99, nfComp);
    cout << "Element 99 not found: result=" << nfResult << ", comparisons=" << nfComp << " (not best case!)" << endl;

    cout << "\n============================================================" << endl;
    cout << " BEST CASE SUMMARY: Minimum operations for best input." << endl;
    cout << " Linear Search Best Case = O(1) — target at first position." << endl;
    cout << "============================================================" << endl;

    return 0;
}
