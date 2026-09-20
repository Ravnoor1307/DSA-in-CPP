
/*
 TASK 4 SOLUTION — overflow detection with long long
*/
#include <iostream>
using namespace std;
int main() {
    long long a, b; cin >> a >> b;
    long long prod = a * b;                 // long long: 10^9 * 10^9 = 10^18
    cout << "correct product = " << prod << "\n";
    int wrong = (int)prod;                  // 10^18 ko int me thoopna impossible
    cout << "int cast gives  = " << wrong << "  (overflow corrupt aaya)\n";
    return 0;
}
// Explanation: int ki range ~±2.1e9 — product 10^18 uska bahut bada hai.
// Cast truncate karke galat value deta hai; long long (8 bytes)
// ise rakh leta hai. Constant ops → O(1).
