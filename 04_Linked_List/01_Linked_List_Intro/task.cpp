/*
 * ══════════════════════════════════════════════════
 *  TASKS — 01_Linked_List_Intro
 *  5 tasks, EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <vector>
using namespace std;

// shared Node struct for all tasks below
struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// ---- helper: print list (used by several tasks) ----
void print(Node* h) {
    while (h) { cout << h->data << (h->next ? " -> " : ""); h = h->next; }
    cout << endl;
}

/* TASK 1 — create & link (EASY)
   Build a 4-node list 5->7->9->11 using `new`, return head.
   Expected print: 5 -> 7 -> 9 -> 11 */
Node* task1_build() {
    Node* a = new Node(5);
    Node* b = new Node(7);
    Node* c = new Node(9);
    Node* d = new Node(11);
    a->next = b; b->next = c; c->next = d;
    return a;
}

/* TASK 2 — count nodes (EASY)
   Given head, return the number of nodes (walk till nullptr).
   Expected: 4 */
int task2_count(Node* head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
}

/* TASK 3 — find max (EASY-MEDIUM)
   Return the LARGEST data value in the list.
   Expected: 11 */
int task3_max(Node* head) {
    int mx = head ? head->data : 0;
    while (head) { if (head->data > mx) mx = head->data; head = head->next; }
    return mx;
}

/* TASK 4 — compare with array (MEDIUM)
   The SAME data "3,6,9" lives in an array AND in a list.
   Return true if arr[i] equals node i for every i (both orders match).
   Input list: 3->6->9 ; arr = {3,6,9}. Expected: true */
bool task4_matches(Node* head, const vector<int>& arr) {
    int i = 0;
    while (head) {
        if (i >= (int)arr.size()) return false;   // list longer than array
        if (head->data != arr[i]) return false;    // mismatch at position i
        head = head->next;
        i++;
    }
    return i == (int)arr.size();                   // array longer than list?
}

/* TASK 5 — clean-up practice (HARD)
   Delete the WHOLE list safely and return the new (now null) head.
   No leaks allowed: save next before delete.
   Expected return: nullptr */
Node* task5_destroy(Node* head) {
    while (head) {
        Node* nxt = head->next;    // count: sabse pehle next save karo
        delete head;
        head = nxt;
    }
    return nullptr;
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    Node* h1 = task1_build();
    print(h1);                       // -> 5 -> 7 -> 9 -> 11

    cout << "---- TASK 2 ----" << endl;
    cout << "count = " << task2_count(h1) << endl;   // 4

    cout << "---- TASK 3 ----" << endl;
    cout << "max   = " << task3_max(h1) << endl;     // 11

    cout << "---- TASK 4 ----" << endl;
    Node* h4 = task1_build();
    vector<int> v = {3, 6, 9};       // NOTE: different data than h4 -> false
    cout << "match(3,6,9 arr vs 5,7,9 list) = " << (task4_matches(h4, v) ? "true" : "false") << endl;
    Node* h4b = new Node(3); h4b->next = new Node(6); h4b->next->next = new Node(9);
    cout << "match(3,6,9 arr vs 3,6,9 list) = " << (task4_matches(h4b, v) ? "true" : "false") << endl;
    h4 = task5_destroy(h4);
    h4b = task5_destroy(h4b);

    cout << "---- TASK 5 ----" << endl;
    Node* h5 = h1;                   // reuse the very first list
    h5 = task5_destroy(h5);
    cout << "head after destroy = " << (h5 == nullptr ? "nullptr (clean)" : "LEAK!") << endl;
    return 0;
}