/*
═══════════════════════════════════════════════
 TASK FILE — AVERAGE CASE RUNNING TIME
═══════════════════════════════════════════════

 Task 1 me linear search ka average case nikalna hai: har possible
 target position (0..n-1) ke liye search lo aur average comparisons
 (n+1)/2 prove karo.

 Task 2 me nested-loop (bubble sort style) ka average comparisons
 count karna hai with derivation.

 Task 3 me poora mathematical proof do ki average case = (n+1)/2,
 with probability sum approach, O(n) tak.
*/

#include <iostream>
using namespace std;

/* ====================================================================
   TASK 1: Linear Search — Average Comparisons (n+1)/2
   ====================================================================
   PROBLEM:
   Ek array lo, har target position 0..n-1 ke liye linear search chalao.
   Saare comparisons ka sum karo aur average nikalo. Prove karo ki
   average = (n+1)/2.

   💡 HINT:
   Position i par target hone par comparisons = i+1. Sum karne par
   (1 + 2 + ... + n) = n(n+1)/2. Average = [n(n+1)/2] / n = (n+1)/2.

   ✏️ STARTER CODE:
   // int linearSearch(int arr[], int n, int target, int &comparisons):
   //     comparisons = 0
   //     for i in 0..n-1:
   //         comparisons++
   //         if arr[i] == target: return i
   //     return -1

   // main():
   //     total = 0
   //     for pos in 0..n-1:
   //         run search with target = arr[pos], count comparisons
   //         total += comparisons
   //     average = total / n
*/

/* ====================================================================
   TASK 2: Bubble Sort — Average Comparisons in Nested Loops
   ====================================================================
   PROBLEM:
   Bubble sort ke inner loop ka total comparison count derive karo.
   Outer loop i=0..n-2; inner loop j=0..n-2-i. Total comparisons
   kya hote hain constant n ke liye? Average case kya hai?

   💡 HINT:
   Total comparisons = sum over i of (n-1-i) from i=0 to n-2
   = (n-1) + (n-2) + ... + 1 = n(n-1)/2. Ye har input ke liye SAME
   hota hai (swaps change hoti hain, comparisons nahi) — is liye
   average = worst = best = n(n-1)/2 = O(n^2).

   ✏️ STARTER CODE:
   // int bubbleComparisons(int n):
   //     total = 0
   //     for i in 0..n-2:
   //         for j in 0..n-2-i:
   //             total++   // comparison count
   //     return total
*/

/* ====================================================================
   TASK 3: Proof — Average Case of Linear Search
   ====================================================================
   PROBLEM:
   Formal mathematical proof likhna hai using probability:
   1. Sample space = {0, 1, ..., n-1} (target position)
   2. Probability of each = 1/n
   3. Expected comparisons = E[X] = sum(x * P(X=x))
   4. Derive (n+1)/2 and show it is O(n).

   💡 HINT:
   E[X] = (1/n)(1 + 2 + ... + n) = (1/n)(n(n+1)/2) = (n+1)/2.
   Pura proof niche solution me likha hai.
*/

// -------------- SOLUTIONS --------------

// --- TASK 1 SOLUTION: Average comparisons via simulation ---
int solLinearSearch(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// --- TASK 2 SOLUTION: Bubble sort inner loop comparison count ---
int solBubbleComparisons(int n) {
    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            total++; // har pair comparison
        }
    }
    return total;
}

// --- TASK 3 SOLUTION: print formal proof ---
void solPrintAverageProof(int n) {
    cout << endl;
    cout << "PROOF: Average Case of Linear Search" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Step 1 — Sample space: target position pos in {0,1,...,n-1}" << endl;
    cout << "Step 2 — Uniform probability: P(pos) = 1/n for every pos" << endl;
    cout << "Step 3 — Cost at position pos: comparisons(pos) = pos + 1" << endl;
    cout << "   (pos 0 -> 1 compare, pos 1 -> 2 compares, ...," << endl;
    cout << "    pos n-1 -> n compares)" << endl;
    cout << "Step 4 — Expected value E[X]:" << endl;
    cout << "   E[X] = sum over all pos of [ cost(pos) * P(pos) ]" << endl;
    cout << "        = (1/n) * [ 1 + 2 + 3 + ... + n ]" << endl;
    cout << "   Sum of first n integers = n(n+1)/2" << endl;
    cout << "        = (1/n) * n(n+1)/2" << endl;
    cout << "        = (n+1)/2" << endl;
    cout << "Step 5 — Big-O form:" << endl;
    cout << "   (n+1)/2 = n/2 + 1/2" << endl;
    cout << "   Dominant term = n/2; drop constant 1/2" << endl;
    cout << "   -> Average Case = O(n)" << endl;
    cout << "Step 6 — For n=1000: E[X] = " << (1000 + 1) / 2.0
         << " comparisons average" << endl;
    cout << "   Note: average is HALF of worst (n=1000) but SAME order." << endl;
}

int main() {
    cout << "============================================================" << endl;
    cout << "   TASK SOLUTIONS — AVERAGE CASE RUNNING TIME" << endl;
    cout << "============================================================" << endl;

    // ---------- TASK 1 SOLUTION RUN ----------
    cout << "\n>>> TASK 1: Linear Search Average (Simulation) <<<" << endl;
    int arr[] = {2, 5, 7, 10, 15, 21, 28, 36};
    int n = 8;
    int total = 0;
    cout << "Array: [";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "], n = " << n << endl;

    cout << "Running search for ALL positions 0.." << n - 1 << ":" << endl;
    for (int pos = 0; pos < n; pos++) {
        int comps = 0;
        int target = arr[pos];
        int result = solLinearSearch(arr, n, target, comps);
        cout << "  target=" << target << " at index " << result
             << " -> comparisons=" << comps << endl;
        total += comps;
    }

    double average = (double)total / n;
    cout << "\nTotal comparisons = " << total << endl;
    cout << "Average = " << total << " / " << n << " = " << average << endl;
    cout << "Formula (n+1)/2 = " << (n + 1) / 2.0 << endl;
    cout << "Match: " << ((average == (n + 1) / 2.0) ? "YES ✓" : "NO") << endl;

    // ---------- TASK 2 SOLUTION RUN ----------
    cout << "\n>>> TASK 2: Bubble Sort Nested Loop Average <<<" << endl;
    int nB = 5;
    int compCount = solBubbleComparisons(nB);
    cout << "For n = " << nB << ":" << endl;
    cout << "nested loops i=0.." << nB - 2 << ", j=0.." << nB - 2 << "-i" << endl;
    cout << "Total comparisons = " << compCount << endl;
    cout << "Formula n(n-1)/2 = " << (nB * (nB - 1)) / 2 << "  ✓" << endl;
    cout << "Derivation: comparisons har pass = n-1-i" << endl;
    cout << "  sum_{i=0}^{n-2} (n-1-i) = (n-1)+(n-2)+...+1 = n(n-1)/2" << endl;
    cout << "Comparisons are FIXED (swaps nahi badalti count) ->" << endl;
    cout << "  Average = Worst = " << nB * (nB - 1) / 2 << " = O(n^2)" << endl;

    // ---------- TASK 3 SOLUTION RUN ----------
    cout << "\n>>> TASK 3: Formal Proof of Average = (n+1)/2 <<<" << endl;
    solPrintAverageProof(1000);

    cout << "\n============================================================" << endl;
    cout << "   END OF TASK SOLUTIONS" << endl;
    cout << "============================================================" << endl;
    return 0;
}