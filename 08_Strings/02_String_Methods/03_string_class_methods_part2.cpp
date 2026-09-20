/*
═══════════════════════════════════════════════
 STRING CLASS METHODS — PART 2
 ⏱️ TIME COMPLEXITY: append O(m), insert O(n+m), erase O(n), push_back/pop_back O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a chat app, appending an emoji at the end of a message, inserting a
 word in the middle, erasing a typo, and deleting the last character are
 all common. The string class supports these operations directly.

 📖 THEORY:
 - `append(text)` adds text at the end.
 - `insert(pos,text)` inserts text at the given index.
 - `erase(pos,len)` removes a segment.
 - `push_back(ch)` adds one char at the end.
 - `pop_back()` removes the last char.

 ASCII DIAGRAM / MEMORY STATE:

 Start: "code"
 append("r")       -> "coder"
 insert(0,"DSA ")  -> "DSA coder"
 erase(3,1)         -> "DSAcoder" (space removed)
 push_back('!')     -> "DSAcoder!"
 pop_back()         -> "DSAcoder"

 🧠 LOGIC — STEP BY STEP:
 Step 1: append("r") to grow the text from the end.
    WHY: The new characters are written after the current last char.
 Step 2: insert(0,"DSA ") to place text at the front.
    WHY: Existing chars shift right to make room for the new block.
 Step 3: erase(3,1) to delete a single character.
    WHY: The tail of the string shifts left to close the gap.
 Step 4: push_back/pop_back for one-char edits.
    WHY: These touch only the last cell, so each is constant work.

 DRY RUN:
 s="code"
 append r -> coder
 insert DSA_ at pos 0 -> DSA coder
 erase one space at pos 3 -> DSAcoder
 push ! -> DSAcoder!
 pop -> DSAcoder

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - append of m chars copies m chars -> O(m).
 - insert may shift n chars and copy m chars -> O(n+m).
 - erase may shift the remaining chars -> O(n).
 - push_back amortized O(1), pop_back O(1).

 SPACE COMPLEXITY CALCULATION:
 - Operations modify the same string; capacity may be reallocated.
 -> Extra Space Complexity = O(1) to O(n), implementation-dependent during reallocation.
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
    string s = "code";
    s.append("r");
    cout << "after append: " << s << "\n";
    s.insert(0, "DSA ");
    cout << "after insert: " << s << "\n";
    s.erase(3, 1);
    cout << "after erase: " << s << "\n";
    s.push_back('!');
    cout << "after push_back: " << s << "\n";
    s.pop_back();
    cout << "after pop_back: " << s << "\n";
    return 0;
}

/*
OUTPUT:
after append: coder
after insert: DSA coder
after erase: DSAcoder
after push_back: DSAcoder!
after pop_back: DSAcoder
*/

