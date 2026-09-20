
/*
 TASK 6 SOLUTION — Celsius to Fahrenheit danger report
*/
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    double c[100];                   // raw celsius readings
    for (int i = 0; i < n; i++) cin >> c[i];
    int dangerous = 0;
    for (int i = 0; i < n; i++) {
        double f = c[i] * 9.0 / 5.0 + 32.0;   // F = C * 9/5 + 32
        cout << c[i] << "C = " << f << "F\n";
        if (f > 104.0) dangerous++;  // 104F upar → heat-stroke risk flagged
    }
    cout << "dangerous readings: " << dangerous << " of " << n << "\n";
    return 0;
}
// Explanation: raw celsius ko meaningful Fahrenheit me convert kiya aur ek
// threshold laga kar actionable alert (danger count) banaya — yehi
// information hai jo raw data me pehle nahi thi.