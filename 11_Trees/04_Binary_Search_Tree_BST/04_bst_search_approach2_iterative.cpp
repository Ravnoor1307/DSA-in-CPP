/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_bst_search_approach2_iterative.cpp
│
│ REAL-WORLD SCENARIO:
│ Dictionary me recursion ki jagah finger pointer se page move karte jao: left ya right. Iterative BST search stack space bachata hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. current=root set karo.
│ 2. Jab tak current null nahi, compare key.
│ 3. Equal -> found.
│ 4. Smaller -> current=current->left.
│ 5. Larger -> current=current->right.
│ 6. No recursion, so O(1) extra space.
│
│ ASCII VISUAL / BST STATE:
│ Search 40:
│ current 50: 40<50 -> left
│ current 30: 40>30 -> right
│ current 40: found
│
│ Path arrows: 50 -> 30 -> 40
│
│ DRY RUN:
│ current=50, key40 smaller.
│ current=30, key40 larger.
│ current=40, match return true.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - One comparison per level on search path.
│ - Path length = h.
│ -> Time Complexity = O(h).
│
│ SPACE COMPLEXITY CALCULATION:
│ - current pointer only.
│ -> Extra Space Complexity = O(1).
│ APPROACH COMPARISON TABLE:
│ Recursive search = assistant follows dictionary branches, O(h) time/O(h) stack.
│ Iterative search = one finger pointer moves branches, O(h) time/O(1) space.
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
bool searchIterative(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        cout << "visit " << current->data << "\n";
        if (current->data == key) return true;
        if (key < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

int main() {
    Node* root = buildBST();
    bool found = searchIterative(root, 40);
    cout << "Search 40 = " << (found ? "FOUND" : "NOT FOUND") << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
visit 50
visit 30
visit 40
Search 40 = FOUND
*/

