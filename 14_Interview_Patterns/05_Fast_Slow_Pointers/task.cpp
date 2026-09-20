/*
REAL-WORLD SCENARIO:
Race track style cycle detection practice: lists, arrays, numbers.

TASKS easy -> hard:
1. Floyd cycle detection proof comments me likho.
2. Linked list cycle detect karo.
3. Find duplicate number using nums[i] as next pointer.
4. Happy number O(1) space se check karo.
5. Middle of linked list find karo.
6. Palindrome linked list middle + reverse se solve karo.

HINTS:
- slow 1 step, fast 2 steps.
- Cycle entry ke liye one pointer start par lao.
- Happy number next = sum of digit squares.

STARTER CODE:
while (fast && fast->next) { }

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do { slow = nums[slow]; fast = nums[nums[fast]]; } while (slow != fast);
    int finder = nums[0];
    while (finder != slow) { finder = nums[finder]; slow = nums[slow]; }
    return finder;
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums) << "\n";
    return 0;
}

/*
OUTPUT:
2
*/
