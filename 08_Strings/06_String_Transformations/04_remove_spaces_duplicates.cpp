/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_remove_spaces_duplicates.cpp
│
│ REAL-WORLD SCENARIO:
│ Data-cleaning app extra spaces aur duplicate characters hata kar clean ID banata hai. Pehle spaces skip karo, phir duplicate seen characters ignore karo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Remove spaces: char != ' ' ho to append.
│ 2. Remove duplicates: seen[256] use karo.
│ 3. Character first time mile to append and mark seen.
│ 4. Repeat char mile to skip.
│ 5. Order preserve hota hai.
│
│ ASCII VISUAL / COUNT STATE:
│ s="a b a c c"
│ remove spaces -> "abacc"
│ remove duplicates preserving order:
│ a keep, b keep, a skip, c keep, c skip
│ result -> "abc"
│
│ DRY RUN:
│ input chars:
│ a keep, space skip, b keep, space skip, a duplicate skip,
│ space skip, c keep, space skip, c duplicate skip
│ final abc
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n chars once.
│ - seen lookup constant O(1).
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - seen array fixed 256.
│ - Answer string up to n chars.
│ -> Extra Space Complexity = O(n) for answer, O(1) for seen.
└────────────────────────────────────────────────────────────┘
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

