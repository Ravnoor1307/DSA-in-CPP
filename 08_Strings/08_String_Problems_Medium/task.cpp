/*
═══════════════════════════════════════════════
 TASK SET — STRING PROBLEMS (MEDIUM)
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: An interview medium-level practice session needs work on
    cipher mapping, anagram grouping, bracket validation, sliding windows, and
    prefix-sum queries. These are the patterns that appear again and again in
    medium string interviews.

 🧠 HOW TO SOLVE: Isomorphic strings need two maps (forward and reverse) to enforce a
    bijection. Group anagrams by a frequency key. Validate parentheses with a stack
    whose top must match each closer. For longest unique substring, expand the right
    edge and shrink the left while a duplicate exists. Answer repeated vowel range
    queries with prefix[r+1]-prefix[l].

 MODES/TOPICS COVERED:
  1. Check isomorphic strings
  2. Group anagrams using a frequency key
  3. Valid parentheses using a stack
  4. Longest substring without repeat with brute force
  5. Longest substring without repeat with a sliding window
  6. Build a vowel prefix sum and answer range queries
  7. Print the sliding window states as ASCII comments
  8. Write the approach comparison table

 HINTS:
 - Isomorphic needs two maps.
 - Parentheses stack top must match.
 - Sliding window: right adds, while duplicate left removes.
 - Prefix query: prefix[r+1]-prefix[l].

 STARTER CODE:
 vector<int> freq(256,0); int left=0;

 SOLUTION: A compact demo is below.

 ASCII VISUAL / WINDOW STATE:
 Sliding window abcabcbb:
 a -> ab -> abc -> duplicate a, left moves -> bca
 best=3

 Prefix leetcode:
 query [1,3] eet has 2 vowels.

 DRY RUN:
 Parentheses ({[]}) push push push, then pop matching closers.
 Isomorphic egg/add: e->a, g->d consistent.

 FLOW OF EXECUTION:
 input string(s) -> choose pattern/window/map -> update state -> return answer

 TIME COMPLEXITY CALCULATION:
 - Isomorphic/parentheses/sliding scan n chars = O(n).
 - Brute longest unique O(n³).
 - Prefix build O(n), each query O(1).

 SPACE COMPLEXITY CALCULATION:
 - Stack can store O(n) brackets.
 - Sliding freq fixed 256 -> O(1).
 - Prefix array O(n).
═══════════════════════════════════════════════
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

