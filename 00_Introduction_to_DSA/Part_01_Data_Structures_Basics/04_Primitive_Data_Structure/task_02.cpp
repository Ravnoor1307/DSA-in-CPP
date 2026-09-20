
/*
 TASK 2 SOLUTION — integer division trap
*/
#include <iostream>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    cout << "int division   : " << a / b << "\n";          // truncate hota hai
    cout << "float division : " << (float)a / b << "\n";   // pehle float cast
    cout << "double division: " << (double)a / b << "\n";  // zyada precision
    return 0;
}
// Input 7 2 → int:3, float:3.5, double:3.5.
// Explanation: int/int integer division karta hai (bina point wala part).
// Cast ke baad hi decimal aata hai. Constant ops → O(1).
