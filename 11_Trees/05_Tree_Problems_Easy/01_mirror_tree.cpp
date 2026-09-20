/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_mirror_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Mirror me left side right ban jati hai aur right side left. Tree mirror banane ke liye har node ke left/right children swap karte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: root null, return.
│ 2. Current node ke left and right pointers swap karo.
│ 3. Recursively left subtree mirror karo.
│ 4. Recursively right subtree mirror karo.
│ 5. Har node par exactly one swap hota hai.
│
│ ASCII VISUAL / TREE STATE:
│ Before:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ After mirror:
│          1
│        /   \
│       3     2
│      /     / \
│     7     5   4
│
│ DRY RUN:
│ root1 swap left2/right3.
│ node3 old right7 becomes left7.
│ node2 swaps children 4 and5 -> 5 and4.
│ preorder before 1 2 4 5 3 7.
│ preorder after 1 3 7 2 5 4.
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - Each node visited once.
│ - Each node one pointer swap.
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
void mirror(Node* root) {
    if (root == nullptr) return;
    swap(root->left, root->right); // Hinglish: left/right children ulte
    mirror(root->left);
    mirror(root->right);
}

int main() {
    Node* root = sampleTree();
    cout << "Before mirror preorder: "; preorder(root); cout << "\n";
    mirror(root);
    cout << "After mirror preorder: "; preorder(root); cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Before mirror preorder: 1 2 4 5 3 7
After mirror preorder: 1 3 7 2 5 4
*/

