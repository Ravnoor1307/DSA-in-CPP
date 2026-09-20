/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_rotate_string_check.cpp
│
│ REAL-WORLD SCENARIO:
│ Necklace ko rotate karne par beads ka order circular shift hota hai. "abcde" rotate hoke "cdeab" ban sakta hai. Double-string trick se check karte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Dono strings length same honi chahiye.
│ 2. Original string ko khud se concatenate karo: s+s.
│ 3. Agar target is doubled string ka substring hai, target rotation hai.
│ 4. Example: abcde+abcde = abcdeabcde contains cdeab.
│ 5. Built-in find use kar sakte hain.
│
│ ASCII VISUAL / COUNT STATE:
│ s="abcde"
│ doubled="abcdeabcde"
│
│ rotations visible inside doubled:
│ abcde
│  bcdea
│   cdeab  <- target found
│    deabc
│     eabcd
│
│ DRY RUN:
│ s=abcde, goal=cdeab
│ lengths both 5.
│ doubled=abcdeabcde.
│ doubled.find(goal) returns index2.
│ answer true.
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Building doubled copies 2n chars -> O(n).
│ - find worst conceptual string matching n*m; here m=n, worst O(n²) for naive idea.
│ - Many library implementations optimize, but safe DSA statement with find can be O(n²) worst.
│ -> Time Complexity = O(n²) worst with naive find.
│
│ SPACE COMPLEXITY CALCULATION:
│ - doubled string stores 2n chars.
│ -> Extra Space Complexity = O(n).
│ APPROACH COMPARISON TABLE:
│ Manual rotate all shifts = rotate necklace one by one, O(n²) time/O(1) or O(n) space.
│ Double-string find = put two necklaces together, O(n²) worst with naive find/O(n) space, usually concise.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isRotation(const string& s, const string& goal) {
    if (s.size() != goal.size()) return false;
    string doubled = s + s;
    return doubled.find(goal) != string::npos;
}

int main() {
    cout << boolalpha;
    cout << "abcde rotation of cdeab? " << isRotation("abcde", "cdeab") << "\n";
    cout << "abcde rotation of abced? " << isRotation("abcde", "abced") << "\n";
    return 0;
}

/*
OUTPUT:
abcde rotation of cdeab? true
abcde rotation of abced? false
*/

