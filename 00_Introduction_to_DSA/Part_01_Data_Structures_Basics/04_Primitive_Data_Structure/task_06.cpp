
/*
 TASK 6 SOLUTION — float precision trap (0.1 × 10 ≠ 1.0)
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float fs = 0.0f;
    double ds = 0.0;
    for (int i = 0; i < 10; i++) {
        fs += 0.1f;     // float wala sum
        ds += 0.1;      // double wala sum
    }
    cout << setprecision(20);
    cout << "float  sum of 0.1 ×10 = " << fs << "  diff=" << fs - 1.0 << "\n";
    cout << "double sum of 0.1 ×10 = " << ds << "  diff=" << ds - 1.0 << "\n";
    return 0;
}
// Explanation: 0.1 binary me infinite decimal hai, isliye har add me
// chhota error accumulate hota hai. Float error bada hai (≈1e-7), double
// chhota (≈1e-16), dono exactly 1.0 nahi aate. Loop 10 iterations → O(1)
// because count fixed; space O(1).