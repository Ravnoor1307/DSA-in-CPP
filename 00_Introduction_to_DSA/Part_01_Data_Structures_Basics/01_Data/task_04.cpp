
/*
 TASK 4 SOLUTION — pass/fail report
*/
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int pass = 0, fail = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int mark; cin >> mark;
        if (mark >= 33) pass++;      // passing boundary 33
        else fail++;                 // 33 se kam → fail
        sum += mark;                 // total marks ka addition (raw aggregation)
    }
    double avg = (n == 0) ? 0.0 : (double)sum / n;   // divide-by-zero guard
    cout << "pass = " << pass << ", fail = " << fail
         << ", average = " << avg << "\n";
    return 0;
}
// Explanation: ek hi pass me pass/fail + sum nikala. Sum ko double me
// cast karke average banaya — integer division ka trap dhyan me rakho.
