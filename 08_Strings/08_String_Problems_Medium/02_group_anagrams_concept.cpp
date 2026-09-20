/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_group_anagrams_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Scrabble club me same letters wale words ko same box me rakhna hai: eat, tea, ate ek group. Frequency-key hashing se group anagrams bante hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har word ke liye 26-count frequency key banao.
│ 2. Same key wale words anagrams hote hain.
│ 3. map/unordered_map key -> vector words.
│ 4. Frequency key sorting se faster conceptual O(word length) hota hai.
│ 5. Hashing detailed module me aur aayega; yahan preview hai.
│
│ ASCII VISUAL / WINDOW STATE:
│ words: eat, tea, tan, ate, nat, bat
│
│ eat key: a1e1t1
│ tea key: a1e1t1
│ ate key: a1e1t1
│ group -> [eat, tea, ate]
│
│ tan/nat key: a1n1t1 -> [tan,nat]
│
│ DRY RUN:
│ eat -> key #1, push in group1
│ tea -> same key #1, same group
│ tan -> key #2
│ ate -> key #1
│ nat -> key #2
│ bat -> key #3
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Let total characters across all words = T.
│ - Building freq key for each word scans its chars; total T.
│ - Fixed 26 loop per word to serialize key.
│ -> Time Complexity = O(T + 26*k) = O(T) for k words.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores all words and keys.
│ -> Extra Space Complexity = O(T).
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

