/*
 * ══════════════════════════════════════════════════
 *  TASKS — 05_Infix_Postfix_Expressions
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
bool isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

/* TASK 1 — precedence of a char (EASY)
   printed index: 3 for '*', 1 for '+', 0 for 'a'. */
int task1_precedence(char c) { return prec(c); }

/* TASK 2 — validate a postfix string has enough operands (EASY)
   Every operator needs 2 operands; counts must never go negative and must
   end at 1. "12+3*" → true ; "12+" true ; "+12" false. */
bool task2_validPostfix(const string& s) {
    int ops = 0;
    for (char c : s) {
        if (isdigit(c)) ops++;
        else if (isOp(c)) {
            if (ops < 2) return false;   // 2 operand nahi mile
            ops--;                       // do operands → ek result
        }
    }
    return ops == 1;
}

/* TASK 3 — evaluate "+" only with two operands (MEDIUM)
   "3 5 + 2 +" → 10. Return gathered sum. */
int task3_evalAdd(const string& s) {
    stack<int> st;
    for (char c : s) {
        if (c == ' ') continue;
        if (isdigit(c)) st.push(c - '0');
        else if (c == '+') { int a = st.top(); st.pop(); int b = st.top(); st.pop(); st.push(a + b); }
    }
    return st.top();
}

/* TASK 4 — convert a*b+c to postfix by hand-driven stack (MEDIUM)
   a*b+c -> ab*c+ . Reuse the shunting algorithm via helper below. */
string task4_convert(const string& infix) {
    stack<char> st;
    string out;
    for (char c : infix) {
        if (isdigit(c) || isalpha(c)) out += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') { out += st.top(); st.pop(); }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' && prec(st.top()) >= prec(c)) {
                out += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { out += st.top(); st.pop(); }
    return out;
}

/* TASK 5 — full check: convert then evaluate "a=2 style" (HARD)
   Convert "(4+5)*2-3" to postfix, then evaluate. Expected 15. */
int task5_chain(const string& infix) {
    string post = task4_convert(infix);
    stack<int> st;
    for (char c : post) {
        if (isdigit(c)) st.push(c - '0');
        else if (isOp(c)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int r = (c == '+') ? a + b : (c == '-') ? a - b : (c == '*') ? a * b : a / b;
            st.push(r);
        }
    }
    return st.top();
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << task1_precedence('*') << " " << task1_precedence('+')
         << " " << task1_precedence('a') << endl;            // 2 1 0

    cout << "---- TASK 2 ----" << endl;
    cout << task2_validPostfix("12+3*") << " " << task2_validPostfix("+12") << endl; // 1 0

    cout << "---- TASK 3 ----" << endl;
    cout << "sum = " << task3_evalAdd("3 5 + 2 +") << endl;  // 10

    cout << "---- TASK 4 ----" << endl;
    cout << "a*b+c -> " << task4_convert("a*b+c") << endl;   // ab*c+

    cout << "---- TASK 5 ----" << endl;
    cout << "(4+5)*2-3 = " << task5_chain("(4+5)*2-3") << endl; // 15
    return 0;
}