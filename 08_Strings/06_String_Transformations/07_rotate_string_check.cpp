/*
═══════════════════════════════════════════════
 ROTATE STRING CHECK (DOUBLE-STRING TRICK)
 ⏱️ TIME COMPLEXITY: O(n²) worst — building doubled copies 2n chars is O(n), naive find can be O(n*m)=O(n²) with m=n, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Rotating a necklace shifts the beads in a circular way. "abcde" rotated can become
 "cdeab". The double-string trick makes this easy to check.

 📖 THEORY:
 - Both strings must have the same length.
 - Concatenate the original string with itself: s+s.
 - If the target is a substring of the doubled string, the target is a rotation.
 - Example: abcde+abcde = abcdeabcde contains cdeab.
 - The built-in find can be used for the substring test.

 ASCII VISUAL / COUNT STATE:
 s="abcde"
 doubled="abcdeabcde"

 rotations visible inside doubled:
 abcde
  bcdea
   cdeab  <- target found
    deabc
     eabcd

 🧠 LOGIC — STEP BY STEP:
 Step 1: If lengths differ, return false.
    WHY: rotations preserve length, so unequal lengths can never match.
 Step 2: Build doubled = s + s.
    WHY: every rotation of s appears as a contiguous block inside s+s.
 Step 3: Search for goal inside doubled.
    WHY: a successful find means goal is one of s's rotations.

 DRY RUN:
 s=abcde, goal=cdeab
 lengths both 5.
 doubled=abcdeabcde.
 doubled.find(goal) returns index2.
 answer true.

 FLOW OF EXECUTION:
 input strings -> length check -> build s+s -> find goal inside -> print result

 TIME COMPLEXITY CALCULATION:
 - Building doubled copies 2n chars -> O(n).
 - find worst conceptual string matching n*m; here m=n, worst O(n²) for naive idea.
 - Many library implementations optimize, but safe DSA statement with find can be O(n²) worst.
 -> Time Complexity = O(n²) worst with naive find.

 SPACE COMPLEXITY CALCULATION:
 - doubled string stores 2n chars.
 -> Extra Space Complexity = O(n).
 APPROACH COMPARISON TABLE:
 Manual rotate all shifts = rotate necklace one by one, O(n²) time/O(1) or O(n) space.
 Double-string find = put two necklaces together, O(n²) worst with naive find/O(n) space, usually concise.
═══════════════════════════════════════════════
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

