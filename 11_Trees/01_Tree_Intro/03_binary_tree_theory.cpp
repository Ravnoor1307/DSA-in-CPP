/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_binary_tree_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Company hierarchy me agar rule ho ki har manager ke maximum 2 direct reports ho sakte hain, to structure binary tree jaisa ban jata hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Binary tree me har node ke at most 2 children hote hain.
│ 2. Children names: left child and right child.
│ 3. 0 child allowed, 1 child allowed, 2 children allowed.
│ 4. 3 children wala node binary tree invalid hai.
│ 5. Skewed tree linked list jaisa degenerate ho sakta hai.
│ 6. Perfect tree me all internal nodes have 2 children and all leaves same level.
│
│ ASCII VISUAL / TREE STATE:
│ Valid binary tree:
│        10
│       /  \
│      5    20
│     /
│    3
│
│ Invalid binary tree:
│        10
│      /  |  \
│     5   7   20   ← 3 children not allowed
│
│ Skewed tree (linked list ban gaya):
│ 1
│  \
│   2
│    \
│     3
│
│ Perfect tree:
│        1
│      /   \
│     2     3
│    / \   / \
│   4  5  6  7
│
│ DRY RUN:
│ Node 10 with left=5 and right=20 is valid.
│ Node 5 with only left=3 is also valid.
│ A node with left, middle, right three children breaks binary rule.
│
│ FLOW OF EXECUTION:
│ main -> create/describe tree -> pointer/term logic -> output
│
│ COMPLEXITY CALCULATION:
│ - Checking binary property conceptually for n nodes visits each node once.
│ - Each node child-count check is constant.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Tree stores n nodes.
│ - Skewed traversal stack can become n.
│ -> Space Complexity = O(n).
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
    cout << "Binary Tree rule: every node has at most 2 children.\n";
    cout << "Valid children counts: 0, 1, or 2. Invalid: 3 or more.\n";
    cout << "Skewed tree can behave like linked list; perfect tree is fully filled.\n";
    return 0;
}

/*
OUTPUT:
Binary Tree rule: every node has at most 2 children.
Valid children counts: 0, 1, or 2. Invalid: 3 or more.
Skewed tree can behave like linked list; perfect tree is fully filled.
*/

