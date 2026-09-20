/*
═══════════════════════════════════════════════
 OPERATIONS ON DATA STRUCTURES
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Your class register has 40 student names. Every morning you must find
 whether "Rahul" is present (search). When a new student joins, you add
 the name at the end (insertion). When someone leaves, you erase the
 name (deletion). You sometimes re-print the list alphabetically
 (sorting) and combine two class registers into one (merging). Each
 action has a cost — some are instant, some take effort. Operations on
 data structures are exactly these actions, and knowing their cost tells
 you which structure to pick.

 📖 THEORY — operations and where each costs what:

 - TRAVERSAL: visit every element exactly once.
   * Array/vector: walk indices 0..n-1 — simple O(n).
   * Tree: pre/in/post order recursion O(n). Graph: BFS/DFS O(V+E).
   * Every structure must be fully visited → O(n) at minimum.

 - INSERTION: put a new element in.
   * Stack: push at top O(1). Queue: enqueue at back O(1).
   * Array middle: shift all right → O(n). Array end: O(1).
   * Linked list at front: O(1); at known spot O(1); find spot O(n).
   * BST balanced: O(log n). Hash table: O(1) average.

 - DELETION: remove an element.
   * Stack pop O(1). Queue dequeue O(1).
   * Array middle: shift left → O(n). End: O(1).
   * Linked list at known node: O(1); need search first: O(n).
   * BST balanced: O(log n). Hash table: O(1) average.

 - SEARCHING: find a value.
   * Unsorted array: linear scan O(n).
   * Sorted array: binary search O(log n).
   * BST balanced: O(log n). Hash table: O(1) average.
   * The KEY insight: sorted ≠ searchable in O(1), hashed = O(1).

 - SORTING: arrange in order (ascending/descending).
   * Usually done on arrays/vectors (and linked lists).
   * STL sort() = introsort: average O(n log n).
   * Comparisons + rearrangements dominate the cost.

 - MERGING: combine two sorted collections into one sorted output.
   * Scan both left-to-right, pick smaller each time → O(a + b).
   * Needs only O(a+b) time if both inputs are already sorted.

 ASCII OVERVIEW:

   Array:   [ 3 | 1 | 4 | 2 ]
     search → scan 0..3         access arr[i] → O(1)
     insert middle → shift      delete middle → shift

   Insert middle (index 2):
      before: [ 3 | 1 | 4 | 2 ]
      shift right: [ 3 | 1 | _ | 4 | 2 ]   → insert 9
         → [ 3 | 1 | 9 | 4 | 2 ]

   Delete middle (index 1):
      before: [ 3 | 1 | 9 | 4 | 2 ]        → remove 1
      shift left: [ 3 | 9 | 4 | 2 | _ ]

   Merge:  a = [1,3,5]  +  b = [2,4,6]
      compare 1<2 take 1 | 3 vs 2 take 2 | 3 vs 4 take 3
      | 5 vs 4 take 4 | 5 vs 6 take 5 | take 6
      → [1,2,3,4,5,6]

 🧠 LOGIC — STEP BY STEP (array mini-program):

 Step 1: Keep a size variable alongside the array.
    WHY: C arrays don't know their length; searching, inserting and
    deleting all need to know how many elements are "live".

 Step 2: SEARCH — linear scan.
    WHY: With no order guaranteed, the only way is to check every
    element 0..n-1 until found or finish.

 Step 3: INSERT at the end.
    WHY: Appending at position 'size' needs no shifting → O(1), and
    we just increment size.

 Step 4: DELETE by value.
    WHY: First locate the index (search), then shift all following
    elements one step LEFT to fill the gap, and decrement size.
    If we deleted from the middle, everything after must move — O(n).

 Step 5: Print after each step.
    WHY: Visible output proves the operation math — counts go
    up/down correctly and no value is lost or duplicated.

 VISUAL WALKTHROUGH:

   Start:  arr = [20, 10, 40, 30, 50], size = 5
   Search 40 → index 2  (0-based)
   Insert 99 at end → [20,10,40,30,50,99], size = 6
   Delete 30 → amnee after 3rd position? list becomes
               [20,10,40,50,99], size = 5

 DRY RUN of the demo:

   initialize: size=5, arr=[20,10,40,30,50]

   search(arr, size, 40):
     i=0: 20 != 40   i=1: 10 != 40   i=2: 40 == 40 → return 2

   insertEnd(arr, size, 99):
     arr[5]=99, size=5→6. arr=[20,10,40,30,50,99]

   deleteByValue(arr, size, 30):
     find index: i=0:20, i=1:10, i=2:40, i=3:30 → idx=3
     shift left from idx+1=4:
        i=4: arr[3]=arr[4] → arr[3]=50
        i=5: arr[4]=arr[5] → arr[4]=99
        i=6 < size? no (size=6) stop
     size=6→5. arr=[20,10,40,50,99]. 30 chala gaya. ✔

 TIME COMPLEXITY CALCULATION:
 - Search: loop goes from 0 to n-1; worst case scans all n elements,
   each comparison constant work → O(n) comparisons → Time O(n).
 - Insert at end: single assignment + increment → O(1) (amortized).
 - Delete by value: search O(n) + shifting up to n-1 indices O(n)
   → O(n) + O(n) = O(2n) → Time O(n) total.
 - Print: n prints → O(n).
   → Overall demo Time Complexity = O(n) per core operation.

 SPACE COMPLEXITY CALCULATION:
 - The array holds n ints → O(n).
 - All operations use a handful of loop counters (i, idx, etc.) —
   constant extra space, no copies, no recursion.
   → Space Complexity = O(n) for data + O(1) working = O(n).

 APPROACH COMPARISON — cost of each operation per structure:

 ┌────────────────────┬───────────────┬───────────────┬───────────────┬──────────────┬───────────────┐
 │ Structure          │ Search        │ Insert        │ Delete        │ Sort         │ Merge         │
 ├────────────────────┼───────────────┼───────────────┼───────────────┼──────────────┼───────────────┤
 │ Unsorted array     │ O(n) scan     │ O(1) end      │ O(n) shift    │ O(n log n)   │ O(n)[+sort]   │
 │ Sorted array       │ O(log n) b.s. │ O(n) shift    │ O(n) shift    │ done         │ O(a+b)        │
 │ Linked list        │ O(n) scan     │ O(1) given    │ O(1) given    │ O(n log n)   │ O(a+b)        │
 │ Balanced BST       │ O(log n)      │ O(log n)      │ O(log n)      │ O(n) inorder │ O(m+n) merge  │
 │ Hash table         │ O(1) avg      │ O(1) avg      │ O(1) avg      │ — (unsorted) │ —             │
 └────────────────────┴───────────────┴───────────────┴───────────────┴──────────────┴───────────────┘

 Conclusion: no single structure wins everywhere — arrays give instant
 random access but slow middle-inserts; hash gives fast lookup but no
 order; BST balances all three.
*/

