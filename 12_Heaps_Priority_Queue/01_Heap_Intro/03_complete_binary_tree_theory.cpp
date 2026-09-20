/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_complete_binary_tree_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ File cabinet shelves left-to-right fill hote hain. Jab shelf complete style me fill hoti hai, numbering simple ho jati hai; heap bhi complete binary tree hota hai, isliye array me store ho jata hai.
│
│ VISUAL NOTES:
│ Complete Binary Tree:
│        1
│      /   \
│     2     3
│    / \   /
│   4   5 6
│ Last level left-filled hai, gap beech me nahi.
│
│ Not complete:
│        1
│      /   \
│     2     3
│      \     \
│       5     7
│ Left gaps before right nodes -> array mapping waste/invalid.
│
│ Why complete for heap?
│ Tree index labels:
│        0
│      /   \
│     1     2
│    / \   /
│   3   4 5
│
│ Array:
│ index:  0  1  2  3  4  5
│ value: [1, 2, 3, 4, 5, 6]
│ No pointers needed.

│
│ DRY RUN / FLOW:
│ Real-world input -> identify priority -> maintain heap property -> answer fast.
│
│ COMPLEXITY CALCULATION:
│ Complete tree insertion always next open array index pe hota hai.
│ For n elements, append cost amortized O(1).
│ Then heapify-up may travel height h.
│
│ Complete tree height proof:
│ At each level nodes double.
│ n / 2^k = 1 -> n = 2^k -> k = log₂n.
│ height = O(log n).
│
│ Space: vector stores n values -> O(n), no left/right pointers.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void showIndexMapping(const vector<int>& a) {
    for (int i = 0; i < (int)a.size(); i++) {
        cout << "index " << i << " stores node " << a[i] << "\n";
    }
}

int main() {
    vector<int> completeTree = {1, 2, 3, 4, 5, 6};
    cout << "Complete tree can be stored level-order in array:\n";
    showIndexMapping(completeTree);
    cout << "Next insertion position index = " << completeTree.size() << " (left-to-right fill).\n";
    return 0;
}

/*
OUTPUT:
Complete tree can be stored level-order in array:
index 0 stores node 1
index 1 stores node 2
index 2 stores node 3
index 3 stores node 4
index 4 stores node 5
index 5 stores node 6
Next insertion position index = 6 (left-to-right fill).
*/

