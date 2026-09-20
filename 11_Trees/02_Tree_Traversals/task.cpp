/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_Tree_Traversals task.cpp
│
│ REAL-WORLD SCENARIO:
│ Traversal practice lab me ek tree ko multiple route se visit karna hai and recursion/queue/stack states draw karni hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Sample tree create karo: 1 root, 2/3, 4/5/6/7.
│ 2. Inorder traversal implement karo.
│ 3. Preorder traversal implement karo.
│ 4. Postorder traversal implement karo.
│ 5. One tree ke teeno outputs side-by-side print karo.
│ 6. Level order using height-loop implement karo.
│ 7. Level order using queue implement karo and queue states draw karo.
│ 8. Iterative inorder using stack implement karo.
│
│ HINTS:
│ - Inorder: L Root R.
│ - Preorder: Root L R.
│ - Postorder: L R Root.
│ - Level order queue: push root, pop front, push children.
│
│ STARTER CODE:
│ void inorder(Node* root){ if(!root)return; inorder(root->left); cout<<root->data; inorder(root->right); }
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Inorder: 4 2 5 1 6 3 7
│ Preorder: 1 2 4 5 3 6 7
│ Postorder: 4 5 2 6 7 3 1
│
│ DRY RUN:
│ Queue level:
│ [1] -> visit1, push2,3
│ [2,3] -> visit2, push4,5
│ [3,4,5] -> visit3, push6,7
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - DFS each node once -> O(n).
│ - Queue level order n pushes + n pops = 2n -> O(n).
│ - Height-loop skewed work 1+2+...+n = n(n+1)/2 -> O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - DFS stack O(h), worst O(n).
│ - BFS queue O(width), worst O(n).
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

void inorder(Node* r){ if(!r)return; inorder(r->left); cout<<r->data<<" "; inorder(r->right); }
void preorder(Node* r){ if(!r)return; cout<<r->data<<" "; preorder(r->left); preorder(r->right); }
void postorder(Node* r){ if(!r)return; postorder(r->left); postorder(r->right); cout<<r->data<<" "; }
void levelOrder(Node* root){
    if(!root)return;
    queue<Node*> q; q.push(root);
    while(!q.empty()){
        Node* cur=q.front(); q.pop(); cout<<cur->data<<" ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}
int main(){
    Node* root=sampleTree();
    cout<<"Inorder: "; inorder(root); cout<<"\n";
    cout<<"Preorder: "; preorder(root); cout<<"\n";
    cout<<"Postorder: "; postorder(root); cout<<"\n";
    cout<<"Level order: "; levelOrder(root); cout<<"\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Inorder: 4 2 5 1 6 3 7
Preorder: 1 2 4 5 3 6 7
Postorder: 4 5 2 6 7 3 1
Level order: 1 2 3 4 5 6 7
*/

