/*
═══════════════════════════════════════════════
 POINTERS + ARRAYS (Name Decay, arr[i]==*(arr+i), Function Passing)
 ⏱️ TIME COMPLEXITY: access arr[i] O(1), find/sum O(N), two-pointer reverse O(N)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You give a delivery person a list of addresses. The physical list never
 moves — instead you hand over the FIRST address, and they can read all
 addresses by walking forward one by one. In C++, an array name is exactly
 that: it "decays" into a pointer to the first element. Passing "the whole
 array" to a function never actually copies it — just the starting address.

 📖 THEORY: (pure English, beginner-level)
 - An array name arr behaves as a pointer to its first element: &arr[0].
 - arr[i] is identical to *(arr + i). Compiler does this translation.
 - Passing an array to a function passes a POINTER (start address) — no copy.
 - You can index a pointer: p[2] works on pointers too.
 - POINTERS and ARRAYS differ: sizeof(arr) = whole array size;
   sizeof(p) = fixed pointer size (8 bytes). Arrays cannot be reassigned;
   pointers can point anywhere.

 ASCII — arr decays to pointer:
   int arr[5] = {7, 14, 21, 28, 35};

   arr  (array name)  →  &arr[0]
   ┌──────────────────────────────────────────────┐
   │  7   14   21   28   35                        │
   └──────────────────────────────────────────────┘
     ▲    ▲    ▲    ▲    ▲
     p    p+1  p+2  p+3  p+4        (p = arr)

   arr[2]  ==  *(arr + 2)  ==  *(p + 2)  ==  p[2]  ==  21
   (0x...A)  (0x...A + 2*4)
   Index n → p+n skips n*sizeof(int) bytes.

 WHEN TO USE:
 - Passing arrays to functions (most C++ APIs work this way)
 - Two-pointer techniques (reverse, palindrome, sliding window)
 - Iterating when you need to know memory layout
 - Function pointers and callbacks in dynamic dispatch

 🧠 LOGIC — STEP BY STEP (Pass array to function):
 Step 1: Function signature: int sum(int* arr, int n) OR int sum(int arr[], int n)
         WHY: both are the SAME — compiler treats the parameter as a pointer.
 Step 2: Loop arr[0..n-1] and add. WHY: pointer decay gives us access
         to the same memory without copying.
 Step 3: Return sum. WHY: caller's array untouched, value returned.

 VISUAL WALKTHROUGH — Reverse via two pointers:
 int a[5] = {1, 2, 3, 4, 5};
 left=0, right=4:
 Step 1: swap a[0] ↔ a[4] → {5, 2, 3, 4, 1}
 Step 2: swap a[1] ↔ a[3] → {5, 4, 3, 2, 1}
 Step 3: left==right (2) → stop. The center stays in its place.

 DRY RUN — array sum via pointer (arr = {2,4,6}, n=3):
 p=arr  sum=0
 p:  sum += *p = 2 → sum=2; p++
 p:  sum += *p = 4 → sum=6; p++
 p:  sum += *p = 6 → sum=12; p++
 p == end (arr+3) → stop
 Result: 12

 TIME COMPLEXITY CALCULATION:
 - Indexing arr[i]: single memory access, constant work = 1 → O(1)
 - Array sum: loop runs N times, each add is O(1) → work = N → O(N)
 - Reverse via two pointers: N/2 swaps, each O(1) → work = N/2 → O(N)
 → Time Complexity = O(1) per element, O(N) for full-array passes

 SPACE COMPLEXITY CALCULATION:
 - The array itself: N * sizeof(int).
 - Passing to function: ONE pointer (8 bytes) copied, NOT N elements.
   No extra array allocated anywhere.
 - Two-pointer reverse: two int indexes, constant.
 → Space Complexity = O(1) extra (beyond the array itself)

 APPROACH COMPARISON:
 ┌─────────────────────┬─────────────────────────┬──────────────────────────────┐
 │ Aspect              │ Array (arr[])          │ Pointer (int* p)             │
 ├─────────────────────┼─────────────────────────┼──────────────────────────────┤
 │ sizeof              │ N * sizeof(int)        │ sizeof(void*) = 8 fixed      │
 │ Reassign             │ ERROR (fixed name)    │ p = anytime/anywhere OK      │
 │ Pass to function    │ decays → pointer       │ passes the address directly  │
 │ Indexing            │ arr[i]                 │ p[i] / *(p+i) both work      │
 │ arr == &arr[0]      │ true when passed       │ explicit                      │
 └─────────────────────┴─────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
using namespace std;

// Function array pointer leta hai — par koi copy NAHI hoti
// signature int sumArr(int arr[], int n) ek jaisi hi hai
int sumArray(int* arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];          // same as *(arr + i)
    }
    return s;
}

// Reverse using two pointers (left, right)
void reverseArr(int* arr, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;      // swap
        left++;
        right--;
    }
}

int main() {

    // ═══════════════════════════════════════════
    // DEMO 1: arr[i] vs *(arr + i)
    // ═══════════════════════════════════════════
    cout << "=== DEMO 1: arr[i] == *(arr+i) ===" << endl;

    int arr[5] = {7, 14, 21, 28, 35};
    int* p = arr;    // decay: &arr[0]

    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "]=" << arr[i]
             << "   *(arr+" << i << ")=" << *(arr + i)
             << "    *(p+" << i << ")=" << *(p + i)
             << "   p[" << i << "]=" << p[i] << endl;
    }
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 2: Array name decay proof — &arr[0] == arr
    // ═══════════════════════════════════════════
    cout << "=== DEMO 2: Decay Proof ===" << endl;
    cout << "arr      = " << arr << endl;
    cout << "&arr[0]  = " << &arr[0] << "   (same address!)" << endl;
    cout << "*(arr+0) = " << *(arr + 0) << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 3: Pass array to function (no copy!)
    // ═══════════════════════════════════════════
    cout << "=== DEMO 3: Pass Array to Function ===" << endl;

    int big[5] = {1, 2, 3, 4, 5};
    cout << "sumArray(big, 5) = " << sumArray(big, 5) << endl;
    cout << "Goto address of big in function = sirf pointer gaya, "
         << "5 ints copy NAHI hue." << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 4: sizeof difference — array vs pointer
    // ═══════════════════════════════════════════
    cout << "=== DEMO 4: sizeof(arr) vs sizeof(p) ===" << endl;

    cout << "sizeof(arr) = " << sizeof(arr) << "  (5 * 4 bytes)" << endl;
    cout << "sizeof(p)   = " << sizeof(p) << "  (pointer fixed size)" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 5: Reverse via two pointers (in-place)
    // ═══════════════════════════════════════════
    cout << "=== DEMO 5: Reverse with Two Pointers ===" << endl;

    int rev[5] = {1, 2, 3, 4, 5};
    cout << "Before: ";
    for (int x : rev) cout << x << " ";
    cout << endl;

    reverseArr(rev, 5);

    cout << "After:  ";
    for (int x : rev) cout << x << " ";
    cout << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: Empty array (n=0) safety
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: Empty Array ===" << endl;

    int* empty = nullptr;
    cout << "sumArray(empty, 0) = " << sumArray(empty, 0) << endl;
    cout << "reverseArr(empty, 0) — loop kabhi shuru nahi hota, safe" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: Single element reverse
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: Single Element ===" << endl;

    int one[1] = {42};
    cout << "Before reverse: " << one[0] << endl;
    reverseArr(one, 1);
    cout << "After  reverse: " << one[0] << " (koi change nahi — sahi hai)" << endl;

    // Bonus: pointer reassignment allowed (array reassign is NOT)
    int* q = arr;
    q = &one[0];   // pointer redirect ho sakta hai
    cout << "\n*q ab = " << *q << "  (pointer doosri jagah point kar raha hai)" << endl;

    return 0;
}