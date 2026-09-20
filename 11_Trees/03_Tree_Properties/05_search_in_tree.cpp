/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_search_in_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Unsorted file cabinet me target file dhundhni hai. BST nahi hai, so sorted direction nahi milti; tree ke nodes linearly search karne padte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty node means target absent in that branch.
│ 2. Agar root->data target hai, true.
│ 3. Left subtree search karo.
│ 4. Right subtree search karo.
│ 5. Normal binary tree me ordering nahi hoti, so half discard nahi kar sakte.
│ 6. Worst case all nodes visit karne padte hain.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ Search 7:
│ 1 not, search left 2/4/5 not, search right 3 then 7 found
│
│ ⚠️ BST nahi hai toh linear hi search hoga!
│
│ DRY RUN:
│ search(1): not 7.
│ search(2): not 7; leaves 4,5 not.
│ search(3): not 7; right child 7 found.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - Worst case target absent or last visited.
│ - Every node may be checked once.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h.
│ -> Space Complexity = O(h), worst O(n).
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

Node* sampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    return root;
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
bool searchTree(Node* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    return searchTree(root->left, target) || searchTree(root->right, target);
}

int main() {
    Node* root = sampleTree();
    cout << "Search 7 = " << (searchTree(root, 7) ? "FOUND" : "NOT FOUND") << "\n";
    cout << "Normal tree is not BST, so worst search is O(n).\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Search 7 = FOUND
Normal tree is not BST, so worst search is O(n).
*/

