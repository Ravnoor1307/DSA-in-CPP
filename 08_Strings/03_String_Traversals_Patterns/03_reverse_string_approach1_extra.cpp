/*
═══════════════════════════════════════════════
 REVERSE STRING — APPROACH 1 (EXTRA STRING)
 ⏱️ TIME COMPLEXITY: O(n) — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A mirror app needs to show a name backwards. The easy method is to
 build a brand-new string by copying the original from right to left.

 📖 THEORY:
 - Create an empty answer string.
 - Loop from the last index of the original down to 0.
 - Push each character into the answer.
 - The original string stays unchanged.
 - This uses O(n) extra space.

 ASCII DIAGRAM / POINTER STATE:

 s = "hello"
 index: 0 1 2 3 4
 char:  h e l l o

 reverse build:
 ans="" -> "o" -> "ol" -> "oll" -> "olle" -> "olleh"

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create an empty answer string.
    WHY: It will collect characters in reversed order.
 Step 2: Run the index from size-1 down to 0.
    WHY: The last character of s must become the first of the answer.
 Step 3: Append each visited character to the answer.
    WHY: Appending in this order automatically reverses the sequence.
 Step 4: Return the answer while leaving s untouched.
    WHY: This approach favors simplicity and non-mutation over saving space.

 DRY RUN:
 i=4 add o
 i=3 add l
 i=2 add l
 i=1 add e
 i=0 add h
 final ans=olleh

 FLOW OF EXECUTION:
 input string -> scan/split/pointer movement -> build/modify answer -> print result

 TIME COMPLEXITY CALCULATION:
 - The loop runs n times.
 - Each iteration appends one character.
 - Total appends = n.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - The answer string stores n characters.
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

string reverseExtra(const string& s) {
    string ans;
    for (int i = (int)s.size() - 1; i >= 0; i--) ans.push_back(s[i]);
    return ans;
}

int main() {
    string s = "hello";
    cout << "reverse using extra = " << reverseExtra(s) << "\n";
    return 0;
}

/*
OUTPUT:
reverse using extra = olleh
*/

