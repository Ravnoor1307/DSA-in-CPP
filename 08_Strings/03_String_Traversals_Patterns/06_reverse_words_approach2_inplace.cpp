/*
═══════════════════════════════════════════════
 REVERSE WORDS IN A STRING — APPROACH 2 (IN-PLACE REVERSE TRICK)
 ⏱️ TIME COMPLEXITY: O(n) — few linear passes (clean O(n), whole reverse ~n/2 swaps, per-word reverse ~n/2 swaps), extra O(n) here
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a whiteboard: first flip the entire message from left to right, then flip
 every word back to normal. The words land in reverse order while the letters inside
 each word become correct again. This two-step "flip everything, flip each word"
 trick reverses word order without needing any extra board.

 📖 THEORY:
 - Approach: reverse the WHOLE string, then reverse EACH individual word segment.
 - Collecting words with a stream normalizes extra spaces; a clean sentence with single
   spaces is built first.
 - Reversing all characters produces "dlroW olleH"; flipping each word back yields
   "World Hello".
 - In a strict mutable char-array setting, the same buffer can be modified in place
   using O(1) extra space; the C++ string version here builds a normalized string, so
   it uses O(n) extra space.
 - Trick to remember: reverse all + reverse each word.

 ASCII VISUAL / POINTER STATE:
 "Hello World"
 reverse whole -> "dlroW olleH"
 reverse each word:
 "dlroW" -> "World"
 "olleH" -> "Hello"
 Final -> "World Hello"

 Comparison:
 Stack = word pile, O(n) extra.
 Reverse trick = board flipping, O(1) extra if in-place buffer.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Normalize spaces by collecting words into a clean sentence.
    WHY: single spaces make word boundaries consistent for the segment reverses.
 Step 2: Reverse the whole cleaned string.
    WHY: the whole reversal puts the words in reverse order.
 Step 3: Reverse each word segment back to normal.
    WHY: reversing each segment fixes the letters while keeping the new word order.
 Step 4: Walk the array and flip from start to every space (or end).
    WHY: each space marks a word boundary; only whole words are flipped back.

 DRY RUN:
 s="Hello World"
 Step1 reverse all: dlroW olleH
 Step2 word [0..4] reverse -> World
 Step3 word [6..10] reverse -> Hello
 answer World Hello

 FLOW OF EXECUTION:
 input string -> tokenize/clean to single spaces -> reverse whole string -> reverse each word segment -> print result

 TIME COMPLEXITY CALCULATION:
 - Clean/normalize reads n chars.
 - Reverse whole swaps n/2 chars.
 - Reverse each word total swaps <= n/2.
 - Total linear passes over n chars.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - If normalized string is built, O(n) extra.
 - If input buffer is already clean and modified in-place, O(1) extra.
 -> This demo uses O(n) due to clean string creation.
 APPROACH COMPARISON TABLE:
 Stack method = put word cards in a pile, O(n) time/O(n) space.
 Reverse trick = flip full board then each word, O(n) time/O(1) possible on mutable clean buffer.
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

string normalizeSpaces(const string& s) {
    stringstream ss(s);
    string word, clean;
    while (ss >> word) {
        if (!clean.empty()) clean += ' ';
        clean += word;
    }
    return clean;
}

string reverseWordsInPlaceStyle(const string& input) {
    string s = normalizeSpaces(input);
    reverse(s.begin(), s.end());
    int n = s.size();
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    return s;
}

int main() {
    string s = "Hello World";
    cout << "Reverse words by reverse trick = " << reverseWordsInPlaceStyle(s) << "\n";
    cout << "Comparison: stack stores words; reverse trick transforms characters.\n";
    return 0;
}

/*
OUTPUT:
Reverse words by reverse trick = World Hello
Comparison: stack stores words; reverse trick transforms characters.
*/

