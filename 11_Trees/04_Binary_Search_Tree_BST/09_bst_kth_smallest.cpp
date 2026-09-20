/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 09_bst_kth_smallest.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted dictionary tree me 3rd smallest word chahiye. BST inorder sorted list deta hai, so kth smallest inorder traversal se milta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. BST inorder traversal sorted values deta hai.
│ 2. Inorder left-root-right traverse karo.
│ 3. Har visited node par count++.
│ 4. Jab count == k, answer current node.
│ 5. Traversal early stop kar sakte hain.
│ 6. This is inorder golden property ka direct use.
│
│ ASCII VISUAL / BST STATE:
│ BST inorder:
│ 20 30 40 50 60 70 80
│
│ k=3
│ visit20 count1
│ visit30 count2
│ visit40 count3 -> answer 40
│
│ DRY RUN:
│ inorder visits leftmost first.
│ First=20, second=30, third=40.
│ Return 40.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - In worst case kth is n or absent, all n nodes visited.
│ -> Time Complexity = O(n) worst.
│ - If k small and tree balanced, early stop may visit fewer nodes but worst remains n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack height h.
│ -> Space Complexity = O(h).
│ APPROACH COMPARISON TABLE:
│ Build sorted array by inorder = library sorted list, O(n) time/O(n) space.
│ Count during inorder with early stop = read sorted tree until kth, O(n) worst/O(h) space.
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
void kthInorder(Node* root, int k, int& count, int& answer) {
    if (root == nullptr || answer != -1) return;
    kthInorder(root->left, k, count, answer);
    if (answer != -1) return;
    count++;
    if (count == k) {
        answer = root->data;
        return;
    }
    kthInorder(root->right, k, count, answer);
}

int main(){
    Node* root=buildBST();
    int count = 0, answer = -1, k = 3;
    kthInorder(root, k, count, answer);
    cout << k << "rd smallest = " << answer << "\n";
    deleteTree(root);
    return 0;
}

/*
OUTPUT:
3rd smallest = 40
*/

