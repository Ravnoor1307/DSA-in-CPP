/*
═══════════════════════════════════════════════
 PALINDROME CHECK — APPROACH 1 (MANUAL REVERSE BUILD)
 ⏱️ TIME COMPLEXITY: O(n) — reverse-build loop runs n times plus compare up to n chars, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A security code must be verified against its reverse. This version builds the
 reversed string by hand — appending characters from the end of the original to
 the start — instead of using the STL reverse. It makes the reverse logic visible.

 📖 THEORY:
 - Start with an empty reversed string.
 - Walk the original from the last character to the first, appending each char.
 - Compare the built reversed string with the original.
 - Equal strings mean palindrome, unequal means not.
 - This approach clearly shows how reversal works under the hood.
 - An extra string of O(n) is used to hold the reversed result.

 ASCII VISUAL / POINTER STATE:
 s="racecar"
 build reverse:
 "" -> r -> ra -> rac -> race -> racec -> raceca -> racecar
 original == reverse -> YES

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create an empty reversed string.
    WHY: the reversed result is accumulated here.
 Step 2: For i from n-1 down to 0, append s[i].
    WHY: appending from the end gives the exact mirror order.
 Step 3: Compare the built string with the original.
    WHY: equality decides palindrome; the string operator compares char by char.

 DRY RUN:
 i=6 r, i=5 a, i=4 c, i=3 e, i=2 c, i=1 a, i=0 r
 reversed=racecar
 compare true

 FLOW OF EXECUTION:
 input string -> loop from last char to first -> append chars to build reverse -> compare with original -> print result

 TIME COMPLEXITY CALCULATION:
 - Reverse build loop runs n times.
 - Compare loop internally up to n chars.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Reversed string stores n chars.
 -> Extra Space Complexity = O(n).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindromeManualReverse(const string& s) {
    string rev;
    for (int i = (int)s.size() - 1; i >= 0; i--) rev.push_back(s[i]);
    return s == rev;
}

int main() {
    string s = "racecar";
    cout << s << " palindrome? " << (isPalindromeManualReverse(s) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
racecar palindrome? YES
*/

