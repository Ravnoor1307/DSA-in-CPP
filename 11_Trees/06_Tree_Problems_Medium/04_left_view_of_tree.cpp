/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_left_view_of_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Tree ko left side se dekhoge to har level ka first visible node dikhega. Queue BFS me har level ka first node print kar do.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Level order traversal use karo.
│ 2. Har level ka size q.size() se lo.
│ 3. i==0 node current level ka first node hai.
│ 4. Usko left view me add karo.
│ 5. Children ko normal left then right push karo.
│ 6. Output har level se one node.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Left side visible:
│ level1 -> 1
│ level2 -> 2
│ level3 -> 4
│ Left view: 1 2 4
│
│ DRY RUN:
│ queue level1 [1], first=1.
│ queue level2 [2,3], first=2.
│ queue level3 [4,5,6,7], first=4.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - Each node pushed once and popped once.
│ - Total operations = 2n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Queue stores width nodes, worst O(n).
│ - Answer stores height h nodes.
│ -> Space Complexity = O(n).
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
vector<int> leftView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* cur = q.front(); q.pop();
            if (i == 0) ans.push_back(cur->data); // first node of level
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return ans;
}
int main(){
    Node* root=sampleTree();
    vector<int> ans=leftView(root);
    cout << "Left view: "; for(int x:ans) cout << x << " "; cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Left view: 1 2 4
*/

