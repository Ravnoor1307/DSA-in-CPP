/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_max_element_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Family event me sab branches me highest age find karni hai. Tree me max(root, max(left), max(right)) pattern use hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty subtree ka max INT_MIN maan sakte hain.
│ 2. Left subtree maximum recursively nikalo.
│ 3. Right subtree maximum recursively nikalo.
│ 4. Current answer = max(root->data, leftMax, rightMax).
│ 5. BST nahi hai, so every node check karna padega.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Tree values:
│          10
│        /    \
│       25     3
│      / \      \
│     4   50     7
│
│ max(25 subtree)=50
│ max(3 subtree)=7
│ root combine max(10,50,7)=50
│
│ DRY RUN:
│ leaf4 returns4, leaf50 returns50, node25 returns50.
│ leaf7 returns7, node3 returns7.
│ root10 returns50.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - Non-BST tree has no ordering guarantee.
│ - Must inspect all n nodes once.
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

struct Node { int data; Node* left; Node* right; Node(int v):data(v),left(nullptr),right(nullptr){} };
Node* sampleTree(){
    Node* root=new Node(10);
    root->left=new Node(25); root->right=new Node(3);
    root->left->left=new Node(4); root->left->right=new Node(50);
    root->right->right=new Node(7);
    return root;
}
void deleteTree(Node* r){ if(!r)return; deleteTree(r->left); deleteTree(r->right); delete r; }
int maxElement(Node* root) {
    if (root == nullptr) return INT_MIN;
    int leftMax = maxElement(root->left);
    int rightMax = maxElement(root->right);
    return max(root->data, max(leftMax, rightMax));
}
int main(){
    Node* root=sampleTree();
    cout << "Max element = " << maxElement(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Max element = 50
*/

