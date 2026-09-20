
/*
 TASK 6 SOLUTION — BST insert + in-order (sorted output)
*/
#include <iostream>
using namespace std;
struct Node { int data; Node* left; Node* right; };

void insert(Node*& r, int v) {
    if (r == nullptr) {                 // sahi jagah mil gayi
        r = new Node{v, nullptr, nullptr};
        return;
    }
    if (v < r->data) insert(r->left, v);   // chhota → left subtree
    else              insert(r->right, v); // bada/equal → right subtree
}

void inorder(Node* r) {
    if (r == nullptr) return;           // base case: khaali subtree
    inorder(r->left);                   // pehle left
    cout << r->data << " ";             // phir root
    inorder(r->right);                  // phir right
}

int main() {
    Node* root = nullptr;
    int arr[6] = {50, 30, 70, 20, 40, 60};
    for (int i = 0; i < 6; i++) insert(root, arr[i]);   // 6 inserts
    inorder(root);                     // BST ka in-order = sorted output
    cout << "\n";
    return 0;
}
// Expected output: 20 30 40 50 60 70
// Explanation: insert worst case me tree ki height tak jaata hai — yahan
// balanced shape me height ~2-3, isliye 6 inserts ≈ 6*3 = 18 steps.
// Height h wale BST ke liye insert = O(h) steps → skewed tree me O(n).
// Inorder traversal har node exactly ek baar → n steps → O(n). Space:
// n nodes bane → O(n).