/*
═══════════════════════════════════════════════
 STACK APPLICATIONS — bracket matching, valid parens, reverse words, NGE
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Your favourite text editor runs a "lint" feature: the moment you type an
 unbalanced closing brace, it underlines the line red. Behind the scenes
 the checker is a tiny stack walk over the source. The same idea brackets
 HTML tags, validates JSON, and powers the "undo" tape. A compiler also uses
 a stack when it needs to know the NEXT GREATEST context for an expression.
 These are four classic problems — parentheses matching, full bracket
 validation, reversing words with a stack, and next-greater-element — that
 ALL reduce to "push when you see an opening something, pop when you see its
 matching closer, act when the top reveals the answer."

 📖 THEORY: (pure English)
 - 1) PARENTHESES MATCHING (single type '()'):
   * Scan left→right keeping a counter (or stack) of depth.
   * On '(': push/depth++. On ')': if depth==0 → mismatch (too many closes);
     else depth--.
   * At end: valid iff depth==0 (no unclosed opens).
   * Why stack? Nesting — the CURRENTLY OPEN opener is the one a close must
     match; that is exactly LIFO.
 - 2) VALID PARENTHESES (multiple types '()[]{}'):
   * On an opening bracket push the CORRESPONDING closing char (simplifies
     comparison). On a closing bracket: top must equal it, else invalid.
   * Mismatch cases: closing with empty stack; closing whose expected char
     != top; leftover items when input ends.
   * Edge cases: "", "([)]" (nested mismatch), "())", "([" (unclosed).
 - 3) REVERSE STRING / WORDS:
   * Whole string: push chars, pop chars → reversed (O(n) space).
   * Word by word with reverse: push each word onto a stack, then pop words
     → words come back in reverse order (classic "reverse words").
 - 4) NEXT GREATER ELEMENT (NGE):
   * Brute force: for each i scan right → O(nn).
   * Stack (monotonic decreasing): scan right→left; pop while
     stack top ≤ current (those can never be 'next greater' for it);
     the remaining top is the NGE; push current.
     → each element pushed & popped once ⇒ O(n).
   * Stores candidate indices OR values; kept monotonic-decreasing.

  ASCII — bracket matching trace for "(()())":
   (  depth 0→1
   (  depth 1→2
   )  depth 2→1
   (  depth 1→2
   )  depth 2→1
   )  depth 1→0 → balanced ✔

  ASCII — multi-type "([{}])":
        push ')' ']' '}'
   "("   stack: )        ← store the expected closer
   "["   stack: ) ]
   "{"   stack: ) ] }
   "}"   top } == } pop → ) ]
   "]"   top ] == ] pop → )
   ")"   top ) == ) pop → empty → VALID ✔

  ASCII — NGE buckets, arr {4,5,2,25}:
   scanned right→left               NGE
       25  (push)                    -1
        2  (pop none→ top 25)        25
        5  (2<=5 pop; top 25)        25
        4  (5>4 keep)                5
   → {5, 25, 25, -1}

 🧠 LOGIC — STEP BY STEP:
 Step 1: For bracket problems, DECIDE what to push.
        WHY: pushing the expected closer (')' for '(') makes the pop check a
        direct equality — fewer branches than carrying the opener.
 Step 2: On every closer: if stack empty → invalid; if top != closer → invalid.
        WHY: empty means an opener never appeared; top!=closer means wrong
        nesting like the "([)]" trap; both must return false immediately.
 Step 3: At end of input the stack MUST be empty.
        WHY: leftover openers are unclosed brackets — silently invalid.
 Step 4: Reverse words: push whole words, pop them → order flips.
        WHY: the stack naturally reverses the sequence; per-word reversal
        happens while popping (each word backwards) or by a final flip.
 Step 5: NGE: keep the stack strictly decreasing, scanning RIGHT to LEFT.
        WHY: scanning right→left means every candidate to the right is
        already in the stack; popping ≤ current discards elements that can
        never be an NGE for current or anything further left (they are left
        of something bigger).
 Step 6: Prove each element pushed/popped at most once.
        WHY: that single fact makes total O(n) despite nested loops.

 VISUAL WALKTHROUGH — balance "()[]" + NGE {4,5,2,25} shown above; another:
   "([])"  valid ; "([)]" invalid — bottom walkthrough:
   ( push ')'
   [ push ']'  → stack: ) ]
   ) top ']' expected ']'? NO → invalid ✘ (']' got closed by ')' — nesting broken)

DRY RUN: (demo below, exact prints)
   balanced("()")     → true
   balanced("(())()") → true
   balanced(")(")     → false (close with depth 0)
   balanced("(")      → false (unclosed)
   valid("([])")      → true
   valid("([)]")      → false (mismatched nesting)
   valid("{[()]}")    → true
   valid("(")         → false (unclosed)
   valid("")          → true
   reverseWords("the sky is blue") → "blue is sky the"
   NGE {4,5,2,25} → 5 25 25 -1
 TIME COMPLEXITY CALCULATION:
 - Balanced/valid parens: single left→right pass, each bracket pushed once
   and popped once → O(n) time; O(n) worst-case stack (e.g. "((((((...").
 - Reverse whole string: push n chars + pop n chars → O(n) time O(n) space.
 - Reverse words: O(n) chars total across pushes/pops; O(n) space
   (or O(1) aux with modern two-pointer reverse but we demo the stack way).
 - NGE with stack: every element pushed once + popped once → O(n) total.
   Brute-force is O(nn) — comparison shows why stack wins for large n.
 - Space: each uses at most a full copy of input → O(n) auxiliary.
 SPACE COMPLEXITY CALCULATION:
 - Parens stack worst case = n openers → O(n).
 - Reversal stacks hold all n chars or the words → O(n).
 - NGE stack holds ≤ n indices → O(n); result array O(n).
   (constraint: input itself is O(n) in memory; we add only O(n) aux.)

 APPROACH COMPARISON (NGE especially):
 ┌────────────────────┬────────────────────┬────────────────────────────┐
 │ Problem            │ Brute force        │ Stack (monotonic)          │
 ├────────────────────┼────────────────────┼────────────────────────────┤
 │ Valid parens       │ counter works (1)  │ stack needed for multi-type│
 │ Reverse words      │ builtin split+rev  │ stack reverses for free    │
 │ NGE                │ for i scan right   │ right→left monotonic stack │
 │ NGE time           │ O(n·n)             │ O(n)                       │
 │ NGE space (extra)  │ O(1) aux           │ O(n) aux stack             │
 └────────────────────┴────────────────────┴────────────────────────────┘
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ---- bracket matching (single type) ----
bool balanced(const string& s) {
    int depth = 0;
    for (char c : s) {
        if (c == '(') depth++;
        else if (c == ')') {
            if (depth == 0) return false;   // close bina open ke
            depth--;
        }
    }
    return depth == 0;                      // open bacha to galat
}

// ---- valid parentheses (multi-type) returns bool ----
bool validParen(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') st.push(')');
        else if (c == '[') st.push(']');
        else if (c == '{') st.push('}');
        else {
            if (st.empty()) return false;   // closer bina open
            if (st.top() != c) return false;// galat nesting ([)]
            st.pop();
        }
    }
    return st.empty();                      // koi unclosed nahi
}

// ---- reverse words using a stack; "the sky is blue" -> "blue is sky the" ----
string reverseWords(const string& s) {
    stack<string> words;
    string cur;
    for (char c : s) {
        if (c == ' ') { if (!cur.empty()) { words.push(cur); cur.clear(); } }
        else cur += c;
    }
    if (!cur.empty()) words.push(cur);
    string out;
    while (!words.empty()) { out += words.top(); words.pop(); if (!words.empty()) out += " "; }
    return out;
}

// ---- next greater element with monotonic stack ----
void nextGreater(int arr[], int n) {
    stack<int> st;
    int* res = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();  // chhote discard
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++) cout << res[i] << (i + 1 < n ? " " : "\n");
    delete[] res;
}

int main() {
cout << "===== bracket matching (single type) =====" << endl;
    cout << "balanced(\"()\")    = " << (balanced("()") ? "true" : "false") << endl;      // true
    cout << "balanced(\"(())()\") = " << (balanced("(())()") ? "true" : "false") << endl;  // true
    cout << "balanced(\")(\")    = " << (balanced(")(") ? "true" : "false") << endl;      // false
    cout << "balanced(\"(\")      = " << (balanced("(") ? "true" : "false") << endl;      // false

    cout << "===== valid parentheses =====" << endl;
    cout << "valid(\"([])\")  = " << (validParen("([])") ? "true" : "false") << endl;    // true
    cout << "valid(\"([)]\")  = " << (validParen("([)]") ? "true" : "false") << endl;    // false
    cout << "valid(\"{[()]}\") = " << (validParen("{[()]}") ? "true" : "false") << endl;  // true
    cout << "valid(\"(\")      = " << (validParen("(") ? "true" : "false") << endl;       // false
    cout << "valid(\"\")       = " << (validParen("") ? "true" : "false") << endl;        // true

    cout << "===== reverse words =====" << endl;
    cout << reverseWords("the sky is blue") << endl;         // blue is sky the

    cout << "===== next greater element =====" << endl;
    int a[4] = {4, 5, 2, 25};
    nextGreater(a, 4);                                       // 5 25 25 -1
    return 0;
}
