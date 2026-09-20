/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_serialize_deserialize_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Tree ko file/network me bhejna ho to structure ko string me convert karna padta hai. Serialize preorder with # null markers, deserialize same order se tree rebuild karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Serialize: preorder ROOT LEFT RIGHT.
│ 2. Null child ke liye # marker store karo.
│ 3. Tokens space-separated string me add karo.
│ 4. Deserialize: next token read karo.
│ 5. # means null return.
│ 6. Number token means node create, then left/right recursively build.
│ 7. # markers structure preserve karte hain.
│
│ ASCII VISUAL / MEDIUM TREE STATE:
│ Tree:
│      1
│     / \
│    2   3
│
│ Preorder with nulls:
│ 1 2 # # 3 # #
│
│ Without #, string 1 2 3 ambiguous ho sakta hai.
│ With # markers, exact structure rebuild possible.
│
│ DRY RUN:
│ deserialize tokens:
│ read1 create root.
│ read2 create left.
│ read# left of2 null.
│ read# right of2 null.
│ read3 create right.
│ read# read# null children.
│
│ FLOW OF EXECUTION:
│ input tree -> traversal/hash/queue/recursion pattern -> combine/update -> answer
│
│ COMPLEXITY CALCULATION:
│ - Serialize visits each real node once and each null child once.
│ - Binary tree has n nodes and n+1 null links.
│ - Total tokens = 2n+1.
│ -> Time Complexity = O(n).
│ - Deserialize reads same 2n+1 tokens -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Serialized string stores O(n) tokens.
│ - Recursion stack height h.
│ -> Space Complexity = O(n) for string, O(h) stack.
│ APPROACH COMPARISON TABLE:
│ Preorder + # = parcel labels for every missing child, O(n) time/O(n) string.
│ Level-order serialization = queue based, also O(n), often used in platforms.
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
void serialize(Node* root, ostringstream& out) {
    if (!root) {
        out << "# ";
        return;
    }
    out << root->data << " ";
    serialize(root->left, out);
    serialize(root->right, out);
}

Node* deserialize(istringstream& in) {
    string token;
    if (!(in >> token)) return nullptr;
    if (token == "#") return nullptr;
    Node* root = new Node(stoi(token));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root=sampleTree();
    ostringstream out;
    serialize(root,out);
    string data=out.str();
    cout << "Serialized: " << data << "\n";
    istringstream in(data);
    Node* copy=deserialize(in);
    cout << "Preorder after deserialize: "; preorder(copy); cout << "\n";
    deleteTree(root);
    deleteTree(copy);
    return 0;
}

/*
OUTPUT:
Serialized: 1 2 4 # # 5 # # 3 6 # # 7 # #
Preorder after deserialize: 1 2 4 5 3 6 7
*/

