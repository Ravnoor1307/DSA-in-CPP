/*
═══════════════════════════════════════════════
 TASK SET — POINTERS WITH ARRAYS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A delivery fleet tracks parcel weights (an array).
    The operations — total weight, heaviest parcel, sorting routes — are
    all done by passing a POINTER to the first parcel, never copying
    the list.

 🧠 HOW TO SOLVE: Arrays decay to pointers in functions. Use arr[i] or
    *(arr+i) interchangeably. Two-pointer tricks for reversing / sorting
    in place.

 MODES/TOPICS COVERED:
  1. Array sum via a function
  2. Find the largest element
  3. Reverse the array in place (two pointers)
  4. Count occurrences of a value
  5. Selection sort using pointers
  6. Two Sum on a sorted array using pointers
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════
// TASK 1: Array sum
// ═══════════════════════════════════════════
// arr[i] pointer indexing hai — *(arr+i)
int sumArr(int* arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

// ═══════════════════════════════════════════
// TASK 2: Largest element
// ═══════════════════════════════════════════
// pehle element se max start karo, baaki se compare
int largest(int* first, int n) {
    int mx = *first;             // first[0]
    for (int i = 1; i < n; i++) {
        if (first[i] > mx) mx = first[i];
    }
    return mx;
}

// ═══════════════════════════════════════════
// TASK 3: Reverse in place
// ═══════════════════════════════════════════
// left-right pointers content swap karte hain, beech tak
void reverseInPlace(int* a, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int t = a[left];
        a[left] = a[right];
        a[right] = t;
        left++;
        right--;
    }
}

// ═══════════════════════════════════════════
// TASK 4: Count occurrences
// ═══════════════════════════════════════════
// har element se target match karke count badhao
int countOcc(int* a, int n, int target) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) cnt++;
    }
    return cnt;
}

// ═══════════════════════════════════════════
// TASK 5: Selection sort via pointers
// ═══════════════════════════════════════════
// har position i ke liye minimum ka index dhundo, phir swap
void selectionSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        int t = a[i];
        a[i] = a[minIdx];
        a[minIdx] = t;
    }
}

// ═══════════════════════════════════════════
// TASK 6: Two sum on sorted array
// ═══════════════════════════════════════════
// sorted hai isliye dono ends se chalo — left small, right bada
void twoSum(int* a, int n, int target) {
    int left = 0, right = n - 1;
    while (left < right) {
        int cur = a[left] + a[right];
        if (cur == target) {
            cout << "Pair: (" << a[left] << ", " << a[right] << ")" << endl;
            return;
        } else if (cur < target) {
            left++;    // sum chhota hai → left ko badao
        } else {
            right--;   // sum bada hai → right ko ghatado
        }
    }
    cout << "No such pair found." << endl;
}

// ═══════════════════════════════════════════
// DRIVER
// ═══════════════════════════════════════════
int main() {

    // --- Task 1 ---
    cout << "=== TASK 1: Array Sum ===" << endl;
    int a1[] = {1, 2, 3, 4, 5};
    cout << "sumArr([1..5], 5) = " << sumArr(a1, 5) << endl;
    cout << endl;

    // --- Task 2 ---
    cout << "=== TASK 2: Largest ===" << endl;
    int a2[] = {34, 12, 78, 5, 90, 11};
    cout << "largest = " << largest(a2, 6) << endl;
    cout << endl;

    // --- Task 3 ---
    cout << "=== TASK 3: Reverse In-Place ===" << endl;
    int a3[] = {1, 2, 3, 4, 5};
    cout << "Before: ";
    for (int x : a3) cout << x << " ";
    reverseInPlace(a3, 5);
    cout << "\nAfter:  ";
    for (int x : a3) cout << x << " ";
    cout << endl << endl;

    // --- Task 4 ---
    cout << "=== TASK 4: Count Occurrences ===" << endl;
    int a4[] = {3, 1, 3, 7, 3, 9, 3};
    cout << "3 occurs " << countOcc(a4, 7, 3) << " times" << endl;
    cout << endl;

    // --- Task 5 ---
    cout << "=== TASK 5: Selection Sort ===" << endl;
    int a5[] = {64, 25, 12, 22, 11};
    cout << "Before: ";
    for (int x : a5) cout << x << " ";
    selectionSort(a5, 5);
    cout << "\nAfter:  ";
    for (int x : a5) cout << x << " ";
    cout << endl << endl;

    // --- Task 6 ---
    cout << "=== TASK 6: Two Sum ===" << endl;
    int a6[] = {1, 3, 5, 7, 9};
    cout << "Looking for target 10 in [1,3,5,7,9]: ";
    twoSum(a6, 5, 10);
    cout << "Looking for target 99: ";
    twoSum(a6, 5, 99);
    cout << endl;

    // --- EDGE: empty & single element ---
    cout << "=== EDGE CASES ===" << endl;
    int one[] = {7};
    cout << "sumArr({7},1)   = " << sumArr(one, 1) << endl;
    cout << "largest({7},1)  = " << largest(one, 1) << endl;
    cout << "largest(ptr,0) — NULL check: ";
    int* np = nullptr;
    if (np == nullptr) cout << "skip kiya (null array)" << endl;

    return 0;
}