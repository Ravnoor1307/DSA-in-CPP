/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_same_level_sum_k.cpp
│
│ REAL-WORLD SCENARIO:
│ Building ke same floor par rooms ka total rent nikalna hai. Tree me level k ke nodes ka sum level-wise recursion/queue se nikal sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Level convention: root level = 1.
│ 2. If root null, sum 0.
│ 3. If k==1, current node data return.
│ 4. Otherwise left level k-1 + right level k-1.
│ 5. This recursively target level tak depth reduce karta hai.
│
│ ASCII VISUAL / TREE STATE:
│ Tree:
│          1        level 1
│        /   \
│       2     3     level 2
│      / \     \
│     4   5     7   level 3
│
│ k=3 sum = 4 + 5 + 7 = 16
│
│ DRY RUN:
│ sumLevel(root,3)
│ = sumLevel(2,2)+sumLevel(3,2)
│ = (sumLevel(4,1)+sumLevel(5,1)) + (0+sumLevel(7,1))
│ = 4+5+7=16
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - In worst case, recursion visits nodes until level k.
│ - If k is height or larger, may visit all n nodes.
│ -> Time Complexity = O(n) worst.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack depth k or h.
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
int sumAtLevel(Node* root, int k) {
    if (root == nullptr) return 0;
    if (k == 1) return root->data;
    return sumAtLevel(root->left, k - 1) + sumAtLevel(root->right, k - 1);
}
int main(){
    Node* root=sampleTree();
    int k=3;
    cout << "Sum at level " << k << " = " << sumAtLevel(root,k) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Sum at level 3 = 16
*/

