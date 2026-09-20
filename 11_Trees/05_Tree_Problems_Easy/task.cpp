/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_Tree_Problems_Easy task.cpp
│
│ REAL-WORLD SCENARIO:
│ Easy tree practice lab me mirror, identical, sum, balance, and level-sum problems solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Mirror tree implement karo.
│ 2. Identical trees check karo.
│ 3. Sum of all nodes calculate karo.
│ 4. Height balanced check naive approach.
│ 5. Height balanced check optimized height+bool approach.
│ 6. Level k sum calculate karo.
│ 7. Before/after mirror diagram comments me draw karo.
│ 8. Naive vs optimized balanced table likho.
│
│ HINTS:
│ - Mirror: swap children then recurse.
│ - Identical: dono null true, one null false.
│ - Balanced: diff <= 1 at every node.
│ - Level sum: root level = 1.
│
│ STARTER CODE:
│ if(root==nullptr) return ...;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / TREE STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│ sum=22, level3 sum=16, leaves=4,5,7
│
│ DRY RUN:
│ Mirror preorder before: 1 2 4 5 3 7
│ after: 1 3 7 2 5 4
│ balanced optimized returns height3 true.
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - Mirror/sum/identical visit each node once -> O(n).
│ - Naive balance repeats height, skewed sum n(n+1)/2 -> O(n²).
│ - Optimized balance one report per node -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive stack O(h), worst skewed O(n).
│ - Tree storage O(n).
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
int sum(Node* r){ return r ? r->data + sum(r->left) + sum(r->right) : 0; }
void mirror(Node* r){ if(!r)return; swap(r->left,r->right); mirror(r->left); mirror(r->right); }
int levelSum(Node* r,int k){ if(!r)return 0; if(k==1)return r->data; return levelSum(r->left,k-1)+levelSum(r->right,k-1); }
int main(){
    Node* root=sampleTree();
    cout << "sum=" << sum(root) << "\n";
    cout << "level3 sum=" << levelSum(root,3) << "\n";
    mirror(root);
    cout << "mirror preorder: "; preorder(root); cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
sum=22
level3 sum=16
mirror preorder: 1 3 7 2 5 4
*/

