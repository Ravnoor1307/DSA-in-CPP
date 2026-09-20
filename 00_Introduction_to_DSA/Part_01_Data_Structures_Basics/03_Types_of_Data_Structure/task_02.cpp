
/*
 TASK 2 SOLUTION — 3-node linked list traversal
*/
#include <iostream>
using namespace std;
struct Node { int data; Node* next; };
int main() {
    Node a{5, nullptr}, b{10, nullptr}, c{15, nullptr};
    a.next = &b;   // a ke baad b
    b.next = &c;   // b ke baad c (c.next already null hai)
    Node* p = &a;
    while (p != nullptr) {          // jab tak pointer valid hai
        cout << p->data;
        if (p->next) cout << " -> ";
        p = p->next;                // agle node par chalo
    }
    cout << "\n";
    return 0;
}
// Explanation: linked list linear hai par memory scattered — "linear"
// logical order se hai, pointer chain se. n nodes → n steps → O(n). Space O(n).
