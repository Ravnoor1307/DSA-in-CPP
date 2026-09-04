/*
=======================================================================
 THEORY : Complexity Analysis (Time & Space) - DETAILED
=======================================================================
 Complexity analysis measures HOW FAST (time) and HOW MUCH MEMORY
 (space) an algorithm runs as the input size (n) grows. It is the
 MOST important topic in DSA: it tells us which solution will finish
 inside a time limit for large inputs, and which one will hang.

 ---------------------------------------------------------------------
 1. WHY IT MATTERS
    - Rule of thumb: a laptop executes roughly 1e8 (100 million)
      simple operations per second.
    - If n = 1e5 (100000):
        O(n)       -> ~1e5 ops        => instant
        O(n log n) -> ~1.7e6 ops      => fast
        O(n^2)     -> ~1e10 ops       => ~100 seconds (too slow!)
        O(2^n)     -> physically impossible (way more ops than
                       atoms in the universe for n=100)
    So the CHOICE OF ALGORITHM is usually forced by the input size
    given in the problem constraints.

 ---------------------------------------------------------------------
 2. WHAT EXACTLY DO WE COUNT?
    - A "basic operation" = an addition, comparison, assignment,
      array access etc. (any constant-time work).
    - The cost of an algorithm is a FUNCTION of n, written T(n).
    - We only care about the GROWTH RATE of T(n), not the exact
      number. That is what asymptotic analysis gives us.

 ---------------------------------------------------------------------
 3. THE ASYMPTOTIC NOTATIONS (the precise definitions)
    Formal definition with two constants: a scaling constant c and a
    threshold n0 (the point after which the bound "always" holds).

    a) BIG-O   : UPPER bound  -> f(n) <= c*g(n) for all n >= n0
                 "grows at most as fast as"   -> used for WORST case
       Example : f(n) = 3n^2 + 5n + 7  is O(n^2)
                 because 3n^2 + 5n + 7 <= 4n^2 when n >= 5.

    b) BIG-OMEGA (fancy O): LOWER bound -> f(n) >= c*g(n) for n >= n0
                 "grows at least as fast as" -> used for BEST case

    c) BIG-THETA (theta): TIGHT bound -> both O and Omega hold
                 "grows exactly as fast as" -> most precise statement

    d) little-o and little-omega : STRICT bounds (the < and > of
                 asymptotics; used in higher math, rarely in coding).

    In competitive programming we almost always talk about BIG-O of
    the WORST case, because that is what guarantees our program will
    pass the time limit.

 ---------------------------------------------------------------------
 4. GROWTH RATES - COMPARISON TABLE (n = 10 and n = 100)
    Notation     Name        Sub-steps for n=10     n=100
    ------------ ----------- ---------------------- ------------
    O(1)         constant    1                      1
    O(log n)     logarithmic ~3                     ~7
    O(sqrt n)    root        ~3                     ~10
    O(n)         linear      10                     100
    O(n log n)   linearithmic ~33                    ~664
    O(n^2)       quadratic   100                    10,000
    O(n^3)       cubic       1,000                  1,000,000
    O(2^n)       exponential 1,024                  impossible
    O(n!)        factorial   3,628,800              impossible

    Visual ranking (slowest growth <-> fastest growth):
    O(1) < O(log n) < O(sqrt n) < O(n) < O(n log n)
         < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)

 ---------------------------------------------------------------------
 5. RULES FOR READING BIG-O FROM CODE
    a) Drop constants:             3n      -> O(n)
       Even 100*n is O(n): linear growth stays linear.
    b) Drop lower-order terms:     n^2 + n -> O(n^2)
       The biggest term dominates for large n.
    c) Sequential blocks ADD:      O(n) then O(n^2) -> O(n^2)
       (keep only the largest of the sums)
    d) Nested loops MULTIPLY:      outer n * inner n -> O(n^2)
    e) A loop variable that HALVES each step: O(log n)
    f) A loop variable that DOUBLES each step: O(log n)

 ---------------------------------------------------------------------
 6. ANALYSING LOOPS - WORKED EXAMPLES (memorise these!)
    a) for (i=0; i<n; i++)            -> n iterations         O(n)
    b) for (i=0; i<n; i+=2)           -> n/2 iterations       O(n)
       (drop the constant 1/2)
    c) for (i=n; i>0; i/=2)           -> log2(n) iterations   O(log n)
    d) for (i=1; i<n; i*=2)           -> log2(n) iterations   O(log n)
    e) for (i=1; i*i<=n; i++)         -> sqrt(n) iterations   O(sqrt n)
    f) outer n AND inner n (same var
       or two independent vars)       -> n * n                O(n^2)
    g) outer n, inner runs i+1 times
       (triangular)                   -> n(n+1)/2 ~ n^2/2     O(n^2)
    h) while (n > 0) { some O(1) work; n /= 2; }   -> O(log n)
    i) loop halves n STEPS in outer
       loop, inner always runs n      -> n log n              O(n log n)

    Actually COUNT and THINK (don't just plug formulas):
       for (int i = 0; i < n; i++)
         for (int j = 0; j * j < n; j++)   // inner is sqrt(n)
            ...                            => n * sqrt(n) = O(n^1.5)

 ---------------------------------------------------------------------
 7. ANALYSING RECURSION (recurrence relations)
    Write T(n) for the cost, then solve:
      T(n) = T(n/2) + O(1)     -> binary search        -> O(log n)
      T(n) = T(n-1) + O(1)     -> loop-like recursion  -> O(n)
      T(n) = 2T(n/2) + O(n)    -> merge sort           -> O(n log n)
      T(n) = T(n-1) + T(n-2)+O(1) -> naive fibonacci   -> O(2^n)
             (use MEMOIZATION to make it O(n))

    MASTER THEOREM (memorise the three main cases):
    Given T(n) = a*T(n/b) + f(n):
      1) f(n) grows slower than n^(log_b a)   -> T(n) = O(n^(log_b a))
      2) f(n) ~ n^(log_b a)                   -> T(n) = O(n^(log_b a)
                                                   * log n)
      3) f(n) grows faster                     -> T(n) = O(f(n))
    Example: merge sort a=2, b=2, f(n)=n -> n^(log_2 2) = n
             case 2 => O(n log n)

 ---------------------------------------------------------------------
 8. SPACE COMPLEXITY - IN DETAIL
    Space = input storage + AUXILIARY space (extra arrays/structures)
            + CALL STACK (frames created by recursion while executing).
    Count the EXTRA memory in terms of n:
        O(1)   extra storage   e.g. swapping, linear search (loop var)
        O(n)   extra storage   e.g. copying array -> another array;
                                   hash map of n keys
        O(log n) stack depth   e.g. recursive binary search
        O(n)   stack depth     e.g. recursion going n levels deep
                                   (factorial, tree height worst case)

    Famous trade-offs:
      - Merge sort: O(n log n) time but uses O(n) auxiliary array.
      - Quick sort: O(n log n) average with only O(log n) stack.
      - Hashing:    spends O(n) space to get O(1) average lookups.
      - 2 pointers / sliding window: O(1) extra space - interview
        favourite because space is precious too.

 ---------------------------------------------------------------------
 9. AMORTIZED COMPLEXITY (average cost per operation, long run)
    Some single operations can be costly, yet over a long sequence
    the AVERAGE cost is small:
      - vector push_back(): when the vector is full it doubles its
        buffer (cost O(n) to copy), but that happens only ~log n
        times; total cost for n insertions is O(n)
        -> each insertion is O(1) AMORTIZED.
    Big reason dynamic arrays are usable inside tight loops.

 ---------------------------------------------------------------------
 10. BEST vs AVERAGE vs WORST CASE (they are NOT the same pattern)
     Example - LINEAR SEARCH:
        Best   : target at position 0   -> O(1)
        Average: target in the middle   -> O(n)
        Worst  : target missing / at end-> O(n)
     Example - QUICK SORT:
        Best/Average O(n log n) | Worst (already-sorted input + bad
        pivot choice) O(n^2).
     Always ask: "which case will the TEST data hit?"
     Usually answer with the WORST case Big-O.

 ---------------------------------------------------------------------
 11. STANDARD TABLES WORTH MEMORISING
     SEARCHING:
        Linear search  : O(1)/O(n)/O(n)   space O(1) [any array]
        Binary search  : O(1)/O(log n)/O(logn) space O(1) [sorted]
     SORTING (n items):
        Selection sort : O(n^2) all cases
        Bubble sort    : O(n)/O(n^2)/O(n^2)
        Insertion sort : O(n)/O(n^2)/O(n^2)
        Merge sort     : O(n log n) all cases   space O(n)
        Quick sort     : O(n log n) avg, O(n^2) worst, space O(log n)

 ---------------------------------------------------------------------
 12. WHEN IS O(n^2) ACCEPTABLE?
     - n <= ~1000  : O(n^2) ~ 1e6 ops  -> fine in 1 second
     - n <= ~10^5  : need O(n) or O(n log n)
     - n <= ~10^8  : need O(n) or O(log n) with small constants
     - n huge      : need O(log n) or O(1) per query (pre-processing)
     Rule of thumb: 1e8 "simple" operations take ~1 second.

 ---------------------------------------------------------------------
 13. THE 3-STEP PROCEDURE TO ANALYSE ANY CODE
       Step 1 : Find the input size variable (usually n or array len).
       Step 2 : Find the DEEPEST nested loop / the dominant operation
                and count how many times it runs in terms of n.
       Step 3 : Reduce to a Big-O expression
                (drop constants + lower terms, keep the largest).

      PRO TIP for interviews: always STATE the complexity of your
      solution before/after coding - interviewers love it.

  ---------------------------------------------------------------------
  14. HOW TO CALCULATE THE COMPLEXITY OF ANY ALGORITHM
      AND DECIDE WHICH APPROACH IS BEST  (THE MOST IMPORTANT SKILL)

      This is the systematic 5-step method used to compare candidate
      approaches and pick the best one for a given problem.

      STEP A - Find the INPUT SIZE VARIABLE(s).
        Identify what n is. Usually the array/vector length, the
        number of rows, or the size of the dataset. If there are two
        independent sizes (e.g. m rows, n cols) you must keep BOTH:
        O(m * n) or O(m + n), etc.

      STEP B - Find the DOMINANT OPERATION.
        The loop (or recursion / function call) that runs the most.
        For each loop, count how many times its body executes in
        terms of n.

      STEP C - Account for NESTING and SEQUENCING.
        - Nested loops MULTIPLY their counts.
        - Sequential (separate) loops ADD, and you keep the largest.
        - Conditionals: analyse the worst branch.
        - Function calls: add their cost multiplied by how many times
          they are called.

      STEP D - REDUCE to Big-O.
        Drop constants, drop lower-order terms, keep the largest
        term. This is the final complexity of that approach.

      STEP E - DECIDE THE BEST APPROACH using the CONSTRAINT.
        Once you have the Big-O of each candidate, compare against
        the input size given by the problem:
            n <= 1000    -> O(n^2) is fine  (~10^6 ops)
            n <= 10^5    -> need O(n) or O(n log n)
            n <= 10^7    -> need O(n) or O(n log n) with small constants
            n <= 10^8    -> need O(n) or O(log n)
            n huge (10^9+)-> need O(log n) or O(1) per query
        Rule of thumb: 10^8 simple ops ~ 1 second.

      EXAMPLE - Applying the method to "Pair Sum".
        n = array length.
        Approach 1 (brute force): 2 nested loops -> n*n = O(n^2).
        Approach 2 (sort + two pointers): sort O(n log n) + O(n) scan,
          keep largest -> O(n log n).
        Approach 3 (hash set): 1 loop, each op O(1) -> O(n) average.
        DECISION: 
          - If n <= 1000, all three pass; brute force is simplest.
          - If n = 10^5, O(n^2) = 10^10 ops = ~100 sec (TLE); must use
            O(n log n) sort+two-pointers or O(n) hash set.
          - If also memory is limited (space O(1) required), choose
            sort + two pointers over hash set (which needs O(n) space).
        The "best" approach is the SIMPLEST one that FITS the limit.

      EXAMPLE - Applying the method to "Majority Element".
        n = array length.
        Approach 1 (brute force): O(n^2).
        Approach 2 (hash map): O(n) time, O(n) space.
        Approach 3 (sort): O(n log n), O(1) space.
        Approach 4 (Moore's voting): O(n) time, O(1) space.
        DECISION: Moore's is optimal on BOTH time and space, so it is
        clearly the best approach for large n.

      EXAMPLE - Applying the method to "Maximum Subarray (Kadane)".
        n = array length.
        Approach 1 (print all subarrays): O(n^3).
        Approach 2 (brute force max sum): O(n^2).
        Approach 3 (Kadane): single pass O(n), O(1) space.
        DECISION: for n = 100000, O(n^2) = 10^10 (TLE); Kadane's O(n)
        is the only fast one -> clearly the best.

      WHY THE 10^8 RULE DECIDES EVERYTHING:
        The whole point of complexity analysis is to answer "will my
        program finish in time?" A laptop does ~10^8 simple ops/sec.
        If your complexity, inserted n, exceeds ~10^8, your solution
        will likely TLE on that platform. So you pick the approach
        whose Big-O keeps total ops under ~10^7 to 10^8.

      SUMMARY - THE DECISION FRAMEWORK:
        1. Write the Big-O (time and space) of EVERY approach.
        2. Find the input size n from the problem constraints.
        3. Estimate total ops = Big-O value at that n.
        4. Reject any approach whose ops clearly exceed 10^8.
        5. Among those that fit, pick the one with the best space OR
           the simplest code (least bug-prone), whichever matters more.
=======================================================================
*/

