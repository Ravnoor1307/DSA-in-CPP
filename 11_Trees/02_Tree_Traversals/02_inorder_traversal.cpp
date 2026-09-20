/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_inorder_traversal.cpp
│
│ REAL-WORLD SCENARIO:
│ File explorer me left folder pehle open karo, phir current folder name read karo, phir right folder. Inorder traversal ka rule LEFT → ROOT → RIGHT hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: root == nullptr, return.
│ 2. Pehle left subtree traverse.
│ 3. Phir root visit/print.
│ 4. Phir right subtree traverse.
│ 5. BST me inorder sorted order deta hai.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Tree with visit numbers for inorder:
│          1(4)
│        /      \
│     2(2)      3(6)
│    /   \      /   \
│ 4(1) 5(3)  6(5) 7(7)
│
│ Output: 4 2 5 1 6 3 7
│
│ Call stack idea:
│ inorder(1) -> inorder(2) -> inorder(4) -> null, print4, null -> print2 ...
│
│ DRY RUN:
│ inorder(1): go left to 2.
│ inorder(2): go left to 4.
│ inorder(4): left null, print 4, right null.
│ back to 2 print 2.
│ visit 5, then print 1, then right subtree 6 3 7.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Each node receives exactly one function call.
│ - Null children also produce calls, about n+1 null calls in binary tree.
│ - Total calls ≈ 2n+1, dominated by n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack depth equals tree height h.
│ - Balanced tree h=log n, skewed h=n.
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

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);          // LEFT
    cout << root->data << " ";    // ROOT
    inorder(root->right);         // RIGHT
}

int main() {
    Node* root = sampleTree();
    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Inorder: 4 2 5 1 6 3 7
*/

