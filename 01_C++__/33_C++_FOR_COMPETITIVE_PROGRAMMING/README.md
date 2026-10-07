# 33 — C++ for Competitive Programming

## Learning goals

This lesson turns the C++ foundation from the previous 32 folders into
a practical problem-solving toolkit.

By the end, you should understand:

- a clean competitive-programming program structure
- fast input/output
- `ios::sync_with_stdio(false)`
- `cin.tie(nullptr)`
- multiple test cases
- choosing integer types
- signed integer overflow dangers
- `long long`
- safe multiplication
- floating-point precision
- `fixed` and `setprecision`
- useful type aliases
- concise but readable STL usage
- sorting and reversing
- frequency counting
- min/max operations
- binary-search helpers
- prefix-processing habits
- common mathematical helpers
- avoiding unnecessary copies
- input constraints and complexity budgets
- choosing algorithms from constraints
- indexing conventions
- sentinel values
- debugging techniques
- assertions
- local debugging versus judge output
- avoiding undefined behavior
- implementation hygiene
- edge-case checklists
- why `#include <bits/stdc++.h>` is common but non-standard
- a practical contest workflow

A dedicated competitive-programming section appears much later in the
roadmap. This lesson teaches the C++ habits needed before beginning DSA.

---

## 1. Competitive programming is not a different C++

The language is the same C++17 you have been learning.

What changes is the environment.

Typical contest conditions involve:

```text
strict time limits
strict memory limits
exact input/output format
many test cases
large constraints
short implementation time
hidden tests
```

Therefore good contest code emphasizes:

```text
correctness
complexity
reliable implementation
fast enough I/O
careful arithmetic
edge cases
```

---

## 2. A basic contest program

A common structure is:

```cpp
#include <iostream>

using namespace std;

void solve() {
    // solve one test case
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
```

Not every problem has multiple test cases, but this pattern is worth
recognizing.

---

## 3. Real-world analogy

Think of a contest program as an assembly line.

Input arrives in a specific format.

Your program must:

```text
read
transform
produce exact output
```

Correctness is not only about the algorithm.

If your algorithm is correct but the program:

- overflows
- reads the wrong number of values
- prints extra text
- uses an O(n²) solution for n = 200000

the submission can still fail.

Competitive programming therefore combines algorithmic reasoning with
implementation discipline.

---

# Part I — Fast Input and Output

## 4. Standard streams

You already know:

```cpp
cin
cout
```

For many problems they are fast enough, especially with standard
competitive-programming configuration.

At the beginning of `main()`:

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

is common.

---

## 5. `ios::sync_with_stdio(false)`

By default, C++ iostreams are synchronized with corresponding C stdio
facilities.

This helps when mixing:

```text
cin/cout
scanf/printf
```

Disabling synchronization can improve iostream performance:

```cpp
ios::sync_with_stdio(false);
```

After disabling synchronization, do not casually mix C and C++ stream
I/O while assuming their relative buffering behavior remains the same.

A simple contest rule is:

```text
Use cin/cout consistently.
```

---

## 6. `cin.tie(nullptr)`

`cin` is normally tied to `cout`, which helps ensure pending output is
flushed before input operations when appropriate.

In non-interactive batch problems, this automatic flushing is often
unnecessary.

```cpp
cin.tie(nullptr);
```

removes that tie.

This can reduce I/O overhead.

---

## 7. `'\n'` versus `endl`

Both can create a newline, but:

```cpp
endl
```

also flushes the output stream.

Frequent flushing can be unnecessarily expensive.

In ordinary batch contest output prefer:

```cpp
cout << answer << '\n';
```

Use explicit flushing when the problem actually requires it, such as
certain interactive protocols.

---

## 8. Interactive problems are different

In an interactive problem, your program communicates with a judge while
running.

Then flushing can be essential:

```cpp
cout << query << endl;
```

or:

```cpp
cout << query << '\n' << flush;
```

Do not mechanically remove flushing from interactive solutions.

Always follow the problem's interaction protocol.

