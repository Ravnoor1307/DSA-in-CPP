
/*
 TASK 3 SOLUTION — 3-node binary tree print
*/
#include <iostream>
using namespace std;
struct TNode { int data; TNode* left; TNode* right; };
int main() {
    TNode left{3, nullptr, nullptr};
    TNode right{12, nullptr, nullptr};
    TNode root{7, nullptr, nullptr};
    root.left = &left;      // non-linear branching bana di
    root.right = &right;    // ek parent ke 2 children
    cout << "root=" << root.data
         << " left=" << root.left->data
         << " right=" << root.right->data << "\n";
    return 0;
}
// Explanation: fixed 3 nodes, har access constant → O(1) time, O(1)
// space (constant size). Ye non-linear relationship (1 parent -> many children) hai.
