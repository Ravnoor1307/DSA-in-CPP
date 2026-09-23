/*
═══════════════════════════════════════════════
 TASK SET — REFERENCES
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A car workshop has a customer register. Two
    mechanics edit the SAME paper file (one register, two pens). Whatever
    one writes, the other instantly sees — no photocopy, no separate copy.
    That is pass-by-reference: functions work on the caller's real data.
    When you only need to VIEW the register, you still share it but with
    a "const" promise — read-only, no modifications allowed.

 🧠 HOW TO SOLVE: Decide first — do we need to modify the caller's
    variable? If YES → pass int &x (reference). If NO → pass const int &x.
    Swapping = 3 assignments with a temp. Rotation = chain of assignments.
    Reference binding is at declaration time (int &ref = target), and
    after that, using ref is identical to using the target variable.

 MODES/TOPICS COVERED:
  1. Swap two variables by reference
  2. Swap two pairs simultaneously
  3. Left rotate three values by reference
  4. Increment the smaller, decrement the bigger
  5. Find the minimum and maximum using two reference outputs
  6. Find the largest and second largest via references
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════
// TASK 1: Swap two ints via references
// ═══════════════════════════════════════════
void swapRef(int &a, int &b) {
    int temp = a;   // a ki value backup me
    a = b;          // ab caller ka pahla variable b ban gaya
    b = temp;       // caller ka dusra variable purana a
}

// ═══════════════════════════════════════════
// TASK 2: Swap two pairs simultaneously
// ═══════════════════════════════════════════
void swapPairs(int &a, int &b, int &c, int &d) {
    // (a,b) swap
    int temp1 = a;
    a = b;
    b = temp1;
    // (c,d) swap
    int temp2 = c;
    c = d;
    d = temp2;
    // chaaron caller variable change ho gaye
}

// ═══════════════════════════════════════════
// TASK 3: Left rotate (a,b,c) -> (b,c,a)
// ═══════════════════════════════════════════
void rotateLeft(int &a, int &b, int &c) {
    int temp = a;   // a backup karo
    a = b;          // a ko b mila
    b = c;          // b ko c mila
    c = temp;       // c ko purana a mila
}

// ═══════════════════════════════════════════
// TASK 4: adjust x,y based on comparison
// ═══════════════════════════════════════════
void adjust(int &x, int &y) {
    if (x < y) {
        x++;   // chhota badhao
        y--;   // bada ghatiao
    } else {
        y++;   // warna ulta
        x--;
    }
    // directly caller ke variables pe asar
}

// ═══════════════════════════════════════════
// TASK 5: min and max via output references
// ═══════════════════════════════════════════
void minMax(int arr[], int n, int &mn, int &mx) {
    mn = arr[0];   // pahle element ko hi shuruaat maano
    mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) mn = arr[i];   // naya chhota mila
        if (arr[i] > mx) mx = arr[i];   // naya bada mila
    }
    // mn aur mx caller ke variables me LIVE update hue
}

// ═══════════════════════════════════════════
// TASK 6: largest and second largest via references
// ═══════════════════════════════════════════
void multMax(int arr[], int n, int &max1, int &max2) {
    max1 = arr[0];
    max2 = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;        // purana sabse bada ab second hai
            max1 = arr[i];      // naya sabse bada
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];      // second position update
        }
    }
}

int main() {
    cout << "=== TASK 1: Swap ===" << endl;
    int x = 10, y = 20;
    cout << "Before: x=" << x << ", y=" << y << endl;
    swapRef(x, y);
    cout << "After:  x=" << x << ", y=" << y << "   (expect 20, 10)\n" << endl;

    cout << "=== TASK 2: Swap Two Pairs ===" << endl;
    int a = 1, b = 2, c = 3, d = 4;
    cout << "Before: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    swapPairs(a, b, c, d);
    cout << "After:  a=" << a << " b=" << b << " c=" << c << " d=" << d << "   (expect 2 1 4 3)\n" << endl;

    cout << "=== TASK 3: Rotate Left ===" << endl;
    int p = 7, q = 8, r = 9;
    cout << "Before: p=" << p << " q=" << q << " r=" << r << endl;
    rotateLeft(p, q, r);
    cout << "After:  p=" << p << " q=" << q << " r=" << r << "   (expect 8 9 7)\n" << endl;

    cout << "=== TASK 4: Adjust ===" << endl;
    int m = 5, n = 9;
    cout << "Before: m=" << m << " n=" << n << "   (m < n so m++, n--)" << endl;
    adjust(m, n);
    cout << "After:  m=" << m << " n=" << n << "   (expect 6 8)\n" << endl;

    cout << "=== TASK 5: Min & Max ===" << endl;
    int arr[] = {3, 9, 2, 7, 5};
    int mn = 0, mx = 0;
    minMax(arr, 5, mn, mx);
    cout << "Array: 3 9 2 7 5 -> min=" << mn << " max=" << mx << "   (expect 2 9)\n" << endl;

    cout << "=== TASK 6: Two Largest ===" << endl;
    int max1 = 0, max2 = 0;
    multMax(arr, 5, max1, max2);
    cout << "Array: 3 9 2 7 5 -> max1=" << max1 << " max2=" << max2 << "   (expect 9 7)" << endl;

    return 0;
}