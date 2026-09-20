/*
═══════════════════════════════════════════════
 TASK FILE — BINARY SEARCH — LOG₂n PROOF
═══════════════════════════════════════════════

 Task 1 me RECURSIVE binary search implement karna hai with step
 counter, aur verify karna hai ki steps ≤ log₂(n).

 Task 2 me n=1024 ke liye maximum steps count karo (simulate + proof)
 aur linear se compare karo.

 Task 3 me poora formal proof do: proof ki binary search O(log n) hai,
 with the n/2^k = 1 derivation. (STAR task — poora derivation likho.)
*/

#include <iostream>
#include <cmath>
using namespace std;

/* ====================================================================
   TASK 1: Recursive Binary Search With Step Counter
   ====================================================================
   PROBLEM:
   Recursive binary search likho jo har call par steps++ kare. Ek
   sorted array par demo karo aur check karo ki steps kabhi bhi
   log₂(n) se zyada nahi hote.

   💡 HINT:
   Recursive call ka pattern: array ko divide karke ek half par call.
   Recursive depth = number of steps = log₁(n). Steps ko reference
   variable se count karo.

   ✏️ STARTER CODE:
   // int bSearchRec(int arr[], int low, int high, int target, int &steps):
   //     steps++
   //     if low > high: return -1
   //     mid = low + (high - low) / 2
   //     if arr[mid] == target: return mid
   //     if arr[mid] < target: return bSearchRec(arr, mid+1, high, target, steps)
   //     else: return bSearchRec(arr, low, mid-1, target, steps)
*/

/* ====================================================================
   TASK 2: Steps For n = 1024 — Prove & Compare
   ====================================================================
   PROBLEM:
   n = 1024 ke liye maximum binary steps kitne hain? (a) Theoretical
   proof se, (b) actual loop simulation se. Phir linear search se
   compare karo: 1024 vs 10 steps.

   💡 HINT:
   1024 = 2¹⁰, isliye log₂(1024) = 10. Simulation me size loop karo:
   while(size > 1) size = (size+1)/2, steps++.

   ✏️ STARTER CODE:
   // int maxStepsByHalving(int n):
   //     steps = 0
   //     while n > 1: n = (n+1)/2; steps++
   //     return steps
*/

/* ====================================================================
   TASK 3: THE FORMAL PROOF — Binary Search is O(log n)
   ====================================================================
   PROBLEM:
   Pura derivation likho:
   1. Har step par search space aadha hota hai: n → n/2 → n/4 → ...
   2. After k steps: size = n / 2^k
   3. Stop condition: n / 2^k = 1
   4. n = 2^k  →  take log₂ both sides  →  k = log₂(n)
   5. Conclude O(log n). Space bhi derive karo (iterative O(1),
      recursive O(log n)).

   💡 HINT:
   Full proof code me print karwao + README-ready text. Use log2
   function for verification.

   ✏️ STARTER CODE:
   // void printFormalProof(int n):
   //     print all derivation steps
   //     verify using cmath log2: log2(n)
*/

// -------------- SOLUTIONS --------------

// TASK 1: recursive binary search with step counter
int solBSRec(int arr[], int low, int high, int target, int &steps) {
    steps++;
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return solBSRec(arr, mid + 1, high, target, steps);
    }
    return solBSRec(arr, low, mid - 1, target, steps);
}

// TASK 2: maximum steps by simulating halving
int solMaxStepsByHalving(int n) {
    int steps = 0;
    while (n > 1) {
        n = (n + 1) / 2; // ceil halving — remaining elements
        steps++;
    }
    return steps;
}

// TASK 2 helper: linear worst comparisons
int solLinearWorst(int n) {
    return n; // absent target -> n comparisons
}

