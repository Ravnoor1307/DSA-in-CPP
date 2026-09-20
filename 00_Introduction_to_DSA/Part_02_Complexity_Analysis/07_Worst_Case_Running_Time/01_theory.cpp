/*
═══════════════════════════════════════════════
 WORST CASE RUNNING TIME
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are looking for a specific pair of shoes in a huge shoe
 store with 200 boxes on the wall. Now imagine that your size is NOT
 in stock at all — you must check EVERY single box before concluding
 it's missing. That is "Worst Case Running Time" — the absolute
 slowest the algorithm can possibly be for a given input size. Worst
 case analysis is the safest guarantee you can give: "No matter what
 input you throw at me, I will finish within this many steps." For
 linear search, the worst case is checking all n elements (target at
 the last position, or not present at all).

 📖 THEORY: (pure English, formal)

 - DEFINITION:
   The Worst Case Running Time of an algorithm is the MAXIMUM number
   of operations it performs over ALL possible inputs of size n. It is
   the upper bound on time — the algorithm can NEVER take longer.

 - KEY POINTS:
   1. Worst case is the most important metric in competitive
      programming and real-time systems — it gives a hard guarantee.
   2. For linear search: worst case = n comparisons — either target is
      at the last index, or target is ABSENT.
   3. Expressed using Big-O: worst case = O(n). (Upper bound)
   4. Worst case can be triggered by: bad input arrangement, target
      missing, decreasing sequence (for sorting), etc.
   5. Some algorithms don't have a "fully bad" input — e.g., selection
      sort always does the same number of comparisons: n(n-1)/2.

 - ASCII DIAGRAM:

   Array of size n, target at the END or ABSENT:

   [  |  |  |  | X]   index n-1  -> n comparisons  (at end)
   [  |  |  |  |  ]   target absent -> n comparisons + 1 final check

   vs BEST case (1 comparison):
   [X |  |  |  |  ]   index 0 -> 1 comparison

   For n = 100:
     Worst case comparisons = 100
     Best case comparisons  = 1
     Average case           = 50.5

 - WHEN TO USE:
   * Worst case is used when you MUST give a guarantee (network
     routing, air traffic control, deadline systems).
   * Standard interview metric — everyone quotes worst case first.
   * Adversarial inputs (an attacker choosing the worst input) require
     worst-case analysis for security.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Identify the operation being repeated.
         WHY: For linear search it is the comparison
         arr[i] == target.

 Step 2: Find the input that forces MAXIMUM repetitions.
         WHY: Target at last position (n comparisons) or target absent
         (n comparisons + 1 final -1 return). Both give n steps.

 Step 3: Count operations for that input.
         WHY: The loop body runs n times because no early exit happens
         until (or never) the final element.

 Step 4: Express as a function of n.
         WHY: Exactly n comparisons -> f(n) = n -> linear -> O(n).

 VISUAL WALKTHROUGH:

 Array: [3, 9, 17, 24, 33, 41], Target = 99 (NOT present)

 Step 1: compare 3  == 99? no (count=1)
 Step 2: compare 9  == 99? no (count=2)
 Step 3: compare 17 == 99? no (count=3)
 Step 4: compare 24 == 99? no (count=4)
 Step 5: compare 33 == 99? no (count=5)
 Step 6: compare 41 == 99? no (count=6)
 Loop ends -> return -1.

 Total comparisons = 6 = n  (WORST CASE, target absent)

 DRY RUN (full trace):

 Searching for target 10 in array where target is LAST element:

 arr = {1, 2, 3, 4, 10}, target = 10

 i=0: arr[0]=1  != 10 -> comparisons=1
 i=1: arr[1]=2  != 10 -> comparisons=2
 i=2: arr[2]=3  != 10 -> comparisons=3
 i=3: arr[3]=4  != 10 -> comparisons=4
 i=4: arr[4]=10 == 10 -> comparisons=5, return index 4

 Total comparisons = 5 = n  (WORST CASE, target at last index)

 TIME COMPLEXITY CALCULATION:

   Worst case linear search (target at last index or absent):
   - Loop runs for i = 0 to n-1 (n iterations) with one comparison each.
   - Total comparisons = n.
   - f(n) = n.
   - By Big-O definition: f(n) <= c * g(n) for n >= n0.
     Take c = 1, g(n) = n, n0 = 1: n <= 1 * n -> true for all n >= 1.
   - Therefore f(n) = O(n).
   - Also worst case is the upper bound: no input takes more than n
     comparisons, so worst case exactly = n = Θ(n) (since best case
     for that specific scenario class is also n).
   - -> Worst Case Time Complexity = O(n)

 SPACE COMPLEXITY CALCULATION:

   - Linear search uses only fixed variables (i, target, comparisons).
   - No extra arrays, no recursion stack (iterative), no dynamic memory.
   - Space usage is independent of input size n.
   - -> Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────┬─────────────────┬─────────────────┬──────────────┐
 │   Case           │ Input           │ Comparisons     │ Big-O       │
 ├──────────────────┼─────────────────┼─────────────────┼──────────────┤
 │ BEST             │ target at idx 0 │ 1               │ Ω(1)        │
 │ AVERAGE          │ target anywhere │ (n+1)/2         │ Θ(n)        │
 │ WORST            │ target last/absent │ n            │ O(n)        │
 └──────────────────┴─────────────────┴─────────────────┴──────────────┘

   Linear vs Binary (worst cases):
 ┌──────────────┬──────────────┬──────────────┐
 │ Algorithm    │ Worst Compare│ Worst Case   │
 ├──────────────┼──────────────┼──────────────┤
 │ Linear Search│ n            │ O(n)         │
 │ Binary Search│ log2(n)      │ O(log n)     │
 └──────────────┴──────────────┴──────────────┘
*/

