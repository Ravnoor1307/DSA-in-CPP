/*
═══════════════════════════════════════════════
 TASK FILE — BEST CASE RUNNING TIME
═══════════════════════════════════════════════

 Task 1 me array insertion ka BEST CASE nikalna hai: insert at end
 (koi shifting nahi) vs insert at front (sab shifting). Analysis karo
 ki operations kyun constant hain end case me.

 Task 2 me ek custom function likhna hai jo return kare BEST case me
 minimum comparisons, chahe input kuch bhi ho — ek generic search ka
 best case simulate karo.

 Task 3 me derivations ka poora proof do: kyun best case = O(1) jab
 target sabse pehle element hai.

 Complete solve karo — har task me full code + derivation.
*/

#include <iostream>
using namespace std;

/* ====================================================================
   TASK 1: Array Insertion — Best Case (Insert at End vs Insert at Front)
   ====================================================================
   PROBLEM:
   Ek array hai size n. Insert-at-end me operations count karo,
   insert-at-front me operations count karo. Compare karke kaho
   best case kya hai aur kyun.

   💡 HINT:
   Insert at end pe pichle elements ko move karne ki zaroorat nahi.
   Insert at front pe har element ko ek step right shift karna padta
   hai — wo n operations leta hai.

   ✏️ STARTER CODE:
   // insertAtEnd(arr, n, value, ops):
   //     arr[n] = value; n++; ops++  // sirf ek assignment

   // insertAtFront(arr, n, value, ops):
   //     for i from n down to 1: arr[i] = arr[i-1]; ops++
   //     arr[0] = value

   // main(): dono cases ke liye operations print karo
*/

/* ====================================================================
   TASK 2: Minimum Comparisons Finder — Generic Search Best Case
   ====================================================================
   PROBLEM:
   Ek generic search function likho jo FIRST matching element par rukta
   ho. Function ko ek flag do "forceBestCase" jo target ko index 0 par
   rakh ke search kare. Verify karo ki comparisons hamesha 1 rehta hai.

   💡 HINT:
   Target ko pehle element se initialize karo (ya swap karke index 0
   par le aao). Jab loop sirf first iteration kare, total comparisons
   exactly 1 hoga — best case ka proof demo.

   ✏️ STARTER CODE:
   // int genericSearch(int arr[], int n, int target, int &comparisons):
   //     comparisons = 0
   //     for i in 0..n-1:
   //         comparisons++
   //         if arr[i] == target: return i
   //     return -1
*/

/* ====================================================================
   TASK 3: Proof — Best Case for Linear Search is O(1)
   ====================================================================
   PROBLEM:
   Derivation dene hai:
   1. Best-case input kya hota hai?
   2. Kitne comparisons?
   3. Mathematical form me dikhao ki constant hai.
   4. Ek README-ready proof likho.
   NOTE: is task me derivation likhni hai — code optional hai.
   Neche solution me poora proof likha hai.
*/

// -------------- SOLUTIONS --------------

// --- TASK 1 SOLUTION: Insert at End vs Insert at Front ---
void solInsertAtEnd(int arr[], int &n, int value, int &ops) {
    // end par insert → koi shifting nahi
    arr[n] = value;
    n++;
    ops = 1; // sirf ek assignment operation
}

void solInsertAtFront(int arr[], int &n, int value, int &ops) {
    // front par insert → sab elements shift karna padega
    ops = 0;
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1]; // right shift
        ops++;               // har shift ek operation
    }
    arr[0] = value;
    n++;
    ops++; // final assignment bhi count karo
}

// --- TASK 2 SOLUTION: Generic search with comparisons counter ---
int solGenericSearch(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// TASK 3 ki derivation — code se nahi, proof se — niche upar/neche text me
void solPrintBestCaseProof() {
    cout << endl;
    cout << "PROOF: Linear Search Best Case = O(1)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Best-case input: target at index 0" << endl;
    cout << "Comparisons needed: exactly 1" << endl;
    cout << "Mathematical form:" << endl;
    cout << "  f(n) = 1   (constant, n par depend nahi karta)" << endl;
    cout << "  Since f(n) = 1 for ALL n >= 0," << endl;
    cout << "  f(n) is bounded by a constant c = 1." << endl;
    cout << "  By definition of Big-Omega:" << endl;
    cout << "  f(n) = Ω(g(n)) if f(n) >= c * g(n) for n >= n0" << endl;
    cout << "  Choose g(n) = 1, c = 1, n0 = 0:" << endl;
    cout << "  1 >= 1 * 1  → true for all n" << endl;
    cout << "  Therefore f(n) = Ω(1) → Best Case = O(1)" << endl;
    cout << "  Interpretation: it takes CONSTANT time in best case." << endl;
}

int main() {
    cout << "============================================================" << endl;
    cout << "   TASK SOLUTIONS — BEST CASE RUNNING TIME" << endl;
    cout << "============================================================" << endl;

    // ---------- TASK 1 SOLUTION RUN ----------
    cout << "\n>>> TASK 1: Insert at End vs Insert at Front <<<" << endl;
    int arrE[10] = {10, 20, 30, 40, 50};
    int nE = 5;
    int opsE = 0;
    solInsertAtEnd(arrE, nE, 60, opsE);
    cout << "\nINSERT AT END (value 60):" << endl;
    cout << "  Array after: [";
    for (int i = 0; i < nE; i++) {
        if (i > 0) cout << ", ";
        cout << arrE[i];
    }
    cout << "]" << endl;
    cout << "  Operations: " << opsE << endl;
    cout << "  Derivation: best case ke liye elements ko shift nahi karna." << endl;
    cout << "  f(n) = 1 → O(1) constant. BEST CASE = O(1)." << endl;

    int arrF[10] = {10, 20, 30, 40, 50};
    int nF = 5;
    int opsF = 0;
    solInsertAtFront(arrF, nF, 5, opsF);
    cout << "\nINSERT AT FRONT (value 5):" << endl;
    cout << "  Array after: [";
    for (int i = 0; i < nF; i++) {
        if (i > 0) cout << ", ";
        cout << arrF[i];
    }
    cout << "]" << endl;
    cout << "  Operations: " << opsF << endl;
    cout << "  Derivation: n elements shift ho rahe hain." << endl;
    cout << "  f(n) = n + 1 → O(n). This is the WORST case for insertion." << endl;

    // ---------- TASK 2 SOLUTION RUN ----------
    cout << "\n>>> TASK 2: Generic Search — Force Best Case <<<" << endl;
    int arrG[8] = {5, 10, 15, 20, 25, 30, 35, 40};
    int nG = 8;
    int compsG = 0;

    // force best case: target = arr[0]
    int targetG = arrG[0];
    int resG = solGenericSearch(arrG, nG, targetG, compsG);
    cout << "Array: [";
    for (int i = 0; i < nG; i++) {
        if (i > 0) cout << ", ";
        cout << arrG[i];
    }
    cout << "]" << endl;
    cout << "Target (first element): " << targetG << endl;
    cout << "Found at index: " << resG << endl;
    cout << "Comparisons: " << compsG << "  (always 1 → BEST CASE)" << endl;
    cout << "Proof: pehli iteration me hi match mil gaya." << endl;

    // ---------- TASK 3 SOLUTION RUN ----------
    cout << "\n>>> TASK 3: Proof that Best Case = O(1) <<<" << endl;
    solPrintBestCaseProof();

    cout << "\n============================================================" << endl;
    cout << "   END OF TASK SOLUTIONS" << endl;
    cout << "============================================================" << endl;
    return 0;
}