#include <iostream>
using namespace std;

// O(1) - constant time: direct index access, independent of n
int constant_work(int arr[5], int idx)
{
    return arr[idx];
}

// O(n) - single loop, one pass over n elements
long long linear_work(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        ops++; // runs exactly n times
    return ops;
}

// O(n) !!! - stepping by 2 gives n/2 iterations; drop constant 1/2
long long half_loop_work(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i += 2)
        ops++; // runs n/2 times  -> still O(n)
    return ops;
}

// O(log n) - every step halves the value
long long logarithmic_work(int n)
{
    long long ops = 0;
    while (n > 0)
    {
        n /= 2; // n -> n/2 -> n/4 ... -> 0
        ops++;  // runs ~log2(n) times
    }
    return ops;
}

// O(sqrt(n)) - common in primality-style checks
long long sqrt_bound_work(int n)
{
    long long ops = 0;
    for (int i = 1; i * i <= n; i++)
        ops++; // runs ~sqrt(n) times
    return ops;
}

// O(n^2) - nested loop with independent counters
long long quadratic_work(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ops++; // runs n*n times
    return ops;
}

// O(n^2) !!! - TRIANGULAR loop: inner bound depends on i (j from i+1)
long long triangular_quadratic(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ops++; // runs n*(n-1)/2  -> still O(n^2)
    return ops;
}

