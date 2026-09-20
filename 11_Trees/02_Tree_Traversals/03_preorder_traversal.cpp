/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_preorder_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ Company org chart copy karni ho to pehle manager/root create karo, phir uski teams. Preorder ROOT → LEFT → RIGHT tree copy ke liye useful hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: root null, return.
│ 2. Root ko pehle visit/print karo.
│ 3. Left subtree traverse karo.
│ 4. Right subtree traverse karo.
│ 5. Uses: tree copy, prefix expressions, serialization preview.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Same tree preorder visit numbers:
│          1(1)
│        /      \
│     2(2)      3(5)
│    /   \      /   \
│ 4(3) 5(4)  6(6) 7(7)
│
│ Output: 1 2 4 5 3 6 7
│
│ Compare inorder: 4 2 5 1 6 3 7
│
│ DRY RUN:
│ preorder(1): print1.
│ go left 2: print2, then 4,5.
│ go right 3: print3, then 6,7.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Each real node printed once: n prints.
│ - Each edge followed constant times.
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

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";    // ROOT first
    preorder(root->left);         // LEFT
    preorder(root->right);        // RIGHT
}

int main() {
    Node* root = sampleTree();
    cout << "Preorder: ";
    preorder(root);
    cout << "\nUse: tree copy and prefix expressions.\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Preorder: 1 2 4 5 3 6 7
Use: tree copy and prefix expressions.
*/

