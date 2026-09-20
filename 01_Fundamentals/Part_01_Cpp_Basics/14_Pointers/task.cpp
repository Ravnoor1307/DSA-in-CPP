/*
═══════════════════════════════════════════════
 TASK SET — Pointers
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A bank updates two account balances in one call;
   a data analyzer finds the max reading across thousands of sensors.
   Both need functions that modify caller data or avoid copying —
   pointers make them fast and direct.
🧠 HOW TO SOLVE: Capture addresses with &, read/write with *. For arrays,
   pointer arithmetic arr+i == &arr[i]. Always null-check before deref.
═══════════════════════════════════════════════

TASK 1 (EASY): Swap Two Values via Pointers
   Write swap(int* a, int* b) that swaps the values at both addresses.
   Hint: temp = *a; *a = *b; *b = temp; — dereference karke swap.
   // STARTER CODE:
   // void swapPtr(int* a, int* b) { ... }

TASK 2 (EASY): Find Max Element
   Return the maximum element of an array using a pointer to walk it.
   Hint: *p se value lo, max update karo, p++ karke aage badho.
   // STARTER CODE:
   // int findMax(int* start, int size) { ... }

TASK 3 (MEDIUM): Value vs Pointer — Square by Pointer
   Write square(int* n) which modifies the value at n to its square.
   Hint: *n = (*n) * (*n); — caller ka data badal jata hai.
   // STARTER CODE:
   // void squarePtr(int* n) { ... }

TASK 4 (MEDIUM): Count Even Numbers
   Count how many even numbers exist in an array — walk with a pointer.
   Hint: *p % 2 == 0 check karo har iteration mein.
   // STARTER CODE:
   // int countEvens(int* start, int size) { ... }

TASK 5 (HARD): Pointer-to-Pointer — Update a String Hello
   Given a char** that points to a char*, change the pointed string.
   Hint: **pp = 'X'; modifies pehla char of the actual string.
   // STARTER CODE:
   // void changeFirst(char** pp, char newCh) { ... }

TASK 6 (HARD): Sum via Pointer Arithmetic
   Compute sum of an array using ONLY pointer arithmetic (arr[i] nahi).
   Hint: while loop end = start+size tak, sum += *start; start++;
   // STARTER CODE:
   // int ptrSum(int* start, int size) { ... }

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════
// TASK 1: Swap via pointers
// ═══════════════════════════════════════════
// temp helper se dono values ko ulta-do
void swapPtr(int* a, int* b) {
    int temp = *a;   // a wale cell ki value bachao
    *a = *b;         // a mein b ki value dalo
    *b = temp;       // b mein purani a ki value dalo
}

// ═══════════════════════════════════════════
// TASK 2: Find max with pointer walk
// ═══════════════════════════════════════════
// p array ke andar chalta hai, har value se compare karta hai
int findMax(int* start, int size) {
    int maxVal = *start;   // pehla element tentative max
    int* p = start;
    for (int i = 0; i < size; i++, p++) {
        if (*p > maxVal) maxVal = *p;
    }
    return maxVal;
}

// ═══════════════════════════════════════════
// TASK 3: Square through pointer
// ═══════════════════════════════════════════
// *n pe likhne se caller ka variable change hota hai
void squarePtr(int* n) {
    *n = (*n) * (*n);   // value ko hi badal diya
}

// ═══════════════════════════════════════════
// TASK 4: Count evens using pointer
// ═══════════════════════════════════════════
// *p % 2 == 0 → even hai, count badhao
int countEvens(int* start, int size) {
    int cnt = 0;
    for (int* p = start; p < start + size; p++) {
        if (*p % 2 == 0) cnt++;
    }
    return cnt;
}

// ═══════════════════════════════════════════
// TASK 5: Change first char via pointer-to-pointer
// ═══════════════════════════════════════════
// *pp = string ka pehla char; **pp char hi hai
void changeFirst(char** pp, char newCh) {
    if (pp != nullptr && *pp != nullptr) {
        **pp = newCh;   // actual string ka pehla char badlo
    }
}

// ═══════════════════════════════════════════
// TASK 6: Sum using ONLY pointer arithmetic
// ═══════════════════════════════════════════
// p ko end tak badhao; *p har baar sum mein jodo
int ptrSum(int* start, int size) {
    int sum = 0;
    int* end = start + size;   // last ke ek aage
    for (int* p = start; p < end; p++) {
        sum += *p;
    }
    return sum;
}

// ═══════════════════════════════════════════
// DRIVER
// ═══════════════════════════════════════════
int main() {

    // --- Task 1: Swap ---
    cout << "=== TASK 1: Swap via Pointers ===" << endl;
    int u = 5, v = 10;
    cout << "Before: u=" << u << " v=" << v << endl;
    swapPtr(&u, &v);
    cout << "After:  u=" << u << " v=" << v << endl;
    cout << endl;

    // --- Task 2: Find max ---
    cout << "=== TASK 2: Find Max ===" << endl;
    int nums[6] = {3, 1, 45, 22, 7, 9};
    cout << "max = " << findMax(nums, 6) << endl;
    cout << endl;

    // --- Task 3: Square ---
    cout << "=== TASK 3: Square via Pointer ===" << endl;
    int val = 7;
    cout << "Before square: " << val << endl;
    squarePtr(&val);
    cout << "After square:  " << val << endl;
    cout << endl;

    // --- Task 4: Count evens ---
    cout << "=== TASK 4: Count Evens ===" << endl;
    int evens[7] = {1, 2, 3, 4, 5, 6, 8};
    cout << "even count = " << countEvens(evens, 7) << endl;
    cout << endl;

    // --- Task 5: Pointer to pointer ---
    cout << "=== TASK 5: Pointer-to-Pointer ===" << endl;
    char word[8] = "hello";
    char* wp = word;      // wp = string
    char** wpp = &wp;     // wpp = address of wp
    cout << "Before: " << word << endl;
    changeFirst(wpp, 'H');
    cout << "After:  " << word << endl;
    cout << endl;

    // --- Task 6: Pointer arithmetic sum ---
    cout << "=== TASK 6: Sum via Pointer Arithmetic ===" << endl;
    int data[5] = {10, 20, 30, 40, 50};
    cout << "ptrSum = " << ptrSum(data, 5) << endl;
    cout << endl;

    // --- EDGE: empty / null handling ---
    cout << "=== EDGE CASES ===" << endl;
    changeFirst(nullptr, 'X');  // null safe — kuch nahi ho ga
    cout << "changeFirst(nullptr, 'X') — no crash, safe skip" << endl;

    int zero[1] = {0};
    cout << "findMax(single element array) = " << findMax(zero, 1) << endl;
    cout << "ptrSum(single element array)  = " << ptrSum(zero, 1) << endl;

    return 0;
}