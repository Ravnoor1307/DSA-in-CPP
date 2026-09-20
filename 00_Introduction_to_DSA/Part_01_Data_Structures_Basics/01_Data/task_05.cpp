
/*
 TASK 5 SOLUTION — filter invalid sensor data
*/
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    double sum = 0; int valid = 0;
    for (int i = 0; i < n; i++) {
        double t; cin >> t;
        if (t < 0) {
            continue;   // negative = sensor error, skip (data cleaning step)
        }
        sum += t;       // valid temperature ko add karo
        valid++;        // valid count badhao
    }
    if (valid == 0) {
        cout << "NO VALID DATA\n";      // saara data garbage tha
    } else {
        cout << "average = " << sum / valid << "\n";
    }
    return 0;
}
// Explanation: continue statement garbage data ko aage jaane se rokta hai.
// Valid data hi average me jaata hai — isi ko data-cleaning bolte hain.
