/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_reverse_words_approach2_inplace.cpp
│
│ REAL-WORLD SCENARIO:
│ Whiteboard par full sentence reverse karne ke baad har word ko individually reverse karo, to words ka order reverse ho jata hai but letters correct ho jaate hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Extra spaces normalize karne ke liye words collect karo.
│ 2. Clean sentence banao with single spaces.
│ 3. Whole string reverse karo.
│ 4. Har word segment reverse karo.
│ 5. Trick: reverse all + reverse each word.
│ 6. In strict mutable char-array setting, same buffer me O(1) extra possible hota hai; C++ string clean implementation may create normalized string.
│
│ ASCII VISUAL / POINTER STATE:
│ "Hello World"
│ reverse whole -> "dlroW olleH"
│ reverse each word:
│ "dlroW" -> "World"
│ "olleH" -> "Hello"
│ Final -> "World Hello"
│
│ Comparison:
│ Stack = word pile, O(n) extra.
│ Reverse trick = board flipping, O(1) extra if in-place buffer.
│
│ DRY RUN:
│ s="Hello World"
│ Step1 reverse all: dlroW olleH
│ Step2 word [0..4] reverse -> World
│ Step3 word [6..10] reverse -> Hello
│ answer World Hello
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Clean/normalize reads n chars.
│ - reverse whole swaps n/2 chars.
│ - reverse each word total swaps <= n/2.
│ - Total linear passes over n chars.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - If normalized string is built, O(n) extra.
│ - If input buffer is already clean and modified in-place, O(1) extra.
│ -> This demo uses O(n) due to clean string creation.
│ APPROACH COMPARISON TABLE:
│ Stack method = put word cards in a pile, O(n) time/O(n) space.
│ Reverse trick = flip full board then each word, O(n) time/O(1) possible on mutable clean buffer.
└────────────────────────────────────────────────────────────┘
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