#include <iostream>
using namespace std;

// Linear search: value ka index dhundo, nahi mila to -1
int searchArr(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;              // mil gaya — index return
        }
    }
    return -1;                     // nahi mila
}

// Insert at end: O(1) — koi shifting nahi
void insertEnd(int arr[], int &size, int value) {
    arr[size] = value;             // end pe rakho
    size++;                        // size badhao
}

// Delete by value: search karo phir shift left
void deleteByValue(int arr[], int &size, int value) {
    int idx = searchArr(arr, size, value);
    if (idx == -1) {
        cout << "  " << value << " mila hi nahi, delete nahi hua" << endl;
        return;
    }
    for (int i = idx; i < size - 1; i++) {
        arr[i] = arr[i + 1];       // aage wale ko ek step peeche kheench
    }
    size--;                        // size kam karo
    cout << "  " << value << " delete ho gaya (index " << idx << " se)" << endl;
}

// Poore array ko print karo
void printArr(int arr[], int size) {
    cout << "  Array: [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "] (size = " << size << ")" << endl;
}

int main() {
    int arr[10];                   // capacity 10, isme jyada space hai
    arr[0] = 20; arr[1] = 10; arr[2] = 40; arr[3] = 30; arr[4] = 50;
    int size = 5;                  // abhi sirf 5 elements live hain

    cout << "Starting array:" << endl;
    printArr(arr, size);

    cout << "SEARCH 40:" << endl;
    int idx = searchArr(arr, size, 40);
    cout << "  40 ka index: " << idx << endl;       // 2

    cout << "INSERT 99 (end mein):" << endl;
    insertEnd(arr, size, 99);
    printArr(arr, size);

    cout << "DELETE 30:" << endl;
    deleteByValue(arr, size, 30);
    printArr(arr, size);

    cout << "Edge cases:" << endl;
    // Search kisi aisi value jo exist nahi karti
    cout << "  search 777 -> " << searchArr(arr, size, 777) << " (expect -1)" << endl;
    // Delete kisi aisi value jo exist nahi karti
    deleteByValue(arr, size, 777);
    printArr(arr, size);

    return 0;
}