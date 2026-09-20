/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_bst_min_max.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted dictionary tree me sabse chhota word extreme left par aur sabse bada word extreme right par hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. BST property: left smaller, right greater.
│ 2. Minimum ke liye leftmost node tak walk karo.
│ 3. Maximum ke liye rightmost node tak walk karo.
│ 4. Har step one level move.
│ 5. Time O(h).
│
│ ASCII VISUAL / BST STATE:
│ BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│
│ Min path: 50 -> 30 -> 20 (leftmost)
│ Max path: 50 -> 70 -> 80 (rightmost)
│
│ DRY RUN:
│ min: current50 left exists -> 30, left exists -> 20, left null -> min20.
│ max: current50 right -> 70, right -> 80, right null -> max80.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Walk follows one branch of height h.
│ - One pointer move per level.
│ -> Time Complexity = O(h).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Iterative pointers only.
│ -> Extra Space Complexity = O(1).
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
int findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root->data;
}
int findMax(Node* root) {
    while (root->right != nullptr) root = root->right;
    return root->data;
}
int main(){
    Node* root=buildBST();
    cout << "Min = " << findMin(root) << "\n";
    cout << "Max = " << findMax(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Min = 20
Max = 80
*/

