/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_lowest_common_ancestor_bst.cpp
│
│ REAL-WORLD SCENARIO:
│ Family tree sorted dictionary style BST hai. Do members ke paths jahan diverge hote hain, wahi lowest common ancestor hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. BST property use karo.
│ 2. Agar both values root se smaller hain, LCA left subtree me hoga.
│ 3. Agar both values root se greater hain, LCA right subtree me hoga.
│ 4. Otherwise current root split point hai, so LCA.
│ 5. Path diverge visual yaad rakho.
│ 6. Time height h tak path follow karta hai.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│
│ LCA(20,40):
│ root50: both 20,40 < 50 -> go left
│ root30: 20 < 30 and 40 > 30 -> paths diverge
│ answer = 30
│
│ DRY RUN:
│ p=20,q=40.
│ current50: both smaller, move to30.
│ current30: one smaller one greater, return30.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - Each step moves one level down.
│ - Number of steps = height h.
│ -> Time Complexity = O(h).
│ - Balanced h=log n, skewed h=n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Iterative version uses current pointer only.
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
Node* insertBST(Node* root, int key){
    if(!root) return new Node(key);
    if(key < root->data) root->left = insertBST(root->left, key);
    else if(key > root->data) root->right = insertBST(root->right, key);
    return root;
}
Node* buildBST(){ Node* root=nullptr; for(int x:{50,30,70,20,40,60,80}) root=insertBST(root,x); return root; }
void deleteTree(Node* root){ if(!root)return; deleteTree(root->left); deleteTree(root->right); delete root; }
Node* lcaBST(Node* root, int p, int q) {
    while (root != nullptr) {
        if (p < root->data && q < root->data) root = root->left;
        else if (p > root->data && q > root->data) root = root->right;
        else return root; // split point
    }
    return nullptr;
}
int main(){
    Node* root=buildBST();
    Node* ans=lcaBST(root,20,40);
    cout << "LCA in BST of 20 and 40 = " << (ans ? ans->data : -1) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
LCA in BST of 20 and 40 = 30
*/

