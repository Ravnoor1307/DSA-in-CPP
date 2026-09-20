/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_print_all_permutations.cpp
│
│ REAL-WORLD SCENARIO:
│ Photo booth me friends ko every possible standing order me arrange karna hai. Permutation recursion har position ke liye available character choose karta hai, then undo/backtrack karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. index position fix karni hai.
│ 2. i=index..n-1 tak har char ko index par swap karo.
│ 3. Recurse for index+1.
│ 4. Return ke baad swap back: ye backtracking undo hai.
│ 5. Base case index==n, one permutation ready.
│ 6. Total outputs n! hote hain.
│
│ ASCII VISUAL / RECURSION TREE STATE:
│ "abc" swap tree:
│
│ level0 fix index0:
│   a + perm(bc) -> abc, acb
│   b + perm(ac) -> bac, bca
│   c + perm(ba) -> cba, cab
│
│ Backtracking idea:
│ swap -> recurse -> swap back (undo)
│
│ All permutations set: abc, acb, bac, bca, cab, cba
│
│ DRY RUN:
│ start abc
│ index0 choose a, index1 choose b -> abc
│ undo, choose c at index1 -> acb
│ undo to abc, choose b at index0 -> bac, bca
│ choose c at index0 -> cba, cab
│
│ FLOW OF EXECUTION:
│ input/problem state -> recursive choices -> base cases -> undo/unwind/output
│
│ COMPLEXITY CALCULATION:
│ - Number of permutations = n!.
│ - At each leaf, printing string of length n costs n.
│ - Total output cost = n * n!.
│ -> Time Complexity = O(n*n!).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion depth n.
│ - Output storage if stored would be n*n!; this demo prints directly.
│ -> Extra Space Complexity = O(n) call stack.
│ APPROACH COMPARISON TABLE:
│ Used-array recursion = choose unused friend cards, O(n*n!) time/O(n) space.
│ Swap backtracking = arrange in same row and undo swaps, O(n*n!) time/O(n) stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permute(string& s, int index) {
    if (index == (int)s.size()) {
        cout << s << " ";
        return;
    }
    for (int i = index; i < (int)s.size(); i++) {
        swap(s[index], s[i]);      // choose
        permute(s, index + 1);     // explore
        swap(s[index], s[i]);      // undo/backtrack
    }
}

int main() {
    string s = "abc";
    cout << "Permutations: ";
    permute(s, 0);
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Permutations: abc acb bac bca cba cab
*/

