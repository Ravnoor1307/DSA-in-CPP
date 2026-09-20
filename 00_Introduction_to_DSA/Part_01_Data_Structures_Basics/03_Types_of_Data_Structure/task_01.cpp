
/*
 TASK 1 SOLUTION — forward and reverse traversal
*/
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "forward:  ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";   // 0 se n-1
    cout << "\nreverse:  ";
    for (int i = n - 1; i >= 0; i--) cout << a[i] << " ";  // n-1 se 0
    cout << "\n";
    return 0;
}
// Explanation: linear structure me direction sirf index badalne se badal
// jati hai — 2 loops, har ek n steps → total 2n → O(n). Space O(n).
