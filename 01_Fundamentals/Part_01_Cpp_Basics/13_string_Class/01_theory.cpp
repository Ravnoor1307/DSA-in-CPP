/*
═══════════════════════════════════════════════
 std::string (C++ String Class)
 ⏱️ TIME COMPLEXITY: length/at O(1), append/substr O(N), find O(N), concat O(N)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Google Docs is a text editor. You type a sentence, highlight a few words,
 copy, search for a word, and the app instantly finds it. A modern
 text editor NEVER works with raw char arrays and null terminators — it
 uses std::string, which manages its own memory, grows automatically, and
 offers safe, readable operations: length, append, find, substring, replace.

 📖 THEORY: (pure English, beginner-level)
 - std::string is a class from <string> that wraps a dynamic char buffer.
 - It auto-grows when you append; no manual '\0' management needed.
 - Key operations: length(), + (append), == (compare), substr, find,
   replace, erase, getline vs cin.
 - cin >> stops at whitespace. getline reads the ENTIRE line including spaces.
 - Memory: small string may sit in a fixed buffer (SSO — Small String
   Optimization); larger strings are heap-allocated and grow.

 ASCII MEMORY GROWTH DIAGRAM:
 Stage 1:  s = "hi"
   ┌───┬───┬───┬───┐
   │'h'│'i'│'\0'│   │   size=2, capacity=4 (SSO buffer)
   └───┴───┴───┴───┘

 Stage 2:  s += " world"   (needs 8 chars > capacity 4)
   Heap reallocation:
   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
   │'h'│'i'│' '│'w'│'o'│'r'│'l'│'d'│'\0'│   size=8, capacity=16
   └───┴───┴───┴───┴───┴───┴───┴───┴───┘
   Old buffer freed. New, doubled capacity allocated.

 WHEN TO USE:
 - Almost always! Reading user input, string processing, file parsing
 - Competitive programming, web servers, text editors
 - Only use C-strings for C interop or embedded/constrained memory

 🧠 LOGIC — STEP BY STEP (Find + Replace):
 Step 1: pos = str.find(keyword). WHY: find returns first index of match
         or string::npos (-1) if not found.
 Step 2: If pos != npos, replace(pos, len, newText). WHY: replace writes
         new text at position pos, overwriting len characters.

 VISUAL WALKTHROUGH — Substring:
 s = "Hello World"
     0123456789 10
 substr(6, 5) → "World"   (start at 6, take 5 chars)
 substr(0, 5) → "Hello"

 DRY RUN — find on "Hello World", keyword "World":
 i=0: "Hello" vs "World"? H!=W → no
 ...
 i=6: s[6..10] = "World" == "World" → found, return 6
 If keyword "xyz": never matches → return string::npos

 TIME COMPLEXITY CALCULATION:
 - length(): O(1) — stored as a member variable, not counted.
 - append/substr/replace: must copy characters.
   N = string length, M = appended/substring size → work = O(N+M) ≈ O(N)
 - find(k): worst case scans each position doing k comparisons → O(N*k).
 - Iteration with a loop over chars: each char visited once → O(N).
 → Time Complexity = O(N) for the common single-pass operations

 SPACE COMPLEXITY CALCULATION:
 - String stores N+1 bytes (plus capacity slack, up to 2x).
 - Substr/replace may allocate a copy → extra O(N).
 - Iteration uses one index variable.
 → Space Complexity = O(N)

 APPROACH COMPARISON:
 ┌──────────────────┬───────────────────────────┬─────────────────────────────┐
 │ Feature          │ C-string (char[])        │ std::string                 │
 ├──────────────────┼───────────────────────────┼─────────────────────────────┤
 │ Memory           │ Manual, fixed size       │ Auto-grows                  │
 │ Length call      │ strlen — O(N) scan       │ .length() — O(1) stored     │
 │ Concat           │ strcat (unsafe)          │ + — safe, realloc handles   │
 │ Compare          │ strcmp                    │ == (reads naturally)        │
 │ Substring        │ manual loop              │ substr(pos,count)           │
 │ Find             │ manual loop              │ .find(sub)                  │
 └──────────────────┴───────────────────────────┴─────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <cctype>   // toupper ke liye
using namespace std;

int main() {

    // ═══════════════════════════════════════════
    // DEMO 1: getline vs cin — full name input
    // ═══════════════════════════════════════════
    cout << "=== DEMO 1: getline reads full line ===" << endl;

    string fullName;
    cout << "Enter your full name (e.g. Rohan Sharma): ";
    getline(cin, fullName);   // entire line including spaces

    cout << "Hello, " << fullName << "!" << endl;
    cout << "Length: " << fullName.length() << endl;
    cout << endl;

    // Note: cin >> name sirf pehla word leta hai
    // getline ke baad cin buffer clear nahi chahiye yahan kyuki hum
    // pehle hi full line le rahe hain.

    // ═══════════════════════════════════════════
    // DEMO 2: Length + Append
    // ═══════════════════════════════════════════
    cout << "=== DEMO 2: Length + Append ===" << endl;

    string s = "Hello";
    cout << "Initial: \"" << s << "\" length=" << s.length() << endl;

    s.append(" World");        // ya s += " World";
    cout << "After append: \"" << s << "\" length=" << s.length() << endl;

    s += ", DSA!";
    cout << "After +=:    \"" << s << "\" length=" << s.length() << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 3: Find substring
    // ═══════════════════════════════════════════
    cout << "=== DEMO 3: find() ===" << endl;

    string text = "the quick brown fox jumps over the lazy dog";
    string key = "fox";

    size_t pos = text.find(key);
    if (pos != string::npos) {
        cout << "Found \"" << key << "\" at index " << pos << endl;
    } else {
        cout << "Not found." << endl;
    }

    // Edge: keyword not present
    size_t npos = text.find("zebra");
    if (npos == string::npos)
        cout << "\"zebra\" not found → npos = " << (long)npos << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 4: Convert to UPPERCASE via loop
    // ═══════════════════════════════════════════
    cout << "=== DEMO 4: Uppercase via loop ===" << endl;

    string mixed = "Mixed CASE 123";
    for (size_t i = 0; i < mixed.size(); i++) {
        mixed[i] = toupper(mixed[i]);
    }
    cout << "Uppercased: " << mixed << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 5: Substring extraction
    // ═══════════════════════════════════════════
    cout << "=== DEMO 5: substr() ===" << endl;

    string sentence = "I love competitive programming";
    //            indices: I(0) space(1) love(2-5) ...
    string sub1 = sentence.substr(0, 6);   // "I love"
    string sub2 = sentence.substr(18);     // 18 se end tak "programming"
    cout << "substr(0,6)  = \"" << sub1 << "\"" << endl;
    cout << "substr(18)   = \"" << sub2 << "\"" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 6: Compare + Replace + Erase
    // ═══════════════════════════════════════════
    cout << "=== DEMO 6: Compare, Replace, Erase ===" << endl;

    string p = "apple", q = "apple", r = "banana";
    cout << "(p == q)? " << (p == q ? "YES" : "NO") << endl;
    cout << "(p == r)? " << (p == r ? "YES" : "NO") << endl;

    string edit = "I like java";
    size_t at = edit.find("java");
    edit.replace(at, 4, "C++");      // java ko C++ se badlo
    cout << "Replaced: " << edit << endl;

    edit.erase(0, 2);                 // pehle 2 chars hata do ("I ")
    cout << "After erase(0,2): \"" << edit << "\"" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: Empty string
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: Empty String ===" << endl;

    string empty;
    cout << "length: " << empty.length() << ", empty()? "
         << (empty.empty() ? "YES" : "NO") << endl;

    cout << "find(\"x\") in empty: ";
    if (empty.find("x") == string::npos)
        cout << "npos (not found) — safe, no crash" << endl;

    empty.append("added later");
    cout << "After append: \"" << empty << "\"" << endl;

    return 0;
}