/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_diameter_approach1_naive.cpp
│
│ REAL-WORLD SCENARIO:
│ Tree ke two farthest leaves ke beech longest road diameter hai. Naive method har node par left/right height nikal kar through-root path check karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Diameter = longest path between any two nodes, measured in nodes here.
│ 2. For each node, possible diameter through node = height(left)+height(right)+1.
│ 3. Also diameter left subtree me ho sakta hai.
│ 4. Also diameter right subtree me ho sakta hai.
│ 5. Naive approach har node par height() baar-baar call karta hai.
│ 6. Repeated height calculations O(n²) worst banate hain.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ Through root path example: 4 -> 2 -> 1 -> 3 -> 7 = 5 nodes
│ Diameter can be:
│ - through current root
│ - completely in left subtree
│ - completely in right subtree
│
│ DRY RUN:
│ At root1:
│ leftHeight=2, rightHeight=2 -> through=5.
│ leftDiameter=3 (4-2-5).
│ rightDiameter=2 (3-7).
│ max=5.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - diameter() visits n nodes.
│ - At each node, height() can scan its subtree.
│ - In skewed tree, height work = n + (n-1) + ... + 1 = n(n+1)/2.
│ -> Time Complexity = O(n²) worst.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack for diameter/height is height h.
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
int height(Node* root){
    if(root==nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameterNaive(Node* root){
    if(root==nullptr) return 0;
    int throughRoot = height(root->left) + height(root->right) + 1;
    int leftDia = diameterNaive(root->left);
    int rightDia = diameterNaive(root->right);
    return max(throughRoot, max(leftDia, rightDia));
}
int main(){
    Node* root=sampleTree();
    cout << "Diameter naive (nodes) = " << diameterNaive(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Diameter naive (nodes) = 5
*/

