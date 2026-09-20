/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_postorder_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ Folder delete karni ho to pehle andar ke files/subfolders delete karte hain, phir folder. Postorder LEFT → RIGHT → ROOT tree delete ke liye perfect hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: root null, return.
│ 2. Left subtree pehle process.
│ 3. Right subtree process.
│ 4. Root sabse last visit.
│ 5. Uses: delete tree safely, postfix expressions.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Same tree postorder visit numbers:
│          1(7)
│        /      \
│     2(3)      3(6)
│    /   \      /   \
│ 4(1) 5(2)  6(4) 7(5)
│
│ Output: 4 5 2 6 7 3 1
│
│ Delete logic: children first, parent last.
│
│ DRY RUN:
│ postorder(1): left subtree 4 5 2.
│ right subtree 6 7 3.
│ root 1 last.
│ This order avoids deleting parent before children.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Each node visited once.
│ - Work per node constant.
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

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);        // LEFT
    postorder(root->right);       // RIGHT
    cout << root->data << " ";    // ROOT last
}

int main() {
    Node* root = sampleTree();
    cout << "Postorder: ";
    postorder(root);
    cout << "\nUse: delete tree and postfix expressions.\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Postorder: 4 5 2 6 7 3 1
Use: delete tree and postfix expressions.
*/

