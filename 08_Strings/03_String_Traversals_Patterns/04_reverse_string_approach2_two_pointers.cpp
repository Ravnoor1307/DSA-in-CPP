/*
═══════════════════════════════════════════════
 REVERSE STRING — APPROACH 2 (TWO POINTERS)
 ⏱️ TIME COMPLEXITY: O(n) — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You can reverse the order of books on a shelf by swapping the books at
 the two ends and working inward. Reversing a string with two pointers
 swaps the left and right characters in the same way.

 📖 THEORY:
 - Set left = 0 and right = n-1.
 - While left < right, swap s[left] and s[right].
 - Then do left++ and right--.
 - The pointers meet or cross at the center.
 - No extra string is created; modification is in place.

 ASCII DIAGRAM / POINTER STATE:

 s="hello"

 [h][e][l][l][o]
  L           R    swap h,o -> [o][e][l][l][h]
     L     R       swap e,l -> [o][l][l][e][h]
        L          stop

 Final: "olleh"

 🧠 LOGIC — STEP BY STEP:
 Step 1: Place left at 0 and right at n-1.
    WHY: The outermost pair must become the innermost pair after reversal.
 Step 2: Swap the two characters while left < right.
    WHY: Each swap puts both characters in their final position.
 Step 3: Move left forward and right backward.
    WHY: The pointers shrink the unprocessed middle each time.
 Step 4: Stop when left >= right.
    WHY: At the center there is nothing left to flip.

 DRY RUN:
 left0/right4 swap h,o
 left1/right3 swap e,l
 left2/right2 stop
 swaps = floor(5/2)=2

 FLOW OF EXECUTION:
 input string -> scan/split/pointer movement -> build/modify answer -> print result

 TIME COMPLEXITY CALCULATION:
 - Number of swaps = floor(n/2).
 - Each swap is constant time.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Only left/right variables plus temp inside swap.
 -> Extra Space Complexity = O(1).

 APPROACH COMPARISON TABLE:
 Extra-string reverse = photocopy board then read backward, O(n) time/O(n) space.
 Two-pointer reverse = swap books from both ends, O(n) time/O(1) space.
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

void reverseTwoPointers(string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        cout << "swap index " << left << " and " << right << "\n";
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    string s = "hello";
    reverseTwoPointers(s);
    cout << "reverse in-place = " << s << "\n";
    cout << "Comparison: extra approach O(n) space, two-pointer O(1) space.\n";
    return 0;
}

/*
OUTPUT:
swap index 0 and 4
swap index 1 and 3
reverse in-place = olleh
Comparison: extra approach O(n) space, two-pointer O(1) space.
*/

