/*
 * ══════════════════════════════════════════════════
 *  TASKS — 04_Stack_Applications
 *  6 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* TASK 1 — is s fully balanced single-type '()' (EASY)
   Return depth-based verdict. */
bool task1_balanced(const string& s) {
    int d = 0;
    for (char c : s) {
        if (c == '(') d++;
        else if (c == ')') {
            if (d == 0) return false;
            d--;
        }
    }
    return d == 0;
}

/* TASK 2 — count matching pairs (EASY)
   In "(()())" there are 3 pairs. Return pair count (assuming balanced input). */
int task2_countPairs(const string& s) {
    int d = 0, pairs = 0;
    for (char c : s) {
        if (c == '(') d++;
        else if (c == ')') { if (d > 0) { d--; pairs++; } }
    }
    return pairs;
}

/* TASK 3 — valid multiple brackets with greedy check (MEDIUM)
   Reuse valid-balance on mixed brackets but WITHOUT extra cases: just
   stack equality. */
bool task3_validMix(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') st.push(')');
        else if (c == '[') st.push(']');
        else if (c == '{') st.push('}');
        else {
            if (st.empty() || st.top() != c) return false;
            st.pop();
        }
    }
    return st.empty();
}

/* TASK 4 — reverse a string with a char stack (MEDIUM)
   "hello" → "olleh". */
string task4_reverseString(const string& s) {
    stack<char> st;
    for (char c : s) st.push(c);
    string out;
    while (!st.empty()) { out += st.top(); st.pop(); }
    return out;
}

/* TASK 5 — NGE using INDICES into array (MEDIUM-HARD)
   Print NGE by index map: arr {13,7,6,12} → 13→-1? no: [13,7,6,12]
   NGE = 7→12, 6→12, 12→-1, 13→-1 → in original order: -1 12 12 -1.
   Use stack of indices scanning right→left. */
void task5_ngeIndices(int a[], int n) {
    int* res = new int[n];
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();  // chhote bolaao
        res[i] = st.empty() ? -1 : a[st.top()];
        st.push(i);
    }
    for (int i = 0; i < n; i++) cout << res[i] << (i + 1 < n ? " " : "\n");
    delete[] res;
}

/* TASK 6 — min bracket REMOVALS to fix (HARD)
   Count minimum removals to balance a string of '(' ')'. Unmatched closes
   count immediately; leftover '(' count at the end.
   ")())((" → 4: closes at i0@i3 (2) + openers left after pops (2).
   Complexity: single pass O(n). */
int task6_minRemovals(const string& s) {
    stack<char> st;
    int removals = 0;
    for (char c : s) {
        if (c == '(') st.push(c);
        else {                              // ')
            if (st.empty()) removals++;     // unmatched closer → remove it
            else st.pop();
        }
    }
    return removals + (int)st.size();       // leftover openers too
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << task1_balanced("(())()") << " " << task1_balanced("(()") << endl;  // 1 0

    cout << "---- TASK 2 ----" << endl;
    cout << "pairs = " << task2_countPairs("(()())") << endl;      // 3

    cout << "---- TASK 3 ----" << endl;
    cout << task3_validMix("({[]})") << " " << task3_validMix("([)]") << endl;  // 1 0

    cout << "---- TASK 4 ----" << endl;
    cout << task4_reverseString("hello") << endl;                  // olleh

    cout << "---- TASK 5 ----" << endl;
    int a5[4] = {13, 7, 6, 12};
    task5_ngeIndices(a5, 4);                                       // -1 12 12 -1

    cout << "---- TASK 6 ----" << endl;
    cout << "removals = " << task6_minRemovals(")())((") << endl;  // 4
    return 0;
}