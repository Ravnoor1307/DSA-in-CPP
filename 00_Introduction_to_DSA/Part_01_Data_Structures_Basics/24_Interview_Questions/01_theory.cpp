/*
═══════════════════════════════════════════════
 INTERVIEW QUESTIONS — DSA BASICS REVISION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A candidate walks into an interview; the interviewer asks quick-fire basics —
 "What is a data structure?" "Array vs linked list?" "What is an algorithm?"
 The candidate who can answer these crisp one-liners instantly shows code
 readiness. This file is that revision sheet plus one ready-to-type program
 (linear search) to prove you can code under pressure.

 📖 THEORY: (Q&A revision — beginner interview questions, terse one-line answers)

 Q1.  What is a data structure?
      A1.  A way to organise and store data so it can be used efficiently
           (e.g. arrays, linked lists, stacks, trees).

 Q2.  Name the two main categories.
      A2.  Linear (array, linked list, stack, queue — elements in a sequence)
           and Non-linear (tree, graph — hierarchical / network).

 Q3.  Array vs Linked List?
      A3.  Array = contiguous memory, fixed size, O(1) index access, O(n) insert
           anywhere. Linked list = non-contiguous nodes, dynamic size, O(n)
           search, O(1) head insert.

 Q4.  What is a Stack? Which principle?
      A4.  LIFO (Last In, First Out) — undo in editors, back button in browsers.

 Q5.  What is a Queue? Which principle?
      A5.  FIFO (First In, First Out) — printer jobs, ticket counters.

 Q6.  What is an Algorithm?
      A6.  A finite, well-defined step-by-step procedure that turns input into
           output.

 Q7.  What is Time Complexity?
      A7.  Measure of how runtime grows with input size n (Big-O notation).

 Q8.  What is Space Complexity?
      A8.  Measure of extra memory an algorithm needs apart from the input.

 Q9.  What does O(1), O(n), O(log n), O(n²) mean roughly?
      A9.  O(1)=instant, O(n)=linear scan, O(log n)=halving every step (binary
           search), O(n²)=nested loops over n.

 Q10. What is Recursion?
      A10. A function calling itself with a smaller input, guarded by a base
           case that stops the calls.

 Q11. What is an in-place algorithm?
      A11. One needing O(1) extra space — reversing an array by swapping ends.

 Q12. Linear vs Binary search?
      A12. Linear checks each element O(n), works on unsorted data; binary
           halves the range each step O(log n), needs SORTED data.

 Q13. Why are structs useful? (homogeneous vs non-homogeneous)
      A13. A struct bundles different types (id, name, marks) into one record —
           non-homogeneous; arrays hold a single type — homogeneous.

 Q14. Stable vs unstable sort?
      A14. Stable preserves the order of equal elements (bubble, merge);
           unstable may not (quick, heap).

 Q15. What is the difference between structure and class in C++?
      A15. Struct members default to public; class members default to private.

 🧠 LOGIC — STEP BY STEP: (linear search)
 Step 1: Input — an array, its size n, and a key to find.
         WHY: we must know what to search and where.
 Step 2: Loop i from 0 to n-1 and compare arr[i] with key.
         WHY: linear search checks every position one by one.
 Step 3: On match, immediately return index i.
         WHY: we only need the FIRST occurrence.
 Step 4: If the loop ends with no match, return -1.
         WHY: -1 is a convention meaning "not found".

 VISUAL WALKTHROUGH:
   arr = [34, 7, 23, 32, 5], key = 23
   i=0  34 != 23 -> continue
   i=1  7  != 23 -> continue
   i=2  23 == 23 -> RETURN index 2     ✓
   key = 99 -> i=0..4 all mismatch -> RETURN -1

 DRY RUN:
   linearSearch({34,7,23,32,5}, 5, 23)
     i=0: 34==23? no
     i=1: 7==23? no
     i=2: 23==23? yes -> return 2
   linearSearch({34,7,23,32,5}, 5, 99)
     i=0..4 all no -> return -1

 TIME COMPLEXITY CALCULATION:
 - Best case: key at index 0 -> 1 comparison  => O(1).
 - Worst case: key at end OR not present -> compare all n elements
   => n comparisons.
 - Average case (key present, uniform): ~n/2 comparisons.
 → Time Complexity = O(n) (worst & average)

 SPACE COMPLEXITY CALCULATION:
 - Only a loop counter i is used; no array copy, no extra helper storage.
 → Space Complexity = O(1)

 DEMO EXPLANATION:
 - The code below is a complete, interview-ready linear search implementation:
   inputs array + n + key, returns index or -1.
*/

#include <iostream>
using namespace std;

// linear search — O(n) time, O(1) space
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;   // mil gaya, turant index bhejo
    }
    return -1;   // pura array check kar liya, kahin nahi mila
}

int main() {
    int arr[] = {34, 7, 23, 32, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key1 = 23;
    int idx1 = linearSearch(arr, n, key1);
    if (idx1 != -1) cout << key1 << " found at index " << idx1 << "\n";
    else cout << key1 << " not found.\n";

    int key2 = 99;
    int idx2 = linearSearch(arr, n, key2);
    if (idx2 != -1) cout << key2 << " found at index " << idx2 << "\n";
    else cout << key2 << " not found.\n";

    return 0;
}