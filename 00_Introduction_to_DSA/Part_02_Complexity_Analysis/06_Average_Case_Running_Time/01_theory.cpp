/*
═══════════════════════════════════════════════
 AVERAGE CASE RUNNING TIME
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are looking for your friend in a long queue of 100
 people. You don't know where they are — they could be anywhere
 from the front to the back. On average, you'd expect to check
 about 50 people before finding them. That is "Average Case
 Running Time" — not the best scenario, not the worst, but the
 EXPECTED performance when you consider every possible position
 equally likely. Average case tells you: "If I run this algorithm
 a million times with random inputs, how many steps would I EXPECT
 to take each time?"

 📖 THEORY: (pure English, formal)

 - DEFINITION:
   The Average Case Running Time is the EXPECTED number of operations
   an algorithm performs, averaged over ALL possible inputs of size n,
   assuming each input is equally likely to occur.

 - KEY POINTS:
   1. Average case gives the most REALISTIC measure of performance
      for random inputs.
   2. For linear search with target present at random position:
      Average comparisons = (1 + 2 + 3 + ... + n) / n = (n+1)/2.
   3. This simplifies to O(n/2) = O(n) — same order as worst case,
      but the CONSTANT factor is half.
   4. Average case assumes uniform distribution — if some inputs are
      more likely, the average changes.
   5. Calculating average case requires listing ALL inputs and their
      costs, then computing the weighted mean.

 - ASCII DIAGRAM:

   Array of size n, target at each position with equal probability:

   Position 0:  comparisons = 1  (prob = 1/n)
   Position 1:  comparisons = 2  (prob = 1/n)
   Position 2:  comparisons = 3  (prob = 1/n)
   ...
   Position n-1: comparisons = n  (prob = 1/n)

   Average = (1/n) * [1 + 2 + 3 + ... + n]
           = (1/n) * [n(n+1)/2]
           = (n+1)/2

   For n = 100:
   Average comparisons = (100 + 1) / 2 = 50.5

   For n = 1000:
   Average comparisons = (1000 + 1) / 2 = 500.5

 - WHEN TO USE:
   * Average case analysis is used in REAL performance estimation.
   * Algorithm designers use it to predict real-world speed.
   * It's the standard metric in randomized algorithm analysis.
   * Compare: Best case = too optimistic, Worst case = too pessimistic,
     Average case = just right for most practical purposes.

 🧠 LOGIC — STEP BY STEP:

 Step 1: List ALL possible inputs for size n.
         WHY: We need to consider every scenario to compute the average.
         For linear search, the "input" is the position of the target:
         {0, 1, 2, ..., n-1}.

 Step 2: For each input, count the number of comparisons.
         WHY: Position i requires (i+1) comparisons — we compare each
         element from index 0 up to index i.

 Step 3: Assign equal probability to each input (1/n).
         WHY: Without additional information, we assume each position
         is equally likely. This is the "uniform distribution" assumption.

 Step 4: Compute the weighted average.
         WHY: Average = Sum(comparisons_i * probability_i) for all i.
         = Sum[(i+1) * (1/n)] for i = 0 to n-1
         = (1/n) * Sum[i+1] for i = 0 to n-1
         = (1/n) * (1 + 2 + ... + n)
         = (1/n) * n(n+1)/2
         = (n+1)/2

 Step 5: Express in Big-O notation.
         WHY: (n+1)/2 = n/2 + 1/2 -> the dominant term is n/2.
         Dropping constant factors gives O(n).

 VISUAL WALKTHROUGH:

 Searching for target in array [2, 5, 7, 10, 15]:

 All possible target positions and comparisons:

 Position 0: arr[0]=2     -> comparisons = 1
 Position 1: arr[1]=5     -> comparisons = 2
 Position 2: arr[2]=7     -> comparisons = 3
 Position 3: arr[3]=10    -> comparisons = 4
 Position 4: arr[4]=15    -> comparisons = 5

 Average = (1 + 2 + 3 + 4 + 5) / 5 = 15 / 5 = 3.0
 Formula check: (n+1)/2 = (5+1)/2 = 3   ✓

 DRY RUN (full line-by-line trace):

 Example: n = 5, compute average comparisons by running the search
 for EVERY possible target position and averaging.

 Position 0: target=2  -> comparisons=1
 Position 1: target=5  -> comparisons=2
 Position 2: target=7  -> comparisons=3
 Position 3: target=10 -> comparisons=4
 Position 4: target=15 -> comparisons=5

 Total comparisons = 1 + 2 + 3 + 4 + 5 = 15
 Average = 15 / 5 = 3.0
 Expected: (n+1)/2 = (5+1)/2 = 3.0   ✓

 TIME COMPLEXITY CALCULATION:

   Derivation:
   - Sum of first n integers = n(n+1)/2
   - Average = [n(n+1)/2] / n = (n+1)/2
   - (n+1)/2 = n/2 + 1/2

   Big-O: Drop lower-order terms and constants:
   - n/2 is the dominant term
   - Drop the constant 1/2
   - Average Case = O(n)

   Big-Omega: At least 1 comparison is always needed:
   - Average Case = Omega(1)

   Theta: Average case is Theta(n) — it grows linearly.

   -> Average Case Time Complexity = Theta(n)

 SPACE COMPLEXITY CALCULATION:

   - Linear search uses fixed extra space: loop variable, comparison
     counter, return value.
   - No arrays, no recursion stack, no dynamic memory.
   - Space does NOT change regardless of input size.
   - -> Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────┬────────────┬────────────┬────────────┐
 │    Algorithm      │ Best Case  │ Avg Case   │ Worst Case │
 ├──────────────────┼────────────┼────────────┼────────────┤
 │ Linear Search    │ Omega(1)   │ Theta(n)   │ O(n)       │
 │ Binary Search    │ Omega(1)   │ Theta(log n)│ O(log n)  │
 │ Insertion Sort   │ Omega(n)   │ Theta(n^2) │ O(n^2)     │
 │ Bubble Sort      │ Omega(n)   │ Theta(n^2) │ O(n^2)     │
 │ Merge Sort       │ Omega(nlogn)│ Theta(nlogn)│ O(nlogn) │
 └──────────────────┴────────────┴────────────┴────────────┘
   Note: For Linear Search, average case = (n+1)/2 comparisons,
   which is HALF the worst case — but still the same order O(n).
*/

