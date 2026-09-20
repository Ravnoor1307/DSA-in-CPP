/*
═══════════════════════════════════════════════
 COUNT WORDS AND SPACES
 ⏱️ TIME COMPLEXITY: O(n) single scan — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A word processor's status bar shows the word and space count. The simple
 trick `spaces + 1` only works for a clean sentence; leading, trailing,
 and multiple spaces are edge cases that must be handled properly.

 📖 THEORY:
 - Basic idea: a single-spaced sentence without edge spaces gives
   words = spaces + 1.
 - Trap: leading/trailing/multiple spaces break that formula.
 - Robust method: use an insideWord flag.
 - A non-space char when not inside a word starts a new word (count++).
 - On a space, set insideWord = false.
 - The space count can be counted separately.

 ASCII DIAGRAM / POINTER STATE:

 Clean: "hello world"
 spaces=1 -> words=2 works

 Edge: "  hello   world  "
 spaces=7 -> spaces+1=8 wrong
 Robust scan:
 spaces skip, h starts word1, after spaces w starts word2
 words=2

 🧠 LOGIC — STEP BY STEP:
 Step 1: Scan the string from left to right.
    WHY: Each transition between spaces and letters can be detected once.
 Step 2: On a space, increment the space counter and clear insideWord.
    WHY: A gap means the current word has ended.
 Step 3: On a non-space when insideWord is false, start a word.
    WHY: A letter after a gap is the first letter of a new word.
 Step 4: Keep traversing the letters without changing the word count.
    WHY: Letters inside the same word must not be double counted.

 DRY RUN:
 s="  hello   world  "
 char space -> spaces++
 char h while insideWord=false -> words=1, inside=true
 chars ello continue same word
 spaces -> inside=false
 char w -> words=2
 trailing spaces no new word

 FLOW OF EXECUTION:
 input string -> scan/split/pointer movement -> build/modify answer -> print result

 TIME COMPLEXITY CALCULATION:
 - The loop scans each of the n characters once.
 - Each char does constant checks.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Only counters and a boolean flag are used.
 -> Extra Space Complexity = O(1).
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

int main() {
    string s = "  hello   world  ";
    int spaces = 0, words = 0;
    bool insideWord = false;
    for (char ch : s) {
        if (ch == ' ') {
            spaces++;
            insideWord = false;
        } else if (!insideWord) {
            words++;
            insideWord = true;
        }
    }
    cout << "spaces=" << spaces << "\n";
    cout << "robust words=" << words << "\n";
    cout << "Note: spaces+1 trick fails here because of extra spaces.\n";
    return 0;
}

/*
OUTPUT:
spaces=7
robust words=2
Note: spaces+1 trick fails here because of extra spaces.
*/

