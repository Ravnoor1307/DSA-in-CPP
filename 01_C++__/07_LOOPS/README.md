# Loops in C++

Path:

`DSA_JOURNEY/01_C++__/07_LOOPS/`

## Prerequisites

You should already understand:

- variables
- input/output
- arithmetic operators
- comparison operators
- logical operators
- increment/decrement
- `if`, `else if`, `else`
- Boolean expressions
- `break` from `switch`

Now we learn how to repeat work.

Loops are one of the most important foundations for DSA because arrays, strings, matrices, searching, sorting, graphs, and dynamic programming all depend heavily on iteration.

---

# 1. Why Do We Need Loops?

Suppose we want to print:

```text
1
2
3
4
5
```

We could write:

```cpp
cout << 1 << '\n';
cout << 2 << '\n';
cout << 3 << '\n';
cout << 4 << '\n';
cout << 5 << '\n';
```

But what if we need:

```text
1 through 1,000,000
```

Repeating source code manually is not practical.

A loop expresses:

```text
repeat some operation while a rule permits it
```

---

# 2. Real-World Analogy

Imagine a worker packing 100 boxes.

Without a loop-like process:

```text
pack box 1
pack box 2
pack box 3
...
pack box 100
```

A better instruction is:

```text
start with box 1

while there are boxes remaining:
    pack current box
    move to next box
```

That is the central idea of iteration.

---

# 3. Main Loop Types in C++

C++ provides:

```text
while
do-while
for
range-based for
```

Range-based `for` becomes especially useful after we learn arrays and containers.

For now we focus deeply on:

```text
while
do-while
for
```

---

# 4. Anatomy of a Loop

Most loops involve three ideas:

```text
initialization
condition
update
```

Example:

```cpp
int i = 1;

while (i <= 5) {
    cout << i << '\n';
    ++i;
}
```

Mapping:

```text
initialization:
i = 1

condition:
i <= 5

body:
cout << i

update:
++i
```

---

# 5. while Loop

Syntax:

```cpp
while (condition) {
    // body
}
```

Execution:

```text
check condition
      |
      +-- false --> leave loop
      |
      +-- true
             |
             v
         run body
             |
             v
      return to condition
```

The condition is checked before each iteration.

Therefore a `while` loop can execute zero times.

---

# 6. Full Dry Run: while

Code:

```cpp
int i = 1;

while (i <= 3) {
    cout << i << ' ';
    ++i;
}
```

Initial state:

```text
i = 1
output = ""
```

Check:

```text
1 <= 3 -> true
```

Iteration 1:

```text
print 1

output = "1 "

++i

i = 2
```

Check:

```text
2 <= 3 -> true
```

Iteration 2:

```text
output = "1 2 "
i = 3
```

Check:

```text
3 <= 3 -> true
```

Iteration 3:

```text
output = "1 2 3 "
i = 4
```

Check:

```text
4 <= 3 -> false
```

Stop.

Final:

```text
i = 4
output = "1 2 3 "
```

---

# 7. The Update Is Critical

Consider:

```cpp
int i = 1;

while (i <= 5) {
    cout << i << '\n';
}
```

`i` never changes.

The condition remains:

```text
1 <= 5
```

forever.

This creates an infinite loop.

Correct:

```cpp
while (i <= 5) {
    cout << i << '\n';
    ++i;
}
```

When debugging a loop, ask:

```text
What changes each iteration?

Will that change eventually make the condition false?
```

---

# 8. Infinite Loops

An intentionally infinite loop can be written:

```cpp
while (true) {
    // ...
}
```

or:

```cpp
for (;;) {
    // ...
}
```

Infinite loops are not automatically bugs.

They are useful in:

- event loops
- servers
- menu systems
- simulations
- programs that terminate using `break`
- embedded systems

But an unintended infinite loop is a common programming error.

---

# 9. do-while Loop

Syntax:

```cpp
do {
    // body
} while (condition);
```

Notice the semicolon:

```text
;
```

after the condition.

The important difference:

```text
while:
condition is checked BEFORE body

do-while:
condition is checked AFTER body
```

Therefore `do-while` executes its body at least once.

---

# 10. Real-World Analogy for do-while

Suppose a menu must be displayed before a user can decide whether to continue.

Conceptually:

