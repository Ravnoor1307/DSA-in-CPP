/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 08_traversals_without_recursion_idea.cpp
│
│ REAL-WORLD SCENARIO:
│ Recursion call stack ko agar manually manage karna ho, to stack container use kar sakte hain. Inorder iterative traversal call stack ka manual version hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. current=root set karo, stack empty.
│ 2. Left chain ke nodes stack me push karte jao.
│ 3. Jab current null, stack top pop karo and visit.
│ 4. Then current = popped->right.
│ 5. Ye recursion ke hidden stack ko explicit stack bana deta hai.
│ 6. Preorder/postorder iterative variants bhi stack se possible hain.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Inorder iterative for tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Stack journey start:
│ push 1, push 2, push 4
│ pop 4 visit
│ pop 2 visit, go right 5
│ pop 5 visit
│ pop 1 visit, go right 3
│ ...
│ Output: 4 2 5 1 6 3 7
│
│ DRY RUN:
│ current=1 push1, current=2 push2, current=4 push4.
│ current=null, pop4 print.
│ pop2 print, current=5.
│ push5, pop5 print, pop1 print.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Each node pushed once and popped once.
│ - Total stack operations = 2n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack stores at most height h nodes.
│ -> Space Complexity = O(h), worst O(n).
│ APPROACH COMPARISON TABLE:
│ Recursive DFS = system call stack handles nodes, O(n) time/O(h) stack.
│ Iterative DFS = programmer stack container, O(n) time/O(h) stack.
│ Level order = queue FIFO, O(n) time/O(width) space.
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

void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* current = root;
    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);      // recursion ka manual push
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main() {
    Node* root = sampleTree();
    cout << "Iterative inorder: ";
    iterativeInorder(root);
    cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Iterative inorder: 4 2 5 1 6 3 7
*/

