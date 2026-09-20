/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_reverse_words_approach1_stack.cpp
│
│ REAL-WORLD SCENARIO:
│ News headline ke words ko reverse order me display karna hai: "Hello World" -> "World Hello". Stack LIFO nature se last word first nikalta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Sentence ko words me split karo.
│ 2. Har word stack me push karo.
│ 3. Stack se pop karte jao; last word first aayega.
│ 4. Spaces normalize ho jaate hain.
│ 5. Extra stack words store karta hai.
│
│ ASCII VISUAL / POINTER STATE:
│ Sentence: "Hello World from DSA"
│ push Hello
│ push World
│ push from
│ push DSA
│
│ Stack top -> DSA
│              from
│              World
│              Hello
│
│ Pop order: DSA from World Hello
│
│ DRY RUN:
│ Input: Hello World
│ push Hello, push World
│ pop World -> ans="World"
│ pop Hello -> ans="World Hello"
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Splitting reads n characters.
│ - Pushing all words total n chars.
│ - Popping/building answer total n chars.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack stores all words total n characters.
│ - Answer stores n characters.
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

string reverseWordsStack(const string& sentence) {
    stringstream ss(sentence);
    string word;
    stack<string> st;
    while (ss >> word) st.push(word);

    string ans;
    while (!st.empty()) {
        if (!ans.empty()) ans += " ";
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string s = "Hello World";
    cout << "Reverse words using stack = " << reverseWordsStack(s) << "\n";
    return 0;
}

/*
OUTPUT:
Reverse words using stack = World Hello
*/

