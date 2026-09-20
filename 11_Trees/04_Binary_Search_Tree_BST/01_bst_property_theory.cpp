/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_bst_property_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted dictionary ko tree form me rakho: current word se chhote words left side, bade words right side. Ye Binary Search Tree property hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. BST is a binary tree with ordering rule.
│ 2. Left subtree ke saare nodes root se smaller.
│ 3. Right subtree ke saare nodes root se greater.
│ 4. Ye rule har node par recursively true hona chahiye.
│ 5. BST search binary search jaisa half tree discard kar sakta hai.
│ 6. Inorder traversal sorted output deta hai.
│
│ ASCII VISUAL / BST STATE:
│ Valid BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│
│ Check every node:
│ 30 < 50 < 70
│ 20 < 30 < 40
│ 60 < 70 < 80
│
│ Invalid:
│      50
│     /  \
│   30    70
│     \
│      55   ← 55 is in left subtree of 50, invalid
│
│ DRY RUN:
│ Search 40:
│ 40<50 -> left.
│ 40>30 -> right.
│ 40==40 -> found.
│ Right half of 50 discarded at first step.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Theory check using traversal visits n nodes.
│ - Search in BST follows one root-to-leaf path of height h.
│ -> Search Time Complexity = O(h).
│ - Balanced h=log n; skewed h=n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Tree stores n nodes.
│ - Recursive search stack O(h), iterative O(1).
│ -> Space Complexity depends on operation.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    cout << "BST property: all left values < root < all right values, for every node.\n";
    cout << "Inorder of BST gives sorted order.\n";
    cout << "Search follows one path like binary search: O(h).\n";
    return 0;
}

/*
OUTPUT:
BST property: all left values < root < all right values, for every node.
Inorder of BST gives sorted order.
Search follows one path like binary search: O(h).
*/

