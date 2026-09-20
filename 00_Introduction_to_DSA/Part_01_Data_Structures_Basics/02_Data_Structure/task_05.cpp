/*
 TASK 5 SOLUTION — delete by shifting
*/
#include <iostream>
#include <string>
using namespace std;
struct Student { string name; int marks; };
int main() {
    int n, p; cin >> n;
    Student s[100];
    for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].marks;
    cin >> p;

    for (int i = p; i < n - 1; i++) {
        s[i] = s[i + 1];             // aage wale record ko ek ghar peeche lao
    }
    n--;                             // delete ke baad count kam karo

    for (int i = 0; i < n; i++) {
        cout << s[i].name << " -> " << s[i].marks << "\n";
    }
    return 0;
}
// Explanation: array me physical delete nahi hota — hum element ko
// overwrite karte hain aur n ghatate hain. Shifting me (n-p) copies →
// worst case n-1 steps → O(n).
