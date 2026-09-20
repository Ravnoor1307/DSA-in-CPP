/*
═══════════════════════════════════════════════
 TASK SET — STD::STACK
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
Your browser keeps a back-button history — the most recent page
visited is the one popped first (LIFO). Compilers also use a stack
to match brackets like ( [ { and to evaluate expressions. A text
editor uses a stack of actions for undo — last edit undone first.

🧠 HOW TO SOLVE:
Stack only exposes the TOP, so every problem becomes: decide what
you push, when you pop, and what the top() tells you at that
moment. For brackets: push openers, and on a closer compare with
top(). For reverse/next-greater/min-stack: push while scanning and
let the top() answer stay current.

 6-6 tasks EASY → HARD:
──────────────────────────────────────────────
 TASK 1 — Reverse a string
 Statement: Given string "hello", use a stack to reverse it
            → "olleh".
 💡 HINT: Push every char, then pop and append to result.
 ✏️ STARTER CODE:
 // string s = "hello", rev = "";
 // stack<char> st;
 // for (char c : s) st.push(c);   // saare chars andar daalo
 // while (!st.empty()) { rev += st.top(); st.pop(); } // ulta nikal lo
──────────────────────────────────────────────
 TASK 2 — Balanced parentheses
 Statement: Check if "{[()]}" is balanced (true) and "{[(])}"
            is NOT (false).
 💡 HINT: Push openers. On a closer, top() must be its matching
          opener, else false. Stack must be empty at the end.
 ✏️ STARTER CODE:
 // bool isBalanced(string s) {
 //   stack<char> st;
 //   for (char c : s) {
 //     if (c=='('||c=='{'||c=='[') { st.push(c); continue; }
 //     if (st.empty()) return false;      // bina opener ke closer
 //     char t = st.top();
 //     if (!matching(t, c)) return false; // wrong partner
 //     st.pop();
 //   }
 //   return st.empty();
 // }
──────────────────────────────────────────────
 TASK 3 — Next Greater Element
 Statement: For {4, 5, 2, 25}, the next greater of each is
            {5, 25, 25, -1}. Print each element's NGE.
 💡 HINT: Process right→left. Keep a stack of "candidate greater"
          values; it is always decreasing from top.
 ✏️ STARTER CODE:
 // vector<int> a = {4, 5, 2, 25};
 // stack<int> st;                 // monotonic stack
 // vector<int> ans(a.size(), -1);
 // for (int i = a.size()-1; i >= 0; --i) {
 //   while (!st.empty() && st.top() <= a[i]) st.pop(); // chhote hat jao
 //   if (!st.empty()) ans[i] = st.top();
 //   st.push(a[i]);
 // }
──────────────────────────────────────────────
 TASK 4 — Postfix evaluation (intro)
 Statement: Evaluate "23*5+" → (2×3)+5 = 11. Operators: + - * /.
 💡 HINT: Push operands. On an operator, pop TWO values: first is
          right operand, second is left operand.
 ✏️ STARTER CODE:
 // stack<int> st;
 // for (char c : expr) {
 //   if (isdigit(c)) st.push(c - '0');
 //   else {
 //     int r = st.top(); st.pop();  // right operand pehle
 //     int l = st.top(); st.pop();  // left operand doosra
 //     st.push(apply(l, c, r));
 //   }
 // }
 // // answer = st.top()
──────────────────────────────────────────────
 TASK 5 — Min-stack intro
 Statement: Build a stack that supports push, pop, top AND
            getMin() — all O(1). Push {5, 2, 7, 1} → min = 1.
 💡 HINT: Keep a SECOND stack that always holds the current
          minimum at its top.
 ✏️ STARTER CODE:
 // stack<int> data, mins;
 // void push(int x) { data.push(x);
 //   if (mins.empty() || x <= mins.top()) mins.push(x); }
 // int getMin() { return mins.top(); }
 // void pop() {
 //   if (data.top() == mins.top()) mins.pop();  // jo min tha wahi gaya
 //   data.pop();
 // }
──────────────────────────────────────────────
 TASK 6 — Palindrome using stack
 Statement: Check if "madam" is a palindrome (true) and "hello"
            is not, using a stack.
 💡 HINT: Push first half, then compare second half char by char
          with stack pops. Odd length: middle char is skipped.
 ✏️ STARTER CODE:
 // string s = "madam";
 // stack<char> st;
 // int mid = s.size() / 2;
 // for (int i = 0; i < mid; ++i) st.push(s[i]); // pehla aadha
 // int start = mid + (s.size() % 2);            // odd ho to middle skip
 // for (int i = start; i < s.size(); ++i) {
 //   if (s[i] != st.top()) return false;        // dono taraf sama hona chahiye
 //   st.pop();
 // }
 // return true;
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// ---------- TASK 1: reverse a string ----------
void task1() {
    cout << "\n=== TASK 1: Reverse a string ===\n";
    string s = "hello", rev = "";
    stack<char> st;

    for (char c : s) st.push(c);          // saare characters stack me
    while (!st.empty()) { rev += st.top(); st.pop(); } // ulta nikalo

    cout << "Original: " << s << " | Reversed: " << rev << endl;
}

// ---------- TASK 2: balanced parentheses ----------
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') { st.push(c); continue; }
        if (st.empty()) return false;              // closer bina opener ke
        if (!isMatching(st.top(), c)) return false; // galat partner
        st.pop();
    }
    return st.empty(); // end me stack khali hona chahiye
}

void task2() {
    cout << "\n=== TASK 2: Balanced parentheses ===\n";
    cout << "\"{[()]}\" -> " << (isBalanced("{[()]}") ? "balanced" : "NOT balanced") << endl;
    cout << "\"{[(])}\" -> " << (isBalanced("{[(])}") ? "balanced" : "NOT balanced") << endl;
    cout << "\"(\"     -> " << (isBalanced("(") ? "balanced" : "NOT balanced") << endl;
}

// ---------- TASK 3: next greater element ----------
vector<int> nextGreater(const vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st; // monotonic stack — top se hamesha chota sa value niklega

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= a[i]) st.pop(); // chhote greater drop
        if (!st.empty()) ans[i] = st.top();               // stack ka top = next greater
        st.push(a[i]);                                    // current ko candidate banao
    }
    return ans;
}

void task3() {
    cout << "\n=== TASK 3: Next Greater Element ===\n";
    vector<int> a = {4, 5, 2, 25};
    vector<int> ans = nextGreater(a);
    for (int i = 0; i < (int)a.size(); ++i)
        cout << "NGE of " << a[i] << " -> " << ans[i] << endl;
}

// ---------- TASK 4: postfix evaluation ----------
int applyOp(int l, char op, int r) {
    switch (op) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r;
    }
    return 0;
}

int evalPostfix(const string& expr) {
    stack<int> st;
    for (char c : expr) {
        if (c >= '0' && c <= '9') {
            st.push(c - '0');                 // operand ko stack me
        } else {
            int r = st.top(); st.pop();       // right operand pehle pop
            int l = st.top(); st.pop();       // left operand doosra pop
            st.push(applyOp(l, c, r));        // result wapas daal do
        }
    }
    return st.top();
}

void task4() {
    cout << "\n=== TASK 4: Postfix evaluation ===\n";
    string expr = "23*5+";
    cout << expr << " = " << evalPostfix(expr) << "  (=(2*3)+5)\n";
    cout << "62/3- = " << evalPostfix("62/3-") << "  (=(6/2)-3)\n";
}

// ---------- TASK 5: min-stack ----------
class MinStack {
private:
    stack<int> data; // original values
    stack<int> mins; // har state ka current minimum

public:
    void push(int x) {
        data.push(x);
        if (mins.empty() || x <= mins.top()) mins.push(x); // naya min aaya?
    }

    void pop() {
        if (data.empty()) return;
        if (data.top() == mins.top()) mins.pop(); // jo element min tha wahi nikal raha hai
        data.pop();
    }

    int top() { return data.top(); }
    int getMin() { return mins.top(); }
};

void task5() {
    cout << "\n=== TASK 5: Min-Stack (O(1) getMin) ===\n";
    MinStack ms;
    ms.push(5); ms.push(2); ms.push(7); ms.push(1);
    cout << "After push 5,2,7,1 -> top = " << ms.top()
         << ", min = " << ms.getMin() << endl;
    ms.pop();
    cout << "After pop -> top = " << ms.top()
         << ", min = " << ms.getMin() << " (1 chala gaya, ab 2)\n";
    ms.pop();
    cout << "After pop -> top = " << ms.top()
         << ", min = " << ms.getMin() << endl;
}

// ---------- TASK 6: palindrome using stack ----------
bool isPalindromeStack(const string& s) {
    int n = s.size();
    stack<char> st;
    int mid = n / 2;

    for (int i = 0; i < mid; ++i) st.push(s[i]); // pehla aadha push

    int start = mid + (n % 2); // n odd hai to beech ka char ignore
    for (int i = start; i < n; ++i) {
        if (s[i] != st.top()) return false; // aage vs peeche mismatch
        st.pop();
    }
    return true;
}

void task6() {
    cout << "\n=== TASK 6: Palindrome using stack ===\n";
    cout << "\"madam\" -> " << (isPalindromeStack("madam") ? "palindrome" : "NOT") << endl;
    cout << "\"hello\" -> " << (isPalindromeStack("hello") ? "palindrome" : "NOT") << endl;
    cout << "\"racecar\" -> " << (isPalindromeStack("racecar") ? "palindrome" : "NOT") << endl;
}

int main() {
    cout << "========== STD::STACK TASK SET ==========\n";
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    cout << "\n========== ALL TASKS COMPLETE ==========\n";
    return 0;
}