#include <iostream>
using namespace std;

// linear search with comparisons counter
int linearSearchWorstCase(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // not found
}

// worst case proof for selection sort: n(n-1)/2 comparisons always
int selectionSortComparisons(int n) {
    return n * (n - 1) / 2; // always fixed
}

int main() {
    cout << "============================================================" << endl;
    cout << "   WORST CASE RUNNING TIME - DEMO" << endl;
    cout << "============================================================" << endl;

    // --- Demo 1: Target ABSENT (worst case) ---
    int n = 6;
    int arr[] = {3, 9, 17, 24, 33, 41};
    int comparisons = 0;

    cout << "\n--- DEMO 1: Target Absent (Worst Case) ---" << endl;
    cout << "Array: [";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;

    int target = 99; // not present
    cout << "Target: " << target << " (NOT present -> worst case)" << endl;

    int result = linearSearchWorstCase(arr, n, target, comparisons);
    cout << "Result: " << result << " (not found)" << endl;
    cout << "Comparisons made: " << comparisons << " = n = " << n << endl;
    cout << "Worst Case = O(n) -> checked every single element." << endl;

    // --- Demo 2: Target at LAST index (also worst case) ---
    cout << "\n--- DEMO 2: Target at Last Index ---" << endl;
    int arr2[] = {3, 9, 17, 24, 33, 41};
    int n2 = 6;
    int target2 = arr2[n2 - 1]; // last element
    int comparisons2 = 0;
    cout << "Array: [";
    for (int i = 0; i < n2; i++) {
        if (i > 0) cout << ", ";
        cout << arr2[i];
    }
    cout << "]" << endl;
    cout << "Target: " << target2 << " (last element -> worst case)" << endl;

    int result2 = linearSearchWorstCase(arr2, n2, target2, comparisons2);
    cout << "Found at index: " << result2 << endl;
    cout << "Comparisons made: " << comparisons2 << " = n = " << n2 << endl;
    cout << "Worst Case = O(n)" << endl;

    // --- Demo 3: Edge cases ---
    cout << "\n--- DEMO 3: Edge Cases ---" << endl;

    // empty array
    int emptyArr[5];
    int nE = 0;
    int compE = 0;
    int resE = linearSearchWorstCase(emptyArr, nE, 5, compE);
    cout << "Empty array: result=" << resE << ", comparisons=" << compE << endl;

    // single element, not present
    int singleArr[] = {7};
    int compS = 0;
    int resS = linearSearchWorstCase(singleArr, 1, 99, compS);
    cout << "Single element [7], search 99 (absent): result=" << resS
         << ", comparisons=" << compS << " (worst = best = n = 1)" << endl;

    // ----- Selection sort: worst case = ALL cases (fixed comparisons) -----
    int nS = 8;
    cout << "\nSelection Sort ke liye comparisons FIXED hain:" << endl;
    cout << "n = " << nS << " -> " << selectionSortComparisons(nS)
         << " comparisons (har input par same = " << nS * (nS - 1) / 2
         << " = n(n-1)/2)" << endl;
    cout << "So worst = average = best = O(n^2)" << endl;

    cout << "\n============================================================" << endl;
    cout << " WORST CASE SUMMARY: Linear Search = n comparisons = O(n)." << endl;
    cout << " Hard upper bound: koi input bhi isse zyada time nahi lega." << endl;
    cout << "============================================================" << endl;

    return 0;
}