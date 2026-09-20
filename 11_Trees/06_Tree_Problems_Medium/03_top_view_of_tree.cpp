/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_top_view_of_tree.cpp
│
│ REAL-WORLD SCENARIO:
│ Drone se tree ko top se dekhoge to har vertical line ka first visible node dikhega. Top view level-order + horizontal distance map se nikalta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Root horizontal distance hd=0.
│ 2. Left child hd-1, right child hd+1.
│ 3. Level order BFS top-to-bottom process karta hai.
│ 4. Har hd ke liye first node store karo only if absent.
│ 5. map sorted hd order me output deta hai.
│ 6. Hash/map + queue combo pattern.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ Tree:
│          1(hd0)
│        /       \
│    2(-1)       3(+1)
│    /   \       /   \
│ 4(-2) 5(0)  6(0)  7(+2)
│
│ Top visible per hd:
│ -2:4, -1:2, 0:1, +1:3, +2:7
│ Top view: 4 2 1 3 7
│
│ DRY RUN:
│ queue starts (1,0), store hd0=1.
│ pop1 push (2,-1),(3,1).
│ pop2 store -1=2, push4 -2,5 0.
│ pop3 store 1=3, push6 0,7 2.
│ hd0 already has 1, so 5/6 skipped for top view.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - BFS pushes and pops each node once -> 2n queue operations.
│ - map insertion/search costs O(log d), d horizontal distances.
│ -> Time Complexity = O(n log d). With unordered_map + sorting keys can be O(n + d log d).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Queue can store O(n) nodes worst.
│ - Map stores d horizontal distances, d<=n.
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
vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    map<int,int> firstAtHD;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty()) {
        pair<Node*,int> front = q.front(); q.pop();
        Node* node = front.first;
        int hd = front.second;
        if (!firstAtHD.count(hd)) firstAtHD[hd] = node->data;
        if (node->left) q.push({node->left, hd-1});
        if (node->right) q.push({node->right, hd+1});
    }
    for (auto p : firstAtHD) ans.push_back(p.second);
    return ans;
}
int main(){
    Node* root=sampleTree();
    vector<int> ans=topView(root);
    cout << "Top view: "; for(int x:ans) cout << x << " "; cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Top view: 4 2 1 3 7
*/

