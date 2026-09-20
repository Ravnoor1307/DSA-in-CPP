/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_String_Traversals_Patterns task.cpp
│
│ REAL-WORLD SCENARIO:
│ Text-analysis lab me sentence ke characters count, words count, reverse characters, and reverse words karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Vowels and consonants count karo.
│ 2. Spaces count karo and robust word count implement karo.
│ 3. Reverse string using extra string.
│ 4. Reverse string using two pointers.
│ 5. Reverse words using stack.
│ 6. Reverse words using reverse whole + reverse each word trick.
│ 7. Har approach ka before->after diagram comments me banao.
│ 8. Complexity table likho.
│
│ HINTS:
│ - Vowel check lowercase ke baad karo.
│ - Two pointers: left++, right--.
│ - Stack pops words in reverse order.
│
│ STARTER CODE:
│ string s="Hello World";
│
│ SOLUTION: Neeche compact compiled solution hai.
│
│ ASCII VISUAL / POINTER STATE:
│ Reverse string:
│ [h][e][l][l][o]
│  L           R -> swap
│ result olleh
│
│ Reverse words: Hello World -> World Hello
│
│ DRY RUN:
│ For "Hello DSA": vowels=3, consonants=5.
│ For "  hello   world  ": robust words=2.
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - All scans visit n characters.
│ - Reverse swaps floor(n/2) pairs.
│ - Stack reverse reads/builds total n chars.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Two-pointer reverse O(1) extra.
│ - Extra reverse and stack word reverse O(n) extra.
│ -> Space depends on approach.
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

int main() {
    string s = "Hello World";
    string rev = s;
    reverse(rev.begin(), rev.end());
    cout << "Full reverse = " << rev << "\n";

    stringstream ss(s);
    stack<string> st;
    string word;
    while (ss >> word) st.push(word);
    cout << "Reverse words = ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " ";
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Full reverse = dlroW olleH
Reverse words = World Hello
*/

