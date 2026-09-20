/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_height_of_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ File explorer me kisi folder ki depth deepest nested file tak count karni ho to height nikalte hain. Tree height root se deepest leaf tak levels ka count hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty tree height 0.
│ 2. Leaf node height 1.
│ 3. Left subtree height recursively nikalo.
│ 4. Right subtree height recursively nikalo.
│ 5. Current height = max(leftHeight, rightHeight) + 1.
│ 6. Heights bottom se upar propagate hote hain.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ Levels count:
│ Level 1: 1
│ Level 2: 2,3
│ Level 3: 4,5,7
│ height = 3
│
│ Formula at root:
│ height(1)=max(height(2),height(3))+1=max(2,2)+1=3
│
│ DRY RUN:
│ height(4)=1, height(5)=1, height(7)=1.
│ height(2)=max(1,1)+1=2.
│ height(3)=max(0,1)+1=2.
│ height(1)=max(2,2)+1=3.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - height() is called once for every node.
│ - Also null child calls happen, about n+1.
│ - Total calls ≈ 2n+1.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack depth equals height h.
│ - Worst skewed h=n, balanced h=log n.
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
int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1; // max child height + root level
}

int main() {
    Node* root = sampleTree();
    cout << "Height of tree = " << height(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Height of tree = 3
*/

