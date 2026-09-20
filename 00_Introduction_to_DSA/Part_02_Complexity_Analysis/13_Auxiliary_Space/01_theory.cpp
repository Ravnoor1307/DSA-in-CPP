/*
═══════════════════════════════════════════════
 AUXILIARY SPACE
 (Space Complexity = Input Space + Auxiliary Space)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    You are catering a dinner party for n guests. The guests themselves (the
    input data) occupy the chairs they sit in, and that space is fixed the
    moment they arrive. But the MENU decides how much EXTRA gear you must
    carry: a recipe that washes and reuses a single plate needs just 1 extra
    plate; a recipe that serves everyone a fresh plate at once needs n extra
    plates; and a "leave-a-note-recursive" recipe keeps one unfinished ticket
    per guest taped on the fridge, so it also needs n tickets. The guests are
    the INPUT — every plate, note, or scratch table the plan forces you to
    bring is AUXILIARY. Space Complexity = what the guests occupy (input) +
    what you must carry (auxiliary). This split is exactly what interviewers
    drill you on.

 📖 THEORY: (pure English, formal)
    - DEFINITION: Auxiliary Space = the extra temporary space an algorithm
      uses BESIDES the given input — helper arrays, hash tables, recursion
      call-stack frames, and temporary variables.
    - Space Complexity = Input Space + Auxiliary Space.
      Formally, if the input occupies S_in(n) and the algorithm needs S_aux(n)
      extra, then Total(n) = S_in(n) + S_aux(n), and the reported class is the
      growth of Total(n) unless only auxiliary space is asked.
    - KEY RULES:
        * The input you are GIVEN is never "extra" — it existed before the call.
        * The OUTPUT the problem asks you to return is usually NOT counted
          either; only the scratch space needed to build it is.
        * Recursion uses auxiliary space = maximum call-STACK DEPTH, not the
          total number of calls (finished frames are freed, so they never
          coexist in memory).
        * Passing a big C++ vector BY VALUE silently copies it → hidden O(n)
          auxiliary space you did not see coming.
    - ASCII — the three buckets fill one memory box:

        ┌──────────────── Total(n) = Input + Auxiliary ────────────────┐
        │  INPUT SPACE          AUXILIARY SPACE                        │
        │  (n slots, given)     (scratch tables, stack, temp vars)     │
        └──────────────────────────────────────────────────────────────┘

    - WHEN TO USE: in every memory analysis, mentally split Total into
      Input + Auxiliary first. The interviewer WILL follow up with
      "...but what is the AUXILIARY space?" — and the correct answer is
      often different from the total.

 🧠 LOGIC — STEP BY STEP: (pure English)
    Step 1: Spot the INPUT. Count the data the caller handed over, e.g. an
            array of n ints (n slots).                  WHY: this memory existed
            before the function ran, so it can never be "extra".
    Step 2: Scan the body for NEW memory: new[]/malloc, containers declared
            inside, and every recursive call (one stack frame each).
                                                         WHY: anything born inside
            the function is memory the algorithm itself demanded = auxiliary.
    Step 3: For recursion, count MAXIMUM simultaneous frames = depth, not all
            calls.                                      WHY: ended frames are
            freed, so they do not pile up at the same moment.
    Step 4: Add them: Total = Input + Auxiliary, then reduce both to growth
            classes.                                    WHY: Big-O reports growth
            with n, not exact bytes.

 VISUAL WALKTHROUGH:
    Three algorithms on the same array of n = 8 ints (1 slot = 4 bytes):

      (1) LINEAR SEARCH          (2) COPY ARRAY            (3) RECURSIVE SUM
      ┌────────────────┐         ┌────────────────┐        ┌────────────────┐
      │ input:     8   │         │ input:     8   │        │ input:     8   │
      │ auxiliary: 1   │         │ auxiliary: 8   │        │ auxiliary: 8   │
      │ TOTAL:     9   │         │ TOTAL:     16  │        │ TOTAL:     16  │
      └────────────────┘         └────────────────┘        └────────────────┘
        aux = O(1)                 aux = O(n)                aux = O(n) stack

    Stack picture for RECURSIVE SUM (n = 4) — depth 4, only 4 frames at once:

       ▓▒░ frame for sum(arr,4) ─┐
       ▓▒░ frame for sum(arr,3) ─┤  depth = 4  →  aux = O(n)
       ▓▒░ frame for sum(arr,2) ─┤  (NOT 4+3+2+1 total calls — they do not
       ▓▒░ frame for sum(arr,1) ─┘   all exist simultaneously)

 DRY RUN:
    LINEAR SEARCH, arr = {7,3,9,4,5}, key = 9, n = 5.
      i=0: arr[0]=7 != 9 → i++        only 'i' exists → 1 auxiliary slot
      i=1: arr[1]=3 != 9 → i++
      i=2: arr[2]=9 == 9 → return 2   (loop exits, 2 is the answer)
      Peak auxiliary at any instant = the loop counter 'i' = 1 slot → O(1).
      Input = 5 slots → Total = 6 slots → O(n) overall (dominated by input).

 TIME COMPLEXITY CALCULATION:
    - linear search: loop runs n times, 1 compare each → f(n) = n          → O(n)
    - copy array   : loop runs n times, 1 copy each      → f(n) = n        → O(n)
    - recursive sum: n calls, 1 addition each            → f(n) = n        → O(n)
    → Time Complexity = O(n) for all three demo functions.

 SPACE COMPLEXITY CALCULATION:
    - linear search: Input = n (given array); Auxiliary = 1 (loop var 'i')
      Total = n + 1 → O(n) as a whole, but AUX = O(1) exactly.
    - copy array   : Input = n; Auxiliary = n (the fresh n-slot copy)
      Total = 2n → O(n); AUX = O(n).
    - recursive sum: Input = n; Auxiliary = n (stack-depth n; each frame holds
      return address + params ≈ a constant number of slots).
      Total = 2n → O(n); AUX = O(n).
      NOTE: no array was allocated, yet auxiliary is still O(n) — the stack!
    → Input Space = O(n); Auxiliary Space = O(1) for search, O(n) for the
      other two; Total Space = O(n) everywhere.

 APPROACH COMPARISON:
    ┌──────────────────────┬─────────────┬─────────────────────────────────────┐
    │ Algorithm            │ Auxiliary   │ Real-world picture                  │
    ├──────────────────────┼─────────────┼─────────────────────────────────────┤
    │ linear search        │ O(1)        │ wash-and-reuse ONE plate            │
    │ iterative sum        │ O(1)        │ running total on one sticky note    │
    │ copy array           │ O(n)        │ lay out n fresh plates at once      │
    │ recursive sum        │ O(n)        │ n unfinished fridge tickets ⚠️      │
    │ merge sort           │ O(n)        │ one n-slot scratch lane             │
    │ quick sort           │ O(log n)    │ tickets only for each split level   │
    └──────────────────────┴─────────────┴─────────────────────────────────────┘
*/
#include <iostream>
using namespace std;

