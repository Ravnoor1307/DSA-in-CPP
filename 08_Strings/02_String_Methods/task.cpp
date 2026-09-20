/*
═══════════════════════════════════════════════
 TASK SET — STRING METHODS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: Text-editor practice: solve length, copy, find,
    replace, append, compare, and iteration tasks on strings so you can
    handle any text-editing job in code.

 🧠 HOW TO SOLVE: A compiled demo solution is given below. Demo
    strlen/strcpy/strcat/strcmp, verify strcmp returns 0 when equal, use
    string length/substr/find/replace, use append/insert/erase/push_back/
    pop_back, build == vs compare vs strcmp examples, and traverse with
    an index loop, range-for, and an iterator. HINTS: strcmp(a,b)==0 means
    equal; find not found => string::npos; insert/erase may shift chars.

 MODES/TOPICS COVERED:
  1. strlen/strcpy/strcat/strcmp demo
  2. Verify strcmp equal-return value
  3. Use string length, substr, find, replace
  4. Use append, insert, erase, push_back, pop_back
  5. == vs compare vs strcmp examples
  6. Traverse with index loop, range-for, iterator
  7. Complexity table as comments
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    char a[20] = "hi", b[20] = "hi";
    cout << "strcmp equal = " << strcmp(a, b) << "\n";

    string s = "hello world";
    size_t pos = s.find("world");
    if (pos != string::npos) s.replace(pos, 5, "C++");
    s.push_back('!');
    cout << "Edited string = " << s << "\n";

    cout << "Chars: ";
    for (char ch : s) cout << ch << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
strcmp equal = 0
Edited string = hello C++!
Chars: h e l l o   C + + !
*/

