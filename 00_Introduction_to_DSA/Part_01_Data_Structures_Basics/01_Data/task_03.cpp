
/*
 TASK 3 SOLUTION — max and min from raw values
*/
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int maxV = arr[0], minV = arr[0];   // abhi tak ka best guess = pehla element
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxV) maxV = arr[i];   // bada mila → max update
        if (arr[i] < minV) minV = arr[i];   // chhota mila → min update
    }
    cout << "max = " << maxV << ", min = " << minV << "\n";
    return 0;
}
// Explanation: single loop, har element se bas 2 comparisons — max aur min
// dono ek hi pass me nikal gaye. Complexity O(n).
