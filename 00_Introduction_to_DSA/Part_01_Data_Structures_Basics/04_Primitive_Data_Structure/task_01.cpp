/*
 TASK 1 SOLUTION — sizes of all primitives
*/
#include <iostream>
using namespace std;
int main() {
    cout << "short     = " << sizeof(short)     << " bytes\n";
    cout << "int       = " << sizeof(int)       << " bytes\n";
    cout << "long      = " << sizeof(long)      << " bytes\n";
    cout << "long long = " << sizeof(long long) << " bytes\n";
    cout << "float     = " << sizeof(float)     << " bytes\n";
    cout << "double    = " << sizeof(double)    << " bytes\n";
    cout << "char      = " << sizeof(char)      << " bytes\n";
    cout << "bool      = " << sizeof(bool)      << " bytes\n";
    return 0;
}
// Explanation: sizeof compile-time constant deta hai — koi runtime cost
// nahi. Fixed output → O(1) time, O(1) space.
