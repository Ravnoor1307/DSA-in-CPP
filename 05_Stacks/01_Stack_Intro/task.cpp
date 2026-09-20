/*
 * ══════════════════════════════════════════════════
 *  TASKS — 01_Stack_Intro
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <string>
using namespace std;

/* TASK 1 — find MIDDLE of stack without removing (EASY)
   Given array + size acting as a stack (top at front), return the middle
   element's index (n/2) and value. n=5 → index 2, value = arr[2]. */
void task1_middle(int arr[], int n) {
    int mid = n / 2;
    cout << "middle index = " << mid << " value = " << arr[mid] << endl;
}

/* TASK 2 — REVERSE a number using a stack (EASY)
   Given digits pushed in order 1,2,3,4,5, popping gives 5,4,3,2,1.
   Return reversed digits as a string. */
string task2_reverseDigits(int arr[], int n) {
    string rev;
    for (int i = n - 1; i >= 0; i--) {   // top se niche tak
        rev += to_string(arr[i]);
        if (i > 0) rev += ",";
    }
    return rev;
}

/* TASK 3 — check if a bracket SEQUENCE looks balanced (MEDIUM)
   Only '(' and ')'. Use a count (concept of stack depth): never negative,
   ends at 0. Return true if balanced. "(()())" → true, ")(" → false. */
bool task3_balanced(const string& s) {
    int depth = 0;
    for (char c : s) {
        if (c == '(') depth++;
        else depth--;
        if (depth < 0) return false;   // closing bina opening ke
    }
    return depth == 0;                 // open bracket bacha nahi
}

/* TASK 4 — simulate undo using two stacks (MEDIUM)
   text = "ab", operations: type 'c' -> push to undo; 'u' -> undo last.
   Process op list and return final text. "ab" + 'c','c','u' -> "abc". */
string task4_undo(string text, char ops[], int n) {
    string undo;
    for (int i = 0; i < n; i++) {
        if (ops[i] == 'u') {           // undo: last char wapas
            if (!text.empty()) {
                undo.push_back(text.back());
                text.pop_back();
            }
        } else {                       // type karo
            text.push_back(ops[i]);
        }
    }
    return text;
}

/* TASK 5 — monotonic stack: next GREATER element (HARD)
   For each element, output the next element to its right that is strictly
   larger, or -1. arr={4,5,2,25} -> 5 25 25 -1.
   Use a stack of indices scanning right-to-left. */
void task5_nextGreater(int arr[], int n) {
    int* res = new int[n];
    int* st = new int[n];              // index stack
    int top = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (top > 0 && arr[st[top - 1]] <= arr[i]) top--;   // chhote hata do
        res[i] = (top > 0) ? arr[st[top - 1]] : -1;
        st[top++] = i;
    }
    for (int i = 0; i < n; i++) cout << res[i] << (i + 1 < n ? " " : "\n");
    delete[] res;
    delete[] st;
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    int a1[5] = {11, 22, 33, 44, 55};
    task1_middle(a1, 5);                          // index 2 value 33

    cout << "---- TASK 2 ----" << endl;
    int a2[5] = {1, 2, 3, 4, 5};
    cout << task2_reverseDigits(a2, 5) << endl;   // 5,4,3,2,1

    cout << "---- TASK 3 ----" << endl;
    cout << task3_balanced("(()())") << endl;     // 1 (true)
    cout << task3_balanced(")(") << endl;         // 0 (false)

    cout << "---- TASK 4 ----" << endl;
    char ops[5] = {'c', 'c', 'u', 'c', 'u'};
    cout << task4_undo("ab", ops, 5) << endl;     // ab,abc,abcc,abc,abcc,abc -> abc

    cout << "---- TASK 5 ----" << endl;
    int a5[4] = {4, 5, 2, 25};
    task5_nextGreater(a5, 4);                     // 5 25 25 -1
    return 0;
}