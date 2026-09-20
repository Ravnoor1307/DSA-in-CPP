
/*
 TASK 3 SOLUTION — char vowel/consonant/digit
*/
#include <iostream>
using namespace std;
int main() {
    char c; cin >> c;
    if (c >= '0' && c <= '9') {
        cout << c << " is a digit\n";           // char me number bhi ho sakta hai
    } else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << c << " is a vowel\n";
    } else {
        cout << c << " is a consonant\n";
    }
    return 0;
}
// Explanation: char fayda — comparison '0'..'9' character boundaries se.
// Constant comparisons → O(1) time, O(1) space.