```text
show menu
get choice

if continuing:
    show menu again
```

The first execution happens before continuation is tested.

That naturally resembles `do-while`.

---

# 11. Dry Run: do-while

Code:

```cpp
int i = 5;

do {
    cout << i << '\n';
    ++i;
} while (i < 5);
```

Initial:

```text
i = 5
```

The body executes immediately:

```text
print 5
i becomes 6
```

Now condition:

```text
6 < 5 -> false
```

Stop.

Output:

```text
5
```

Equivalent `while`:

```cpp
int i = 5;

while (i < 5) {
    cout << i << '\n';
    ++i;
}
```

would execute zero times.

---

# 12. for Loop

Syntax:

```cpp
for (initialization; condition; update) {
    // body
}
```

Example:

```cpp
for (int i = 1; i <= 5; ++i) {
    cout << i << '\n';
}
```

The three loop-control pieces are visible in one place:

```text
int i = 1    -> initialization
i <= 5       -> condition
++i          -> update
```

---

# 13. Execution Order of for

For:

```cpp
for (int i = 1; i <= 3; ++i) {
    cout << i << '\n';
}
```

execution is conceptually:

```text
1. int i = 1

2. check i <= 3

3. if false -> stop

4. execute body

5. execute ++i

6. return to step 2
```

Initialization runs only once.

The condition runs before every iteration.

The update runs after every normally completed iteration.

---

# 14. Full Dry Run: for

Code:

```cpp
for (int i = 1; i <= 3; ++i) {
    cout << i << ' ';
}
```

Initialization:

```text
i = 1
```

Check:

```text
1 <= 3 -> true
```

Body:

```text
output = "1 "
```

Update:

```text
i = 2
```

Check:

```text
2 <= 3 -> true
```

Body:

```text
output = "1 2 "
```

Update:

```text
i = 3
```

Check:

```text
3 <= 3 -> true
```

Body:

```text
output = "1 2 3 "
```

Update:

```text
i = 4
```

Check:

```text
4 <= 3 -> false
```

Loop ends.

---

# 15. while vs for

These two loops can express the same sequence.

`while`:

```cpp
int i = 1;

while (i <= 5) {
    cout << i << '\n';
    ++i;
}
```

`for`:

```cpp
for (int i = 1; i <= 5; ++i) {
    cout << i << '\n';
}
```

A common guideline:

Use `for` when iteration is naturally controlled by a counter or clearly defined progression.

Use `while` when repetition is primarily controlled by a condition whose update may be less regular.

This is not a strict language rule.

---

# 16. Counting Up

```cpp
for (int i = 1; i <= 5; ++i) {
    cout << i << ' ';
}
```

Output:

```text
1 2 3 4 5
```

State sequence:

```text
i:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> stop
```

---

# 17. Counting Down

```cpp
for (int i = 5; i >= 1; --i) {
    cout << i << ' ';
}
```

Output:

```text
5 4 3 2 1
```

State:

```text
5 -> 4 -> 3 -> 2 -> 1 -> 0 -> stop
```

---

# 18. Different Step Sizes

The update does not need to be exactly `+1`.

Example:

```cpp
for (int i = 0; i <= 10; i += 2) {
    cout << i << ' ';
}
```

Output:

```text
0 2 4 6 8 10
```

State:

```text
0 -> 2 -> 4 -> 6 -> 8 -> 10 -> 12
```

---

# 19. Counter Variables

A counter records how many times something happens.

Example:

```cpp
int count = 0;

for (int i = 1; i <= 5; ++i) {
    ++count;
}
```

Final:

```text
count = 5
```

Later counters will be used for:

- counting matching array elements
- frequencies
- graph components
- valid substrings
- successful conditions

---

# 20. Accumulators

An accumulator stores an ongoing combined result.

Example:

```cpp
int sum = 0;

for (int i = 1; i <= 5; ++i) {
    sum += i;
}
```

Dry run:

```text
Start:
sum = 0

i = 1:
sum = 0 + 1 = 1

i = 2:
sum = 1 + 2 = 3

i = 3:
sum = 3 + 3 = 6

i = 4:
sum = 6 + 4 = 10

i = 5:
sum = 10 + 5 = 15
```

Final:

```text
sum = 15
```

The variable `sum` is an accumulator.

---

