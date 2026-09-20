/*
═══════════════════════════════════════════════
 TASK SET — STACK (LIFO)
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: You are building the "Undo" button for a text
   editor. Every keystroke gets pushed onto a stack. When the user hits
   Ctrl+Z, the LAST action must be undone first — a perfect LIFO case.
   These tasks build the exact logic behind undo, brackets checkers,
   and expression evaluation.

 🧠 HOW TO SOLVE: Use an array + top index. PUSH = top++ then assign.
   POP = read then top--. Always guard against isEmpty before pop/peek
   and isFull before push. For string reversal just pop everything —
   it comes out reversed!
 
 MODES/TOPICS COVERED:
  1. Implement isEmpty() and isFull() checks
  2. Implement peek() (top element without removing)
  3. Reverse a string using a stack
  4. Check balanced parentheses using a stack
  5. HARD: Two stacks sharing one array
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
// NOTE: Each task below is solved fully. Compile the whole file.
// Hinglish comments = code samjhao.

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Stack {
    int arr[MAX];
    int top;

    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};

bool isBalanced(const char expr[]) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char topChar = (char)s.pop();
            if (ch == ')' && topChar != '(') return false;
            if (ch == '}' && topChar != '{') return false;
            if (ch == ']' && topChar != '[') return false;
        }
    }
    return s.isEmpty();
}

struct TwoStacks {
    int arr[MAX];
    int top1;
    int top2;

    TwoStacks() {
        top1 = -1;
        top2 = MAX;
    }

    void push1(int v) {
        if (top1 + 1 >= top2) { cout << "Stack1 overflow!" << endl; return; }
        arr[++top1] = v;
    }

    void push2(int v) {
        if (top2 - 1 <= top1) { cout << "Stack2 overflow!" << endl; return; }
        arr[--top2] = v;
    }

    int pop1() {
        if (top1 == -1) { cout << "S1 empty!" << endl; return -1; }
        return arr[top1--];
    }

    int pop2() {
        if (top2 == MAX) { cout << "S2 empty!" << endl; return -1; }
        return arr[top2++];
    }
};

int main() {
    cout << "==========================================" << endl;
    cout << " TASK SET — STACK (LIFO)" << endl;
    cout << "==========================================" << endl;

    // ---- TASK 1: isEmpty / isFull ----
    cout << "\n--- TASK 1: isEmpty / isFull ---" << endl;
    Stack s1;
    cout << "Nayi stack empty? " << (s1.isEmpty() ? "YES" : "NO") << endl;
    s1.push(5);
    s1.push(6);
    cout << "2 push ke baad empty? " << (s1.isEmpty() ? "YES" : "NO") << endl;
    cout << "Full? " << (s1.isFull() ? "YES" : "NO") << " (capacity " << MAX << ")" << endl;

    // ---- TASK 2: peek ----
    cout << "\n--- TASK 2: peek top ---" << endl;
    Stack s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    cout << "Peek = " << s2.peek() << " (stack wahi rahega)" << endl;
    cout << "Pop = " << s2.pop() << endl;
    cout << "Pop = " << s2.pop() << endl;
    cout << "Pop = " << s2.pop() << endl;
    cout << "Empty ke baad peek = " << s2.peek() << endl;

    // ---- TASK 3: reverse a string ----
    cout << "\n--- TASK 3: Reverse string using stack ---" << endl;
    char word[] = "DSA";
    Stack s3;
    cout << "Original: " << word << endl;
    for (int i = 0; word[i] != '\0'; i++) {
        s3.push(word[i]);
    }
    cout << "Reversed: ";
    while (!s3.isEmpty()) {
        cout << (char)s3.pop();
    }
    cout << endl;
    cout << "Reason: last character sabse pehle pop hua (LIFO)." << endl;

    // ---- TASK 4: balanced parentheses ----
    cout << "\n--- TASK 4: Balanced parentheses ---" << endl;
    const char* tests[] = {"(a+b)*(c-d)", "((a+b)", "{[()]}", "{[(])}"};
    for (int i = 0; i < 4; i++) {
        cout << tests[i] << " -> "
             << (isBalanced(tests[i]) ? "BALANCED" : "NOT BALANCED") << endl;
    }
    cout << "Idea: '(' push karo, ')' mila to '(' pop karo. End me stack empty ho to balanced." << endl;

    // ---- TASK 5: Two stacks in one array ----
    cout << "\n--- TASK 5: Two stacks sharing one array ---" << endl;
    TwoStacks ts;
    ts.push1(1); ts.push1(2);
    ts.push2(90); ts.push2(80);
    cout << "Stack1 pop: " << ts.pop1() << " " << ts.pop1() << endl;
    cout << "Stack2 pop: " << ts.pop2() << " " << ts.pop2() << endl;
    cout << "Ek array me stack1 left se, stack2 right se badhta hai." << endl;

    cout << "\nAll tasks done! LIFO samajh aa gaya." << endl;
    return 0;
}