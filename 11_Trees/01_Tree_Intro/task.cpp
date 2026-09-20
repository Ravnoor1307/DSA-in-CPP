/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_Tree_Intro task.cpp
│
│ REAL-WORLD SCENARIO:
│ Tree intro practice lab me org chart tree create karna, terms label karna, and node pointers samajhne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Tree and linear list ka difference comments me draw karo.
│ 2. Node struct banao with data,left,right.
│ 3. Root 1 with children 2 and 3 create karo.
│ 4. Node 2 ke children 4 and 5 attach karo.
│ 5. Root, leaf, parent, child, sibling terms identify karo.
│ 6. Skewed and perfect binary tree diagrams comments me draw karo.
│ 7. Preorder traversal se created tree verify karo.
│
│ HINTS:
│ - Binary tree node has max 2 children.
│ - Leaf: left==nullptr && right==nullptr.
│ - Edge pointer connection hota hai.
│
│ STARTER CODE:
│ struct Node { int data; Node* left; Node* right; };
│
│ SOLUTION: Neeche compiled demo hai.
│
│ ASCII VISUAL / TREE STATE:
│ Created tree:
│      1
│    /   \
│   2     3
│  / \
│ 4   5
│ Leaves: 4,5,3
│ Siblings: 2 and 3, also 4 and 5
│
│ DRY RUN:
│ Create root=1.
│ Attach left=2, right=3.
│ Attach 4,5 under 2.
│ Preorder prints 1 2 4 5 3.
│
│ FLOW OF EXECUTION:
│ main -> create/describe tree -> pointer/term logic -> output
│
│ COMPLEXITY CALCULATION:
│ - Creating 5 nodes = 5 allocations.
│ - Connecting 4 edges = 4 assignments.
│ - Preorder visits 5 nodes.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Tree stores n nodes.
│ - Traversal stack height h, worst n.
│ -> Space Complexity = O(n) storage, O(h) stack.
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
void preorder(Node* root){
    if(root==nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void deleteTree(Node* root){
    if(root==nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Root=1, Leaves=4,5,3, Parent of 4=2\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Preorder: 1 2 4 5 3
Root=1, Leaves=4,5,3, Parent of 4=2
*/

