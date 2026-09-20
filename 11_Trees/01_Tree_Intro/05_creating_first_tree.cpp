/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_creating_first_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ File explorer me root folder ke andar left/right folders manually create kar sakte ho. Binary tree me nodes manually allocate karke pointers connect karte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Root node create karo.
│ 2. root->left and root->right assign karo.
│ 3. Children ke bhi left/right assign kar sakte hain.
│ 4. Har pointer ek edge represent karta hai.
│ 5. Final structure ko traversal se verify karo.
│
│ ASCII VISUAL / TREE STATE:
│ Manual tree:
│
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     6
│
│ Pointer connections:
│ root->left = 2
│ root->right = 3
│ node2->left = 4
│ node2->right = 5
│ node3->right = 6
│
│ DRY RUN:
│ Create 1.
│ Attach 2 and 3.
│ Attach 4 and 5 below 2.
│ Attach 6 as right of 3.
│ Preorder verification: 1 2 4 5 3 6.
│
│ FLOW OF EXECUTION:
│ main -> create/describe tree -> pointer/term logic -> output
│
│ COMPLEXITY CALCULATION:
│ - Creating n nodes needs n allocations.
│ - Connecting n-1 edges needs n-1 pointer assignments.
│ - Traversal verification visits n nodes.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Tree stores n nodes.
│ - Recursion stack for traversal can be height h, worst n.
│ -> Space Complexity = O(n) storage, O(h) traversal stack.
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

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder of created tree: ";
    preorder(root);
    cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Preorder of created tree: 1 2 4 5 3 6
*/

