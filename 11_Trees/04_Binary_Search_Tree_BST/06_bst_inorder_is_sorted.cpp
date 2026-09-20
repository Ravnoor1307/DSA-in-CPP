/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_bst_inorder_is_sorted.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted dictionary tree ko left page, word, right page order me read karoge to words sorted milenge. BST inorder golden property hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Inorder = LEFT ROOT RIGHT.
│ 2. BST left subtree me smaller values hoti hain.
│ 3. Root middle me aata hai.
│ 4. Right subtree me greater values hoti hain.
│ 5. Therefore inorder output sorted ascending hota hai.
│ 6. Use cases: kth smallest, validate BST, sorted listing.
│
│ ASCII VISUAL / BST STATE:
│ BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│
│ Inorder:
│ left subtree sorted: 20 30 40
│ root: 50
│ right subtree sorted: 60 70 80
│ output: 20 30 40 50 60 70 80
│
│ DRY RUN:
│ inorder(50):
│ inorder(30) prints 20 30 40.
│ print 50.
│ inorder(70) prints 60 70 80.
│ full sorted.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Inorder visits every node once.
│ - n nodes => n prints/checks.
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
void collectInorder(Node* root, vector<int>& values) {
    if (!root) return;
    collectInorder(root->left, values);
    values.push_back(root->data);
    collectInorder(root->right, values);
}
int main(){
    Node* root=buildBST();
    vector<int> values;
    collectInorder(root, values);
    cout << "BST inorder sorted: ";
    for(int x:values) cout << x << " ";
    cout << "\nIs sorted? " << (is_sorted(values.begin(), values.end()) ? "YES" : "NO") << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
BST inorder sorted: 20 30 40 50 60 70 80
Is sorted? YES
*/

