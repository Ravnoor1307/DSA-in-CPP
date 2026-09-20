/*
═══════════════════════════════════════════════
 C-STYLE STRINGS (Char Arrays + Null Terminator)
 ⏱️ TIME COMPLEXITY: strlen O(N), strcpy O(N), strcmp O(min len), reverse O(N)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a school's attendance register. The teacher writes student names
 on a paper list. In C, a name is just a sequence of characters stored in
 a char array — like writing letters in consecutive boxes of a tray. At
 the end of the tray, a special marker (the null terminator '\0') tells
 us "the name ends here." Password checks, name lists, and old C programs
 all use C-style strings.

 📖 THEORY: (pure English, beginner-level)
 - A C-string is a char array ending with a null character '\0'.
 - The '\0' is required so functions know where the string stops.
 - <cstring> provides strlen, strcpy, strcat, strcmp.
 - Manual loops let us compute length, reverse, and check palindrome
   without any library function.

 ASCII MEMORY LAYOUT — "hi world":
 Indices:   0   1   2   3   4   5   6   7   8   9   10
           ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
           │'h'│'i'│' '│'w'│'o'│'r'│'l'│'d'│'\0'│   │   │
           └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
            ^                        ^
            |                        +-- null terminator = end marker
            char name[11];

   strlen = 8 (counts chars BEFORE '\0', does NOT count '\0')

 📖 <cstring> FUNCTIONS:
   strlen(str)  → length (excludes '\0')
   strcpy(dst, src) → copies src into dst INCLUDING '\0'
   strcat(dst, src) → appends src to end of dst (dst must have space)
   strcmp(a, b) → 0 if equal, <0 if a<b, >0 if a>b (lexicographic)

 WHEN TO USE:
 - Simple, tiny, fixed-size strings with no memory management
 - Interfacing with C libraries, file I/O, legacy code
 - Embedded systems (no heap overhead)

 🧠 LOGIC — STEP BY STEP (Manual length):
 Step 1: Start index at 0. WHY: first character is at index 0.
 Step 2: While str[i] != '\0', increment i. WHY: '\0' marks the end.
 Step 3: Return i. WHY: i now equals the number of characters.

 VISUAL WALKTHROUGH — Reverse "abc":
 Original: a   b   c   '\0'
 Reverse:  c   b   a   '\0'
 Swap str[0]↔str[2], str[1] stays. Two pointers: left=0, right=len-1.

 DRY RUN — Palindrome check for "radar":
 Compare str[0]='r' vs str[4]='r' → match
 Compare str[1]='a' vs str[3]='a' → match
 Compare str[2]='d' vs str[2]='d' → match (same position)
 → Is Palindrome: Yes. Total comparisons = 2 (half of 5).

 TIME COMPLEXITY CALCULATION:
 - Manual length: 1 pass, each char checked once.
   N iterations, each O(1) → total work = N
 - Reverse: N/2 swaps, each swap O(1) → total work = N/2
 - Palindrome: N/2 comparisons → total work = N/2
 → Time Complexity = O(N)

 SPACE COMPLEXITY CALCULATION:
 - Input char array: N+1 bytes (N chars + '\0').
 - Reverse/palindrome: no extra arrays, few index variables.
 → Space Complexity = O(1) extra

 APPROACH COMPARISON:
 ┌──────────────────┬───────────────────────────┬─────────────────────────────┐
 │ Feature          │ C-string (char[])        │ std::string                 │
 ├──────────────────┼───────────────────────────┼─────────────────────────────┤
 │ Memory           │ Manual, fixed size       │ Automatic, grows            │
 │ Null terminator  │ Required '\0'            │ Handled internally          │
 │ Length           │ strlen O(N)              │ .length() O(1)              │
 │ Concatenation    │ strcat (dangerous)       │ + operator (safe)           │
 │ Assignment       │ strcpy (manual)          │ = operator                  │
 │ Comparison       │ strcmp                   │ == operator                 │
 └──────────────────┴───────────────────────────┴─────────────────────────────┘
*/

