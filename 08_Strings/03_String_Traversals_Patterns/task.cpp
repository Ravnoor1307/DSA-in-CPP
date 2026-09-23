/*
═══════════════════════════════════════════════
 TASK SET — STRING TRAVERSALS & PATTERNS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A text-analysis lab needs to count the characters and
    words of sentences, reverse characters, and reverse word order. These are the
    exact operations behind word counters, plagiarism tools, and text editors.

 🧠 HOW TO SOLVE: Scan the characters once, tracking vowels, consonants and
    spaces. For reversing, either copy into a second string or swap using two
    pointers (left++ / right--). To reverse word order, push words onto a stack
    (LIFO pops them in reverse) or use the reverse-all + reverse-each-word trick.
    Every approach visits each character at most once.

 MODES/TOPICS COVERED:
  1. Count vowels and consonants
  2. Count spaces and implement a robust word counter
  3. Reverse string using an extra string
  4. Reverse string using two pointers
  5. Reverse words using a stack
  6. Reverse words using reverse whole + reverse each word trick
  7. Draw a before->after diagram in comments for each approach
  8. Write the complexity table

 HINTS:
 - Check vowels after converting to lowercase.
 - Two pointers: left++, right--.
 - Stack pops words in reverse order.

 STARTER CODE:
 string s="Hello World";

 SOLUTION: A compact compiled solution is below.

 ASCII VISUAL / POINTER STATE:
 Reverse string:
 [h][e][l][l][o]
  L           R -> swap
 result olleh

 Reverse words: Hello World -> World Hello

 DRY RUN:
 For "Hello DSA": vowels=3, consonants=5.
 For "  hello   world  ": robust words=2.

 FLOW OF EXECUTION:
 input string -> scan/split/pointer movement -> build/modify answer -> print result

 TIME COMPLEXITY CALCULATION:
 - All scans visit n characters.
 - Reverse swaps floor(n/2) pairs.
 - Stack reverse reads/builds total n chars.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Two-pointer reverse O(1) extra.
 - Extra reverse and stack word reverse O(n) extra.
 -> Space depends on approach.
═══════════════════════════════════════════════
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

