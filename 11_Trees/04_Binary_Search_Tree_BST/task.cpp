/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_Binary_Search_Tree_BST task.cpp
│
│ REAL-WORLD SCENARIO:
│ BST practice lab me sorted dictionary tree banana, search, min/max, delete, validate, and kth smallest solve karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. BST property comments me draw karo.
│ 2. Insert 50,30,70,20,40,60,80.
│ 3. Recursive search implement karo.
│ 4. Iterative search implement karo.
│ 5. Min and max find karo.
│ 6. Inorder sorted output verify karo.
│ 7. Delete node ke 3 cases implement karo.
│ 8. Validate BST using min/max range.
│ 9. kth smallest using inorder count.
│
│ HINTS:
│ - left < root < right.
│ - min = leftmost, max = rightmost.
│ - delete two-child: inorder successor.
│ - kth smallest: inorder traversal.
│
│ STARTER CODE:
│ Node* insert(Node* root,int key){ if(!root)return new Node(key); ... }
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / BST STATE:
│ BST:
│              50
│            /    \
│          30      70
│         /  \    /  \
│       20   40  60   80
│ Inorder: 20 30 40 50 60 70 80
│
│ DRY RUN:
│ Search 40: 50->30->40.
│ Min path: 50->30->20.
│ Max path: 50->70->80.
│ kth=3 => 40.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Insert/search/min/max follow height h -> O(h).
│ - Inorder/validate visit n nodes -> O(n).
│ - Balanced h=log n, skewed h=n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive stack O(h).
│ - Iterative search/min/max O(1) extra.
│ - Tree storage O(n).
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

Node* insertBST(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else if (key > root->data) root->right = insertBST(root->right, key);
    return root;
}

Node* buildBST() {
    Node* root = nullptr;
    for (int x : {50,30,70,20,40,60,80}) root = insertBST(root, x);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
bool searchIter(Node* root,int key){
    while(root){ if(root->data==key)return true; root = key<root->data ? root->left : root->right; }
    return false;
}
int minVal(Node* root){ while(root->left) root=root->left; return root->data; }
int maxVal(Node* root){ while(root->right) root=root->right; return root->data; }
int main(){
    Node* root=buildBST();
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Search 40 = " << (searchIter(root,40)?"FOUND":"NOT FOUND") << "\n";
    cout << "Min=" << minVal(root) << ", Max=" << maxVal(root) << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
Inorder: 20 30 40 50 60 70 80
Search 40 = FOUND
Min=20, Max=80
*/

