/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_Tree_Properties task.cpp
│
│ REAL-WORLD SCENARIO:
│ Tree property lab me ek family/company tree ki height, count, leaves, max, search, and diameter measure karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Height of tree calculate karo.
│ 2. Total nodes count karo.
│ 3. Leaf nodes count karo.
│ 4. Max element in normal binary tree find karo.
│ 5. Search in normal binary tree implement karo.
│ 6. Diameter naive using height() at every node.
│ 7. Diameter optimized using height+diameter pair.
│ 8. Diameter cases through-root/not-through-root comments me draw karo.
│
│ HINTS:
│ - height: max(left,right)+1.
│ - count: left+right+1.
│ - leaf: both children null.
│ - normal tree search is O(n), not O(log n).
│
│ STARTER CODE:
│ int height(Node* root){ if(!root)return 0; return max(height(root->left),height(root->right))+1; }
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Sample tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│ height=3, total=6, leaves=3, diameter=5 nodes.
│
│ DRY RUN:
│ height leaves=1.
│ height node2=2, node3=2.
│ root height=3.
│ diameter through root = 2+2+1=5.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - Height/count/leaves/max/search each node once -> O(n).
│ - Naive diameter skewed repeated height sum n(n+1)/2 -> O(n²).
│ - Optimized diameter each node once -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive stack O(h), worst skewed O(n).
│ - Optimized pair adds constant data per call.
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

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int height(Node* r){ return r ? max(height(r->left),height(r->right))+1 : 0; }
int count(Node* r){ return r ? count(r->left)+count(r->right)+1 : 0; }
int leaves(Node* r){ if(!r)return 0; if(!r->left && !r->right)return 1; return leaves(r->left)+leaves(r->right); }
struct Info{int height; int diameter;};
Info solveDia(Node* r){
    if(!r)return {0,0};
    Info L=solveDia(r->left), R=solveDia(r->right);
    int h=max(L.height,R.height)+1;
    int d=max(L.height+R.height+1,max(L.diameter,R.diameter));
    return {h,d};
}
int main(){
    Node* root=sampleTree();
    cout << "height=" << height(root) << "\n";
    cout << "count=" << count(root) << "\n";
    cout << "leaves=" << leaves(root) << "\n";
    cout << "diameter=" << solveDia(root).diameter << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
height=3
count=6
leaves=3
diameter=5
*/

