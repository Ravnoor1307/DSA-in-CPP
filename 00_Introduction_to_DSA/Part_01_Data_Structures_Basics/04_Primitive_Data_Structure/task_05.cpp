
/*
 TASK 5 SOLUTION — leap year with bool
*/
#include <iostream>
using namespace std;
int main() {
    int y; cin >> y;
    bool leap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    if (leap) cout << y << " is a LEAP year\n";
    else      cout << y << " is NOT a leap year\n";
    return 0;
}
// 2000 → leap (400 se divide), 1900 → not leap (100 rule), 2024 → leap.
// Explanation: bool ek single flag rakhta hai — ek expression me pura
// condition combine kiya. Constant ops → O(1).
