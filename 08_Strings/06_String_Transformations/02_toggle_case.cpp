/*
═══════════════════════════════════════════════
 TOGGLE CASE
 ⏱️ TIME COMPLEXITY: O(n) — one loop visits n chars with constant range checks, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A chat app wants a Caps Lock toggle: lowercase becomes uppercase and uppercase becomes
 lowercase. Each character must be inspected to decide its new case.

 📖 THEORY:
 - Loop over every character of the string.
 - If ch is uppercase A-Z, add 32.
 - If ch is lowercase a-z, subtract 32.
 - Non-alphabet characters stay unchanged.
 - The same string can be modified in place.

 ASCII VISUAL / COUNT STATE:
 s="HeLLo 123"
 H -> h
 e -> E
 L -> l
 L -> l
 o -> O
 space/123 unchanged
 Result: hEllO 123

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop over each character by reference.
    WHY: modifying in place avoids an extra string.
 Step 2: If ch is in A-Z, add 32.
    WHY: an uppercase letter becomes lowercase.
 Step 3: Else if ch is in a-z, subtract 32.
    WHY: a lowercase letter becomes uppercase.
 Step 4: Leave everything else as is.
    WHY: digits, spaces and symbols have no case.

 DRY RUN:
 i0 H uppercase -> h
 i1 e lowercase -> E
 i2 L uppercase -> l
 i3 L uppercase -> l
 i4 o lowercase -> O

 FLOW OF EXECUTION:
 input string -> loop each char -> flip case in place -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop visits n chars once.
 - Each char constant range checks.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - In-place modification, no extra string.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "HeLLo 123";
    for (char& ch : s) {
        if (ch >= 'A' && ch <= 'Z') ch = (char)(ch + 32);
        else if (ch >= 'a' && ch <= 'z') ch = (char)(ch - 32);
    }
    cout << "Toggle case = " << s << "\n";
    return 0;
}

/*
OUTPUT:
Toggle case = hEllO 123
*/

