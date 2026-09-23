/*
═══════════════════════════════════════════════
 GROUP ANAGRAMS — CONCEPT
 ⏱️ TIME COMPLEXITY: O(T + 26*k) = O(T) for k words with total characters T, extra space O(T)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a Scrabble club, words made of the same letters belong in the same box: eat, tea,
 ate form one group. Frequency-key hashing groups anagrams together.

 📖 THEORY:
 - Build a 26-count frequency key for each word.
 - Words with the same key are anagrams.
 - Use map/unordered_map: key -> vector of words.
 - The frequency key is conceptually O(word length), faster than sorting.
 - Hashing will be covered in detail in its own module; this is a preview.

 ASCII VISUAL / WINDOW STATE:
 words: eat, tea, tan, ate, nat, bat

 eat key: a1e1t1
 tea key: a1e1t1
 ate key: a1e1t1
 group -> [eat, tea, ate]

 tan/nat key: a1n1t1 -> [tan,nat]

 🧠 LOGIC — STEP BY STEP:
 Step 1: For each word, count letters into freq[26].
    WHY: anagrams share identical letter counts.
 Step 2: Serialize the counts into a string key.
    WHY: equal keys let a hash map bucket anagrams together.
 Step 3: Insert the word into groups[key].
    WHY: every word lands in its anagram bucket.
 Step 4: Output each bucket as a group.
    WHY: each bucket is exactly one set of anagrams.

 DRY RUN:
 eat -> key #1, push in group1
 tea -> same key #1, same group
 tan -> key #2
 ate -> key #1
 nat -> key #2
 bat -> key #3

 FLOW OF EXECUTION:
 input words -> build frequency key per word -> bucket by key -> print groups

 TIME COMPLEXITY CALCULATION:
 - Let total characters across all words = T.
 - Building freq key for each word scans its chars; total T.
 - Fixed 26 loop per word to serialize key.
 -> Time Complexity = O(T + 26*k) = O(T) for k words.

 SPACE COMPLEXITY CALCULATION:
 - Map stores all words and keys.
 -> Extra Space Complexity = O(T).
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

string freqKey(const string& word) {
    vector<int> freq(26, 0);
    for (char ch : word) if (ch >= 'a' && ch <= 'z') freq[ch - 'a']++;
    string key;
    for (int i = 0; i < 26; i++) key += "#" + to_string(freq[i]);
    return key;
}

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    map<string, vector<string>> groups;
    for (const string& word : words) groups[freqKey(word)].push_back(word);

    cout << "Grouped anagrams:\n";
    for (const auto& entry : groups) {
        cout << "group: ";
        for (const string& word : entry.second) cout << word << " ";
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
Grouped anagrams:
group: bat
group: eat tea ate
group: tan nat
*/

