/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_top_k_frequent_words.cpp
│
│ REAL-WORLD SCENARIO:
│ Search engine trending words dikhata hai: frequency high pehle, tie me lexicographically smaller word pehle. Hashmap count + heap ranking pattern use hota hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ words = [i,love,leetcode,i,love,coding], k=2
│ frequency:
│ i -> 2
│ love -> 2
│ leetcode -> 1
│ coding -> 1
│
│ Ranking:
│ high frequency first
│ tie: smaller word first
│
│ Top 2 = i, love
│ because both freq2 and "i" < "love".

│
│ STEP-BY-STEP DRY RUN:
│ Step1 count frequency with unordered_map.
│ Step2 push words into priority queue with comparator.
│ Step3 pop k words.

│
│ COMPLEXITY CALCULATION:
│ n total words, m unique words.
│ Count loop n hashmap updates -> O(n) average.
│ Push m words into heap -> O(m log m).
│ Pop k words -> O(k log m).
│ Total = O(n + m log m + k log m).
│ Space = map O(m) + heap O(m).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct WordCmp {
    unordered_map<string,int>* freq;
    bool operator()(const string& a, const string& b) const {
        if ((*freq)[a] != (*freq)[b]) return (*freq)[a] < (*freq)[b]; // higher freq top
        return a > b; // lexicographically smaller top
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string,int> freq;
    for (const string& w : words) freq[w]++;
    WordCmp cmp{&freq};
    priority_queue<string, vector<string>, WordCmp> pq(cmp);
    for (auto& e : freq) pq.push(e.first);
    vector<string> ans;
    while (k-- && !pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    vector<string> ans = topKFrequent(words, 2);
    for (const string& w : ans) cout << w << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
i love
*/

