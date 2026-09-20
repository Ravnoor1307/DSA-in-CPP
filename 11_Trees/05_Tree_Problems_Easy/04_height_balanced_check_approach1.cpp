/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_height_balanced_check_approach1.cpp
│
│ REAL-WORLD SCENARIO:
│ Company teams balanced tab hain jab har manager ke left/right teams ki height difference at most 1 ho. Naive method har node par height dobara calculate karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Balanced condition: abs(leftHeight-rightHeight) <= 1 at every node.
│ 2. Naive check current node par height(left) and height(right) call karta hai.
│ 3. Then left subtree balanced and right subtree balanced recursively check karta hai.
│ 4. Height repeated calculate hoti hai.
│ 5. Worst skewed tree me O(n²).
│
│ ASCII VISUAL / TREE STATE:
│ Unbalanced tree:
│      1
│     /
│    2
│   /
│  3
│ /
│4
│
│ At root:
│ leftHeight=3, rightHeight=0, diff=3 -> not balanced
│
│ Repeated work: height(2) computed during root check, then again inside balanced(2).
│
│ DRY RUN:
│ height(left of 1)=3, height(right)=0.
│ diff=3 > 1, return false.
│ For many shapes, repeated height calls create high cost.
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - At each node, height() may scan its subtree.
│ - Skewed tree work: n + (n-1) + ... + 1 = n(n+1)/2.
│ -> Time Complexity = O(n²) worst.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h for height/check.
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

struct Node { int data; Node* left; Node* right; Node(int v):data(v),left(nullptr),right(nullptr){} };
void deleteTree(Node* r){ if(!r)return; deleteTree(r->left); deleteTree(r->right); delete r; }
int height(Node* root){ return root ? max(height(root->left), height(root->right)) + 1 : 0; }
bool isBalancedNaive(Node* root) {
    if (root == nullptr) return true;
    int leftH = height(root->left);
    int rightH = height(root->right);
    if (abs(leftH - rightH) > 1) return false;
    return isBalancedNaive(root->left) && isBalancedNaive(root->right);
}
int main(){
    Node* root=new Node(1); root->left=new Node(2); root->left->left=new Node(3); root->left->left->left=new Node(4);
    cout << "Balanced naive? " << (isBalancedNaive(root) ? "YES" : "NO") << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Balanced naive? NO
*/

