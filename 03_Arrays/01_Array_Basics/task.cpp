/*
═══════════════════════════════════════════════
 TASK SET — ARRAY BASICS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A teacher holds the marks list of 5 students — exactly like an
 array of ints. She needs the highest mark (topper), the second highest (runner-up),
 the class average, the roll number of one student, and the list printed back-to-front.
 Our tasks answer all of these by simply walking the marks list with a loop.

🧠 HOW TO SOLVE: Every task uses one core idea — TRAVERSAL: a single for-loop from i=0
 to i<n that examines each arr[i] once. For max-type problems keep a "running best"
 variable and update it when a better value appears. For position search remember the
 index i when the value matches. For reverse, print from the last index down to 0. No
 extra data structure is needed — everything runs in O(n) time with O(1) extra space.

 5 tasks EASY → HARD:

 TASK 1 (EASY) — FIND THE MAXIMUM
   Statement: Given arr = {34, 12, 78, 5, 42}, find and print the largest value.
   💡 HINT: Assume arr[0] is the maximum; compare every arr[i] with it — if
            arr[i] is bigger, update the maximum.
   ✏️ STARTER CODE (fill in the blanks):
       // int max = arr[0];
       // for (int i = 1; i < n; i++) {
       //     if (arr[i] ____ max) max = ____;
       // }

 TASK 2 (EASY-MEDIUM) — FIND THE SECOND MAXIMUM
   Statement: In the same array, print the largest and the second-largest value.
   💡 HINT: Keep two variables — 'first' (the largest) and 'second' (the one
            right after it). When any arr[i] bigger than first appears, the
            old first becomes the second.
   ✏️ STARTER CODE:
       // int first, second;
       // // initialize from arr[0] and arr[1]
       // for (int i = 2; i < n; i++) {
       //     if (arr[i] > first) { second = first; first = arr[i]; }
       //     else if (arr[i] > second) { ____ = arr[i]; }
       // }

 TASK 3 (EASY) — SUM AND AVERAGE
   Statement: Given arr = {10, 20, 30, 40}, print the sum and the average.
   💡 HINT: Add all elements into one sum variable; average = sum / n. Do not
            forget to make n a double before dividing, otherwise integer
            division will give a wrong result.
   ✏️ STARTER CODE:
       // int sum = 0;
       // for (int i = 0; i < n; i++) sum ____ arr[i];
       // double avg = (double)sum / n;

 TASK 4 (MEDIUM) — LINEAR SEARCH: FIND THE INDEX OF A VALUE
   Statement: In arr = {5, 8, 3, 9, 1}, find the index of value 3 and print it.
              If missing, print -1 (not found).
   💡 HINT: Keep scanning until the value is found; as soon as it is found,
            print i and break. If no value is found, -1 means not found.
   ✏️ STARTER CODE:
       // int found = -1;
       // for (int i = 0; i < n; i++) {
       //     if (____ == x) { found = i; ____; }
       // }
       // cout << found;

 TASK 5 (HARD) — PRINT ARRAY IN REVERSE
   Statement: Print arr = {1, 2, 3, 4, 5} from the last element to the first.
   💡 HINT: Start the loop at i = n-1 and decrease while i >= 0 (i--). The last
            element is arr[n-1], then arr[n-2] ... and finally arr[0].
   ✏️ STARTER CODE:
       // for (int i = ____; i >= ____; i--) {
       //     cout << arr[i] << " ";
       // }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

// TASK 1: maximum element
void task1() {
    int arr[] = {34, 12, 78, 5, 42};
    int n = 5;

    // pehle element ko abhi ke liye max maan liya
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];              // naya behtar value mila to max update
        }
    }
    cout << "TASK 1 -> Max = " << max << "\n";
    // DRY RUN: max=34; i=1 (12 chhota, no); i=2 (78>34, max=78);
    //          i=3 (5 chhota, no); i=4 (42 chhota, no) => answer 78
}

// TASK 2: first and second maximum
void task2() {
    int arr[] = {34, 12, 78, 5, 42};
    int n = 5;

    // pehle do elements se initialize: bigger wala first, chhota wala second
    int first  = (arr[0] > arr[1]) ? arr[0] : arr[1];   // sabse bada
    int second = (arr[0] > arr[1]) ? arr[1] : arr[0];   // uske baad wala

    for (int i = 2; i < n; i++) {      // bache hue elements scan karo
        if (arr[i] > first) {          // naya sabse bada mil gaya
            second = first;            // purana first ab second ban jayega
            first = arr[i];            // naya first set
        } else if (arr[i] > second) {  // first se chhota lekin second se bada
            second = arr[i];
        }
    }
    cout << "TASK 2 -> First max = " << first << ", Second max = " << second << "\n";
    // DRY RUN: first=34 second=12; i=2 (78>34 → second=34, first=78);
    //          i=3 (5 chhota); i=4 (42>34 → second=42) => 78, 42
}

// TASK 3: sum and average
void task3() {
    int arr[] = {10, 20, 30, 40};
    int n = 4;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];                 // har element ko sum me jod rahe hain
    }
    // (double) important hai — warna 100/4 integer ok hoga, lekin 95/4 galat hoga
    double avg = (double)sum / n;

    cout << "TASK 3 -> Sum = " << sum << ", Average = " << avg << "\n";
    // DRY RUN: sum=10→30→60→100; avg = 100/4 = 25.0
}

// TASK 4: linear search — index of x, else -1
void task4() {
    int arr[] = {5, 8, 3, 9, 1};
    int n = 5;
    int x = 3;

    int found = -1;                    // sentinel: abhi tak nahi mila
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = i;                 // mil gaya — index yaad karo
            break;                     // aage dekhne ki zaroorat nahi, loop tod do
        }
    }
    if (found != -1) {
        cout << "TASK 4 -> " << x << " found at index " << found << "\n";
    } else {
        cout << "TASK 4 -> " << x << " not found (-1)\n";
    }
    // DRY RUN: i=0 (5 no); i=1 (8 no); i=2 (3 yes → found=2, break) => 2
}

// TASK 5: print array in reverse
void task5() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "TASK 5 -> Reverse: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";         // aakhri se shuru, peeche ki taraf jaao
    }
    cout << "\n";
    // DRY RUN: i=4 (5) i=3 (4) i=2 (3) i=1 (2) i=0 (1) => 5 4 3 2 1
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}