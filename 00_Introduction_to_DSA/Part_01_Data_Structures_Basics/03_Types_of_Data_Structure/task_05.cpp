
/*
 TASK 5 SOLUTION — queue (FIFO) with array
*/
#include <iostream>
using namespace std;
int main() {
    int q[100], front = 0, rear = -1;     // empty queue
    int a, b, c; cin >> a >> b >> c;
    q[++rear] = a;                        // enqueue: rear badhao, value rakho
    q[++rear] = b;
    q[++rear] = c;
    cout << "front = " << q[front] << "\n";   // sabse purana element
    front++;                                  // dequeue: front ek aage
    front++;                                  // doosri dequeue
    cout << "after 2 dequeues, front = " << q[front] << "\n";
    return 0;
}
// Explanation: FIFO rule — jo pehle aaya wo pehle niklega. Yahan rear se
// data add hota hai (right side) aur front se nikalta hai (left side).
// Constant number of ops → O(1) time, O(1) space.
