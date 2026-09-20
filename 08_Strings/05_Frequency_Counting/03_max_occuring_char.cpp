/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_max_occuring_char.cpp
│
│ REAL-WORLD SCENARIO:
│ Voting booth me jis letter ko sabse zyada votes mile, wahi winner hai. Frequency array bana kar max occurring character nikal sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Frequency array 26 banao.
│ 2. String scan karke counts fill karo.
│ 3. freq array scan karke maximum count and character find karo.
│ 4. Tie case me earliest alphabet choose kar sakte hain.
│ 5. Lowercase strings ke liye direct mapping works.
│
│ ASCII VISUAL / COUNT STATE:
│ s="success"
│ counts:
│ c:2, e:1, s:3, u:1
│ max = s with 3
│
│ freq boxes:
│ a b c d e ... s ... u
│ 0 0 2 0 1 ... 3 ... 1
│
│ DRY RUN:
│ scan success:
│ s count1, u1, c1, c2, e1, s2, s3
│ scan freq: max char s count3
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - First scan n chars.
│ - Second scan fixed 26 cells.
│ - Total = n + 26.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Fixed 26 frequency cells.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "success";
    vector<int> freq(26, 0);
    for (char ch : s) if (ch >= 'a' && ch <= 'z') freq[ch - 'a']++;

    int bestIndex = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[bestIndex]) bestIndex = i;
    }
    cout << "Max occurring char = " << char('a' + bestIndex)
         << " with count " << freq[bestIndex] << "\n";
    return 0;
}

/*
OUTPUT:
Max occurring char = s with count 3
*/

