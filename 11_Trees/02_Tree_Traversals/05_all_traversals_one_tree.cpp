/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_all_traversals_one_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Same city map ko tourist, cleaner, aur inspector different route se visit kar sakte hain. Same tree ke inorder/preorder/postorder outputs different hote hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Same tree use karo.
│ 2. Inorder rule: LEFT ROOT RIGHT.
│ 3. Preorder rule: ROOT LEFT RIGHT.
│ 4. Postorder rule: LEFT RIGHT ROOT.
│ 5. Trick: root kahan aata hai — PRE means pehle, IN means beech, POST means last.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ MASTER VISUAL:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Preorder:  root pehle -> 1 2 4 5 3 6 7
│ Inorder:   root beech  -> 4 2 5 1 6 3 7
│ Postorder: root last   -> 4 5 2 6 7 3 1
│
│ Memory trick: in(pre-POST): root position changes.
│
│ DRY RUN:
│ Root=1.
│ Preorder starts with 1.
│ Inorder has complete left subtree before 1.
│ Postorder ends with 1.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Each traversal visits n nodes.
│ - Three traversals visit 3n nodes total.
│ -> Time Complexity = O(3n) = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Each DFS traversal stack height h.
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

void inorder(Node* root){ if(!root)return; inorder(root->left); cout<<root->data<<" "; inorder(root->right); }
void preorder(Node* root){ if(!root)return; cout<<root->data<<" "; preorder(root->left); preorder(root->right); }
void postorder(Node* root){ if(!root)return; postorder(root->left); postorder(root->right); cout<<root->data<<" "; }

int main() {
    Node* root = sampleTree();
    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Preorder: 1 2 4 5 3 6 7
Inorder: 4 2 5 1 6 3 7
Postorder: 4 5 2 6 7 3 1
*/

