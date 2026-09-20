/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_height_balanced_check_approach2.cpp
│
│ REAL-WORLD SCENARIO:
│ Team audit me har manager ek hi report bheje: meri height kya hai aur meri team balanced hai ya nahi. Optimized method height+check combo return karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function pair height and balanced return kare.
│ 2. Left subtree report lo.
│ 3. Right subtree report lo.
│ 4. Current height=max(left.height,right.height)+1.
│ 5. Current balanced = leftBalanced && rightBalanced && diff<=1.
│ 6. Har node once process hota hai.
│
│ ASCII VISUAL / TREE STATE:
│ Balanced tree:
│        1
│      /   \
│     2     3
│    / \     \
│   4   5     7
│
│ Leaves return height1 balanced true.
│ Node2 height2 balanced true.
│ Node3 height2 balanced true.
│ Root diff=0 -> balanced true.
│
│ Optimized avoids repeated height() calls.
│
│ DRY RUN:
│ node4->{1,true}, node5->{1,true}, node2->{2,true}.
│ node7->{1,true}, node3->{2,true}.
│ root->{3,true}.
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - Each node processed once.
│ - Constant combine work per node.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h.
│ -> Space Complexity = O(h), worst O(n).
│ APPROACH COMPARISON TABLE:
│ Naive = har manager se height report baar-baar manga, O(n²) worst/O(h) stack.
│ Optimized = height+balanced ek report, O(n) time/O(h) stack.
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
    root->right->right = new Node(7);
    return root;
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
struct BalanceInfo {
    int height;
    bool balanced;
};
BalanceInfo checkBalanced(Node* root) {
    if (root == nullptr) return {0, true};
    BalanceInfo left = checkBalanced(root->left);
    BalanceInfo right = checkBalanced(root->right);
    int h = max(left.height, right.height) + 1;
    bool ok = left.balanced && right.balanced && abs(left.height - right.height) <= 1;
    return {h, ok};
}
int main(){
    Node* root=sampleTree();
    BalanceInfo ans=checkBalanced(root);
    cout << "Height = " << ans.height << "\n";
    cout << "Balanced optimized? " << (ans.balanced ? "YES" : "NO") << "\n";
    cout << "Comparison: naive O(n^2), optimized O(n).\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Height = 3
Balanced optimized? YES
Comparison: naive O(n^2), optimized O(n).
*/

