/*
═══════════════════════════════════════════════
 INFIX → POSTFIX — why, algorithm, evaluation
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A calculator engine receives "1 + 2 * 3" from the screen. Humans know
 "multiplication before addition" from school. Machines hate that: a
 left-to-right computer would happily do 1+2=3, then 3*3=9 — WRONG. Compilers
 and calcpads solve it by rewriting the expression WITHOUT parentheses,
 where the operator is written AFTER its operands: "1 2 3 * +". Now the
 machine reads left→right and applies every operator to the operands it just
 saw — no precedence rules, no parentheses, no backtracking. That rewritten
 form is POSTFIX (a.k.a. Reverse Polish Notation). Calculators like classic
 HP RPN models and stack machines (JVM bytecode!) evaluate postfix directly.

 📖 THEORY: (pure English)
 - INFIX: operator sits BETWEEN operands, needs precedence + associativity +
   parentheses to disambiguate → hard for a machine to parse in one pass.
 - POSTFIX: operator comes AFTER both operands. Eliminates parentheses &
   precedence: the order of operators in postfix IS the order of evaluation.
 - CONVERSION (Shunting-yard style, using an OPERATOR stack + output):
     Scan infix left→right:
       * operand → append to output.
       * '(' → push to operator stack.
       * ')' → pop operators to output until '(' (discard the paren).
       * operator → pop from stack to output WHILE the stack top has
         HIGHER-OR-EQUAL precedence (and for left-associative ops, equal
         counts as higher → pop), THEN push this operator.
     At end → pop the whole operator stack to output.
   Precedence (low→high): + − (1), * / (2). '^' (3) if included.
   WHY '(' is pushed without popping: it acts as a hard boundary; operators
   above it belong to the inner (sub)expression — they must come out first
   when ')' arrives.
 - EVALUATION with an OPERAND stack:
     Token by token:
       * operand → push.
       * operator → pop two operands (b, then a — order matters for − and /),
         compute a op b, push result.
     Final: the single value left on the stack is the answer.
   WHY pop b first then a: postfix "a b −" means a−b; since the stack top is
   b, you must grab the SECOND one as a, or you'd compute b−a.
 - WHY INFIX→POSTFIX: lets the evaluator ignore precedence entirely; the
   parentheses are already "compiled away" into the order.

  ASCII — conversion "1 + 2 * 3":
   char  stack(top→)     output
   1      (empty)         1
   +      +               1
   2      +               1 2
   *      + *             1 2
   3      + *             1 2 3
   end    pop all         1 2 3 * +
   → "1 2 3 * +"

  ASCII — conversion "1 + 2 * 3" why * pops on + NOT seen yet:
   after "1 2 *" new '+' arrives while stack top is '*'; '*' has higher
   precedence → pop '*' to output "1 2 3 *", then push '+'.
   Final output "1 2 3 * +" — the '*' printed BEFORE '+' → multiplies first.

  ASCII — evaluation "1 2 3 * +" (operand stack):
   1 → [1]
   2 → [1,2]
   3 → [1,2,3]
   * → pop b=3, a=2 → 6 → [1,6]
   + → pop b=6, a=1 → 7 → [7]  → ANSWER = 7
   (order note: for '-' we MUST do a-b not b-a)

 🧠 LOGIC — STEP BY STEP (conversion):
 Step 1: operand → straight to output.
        WHY: operands never wait on precedence; they keep their order.
 Step 2: '(' → push to operator stack.
        WHY: it marks the start of a sub-expression; everything above it on
        the stack must flush to output before the ')' releases it.
 Step 3: ')' → pop & output until '(' is found.
        WHY: the innermost parentheses must resolve first — that is LIFO on
        the operator stack doing its job.
 Step 4: operator → pop stack while top-prec >= current-prec, then push.
        WHY: same-precedence left-associative ops must evaluate left→right,
        so an equal-precedence operator sitting on top must be emitted before
        the newcomer ('a-b-c' must stay ((a-b)-c)).
 Step 5: end → dump the stack.
        WHY: remaining operators apply at the top level; the last pushed
        outer operator is processed last in postfix — consistent with tree
        post-order traversal.

 🧠 LOGIC — STEP BY STEP (evaluation):
 Step 1: operand → operand stack.
 Step 2: operator → pop b then a.
        WHY: top is the RIGHT operand because it was pushed last; a-b needs
        the left (older) one subtracted by the newer.
 Step 3: push result.
        WHY: result acts as an operand for whatever operator comes next —
        the stack stores intermediate values of the expression tree.
 Step 4: end → the only remaining value = answer.
        WHY: a well-formed postfix expression evaluates to exactly one value.

 VISUAL WALKTHROUGH: convert "a+b*c" done above; evaluate same pattern with
 numbers; SECOND example: convert "a*b+c" vs "a+b*c" to see precedence flip:
   "a*b+c" → a b * c +   ('*' already on top, '+' lower → pop, push +)
   "a+b*c" → a b c * +   ('+' stays under '*', '*' pops first on end)

 DRY RUN: (demo below, exact prints)
   POSTFIX conversion:
     infix "1+2*3"    → "1 2 3 * +"
     infix "(1+2)*3"  → "1 2 + 3 *"
     infix "1+2*3-4"  → "1 2 3 * + 4 -"
   EVALUATION:
     postfix "1 2 3 * +"   → result 7
     postfix "1 2 + 3 *"   → result 9   (the parenthesized version)
 TIME COMPLEXITY CALCULATION:
 - Conversion: each char handled once; each operator pushed once and popped
   once. O(n) time, O(n) worst-case operator stack (nested expressions).
 - Evaluation: each token once; each operator pops+pushing const work.
   O(n) time, O(n) operand stack worst case.
 - Both are single linear passes — the stack work is amortized constant
   per token because an element can go in/out only once.
 SPACE COMPLEXITY CALCULATION:
 - Conversion: output string O(n) + operator stack ≤ n → O(n) total.
 - Evaluation: operand stack holds ≤ n intermediate values → O(n).
 - No extra auxiliary arrays beyond those two linear structures.

 APPROACH COMPARISON:
 ┌────────────────────┬──────────────────┬──────────────────────────────┐
 │ Aspect             │ Infix directly   │ Postfix (via stack)          │
 ├────────────────────┼──────────────────┼──────────────────────────────┤
 │ Precedence handling│ recursive desc / │ compiled into order          │
 │ Parentheses        │ still in grammar │ eliminated entirely          │
 │ One-pass machine   │ difficult        │ trivial left→right           │
 │ Used by            │ humans, parsers  │ stack machines, JVM, RPN     │
 └────────────────────┴──────────────────┴──────────────────────────────┘
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// operator precedence: + - low, * / high
int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// infix (single-digit operands, + - * / and parens) -> postfix string
string toPostfix(const string& infix) {
    stack<char> st;
    string out;
    for (char c : infix) {
        if (c == ' ') continue;                       // whitespace skip
        if (isdigit(c)) out += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') { // sab '(' tak bahar
                out += st.top(); st.pop();
            }
            if (!st.empty()) st.pop();                // '(' hatao
        } else {                                       // operator
            while (!st.empty() && st.top() != '(' && prec(st.top()) >= prec(c)) {
                out += st.top(); st.pop();             // upar wala precedence chhota nahi
            }
            st.push(c);
        }
    }
    while (!st.empty()) { out += st.top(); st.pop(); } // stack khaali karo
    return out;
}

// postfix (single digits) -> int result
int evalPostfix(const string& post) {
    stack<int> st;
    for (char c : post) {
        if (c == ' ') continue;
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();               // pehle right operand
            int a = st.top(); st.pop();               // phir left
            int r = (c == '+') ? a + b :
                    (c == '-') ? a - b :
                    (c == '*') ? a * b : a / b;
            st.push(r);
        }
    }
    return st.top();
}

int main() {
    cout << "===== POSTFIX CONVERSION =====" << endl;
    string s1 = "1+2*3";
    string s2 = "(1+2)*3";
    string s3 = "1+2*3-4";
    cout << "infix " << s1 << " -> postfix " << toPostfix(s1) << endl;      // 123*+
    cout << "infix " << s2 << " -> postfix " << toPostfix(s2) << endl;      // 12+3*
    cout << "infix " << s3 << " -> postfix " << toPostfix(s3) << endl;      // 123*+4-

    cout << "===== POSTFIX EVALUATION =====" << endl;
    string p1 = "123*+";                       // 1+2*3 = 7
    string p2 = "12+3*";                       // (1+2)*3 = 9
    cout << "eval " << p1 << " = " << evalPostfix(p1) << endl;              // 7
    cout << "eval " << p2 << " = " << evalPostfix(p2) << endl;              // 9
    return 0;
}