// Linear search — loop me sirf 'i' rehta hai, koi array nahi banti
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {          // 1 extra variable hi hai
        if (arr[i] == key) return i;       // compare + return
    }
    return -1;
}

// Copy array — n size ki nayi array allocate hoti hai (aux = n)
int* copyArray(int arr[], int n) {
    int* copy = new int[n];                // ⚠️ AAA n extra slots khule
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    return copy;
}

// Recursive sum — har call ke liye ek stack frame (aux = depth = n)
int sumRecursive(int arr[], int n) {
    if (n <= 0) return 0;                  // base case → frame hatao
    return arr[n - 1] + sumRecursive(arr, n - 1);   // 1 add + 1 naya frame per call
}

// Accounting printer — input/aux/total ka hisaab dikhata hai
void printAccounting(const char* name, int inputSlots, int auxSlots) {
    int total = inputSlots + auxSlots;     // Total = Input + Aux
    cout << "   " << name << "\n";
    cout << "     Input space     = " << inputSlots << " slots (" << inputSlots * 4 << " B)\n";
    cout << "     Auxiliary space = " << auxSlots << " slots (" << auxSlots * 4 << " B)\n";
    cout << "     TOTAL space     = " << total << " slots (" << total * 4 << " B)\n";
    cout << "     Total = O(n)    , Auxiliary class: "
         << (auxSlots <= 1 ? "O(1)" : "O(n)") << "\n\n";
}

int main() {
    const int n = 8;
    int arr[n];                            // 8 ints se bhar do
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    cout << "n = " << n << "  (1 slot = 1 int = 4 bytes)\n\n";

    cout << "DEMO 1 — LINEAR SEARCH (key 42 absent):\n";
    int found = linearSearch(arr, n, 42);  // -1 milega
    cout << "   result = " << found << "\n";
    printAccounting("linearSearch", n, 1);        // aux = sirf 'i' → O(1)

    cout << "DEMO 2 — COPY ARRAY:\n";
    int* copy = copyArray(arr, n);         // n slots ki nayi array
    printAccounting("copyArray", n, n);           // aux = n → O(n)
    delete[] copy;

    cout << "DEMO 3 — RECURSIVE SUM:\n";
    int s = sumRecursive(arr, n);          // depth n → n stack frames
    cout << "   sum = " << s << "\n";
    printAccounting("sumRecursive", n, n);        // koi array nahi, fir bhi aux = O(n) (stack)

    cout << "WHAT COUNTS AS AUXILIARY?\n";
    cout << "   [OK ] nayi array / vector / hash-table banayi\n";
    cout << "   [OK ] recursion call-stack (depth = ek waqt ke frames)\n";
    cout << "   [OK ] helper variables joh function ke andar khule\n";
    cout << "   [NO ] given input array (wo pehle se thi)\n";
    cout << "   [NO ] output jo problem ne return karne ko kaha\n";
    return 0;
}