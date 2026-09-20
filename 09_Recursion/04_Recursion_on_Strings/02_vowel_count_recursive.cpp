/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_vowel_count_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ English teacher letters ko one-by-one check kar rahi hai. Recursion index ke current character ka vowel score add karta hai plus baaki string ka answer.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function countVowels(s,index).
│ 2. Base case: index == s.length(), return 0.
│ 3. current = 1 if s[index] vowel else 0.
│ 4. Return current + countVowels(s,index+1).
│ 5. Har character exactly once check hota hai.
│
│ ASCII VISUAL / STRING STATE:
│ s="education"
│ e vowel -> 1 + rest
│ d consonant -> 0 + rest
│ u vowel -> 1 + rest
│ ...
│ vowels: e,u,a,i,o = 5
│
│ DRY RUN:
│ index0 e -> 1
│ index1 d -> 0
│ index2 u -> 1
│ index3 c -> 0
│ index4 a -> 1
│ index5 t -> 0
│ index6 i -> 1
│ index7 o -> 1
│ index8 n -> 0
│ total 5
│
│ FLOW OF EXECUTION:
│ input string -> recursive index/pointers -> base case -> build/return output
│
│ COMPLEXITY CALCULATION:
│ - index increases from 0 to n.
│ - Calls = n+1 including base.
│ - Each call constant vowel check.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth n+1.
│ -> Space Complexity = O(n).
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

int countVowelsRec(const string& s, int index) {
    if (index == (int)s.size()) return 0;
    int current = isVowel(s[index]) ? 1 : 0;
    return current + countVowelsRec(s, index + 1);
}

int main() {
    cout << "vowels in education = " << countVowelsRec("education", 0) << "\n";
    return 0;
}

/*
OUTPUT:
vowels in education = 5
*/

