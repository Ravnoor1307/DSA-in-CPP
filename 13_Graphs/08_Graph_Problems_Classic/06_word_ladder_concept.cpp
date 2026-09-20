/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_word_ladder_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Word game me ek word se doosre word tak jaana hai, har step me sirf one letter change allowed hai. Words graph nodes hain, one-letter difference edges hain; shortest transformation BFS se milega.
│
│ ASCII VISUAL / GRAPH-GRID STATE:
│ begin = hit, end = cog
│ dictionary = hot, dot, dog, lot, log, cog
│
│ Word graph edges:
│ hit -> hot
│ hot -> dot, lot
│ dot -> dog
│ lot -> log
│ dog -> cog
│ log -> cog
│
│ BFS levels:
│ level1: hit
│ level2: hot
│ level3: dot, lot
│ level4: dog, log
│ level5: cog
│
│ Answer ladder length = 5
│ Path example: hit -> hot -> dot -> dog -> cog

│
│ STEP-BY-STEP DRY RUN:
│ q=[(hit,1)]
│ pop hit, generate hot -> q=[(hot,2)]
│ pop hot, generate dot,lot -> q=[(dot,3),(lot,3)]
│ pop dot, generate dog -> q=[(lot,3),(dog,4)]
│ pop lot, generate log -> q=[(dog,4),(log,4)]
│ pop dog, generate cog -> found length5.

│
│ COMPLEXITY CALCULATION:
│ Let N = number of dictionary words, L = word length.
│ For each popped word, for each L positions try 26 letters -> 26L transformations.
│ Each valid word removed from set once, so at most N words popped.
│ Time = O(N * L * 26) = O(NL).
│ Space = dictionary set O(N) + queue O(N).

│ APPROACH COMPARISON TABLE:
│ | Classic problem | Pattern | Real-world analogy | Time | Space |
│ | Rotten oranges | multi-source BFS | infection waves | O(R*C) | O(R*C) |
│ | Course schedule | Kahn topological BFS | prerequisites unlock | O(V+E) | O(V+E) |
│ | Flood fill | DFS/BFS grid | paint bucket | O(R*C) | O(R*C) |
│ | Surrounded regions | boundary DFS | safe boundary region | O(R*C) | O(R*C) |
│ | Bipartite | BFS 2-coloring | two teams | O(V+E) | O(V) |
│ | Word ladder | BFS on generated words | word transformation game | O(NL) | O(N) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;
    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    dict.erase(beginWord);

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        string word = cur.first;
        int level = cur.second;
        if (word == endWord) return level;

        for (int i = 0; i < (int)word.size(); i++) {
            string next = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                next[i] = ch;
                if (dict.count(next)) {
                    dict.erase(next); // Visited mark: word dobara queue me nahi jayega.
                    q.push({next, level + 1});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << "Word ladder length = " << ladderLength("hit", "cog", words) << "\n";
    return 0;
}

/*
OUTPUT:
Word ladder length = 5
*/

