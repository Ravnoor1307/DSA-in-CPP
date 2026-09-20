/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_middle_revisited_palindrome_combo.cpp
│
│ REAL-WORLD SCENARIO:
│ Palindrome train check karna hai: middle tak fast-slow jao, second half reverse karo, phir dono halves compare karo.
│
│ ASCII VISUAL / PATTERN STATE:
│ Linked list:
│ 1 -> 2 -> 2 -> 1
│
│ Step 1 middle by fast-slow:
│ slow reaches 3rd node value 2.
│
│ Step 2 reverse second half:
│ 2 -> 1 becomes 1 -> 2
│
│ Step 3 compare:
│ first half:  1 -> 2
│ second half: 1 -> 2
│ same -> palindrome.

│
│ STEP-BY-STEP DRY RUN:
│ slow/fast:
│ start at1
│ step1 slow=2, fast=2(third)
│ step2 slow=2(third), fast=null
│ reverse from slow.
│ compare values 1==1, 2==2.

│
│ COMPLEXITY CALCULATION:
│ Find middle scans n/2 nodes -> O(n).
│ Reverse second half scans n/2 nodes -> O(n).
│ Compare scans n/2 nodes -> O(n).
│ Total = O(n).
│ Extra pointers constant -> O(1).

│ APPROACH COMPARISON TABLE:
│ | Fast-slow use | Analogy | Key idea | Time | Space |
│ | Cycle detect | race track | fast catches slow | O(n) | O(1) |
│ | Duplicate number | array as linked list | cycle entry | O(n) | O(1) |
│ | Happy number | digit process cycle | slow/fast sequence | O(m*d) | O(1) |
│ | Palindrome LL | train midpoint | middle + reverse | O(n) | O(1) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct Node { int data; Node* next; Node(int x): data(x), next(nullptr) {} };

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverseList(slow);
    Node* first = head;
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }
    return true;
}

int main() {
    Node* a = new Node(1); Node* b = new Node(2); Node* c = new Node(2); Node* d = new Node(1);
    a->next=b; b->next=c; c->next=d;
    cout << "Palindrome? " << (isPalindrome(a) ? "YES" : "NO") << "\n";
    delete a; delete b; delete c; delete d;
    return 0;
}

/*
OUTPUT:
Palindrome? YES
*/

