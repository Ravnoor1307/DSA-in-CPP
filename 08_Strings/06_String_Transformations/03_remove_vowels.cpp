/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_remove_vowels.cpp
│
│ REAL-WORLD SCENARIO:
│ SMS compressor vowels hata kar short code banana chahta hai. Har character check karo; vowel ho to skip, warna answer me add karo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har character lowercase copy se vowel check karo.
│ 2. Vowels a,e,i,o,u skip karo.
│ 3. Baaki characters answer me append karo.
│ 4. Case-insensitive removal ke liye tolower use karo.
│ 5. Non-letters normally keep kar sakte hain.
│
│ ASCII VISUAL / COUNT STATE:
│ s="Beautiful Day"
│ B keep
│ e vowel skip
│ a vowel skip
│ u vowel skip
│ t keep
│ i skip
│ f keep
│ u skip
│ l keep
│ space keep
│ D keep
│ a skip
│ y keep
│ Result: Btfl Dy
│
│ DRY RUN:
│ Scan each char:
│ vowels removed: e,a,u,i,u,a
│ kept chars form "Btfl Dy"
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n chars once.
│ - Each char constant vowel check.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Answer string can store up to n chars.
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isVowel(char ch) {
    ch = (char)tolower((unsigned char)ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

int main() {
    string s = "Beautiful Day";
    string ans;
    for (char ch : s) if (!isVowel(ch)) ans.push_back(ch);
    cout << "After removing vowels = " << ans << "\n";
    return 0;
}

/*
OUTPUT:
After removing vowels = Btfl Dy
*/

