/*
═══════════════════════════════════════════════
 TASK SET — STRING TRANSFORMATIONS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A text editor and data-cleaning lab needs to convert, clean,
    compress, and rotation-check strings. These transformations power title-casing,
    case toggling, data cleanup, SMS-style compression, and rotation validators.

 🧠 HOW TO SOLVE: Use the ASCII gap 'a'-'A'=32 to change case (add 32 to lower,
    subtract to upper). Keep a seen[256] array to drop duplicate characters. Track a
    run of equal chars to compress ("aaabbc" -> "a3b2c1") and remember to append the
    last group. For rotation, require equal lengths and test `(s+s).find(goal)`.

 MODES/TOPICS COVERED:
  1. Uppercase to lowercase using the ASCII trick
  2. Lowercase to uppercase using the ASCII trick
  3. Implement toggle case
  4. Remove vowels from a string
  5. Remove spaces and duplicate chars preserving order
  6. Capitalize the first letter of every word
  7. String compression "aaabbc" -> "a3b2c1"
  8. Rotate string check using s+s

 HINTS:
 - 'a'-'A'=32.
 - seen[256] for duplicates.
 - For compression always append the last group.
 - For rotation, lengths must be equal and check `(s+s).find(goal)`.

 STARTER CODE:
 for(char &ch:s){ if(ch>='A'&&ch<='Z') ch+=32; }

 SOLUTION: A compact demo solution is below.

 ASCII VISUAL / COUNT STATE:
 Case:
 HeLLo -> hello / HELLO / hEllO
 Compression:
 aaabbc -> a3b2c1
 Rotation:
 abcdeabcde contains cdeab

 DRY RUN:
 remove vowels Beautiful Day -> Btfl Dy
 remove spaces duplicates a b a c c -> abc

 FLOW OF EXECUTION:
 input string -> scan/build frequency/transform -> produce output

 TIME COMPLEXITY CALCULATION:
 - Most transformations one scan n -> O(n).
 - Rotation with naive find worst O(n²).
 - Compression n-1 comparisons -> O(n).

 SPACE COMPLEXITY CALCULATION:
 - In-place case operations O(1).
 - Output-building transformations O(n).
 - Rotation doubled string O(n).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string compress(const string& s) {
    if (s.empty()) return "";
    string ans;
    char cur = s[0];
    int cnt = 1;
    for (int i=1;i<(int)s.size();i++) {
        if (s[i] == cur) cnt++;
        else { ans.push_back(cur); ans += to_string(cnt); cur = s[i]; cnt = 1; }
    }
    ans.push_back(cur); ans += to_string(cnt);
    return ans;
}

int main() {
    string s = "HeLLo";
    for (char& ch : s) {
        if (ch >= 'A' && ch <= 'Z') ch = (char)(ch + 32);
    }
    cout << "lower = " << s << "\n";
    cout << "compression = " << compress("aaabbc") << "\n";
    cout << "rotation? " << ((string("abcdeabcde").find("cdeab") != string::npos) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
lower = hello
compression = a3b2c1
rotation? YES
*/

