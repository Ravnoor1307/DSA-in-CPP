/*
═══════════════════════════════════════════════
 PALINDROME CHECK — APPROACH 1 (REVERSE & COMPARE)
 ⏱️ TIME COMPLEXITY: O(n) — reverse copies/writes n chars and compare checks up to n chars, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A word seen in a mirror looks identical if it is a palindrome, like "MADAM".
 The simplest check: build the reverse of the string and compare it with the
 original — if both are the same, the string is a palindrome.

 📖 THEORY:
 - A palindrome reads the same forwards and backwards (e.g. "madam", "level").
 - Reverse & Compare: create a copy, reverse the copy, then test original == reversed.
 - If original == reversed, it is a palindrome; otherwise it is not.
 - Very simple to reason about, but it needs an extra O(n) space for the reversed copy.
 - Starter input for the demo: "madam".

 ASCII VISUAL / POINTER STATE:
 s = "madam"
 reverse = "madam"
 same -> palindrome

 s = "hello"
 reverse = "olleh"
 different -> not palindrome

 🧠 LOGIC — STEP BY STEP:
 Step 1: Copy the original string.
    WHY: the copy is flipped without touching the input.
 Step 2: Reverse the copy.
    WHY: reversing creates the mirror image of the string.
 Step 3: Compare original == reversed.
    WHY: equal strings mean it reads the same both ways.
 Step 4: If same -> palindrome, else -> not palindrome.
    WHY: the comparison directly decides the answer.
 Step 5: Note that extra O(n) space is used.
    WHY: the reversed copy stores n characters.

 DRY RUN:
 madam:
 copy madam
 reverse copy -> madam
 compare char by char all same -> YES

 FLOW OF EXECUTION:
 input string -> copy original -> reverse the copy -> compare -> print result

 TIME COMPLEXITY CALCULATION:
 - Reverse copies/swaps n chars.
 - Compare may check n chars.
 - Total about 2n operations.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Reversed copy stores n characters.
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

bool isPalindromeReverseCompare(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    string s = "madam";
    cout << s << " palindrome? " << (isPalindromeReverseCompare(s) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
madam palindrome? YES
*/