---

# Part II — Test Cases

## 9. Multiple test cases

Input may look like:

```text
3
5
1 2 3 4 5
3
10 20 30
1
7
```

The first integer says:

```text
3 test cases
```

A common structure:

```cpp
int t;
cin >> t;

while (t--) {
    solve();
}
```

Keep each test case's state isolated.

---

## 10. Reset per-test state

A common bug:

```cpp
vector<int> values;

while (t--) {
    // accidentally reuse previous test's values
}
```

Prefer state inside `solve()` where possible:

```cpp
void solve() {
    vector<int> values;
}
```

Then each function call creates fresh local state.

This reduces accidental leakage between test cases.

---

# Part III — Integer Types and Overflow

## 11. `int` is not infinitely large

A typical 32-bit `int` has a maximum near:

```text
2.147 * 10^9
```

Do not rely on the exact width when portable type width matters, but
competitive-programming platforms commonly use 32-bit `int`.

Suppose:

```text
n <= 200000
a[i] <= 1000000000
```

A sum can reach roughly:

```text
200000 * 1000000000
= 200000000000000
= 2 * 10^14
```

That does not fit in 32-bit `int`.

Use `long long`.

---

## 12. Constraint-based type selection

Always estimate the maximum magnitude.

Example:

```text
n <= 100000
a[i] <= 1000000000
```

Worst-case sum:

```text
10^5 * 10^9
= 10^14
```

Therefore:

```cpp
long long sum = 0;
```

is appropriate.

This calculation should happen before coding.

---

## 13. Signed integer overflow

Overflow of signed integer arithmetic beyond the representable range
causes undefined behavior in C++.

Do not assume signed overflow safely wraps around.

Example danger:

```cpp
int a = 1000000000;
int b = 1000000000;

int product = a * b;
```

The mathematical result:

```text
10^18
```

cannot fit in typical 32-bit `int`.

---

## 14. Assigning to `long long` may be too late

This is a famous trap:

```cpp
int a = 1000000000;
int b = 1000000000;

long long product = a * b;
```

The multiplication happens using `int` operands first.

Only afterward would the result be converted to `long long`.

But overflow may already have occurred.

Correct:

```cpp
long long product =
    1LL * a * b;
```

Now the arithmetic is promoted appropriately before the dangerous
multiplication.

---

## 15. Dry run: safe multiplication

Given:

```text
a = 1,000,000,000
b = 1,000,000,000
```

Expression:

```cpp
1LL * a * b
```

Step 1:

```text
1LL is long long
```

Step 2:

```text
1LL * a
```

is computed in a sufficiently wide integer type.

Step 3:

```text
result * b
```

also uses that wide type.

Final mathematical value:

```text
1,000,000,000,000,000,000
```

which fits in typical signed 64-bit `long long`.

---

## 16. `long long` also has limits

Typical signed 64-bit range is approximately:

```text
-9.22 * 10^18 to +9.22 * 10^18
```

It is not arbitrary precision.

For example:

```text
10^12 * 10^12 = 10^24
```

does not fit in 64-bit signed integer.

Later modular arithmetic, overflow-safe multiplication techniques, and
problem-specific representations become important.

---

## 17. `size_t` and signed/unsigned issues

Container sizes commonly use an unsigned size type:

```cpp
values.size()
```

Comparing it carelessly with negative signed integers can create
warnings or subtle bugs.

Beginner contest code often uses:

```cpp
int n;
```

for problem sizes known to fit in `int`, and indexes with an `int`.

For generic production code, type choices require more care.

Do not silence signed/unsigned warnings without understanding them.

---

# Part IV — Floating Point

## 18. Floating-point values are approximate

Many decimal fractions cannot be represented exactly in binary
floating point.

Therefore:

```cpp
double a = 0.1 + 0.2;
double b = 0.3;
```

Direct equality may not behave as mathematically expected.

When tolerance-based comparison is appropriate:

```cpp
abs(a - b) < epsilon
```

may be used.

