/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_diameter_approach2_optimized.cpp
│
│ REAL-WORLD SCENARIO:
│ Road inspector ek hi visit me branch height bhi measure kare aur longest road bhi note kare. Optimized diameter height aur diameter same recursion me return karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har node ke liye left subtree ka height+diameter lo.
│ 2. Right subtree ka height+diameter lo.
│ 3. Current height = max(leftHeight,rightHeight)+1.
│ 4. Through-root diameter = leftHeight+rightHeight+1.
│ 5. Current diameter = max(throughRoot,leftDiameter,rightDiameter).
│ 6. Har node once process hota hai, repeated height calls nahi.
│
│ ASCII VISUAL / PROPERTY STATE:
│ Cases at each node:
│
│ Case A: diameter through root
│ left deepest -> root -> right deepest
│
│ Case B: diameter not through root
│ completely left subtree or right subtree
│
│ Tree path: 4 -> 2 -> 1 -> 3 -> 7 = 5 nodes
│ Optimized returns pair(height,diameter).
│
│ DRY RUN:
│ Leaf4 returns height1 diameter1.
│ Node2 combines leaf4 and leaf5 -> height2 diameter3.
│ Node3 combines right7 -> height2 diameter2.
│ Root1 through=2+2+1=5, max=5.
│
│ FLOW OF EXECUTION:
│ root -> solve left subtree -> solve right subtree -> combine answer at root
│
│ COMPLEXITY CALCULATION:
│ - Each node processed once.
│ - At each node constant work after left/right results.
│ - Total work = n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h.
│ -> Space Complexity = O(h), worst O(n).
│ APPROACH COMPARISON TABLE:
│ Naive = har node par height dobara measure, O(n²) worst/O(h) stack.
│ Optimized = ek visit me height+diameter report, O(n) time/O(h) stack.
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
struct Info {
    int height;
    int diameter;
};

Info diameterOptimized(Node* root) {
    if (root == nullptr) return {0, 0};
    Info left = diameterOptimized(root->left);
    Info right = diameterOptimized(root->right);
    int heightNow = max(left.height, right.height) + 1;
    int throughRoot = left.height + right.height + 1;
    int diameterNow = max(throughRoot, max(left.diameter, right.diameter));
    return {heightNow, diameterNow};
}

int main() {
    Node* root = sampleTree();
    Info ans = diameterOptimized(root);
    cout << "Height = " << ans.height << "\n";
    cout << "Diameter optimized (nodes) = " << ans.diameter << "\n";
    cout << "Comparison: naive O(n^2), optimized O(n).\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Height = 3
Diameter optimized (nodes) = 5
Comparison: naive O(n^2), optimized O(n).
*/

