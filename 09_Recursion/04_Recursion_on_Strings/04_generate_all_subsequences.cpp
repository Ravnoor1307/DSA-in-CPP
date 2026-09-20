/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_generate_all_subsequences.cpp
│
│ REAL-WORLD SCENARIO:
│ Treasure selection game me har item ke liye 2 choices hoti hain: TAKE ya SKIP. String subsequences bhi har character ke take/skip decisions se banti hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function generate(index,current).
│ 2. Base case: index == n, current subsequence ready.
│ 3. Recursive branch 1: TAKE s[index].
│ 4. Recursive branch 2: SKIP s[index].
│ 5. Total subsequences 2^n, empty subsequence included conceptually.
│ 6. "abc" non-empty subsequences: a,b,c,ab,ac,bc,abc.
│
│ ASCII VISUAL / STRING STATE:
│ Take/Skip tree for "abc":
│
│                         ""
│                    /take a   \skip a
│                  "a"          ""
│              /take b \skip b /take b \skip b
│            "ab"      "a"   "b"      ""
│           /  \       / \    / \      / \
│        abc  ab     ac  a   bc  b    c  ""
│
│ Non-empty results: a,b,c,ab,ac,bc,abc
│
│ DRY RUN:
│ index0 char a: take -> current a, skip -> current empty
│ index1 char b: branches from both states
│ index2 char c: branches again
│ leaves = 2^3=8 including empty.
│
│ FLOW OF EXECUTION:
│ input string -> recursive index/pointers -> base case -> build/return output
│
│ COMPLEXITY CALCULATION:
│ - Each character has 2 choices.
│ - Leaves = 2*2*... n times = 2^n.
│ - Building/printing subsequences can take up to n per leaf.
│ -> Time Complexity = O(n*2^n) when storing/printing strings.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion depth n.
│ - Output list stores 2^n strings, total chars O(n*2^n).
│ -> Space Complexity = O(n*2^n) including output.
│ APPROACH COMPARISON TABLE:
│ Iterative bitmask = every subset as binary choice mask, O(n*2^n) time.
│ Recursive take/skip = decision tree, O(n*2^n) time and natural recursion visual.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

void generateSubseq(const string& s, int index, string current, vector<string>& ans) {
    if (index == (int)s.size()) {
        if (!current.empty()) ans.push_back(current);
        return;
    }
    generateSubseq(s, index + 1, current + s[index], ans); // TAKE
    generateSubseq(s, index + 1, current, ans);            // SKIP
}

int main() {
    vector<string> ans;
    generateSubseq("abc", 0, "", ans);
    sort(ans.begin(), ans.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    cout << "Non-empty subsequences of abc: ";
    for (const string& x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Non-empty subsequences of abc: a b c ab ac bc abc
*/