The correct epsilon depends on the problem's scale and requirements.

---

## 19. Output precision

Use:

```cpp
#include <iomanip>
```

Then:

```cpp
cout << fixed
     << setprecision(6)
     << value;
```

For:

```text
3.1415926535
```

this prints six digits after the decimal:

```text
3.141593
```

Read the judge's required error tolerance carefully.

---

## 20. Avoid floating point when exact integers work

If a problem asks whether:

```text
a / b == c / d
```

cross multiplication may sometimes avoid floating-point comparison:

```text
a * d == c * b
```

but multiplication itself may overflow.

Type range analysis remains necessary.

Do not automatically introduce `double` when exact integer arithmetic is
available.

---

# Part V — Useful Aliases

## 21. Type aliases

C++ supports:

```cpp
using ll = long long;
```

Then:

```cpp
ll answer = 0;
```

You may also encounter:

```cpp
typedef long long ll;
```

Modern C++ generally prefers `using`.

---

## 22. Do not over-abbreviate

Contest code often becomes unreadable through excessive aliases.

Good:

```cpp
using ll = long long;
using pii = pair<int, int>;
```

Potentially confusing:

```cpp
using vvi = vector<vector<int>>;
using vvpll = ...
```

Use abbreviations when they genuinely improve speed and readability.

---

# Part VI — `bits/stdc++.h`

## 23. What is it?

Competitive programmers using GCC often write:

```cpp
#include <bits/stdc++.h>
```

This includes a large collection of standard-library headers through a
GCC-specific convenience header.

Advantages:

- quick contest setup
- fewer missing-header mistakes

Disadvantages:

- non-standard
- not portable to all C++ implementations
- increases preprocessing/compile work

---

## 24. Repository recommendation

For learning, prefer explicit standard headers:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
```

This teaches where facilities come from.

For a GCC-based contest where `bits/stdc++.h` is supported, using it is
a common practical choice.

Know the difference between:

```text
standard C++ feature
```

and:

```text
compiler-specific contest convenience
```

---

# Part VII — Useful STL Contest Patterns

## 25. Read a vector

Typical:

```cpp
int n;
cin >> n;

vector<int> a(n);

for (int& value : a) {
    cin >> value;
}
```

If values can be large:

```cpp
vector<long long> a(n);
```

---

## 26. Sort ascending

```cpp
sort(a.begin(), a.end());
```

Complexity:

```text
O(n log n)
```

---

## 27. Sort descending

```cpp
sort(
    a.begin(),
    a.end(),
    greater<int>()
);
```

or:

```cpp
sort(
    a.begin(),
    a.end(),
    [](int x, int y) {
        return x > y;
    }
);
```

For simple built-in descending order, `greater<int>` is concise.

---

## 28. Reverse

```cpp
reverse(
    a.begin(),
    a.end()
);
```

Time:

```text
O(n)
```

---

## 29. Minimum and maximum

If the range is non-empty:

```cpp
int minimum =
    *min_element(a.begin(), a.end());

int maximum =
    *max_element(a.begin(), a.end());
```

Dereferencing the returned iterator for an empty range is invalid.

Always understand whether the constraints guarantee non-empty input.

---

## 30. Sum

```cpp
long long sum = accumulate(
    a.begin(),
    a.end(),
    0LL
);
```

Why:

```cpp
0LL
```

?

Because the accumulator type is influenced by the initial value.

Using:

```cpp
0
```

can cause accumulation using `int`, potentially overflowing even if
you assign the final result to `long long`.

This is an important contest trap.

---

## 31. Dry run: accumulate type

Values:

```text
[1,000,000,000,
 1,000,000,000,
 1,000,000,000]
```

Using:

```cpp
accumulate(..., 0LL)
```

initial state:

```text
sum type = long long
sum = 0
```

Steps:

```text
0 + 1e9 = 1e9
1e9 + 1e9 = 2e9
2e9 + 1e9 = 3e9
```

No 32-bit accumulator overflow.

---

## 32. Frequency map

Hash frequency:

```cpp
unordered_map<int, int> frequency;

