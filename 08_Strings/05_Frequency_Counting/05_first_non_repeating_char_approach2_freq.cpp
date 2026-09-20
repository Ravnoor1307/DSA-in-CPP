/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_first_non_repeating_char_approach2_freq.cpp
│
│ REAL-WORLD SCENARIO:
│ Class attendance me pehle total frequency register bana lo, phir line me pehla student jiska count 1 ho dhundho. Ye two-pass frequency method hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. PASS 1: frequency array/map banao.
│ 2. PASS 2: original string left to right scan karo.
│ 3. First char with freq==1 return karo.
│ 4. Order preserve karne ke liye second pass original string par hota hai.
│ 5. Lowercase case me array26 enough hai.
│
│ ASCII VISUAL / COUNT STATE:
│ s="swiss"
│ PASS 1 counts:
│ s:3, w:1, i:1
│ PASS 2:
│ s freq3 skip
│ w freq1 -> answer w
│
│ DRY RUN:
│ pass1: s,w,i,s,s counts build.
│ pass2: index0 s not unique; index1 w unique -> return.
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - PASS 1 scans n chars.
│ - PASS 2 scans up to n chars.
│ - Total scans = 2n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Fixed 256 frequency array used for ASCII.
│ -> Extra Space Complexity = O(256) = O(1).
│ APPROACH COMPARISON TABLE:
│ Nested = ask every student by rescanning full line, O(n²) time/O(1) space.
│ Frequency = make attendance register then one scan, O(n) time/O(1) ASCII space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

char firstNonRepeatingFreq(const string& s) {
    vector<int> freq(256, 0);
    for (unsigned char ch : s) freq[ch]++;
    for (unsigned char ch : s) {
        if (freq[ch] == 1) return (char)ch;
    }
    return '#';
}

int main() {
    string s = "swiss";
    cout << "First non-repeating using freq = " << firstNonRepeatingFreq(s) << "\n";
    cout << "Comparison: nested O(n^2), freq two-pass O(n).\n";
    return 0;
}

/*
OUTPUT:
First non-repeating using freq = w
Comparison: nested O(n^2), freq two-pass O(n).
*/

