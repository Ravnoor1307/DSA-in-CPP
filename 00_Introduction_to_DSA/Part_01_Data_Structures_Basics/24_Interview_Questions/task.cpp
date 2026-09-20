/*
═══════════════════════════════════════════════
 TASK SET — INTERVIEW QUESTIONS REVISION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: You are in an interview. The interviewer asks you to
 "implement searching" and "find the biggest element" on a whiteboard. Your
 revision tasks = solve small array problems instantly, in clean code, with edge
 cases handled — exactly what is expected in a coding round.
🧠 HOW TO SOLVE: Right after the question, name the approach (linear scan O(n)),
 mention if any sorting/pre-condition is needed, then code it with loops and test
 edge cases (empty/single element, not-found, duplicates).

 TASK 1 (EASY): Re-implement linear search but take the array size and key from
   the USER. Print "Found at index i" or "Not found".
 💡 HINT: loop i=0..n-1, compare == key.
 ✏️ STARTER CODE:
   int main() {
       int n, key; cin >> n;                 // array size
       int arr[100]; for (...) cin >> arr[i]; // read elements
       cin >> key;
       // TODO: linear search, print index or Not found
       return 0;
   }

 TASK 2 (EASY): COUNT all occurrences of a key in an array (not just first).
   Example: {1,2,1,3,1} key=1 -> count 3.
 💡 HINT: don't return early; increment counter on every match.
 ✏️ STARTER CODE:
   int countOccurrences(int arr[], int n, int key) {
       int count = 0;
       // TODO: count all matches
       return count;
   }

 TASK 3 (MEDIUM): Find BOTH the minimum and maximum of an array in ONE pass.
   Example: {3,9,2,7,5} -> min 2, max 9.
 💡 HINT: init min=max=arr[0]; update both inside one loop.
 ✏️ STARTER CODE:
   void findMinMax(int arr[], int n) {
       // TODO: single loop, print min and max
   }

 TASK 4 (MEDIUM): REVERSE an array IN-PLACE (O(1) extra space) using two
   pointers. Example: {1,2,3,4} -> {4,3,2,1}.
 💡 HINT: swap arr[left] and arr[right], move pointers toward the middle.
 ✏️ STARTER CODE:
   void reverseInPlace(int arr[], int n) {
       int left = 0, right = n - 1;
       // TODO: while (left < right) { swap; left++; right--; }
   }

 TASK 5 (MEDIUM): Print even and odd counts of an array. Example {1,2,3,4,5} ->
   even 2, odd 3.
 💡 HINT: n % 2 == 0 is even.
 ✏️ STARTER CODE:
   // TODO: loop, count even and odd, print both counts

 TASK 6 (HARD): Find the SECOND LARGEST element of an array without sorting.
   Example {3,9,2,9,7,5} -> 7 (handles duplicates correctly).
 💡 HINT: track largest and secondLargest; when arr[i] > largest, shift largest
   into second; when between them, update second.
 ✏️ STARTER CODE:
   int secondLargest(int arr[], int n) {
       if (n < 2) return -1;
       int largest = arr[0], second = -1;   // note: may need INT_MIN handling
       // TODO: single pass updating largest / second correctly
       return second;
   }
   // IMPROVE: for negative-heavy arrays start largest = INT_MIN too

 TASK 7 (HARD): MENU-DRIVEN mini revision program. Menu: 1) Search a key
   2) Find max 3) Reverse array 4) Exit. Use tasks from above!
 💡 HINT: use a switch, reuse linearSearch / findMinMax / reverseInPlace ideas.
   Guard the input: if (!(cin >> choice)) break; so bad input / EOF never spins
   your menu forever.
 ✏️ STARTER CODE:
   // TODO: while(true) { print menu; if (!(cin >> choice)) break; switch(choice){...} }

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <climits>
using namespace std;

// ---------- SOLUTION TASK 1 ----------
void task1() {
    int n, key;
    cout << "Enter array size: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter key to search: ";
    cin >> key;

    int found = -1;
    for (int i = 0; i < n; i++) {          // linear scan
        if (arr[i] == key) { found = i; break; }
    }
    if (found != -1) cout << "Found at index " << found << "\n";
    else cout << "Not found.\n";
}

// ---------- SOLUTION TASK 2 ----------
int countOccurrences(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) count++;        // return nahi, count badhao
    return count;
}

// ---------- SOLUTION TASK 3 ----------
void findMinMax(int arr[], int n) {
    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    cout << "min = " << mn << ", max = " << mx << "\n";
}

// ---------- SOLUTION TASK 4 ----------
void reverseInPlace(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {                 // dono pointers beech me milte hain
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// ---------- SOLUTION TASK 5 ----------
void evenOddCounts(int arr[], int n) {
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) even++;
        else odd++;
    }
    cout << "even = " << even << ", odd = " << odd << "\n";
}

// ---------- SOLUTION TASK 6 ----------
int secondLargest(int arr[], int n) {
    if (n < 2) return -1;
    int largest = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {            // naya sabse bada mila
            second = largest;              // purana largest second ban gaya
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];               // largest ke beech me hai
        }
    }
    return (second == INT_MIN) ? -1 : second;
}

// ---------- SOLUTION TASK 7 ----------
void task7(int arr[], int &n) {
    int choice;
    while (true) {
        cout << "\nMENU: 1)Search  2)Max  3)Reverse  4)Exit\nChoice: ";
        if (!(cin >> choice)) { cout << "Bad input / EOF -> exiting.\n"; break; }
        if (choice == 4) break;

        if (choice == 1) {
            int key; cin >> key;
            int found = -1;
            for (int i = 0; i < n; i++) if (arr[i] == key) { found = i; break; }
            cout << (found != -1 ? "Found at index " : "Not found");
            if (found != -1) cout << found;
            cout << "\n";
        } else if (choice == 2) {
            int mx = arr[0];
            for (int i = 1; i < n; i++) if (arr[i] > mx) mx = arr[i];
            cout << "Max = " << mx << "\n";
        } else if (choice == 3) {
            reverseInPlace(arr, n);        // reuse task 4 solution
            cout << "Reversed: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
}

int main() {
    cout << "===== TASK 1 =====\n"; task1();

    int a1[] = {1, 2, 1, 3, 1};
    cout << "===== TASK 2 =====\n";
    cout << "countOccurrences(1) = " << countOccurrences(a1, 5, 1) << "\n";

    int a2[] = {3, 9, 2, 7, 5};
    cout << "===== TASK 3 =====\n";
    findMinMax(a2, 5);

    int a3[] = {1, 2, 3, 4};
    cout << "===== TASK 4 =====\n";
    reverseInPlace(a3, 4);
    for (int i = 0; i < 4; i++) cout << a3[i] << " ";
    cout << "\n";

    int a4[] = {1, 2, 3, 4, 5};
    cout << "===== TASK 5 =====\n";
    evenOddCounts(a4, 5);

    int a5[] = {3, 9, 2, 9, 7, 5};
    cout << "===== TASK 6 =====\n";
    cout << "secondLargest = " << secondLargest(a5, 6) << "\n";

    int a6[] = {5, 8, 1, 9, 3};
    int n6 = 5;
    cout << "===== TASK 7 =====\n";
    task7(a6, n6);
    return 0;
}