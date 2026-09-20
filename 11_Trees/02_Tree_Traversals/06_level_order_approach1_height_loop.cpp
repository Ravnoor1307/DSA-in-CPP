/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_level_order_approach1_height_loop.cpp
│
│ REAL-WORLD SCENARIO:
│ Building inspection me floor 1, floor 2, floor 3 separately inspect karna hai. Height-loop approach har level ke liye tree ko root se dubara scan karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Pehle height calculate karo.
│ 2. level=1 to height tak loop.
│ 3. Har level ke liye printGivenLevel(root, level) call karo.
│ 4. printGivenLevel recursively target level nodes print karta hai.
│ 5. Skewed tree me har level ke liye almost full path scan hota hai, so O(n²) worst.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Levels:
│ level1: 1
│ level2: 2 3
│ level3: 4 5 6 7
│
│ Approach scans from root for each level.
│
│ DRY RUN:
│ height=3.
│ print level1 -> visits root.
│ print level2 -> root then children.
│ print level3 -> root, children, grandchildren.
│ output 1 2 3 4 5 6 7.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - height() visits n nodes once -> O(n).
│ - For each level, printGivenLevel can visit many nodes.
│ - Worst skewed height h=n, levels n, each call may scan path up to level.
│ - Work 1+2+3+...+n = n(n+1)/2.
│ -> Worst Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h for height/printGivenLevel.
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
    root->right->left = new Node(6);
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
    return max(height(root->left), height(root->right)) + 1;
}

void printGivenLevel(Node* root, int level) {
    if (root == nullptr) return;
    if (level == 1) cout << root->data << " ";
    else {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int main() {
    Node* root = sampleTree();
    int h = height(root);
    cout << "Level order using height loop: ";
    for (int level = 1; level <= h; level++) printGivenLevel(root, level);
    cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Level order using height loop: 1 2 3 4 5 6 7
*/

