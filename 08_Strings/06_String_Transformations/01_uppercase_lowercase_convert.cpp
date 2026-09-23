/*
═══════════════════════════════════════════════
 UPPERCASE / LOWERCASE CONVERSION
 ⏱️ TIME COMPLEXITY: O(n) — one loop scans n chars for lower and one for upper, total 2n operations, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A school notice board sometimes needs text in uppercase and sometimes in lowercase.
 The ASCII difference between cases makes the conversion easy to understand.

 📖 THEORY:
 - `tolower(ch)` and `toupper(ch)` are library functions for case conversion.
 - ASCII trick: lowercase - uppercase = 32.
 - 'a' - 'A' = 97 - 65 = 32.
 - Upper to lower: ch + 32 if the char is in A-Z.
 - Lower to upper: ch - 32 if the char is in a-z.

 ASCII VISUAL / COUNT STATE:
 ASCII snapshot:
 'A'=65, 'B'=66 ... 'Z'=90
 'a'=97, 'b'=98 ... 'z'=122

 'a' - 'A' = 97 - 65 = 32

 'D' + 32 = 'd'
 'm' - 32 = 'M'

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop over each character of the string.
    WHY: conversion is applied character by character.
 Step 2 (to lower): if ch is in A-Z, add 32.
    WHY: adding 32 maps an uppercase letter to its lowercase ASCII value.
 Step 3 (to upper): if ch is in a-z, subtract 32.
    WHY: subtracting 32 maps a lowercase letter to its uppercase ASCII value.
 Step 4: Leave all other characters unchanged.
    WHY: only letters have case.

 DRY RUN:
 s="HeLLo"
 toLower:
 H->h, e->e, L->l, L->l, o->o => hello
 toUpper:
 H->H, e->E, L->L, L->L, o->O => HELLO

 FLOW OF EXECUTION:
 input string -> loop each char -> add/subtract 32 within letter ranges -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop scans n characters for lower conversion.
 - Loop scans n characters for upper conversion.
 - Total 2n operations.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Result strings store n+n chars in this demo.
 -> Extra Space Complexity = O(n).
═══════════════════════════════════════════════
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