// O(n log n) - outer loop halves, inner ALWAYS runs n times
long long n_log_n_work(int n)
{
    long long ops = 0;
    for (int step = n; step > 0; step /= 2) // ~log n rounds
        for (int i = 0; i < n; i++)
            ops++; // n per round  -> n*log n total
    return ops;
}

// O(log n) - binary search halves the search space
int binarySearch(int arr[], int size, int target)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ----------------------------------------------------------------
// DEMO : Choosing the BEST approach by complexity
// Three solutions to "find a target" in a sorted array.
// Count the operations to PROVE which approach is best.
// ----------------------------------------------------------------

// Approach 1 : O(n) linear scan -- 1 nested level, n iterations
long long approach1_ops(int arr[], int n, int target)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
    {
        ops++;
        if (arr[i] == target)
            break;
    }
    return ops; // up to n comparisons
}

// Approach 2 : O(log n) binary search -- halves each step
long long approach2_ops(int arr[], int n, int target)
{
    long long ops = 0;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        ops++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return ops;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ops; // ~log2(n) comparisons
}

// Approach 3 : O(n^2) "check every pair" - imitate inefficient search
long long approach3_ops(int arr[], int n, int target)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ops++;
            if (arr[i] + arr[j] == target) // artificial, just to count
                return ops;
        }
    return ops;
}

