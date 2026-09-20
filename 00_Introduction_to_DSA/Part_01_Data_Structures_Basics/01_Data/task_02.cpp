/*
 TASK 2 SOLUTION — even/odd counts (data → summary info)
*/
#include <iostream>
using namespace std;
int main() {
    int n, x, even = 0, odd = 0;
    cout << "kitne numbers? "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) even++;   // 2 se bilkul divide → even
        else odd++;               // nahi to odd
    }
    cout << "even: " << even << ", odd: " << odd << "\n";
    return 0;
}
// Explanation: raw numbers se do derived facts ban gaye — even count aur
// odd count. Ye chhota sa example hi data->information ka process hai.
