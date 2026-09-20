/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_count_leaf_nodes.cpp
│
│ REAL-WORLD SCENARIO:
│ Org chart me employees jinke under koi report nahi, woh leaf employees hain. Tree leaf node ke left and right dono null hote hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty tree leaf count 0.
│ 2. If left==nullptr and right==nullptr, node is leaf, return 1.
│ 3. Otherwise leaf count = left leaf count + right leaf count.
│ 4. Har node check hota hai.
│ 5. Leaf definition interview me important hai.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ Leaves: 4, 5, 7
│ leaf count = 3
│
│ DRY RUN:
│ node4 left null and right null -> 1.
│ node5 -> 1.
│ node7 -> 1.
│ node2 combines 2, node3 combines 1, root combines 3.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - Each node visited once and leaf condition checked.
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
int countLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = sampleTree();
    cout << "Leaf nodes = " << countLeaves(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Leaf nodes = 3
*/

