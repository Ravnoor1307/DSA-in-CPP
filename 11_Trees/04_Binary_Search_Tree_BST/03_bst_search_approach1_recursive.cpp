/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_bst_search_approach1_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted dictionary tree me target word chhota ho to left pages, bada ho to right pages. Recursive BST search same comparison se half tree discard karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: root null -> not found.
│ 2. If key == root->data -> found.
│ 3. If key < root->data -> search left.
│ 4. If key > root->data -> search right.
│ 5. Har step me ek subtree discard hota hai.
│
│ ASCII VISUAL / BST STATE:
│ BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│
│ Search 60:
│ 60 > 50 -> discard left subtree, go right
│ 60 < 70 -> discard right of 70, go left
│ 60 == 60 found
│
│ DRY RUN:
│ recursiveSearch(50,60)
│ -> recursiveSearch(70,60)
│ -> recursiveSearch(60,60)
│ -> true
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Search follows one path from root to leaf.
│ - Path length = height h.
│ -> Time Complexity = O(h).
│ - Balanced h=log n, skewed h=n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive stack depth h.
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
bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    cout << "visit " << root->data << "\n";
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

int main() {
    Node* root = buildBST();
    bool found = searchRecursive(root, 60);
    cout << "Search 60 = " << (found ? "FOUND" : "NOT FOUND") << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
visit 50
visit 70
visit 60
Search 60 = FOUND
*/

