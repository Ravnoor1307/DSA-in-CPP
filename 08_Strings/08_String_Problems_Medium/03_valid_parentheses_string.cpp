/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_valid_parentheses_string.cpp
│
│ REAL-WORLD SCENARIO:
│ Factory me har opening gate ka matching closing gate hona chahiye. Parentheses validation stack se hota hai: latest opened bracket pehle close hoga.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Opening brackets `(`, `{`, `[` stack me push karo.
│ 2. Closing bracket aaye to stack top matching opening hona chahiye.
│ 3. Mismatch or empty stack -> invalid.
│ 4. End me stack empty ho to valid.
│ 5. Ye stack preview/application hai strings me.
│
│ ASCII VISUAL / WINDOW STATE:
│ s="({[]})"
│ read ( push: [(]
│ read { push: [(,{]
│ read [ push: [(,{,[]
│ read ] matches [ pop
│ read } matches { pop
│ read ) matches ( pop
│ stack empty -> valid
│
│ DRY RUN:
│ ({[]}):
│ push (, push {, push [
│ ] matches [, pop
│ } matches {, pop
│ ) matches (, pop
│ valid
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n characters once.
│ - Each char push/pop/top constant time.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Worst case all opening brackets stored in stack.
│ -> Extra Space Complexity = O(n).
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

