/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_sum_of_all_nodes.cpp
│
│ REAL-WORLD SCENARIO:
│ Company payroll tree me total salary nikalni hai. Har manager/node ka salary plus left team plus right team sum hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty subtree sum 0.
│ 2. Left subtree sum recursively nikaalo.
│ 3. Right subtree sum recursively nikaalo.
│ 4. Total = root->data + leftSum + rightSum.
│ 5. Har node exactly once add hota hai.
│
│ ASCII VISUAL / TREE STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ sum = 1+2+3+4+5+7 = 22
│
│ Formula at root:
│ sum(1)=1+sum(2)+sum(3)=1+11+10=22
│
│ DRY RUN:
│ leaves return 4,5,7.
│ node2 returns 2+4+5=11.
│ node3 returns 3+0+7=10.
│ root returns 1+11+10=22.
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - Each node contributes once.
│ - n nodes => n additions.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h.
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
int sumNodes(Node* root) {
    if (root == nullptr) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int main(){
    Node* root=sampleTree();
    cout << "Sum of all nodes = " << sumNodes(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Sum of all nodes = 22
*/

