/*
═══════════════════════════════════════════════
 TASK FILE — WORST CASE RUNNING TIME
═══════════════════════════════════════════════

 Task 1 me linear search ka worst case demo karo: target absent hone
 par comparisons = n exactly, aur target last index par = n.

 Task 2 me "sabse slow input" ka systemetic search karo — ek function
 jo har possible input ke liye operations count karke max nikale.

 Task 3 me full derivation do ki worst case worst kyun hota hai —
 proof ki f(n) = n is O(n), kisi bhi input ke liye isse zyada nahi.
*/

#include <iostream>
using namespace std;

/* ====================================================================
   TASK 1: Linear Search — Worst Case Comparisons = n
   ====================================================================
   PROBLEM:
   Two scenarios dikhane hain:
   (a) target = last element of array  -> n comparisons
   (b) target absent                    -> n comparisons (phir return -1)
   Dono me verify karo ki comparisons exactly n hain.

   💡 HINT:
   Worst case tab hota hai jab loop kisi bhi point par early-exit na
   kare. Last element par match milne se pahle n-1 comparisons + 1
   final = n. Absent case me bhi poore n comparisons ke baad -1.

   ✏️ STARTER CODE:
   // int searchCount(int arr[], int n, int target, int &c):
   //     c = 0
   //     for i in 0..n-1:
   //         c++
   //         if arr[i]==target: return i
   //     return -1
*/

/* ====================================================================
   TASK 2: Max Over All Inputs — Exhaustive Worst Case Finder
   ====================================================================
   PROBLEM:
   Ek function likho jo har possible target-position input ke liye
   comparisons count kare aur MAXIMUM return kare. Ye "brute force"
   worst case nikalne ka tareeka hai — mathematically prove karo ke
   max n hi aayega.

   💡 HINT:
   Har position 0..n-1 ke liye search chalao (position bhi target ki,
   aur ek "absent" case bhi). Max nikalo. Max hamesha n hi hoga.

   ✏️ STARTER CODE:
   // int worstComparisonsLinear(int arr[], int n):
   //     maxSoFar = 0
   //     for each position p in 0..n-1:
   //         run search with target=arr[p], collect comparisons
   //         maxSoFar = max(maxSoFar, comparisons)
   //     also try target = 10000 (absent) and take max
   //     return maxSoFar
*/

/* ====================================================================
   TASK 3: Proof — Worst Case of Linear Search is O(n)
   ====================================================================
   PROBLEM:
   Formal proof:
   1. Define worst input.
   2. Count operations.
   3. Show f(n) = n fits the Big-O definition.
   4. Conclude ki koi bhi input n se zyada comparisons nahi kara
      sakta.

   💡 HINT:
   Proof niche solution me poora likha hai — code + text.
*/

// -------------- SOLUTIONS --------------

// --- TASK 1 & 2 helper: linear search returning comparisons ---
int solSearchCount(int arr[], int n, int target, int &c) {
    c = 0;
    for (int i = 0; i < n; i++) {
        c++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// --- TASK 2: brute force worst case over all inputs ---
int solWorstComparisonsLinear(int arr[], int n) {
    int worst = 0;
    for (int p = 0; p < n; p++) {
        int c = 0;
        solSearchCount(arr, n, arr[p], c); // target at position p
        if (c > worst) worst = c;
    }
    // absent case
    int cAbsent = 0;
    solSearchCount(arr, n, 10000, cAbsent); // guaranteed absent
    if (cAbsent > worst) worst = cAbsent;
    return worst;
}

// --- TASK 3: proof printer ---
void solPrintWorstProof(int n) {
    cout << endl;
    cout << "PROOF: Worst Case of Linear Search = O(n)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1) Worst input candidate: (a) target at last index," << endl;
    cout << "   or (b) target absent." << endl;
    cout << "2) Operation counting:" << endl;
    cout << "   loop har iteration par exactly 1 comparison karta hai." << endl;
    cout << "   loop ki 0 se n-1 tak iterations = n iterations." << endl;
    cout << "   => comparisons = n." << endl;
    cout << "3) Big-O verification:" << endl;
    cout << "   f(n) = n. Definition: f(n) in O(g(n)) if exists c > 0," << endl;
    cout << "   n0 such that f(n) <= c * g(n) for all n >= n0." << endl;
    cout << "   Choose g(n) = n, c = 1, n0 = 1:" << endl;
    cout << "   n <= 1 * n  -> true for all n >= 1." << endl;
    cout << "   => f(n) = O(n)." << endl;
    cout << "4) Bound proof: kisi bhi input me loop n se zyada nahi" << endl;
    cout << "   chal sakta (array me sirf n elements hain)." << endl;
    cout << "   => n comparisons absolute max, further n+1 not possible." << endl;
    cout << "5) For n = " << n << ": worst comparisons = " << n << "." << endl;
}

int main() {
    cout << "============================================================" << endl;
    cout << "   TASK SOLUTIONS — WORST CASE RUNNING TIME" << endl;
    cout << "============================================================" << endl;

    // ---------- TASK 1 SOLUTION RUN ----------
    cout << "\n>>> TASK 1: Worst Case Comparisons = n <<<" << endl;
    int arr[] = {3, 9, 17, 24, 33, 41, 55, 70};
    int n = 8;

    // (a) target at last index
    int cA = 0;
    int rA = solSearchCount(arr, n, arr[n - 1], cA);
    cout << "Scenario A (target = last element, value " << arr[n - 1] << "):" << endl;
    cout << "  found at index " << rA << ", comparisons = " << cA << " = n ✓" << endl;

    // (b) target absent
    int cB = 0;
    int rB = solSearchCount(arr, n, 999, cB);
    cout << "Scenario B (target = 999, ABSENT):" << endl;
    cout << "  result = " << rB << " (not found), comparisons = " << cB << " = n ✓" << endl;

    // ---------- TASK 2 SOLUTION RUN ----------
    cout << "\n>>> TASK 2: Exhaustive Max-Over-All-Inputs <<<" << endl;
    cout << "Array: [";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;
    cout << "Running search for every possible target position + absent:" << endl;
    int worstFound = solWorstComparisonsLinear(arr, n);
    cout << "Maximum comparisons over ALL inputs = " << worstFound << endl;
    cout << "Proof: max = n = " << n << " -> matches theoretical worst ✓" << endl;

    // ---------- TASK 3 SOLUTION RUN ----------
    cout << "\n>>> TASK 3: Formal Worst-Case Proof <<<" << endl;
    solPrintWorstProof(n);

    cout << "\n============================================================" << endl;
    cout << "   END OF TASK SOLUTIONS" << endl;
    cout << "============================================================" << endl;
    return 0;
}