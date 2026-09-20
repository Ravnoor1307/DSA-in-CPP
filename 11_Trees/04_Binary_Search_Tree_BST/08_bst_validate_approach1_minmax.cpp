/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 08_bst_validate_approach1_minmax.cpp
│
│ REAL-WORLD SCENARIO:
│ Customs gate me har room ke liye allowed value range hoti hai. BST validate karne ke liye har node ko min/max allowed range pass karte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Root can be in (-inf,+inf).
│ 2. Left child range becomes (min, root->data).
│ 3. Right child range becomes (root->data, max).
│ 4. Agar node value range ke bahar hai, invalid.
│ 5. Range passing full subtree property correctly check karta hai.
│ 6. Sirf direct child comparison enough nahi hota.
│
│ ASCII VISUAL / BST STATE:
│ Valid:
│      50
│     /  \
│   30    70
│
│ Ranges:
│ 50 in (-inf,inf)
│ 30 in (-inf,50)
│ 70 in (50,inf)
│
│ Invalid hidden issue:
│      50
│     /  \
│   30    70
│     \
│      55   ← greater than 50 but in left subtree, invalid by range
│
│ DRY RUN:
│ validate(50,-inf,inf) pass.
│ validate(30,-inf,50) pass.
│ validate(55,30,50) fails because 55 >= 50.
│
│ FLOW OF EXECUTION:
│ root -> compare with key -> go left/right -> update/search/return
│
│ COMPLEXITY CALCULATION:
│ - Every node checked once.
│ - Range update constant per node.
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
bool validate(Node* root, long long low, long long high) {
    if (root == nullptr) return true;
    if (root->data <= low || root->data >= high) return false;
    return validate(root->left, low, root->data) && validate(root->right, root->data, high);
}
void deleteTree(Node* r){ if(!r)return; deleteTree(r->left); deleteTree(r->right); delete r; }
int main(){
    Node* valid = new Node(50);
    valid->left = new Node(30); valid->right = new Node(70);
    Node* invalid = new Node(50);
    invalid->left = new Node(30); invalid->right = new Node(70); invalid->left->right = new Node(55);
    cout << "Valid tree? " << (validate(valid, LLONG_MIN, LLONG_MAX) ? "YES" : "NO") << "\n";
    cout << "Invalid tree? " << (validate(invalid, LLONG_MIN, LLONG_MAX) ? "YES" : "NO") << "\n";
    deleteTree(valid); deleteTree(invalid);
    return 0;
}

/*
OUTPUT:
Valid tree? YES
Invalid tree? NO
*/

