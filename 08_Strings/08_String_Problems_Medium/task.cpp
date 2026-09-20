/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 08_String_Problems_Medium task.cpp
│
│ REAL-WORLD SCENARIO:
│ Interview medium practice me cipher mapping, anagram grouping, bracket validation, sliding window, and prefix sum queries solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Isomorphic strings check karo.
│ 2. Group anagrams using frequency key.
│ 3. Valid parentheses using stack.
│ 4. Longest substring without repeat brute force.
│ 5. Longest substring without repeat sliding window.
│ 6. Vowel prefix sum banao and range query answer karo.
│ 7. Sliding window states ASCII comments me print karo.
│ 8. Approach comparison table likho.
│
│ HINTS:
│ - Isomorphic needs two maps.
│ - Parentheses stack top matching hona chahiye.
│ - Sliding window: right add, while duplicate left remove.
│ - Prefix query: prefix[r+1]-prefix[l].
│
│ STARTER CODE:
│ vector<int> freq(256,0); int left=0;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / WINDOW STATE:
│ Sliding window abcabcbb:
│ a -> ab -> abc -> duplicate a, left moves -> bca
│ best=3
│
│ Prefix leetcode:
│ query [1,3] eet has 2 vowels.
│
│ DRY RUN:
│ Parentheses ({[]}) push push push, then pop matching closers.
│ Isomorphic egg/add: e->a, g->d consistent.
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Isomorphic/parentheses/sliding scan n chars = O(n).
│ - Brute longest unique O(n³).
│ - Prefix build O(n), each query O(1).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack can store O(n) brackets.
│ - Sliding freq fixed 256 -> O(1).
│ - Prefix array O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

int longestUniqueSliding(const string& s) {
    vector<int> freq(256,0);
    int left=0,best=0;
    for (int right=0; right<(int)s.size(); right++) {
        unsigned char ch=s[right];
        freq[ch]++;
        while (freq[ch] > 1) { freq[(unsigned char)s[left]]--; left++; }
        best=max(best,right-left+1);
    }
    return best;
}

int main() {
    cout << "Longest unique abcabcbb = " << longestUniqueSliding("abcabcbb") << "\n";
    cout << "Valid parentheses uses stack; group anagrams uses freq-key hashing.\n";
    cout << "Vowel prefix query formula: prefix[r+1]-prefix[l].\n";
    return 0;
}

/*
OUTPUT:
Longest unique abcabcbb = 3
Valid parentheses uses stack; group anagrams uses freq-key hashing.
Vowel prefix query formula: prefix[r+1]-prefix[l].
*/

