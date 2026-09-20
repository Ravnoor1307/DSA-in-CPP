/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_first_non_repeating_char_approach1.cpp
│
│ REAL-WORLD SCENARIO:
│ Queue me sabse pehla unique token dhundhna hai, lekin helper counter nahi hai. Har token ke liye poori line scan karni padegi.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Outer loop current character choose karta hai.
│ 2. Inner loop us character ka total count nikalta hai.
│ 3. Jiska count 1 pehle milta hai, wahi first non-repeating.
│ 4. Simple but O(n²) hai.
│ 5. Small strings/explanation ke liye useful, production me frequency better.
│
│ ASCII VISUAL / COUNT STATE:
│ s="swiss"
│ i=0 s -> scan all, count 3 -> not unique
│ i=1 w -> scan all, count 1 -> first non-repeating w
│ Answer = w
│
│ DRY RUN:
│ Check s:
│ compare s with s,w,i,s,s -> count3
│ Check w:
│ compare w with s,w,i,s,s -> count1 -> return w
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Outer loop can run n times.
│ - Inner loop runs n times for each outer char.
│ - Worst comparisons = n*n.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - No extra frequency array.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

char firstNonRepeatingNested(const string& s) {
    for (int i = 0; i < (int)s.size(); i++) {
        int count = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[i] == s[j]) count++;
        }
        if (count == 1) return s[i];
    }
    return '#';
}

int main() {
    string s = "swiss";
    cout << "First non-repeating = " << firstNonRepeatingNested(s) << "\n";
    return 0;
}

/*
OUTPUT:
First non-repeating = w
*/