# 21. Product Accumulator

To multiply values:

```cpp
long long product = 1;

for (int i = 1; i <= 5; ++i) {
    product *= i;
}
```

Final:

```text
120
```

Notice initialization:

```text
sum starts at 0
product starts at 1
```

Why?

Because:

```text
0 is the additive identity
1 is the multiplicative identity
```

Starting a product with zero would make the result remain zero.

---

# 22. Factorial

Factorial is defined for non-negative integers:

```text
n! = 1 * 2 * 3 * ... * n
```

And:

```text
0! = 1
```

Example:

```cpp
int n = 5;
long long factorial = 1;

for (int i = 2; i <= n; ++i) {
    factorial *= i;
}
```

Dry run:

```text
factorial = 1

i = 2 -> 2
i = 3 -> 6
i = 4 -> 24
i = 5 -> 120
```

Factorials grow extremely quickly, so even `long long` overflows for fairly small `n`.

On common signed 64-bit systems:

```text
20!
```

fits but:

```text
21!
```

does not.

Do not assume `long long` can store arbitrary factorials.

---

# 23. break

`break` immediately exits the nearest enclosing loop or `switch`.

Example:

```cpp
for (int i = 1; i <= 10; ++i) {
    if (i == 5) {
        break;
    }

    cout << i << ' ';
}
```

Output:

```text
1 2 3 4
```

When:

```text
i = 5
```

the `break` executes before printing `5`.

---

# 24. Dry Run: break

Loop:

```cpp
for (int i = 1; i <= 5; ++i) {
    if (i == 3) {
        break;
    }

    cout << i << ' ';
}
```

Iteration 1:

```text
i = 1
i == 3 -> false
print 1
```

Iteration 2:

```text
i = 2
i == 3 -> false
print 2
```

Iteration 3:

```text
i = 3
i == 3 -> true
break
```

Loop ends immediately.

Final output:

```text
1 2
```

---

# 25. continue

`continue` skips the remainder of the current iteration.

Example:

```cpp
for (int i = 1; i <= 5; ++i) {
    if (i == 3) {
        continue;
    }

    cout << i << ' ';
}
```

Output:

```text
1 2 4 5
```

Unlike `break`, `continue` does not terminate the whole loop.

---

# 26. break vs continue

Mental model:

```text
break
  |
  v
leave loop completely
```

```text
continue
   |
   v
skip rest of this iteration
   |
   v
move toward next iteration
```

Real-world analogy:

Imagine checking items in a queue.

`continue` means:

```text
skip this item and inspect the next
```

`break` means:

```text
stop inspecting items entirely
```

---

# 27. continue in a for Loop

For:

```cpp
for (int i = 1; i <= 5; ++i) {
    if (i == 3) {
        continue;
    }
}
```

`continue` transfers control to the loop's update expression:

```text
++i
```

then the condition is checked again.

This differs slightly from how you reason about a `while` loop.

---

# 28. continue Trap in while

Consider:

```cpp
int i = 0;

while (i < 5) {
    if (i == 2) {
        continue;
    }

    ++i;
}
```

When `i == 2`:

```text
continue
```

skips:

```cpp
++i;
```

So `i` remains `2` forever.

Infinite loop.

One correction:

```cpp
while (i < 5) {
    if (i == 2) {
        ++i;
        continue;
    }

    ++i;
}
```

But often the clearest solution is to structure the loop so the update cannot accidentally be skipped.

This is one reason `for` loops are convenient for regular counter iteration.

---

# 29. Nested Loops

A loop can contain another loop.

Example:

```cpp
for (int row = 1; row <= 3; ++row) {
    for (int col = 1; col <= 2; ++col) {
        cout << row << ',' << col << '\n';
    }
}
```

Output:

```text
1,1
1,2
2,1
2,2
3,1
3,2
```

For each outer iteration, the inner loop runs from beginning to end.

---

# 30. Real-World Analogy for Nested Loops

Imagine a hotel.

There are:

```text
3 floors
2 rooms per floor
```

To visit every room:

```text
for every floor:
    for every room on that floor:
        visit room
```

This is the same conceptual structure as nested loops.

Later this directly maps to:

- matrices
- grids
- pair comparisons
- brute-force combinations

---

# 31. Full Dry Run: Nested Loop