for (int value : a) {
    ++frequency[value];
}
```

Ordered frequency:

```cpp
map<int, int> frequency;
```

Choose based on whether sorted key order matters.

---

## 33. Frequency array

If constraints say:

```text
0 <= a[i] <= 1000
```

you may not need a hash map.

Use:

```cpp
vector<int> frequency(1001);

for (int value : a) {
    ++frequency[value];
}
```

This can be simple and efficient.

Constraint information should influence data-structure choice.

---

## 34. Remove duplicates after sorting

Pattern:

```cpp
sort(a.begin(), a.end());

a.erase(
    unique(a.begin(), a.end()),
    a.end()
);
```

Important:

```cpp
unique
```

does not itself shrink the vector.

It rearranges the range and returns the new logical end.

`erase` removes the remaining tail.

---

## 35. Binary search

For sorted `a`:

```cpp
bool exists =
    binary_search(
        a.begin(),
        a.end(),
        target
    );
```

Or:

```cpp
auto it =
    lower_bound(
        a.begin(),
        a.end(),
        target
    );
```

Check exact existence:

```cpp
if (
    it != a.end()
    && *it == target
) {
    // found
}
```

---

## 36. Count occurrences in sorted data

For sorted vector:

```cpp
auto first =
    lower_bound(a.begin(), a.end(), x);

auto afterLast =
    upper_bound(a.begin(), a.end(), x);

auto count =
    afterLast - first;
```

For random-access iterators such as vector's, subtraction gives the
distance directly.

---

## 37. Pair sorting

Pairs use lexicographical ordering by default:

```cpp
pair<int, int>
```

compares:

```text
first
then second if first values tie
```

This is convenient for:

```text
(interval start, end)
(distance, node)
(value, index)
```

Understand the default before writing custom comparators.

---

# Part VIII — Constraints Drive Complexity

## 38. Start with constraints

Before designing an algorithm, inspect:

```text
n
value ranges
number of test cases
memory limit
time limit
```

Constraints often tell you which complexities are plausible.

---

## 39. Rough complexity intuition

These are approximate contest heuristics, not mathematical guarantees:

```text
n <= 20
-> exponential methods may be possible

n <= 100
-> O(n^3) may sometimes be possible

n <= 1000
-> O(n^2) may be possible

n <= 100000 or 200000
-> usually seek O(n log n) or O(n)

