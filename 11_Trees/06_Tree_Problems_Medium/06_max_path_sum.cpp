/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_max_path_sum.cpp
│
│ REAL-WORLD SCENARIO:
│ Mountain trail tree me maximum happiness path chahiye; path kisi bhi node se start/end ho sakta hai but parent-child connections follow karega. Negative branch ko avoid kar sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. For each node, gain from left = max(0, leftGain).
│ 2. Gain from right = max(0, rightGain).
│ 3. Path through current = node->data + leftGain + rightGain.
│ 4. Global answer update karo.
│ 5. Parent ko one-side gain return hota hai: node->data + max(leftGain,rightGain).
│ 6. Hard classic pattern: split path only at current node, upward path single branch hota hai.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ Tree:
│        -10
│        /  \
│       9    20
│           /  \
│          15   7
│
│ At node20:
│ leftGain=15, rightGain=7
│ through20 = 20+15+7 = 42
│ return to parent = 20 + max(15,7) = 35
│
│ At root -10:
│ through = -10 + 9 + 35 = 34
│ global max remains 42
│
│ DRY RUN:
│ leaf15 returns15, global15.
│ leaf7 returns7, global15.
│ node20 through42, global42, return35.
│ leaf9 returns9.
│ root through34, global stays42.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - Each node processed exactly once.
│ - Each node constant max/add operations.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h.
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

struct Node { int data; Node* left; Node* right; Node(int v):data(v),left(nullptr),right(nullptr){} };
void deleteTree(Node* r){ if(!r)return; deleteTree(r->left); deleteTree(r->right); delete r; }
int maxGain(Node* root, int& best) {
    if (!root) return 0;
    int leftGain = max(0, maxGain(root->left, best));
    int rightGain = max(0, maxGain(root->right, best));
    int through = root->data + leftGain + rightGain;
    best = max(best, through);
    return root->data + max(leftGain, rightGain);
}
int main(){
    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    int best=INT_MIN;
    maxGain(root,best);
    cout << "Max path sum = " << best << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Max path sum = 42
*/

