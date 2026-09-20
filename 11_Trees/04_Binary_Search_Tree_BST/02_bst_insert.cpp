/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_bst_insert.cpp
│
│ REAL-WORLD SCENARIO:
│ Dictionary me new word insert karte time compare karke left/right page section me jaate ho. BST insert bhi comparison path follow karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Root null ho to new node banao.
│ 2. key < root->data, left subtree me insert.
│ 3. key > root->data, right subtree me insert.
│ 4. Equal values usually ignore ya count handle karte hain; yahan ignore.
│ 5. Insert path height h tak jaata hai.
│
│ ASCII VISUAL / BST STATE:
│ Insert order: 50,30,70,20,40
│
│ 50 -> root
│ 30 < 50 -> left
│ 70 > 50 -> right
│ 20 < 50, 20 < 30 -> left of 30
│ 40 < 50, 40 > 30 -> right of 30
│
│ Result:
│          50
│        /    \
│      30      70
│     /  \
│   20    40
│
│ DRY RUN:
│ insert50: root null -> 50.
│ insert30: compare 30<50 -> left null -> place.
│ insert70: 70>50 -> right null.
│ insert20: 20<50, 20<30 -> left of 30.
│ insert40: 40<50, 40>30 -> right of 30.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Insert compares once per level.
│ - Number of levels on path = h.
│ -> Time Complexity = O(h).
│ - Balanced h=log n; skewed h=n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive insert stack depth h.
│ - One new node allocated O(1).
│ -> Extra Space Complexity = O(h) recursion, O(1) new node besides tree storage.
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
Node* insertWithTrace(Node* root, int key) {
    if (root == nullptr) {
        cout << "place " << key << " here\n";
        return new Node(key);
    }
    if (key < root->data) {
        cout << key << " < " << root->data << " -> go left\n";
        root->left = insertWithTrace(root->left, key);
    } else if (key > root->data) {
        cout << key << " > " << root->data << " -> go right\n";
        root->right = insertWithTrace(root->right, key);
    }
    return root;
}
void inorder(Node* r){ if(!r)return; inorder(r->left); cout<<r->data<<" "; inorder(r->right); }
void deleteTree(Node* r){ if(!r)return; deleteTree(r->left); deleteTree(r->right); delete r; }
int main(){
    Node* root=nullptr;
    for(int x:{50,30,70,20,40}) root=insertWithTrace(root,x);
    cout << "Inorder after inserts: "; inorder(root); cout << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
place 50 here
30 < 50 -> go left
place 30 here
70 > 50 -> go right
place 70 here
20 < 50 -> go left
20 < 30 -> go left
place 20 here
40 < 50 -> go left
40 > 30 -> go right
place 40 here
Inorder after inserts: 20 30 40 50 70
*/

