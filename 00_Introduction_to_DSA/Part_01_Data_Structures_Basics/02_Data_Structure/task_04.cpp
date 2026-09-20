
/*
 TASK 4 SOLUTION — update + highest scorer
*/
#include <iostream>
#include <string>
using namespace std;
struct Student { string name; int marks; };
int main() {
    int n; cin >> n;
    Student s[100];
    for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].marks;

    for (int i = 0; i < n; i++) {
        s[i].marks += 5;             // update operation: bonus marks add
    }

    int maxIdx = 0;                  // abhi tak ka topper = pehla student
    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[maxIdx].marks) {
            maxIdx = i;              // naya topper mila
        }
    }
    cout << "topper: " << s[maxIdx].name << " (" << s[maxIdx].marks << ")\n";
    return 0;
}
// Explanation: 2 independent loops — ek update (n steps), ek max find
// (n-1 comparisons). Total ≈ 2n steps → O(n).

