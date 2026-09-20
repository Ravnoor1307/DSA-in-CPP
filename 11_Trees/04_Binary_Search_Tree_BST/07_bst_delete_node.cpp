/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_bst_delete_node.cpp
│
│ REAL-WORLD SCENARIO:
│ Dictionary tree se word delete karte time 3 cases hote hain: leaf word, one-child word, ya two-children word jahan successor replace karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Pehle key search karo using BST comparisons.
│ 2. Case 1 leaf: directly delete and return null.
│ 3. Case 2 one child: child ko upar return karo.
│ 4. Case 3 two children: inorder successor (right subtree minimum) find karo.
│ 5. Root data successor se replace karo.
│ 6. Successor node ko right subtree se delete karo.
│
│ ASCII VISUAL / BST STATE:
│ Initial BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│
│ CASE 1 leaf delete 20:
│ 30->left becomes NULL
│
│ CASE 2 one child delete 30 after 20 gone:
│      30
│        \
│        40
│ child 40 moves up
│
│ CASE 3 two children delete 50:
│ successor = min(right subtree)=60
│ replace 50 by 60, then delete old 60
│
│ DRY RUN:
│ delete20: found leaf, return null.
│ delete30: node has only right child 40, return 40.
│ delete50: two children, successor60, root data becomes60, delete60 from right subtree.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Search/delete follows one root-to-target path height h.
│ - In two-child case, successor search walks left in right subtree, at most h.
│ - Total work proportional to h+h = 2h.
│ -> Time Complexity = O(h).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive delete stack depth h.
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

Node* insertBST(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else if (key > root->data) root->right = insertBST(root->right, key);
    return root;
}

Node* buildBST() {
    Node* root = nullptr;
    for (int x : {50,30,70,20,40,60,80}) root = insertBST(root, x);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) { // case 1 leaf
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) { // case 2 one right child
            Node* child = root->right;
            delete root;
            return child;
        }
        if (root->right == nullptr) { // case 2 one left child
            Node* child = root->left;
            delete root;
            return child;
        }
        Node* succ = minNode(root->right); // case 3 inorder successor
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int main(){
    Node* root=buildBST();
    cout << "Initial inorder: "; inorder(root); cout << "\n";
    root = deleteNode(root, 20);
    cout << "After deleting leaf 20: "; inorder(root); cout << "\n";
    root = deleteNode(root, 30);
    cout << "After deleting one-child 30: "; inorder(root); cout << "\n";
    root = deleteNode(root, 50);
    cout << "After deleting two-child 50: "; inorder(root); cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Initial inorder: 20 30 40 50 60 70 80
After deleting leaf 20: 30 40 50 60 70 80
After deleting one-child 30: 40 50 60 70 80
After deleting two-child 50: 40 60 70 80
*/

