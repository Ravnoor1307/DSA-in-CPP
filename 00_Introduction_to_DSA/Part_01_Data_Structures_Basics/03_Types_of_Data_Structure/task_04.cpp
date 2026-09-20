
/*
 TASK 4 SOLUTION — stack (LIFO) with array
*/
#include <iostream>
using namespace std;
int main() {
    int stk[100], top = -1;               // empty stack ka top = -1
    int a, b, c; cin >> a >> b >> c;
    stk[++top] = a;                       // push: pehle top badhao, phir value
    stk[++top] = b;
    stk[++top] = c;
    cout << "top = " << stk[top] << "\n"; // top me last inserted element
    top--;                                // pop: top kam karo
    cout << "after 1 pop, top = " << stk[top] << "\n";
    return 0;
}
// Explanation: LIFO rule — jo sabse aakhri me aaya wo pehle niklega.
// Har push/pop O(1) (sirf index math). 3 pushes + 1 pop = constant steps → O(1).
