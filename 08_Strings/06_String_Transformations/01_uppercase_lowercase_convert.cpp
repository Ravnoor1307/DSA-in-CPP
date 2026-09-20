/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_uppercase_lowercase_convert.cpp
│
│ REAL-WORLD SCENARIO:
│ School notice board par text kabhi uppercase, kabhi lowercase chahiye hota hai. ASCII difference se case convert samajh sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `tolower(ch)` and `toupper(ch)` library functions hain.
│ 2. ASCII trick: lowercase - uppercase = 32.
│ 3. 'a' - 'A' = 97 - 65 = 32.
│ 4. Upper to lower: ch + 32 if A-Z.
│ 5. Lower to upper: ch - 32 if a-z.
│
│ ASCII VISUAL / COUNT STATE:
│ ASCII snapshot:
│ 'A'=65, 'B'=66 ... 'Z'=90
│ 'a'=97, 'b'=98 ... 'z'=122
│
│ 'a' - 'A' = 97 - 65 = 32
│
│ 'D' + 32 = 'd'
│ 'm' - 32 = 'M' 
│
│ DRY RUN:
│ s="HeLLo"
│ toLower:
│ H->h, e->e, L->l, L->l, o->o => hello
│ toUpper:
│ H->H, e->E, L->L, L->L, o->O => HELLO
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n characters for lower conversion.
│ - Loop scans n characters for upper conversion.
│ - Total 2n operations.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Result strings store n+n chars in this demo.
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string toLowerManual(string s) {
    for (char& ch : s) if (ch >= 'A' && ch <= 'Z') ch = (char)(ch + 32);
    return s;
}
string toUpperManual(string s) {
    for (char& ch : s) if (ch >= 'a' && ch <= 'z') ch = (char)(ch - 32);
    return s;
}

int main() {
    string s = "HeLLo";
    cout << "ASCII 'a'-'A' = " << ('a' - 'A') << "\n";
    cout << "lower = " << toLowerManual(s) << "\n";
    cout << "upper = " << toUpperManual(s) << "\n";
    return 0;
}

/*
OUTPUT:
ASCII 'a'-'A' = 32
lower = hello
upper = HELLO
*/

