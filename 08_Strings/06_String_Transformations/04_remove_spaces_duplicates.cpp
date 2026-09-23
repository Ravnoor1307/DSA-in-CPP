/*
═══════════════════════════════════════════════
 REMOVE SPACES AND DUPLICATES
 ⏱️ TIME COMPLEXITY: O(n) — one loop scans n chars with constant seen lookups, extra space O(n) for the answer, O(1) for seen
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A data-cleaning app strips extra spaces and duplicate characters to produce a clean
 ID. First skip spaces, then ignore characters already seen.

 📖 THEORY:
 - Remove spaces: append only when char != ' '.
 - Remove duplicates: use a seen[256] array.
 - The first time a character appears, append it and mark it seen.
 - A repeated character is skipped.
 - The original order of first appearances is preserved.

 ASCII VISUAL / COUNT STATE:
 s="a b a c c"
 remove spaces -> "abacc"
 remove duplicates preserving order:
 a keep, b keep, a skip, c keep, c skip
 result -> "abc"

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop over each character.
    WHY: cleaning is done character by character.
 Step 2: If the char is a space, skip it.
    WHY: spaces are not part of the clean ID.
 Step 3: If the char has not been seen, append it and mark seen.
    WHY: only the first occurrence is kept.
 Step 4: If already seen, skip it.
    WHY: duplicates are discarded while order is preserved.

 DRY RUN:
 input chars:
 a keep, space skip, b keep, space skip, a duplicate skip,
 space skip, c keep, space skip, c duplicate skip
 final abc

 FLOW OF EXECUTION:
 input string -> loop each char -> skip spaces -> keep first occurrence only -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop scans n chars once.
 - seen lookup constant O(1).
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - seen array fixed 256.
 - Answer string up to n chars.
 -> Extra Space Complexity = O(n) for answer, O(1) for seen.
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "a b a c c";
    vector<bool> seen(256, false);
    string ans;
    for (unsigned char ch : s) {
        if (ch == ' ') continue;
        if (!seen[ch]) {
            seen[ch] = true;
            ans.push_back((char)ch);
        }
    }
    cout << "After removing spaces and duplicates = " << ans << "\n";
    return 0;
}

/*
OUTPUT:
After removing spaces and duplicates = abc
*/

