/*
═══════════════════════════════════════════════
 REVERSE WORDS IN A STRING — APPROACH 1 (STACK)
 ⏱️ TIME COMPLEXITY: O(n) — single linear pass over n characters, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A news ticker needs words displayed in reverse order: "Hello World" -> "World Hello".
 Because a stack is LIFO (Last In, First Out), the last word pushed pops out first, so
 words come back in exactly the reverse order — perfect for reversing headlines.

 📖 THEORY:
 - A stack follows LIFO: the last item inserted is the first item removed.
 - Split the sentence into words; reading with a stream automatically skips extra spaces.
 - Push every word onto the stack; the last word of the sentence lands on top.
 - Pop repeatedly; the top word comes out first, so the first word to pop is the last
   word of the original sentence.
 - Build the answer by concatenating popped words, separating them with a single space.
 - The stack stores all words, so it needs O(n) extra space.

 ASCII VISUAL / STACK STATE:
 Sentence: "Hello World from DSA"
 push Hello
 push World
 push from
 push DSA

 Stack top -> DSA
              from
              World
              Hello

 Pop order: DSA from World Hello

 🧠 LOGIC — STEP BY STEP:
 Step 1: Tokenize the sentence into words using a string stream.
    WHY: word-by-word extraction separates the words and normalizes all extra spaces.
 Step 2: Push every word onto the stack.
    WHY: LIFO guarantees the last word is popped first.
 Step 3: Pop words one by one and append them with a space in between.
    WHY: each pop returns the top word, which is the next word in reverse order.

 DRY RUN:
 Input: Hello World
 push Hello, push World
 pop World -> ans="World"
 pop Hello -> ans="World Hello"

 FLOW OF EXECUTION:
 input string -> tokenize into words -> push all words on stack -> pop and build answer -> print result

 TIME COMPLEXITY CALCULATION:
 - Splitting reads n characters.
 - Pushing all words processes total n characters.
 - Popping/building the answer processes total n characters.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - The stack stores all words, total n characters.
 - The answer stores n characters.
 -> Extra Space Complexity = O(n).
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

