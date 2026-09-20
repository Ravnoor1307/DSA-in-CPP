/*
═══════════════════════════════════════════════
 TASK SET — 1-D ARRAYS
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
  A teacher's student marks live in one flat list. Every task is a list-based
  question: total, average, min-max, the index of some roll number, reversing
  the whole list, the second topper, or rotating the whole list.

 🧠 HOW TO SOLVE:
  Indexing starts at 0. Traversing = a loop of 0..n-1. For in-place changes,
  modify arr[i] directly (when an array is passed it decays into a pointer —
  so pass the size along with it).

  MODES/TOPICS COVERED:
   1. Sum of array
   2. Average (as double)
   3. Max & Min (one pass for both)
   4. Linear search (return index)
   5. Reverse in-place
   6. Second largest (single pass)
   7. Left rotate by k

  ═══════════════════════════════════════════════
   TASK 1 (EASY) — Sum of array
   {1, 2, 3, 4, 5} -> 15
   💡 HINT: total = 0; keep adding every element in the loop.
   ✏️ STARTER CODE (description): int sumArray(int arr[], int n) {
       int t = 0; for (int i = 0; i < n; i++) t += arr[i]; return t; }

   TASK 2 (EASY) — Average (as double)
   💡 HINT: divide sum by n as a double — "sum / n" does integer division
       (the fraction gets cut off). Don't forget the cast.
   ✏️ STARTER CODE (description): double avg = (double)sumArray(arr, n) / n;
       return avg. If n == 0 return 0 (no division by zero).

   TASK 3 (MEDIUM) — Max & Min (one pass for both)
   💡 HINT: minVal = maxVal = arr[0]; check/update both in the loop.
       Use reference parameters (int &mn, int &mx) for the output.
   ✏️ STARTER CODE (description): void fillMinMax(int arr[], int n, int &mn,
       int &mx) { mn = mx = arr[0]; for i=1..n-1 update both; }

   TASK 4 (MEDIUM) — Linear search (return index)
   In {10, 20, 30, 40}, 30 -> index 2; 99 -> -1.
   💡 HINT: loop 0..n-1; if arr[i] == target, return i immediately.
   ✏️ STARTER CODE: // int linearSearch(int arr[], int n, int target) {
       //   for (int i = 0; i < n; i++) if (arr[i] == target) return i;
       //   return -1;
       // }

   TASK 5 (MEDIUM) — Reverse in-place
   {1,2,3,4} -> {4,3,2,1}. Don't create an extra array (O(1) space is required).
   💡 HINT: swap arr[i] ↔ arr[n-1-i], only up to i < n/2.
   ✏️ STARTER CODE: // void reverseInPlace(int arr[], int n) {
       //   for (int i = 0; i < n / 2; i++) {
       //     int temp = arr[i]; arr[i] = arr[n-1-i]; arr[n-1-i] = temp;
       //   }
       // }

   TASK 6 (HARD) — Second largest (single pass)
   {12, 35, 1, 10, 34, 1} -> 34. If there are not two distinct elements,
   return INT_MIN.
   💡 HINT: maintain both largest and secondLargest together:
       if arr[i] > largest, the old largest becomes second.
   ✏️ STARTER CODE (description): int l = arr[0], sl = INT_MIN (include <climits>);
       for i=1..n-1: if arr[i] > l { sl = l; l = arr[i]; } else if (arr[i] > sl
       && arr[i] != l) { sl = arr[i]; }

   TASK 7 (HARD) — Left rotate by k
   {1,2,3,4,5}, k=2 -> {3,4,5,1,2}. First do k = k % n (to handle k>n).
   💡 HINT: First copy the first k elements into temp, left-shift the rest,
       then paste temp back at the end.
   ✏️ STARTER CODE (description): void leftRotate(int arr[], int n, int k);
       k %= n; if k==0 or n==0 return. copy temp[k]; shift; paste at the end.
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <climits>
using namespace std;

// print helper
void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

// TASK 1 — sum
int sumArray(int arr[], int n) {
    int t = 0;
    for (int i = 0; i < n; i++) t += arr[i];
    return t;
}

// TASK 2 — average (double cast essential)
double averageArray(int arr[], int n) {
    if (n == 0) return 0.0;                    // edge: 0 se divide nahi
    return (double)sumArray(arr, n) / n;       // cast — warna integer divide
}

// TASK 3 — min & max ek pass me, reference params ke through
void fillMinMax(int arr[], int n, int &mn, int &mx) {
    mn = mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
}

// TASK 4 — linear search index
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// TASK 5 — reverse in-place (n/2 swaps)
void reverseInPlace(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

// TASK 6 — second largest (single pass)
int secondLargest(int arr[], int n) {
    if (n < 2) return INT_MIN;                 // do elements hi chahiye minimum
    int largest = arr[0], second = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;                  // purana largest demote
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];                   // beech ka candidate
        }
    }
    return second;
}

// TASK 7 — left rotate by k (O(k) temp, O(n) time)
void leftRotate(int arr[], int n, int k) {
    if (n == 0) return;
    k = k % n;                                 // k > n ho to normalize
    if (k == 0) return;
    int temp[100];                             // pehle k elements ki copy
    for (int i = 0; i < k; i++) temp[i] = arr[i];
    for (int i = k; i < n; i++) arr[i - k] = arr[i];   // baaki left shift
    for (int i = 0; i < k; i++) arr[n - k + i] = temp[i]; // temp end me daalo
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "TASK 1 — sum ";
    printArray(a, n);
    cout << " = " << sumArray(a, n) << endl;

    cout << "TASK 2 — average ";
    printArray(a, n);
    cout << " = " << averageArray(a, n) << endl;

    int mn, mx;
    fillMinMax(a, n, mn, mx);
    cout << "TASK 3 — min = " << mn << ", max = " << mx << endl;

    cout << "TASK 4 — index of 30: " << linearSearch(a, n, 30)
         << " (absent -> -1) | index of 3: " << linearSearch(a, n, 3) << endl;

    reverseInPlace(a, n);
    cout << "TASK 5 — reverse -> ";
    printArray(a, n);
    cout << endl;
    reverseInPlace(a, n);                      // wapas original

    int b[] = {12, 35, 1, 10, 34, 1};
    cout << "TASK 6 — second largest of ";
    printArray(b, 6);
    cout << " = " << secondLargest(b, 6) << endl;

    leftRotate(a, n, 2);
    cout << "TASK 7 — left rotate by 2 -> ";
    printArray(a, n);
    cout << endl;

    cout << "\n===== EDGE CASES =====\n";
    int single[1] = {7};
    cout << "single sum = " << sumArray(single, 1)
         << ", avg = " << averageArray(single, 1) << endl;
    reverseInPlace(single, 1);
    cout << "reverse single -> ";
    printArray(single, 1);
    cout << endl;
    leftRotate(single, 1, 5);
    cout << "rotate single by 5 -> ";
    printArray(single, 1);
    cout << "  (k%n = 0, same rehna chahiye)" << endl;
    cout << "avg of empty (n=0) = " << averageArray(a, 0)
         << "  (safe 0 — divide avoided)" << endl;
    cout << "secondLargest of single = " << secondLargest(single, 1)
         << "  (INT_MIN = " << INT_MIN << ")" << endl;
    return 0;
}