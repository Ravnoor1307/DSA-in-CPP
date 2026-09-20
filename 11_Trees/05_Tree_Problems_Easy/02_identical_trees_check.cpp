/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_identical_trees_check.cpp
│
│ REAL-WORLD SCENARIO:
│ Do file explorers same hain ya nahi check karna hai: folder name same, left subfolder same, right subfolder same. Identical trees check dono trees ko saath traverse karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Agar dono nodes null, true.
│ 2. Agar ek null aur ek non-null, false.
│ 3. Data different ho, false.
│ 4. Left subtrees identical and right subtrees identical hone chahiye.
│ 5. Dono trees ka structure and values same honi chahiye.
│
│ ASCII VISUAL / TREE STATE:
│ Tree A and B:
│      1          1
│     / \        / \
│    2   3      2   3
│
│ Compare:
│ 1==1, left 2==2, right 3==3 -> identical
│
│ If B right data 4 hota, then not identical.
│
│ DRY RUN:
│ compare root 1 and1 -> same.
│ compare left 2 and2 -> same.
│ compare null children -> true.
│ compare right 3 and3 -> same.
│ final true.
│
│ FLOW OF EXECUTION:
│ root -> solve children/subtrees -> combine/swap/check/sum -> output
│
│ COMPLEXITY CALCULATION:
│ - In worst case trees identical, every pair of nodes compared once.
│ - n nodes => n comparisons.
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
Node* smallTree(){ Node* r=new Node(1); r->left=new Node(2); r->right=new Node(3); return r; }
void deleteTree(Node* r){ if(!r)return; deleteTree(r->left); deleteTree(r->right); delete r; }
bool identical(Node* a, Node* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right);
}
int main(){
    Node* a=smallTree();
    Node* b=smallTree();
    cout << "Trees identical? " << (identical(a,b) ? "YES" : "NO") << "\n";
    b->right->data = 4;
    cout << "After changing one node identical? " << (identical(a,b) ? "YES" : "NO") << "\n";
    deleteTree(a); deleteTree(b);
    return 0;
}

/*
OUTPUT:
Trees identical? YES
After changing one node identical? NO
*/

