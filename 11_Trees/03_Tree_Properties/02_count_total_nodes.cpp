/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_count_total_nodes.cpp
│
│ REAL-WORLD SCENARIO:
│ Company org chart me total employees count karne ke liye left team count + right team count + current manager count hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty subtree has 0 nodes.
│ 2. Left subtree nodes recursively count karo.
│ 3. Right subtree nodes recursively count karo.
│ 4. Total = left + right + 1 for root.
│ 5. This left + right + root pattern trees me very common hai.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \     \
│     4   5     7
│
│ count(2)=count(4)+count(5)+1=1+1+1=3
│ count(3)=0+1+1=2
│ count(1)=3+2+1=6
│
│ DRY RUN:
│ Leaves 4,5,7 return 1 each.
│ Node2 returns 3.
│ Node3 returns 2.
│ Root returns 6.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - Each node counted once.
│ - For n nodes, n real node calls plus null calls.
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
int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
    Node* root = sampleTree();
    cout << "Total nodes = " << countNodes(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Total nodes = 6
*/

