/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_char_frequency_approach2_array26.cpp
│
│ REAL-WORLD SCENARIO:
│ Alphabet attendance board me 26 fixed boxes hain: a se z tak. Har letter ko direct uske box me count karna fastest hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `vector<int> freq(26,0)` banao.
│ 2. Har lowercase char ch ke liye index = ch - 'a'.
│ 3. freq[index]++ karo.
│ 4. Mapping trick: a->0, b->1, ..., z->25.
│ 5. Ye array-indexing trick anagram/sliding-window me bahut kaam aayegi.
│
│ ASCII VISUAL / COUNT STATE:
│ s="banana"
│
│ a b c d ... n ... z
│ 3 1 0 0 ... 2 ... 0
│
│ Mapping:
│ 'a'-'a'=0
│ 'b'-'a'=1
│ 'n'-'a'=13
│
│ DRY RUN:
│ b -> index 1 -> freq[1]=1
│ a -> index 0 -> freq[0]=1
│ n -> index 13 -> freq[13]=1
│ a -> freq[0]=2
│ n -> freq[13]=2
│ a -> freq[0]=3
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n characters once.
│ - Each char direct index and increment = O(1).
│ - Total operations proportional to n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Frequency array has fixed 26 cells.
│ -> Extra Space Complexity = O(26) = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "banana";
    vector<int> freq(26, 0);
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') freq[ch - 'a']++; // array-indexing trick
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) cout << char('a' + i) << " -> " << freq[i] << "\n";
    }
    return 0;
}

/*
OUTPUT:
a -> 3
b -> 1
n -> 2
*/

