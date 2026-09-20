/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_level_order_approach2_queue.cpp
│
│ REAL-WORLD SCENARIO:
│ Metro station par passengers level-by-level queue me process hote hain. Tree level order traversal queue ka real use hai: parent nikalo, children queue me daalo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Queue me root push karo.
│ 2. Jab tak queue empty nahi, front node pop karo and print.
│ 3. Uske left child ko push karo if present.
│ 4. Uske right child ko push karo if present.
│ 5. Queue FIFO ensures level-by-level order.
│ 6. This connects Queue journey with Trees.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Queue states:
│ start [1]
│ pop1, push2,3 -> [2,3]
│ pop2, push4,5 -> [3,4,5]
│ pop3, push6,7 -> [4,5,6,7]
│ pop4 -> [5,6,7]
│ pop5 -> [6,7]
│ pop6 -> [7]
│ pop7 -> []
│ Output: 1 2 3 4 5 6 7
│
│ DRY RUN:
│ q=[1]
│ visit 1, q becomes [2,3]
│ visit 2, q becomes [3,4,5]
│ visit 3, q becomes [4,5,6,7]
│ visit 4,5,6,7 then empty.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Each node pushed into queue once.
│ - Each node popped from queue once.
│ - Total operations = n pushes + n pops = 2n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Queue stores at most tree width nodes.
│ - Worst width can be about n/2 in complete tree.
│ -> Space Complexity = O(n) worst.
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

void printQueue(queue<Node*> q) {
    cout << "[";
    bool first = true;
    while (!q.empty()) {
        if (!first) cout << ",";
        cout << q.front()->data;
        first = false;
        q.pop();
    }
    cout << "]";
}

void levelOrderQueue(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        cout << "queue before pop = ";
        printQueue(q);
        Node* current = q.front();
        q.pop();
        cout << ", visit " << current->data << "\n";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    Node* root = sampleTree();
    levelOrderQueue(root);
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
queue before pop = [1], visit 1
queue before pop = [2,3], visit 2
queue before pop = [3,4,5], visit 3
queue before pop = [4,5,6,7], visit 4
queue before pop = [5,6,7], visit 5
queue before pop = [6,7], visit 6
queue before pop = [7], visit 7
*/

