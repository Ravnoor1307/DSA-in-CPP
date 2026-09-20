/*
═══════════════════════════════════════════════
 TASK SET — VARIOUS DATA STRUCTURES
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 Your boss asks you to pick the right tool for four jobs: (1) process
 emails in the order received, (2) support undo in an editor, (3) keep
 a name→phone lookup for 1000 contacts, (4) always fetch the cheapest
 flight first. Each job needs a different data structure. This task set
 trains you to identify and use the correct container for each job.

🧠 HOW TO SOLVE:
 - Read the scenario → decide which classic DS fits (queue, stack,
   hash map, heap, etc.).
 - For coding tasks use STL: vector (dynamic list), map (sorted
   key-value), stack, queue (from <stack>, <queue>).
 - Remember the operation rules: pop from stack = last pushed;
   pop from queue = first pushed.

 TASK 1: (EASY) Identify the data structure
   Match: undo function, printer queue, contact lookup by name.
   Fill in the correct one-word answer in the print statements.
   💡 HINT: LIFO=stack, FIFO=queue, key→value=hash table/map.
   ✏️ STARTER CODE:
     // TODO: replace ??? with correct DS name
     cout << "Undo uses: ???" << endl;
     cout << "Printer jobs use: ???" << endl;
     cout << "Name->phone lookup uses: ???" << endl;

 TASK 2: (EASY) stack LIFO check
   Push 3 numbers onto a stack, pop them and print — verify the order
   is reversed (LIFO).
   💡 HINT: include <stack>; use push(), top(), pop().
   ✏️ STARTER CODE:
     #include <stack>
     stack<int> s;
     s.push(1); s.push(2); s.push(3);
     // TODO: while stack not empty, print top, then pop
     // expected output: 3 2 1

 TASK 3: (MEDIUM) queue FIFO check
   Enqueue 3 numbers and dequeue them — order should stay 1 2 3.
   💡 HINT: include <queue>; use push(), front(), pop().
   ✏️ STARTER CODE:
     #include <queue>
     queue<int> q;
     q.push(1); q.push(2); q.push(3);
     // TODO: while not empty, print front, then pop
     // expected output: 1 2 3

 TASK 4: (MEDIUM) map name → age
   Store 3 friends' ages in a map and print each friend +
   age in sorted name order, then look up one friend's age.
   💡 HINT: map<string,int> m; m["name"]=age; iterate to print.
   ✏️ STARTER CODE:
     #include <map>
     map<string,int> m;
     m["Raj"]=21; m["Anu"]=19; m["Tom"]=22;
     // TODO: iterate and print; then find("Anu") and print age

 TASK 5: (MEDIUM) vector with largest value
   Read 5 numbers into a vector (hardcode them) and print the largest.
   💡 HINT: keep a running max while looping over v.size().
   ✏️ STARTER CODE:
     #include <vector>
     vector<int> v; // push 5 values
     // TODO: loop and find the max, print it
     // expected for 4 9 2 7 5 → 9

 TASK 6: (HARD) stack-based palindrome check
   Check if a word is a palindrome using a stack: push all letters,
   then pop letters and compare with the original word.
   💡 HINT: if word[i] != top after pop → not a palindrome.
   ✏️ STARTER CODE:
     bool isPalin(string w) {
         stack<char> s;
         for (char c : w) s.push(c);
         // TODO: pop and compare with w[i]; if mismatch return false
         return true;
     }

═══════════════════════════════════════════════
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;

// TASK 1: DS identify karo
void identifyDS() {
    cout << "Undo uses: stack (LIFO)" << endl;
    cout << "Printer jobs use: queue (FIFO)" << endl;
    cout << "Name->phone lookup uses: hash table / map" << endl;
}
// Explanation: undo = last action pehle undo hota hai (LIFO).
// Printer = pehle aaya print pehle hoga (FIFO). Name se phone khujna
// = key-value lookup, hash table.

// TASK 2: stack LIFO
void stackDemo() {
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    cout << "Stack pop order (LIFO): ";
    while (!s.empty()) {
        cout << s.top() << " ";   // top wale ko dekho
        s.pop();                  // top hatao
    }
    cout << endl;                  // expected: 3 2 1
}
// Explanation: top() peek karta hai, pop() remove karta hai, empty()
// check karta hai. Isliye ulta order milta hai.

// TASK 3: queue FIFO
void queueDemo() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "Queue dequeue order (FIFO): ";
    while (!q.empty()) {
        cout << q.front() << " ";  // front wale ko dekho
        q.pop();                   // front hatao
    }
    cout << endl;                  // expected: 1 2 3
}
// Explanation: queue mein front() pehle wala lauta hai — same order.

// TASK 4: map name->age
void mapDemo() {
    map<string, int> m;
    m["Raj"] = 21;
    m["Anu"] = 19;
    m["Tom"] = 22;
    cout << "map (sorted order): ";
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << "=" << it->second << " ";
    }
    cout << endl;
    map<string, int>::iterator f = m.find("Anu");
    if (f != m.end()) {
        cout << "Anu's age: " << f->second << endl;   // 19
    }
}
// Explanation: map keys sorted order mein iterate hoti hain (Anu, Raj,
// Tom). find() O(log n) mein key khujta hai.

// TASK 5: vector ka max
void vectorMax() {
    vector<int> v;
    v.push_back(4);
    v.push_back(9);
    v.push_back(2);
    v.push_back(7);
    v.push_back(5);
    int maxVal = v[0];
    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] > maxVal) maxVal = v[i];
    }
    cout << "Largest in vector: " << maxVal << endl;   // 9
}
// Explanation: har element se compare karo, jo bada ho use max banao.

// TASK 6: stack se palindrome check
bool isPalin(string w) {
    stack<char> s;
    for (int i = 0; i < (int)w.size(); i++) {
        s.push(w[i]);                // saare letters stack pe
    }
    for (int i = 0; i < (int)w.size(); i++) {
        if (s.top() != w[i]) {
            return false;            // match nahi hua → palindrome nahi
        }
        s.pop();
    }
    return true;
}
// Explanation: word ko stack pe chadhane se ulta order milta hai;
// ulta order = original order ho to palindrome hai. "racecar" jaise.

int main() {
    identifyDS();
    stackDemo();      // 3 2 1
    queueDemo();      // 1 2 3
    mapDemo();        // Anu=19 Raj=21 Tom=22 | Anu's age: 19
    vectorMax();      // 9

    cout << "isPalin(\"racecar\") = " << (isPalin("racecar") ? "yes" : "no") << endl;  // yes
    cout << "isPalin(\"hello\")   = " << (isPalin("hello")   ? "yes" : "no") << endl;  // no

    // Edge case: ek-akhshar word hamesha palindrome hota hai
    cout << "isPalin(\"a\") = " << (isPalin("a") ? "yes" : "no") << endl;               // yes

    return 0;
}

// ⏱ Time: stack/queue ops O(1) each; map find/insert O(log n);
//          vector max O(n); palindrome O(len).
// 🧠 Space: stack/queue/map/vector apne elements ke liye O(n).