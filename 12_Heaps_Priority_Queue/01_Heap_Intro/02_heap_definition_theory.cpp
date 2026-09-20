/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_heap_definition_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Company escalation desk me boss node apne direct reports se higher priority rakhta hai. Heap me rule local parent-child hota hai, globally sorted left-right order zaroori nahi hota.
│
│ VISUAL NOTES:
│ HEAP = Complete Binary Tree + Heap Property
│
│ Max Heap property: parent >= children at every node
│        90
│       /  \
│     70    80
│    / \   /
│   20 30 60
│
│ Min Heap property: parent <= children at every node
│        10
│       /  \
│     20    30
│    / \   /
│   50 60 40
│
│ Heap vs BST:
│ BST:
│       50
│      /  \
│    30    70     left subtree < root < right subtree
│
│ Heap:
│       90
│      /  \
│    70    80     sirf parent child se bada hai
│                 left child and right child ka mutual order fixed nahi

│
│ DRY RUN / FLOW:
│ Real-world input -> identify priority -> maintain heap property -> answer fast.
│
│ COMPLEXITY CALCULATION:
│ Validate max heap by checking parent-child edges.
│ For each index i:
│ left = 2i+1, right = 2i+2.
│ If child exists and arr[i] < child -> rule break.
│
│ Each valid edge checked once.
│ Complete binary tree with n nodes has n-1 edges.
│ Time = O(n).
│ Space = O(1) extra for iterative check.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isMaxHeap(const vector<int>& heap) {
    for (int i = 0; i < (int)heap.size(); i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // Parent ko dono children se bada/equal hona chahiye.
        if (left < (int)heap.size() && heap[i] < heap[left]) return false;
        if (right < (int)heap.size() && heap[i] < heap[right]) return false;
    }
    return true;
}

int main() {
    vector<int> maxHeap = {90, 70, 80, 20, 30, 60};
    vector<int> notHeap = {50, 70, 80};
    cout << "maxHeap valid? " << (isMaxHeap(maxHeap) ? "YES" : "NO") << "\n";
    cout << "notHeap valid? " << (isMaxHeap(notHeap) ? "YES" : "NO") << "\n";
    cout << "Heap checks local parent-child rule, BST checks ordered left/right ranges.\n";
    return 0;
}

/*
OUTPUT:
maxHeap valid? YES
notHeap valid? NO
Heap checks local parent-child rule, BST checks ordered left/right ranges.
*/