Code:

```cpp
for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 3; ++j) {
        cout << i << j << ' ';
    }
}
```

Outer:

```text
i = 1
```

Inner states:

```text
j = 1 -> print 11
j = 2 -> print 12
j = 3 -> print 13
j = 4 -> stop inner
```

Outer update:

```text
i = 2
```

Inner begins again with:

```text
j = 1
```

Print:

```text
21 22 23
```

Final output:

```text
11 12 13 21 22 23
```

Important:

The inner-loop variable is initialized again for each outer iteration.

---

# 32. Nested Loop Complexity Preview

Consider:

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        // constant work
    }
}
```

For each of `n` outer iterations, the inner loop executes `n` times.

Total body executions:

```text
n * n = n²
```

Therefore:

```text
O(n²)
```

Formal complexity analysis comes much later, but loops are where complexity starts becoming concrete.

---

# 33. Not Every Nested Loop Is O(n²)

This is important.

You cannot simply say:

```text
two loops = O(n²)
```

Example:

```cpp
for (int i = 0; i < n; ++i) {
    // ...
}

for (int j = 0; j < n; ++j) {
    // ...
}
```

These loops are sequential, not nested.

Total work:

```text
n + n = 2n
```

which becomes:

```text
O(n)
```

Meanwhile:

```cpp
for (...) {
    for (...) {
    }
}
```

often multiplies iteration counts.

Always count the actual work.

---

# 34. Triangular Nested Loop

Consider:

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
        // work
    }
}
```

Inner loop counts:

```text
1
2
3
...
n
```

Total:

```text
1 + 2 + ... + n
```

which equals:

```text
n(n + 1) / 2
```

Therefore complexity is:

```text
O(n²)
```

even though the inner loop does not always run exactly `n` times.

---

# 35. Logarithmic Loops Preview

Consider:

```cpp
for (int i = 1; i < n; i *= 2) {
    // work
}
```

Values:

```text
1
2
4
8
16
...
```

If `n = 32`:

```text
1
2
4
8
16
```

Only about:

```text
log2(n)
```

iterations occur.

So the complexity is:

```text
O(log n)
```

This pattern becomes crucial in binary search and many advanced algorithms.

---

# 36. Be Careful with Multiplicative Updates

This is wrong:

```cpp
for (int i = 0; i < n; i *= 2) {
}
```

Why?

Start:

```text
i = 0
```

Then:

```text
i *= 2
```

still gives:

```text
0
```

If `n > 0`, the condition stays true forever.

For doubling loops, commonly start with:

```cpp
int i = 1;
```

---

# 37. Loop Scope

Example:

```cpp
for (int i = 0; i < 5; ++i) {
    cout << i;
}
```

The `i` declared in the `for` initialization belongs to the loop's scope.

You cannot normally use that same `i` after the loop:

```cpp
cout << i; // error
```

If you need the variable afterward:

```cpp
int i = 0;

for (; i < 5; ++i) {
}

cout << i;
```

Scope is studied deeply in its dedicated folder.

---

# 38. for Components Can Be Omitted

The general syntax:

```cpp
for (initialization; condition; update)
```

allows components to be omitted.

Example:

```cpp
int i = 0;

for (; i < 5;) {
    cout << i << '\n';
    ++i;
}
```

This behaves much like a `while`.

Infinite form:

```cpp
for (;;) {
}
```

The missing condition is treated as always true.

---

# 39. Multiple Loop-Control Variables

A `for` loop can update multiple expressions using the comma operator.

Example:

```cpp
for (int left = 0, right = 5;
     left < right;
     ++left, --right) {

    cout << left << ' ' << right << '\n';
}
```

This pattern will later be useful for two-pointer techniques.

Do not confuse comma separators in declarations with the comma operator used in the update expression.

---

# 40. Sentinel-Controlled Loops

Sometimes the number of repetitions is unknown.

Instead, a special value indicates termination.

Example:

```cpp
int value;
cin >> value;

while (value != -1) {
    cout << value << '\n';
    cin >> value;
}
```

Here:

```text
-1
```

is a sentinel.

Example input:

```text
10
20
30
-1
```

Output:

```text
10
20
30
```

---

# 41. Better Input-Controlled Loop

A more robust pattern when processing until input ends is:

```cpp
int value;

while (cin >> value) {
    cout << value << '\n';
}
```

The extraction itself supplies the loop condition.

The loop continues while input succeeds.

This naturally handles EOF.

Later you will use this pattern in some competitive-programming problems.

---

# 42. Off-by-One Errors

One of the most common DSA bugs is executing one too many or one too few iterations.

Compare:

```cpp
for (int i = 0; i < 5; ++i)
```

Values:

```text
0 1 2 3 4
```

Five iterations.

Compare:

```cpp
for (int i = 0; i <= 5; ++i)
```

Values:

```text
0 1 2 3 4 5
```

Six iterations.

The difference between:

```text
<
```

and:

```text
<=
```

will become critical with arrays.

---

# 43. Half-Open Ranges

C++ algorithms frequently use ranges conceptually like:

```text
[start, end)
```

meaning:

```text
start is included
end is excluded
```

For example:

```cpp
for (int i = 0; i < n; ++i)
```

visits:

```text
0, 1, 2, ..., n - 1
```

This is exactly `n` iterations when `n > 0`.

This pattern aligns naturally with zero-based array indexing, which we will learn later.

---

# 44. Loop Invariants: First Introduction

A loop invariant is a fact that remains true at a particular point of every iteration.

Consider:

```cpp
int sum = 0;

for (int i = 1; i <= n; ++i) {
    sum += i;
}
```

At the beginning of each iteration with current `i`, we can reason:

```text
sum contains the total of numbers from 1 through i - 1
```

After:

```cpp
sum += i;
```

it contains the total through `i`.

This style of reasoning later becomes essential for proving algorithms correct.

Real-world analogy:

Imagine maintaining a running bank total while processing transactions.

Before each next transaction:

```text
the current total already correctly represents
all transactions processed so far
```

That maintained truth is similar to a loop invariant.

---

# 45. Termination Reasoning

A correct loop normally needs:

1. a state
2. a continuation condition
3. progress toward termination

Example:

```cpp
int i = 0;

while (i < n) {
    ++i;
}
```

Reasoning:

```text
state:
i

condition:
i < n

progress:
i increases

termination:
eventually i reaches n
```

This mental model helps detect infinite loops before running the code.

---

# 46. Counting Digits

A classic loop problem:

```cpp
int n = 12345;
int count = 0;

while (n > 0) {
    ++count;
    n /= 10;
}
```

State:

```text
n = 12345, count = 0
n = 1234,  count = 1
n = 123,   count = 2
n = 12,    count = 3
n = 1,     count = 4
n = 0,     count = 5
```

Answer:

```text
5
```

Special case:

```text
n = 0
```

has one decimal digit, but the loop above executes zero times.

Edge cases matter.

A corrected approach can initialize accordingly or explicitly handle zero.

---

# 47. Extracting Digits

For a positive integer:

```cpp
int digit = n % 10;
n /= 10;
```

Example:

```text
n = 482
```

First:

```text
digit = 482 % 10 = 2
n = 48
```

Then:

```text
digit = 8
n = 4
```

Then:

```text
digit = 4
n = 0
```

Digits are obtained from right to left.

This technique appears constantly in beginner mathematical problems.

---

# 48. Sum of Digits

Example:

```cpp
int n = 482;
int sum = 0;

while (n > 0) {
    int digit = n % 10;
    sum += digit;
    n /= 10;
}
```

Dry run:

```text
n = 482, sum = 0

digit = 2
sum = 2
n = 48

digit = 8
sum = 10
n = 4

digit = 4
sum = 14
n = 0
```

Final:

```text
sum = 14
```

---

# 49. Reverse an Integer: Conceptual Pattern

For positive values within safe range:

```cpp
int reversed = 0;

while (n > 0) {
    int digit = n % 10;

    reversed =
        reversed * 10 + digit;

    n /= 10;
}
```

Example:

```text
123
```

State:

```text
reversed = 0

digit 3:
reversed = 3

digit 2:
reversed = 32

digit 1:
reversed = 321
```

Important:

```cpp
reversed * 10 + digit
```

can overflow for sufficiently large input.

Later algorithm problems require explicit overflow handling.

---

# 50. Pattern Printing

Nested loops can create patterns.

Example:

```cpp
for (int row = 1; row <= 3; ++row) {
    for (int col = 1; col <= 4; ++col) {
        cout << '*';
    }

    cout << '\n';
}
```

Output:

```text
****
****
****
```

Outer loop:

```text
rows
```

Inner loop:

```text
columns
```

Pattern problems are useful for learning nested-loop control even though they are not usually the central focus of DSA interviews.

---

# 51. Common Interview and Beginner Mistakes

1. Forgetting to update a `while` loop variable.

2. Using `<=` when `<` is needed.

3. Using `<` when the endpoint should be included.

4. Starting from the wrong value.

5. Updating in the wrong direction.

Example:

```cpp
for (int i = 0; i < 10; --i)
```

moves away from termination.

6. Using `continue` before a required `while` update.

7. Confusing `break` with `continue`.

8. Assuming two sequential loops imply O(n²).

9. Assuming every nested loop is automatically O(n²).

10. Starting a doubling loop from zero.

11. Initializing a product accumulator to zero.

12. Forgetting `0! = 1`.

13. Failing to handle `n = 0` in digit counting.

14. Modifying the original number when a later part of the program still needs it.

Use a copy:

```cpp
int temp = n;
```

15. Overflowing an accumulator.

Example:

```cpp
int sum
```

may be too small for a large sum.

16. Forgetting that `break` only exits the nearest enclosing loop.

17. Expecting `continue` to exit the entire loop.

18. Accidentally placing a semicolon after a loop condition:

```cpp
while (condition);
```

19. Trusting indentation instead of braces.

20. Performing too much work inside a loop and causing a time-limit problem.

---

# 52. break Only Exits the Nearest Loop

Consider:

```cpp
for (...) {
    for (...) {
        if (condition) {
            break;
        }
    }
}
```

The `break` exits only the inner loop.

The outer loop continues.

If you need to stop multiple loop levels, common approaches later include:

- a Boolean flag
- moving logic into a function and returning
- changing loop conditions
- other problem-specific restructuring

Do not assume one `break` exits every surrounding loop.

---

# 53. Complexity Table

| Loop Pattern | Iterations | Typical Time |
|---|---:|---:|
| `for (i = 0; i < n; ++i)` | n | O(n) |
| `for (i = n; i > 0; --i)` | n | O(n) |
| `for (i = 0; i < n; i += 2)` | about n/2 | O(n) |
| `for (i = 1; i < n; i *= 2)` | about log₂n | O(log n) |
| two sequential n-loops | 2n | O(n) |
| nested n × n loops | n² | O(n²) |
| triangular nested loops | n(n+1)/2 | O(n²) |
| fixed 100-iteration loop | 100 | O(1) |
| digit loop `n /= 10` | number of digits | O(log₁₀ n) for positive n |

Space for simple counter loops is generally:

```text
O(1)
```

because only a fixed number of scalar variables are used.

Complexity is studied formally later. For now, practice counting iterations.

---

# 54. Practice Questions

1. LeetCode 412 — Fizz Buzz  
   https://leetcode.com/problems/fizz-buzz/

2. LeetCode 1281 — Subtract the Product and Sum of Digits of an Integer  
   https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

3. LeetCode 1342 — Number of Steps to Reduce a Number to Zero  
   https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

4. GFG — Loops in C++  
   https://www.geeksforgeeks.org/cpp-loops/

5. HackerRank — For Loop  
   https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

Fizz Buzz may involve concepts that become cleaner with strings, but the loop/condition reasoning is already useful.

---

# 55. Final Checklist

You should understand:

```text
iteration
while
do-while
for
initialization
condition
update
counter
accumulator
break
continue
nested loops
infinite loops
sentinel loops
EOF-controlled loops
off-by-one errors
half-open ranges
loop scope
digit extraction
sum of digits
factorial
pattern printing
linear loops
nested-loop work
logarithmic loops
loop invariants
termination reasoning
```

You should be able to dry-run:

```cpp
for (int i = 0; i < n; ++i)
```

and explain exactly:

- initialization
- first condition check
- body execution
- update
- next condition check
- final value that stops the loop

---

# What's Next

`01_C++__/08_FUNCTIONS/`

Next we learn how to package reusable logic into functions using declarations, definitions, parameters, arguments, return values, function calls, the call stack at a beginner level, and function decomposition.
