/*
═══════════════════════════════════════════════
 TASK SET — OPERATIONS ON DATA STRUCTURES
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 A library keeps the list of available books. Every morning the librarian
 must check if a book is on the shelf (search), add newly arrived books
 (insertion), remove sold-out books (deletion), first show the newest ones
 (search again after sorting), and merge two shelf lists into one. Each
 chore is a data-structure operation with its own cost.

🧠 HOW TO SOLVE:
 - Arrays here are fixed-capacity; keep a separate live `size` counter.
 - Search = linear scan (compare each element).
 - Insert = place at end (O(1)) or at an index (shift right first).
 - Delete = find index, then shift everything after it one step left.
 - Minimum = walk once keeping the smallest; merge = two-pointer scan.
 - Print after every change so you can verify counts stay correct.

 TASK 1: (EASY) Find the minimum value
   In an array of 6 numbers, find and print the smallest element.
   💡 HINT: assume arr[0] is min, then compare each arr[i].
   ✏️ STARTER CODE:
     int findMin(int a[], int n) {
         int mn = a[0];
         // TODO: loop i=1..n-1, if a[i] < mn, mn = a[i]
         return mn;
     }
     // main: int arr[] = {3,1,4,1,5,9}; n=6 → expect 1

 TASK 2: (EASY) Insert at the END
   Add a given value to the END of an array (no shifting needed) and
   print the new array with its new size.
   💡 HINT: arr[size] = value; size++.
   ✏️ STARTER CODE:
     void insertEnd(int a[], int &n, int val) {
         // TODO: place at a[n], then n++
     }

 TASK 3: (MEDIUM) Insert at a GIVEN index
   Insert a value at a chosen index — shift everything right first.
   💡 HINT: shift from the BACK to the front so you don't overwrite.
   ✏️ STARTER CODE:
     void insertAt(int a[], int &n, int idx, int val) {
         // TODO: shift a[i]=a[i-1] for i=n down to idx+1; then a[idx]=val; n++
     }
     // array {1,2,3}: insert 99 at index 1 → {1,99,2,3}

 TASK 4: (MEDIUM) Delete an element BY VALUE
   Find the first occurrence of a value, delete it by shifting left.
   💡 HINT: reuse a search loop to get idx; then shift a[idx+i] left.
   ✏️ STARTER CODE:
     void deleteVal(int a[], int &n, int val) {
         // TODO: find idx, if found shift left and n--
     }

 TASK 5: (MEDIUM) Count how many times a value appears
   Count occurrences of a value in the array.
   💡 HINT: counter++; loop for every match.
   ✏️ STARTER CODE:
     int countOccur(int a[], int n, int val) {
         int c = 0;
         // TODO: count matches
         return c;
     }

 TASK 6: (HARD) Merge two sorted arrays
   Merge two already-sorted arrays into a third sorted array (no gaps,
   no extra sorting) and print it.
   💡 HINT: two pointers i (on a) and j (on b); take the smaller of
   a[i], b[j] each time.
   ✏️ STARTER CODE:
     void mergeSorted(int a[], int na, int b[], int nb, int res[]) {
         int i=0, j=0, k=0;
         // TODO: while i<na && j<nb pick smaller; then drain leftovers
     }
     // a={1,3,5} b={2,4,6} → res={1,2,3,4,5,6}

═══════════════════════════════════════════════
 DIAGRAM OF TEST ARRAY USED:
   before:  [ 20 | 10 | 40 | 30 | 50 ]   size = 5
   search 40 → 2        insert 99 end → size 6
   delete 30 → [ 20 | 10 | 40 | 50 | 99 ] size 5
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <string>
using namespace std;

// saathi: har print ke baad array aur size dikhana
void printArr(int a[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "] (size=" << n << ")" << endl;
}

// TASK 1: minimum value
int findMin(int a[], int n) {
    int mn = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < mn) mn = a[i];
    }
    return mn;
}
// Explanation: pehle ko min maan lo, phir har element se compare;
// jo chota ho use min bana lo. Ek hi loop → O(n).

// TASK 2: end mein insert
void insertEnd(int a[], int &n, int val) {
    a[n] = val;
    n++;
}
// Explanation: a[n] naya khaali slot hai; wahan rakho aur size badhao.
// Koi shifting nahi → O(1).

// TASK 3: index pe insert (shift right)
void insertAt(int a[], int &n, int idx, int val) {
    for (int i = n; i > idx; i--) {
        a[i] = a[i - 1];         // peeche se aage ki taraf kheench
    }
    a[idx] = val;                // slot ab khaali hai, value daalo
    n++;
}
// Explanation: pichhe se shift karo taaki aage ke values overwrite na
// ho jayein. Sab elements idx ke baad ek step right → O(n).

// TASK 4: value se delete (shift left)
void deleteVal(int a[], int &n, int val) {
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == val) { idx = i; break; }   // pehli occurrence
    }
    if (idx == -1) return;
    for (int i = idx; i < n - 1; i++) {
        a[i] = a[i + 1];         // aage wale peeche kheench
    }
    n--;
}
// Explanation: find index phir baaki sab ek step left — gap bharna.
// Search O(n) + shift O(n) → O(n).

// TASK 5: kitni baar aaya
int countOccur(int a[], int n, int val) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == val) c++;
    }
    return c;
}
// Explanation: har match pe counter badhao → O(n).

// TASK 6: two sorted arrays merge
void mergeSorted(int a[], int na, int b[], int nb, int res[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            res[k++] = a[i++];   // a ka chhota element le lo
        } else {
            res[k++] = b[j++];   // warna b ka
        }
    }
    while (i < na) res[k++] = a[i++];   // a ke bache hue
    while (j < nb) res[k++] = b[j++];   // b ke bache hue
}
// Explanation: dono pointers har step pe chhota element uthate hain;
// ek khatam ho jaye to doosre ke bache hue seedhe copy. O(a+b).

int main() {
    int arr[10];
    arr[0] = 20; arr[1] = 10; arr[2] = 40; arr[3] = 30; arr[4] = 50;
    int size = 5;

    cout << "Task 1 — Min: " << findMin(arr, size) << endl;   // 10

    cout << "Task 2 — Insert 99 at end: ";
    insertEnd(arr, size, 99);
    printArr(arr, size);                                      // ...99 size=6

    cout << "Task 3 — Insert 7 at index 2: ";
    insertAt(arr, size, 2, 7);
    printArr(arr, size);                                      // 20 10 7 40 30 50 99

    cout << "Task 4 — Delete 40: ";
    deleteVal(arr, size, 40);
    printArr(arr, size);                                      // 20 10 7 30 50 99

    cout << "Task 5 — Count of 7: " << countOccur(arr, size, 7) << endl;  // 1

    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int res[6];
    mergeSorted(a, 3, b, 3, res);
    cout << "Task 6 — Merged: ";
    printArr(res, 6);                                         // 1 2 3 4 5 6

    // Edge cases
    int single[] = {42};
    cout << "Edge — single array min: " << findMin(single, 1) << endl;      // 42
    int e1[] = {1}, e2[] = {2}, er[2];
    mergeSorted(e1, 1, e2, 1, er);
    cout << "Edge — merge singles: ";
    printArr(er, 2);                                          // 1 2

    return 0;
}

// ⏱ Time: Task1/2 (O(n)/O(1)); Task3/4 (O(n)); Task5 (O(n));
//          Task6 (O(a+b)).
// 🧠 Space: sab array pe kaam, extra O(1) hi — res ke alawa O(a+b).