#include <iostream>
#include <cstring>   // strlen, strcpy, strcat, strcmp ke liye
using namespace std;

// Manual length — indexing ki madad se
int myStrlen(const char* s) {
    int i = 0;
    while (s[i] != '\0') i++;  // jab tak '\0' nahi milta, count karo
    return i;
}

// Manual reverse — two-pointer approach
void myReverse(char* s) {
    int len = myStrlen(s);
    int left = 0, right = len - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// Manual palindrome — dono ends se compare karo
bool isPalindrome(const char* s) {
    int len = myStrlen(s);
    int left = 0, right = len - 1;
    while (left < right) {
        if (s[left] != s[right])
            return false;   // mismatch mila — palindrome nahi hai
        left++;
        right--;
    }
    return true;
}

int main() {

    // ═══════════════════════════════════════════
    // DEMO 1: C-string + Null Terminator Visualization
    // ═══════════════════════════════════════════
    cout << "=== DEMO 1: Null Terminator Visualization ===" << endl;

    char name[16] = "hi";   // internally: 'h', 'i', '\0'
    cout << "Contents with indices:\n";
    cout << "Index: ";
    for (int i = 0; i < 3; i++) cout << i << "     ";
    cout << endl;
    cout << "Char:  ";
    for (int i = 0; i < 3; i++) {
        if (name[i] == '\0')
            cout << "'\\0'" << "   ";
        else
            cout << "'" << name[i] << "'" << "    ";
    }
    cout << "\n\n";

    // ═══════════════════════════════════════════
    // DEMO 2: strlen vs manual length
    // ═══════════════════════════════════════════
    cout << "=== DEMO 2: Length (library vs manual) ===" << endl;
    char word[32] = "programming";
    cout << "strlen(\"programming\") = " << strlen(word) << endl;
    cout << "myStrlen(\"programming\") = " << myStrlen(word) << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 3: Reverse (manual)
    // ═══════════════════════════════════════════
    cout << "=== DEMO 3: Reverse ===" << endl;
    char rev[32] = "hello world";
    cout << "Before: " << rev << endl;
    myReverse(rev);
    cout << "After:  " << rev << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 4: Palindrome
    // ═══════════════════════════════════════════
    cout << "=== DEMO 4: Palindrome Check ===" << endl;
    char pal1[32] = "radar";
    char pal2[32] = "hello";
    cout << "Is \"" << pal1 << "\" palindrome? " << (isPalindrome(pal1) ? "YES" : "NO") << endl;
    cout << "Is \"" << pal2 << "\" palindrome? " << (isPalindrome(pal2) ? "YES" : "NO") << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 5: strcpy, strcat, strcmp (library)
    // ═══════════════════════════════════════════
    cout << "=== DEMO 5: Library Functions ===" << endl;

    char first[32];
    strcpy(first, "Aman");          // copy into destination
    strcat(first, " Kumar");        // append at the end
    cout << "After strcpy + strcat: " << first << endl;

    char a[16] = "apple", b[16] = "apple", c[16] = "banana";
    cout << "strcmp(\"apple\",\"apple\")  = " << strcmp(a, b) << " (equal)" << endl;
    cout << "strcmp(\"apple\",\"banana\") = " << strcmp(a, c) << " (negative = a < b)" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: Empty string
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: Empty String ===" << endl;
    char empty[8] = "";   // sirf '\0'
    cout << "strlen(empty) = " << strlen(empty) << endl;
    cout << "Is empty string palindrome? " << (isPalindrome(empty) ? "YES" : "NO") << endl;
    myReverse(empty);      // kuch bhi nahi hoga, safe
    cout << "Reverse of empty = \"" << empty << "\"" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: Buffer size safety
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: Buffer Safety ===" << endl;
    char safe[8] = "ok";   // buffer size sirf 8
    cout << "Buffer \"ok\" fitted safely in char[8]" << endl;
    cout << "Length: " << myStrlen(safe) << endl;

    return 0;
}