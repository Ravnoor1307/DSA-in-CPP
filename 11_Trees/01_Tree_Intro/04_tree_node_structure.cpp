/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_tree_node_structure.cpp
│
│ REAL-WORLD SCENARIO:
│ Linked list node ke paas ek next pointer hota hai. Binary tree node linked list ka extension hai: ek left pointer aur ek right pointer.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Node data store karta hai.
│ 2. `left` pointer left child ko point karta hai.
│ 3. `right` pointer right child ko point karta hai.
│ 4. Leaf node ke left/right NULL/nullptr hote hain.
│ 5. Tree root ek Node* hota hai.
│
│ ASCII VISUAL / TREE STATE:
│ Node box:
│ +-----------------------------+
│ | left ptr | data | right ptr |
│ +-----------------------------+
│      |       10        |
│      v                 v
│   left child        right child
│
│ struct Node {
│     int data;
│     Node* left;
│     Node* right;
│ };
│
│ DRY RUN:
│ Node root(10): data=10, left=nullptr, right=nullptr.
│ Add left child 5: root->left points to Node(5).
│ Add right child 20: root->right points to Node(20).
│
│ FLOW OF EXECUTION:
│ main -> create/describe tree -> pointer/term logic -> output
│
│ COMPLEXITY CALCULATION:
│ - Creating one node does fixed assignments: data, left, right.
│ -> Time Complexity = O(1) per node.
│
│ SPACE COMPLEXITY CALCULATION:
│ - One node stores data + two pointers.
│ -> Space Complexity = O(1) per node, O(n) for n nodes.
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

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);   // Hinglish: left child attach
    root->right = new Node(20); // Hinglish: right child attach
    cout << "Root data = " << root->data << "\n";
    cout << "Left child = " << root->left->data << ", Right child = " << root->right->data << "\n";
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}

/*
OUTPUT:
Root data = 10
Left child = 5, Right child = 20
*/

