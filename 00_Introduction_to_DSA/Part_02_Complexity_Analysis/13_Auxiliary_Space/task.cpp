/*
═══════════════════════════════════════════════
  TASK SET — AUXILIARY SPACE
  (Input vs Auxiliary vs Total Space)
═══════════════════════════════════════════════

  🌍 REAL-WORLD SCENARIO:
    Every catering plan has two bills: the chairs the guests already occupy
    (input space) and the extra plates/notes/scratch-tables the recipe forces
    you to haul in (auxiliary space). In interviews, "find the auxiliary
    space of this snippet" is the classic follow-up question, because it is
    easy to confuse the memory you were given with the memory you created.

  🧠 HOW TO SOLVE:
    Step A — Input: kata hua array/vector kitni slots deta hai? (n slots)
    Step B — Auxiliary: function ke andar naya kya bana? (arrays, maps,
             recursion stack) → bas use count karo.
    Step C — Recursion: depth = ek waqt ki max frames (total calls nahi).
    Step D — Total = Input + Auxiliary; sab ko growth-class me batao.

  TASKS (EASY → HARD):

  ── TASK 1 [EASY] ─────────────────────────────────────────────
    swap(a, b) me do integers a aur b ko ek temp variable se swap kiya
    jata hai. Iski AUXILIARY space kya hai? Code likho aur derivation do.
    💡 HINT: temp sirf 1 slot leta hai — n par nirbhar nahi.
    ✏️ STARTER CODE:
      #include <iostream>
      using namespace std;
      void swapIt(int& a, int& b) {
          // TODO: temp variable se swap karo
      }
      int main() {
          int a = 5, b = 9;
          // TODO: swapIt call karke print karo
          return 0;
      }

  ── TASK 2 [EASY] ─────────────────────────────────────────────
    Iterative sum (for-loop) vs Recursive sum — dono ka auxiliary space
    batayo aur code likho. Input = n-slots array hai dono me.
    💡 HINT: iterative me sirf 'sum' variable; recursive me n stack frames.
    ✏️ STARTER CODE:
      int iterativeSum(int arr[], int n) {
          int sum = 0;
          // TODO: for-loop se sum nikaalo
          return sum;
      }
      int recursiveSum(int arr[], int n) {
          // TODO: base case 0, warna arr[n-1] + recursiveSum(arr, n-1)
      }

  ── TASK 3 [MEDIUM] ───────────────────────────────────────────
    Array reverse ke DO tareeke: (a) in-place — first/last swap, (b) nayi
    ulti array banana. Har tareeke ki input / aux / total space nikaalo.
    Dono code likho aur accounting print karo.
    💡 HINT: (a) sirf temp + i,j → aux O(1); (b) new int[n] → aux O(n).
    ✏️ STARTER CODE:
      void reverseInPlace(int arr[], int n) {
          // TODO: i=0, j=n-1; swap(arr[i], arr[j]); i++, j--
      }
      int* reverseNewArray(int arr[], int n) {
          // TODO: new int[n] banana, ulta fill karna
      }

  ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    In teeno ka auxiliary class batayo aur thoda code ka tukda likho:
      (a) palindrome check — do pointers (i, j) ek hi array par
      (b) frequency array banana (count[something]) — n size ka
      (c) n×n matrix banana — 2D n² cells
    💡 HINT: (a) O(1), (b) O(n), (c) O(n²).
    ✏️ STARTER CODE:
      int main() {
          // (a) char arr[]; int i=0, j=n-1;  // sirf 2 variables
          // (b) int freq[256]; for each char freq[c]++;
          // (c) int** mat = new int*[n]; for(int i=0;i<n;i++) mat[i]=new int[n];
          return 0;
      }

  ── TASK 5 [MEDIUM-HARD] ──────────────────────────────────────
    Recursive power(x, n): if n==0 return 1; if n even → p=power(x,n/2),
    return p*p; else return x*power(x,n/2). Iski auxiliary space kya hai?
    Code likho. NOTE: depth sirf log2(n) hai — n/2 hota jaata hai.
    💡 HINT: depth = log₂n → stack frames = log₂n → aux = O(log n).
    ✏️ STARTER CODE:
      long long power(long long x, int n) {
          // TODO: n==0 -> 1
          // TODO: p = power(x, n/2); even -> p*p, odd -> x*p*p
      }

  ── TASK 6 [HARD] ─────────────────────────────────────────────
    Subarray sum queries: brute approach har query me loop chalaata hai
    (aux O(1), time O(n) per query). Prefix-sum approach pehle ek n-slots-
    wala prefix array banata hai (aux O(n)) phir har query O(1) me answer
    deta hai. Dono ka accounting table banake print karo (given arr + q
    queries). Code likho jo dono approaches ka input/aux/total dikhaye.
    💡 HINT: prefix[i] = prefix[i-1] + arr[i]; query(l,r) = prefix[r]-prefix[l-1].
    ✏️ STARTER CODE:
      #include <iostream>
      using namespace std;
      int bruteQuery(int arr[], int n, int l, int r) {
          int s = 0;
          // TODO: l..r tak loop karke sum
          return s;
      }
      int* buildPrefix(int arr[], int n) {
          // TODO: n size ka prefix array
      }
 ═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

// ---------------- TASK 1: swap — aux = O(1) ----------------
void swapIt(int& a, int& b) {
    int temp = a;        // 1 hi extra slot — n se koi sambandh nahi
    a = b;
    b = temp;
}

void sol_task1() {
    int a = 5, b = 9;
    cout << "   Swap: a=5, b=9, temp variable se\n";
    cout << "     Auxiliary = 1 int slot = O(1)   (input a,b chhote hi hain)\n";
    swapIt(a, b);
    cout << "     After swap: a=" << a << ", b=" << b << "\n";
    cout << "   DERIVATION: temp ek fixed variable hai; n badhne se kuch\n"
            "   nahi badhta  →  f(n) = 1  →  Auxiliary = O(1)\n\n";
}

// ---------------- TASK 2: iterative vs recursive sum ----------------
int iterativeSum(int arr[], int n) {
    int sum = 0;                 // sirf 1 variable
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int recursiveSum(int arr[], int n) {
    if (n <= 0) return 0;        // base case → frame pop
    return arr[n - 1] + recursiveSum(arr, n - 1);   // n depth ke frames
}

void sol_task2() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "   Iterative sum = " << iterativeSum(arr, n) << "\n";
    cout << "     Auxiliary = O(1): sirf 'sum' + 'i' = 2 fixed slots\n";
    cout << "   Recursive sum = " << recursiveSum(arr, n) << "\n";
    cout << "     Auxiliary = O(n): depth n ke stack frames, koi array nahi\n";
    cout << "   Input (dono me) = n = 5 slots;  Aux: iter O(1) vs recur O(n)\n\n";
}

// ---------------- TASK 3: in-place vs new-array reverse ----------------
void reverseInPlace(int arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {   // i,j,temp hi kaafi
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int* reverseNewArray(int arr[], int n) {
    int* out = new int[n];       // ⚠️ n slots ki nayi array = auxiliary
    for (int i = 0; i < n; i++) out[i] = arr[n - 1 - i];
    return out;
}

void sol_task3() {
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    reverseInPlace(a, n);
    int* out = reverseNewArray(b, n);
    cout << "   (a) In-place  : aux = i,j,temp = 3 slots → O(1), Total = n+3\n";
    cout << "         result: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n   (b) New array : aux = n slots → O(n),     Total = 2n\n";
    cout << "         result: ";
    for (int i = 0; i < n; i++) cout << out[i] << " ";
    cout << "\n   DERIVATION: (a) fixed vars f(n)=3 → O(1);"
            " (b) f(n)=n → O(n)\n\n";
    delete[] out;
}

// ---------------- TASK 4: classify three snippets ----------------
void sol_task4() {
    cout << "   (a) two-pointer palindrome → sirf i,j → Aux = O(1)\n";
    cout << "   (b) frequency array → n size ka count[] → Aux = O(n)\n";
    cout << "   (c) n×n matrix     → n² cells     → Aux = O(n²)\n";
    cout << "   DERIVATION: variables fixed (1), 1D size n (n), "
            "2D size n*n (n²)\n\n";
}

// ---------------- TASK 5: recursive power — aux = O(log n) ----------------
long long power(long long x, int n) {
    if (n == 0) return 1;                 // base case
    long long p = power(x, n / 2);        // har baar n aadha → depth log2(n)
    return (n % 2 == 0) ? p * p : x * p * p;
}

void sol_task5() {
    cout << "   power(2, 10) = " << power(2, 10) << "\n";
    cout << "   Depth chain: n=10 → 5 → 2 → 1 → 0  = 4 frames\n";
    cout << "   Aux = stack depth = log2(10) ≈ 4 → O(log n)\n";
    cout << "   DERIVATION: n/2 har call par → depth = ⌊log2 n⌋ + 1\n"
            "   frames. Total calls taki hoti, par ek waqt me sirf\n"
            "   depth frames hain → Auxiliary = O(log n)\n\n";
}

// ---------------- TASK 6: brute vs prefix-sum -----------------
int bruteQuery(int arr[], int n, int l, int r) {
    int s = 0;                 // O(1) aux, O(r-l+1) time
    for (int i = l; i <= r; i++) s += arr[i];
    return s;
}

int* buildPrefix(int arr[], int n) {
    int* pre = new int[n];     // ⚠️ n slots auxiliary
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + arr[i];
    return pre;
}

int prefixQuery(int pre[], int l, int r) {
    return (l == 0) ? pre[r] : pre[r] - pre[l - 1];   // O(1) answer
}

void sol_task6() {
    int arr[] = {2, 4, 1, 7, 3};
    int n = 5;
    int pre[] = {2, 6, 7, 14, 17};      // build karke runtime me bhi dikhao
    cout << "   Brute  : query(1,3) = " << bruteQuery(arr, n, 1, 3) << "\n";
    cout << "     Aux = O(1), per-query Time = O(r-l+1)\n";
    cout << "   Prefix : query(1,3) = " << prefixQuery(pre, 1, 3) << "\n";
    cout << "     Aux = O(n) (prefix array), per-query Time = O(1)\n";
    cout << "   TABLE:\n";
    cout << "     ┌───────────────────┬────────┬────────┬─────────┐\n";
    cout << "     │ approach          │ input  │  aux   │ time/q  │\n";
    cout << "     ├───────────────────┼────────┼────────┼─────────┤\n";
    cout << "     │ brute             │  n     │  O(1)  │  O(n)   │\n";
    cout << "     │ prefix-sum        │  n     │  O(n)  │  O(1)   │\n";
    cout << "     └───────────────────┴────────┴────────┴─────────┘\n";
    cout << "   DERIVATION: prefix array n slots → aux O(n); har query\n"
            "   1 subtraction → time O(1). Total = n + n = 2n → O(n).\n";
}

int main() {
    cout << "TASK 1:\n"; sol_task1();
    cout << "TASK 2:\n"; sol_task2();
    cout << "TASK 3:\n"; sol_task3();
    cout << "TASK 4:\n"; sol_task4();
    cout << "TASK 5:\n"; sol_task5();
    cout << "TASK 6:\n"; sol_task6();
    return 0;
}