// Helper to fill a sorted array of size n
void fillSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i * 2; // 0,2,4,6,...
}

void compareApproaches()
{
    cout << "\n===== DECIDING THE BEST APPROACH BY COMPLEXITY =====" << endl;
    cout << "Finding a target in a SORTED array of size n." << endl;
    cout << "We count actual operations to confirm the Big-O." << endl;

    int sizes[] = {100, 10000, 1000000}; // increasing input sizes
    const char *names[] = {"n=100    ", "n=10000  ", "n=1000000"};

    for (int s = 0; s < 3; s++)
    {
        int n = sizes[s];
        int *arr = new int[n];
        fillSorted(arr, n);
        int target = arr[n - 1]; // worst-ish: target near the end

        long long ops1 = approach1_ops(arr, n, target); // O(n)
        long long ops2 = approach2_ops(arr, n, target); // O(log n)
        long long ops3 = approach3_ops(arr, n, target); // O(n^2)

        cout << names[s]
             << "  Linear O(n)=" << ops1
             << "  Binary O(logn)=" << ops2
             << "  Pairwise O(n^2)=" << ops3
             << "   BEST: " << (ops2 < ops1 ? "Binary search (O(log n))" : "compare")
             << endl;
        delete[] arr;
    }

    cout << "\nConclusion: For large n, O(log n) binary search does"
         << "\nlog2(n) ops while O(n) linear does n and O(n^2) does n^2."
         << "\nAt n=1,000,000: log2 ~ 20, linear = 1,000,000,"
         << "\npairwise = ~10^12 (impossible). So the best approach"
         << "\nis the one with the smallest growth rate that fits." << endl;
}

int main()
{
    // Quick complexity demonstrations (operation counts are printed)
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "O(1)       arr[2]              -> " << constant_work(arr, 2) << endl;
    cout << "O(n)       full loop  n=1000   -> " << linear_work(1000) << endl;
    cout << "O(n)       half loop  n=1000   -> " << half_loop_work(1000) << endl;
    cout << "O(log n)   halve 2^20          -> " << logarithmic_work(1048576) << endl;
    cout << "O(sqrt n)  n=1000              -> " << sqrt_bound_work(1000) << endl;
    cout << "O(n^2)     square     n=1000   -> " << quadratic_work(1000) << endl;
    cout << "O(n^2)     triangular n=1000   -> " << triangular_quadratic(1000) << endl;
    cout << "O(n log n) n=1024              -> " << n_log_n_work(1024) << endl;

    // Sorted array required for binary search
    int sorted[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << "O(log n)   binary search 7     -> index "
         << binarySearch(sorted, 8, 7) << endl;

    // Compare approaches to pick the best one
    compareApproaches();

    return 0;
}