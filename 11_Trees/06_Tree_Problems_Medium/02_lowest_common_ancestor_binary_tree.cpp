/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_lowest_common_ancestor_binary_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Normal family tree sorted nahi hai. Dono members ko left/right branches me recursively dhundho; jahan dono sides se answer aaye, wahi LCA.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base: root null -> null.
│ 2. Agar root p ya q hai, root return.
│ 3. Left subtree me p/q search karo.
│ 4. Right subtree me p/q search karo.
│ 5. Agar left and right dono non-null, current root LCA.
│ 6. Agar ek side non-null, wahi answer upar bhejo.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ Binary tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ LCA(4,5):
│ node2 ke left se 4 mila, right se 5 mila -> LCA=2
│
│ LCA(4,6):
│ root1 ke left se 4, right se 6 -> LCA=1
│
│ DRY RUN:
│ lca(1,4,5): search left node2 and right node3.
│ lca(2): left returns4, right returns5 -> return2.
│ root1 gets left2 and right null -> returns2.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - Normal binary tree has no ordering, so may visit all n nodes.
│ - Each node does constant combine after left/right calls.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h, worst n.
│ -> Space Complexity = O(h).
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
Node* lcaBT(Node* root, int p, int q) {
    if (root == nullptr) return nullptr;
    if (root->data == p || root->data == q) return root;
    Node* left = lcaBT(root->left, p, q);
    Node* right = lcaBT(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}
int main(){
    Node* root=sampleTree();
    Node* ans=lcaBT(root,4,5);
    cout << "LCA in binary tree of 4 and 5 = " << (ans ? ans->data : -1) << "\n";
    ans=lcaBT(root,4,6);
    cout << "LCA in binary tree of 4 and 6 = " << (ans ? ans->data : -1) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
LCA in binary tree of 4 and 5 = 2
LCA in binary tree of 4 and 6 = 1
*/

