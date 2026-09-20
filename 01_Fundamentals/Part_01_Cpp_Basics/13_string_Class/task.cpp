/*
═══════════════════════════════════════════════
 TASK SET — std::string
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A search engine needs to count vowels in queries,
    find the first non-repeating character in a username, and reverse the
    words of a sentence. Every one of these is a std::string task.
 🧠 HOW TO SOLVE: Use .length(), loops over indices, .find(), .substr().
    Think character-by-character for counting; boundary scanning for words.
 MODES/TOPICS COVERED:
   1. Count Vowels
   2. First Unique Character
   3. Reverse Words in Place
   4. Longest Word
   5. Check Anagram
   6. Remove All Spaces

 TASK 1 (EASY): Count Vowels
    Count vowels (a,e,i,o,u — case-insensitive) in a string.
    Hint: Check every char after converting it to lowercase.
    // STARTER CODE:
    // int countVowels(const string& s) { int cnt=0; for(char c : s) ... }

 TASK 2 (EASY): First Unique Character
    Return the index of the first character that appears exactly once; else -1.
    Hint: Build a frequency array [26] — count in the first pass, find in the
    second pass.
    // STARTER CODE:
    // int firstUnique(const string& s) { int freq[26]={0}; ... }

 TASK 3 (MEDIUM): Reverse Words in Place
    Reverse the order of words in a sentence ("hi there" → "there hi").
    Hint: Reverse the whole string, then reverse every word again.
    // STARTER CODE:
    // string reverseWordsOrder(const string& s) { ... }

 TASK 4 (MEDIUM): Longest Word
    Find the longest word in a sentence. Return the word (or length).
    Hint: Boundaries — segment from space to space, track its length.
    // STARTER CODE:
    // string longestWord(const string& s) { ... }

 TASK 5 (HARD): Check Anagram
    Two strings are anagrams if same letters in different order ("listen"/"silent").
    Hint: Both character count arrays must be equal.
    // STARTER CODE:
    // bool isAnagram(const string& a, const string& b) { ... }

 TASK 6 (HARD): Remove All Spaces
    Remove every space from the string without extra memory (in-place).
    Hint: Write-pointer approach — j writes, i reads.
    // STARTER CODE:
    // void removeSpaces(string& s) { size_t j=0; for(size_t i=0; ...) ... }

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <string>
#include <algorithm>   // reverse() ke liye
#include <cctype>      // tolower() ke liye
using namespace std;

// ═══════════════════════════════════════════
// TASK 1: Count Vowels
// ═══════════════════════════════════════════
// har char ko lowercase karke vowel set se compare karo
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowels(const string& s) {
    int cnt = 0;
    for (char c : s) {
        if (isVowel(c)) cnt++;
    }
    return cnt;
}

// ═══════════════════════════════════════════
// TASK 2: First Unique Character
// ═══════════════════════════════════════════
// freq[26] mein pehle count karo, phir string mein pehla freq==1 dhundo
int firstUnique(const string& s) {
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;   // 'a' hash karne ki tarah
    }
    for (size_t i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) return (int)i;
    }
    return -1;
}

// ═══════════════════════════════════════════
// TASK 3: Reverse Words Order
// ═══════════════════════════════════════════
// Puri string reverse karo, phir har word reverse karo → word order ulat jata
string reverseWordsOrder(const string& s) {
    string t = s;
    reverse(t.begin(), t.end());   // "hi there" → "ereht ih"

    size_t i = 0;
    while (i < t.size()) {
        size_t start = i;
        while (i < t.size() && t[i] != ' ') i++;  // word end tak jao
        reverse(t.begin() + start, t.begin() + i); // us word ko reverse
        while (i < t.size() && t[i] == ' ') i++;  // space skip
    }
    return t;
}

// ═══════════════════════════════════════════
// TASK 4: Longest Word
// ═══════════════════════════════════════════
// space boundaries ke beech ka segment length-track karke compare karo
string longestWord(const string& s) {
    string best, cur;
    for (size_t i = 0; i <= s.size(); i++) {
        if (i < s.size() && s[i] != ' ') {
            cur += s[i];
        } else {
            if (cur.size() > best.size()) {
                best = cur;   // ab tak ka longest mile
            }
            cur.clear();
        }
    }
    return best;
}

// ═══════════════════════════════════════════
// TASK 5: Anagram Check
// ═══════════════════════════════════════════
// dono ke character counts match karo; koi bhi mismatch = not anagram
bool isAnagram(const string& a, const string& b) {
    if (a.size() != b.size()) return false;   // length alag = anagram nahi

    int freq[26] = {0};
    for (char c : a) freq[c - 'a']++;         // a ke chars +1
    for (char c : b) freq[c - 'a']--;         // b ke chars -1
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;       // balance nahi = galat
    }
    return true;
}

// ═══════════════════════════════════════════
// TASK 6: Remove All Spaces (In-Place)
// ═══════════════════════════════════════════
// write-pointer j sirf non-space chars copy karta hai
void removeSpaces(string& s) {
    size_t j = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            s[j] = s[i];   // aage write karo
            j++;
        }
        // space aaya to j ruke, i aage badhta rahe
    }
    s.resize(j);   // naya chhota size — bacha hua trash hataya
}

// ═══════════════════════════════════════════
// DRIVER
// ═══════════════════════════════════════════
int main() {

    // --- Task 1 ---
    cout << "=== TASK 1: Count Vowels ===" << endl;
    cout << "countVowels(\"Hello World\") = " << countVowels("Hello World") << endl;   // 3
    cout << "countVowels(\"xyz\")         = " << countVowels("xyz") << endl;           // 0
    cout << endl;

    // --- Task 2 ---
    cout << "=== TASK 2: First Unique ===" << endl;
    cout << "firstUnique(\"leetcode\") = " << firstUnique("leetcode") << endl;   // 0 for 'l'
    cout << "firstUnique(\"aabb\")     = " << firstUnique("aabb") << endl;       // -1
    cout << endl;

    // --- Task 3 ---
    cout << "=== TASK 3: Reverse Word Order ===" << endl;
    cout << "\"hi there friend\" -> \"" << reverseWordsOrder("hi there friend") << "\"" << endl;
    cout << endl;

    // --- Task 4 ---
    cout << "=== TASK 4: Longest Word ===" << endl;
    cout << "\"the quick brown fox\" -> \"" << longestWord("the quick brown fox") << "\"" << endl;
    cout << endl;

    // --- Task 5 ---
    cout << "=== TASK 5: Anagram ===" << endl;
    cout << "isAnagram(\"listen\",\"silent\") = " << (isAnagram("listen", "silent") ? "YES" : "NO") << endl;
    cout << "isAnagram(\"hello\",\"world\")   = " << (isAnagram("hello", "world") ? "YES" : "NO") << endl;
    cout << endl;

    // --- Task 6 ---
    cout << "=== TASK 6: Remove Spaces ===" << endl;
    string spacey = "a b  c   d";
    cout << "Before: \"" << spacey << "\"" << endl;
    removeSpaces(spacey);
    cout << "After:  \"" << spacey << "\"" << endl;
    cout << endl;

    // --- EDGE: Empty string ---
    cout << "=== EDGE CASE ===" << endl;
    cout << "countVowels(\"\") = " << countVowels("") << endl;                    // 0
    cout << "firstUnique(\"\") = " << firstUnique("") << endl;                    // -1
    cout << "longestWord(\"\") = \"" << longestWord("") << "\"" << endl;          // ""
    cout << "isAnagram(\"\",\"\")   = " << (isAnagram("", "") ? "YES" : "NO") << endl;   // YES

    return 0;
}