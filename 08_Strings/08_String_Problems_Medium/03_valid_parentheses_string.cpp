/*
═══════════════════════════════════════════════
 VALID PARENTHESES STRING
 ⏱️ TIME COMPLEXITY: O(n) — one loop over n chars with constant push/pop/top, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a factory, every opening gate must have a matching closing gate. Parentheses
 validation uses a stack: the most recently opened bracket must close first.

 📖 THEORY:
 - Push opening brackets `(`, `{`, `[` onto the stack.
 - On a closing bracket, the stack top must be the matching opening.
 - A mismatch or an empty stack means invalid.
 - If the stack is empty at the end, the string is valid.
 - This is a stack application in strings.

 ASCII VISUAL / WINDOW STATE:
 s="({[]})"
 read ( push: [(]
 read { push: [(,{]
 read [ push: [(,{,[]
 read ] matches [ pop
 read } matches { pop
 read ) matches ( pop
 stack empty -> valid

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop over each character.
    WHY: each bracket must be processed in order.
 Step 2: If it is an opening bracket, push it.
    WHY: it must be closed later.
 Step 3: Else check the stack top matches this closing bracket.
    WHY: LIFO means the latest opening is closed first.
 Step 4: If the stack is empty or mismatched, return false.
    WHY: an unmatched close is invalid.
 Step 5: Otherwise pop and continue; at the end return stack.empty().
    WHY: all openings must be closed for validity.

 DRY RUN:
 ({[]}):
 push (, push {, push [
 ] matches [, pop
 } matches {, pop
 ) matches (, pop
 valid

 FLOW OF EXECUTION:
 input string -> push openings / match closings via stack -> check empty at end -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop scans n characters once.
 - Each char push/pop/top constant time.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Worst case all opening brackets stored in stack.
 -> Extra Space Complexity = O(n).
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

bool matches(char open, char close) {
    return (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
}

bool isValidParentheses(const string& s) {
    stack<char> st;
    for (char ch : s) {
        if (ch=='(' || ch=='{' || ch=='[') st.push(ch);
        else {
            if (st.empty() || !matches(st.top(), ch)) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    cout << boolalpha;
    cout << "({[]}) valid? " << isValidParentheses("({[]})") << "\n";
    cout << "([)] valid? " << isValidParentheses("([)]") << "\n";
    return 0;
}

/*
OUTPUT:
({[]}) valid? true
([)] valid? false
*/

