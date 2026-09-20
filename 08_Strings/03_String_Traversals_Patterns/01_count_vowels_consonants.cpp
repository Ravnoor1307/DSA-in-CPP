/*
═══════════════════════════════════════════════
 COUNT VOWELS AND CONSONANTS
 ⏱️ TIME COMPLEXITY: O(n) single pass — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An English teacher wants the vowels and consonants counted in a
 sentence. We check every character and decide: is it a vowel, a
 consonant, or a non-letter to skip.

 📖 THEORY:
 - Traverse the string from left to right.
 - Convert each character to lowercase.
 - If it is not an alphabet letter, skip it.
 - If it is a/e/i/o/u, increment the vowel count.
 - Otherwise increment the consonant count.
 - Each character is checked exactly once.

 ASCII DIAGRAM / POINTER STATE:

 s = "Hello DSA"

 H -> h -> consonant
 e -> vowel
 l -> consonant
 l -> consonant
 o -> vowel
 space -> skip
 D -> d -> consonant
 S -> s -> consonant
 A -> a -> vowel

 vowels=3, consonants=5

 🧠 LOGIC — STEP BY STEP:
 Step 1: Walk the string one character at a time.
    WHY: A single pass guarantees every character is judged once.
 Step 2: Lowercase the character before comparing.
    WHY: 'A' and 'a' must be treated as the same vowel.
 Step 3: Skip non-alphabetic characters.
    WHY: Spaces, digits, and punctuation belong to neither group.
 Step 4: Classify a/e/i/o/u as vowel, the rest as consonant.
    WHY: These five letters define the vowel set; everything else is a
    consonant.

 DRY RUN:
 i0 H: consonant=1
 i1 e: vowel=1
 i2 l: consonant=2
 i3 l: consonant=3
 i4 o: vowel=2
 i5 space: skip
 i6 D: consonant=4
 i7 S: consonant=5
 i8 A: vowel=3

 FLOW OF EXECUTION:
 input string -> scan/split/pointer movement -> build/modify answer -> print result

 TIME COMPLEXITY CALCULATION:
 - The loop runs n times for n characters.
 - Each iteration does lowercase + alphabet/vowel checks, constant work.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Only two counters and a char variable are used.
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

bool isVowel(char ch) {
    ch = (char)tolower((unsigned char)ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

int main() {
    string s = "Hello DSA";
    int vowels = 0, consonants = 0;
    for (char ch : s) {
        if (!isalpha((unsigned char)ch)) continue;
        if (isVowel(ch)) vowels++;
        else consonants++;
    }
    cout << "vowels=" << vowels << ", consonants=" << consonants << "\n";
    return 0;
}

/*
OUTPUT:
vowels=3, consonants=5
*/