// TASK 3: formal proof printer
void solPrintFormalProof(int n) {
    cout << endl;
    cout << "THE FORMAL PROOF — Binary Search is O(log n)" << endl;
    cout << "================================================" << endl;
    cout << "1) Halving invariant:" << endl;
    cout << "   Har step search space ka SIZE aadha kar deta hai." << endl;
    cout << "   Step 0 -> n, Step 1 -> n/2, Step 2 -> n/4, ..." << endl;
    cout << "   After k steps -> size = n / 2^k" << endl;
    cout << endl;
    cout << "2) Termination condition:" << endl;
    cout << "   Search tab rukta hai jab sirf 1 element bachta hai" << endl;
    cout << "   (ya 0 — not found). Toh:" << endl;
    cout << "       n / 2^k  =  1" << endl;
    cout << "   Multiply dono sides ko 2^k se:" << endl;
    cout << "       n = 2^k" << endl;
    cout << "   Dono sides ka log₂ lo:" << endl;
    cout << "       log₂(n) = log₂(2^k)" << endl;
    cout << "       log₂(n) = k" << endl;
    cout << "   =>  k = log₂(n)" << endl;
    cout << endl;
    cout << "3) Therefore worst-case steps = log₂(n)." << endl;
    cout << "   Har step par O(1) kaam (1 comparison + pointer update)." << endl;
    cout << "   Total = O(1) * log₂(n) = O(log n)." << endl;
    cout << endl;
    cout << "4) Verification for n = " << n << ":" << endl;
    cout << "   halving simulation steps = " << solMaxStepsByHalving(n) << endl;
    cout << "   log2(" << n << ") = " << (int)log2(n) << endl;
    cout << "   max steps (ceil for non-powers) = "
         << solMaxStepsByHalving(n) << " = ceil(log2(" << n << "))" << endl;
}

// -------------- main --------------
int main() {
    cout << "============================================================" << endl;
    cout << "   TASK SOLUTIONS — BINARY SEARCH — LOG₂n PROOF" << endl;
    cout << "============================================================" << endl;

    // ---------- TASK 1 SOLUTION RUN ----------
    cout << "\n>>> TASK 1: Recursive Binary Search + Step Counter <<<" << endl;
    int n1 = 64;
    int arr[64];
    for (int i = 0; i < 64; i++) arr[i] = i * 2; // evens 0..126
    cout << "Sorted array size " << n1 << " = evens 0..126" << endl;
    cout << "log2(" << n1 << ") = 6 -> max allowed steps = 6" << endl;

    // test on several targets
    int testTargets[] = {0, 64, 90, 126, 127, 7};
    for (int t : testTargets) {
        int steps1 = 0;
        int r1 = solBSRec(arr, 0, n1 - 1, t, steps1);
        cout << "  target " << t << " -> index " << r1
             << ", steps " << steps1 << " (limit 6) "
             << (steps1 <= 6 ? "OK ✓" : "OVER ✗") << endl;
    }

    // ---------- TASK 2 SOLUTION RUN ----------
    cout << "\n>>> TASK 2: n = 1024 — Steps = 10 vs Linear 1024 <<<" << endl;
    int N = 1024;
    int binSteps2 = solMaxStepsByHalving(N);
    cout << "n = " << N << " = 2^10" << endl;
    cout << "(a) Halving simulation max steps      = " << binSteps2 << endl;
    cout << "(b) Theory: log2(1024) = 10           = 10" << endl;
    cout << "    (dono match: " << (binSteps2 == 10 ? "YES ✓" : "NO") << ")" << endl;
    cout << "Linear search worst comparisons for n=1024 = "
         << solLinearWorst(N) << endl;
    cout << "IMPROVEMENT: " << N << " / " << binSteps2 << " = "
         << N / (double)binSteps2 << "x faster (absent target)" << endl;
    cout << "Even n=1,000,000: binary ~" << solMaxStepsByHalving(1000000)
         << " steps only!" << endl;

    // ---------- TASK 3 SOLUTION RUN ----------
    cout << "\n>>> TASK 3: The Formal O(log n) Proof <<<" << endl;
    solPrintFormalProof(1024);

    cout << "\n============================================================" << endl;
    cout << "   END OF TASK SOLUTIONS" << endl;
    cout << "   k = log2(n); space: iterative O(1), recursive O(log n)" << endl;
    cout << "============================================================" << endl;
    return 0;
}