#include <iostream>
using namespace std;

// linear search with explicit comparisons count
int linearSearch(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++; // har element par ek comparison
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// simple sum helper: 1 + 2 + ... + n
int sumFirstN(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) s += i;
    return s;
}

int main() {
    cout << "============================================================" << endl;
    cout << "   AVERAGE CASE RUNNING TIME - DEMO" << endl;
    cout << "   Linear Search: Average Comparisons = (n+1)/2" << endl;
    cout << "============================================================" << endl;

    // --- Demo 1: Run search across ALL target positions 0..n-1 ---
    int n = 5;
    int arr[] = {2, 5, 7, 10, 15};
    int totalComparisons = 0;

    cout << "\nArray: [";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "], n = " << n << endl;

    cout << "\n--- Searching for EVERY possible target position ---" << endl;
    for (int pos = 0; pos < n; pos++) {
        int comparisons = 0;
        int target = arr[pos]; // target ko har position par rakho
        int result = linearSearch(arr, n, target, comparisons);
        cout << "  Target " << target << " at index " << result
             << " -> comparisons = " << comparisons << endl;
        totalComparisons += comparisons;
    }

    double average = (double)totalComparisons / n;
    cout << "\nTotal comparisons = " << totalComparisons << endl;
    cout << "Average comparisons = " << totalComparisons << " / " << n
         << " = " << average << endl;
    cout << "Expected formula (n+1)/2 = " << (n + 1) / 2.0 << endl;
    cout << "Check: average == (n+1)/2 ? -> "
         << ((average == (n + 1) / 2.0) ? "YES ✓" : "NO") << endl;

    // --- Demo 2: Larger n to show the trend (n = 16) ---
    cout << "\n--- Demo 2: n = 16, uniform distribution average ---" << endl;
    int n2 = 16;
    int total2 = sumFirstN(n2); // 1+2+...+16 = 136
    double avg2 = (double)total2 / n2;
    cout << "Total comparisons (sum 1..16) = " << total2 << endl;
    cout << "Average = 136 / 16 = " << avg2 << endl;
    cout << "Formula (16+1)/2 = " << (16 + 1) / 2.0 << "  ✓ match" << endl;

    // --- Demo 3: Edge cases ---
    cout << "\n--- Demo 3: Edge Cases ---" << endl;

    // n = 1 -> average = (1+1)/2 = 1
    int n3 = 1;
    cout << "n = 1 -> average = (1+1)/2 = " << (n3 + 1) / 2.0
         << " (target hi ek element hai)" << endl;

    // n = 2 -> average = 1.5
    int n4 = 2;
    cout << "n = 2 -> average = (2+1)/2 = " << (n4 + 1) / 2.0
         << " (positions 0 and 1 -> comparisons 1 and 2)" << endl;

    // large n comparison: formula vs loop
    int n5 = 1000;
    double loopAvg = (double)sumFirstN(n5) / n5;
    double formulaAvg = (n5 + 1) / 2.0;
    cout << "n = 1000 -> loop avg = " << loopAvg
         << ", formula avg = " << formulaAvg
         << " -> match: " << ((loopAvg == formulaAvg) ? "YES ✓" : "NO") << endl;

    cout << "\n============================================================" << endl;
    cout << " AVERAGE CASE SUMMARY: Linear Search = (n+1)/2 comparisons " << endl;
    cout << " = O(n). Same order as worst case, half the constant.    " << endl;
    cout << "============================================================" << endl;

    return 0;
}