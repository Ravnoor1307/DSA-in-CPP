/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_zigzag_level_order.cpp
│
│ REAL-WORLD SCENARIO:
│ Museum tour me first floor left-to-right, next floor right-to-left, phir left-to-right. Tree zigzag level order queue + direction flag se hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Queue level order use karo.
│ 2. Har level ka size nikaalo.
│ 3. level vector fixed size ka banao.
│ 4. direction leftToRight true ho to index=i.
│ 5. false ho to index=levelSize-1-i.
│ 6. Har level ke baad direction toggle karo.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Levels:
│ L->R: 1
│ R->L: 3 2
│ L->R: 4 5 6 7
│
│ Zigzag output: 1 | 3 2 | 4 5 6 7
│
│ DRY RUN:
│ level1 direction true -> [1].
│ toggle false.
│ level2 nodes 2,3 placed reverse -> [3,2].
│ toggle true.
│ level3 placed normal -> [4,5,6,7].
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - Each node popped once and pushed once.
│ - Placing in level vector constant per node.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Queue O(width), output O(n).
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
vector<vector<int>> zigzag(Node* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level(levelSize);
        for (int i = 0; i < levelSize; i++) {
            Node* cur = q.front(); q.pop();
            int index = leftToRight ? i : levelSize - 1 - i;
            level[index] = cur->data;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    return ans;
}
int main(){
    Node* root=sampleTree();
    vector<vector<int>> ans=zigzag(root);
    cout << "Zigzag levels:\n";
    for(const auto& level:ans){ for(int x:level) cout << x << " "; cout << "\n"; }
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Zigzag levels:
1
3 2
4 5 6 7
*/

