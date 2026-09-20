/*
═══════════════════════════════════════════════
 TASK SET — STATIC vs DYNAMIC DATA STRUCTURES
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A canteen first orders food for exactly 10 students
 (static), but 25 students show up. The manager must either copy everything to a
 bigger list manually OR use a rack that grows automatically (dynamic). These
 tasks make you practise that same "grow the storage" idea in C++.
🧠 HOW TO SOLVE: Use plain arrays (static) for fixed-count problems and
 std::vector (dynamic) whenever the count changes at runtime. Watch size vs
 capacity and memory addresses to understand the difference.

 TASK 1 (EASY): Print size of a static array and size of a vector side by side.
   Declare int arr[5] and vector<int> v with 3 pushed elements. For the array use
   sizeof(arr)/sizeof(arr[0]); for the vector use v.size(). Print both.
 💡 HINT: sizeof() gives total BYTES; divide by size of one element.
 ✏️ STARTER CODE:
   int arr[5] = {1,2,3,4,5};
   vector<int> v; v.push_back(10); v.push_back(20); v.push_back(30);
   // TODO: print array size and vector size, compare them

 TASK 2 (EASY): Push 6 elements into a vector and print size and capacity after
   each push_back. Count how many times capacity actually changed.
 💡 HINT: capacity changes only when size reaches capacity.
 ✏️ STARTER CODE:
   vector<int> v;
   int prevCap = 0, growths = 0;
   for (int i = 1; i <= 6; i++) {
       v.push_back(i);
       // TODO: print size, capacity; if capacity changed, growths++
   }
   cout << "Total re-allocations: " << growths << "\n";

 TASK 3 (MEDIUM): Prove that a static array IS contiguous memory but a dynamic
   vector MIGHT re-allocate. Print addresses of consecutive elements of int arr[4]
   and of vector<int> v(4). Observe that array addresses increase by exactly
   sizeof(int) = 4 bytes.
 💡 HINT: &arr[i] gives the address; print it as long long or pointer.
 ✏️ STARTER CODE:
   int arr[4] = {5,6,7,8};
   vector<int> v = {5,6,7,8};
   // TODO: print &arr[i] and &v[i] for i in 0..3, note the gaps

 TASK 4 (MEDIUM): Manually do what a vector does automatically — "grow" a static
   array. Start with int oldArr[2] = {1,2}. Create int newArr[5], copy 2 elements,
   then add 3 more. Print the final array.
 💡 HINT: copy with a simple for loop before adding the new items.
 ✏️ STARTER CODE:
   int oldArr[2] = {1, 2};
   int newArr[5];
   // TODO: copy old -> new, then newArr[2]=3, newArr[3]=4, newArr[4]=5
   // TODO: print all five elements

 TASK 5 (MEDIUM): Play with vector reserve / resize. Create vector<int> v; call
   v.reserve(10); then push 3 elements. Print capacity (should be 10). Then call
   v.shrink_to_fit(); print capacity again.
 💡 HINT: reserve() fixes capacity in advance so no mid-growth re-allocation.
 ✏️ STARTER CODE:
   vector<int> v;
   v.reserve(10);
   v.push_back(1); v.push_back(2); v.push_back(3);
   // TODO: print v.capacity() after reserve -> should be 10
   // TODO: shrink_to_fit() then print capacity again

 TASK 6 (HARD): Lambda-style: take n from the user and store n numbers in a
   vector (works for ANY n). Then TRY the same with a fixed int arr[5] — before
   writing, check "if (n > 5)" and print a warning instead of overflowing.
 💡 HINT: safe guard: if n > 5 print "too many for static array, use vector".
 ✏️ STARTER CODE:
   int n; cout << "How many numbers? "; cin >> n;
   vector<int> v(n);
   if (n > 5) cout << "Warning: n(" << n << ") > 5 cannot fit in int arr[5].\n";
   // TODO: fill vector with n numbers from user and print them
   // TODO: explain why vector succeeded where static array would fail

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
using namespace std;

// ---------- SOLUTION TASK 1 ----------
void task1() {
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int> v;
    v.push_back(10); v.push_back(20); v.push_back(30);

    int arrSize = sizeof(arr) / sizeof(arr[0]);   // total bytes / ek element ke bytes
    cout << "Static array size = " << arrSize << "\n";
    cout << "Vector size       = " << v.size() << "\n";
    // static array fixed 5, vector currently 3 (can become 4 later)
}

// ---------- SOLUTION TASK 2 ----------
void task2() {
    vector<int> v;
    int prevCap = 0, growths = 0;
    for (int i = 1; i <= 6; i++) {
        v.push_back(i);
        if ((int)v.capacity() != prevCap) {   // capacity badla matlab re-allocation hui
            growths++;
            prevCap = v.capacity();
            cout << "re-allocation at size " << v.size()
                 << " -> new capacity " << v.capacity() << "\n";
        } else {
            cout << "push " << i << ": size=" << v.size()
                 << " capacity=" << v.capacity() << " (no growth)\n";
        }
    }
    cout << "Total re-allocations: " << growths << "\n";
}

// ---------- SOLUTION TASK 3 ----------
void task3() {
    int arr[4] = {5, 6, 7, 8};
    vector<int> v = {5, 6, 7, 8};
    cout << "Static array addresses: ";
    for (int i = 0; i < 4; i++) cout << &arr[i] << " ";
    cout << "\nVector addresses:       ";
    for (int i = 0; i < 4; i++) cout << &v[i] << " ";
    cout << "\n(static array addresses differ by exactly 4 bytes = contiguous.)\n";
}

// ---------- SOLUTION TASK 4 ----------
void task4() {
    int oldArr[2] = {1, 2};
    int newArr[5];
    for (int i = 0; i < 2; i++) newArr[i] = oldArr[i];   // purana data copy kiya
    newArr[2] = 3; newArr[3] = 4; newArr[4] = 5;         // naye elements add kiye
    cout << "Manually grown array: ";
    for (int i = 0; i < 5; i++) cout << newArr[i] << " ";
    cout << "\n";
}

// ---------- SOLUTION TASK 5 ----------
void task5() {
    vector<int> v;
    v.reserve(10);                       // pehle se 10 slots book kar liye
    v.push_back(1); v.push_back(2); v.push_back(3);
    cout << "Capacity after reserve(10) = " << v.capacity() << "\n";
    v.shrink_to_fit();                   // extra jagah hata di
    cout << "Capacity after shrink_to_fit() = " << v.capacity() << "\n";
}

// ---------- SOLUTION TASK 6 ----------
void task6() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n > 5) {
        cout << "Warning: n(" << n << ") > 5 cannot fit in int arr[5].\n";
    }

    vector<int> v(n);   // dynamic: n kuch bhi ho, vector sambhal lega
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> v[i];
    }
    cout << "Stored " << n << " numbers in vector: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n(static int arr[5] would have overflowed / become invalid for n>5,\n"
         << " vector grew dynamically so it worked fine.)\n";
}

int main() {
    cout << "===== TASK 1 =====\n"; task1();
    cout << "===== TASK 2 =====\n"; task2();
    cout << "===== TASK 3 =====\n"; task3();
    cout << "===== TASK 4 =====\n"; task4();
    cout << "===== TASK 5 =====\n"; task5();
    cout << "===== TASK 6 =====\n"; task6();
    return 0;
}