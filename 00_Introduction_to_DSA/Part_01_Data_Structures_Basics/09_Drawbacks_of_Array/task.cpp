/*
═══════════════════════════════════════════════
 TASK SET — DRAWBACKS / LIMITATIONS OF ARRAY
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
You manage a fixed 100-seat banquet hall. Guests keep squeezing into the
middle of a packed row, so every person to the right must shuffle one seat
over — the more guests, the costlier the shuffle. You also pay rent for all
100 seats even when only 20 people actually show up.

 🧠 HOW TO SOLVE:
Accept that an array is a CONTIGUOUS block of FIXED capacity. Any middle
insert or delete shifts (n - p) elements, empty slots waste capacity × size
bytes, and stepping past the end is undefined behaviour. Build tiny functions
that count shifts, detect a full array, compute wastage, and only then insert.

 ┌──────────────────────────────────────────────────────────────┐
 │ Task  Difficulty  What you practice                          │
 ├──────────────────────────────────────────────────────────────┤
 │ 1     EASY        computing shifts = (n - p)                 │
 │ 2     EASY        writing insertAt() with a shift counter    │
 │ 3     MEDIUM      writing deleteAt() with a shift counter    │
 │ 4     MEDIUM      computing used vs wasted memory in bytes   │
 │ 5     HARD        sorted insert with graceful full-check     │
 └──────────────────────────────────────────────────────────────┘

 TASK 1: Given the number of elements n and an insertion position p, print
         how many elements must shift: shifts = n - p.
 💡 HINT: elements from index p to n-1 move right; that count is exactly n - p.
 ✏️ STARTER CODE:
         int main() {
             int n = 5, pos = 2;
             // TODO: shifts = n - pos
             return 0;
         }

 TASK 2: Write insertAt(arr, n&, capacity, pos, val). Shift from the BACK
         first, count and print every shift, place val at pos, and refuse
         with a message if the array is already full.
 💡 HINT: the loop is for (int i = n; i > pos; --i) { arr[i] = arr[i-1]; }
 ✏️ STARTER CODE:
         void insertAt(int arr[], int &n, int capacity, int pos, int val) {
             // TODO: if n >= capacity print error and return
             // TODO: shift right from the back
             // TODO: arr[pos] = val;  n++;
         }
         int main() {  // test on [10,20,30,40,50] insert 15 at 1 }

 TASK 3: Write deleteAt(arr, n&, pos) that shifts everything LEFT from pos
         and prints how many shifts happened.
 💡 HINT: for (int i = pos; i < n - 1; ++i) { arr[i] = arr[i+1]; }  then n--.
 ✏️ STARTER CODE:
         void deleteAt(int arr[], int &n, int pos) {
             // TODO: shift everything left from pos
             // TODO: n--;
         }
         int main() {  // test on an array, delete middle element }

 TASK 4: Given capacity and used count of an int array, print used bytes,
         wasted bytes, and the wastage percentage.
 💡 HINT: one element = sizeof(int) bytes; wastage% = (cap - used)*100/cap.
 ✏️ STARTER CODE:
         int main() {
             int capacity = 10, used = 3;
             // TODO: print used bytes, wasted bytes, wastage %
             return 0;
         }

 TASK 5: The array must STAY SORTED. Write sortedInsert(arr, n&, capacity,
         val) that finds the correct spot, first checks capacity, shifts from
         the back, and inserts. If full, print why it failed.
 💡 HINT: find pos with  while (pos < n && arr[pos] < val) pos++;
 ✏️ STARTER CODE:
         void sortedInsert(int arr[], int &n, int capacity, int val) {
             // TODO: reject if full
             // TODO: find insertion pos while it stays sorted
             // TODO: shift from back, insert, n++
         }
         int main() {  // insert 25 into [10,20,30,40,50] → sorted }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

// ---- TASK 1: sirf formula — (n - p) elements shift honge ----
void task1() {
    int n = 5, pos = 2;
    int shifts = n - pos;                 // goldan rule: p se aage saare elements hile
    cout << "n=" << n << " pos=" << pos
         << " → shifts = " << shifts << endl;
}

// ---- TASK 2: insertAt — peeche se shift, kaafi asaan agar direction sahi ho ----
void insertAt(int arr[], int &n, int capacity, int pos, int val) {
    if (n >= capacity) {                  // full check pehle — warna undefined behaviour
        cout << "❌ FULL! insert fail: " << val << endl;
        return;
    }
    int shifts = 0;
    for (int i = n; i > pos; --i) {       // BACK se FRONT — aage se karte to data overwrite
        arr[i] = arr[i - 1];
        ++shifts;
    }
    arr[pos] = val;                       // ab slot khaali hai, daal do
    ++n;
    cout << "inserted " << val << " at " << pos << " | shifts = " << shifts << endl;
}

// ---- TASK 3: deleteAt — direction ULTA: front se shift ----
void deleteAt(int arr[], int &n, int pos) {
    int shifts = 0;
    for (int i = pos; i < n - 1; ++i) {   // aage se peeche ki taraf
        arr[i] = arr[i + 1];
        ++shifts;
    }
    --n;                                  // tail ki purani copy ab reach nahi
    cout << "deleted index " << pos << " | shifts = " << shifts << endl;
}

// ---- TASK 4: wastage — capacity quantity, used nahi, memory = hafte ka bill ----
void task4() {
    int cap = 10, used = 3;
    int elem = sizeof(int);               // int = 4 bytes
    int usedBytes   = used * elem;
    int wastedBytes = (cap - used) * elem;
    int wastedPct   = (cap - used) * 100 / cap;
    cout << "used = " << usedBytes << " B | wasted = " << wastedBytes
         << " B | wastage = " << wastedPct << "%" << endl;
}

// ---- TASK 5: sortedInsert — array sada sorted rehna chahiye ----
void sortedInsert(int arr[], int &n, int capacity, int val) {
    if (n >= capacity) {                  // jagah hi nahi → koi point nahi
        cout << "❌ capacity khatam — " << val << " nahi aa sakta" << endl;
        return;
    }
    int pos = 0;
    while (pos < n && arr[pos] < val)     // sahi jagah dhundho — sorted order
        ++pos;
    for (int i = n; i > pos; --i)         // peeche se khiskao
        arr[i] = arr[i - 1];
    arr[pos] = val;
    ++n;
    cout << "sorted insert " << val << " at " << pos << " → ";
}

int main() {
    cout << "──────── TASK 1 ────────" << endl;
    task1();

    cout << "\n──────── TASK 2 ────────" << endl;
    int a[6] = {10, 20, 30, 40, 50};
    int n = 5;
    printArr(a, n);
    insertAt(a, n, 6, 1, 15);
    printArr(a, n);

    cout << "\n──────── TASK 3 ────────" << endl;
    deleteAt(a, n, 2);                    // ab [10,15,20,30,40,50] me 20 hatao
    printArr(a, n);

    cout << "\n──────── TASK 4 ────────" << endl;
    task4();

    cout << "\n──────── TASK 5 ────────" << endl;
    int b[6] = {10, 20, 30, 40, 50};
    int nb = 5;
    sortedInsert(b, nb, 6, 25);           // 25 apni sahi jagah pe chalna chahiye
    printArr(b, nb);
    sortedInsert(b, nb, 6, 99);           // ab bhar gaya → reject ho
    return 0;
}