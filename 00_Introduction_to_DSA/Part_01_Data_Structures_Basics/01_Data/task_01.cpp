/*
 TASK 1 SOLUTION — prints raw data as-is
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "kitni values daloge? ";
    cin >> n;
    int arr[100];
    cout << "values do: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];           // raw data ko store kar rahe hain
    }
    cout << "stored data: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";   // raw data ko waise ka waise print karo
    }
    cout << "\n";
    return 0;
}
// Explanation: pehla loop sirf data collect karta hai (storage), dusra
// loop use print karta hai. Koi processing nahi — isliye output hi "raw data" hai.
