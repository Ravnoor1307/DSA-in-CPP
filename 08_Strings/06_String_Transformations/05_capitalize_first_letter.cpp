/*
═══════════════════════════════════════════════
 CAPITALIZE FIRST LETTER OF EACH WORD
 ⏱️ TIME COMPLEXITY: O(n) — one loop visits n chars with constant checks, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A document editor's title-case feature turns "hello world" into "Hello World".
 The first letter of every word must be uppercased.

 📖 THEORY:
 - Track the start of a word using a `newWord` flag.
 - If the current char is alphabetic and newWord is true, uppercase it.
 - After a non-space char, set newWord=false.
 - After a space, set newWord=true.
 - Other letters can optionally be lowercased; here the focus is capitalizing the
   first letter of each word.

 ASCII VISUAL / COUNT STATE:
 s="hello world from dsa"
 h is new word -> H
 e/l/l/o same word
 space -> next char new word
 w -> W
 result: Hello World From Dsa

 🧠 LOGIC — STEP BY STEP:
 Step 1: Start with newWord = true.
    WHY: the very first character begins a word.
 Step 2: On a space, set newWord = true.
    WHY: the next character starts a new word.
 Step 3: On a non-space char with newWord true, uppercase it.
    WHY: the first letter of a word is capitalized.
 Step 4: After handling a non-space char, set newWord = false.
    WHY: the remaining letters of the word are not first letters.

 DRY RUN:
 h newWord -> H
 chars ello keep
 space -> newWord true
 w -> W
 rest keep

 FLOW OF EXECUTION:
 input string -> loop each char -> detect word starts -> uppercase first letter -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop visits n chars once.
 - Each char constant checks/conversion.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - In-place modification.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "hello world from dsa";
    bool newWord = true;
    for (char& ch : s) {
        if (ch == ' ') {
            newWord = true;
        } else {
            if (newWord) ch = (char)toupper((unsigned char)ch);
            newWord = false;
        }
    }
    cout << "Capitalized = " << s << "\n";
    return 0;
}

/*
OUTPUT:
Capitalized = Hello World From Dsa
*/