n around 10^6
-> usually close to O(n) or O(n log n) with careful constants
```

Actual feasibility depends on:

- language
- operation cost
- time limit
- hardware
- number of test cases
- memory behavior

Do not memorize these as rigid laws.

---

## 40. Total constraints matter

Suppose:

```text
t <= 10000
n <= 200000
```

That looks enormous.

But the statement may also guarantee:

```text
sum of n over all test cases <= 200000
```

Then O(n log n) per test case may be perfectly reasonable because the
total processed input is bounded.

Always read aggregate constraints.

---

## 41. Dry run: complexity selection

Suppose:

```text
n <= 200000
```

Candidate A:

```text
two nested full loops
O(n²)
```

Approximate operations:

```text
(2 * 10^5)^2
= 4 * 10^10
```

Likely far too large.

Candidate B:

```text
sort + linear scan
O(n log n)
```

Rough scale:

```text
2 * 10^5 * about 18
```

Only a few million comparison-scale operations.

Constraint analysis points strongly toward B.

---

# Part IX — Memory Constraints

## 42. Space matters too

Suppose:

```text
n = 10^7
```

An array of ten million `int` values on a common system is roughly:

```text
40 MB
```

because `int` is commonly four bytes.

Two or three such arrays may exceed a small memory limit.

Always estimate memory for large constraints.

Use `sizeof` when exact implementation size matters.

---

## 43. Stack versus heap for large arrays

This local declaration:

```cpp
int a[10000000];
```

may exceed the program's stack limit.

A dynamic container:

```cpp
vector<int> a(10000000);
```

stores its element buffer dynamically.

This does not mean vector has unlimited memory; it simply avoids placing
the large element buffer as one automatic stack array.

---

## 44. Avoid copying large containers

Bad when copying is unnecessary:

```cpp
long long sum(vector<int> values);
```

This copies the vector.

Prefer:

```cpp
long long sum(
    const vector<int>& values
);
```

for read-only access.

For modification:

```cpp
void normalize(
    vector<int>& values
);
```

Move semantics can also make intentional transfers efficient.

---

# Part X — Indexing and Boundaries

## 45. Zero-based indexing

Most C++ containers use:

```text
0 ... n - 1
```

Contest statements may label objects:

```text
1 ... n
```

Decide whether to:

```text
keep 1-based representation
```

or convert to:

```text
0-based representation
```

and remain consistent.

---

## 46. Common off-by-one bug

For vector size `n`:

```cpp
for (int i = 0; i <= n; ++i)
```

accessing:

```cpp
a[i]
```

is wrong at:

```text
i = n
```

The last valid index is:

```text
n - 1
```

Correct:

```cpp
for (int i = 0; i < n; ++i)
```

---

## 47. Half-open intervals

A powerful convention is:

```text
[l, r)
```

meaning:

```text
l included
r excluded
```

Length:

```text
r - l
```

Empty interval:

```text
l == r
```

This aligns with STL ranges:

```cpp
begin
end
```

and reduces many boundary problems.

---

# Part XI — Sentinel Values

## 48. Sentinel idea

Sometimes an algorithm initializes:

```cpp
long long answer = veryLargeValue;
```

For example:

```cpp
const long long INF =
    4'000'000'000'000'000'000LL;
```

But arithmetic involving sentinels can overflow.

If:

```text
distance = INF
```

do not blindly compute:

```cpp
distance + weight
```

without ensuring the operation is valid.

Later shortest-path lessons will revisit this.

---

## 49. Why not always use `LLONG_MAX`?

Suppose:

```cpp
long long value = LLONG_MAX;
value += 10;
```

This overflows.

Often contest algorithms use a comfortably large finite value below the
numeric maximum, chosen according to problem constraints.

Sentinels should be large enough for the problem while leaving safe
arithmetic headroom.

---

# Part XII — Debugging

## 50. Debug to `cerr`

`cerr` is useful for diagnostics:

```cpp
cerr << "value = "
     << value
     << '\n';
```

Online judges normally compare expected standard output, not standard
error, although platform behavior varies.

Remove or conditionally disable unnecessary debugging before final
submission.

---

## 51. Assertions

```cpp
#include <cassert>

assert(index >= 0);
assert(index < n);
```

Assertions are useful for checking assumptions during development.

If an assertion fails, the program terminates.

Assertions can be disabled when `NDEBUG` is defined, so they are not a
replacement for required runtime input validation.

---

## 52. Local debug macro

A simple pattern:

```cpp
#ifdef LOCAL
#define DEBUG(x) \
    cerr << #x << " = " << (x) << '\n'
#else
#define DEBUG(x)
#endif
```

Compile locally:

```bash
g++ -std=c++17 -DLOCAL main.cpp
```

Then:

```cpp
DEBUG(answer);
```

prints only in local debug builds.

Preprocessor techniques should be kept simple and controlled.

---

## 53. Test tiny cases manually

Before submitting, test:

```text
minimum n
one element
all equal
already sorted
reverse sorted
all negative
all positive
duplicates
answer at first position
answer at last position
no valid answer
maximum magnitude values
```

The relevant cases depend on the problem.

A strong edge-case habit prevents many wrong answers.

---

# Part XIII — Undefined Behavior Traps

## 54. Out-of-bounds access

This is invalid:

```cpp
vector<int> a(3);
cout << a[3];
```

Valid indices:

```text
0, 1, 2
```

`operator[]` does not perform bounds checking.

Undefined behavior can appear to "work" on one test and fail on another.

---

## 55. Empty container access

Invalid:

```cpp
vector<int> a;
cout << a.back();
```

Likewise, calling:

```text
stack.top()
queue.front()
priority_queue.top()
```

requires the adapter to be non-empty.

Check constraints or state first.

---

## 56. Invalidated iterators and references

You learned this in STL basics.

Example:

```cpp
auto it = a.begin();

