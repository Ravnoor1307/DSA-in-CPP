/*
═══════════════════════════════════════════════
 TASK SET — DYNAMIC MEMORY ALLOCATION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A conference room has 30 fixed chairs. When 80
   people register, the manager brings extra chairs at RUNTIME (heap),
   seats everyone, and then the chairs are removed after the event
   (delete). Resizing = bring MORE chairs, ask everyone to shift to the
   new rows, and throw the old chairs away. Forgetting to remove chairs =
   memory leak that slowly eats the hall.

🧠 HOW TO SOLVE: Every dynamic array lives on the heap and must be freed
   with delete[]. To RESIZE: allocate a NEW bigger buffer, copy elements
   from the old buffer, then delete[] the old one and point to the new.
   Always check new (nothrow) for nullptr, and set pointer to nullptr
   after delete[] to avoid dangling pointers.
═══════════════════════════════════════════════

TASK 1 (EASY): Allocate, Fill, Print, Free
   Read n from user, allocate new (nothrow) int[n], fill with i*i,
   print them, then delete[] correctly.
   // STARTER CODE:
   // int n; cin >> n;
   // int* a = new (nothrow) int[n];
   // if (a == nullptr) { cout << "fail"; return 1; }
   // for (int i = 0; i < n; i++) a[i] = i * i;
   // for (int i = 0; i < n; i++) cout << a[i] << " ";
   // delete[] a; a = nullptr;

TASK 2 (MEDIUM): Resize Array to a Larger Buffer
   Start with an array of 5 elements {1,2,3,4,5}. Resize to size 8:
   allocate new int[8], copy the 5 elements, fill 6,7,8 as 0, delete[]
   the old buffer, and print the NEW larger array.
   // STARTER CODE:
   // int* old = new int[5] {1,2,3,4,5};
   // int* bigger = new int[8] {};         // sab zero se shuru
   // for (int i = 0; i < 5; i++) bigger[i] = old[i];   // copy
   // delete[] old;   old = nullptr;      // purana buffer hatao
   // // ab bigger[0..7] print karo

TASK 3 (MEDIUM): Merge Two Dynamic Arrays
   Given two sorted dynamic arrays A(size n) and B(size m), allocate
   C of size n+m, merge them (copy A then B is fine), print, free all.
   // STARTER CODE:
   // int* C = new (nothrow) int[n + m];
   // for (int i = 0; i < n; i++) C[i] = A[i];
   // for (int i = 0; i < m; i++) C[n + i] = B[i];
   // // sab print karo, phir teeno delete[] karo

TASK 4 (MEDIUM): In-Place Reverse of Dynamic Array
   Reverse a dynamic array in place (no extra array). Print before/after.
   Hint: two-pointer — left from 0, right from n-1, swap, move inward.
   // STARTER CODE:
   // int left = 0, right = n - 1;
   // while (left < right) {
   //     int t = a[left]; a[left] = a[right]; a[right] = t;
   //     left++; right--;
   // }

TASK 5 (HARD): Count Even/Odd in Dynamic Array
   Read n, allocate new int[n], fill from user, then count how many are
   even and how many are odd using pointers (traverse with a pointer).
   Free everything at the end.
   // STARTER CODE:
   // int even = 0, odd = 0;
   // for (int* it = a; it != a + n; it++) {
   //     if (*it % 2 == 0) even++; else odd++;
   // }
   // // delete[] a; a = nullptr; LEAK mat karo!

TASK 6 (HARD): Dynamic String Builder
   Read a small word from the user, find its length, build a dynamic
   char buffer of size length+1, copy letters + '\0', print it, delete[].
   Hint: char* s = new char[len + 1]; then for loop copy with '\0' end.
   // STARTER CODE:
   // cout << "enter word: "; string w; cin >> w;
   // char* s = new char[w.size() + 1];
   // for (size_t i = 0; i < w.size(); i++) s[i] = w[i];
   // s[w.size()] = '\0';
   // cout << "built: " << s << endl;
   // delete[] s; s = nullptr;

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== TASK 1: Allocate, Fill, Print, Free ===" << endl;
    {
        int n = 5;
        int *a = new (nothrow) int[n];
        if (a == nullptr) { cout << "alloc failed\n"; return 1; }
        for (int i = 0; i < n; i++) a[i] = i * i;   // fill
        cout << "n=5, squares: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        delete[] a;   a = nullptr;   // delete[] + avoid dangling
    }
    cout << endl;

    cout << "=== TASK 2: Resize to Larger Buffer ===" << endl;
    {
        int *oldArr = new int[5] {1, 2, 3, 4, 5};
        int *bigger = new int[8] {};             // 8 element, sab zero
        for (int i = 0; i < 5; i++) bigger[i] = oldArr[i];   // copy
        delete[] oldArr;  oldArr = nullptr;      // old buffer free
        cout << "Resized array (size 8): ";
        for (int i = 0; i < 8; i++) cout << bigger[i] << " ";
        cout << endl;
        delete[] bigger;  bigger = nullptr;
    }
    cout << endl;

    cout << "=== TASK 3: Merge Two Dynamic Arrays ===" << endl;
    {
        int *A = new int[3] {1, 3, 5};
        int *B = new int[2] {2, 4};
        int n = 3, m = 2;
        int *C = new (nothrow) int[n + m];
        if (C == nullptr) { cout << "alloc failed\n"; return 1; }
        for (int i = 0; i < n; i++) C[i] = A[i];       // A copy
        for (int i = 0; i < m; i++) C[n + i] = B[i];   // B copy
        cout << "Merged C: ";
        for (int i = 0; i < n + m; i++) cout << C[i] << " ";
        cout << endl;
        delete[] A; A = nullptr;
        delete[] B; B = nullptr;
        delete[] C; C = nullptr;   // teeno free — koi leak nahi
    }
    cout << endl;

    cout << "=== TASK 4: In-Place Reverse ===" << endl;
    {
        int *a = new int[5] {10, 20, 30, 40, 50};
        int left = 0, right = 4;
        while (left < right) {
            int t = a[left];
            a[left] = a[right];
            a[right] = t;
            left++; right--;
        }
        cout << "Reversed: ";
        for (int i = 0; i < 5; i++) cout << a[i] << " ";
        cout << "   (expect 50 40 30 20 10)" << endl;
        delete[] a; a = nullptr;
    }
    cout << endl;

    cout << "=== TASK 5: Count Even/Odd with Pointer ===" << endl;
    {
        int *a = new int[6] {2, 7, 4, 9, 6, 11};
        int even = 0, odd = 0;
        for (int *it = a; it != a + 6; it++) {
            if (*it % 2 == 0) even++; else odd++;   // *it se value
        }
        cout << "Array: 2 7 4 9 6 11 -> even=" << even << " odd=" << odd
             << "   (expect 3 3)" << endl;
        delete[] a; a = nullptr;
    }
    cout << endl;

    cout << "=== TASK 6: Dynamic String Builder ===" << endl;
    {
        string w = "DSA";
        char *s = new char[w.size() + 1];
        for (size_t i = 0; i < w.size(); i++) s[i] = w[i];
        s[w.size()] = '\0';          // null terminator zaroori
        cout << "Built dynamic string: " << s << "   (length " << w.size() << ")" << endl;
        delete[] s; s = nullptr;
    }
    cout << endl;

    cout << "All dynamic memory tasks done." << endl;
    return 0;
}