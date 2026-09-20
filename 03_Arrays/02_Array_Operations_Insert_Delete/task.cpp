/*
═══════════════════════════════════════════════
 TASK SET — INSERT / DELETE / UPDATE IN ARRAY
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A railway counter keeps the waiting list of passengers in
 order. New passengers must be inserted while keeping the ticket-queue sorted,
 repeat names must be removed every time they appear, and when a train leaves the
 platform the whole queue shifts forward by one place. Our tasks do exactly these
 queue edits on an array of ticket numbers.

🧠 HOW TO SOLVE: Two mental tools solve everything here. (1) SHIFTING — to insert,
 right-shift from the back backwards so no data is lost when a gap opens; to delete,
 left-shift forward to close the gap. (2) WRITE-INDEX — keep a separate "write" cursor
 and copy only the elements we want to keep; the read cursor scans the whole array.
 Always guard positions (0 <= pos < size) and capacity (size < CAP) before editing.

 5 tasks EASY → HARD:

 TASK 1 (EASY) — INSERT INTO A SORTED ARRAY, KEEPING IT SORTED
   Statement: arr = {1, 3, 5, 7, 9} (sorted). Insert 4 so the array stays sorted.
   💡 HINT: Scan from the right; as long as arr[i] > 4, right-shift the elements.
            The moment the loop stops, place 4 in the slot after it.
   ✏️ STARTER CODE:
       // int i = size - 1;
       // while (i >= 0 && arr[i] > x) {
       //     arr[i + 1] = arr[i];
       //     i--;
       // }
       // arr[i + 1] = x;   // insert at the right position
       // size++;

 TASK 2 (EASY-MEDIUM) — DELETE ALL OCCURRENCES OF X
   Statement: arr = {4, 1, 4, 4, 2, 4}. Remove every 4 and print the survivors.
   💡 HINT: WRITE-INDEX trick — keep a 'w'; copy every non-x element to arr[w] and
            do w++. At the end, size = w (only the surviving elements).
   ✏️ STARTER CODE:
       // int w = 0;
       // for (int r = 0; r < size; r++) {
       //     if (arr[r] != x) { arr[w] = arr[r]; w++; }
       // }
       // size = w;

 TASK 3 (MEDIUM) — INSERT AT BOTH ENDS
   Statement: arr = {2, 3, 4} (capacity 10). Insert 1 at the FRONT and 5 at the BACK.
   💡 HINT: Do the front insert first — right-shift everything, then arr[0] = 1.
            The back insert is trivial: arr[size] = 5, size++.
   ✏️ STARTER CODE:
       // // front insert: right shift
       // for (int i = size - 1; i >= 0; i--) arr[i + 1] = arr[i];
       // arr[0] = 1; size++;
       // // back insert
       // arr[size] = 5; size++;

 TASK 4 (MEDIUM) — LEFT SHIFT THE ARRAY BY ONE
   Statement: arr = {1, 2, 3, 4, 5}. Shift every element one place left
              → {2, 3, 4, 5, 1}.
   💡 HINT: Save arr[0] in a variable first (it goes to the end). Then in the loop
            do arr[i] = arr[i+1], and finally set arr[size-1] = saved first.
   ✏️ STARTER CODE:
       // int first = arr[0];
       // for (int i = 0; i < size - 1; i++) arr[i] = ____;
       // arr[size - 1] = ____;

 TASK 5 (HARD) — REMOVE DUPLICATES FROM A SORTED ARRAY
   Statement: arr = {1, 1, 2, 2, 2, 3, 3, 4} (sorted). Keep only unique values.
   💡 HINT: Write-index + comparison with the last written unique value. For each
            new element: if arr[w-1] != arr[r], copy it, otherwise skip it.
   ✏️ STARTER CODE:
       // int w = 0;
       // for (int r = 0; r < size; r++) {
       //     if (w == 0 || arr[r] != arr[w - 1]) {
       //         arr[w] = arr[r];
       //         w++;
       //     }
       // }
       // size = w;
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

void showArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}

// TASK 1: insert into a sorted array keeping it sorted
void task1() {
    int arr[10] = {1, 3, 5, 7, 9};
    int size = 5;
    int x = 4;

    int i = size - 1;                    // sabse aakhri se scan shuru
    while (i >= 0 && arr[i] > x) {
        arr[i + 1] = arr[i];             // bade elements ko right shift karo
        i--;
    }
    arr[i + 1] = x;                      // sahi slot par x rakh do
    size++;

    cout << "TASK 1 -> After inserting " << x << ": ";
    showArray(arr, size);
    // DRY RUN: x=4; i=4(9>4 shift), i=3(7>4 shift), i=2(5>4 shift),
    //          i=1(3<4 → ruk), arr[2]=4 → {1,3,4,5,7,9}
}

// TASK 2: delete all occurrences of x (write-index technique)
void task2() {
    int arr[] = {4, 1, 4, 4, 2, 4};
    int size = 6;
    int x = 4;

    int w = 0;                           // write cursor — sirf bachne wale elements
    for (int r = 0; r < size; r++) {
        if (arr[r] != x) {
            arr[w] = arr[r];             // survivor ko aage kheench kar rakh do
            w++;
        }
    }
    size = w;                            // nayi size = survivors ki ginti

    cout << "TASK 2 -> After deleting all " << x << "s: ";
    showArray(arr, size);
    // DRY RUN: w=0; r=0(4 skip), r=1(1 → arr[0]=1 w=1), r=2(4 skip),
    //          r=3(4 skip), r=4(2 → arr[1]=2 w=2), r=5(4 skip) → {1,2}
}

// TASK 3: insert at both ends (front = O(n), back = O(1))
void task3() {
    int arr[10] = {2, 3, 4};
    int size = 3;

    // FRONT insert — saare elements ko ek slot right shift karo
    for (int i = size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = 1;                          // ab first slot khali hai
    size++;

    // BACK insert — seedha next slot par, O(1)
    arr[size] = 5;
    size++;

    cout << "TASK 3 -> After front(1) and back(5) insert: ";
    showArray(arr, size);
    // DRY RUN: shift → {_,2,3,4} → arr[0]=1 → {1,2,3,4} → +5 → {1,2,3,4,5}
}

// TASK 4: left shift array by one
void task4() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    int first = arr[0];                  // pehla element bacha lo — aakhri me jayega
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];             // har element ek slot peeche kheench lo
    }
    arr[size - 1] = first;               // saved first ko aakhri slot par rakho

    cout << "TASK 4 -> After left shift by 1: ";
    showArray(arr, size);
    // DRY RUN: first=1; {2,2,3,4,5}→{2,3,3,4,5}→{2,3,4,4,5}→{2,3,4,5,5}
    //          → arr[4]=1 → {2,3,4,5,1}
}

// TASK 5: remove duplicates from a sorted array
void task5() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 4};
    int size = 8;

    int w = 0;                           // write cursor — unique elements yahan aayenge
    for (int r = 0; r < size; r++) {
        if (w == 0 || arr[r] != arr[w - 1]) {   // pehla + har naya unique value
            arr[w] = arr[r];
            w++;
        }
    }
    size = w;

    cout << "TASK 5 -> Unique elements: ";
    showArray(arr, size);
    // DRY RUN: w=0(1 copy w=1); 1==1 skip; 2!=1 copy w=2; 2==2 skip; 2==2 skip;
    //          3!=2 copy w=3; 3==3 skip; 4!=3 copy w=4 → {1,2,3,4}
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}