a.push_back(x); // may reallocate

cout << *it;    // possibly invalid
```

Do not keep iterators/references across operations that may invalidate
them.

---

## 57. Dangling references

Never return:

```cpp
const int& bad() {
    int value = 10;
    return value;
}
```

`value` dies when the function returns.

The returned reference dangles.

The same principle applies to pointers, lambdas with reference captures,
and container-element references.

---

# Part XIV — Implementation Discipline

## 58. Separate solving logic

A practical structure:

```cpp
void solve() {
    // read one test case
    // solve it
    // print answer
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
```

Benefits:

- fresh local state
- easier testing
- clearer multiple-test-case structure

---

## 59. Do not optimize blindly

Start from constraints and complexity.

Bad reasoning:

```text
unordered_map is O(1), so it must always beat vector.
```

Better reasoning:

```text
Keys are integers from 0 to 1000.
A frequency vector is simpler and has direct indexing.
```

Another example:

```text
n <= 20
```

may permit a simple exponential approach that is safer than a complex
optimization.

Use the simplest solution that comfortably satisfies constraints.

---

## 60. Avoid clever macros

Macros such as:

```cpp
#define int long long
```

are common in some contest code but can produce confusing behavior,
change library/API types unexpectedly, and hide type decisions.

Prefer explicit types:

```cpp
long long
```

or a clear alias:

```cpp
using ll = long long;
```

Understand the type you actually need.

---

## 61. Avoid variable-length arrays

This:

```cpp
int n;
cin >> n;

int a[n];
```

is not standard C++17.

Some compilers accept it as an extension.

Portable C++ uses:

```cpp
vector<int> a(n);
```

when runtime-sized contiguous storage is needed.

---

## 62. Reserve when size is predictable

If building a vector incrementally and you know the approximate final
size:

```cpp
vector<int> values;
values.reserve(n);
```

This can reduce reallocations.

Important:

```text
reserve(n)
```

changes capacity, not size.

After:

```cpp
values.reserve(10);
```

this is still invalid if size is zero:

```cpp
values[0] = 5;
```

Use `push_back`, or create actual elements with:

```cpp
vector<int> values(10);
```

---

## 63. `reserve` versus `resize`

`reserve(n)`:

```text
capacity >= n
size unchanged
```

`resize(n)`:

```text
size becomes n
elements are created/removed as necessary
```

This distinction causes frequent bugs.

---

# Part XV — A Contest Workflow

## 64. Step 1: understand the problem

Identify:

```text
input
required output
constraints
what exactly must be optimized/computed
```

Do not code from the title alone.

---

## 65. Step 2: work small examples

Build small manual cases.

Track variables and data structures.

Ask:

```text
What is the brute-force method?
Why is it correct?
```

A correct brute force often exposes the structure required for
optimization.

---

## 66. Step 3: estimate complexity

For each candidate solution ask:

```text
time complexity?
space complexity?
does it fit n and total constraints?
```

Reject impossible approaches before implementing them.

---

## 67. Step 4: choose data structures

Ask which operations dominate:

```text
lookup?
sorting?
minimum/maximum?
frequency?
queue processing?
stack behavior?
```

Choose structures based on those operations.

---

## 68. Step 5: check numeric ranges

Before coding arithmetic:

```text
largest input?
largest sum?
largest product?
negative values?
modulus?
floating point?
```

Select types deliberately.

---

## 69. Step 6: implement cleanly

Prefer:

```text
small solve()
meaningful variable names
clear loops
few global variables
known STL operations
```

Contest code can be concise without becoming cryptic.

---

## 70. Step 7: dry run

Walk through:

```text
normal case
minimum case
boundary case
failure/no-answer case
duplicate case
maximum-value case
```

Track indexes and arithmetic.

---

## 71. Step 8: submit and learn

If rejected, classify the cause:

```text
Wrong Answer
Time Limit Exceeded
Memory Limit Exceeded
Runtime Error
Compilation Error
```

Do not randomly change code.

Find which assumption failed.

A later `24_PRACTICE_AND_MASTERY__/14_MISTAKE_LOG/` folder will formalize
this habit.

---

# Complexity and Contest Heuristics

| Input scale | Common complexity target |
|---|---|
| `n <= 20` | O(2^n), O(n*2^n) may be plausible |
| `n <= 100` | O(n^3) may sometimes be plausible |
| `n <= 1,000` | O(n^2) may be plausible |
| `n <= 100,000` | Usually O(n log n) or O(n) |
| `n <= 1,000,000` | Usually near O(n), sometimes O(n log n) |

These are heuristics, not guarantees. Constant factors, test count,
operation cost, language, hardware, and time limit all matter.

---

## Common interview and contest mistakes

1. Ignoring constraints before coding.

2. Using `int` for a sum that can reach `10^14`.

3. Writing:

```cpp
long long x = a * b;
```

when `a` and `b` are `int` and multiplication can overflow first.

4. Using `accumulate(..., 0)` for a sum requiring `long long`.

5. Using `endl` for every output line unnecessarily.

6. Mixing C and C++ I/O after disabling synchronization without
   understanding buffering.

7. Forgetting to reset state between test cases.

8. Ignoring total constraints across test cases.

9. Using a VLA such as `int a[n]` in standard C++17 code.

10. Confusing `reserve()` with `resize()`.

11. Accessing empty container `front()`, `back()`, or `top()`.

12. Dereferencing `end()`.

13. Binary-searching unsorted data.

14. Using an invalid comparator such as `a >= b` in `sort`.

15. Assuming unordered maps have guaranteed O(1) operations.

16. Using `map[key]` merely to check existence and accidentally
    inserting.

17. Copying large vectors into helper functions.

18. Keeping iterators across vector reallocations.

19. Ignoring floating-point tolerance requirements.

20. Using `#define int long long` without understanding its effects.

21. Printing debug text to required judge output.

22. Overengineering an easy problem.

23. Optimizing micro-details while using the wrong Big-O algorithm.

24. Assuming `bits/stdc++.h` is standard C++.

25. Forgetting that signed integer overflow is undefined behavior.

---

## Practice questions

1. LeetCode 1480 — Running Sum of 1d Array  
   https://leetcode.com/problems/running-sum-of-1d-array/

2. LeetCode 217 — Contains Duplicate  
   https://leetcode.com/problems/contains-duplicate/

3. LeetCode 704 — Binary Search  
   https://leetcode.com/problems/binary-search/

4. LeetCode 1 — Two Sum  
   https://leetcode.com/problems/two-sum/

5. Codeforces Problemset  
   https://codeforces.com/problemset

For Codeforces, begin with problems around the easiest rating bands and
focus on implementation correctness before speed-solving.

---

## C++ foundation checklist

You have now completed the C++ foundation section.

You should be comfortable with:

```text
syntax
types
I/O
operators
conditions
loops
functions
scope/lifetime
value/reference/pointer passing
arrays
strings
pointers
dynamic memory
structs
OOP
constructors/destructors
inheritance
polymorphism
abstraction/encapsulation
static/const/friend
operator overloading
templates
exceptions
namespaces/headers
auto
range loops
lambdas
RAII
smart pointers
move semantics
STL basics
contest-oriented C++ practices
```

The remaining roadmap will use these tools to study data structures and
algorithms systematically.

# What's Next

The C++ foundation is complete.

Continue to:

`02_INTRO_TO_DATA_STRUCTURES__/01_WHAT_ARE_DATA_STRUCTURES/`

The next section begins the conceptual DSA foundation: what data
structures are, why representation matters, how operations define
usefulness, and how data organization affects algorithm design and
complexity.
