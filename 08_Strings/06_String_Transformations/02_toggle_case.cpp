/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_toggle_case.cpp
│
│ REAL-WORLD SCENARIO:
│ Chat app me Caps Lock toggle jaisa feature chahiye: lowercase uppercase ban jaye aur uppercase lowercase. Har character ko inspect karna hoga.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. String ke har character par loop.
│ 2. Agar ch uppercase A-Z hai, ch += 32.
│ 3. Agar ch lowercase a-z hai, ch -= 32.
│ 4. Non-alphabet chars unchanged.
│ 5. Same string in-place modify ho sakti hai.
│
│ ASCII VISUAL / COUNT STATE:
│ s="HeLLo 123"
│ H -> h
│ e -> E
│ L -> l
│ L -> l
│ o -> O
│ space/123 unchanged
│ Result: hEllO 123
│
│ DRY RUN:
│ i0 H uppercase -> h
│ i1 e lowercase -> E
│ i2 L uppercase -> l
│ i3 L uppercase -> l
│ i4 o lowercase -> O
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n chars once.
│ - Each char constant range checks.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - In-place modification, no extra string.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
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

