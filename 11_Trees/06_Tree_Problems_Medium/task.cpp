/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_Tree_Problems_Medium task.cpp
│
│ REAL-WORLD SCENARIO:
│ Medium tree practice lab me LCA, views, zigzag traversal, max path sum, and serialization solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. LCA in BST implement karo.
│ 2. LCA in binary tree implement karo.
│ 3. Top view using BFS + horizontal distance map.
│ 4. Left view using first node of each level.
│ 5. Zigzag level order using queue + direction flag.
│ 6. Max path sum using gain and global best.
│ 7. Serialize/deserialize concept using preorder + # markers.
│ 8. Har problem ka visual path/map/queue state comments me draw karo.
│
│ HINTS:
│ - BST LCA uses ordering.
│ - BT LCA searches both sides.
│ - Top view stores first hd.
│ - Max path sum ignores negative gain using max(0,gain).
│
│ STARTER CODE:
│ if(root==nullptr) return nullptr;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ BST LCA(20,40): 50 -> 30 split, answer30.
│ BT LCA(4,6): left gives4, right gives6 at root1, answer1.
│ Top view sample: 4 2 1 3 7.
│
│ DRY RUN:
│ Zigzag levels:
│ 1
│ 3 2
│ 4 5 6 7
│ Max path sample -10,9,20,15,7 -> 42.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - BST LCA O(h).
│ - Normal BT LCA/views/zigzag/max path visit n nodes -> O(n).
│ - Top view with map costs O(n log d).
│ - Serialization tokens 2n+1 -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Queue/map/output can be O(n).
│ - Recursive stack O(h), worst O(n).
│ - BST iterative LCA O(1) extra.
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
vector<int> leftView(Node* root){
    vector<int> ans; if(!root)return ans; queue<Node*> q; q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            Node* cur=q.front(); q.pop();
            if(i==0) ans.push_back(cur->data);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return ans;
}
int main(){
    Node* root=sampleTree();
    vector<int> ans=leftView(root);
    cout << "Left view: "; for(int x:ans) cout << x << " "; cout << "\n";
    cout << "Study files 01-07 for LCA, top view, zigzag, max path, serialize.\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Left view: 1 2 4
Study files 01-07 for LCA, top view, zigzag, max path, serialize.
*/

