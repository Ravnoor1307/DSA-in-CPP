
/*
 TASK 3 SOLUTION — linear search
*/
#include <iostream>
#include <string>
using namespace std;
struct Student { string name; int marks; };
int main() {
    int n; cin >> n;
    Student s[100];
    for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].marks;
    string key; cin >> key;
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (s[i].name == key) {      // match mil gaya
            found = i;
            break;                   // pehla match — duplicate edge case ke liye
        }
    }
    if (found == -1) cout << "NOT FOUND\n";
    else cout << s[found].name << " has " << s[found].marks << " marks\n";
    return 0;
}
// Explanation: worst case me saare n records compare hue (n steps) → O(n).
// found = -1 sentinel hai — "abhi tak nahi mila" ka indicator.
