/*
═══════════════════════════════════════════════
 REMOVE VOWELS
 ⏱️ TIME COMPLEXITY: O(n) — one loop scans n chars with a constant vowel check, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An SMS compressor wants to shorten text by removing vowels. Check each character;
 if it is a vowel, skip it, otherwise append it to the answer.

 📖 THEORY:
 - Check each character for being a vowel using a lowercase copy.
 - Vowels a, e, i, o, u are skipped.
 - All remaining characters are appended to the answer.
 - Use tolower for case-insensitive removal.
 - Non-letters can normally be kept.

 ASCII VISUAL / COUNT STATE:
 s="Beautiful Day"
 B keep
 e vowel skip
 a vowel skip
 u vowel skip
 t keep
 i skip
 f keep
 u skip
 l keep
 space keep
 D keep
 a skip
 y keep
 Result: Btfl Dy

 🧠 LOGIC — STEP BY STEP:
 Step 1: Convert the char to lowercase for the vowel test.
    WHY: this makes the check case-insensitive.
 Step 2: If it is a vowel (a/e/i/o/u), skip it.
    WHY: vowels are the characters being removed.
 Step 3: Otherwise append it to the answer.
    WHY: consonants, spaces and symbols are kept.

 DRY RUN:
 Scan each char:
 vowels removed: e,a,u,i,u,a
 kept chars form "Btfl Dy"

 FLOW OF EXECUTION:
 input string -> loop each char -> skip vowels / keep others -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop scans n chars once.
 - Each char constant vowel check.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Answer string can store up to n chars.
 -> Extra Space Complexity = O(n).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isVowel(char ch) {
    ch = (char)tolower((unsigned char)ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

int main() {
    string s = "Beautiful Day";
    string ans;
    for (char ch : s) if (!isVowel(ch)) ans.push_back(ch);
    cout << "After removing vowels = " << ans << "\n";
    return 0;
}

/*
OUTPUT:
After removing vowels = Btfl Dy
*/

