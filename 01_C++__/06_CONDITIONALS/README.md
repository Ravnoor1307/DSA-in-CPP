# Conditionals in C++

Path:

`DSA_JOURNEY/01_C++__/06_CONDITIONALS/`

## Prerequisites

You should already understand:

- variables and data types
- input/output
- arithmetic operators
- comparison operators
- logical operators
- Boolean values
- operator precedence
- short-circuit evaluation
- conditional `?:` operator

Now our programs can begin making decisions.

---

# 1. What Is Control Flow?

Until now, most programs executed statements from top to bottom:

```text
statement 1
    |
statement 2
    |
statement 3
```

Real programs often need different behavior depending on data.

For example:

```text
if temperature is below 0
    print "Freezing"
otherwise
    print "Not freezing"
```

This changes control flow.

Instead of always following one straight path, execution chooses a branch.

---

# 2. Real-World Analogy: Road Junction

Imagine driving toward a junction.

```text
             +--> Left road
             |
current road + 
             |
             +--> Right road
```

The direction depends on a condition.

For example:

```text
traffic light is green?
```

If true:

```text
continue
```

If false:

```text
stop
```

An `if` statement creates this kind of decision point in a program.

---

# 3. The if Statement

Syntax:

```cpp
if (condition) {
    // executed if condition is true
}
```

Example:

```cpp
int age = 20;

if (age >= 18) {
    cout << "Adult\n";
}
```

The expression:

```cpp
age >= 18
```

produces a Boolean result.

If it evaluates to `true`, the body executes.

If it evaluates to `false`, the body is skipped.

---

# 4. Dry Run: Simple if

Code:

```cpp
int age = 20;

if (age >= 18) {
    cout << "Adult\n";
}

cout << "Done\n";
```

Initial state:

```text
age = 20
```

Evaluate:

```text
age >= 18

20 >= 18

true
```

Therefore execute:

```text
cout << "Adult\n";
```

Output becomes:

```text
Adult
```

Then execution continues after the `if`:

```text
Done
```

Final output:

```text
Adult
Done
```

---

# 5. What if the Condition Is False?

Code:

```cpp
int age = 15;

if (age >= 18) {
    cout << "Adult\n";
}

cout << "Done\n";
```

Evaluate:

```text
15 >= 18
```

Result:

```text
false
```

The `if` body is skipped.

Final output:

```text
Done
```

---

# 6. if-else

Often we need exactly one of two paths.

Syntax:

```cpp
if (condition) {
    // true branch
} else {
    // false branch
}
```

Example:

```cpp
if (age >= 18) {
    cout << "Adult\n";
} else {
    cout << "Minor\n";
}
```

Exactly one branch executes.

---

# 7. Dry Run: if-else

Suppose:

```text
age = 15
```

Evaluate:

```text
15 >= 18
```

Result:

```text
false
```

Skip:

```text
Adult
```

Execute the `else` branch:

```text
Minor
```

Control then continues after the entire `if-else`.

---

# 8. else if

When more than two mutually exclusive categories exist, we can build a chain.

```cpp
if (score >= 90) {
    cout << "A\n";
} else if (score >= 80) {
    cout << "B\n";
} else if (score >= 70) {
    cout << "C\n";
} else {
    cout << "Below C\n";
}
```

The conditions are checked from top to bottom.

The first true branch executes.

Remaining branches in that chain are skipped.

This ordering is extremely important.

---

# 9. Dry Run: else-if Chain

Suppose:

```text
score = 85
```

Check:

```text
score >= 90
85 >= 90
false
```

Move to next condition:

```text
score >= 80
85 >= 80
true
```

Execute:

```text
B
```

The rest of the chain is skipped.

Final output:

```text
B
```

---

# 10. Order Matters

Consider:

```cpp
if (score >= 60) {
    cout << "Pass\n";
} else if (score >= 90) {
    cout << "Excellent\n";
}
```

For:

```text
score = 95
```

the first condition:

```text
95 >= 60
```

is already true.

Therefore:

```text
Pass
```

prints and the `>= 90` branch is never reached.

If categories are ordered by decreasing thresholds, write:

```cpp
if (score >= 90) {
    cout << "Excellent\n";
} else if (score >= 60) {
    cout << "Pass\n";
}
```

General lesson:

```text
specific/stronger condition first
broader condition later
```

when branches overlap.

---

# 11. Independent if Statements vs else-if

These are not equivalent.

Version A:

```cpp
if (x > 0) {
    cout << "Positive\n";
}

if (x % 2 == 0) {
    cout << "Even\n";
}
```

Both can execute.

For:

```text
x = 10
```

output is:

```text
Positive
Even
```

Version B:

```cpp
if (x > 0) {
    cout << "Positive\n";
} else if (x % 2 == 0) {
    cout << "Even\n";
}
```

Once the first branch succeeds, the second is skipped.

Output:

```text
Positive
```

Use independent `if`s when multiple properties can independently apply.

Use an `if / else if / else` chain when choosing among mutually exclusive alternatives.

---

# 12. Boolean Conditions

The expression inside:

```cpp
if (...)
```

is contextually converted to `bool`.

Example:

```cpp
bool ready = true;

if (ready) {
    cout << "Start\n";
}
```

This is clearer than:

```cpp
if (ready == true)
```

Likewise:

```cpp
if (!ready)
```

is usually clearer than:

```cpp
if (ready == false)
```

---

# 13. Integers as Conditions

Because integers can convert to `bool`:

```text
0       -> false
nonzero -> true
```

this is valid:

```cpp
int x = 5;

if (x) {
    cout << "Nonzero\n";
}
```

But when the actual intention is numerical comparison, clearer code may be:

```cpp
if (x != 0) {
    cout << "Nonzero\n";
}
```

Intent matters.

---

# 14. Assignment vs Equality

A classic bug:

```cpp
if (x = 5) {
    ...
}
```

This performs assignment.

It assigns:

```text
x = 5
```

The assignment expression then has a value that converts to `true` because `5` is nonzero.

You probably meant:

```cpp
if (x == 5) {
    ...
}
```

Compile with warnings:

```bash
-Wall -Wextra -pedantic
```

Compilers often warn about suspicious assignments in conditions.

---

# 15. Combining Conditions with &&

Suppose a valid score must be between:

```text
0 and 100
```

inclusive.

Write:

```cpp
if (score >= 0 && score <= 100) {
    cout << "Valid\n";
}
```

Do not write mathematical chained comparison syntax:

```cpp
0 <= score <= 100
```

That does not mean the same thing in C++.

---

# 16. Combining Conditions with ||

Suppose a character is accepted if it is:

```text
'y'
```

or:

```text
'Y'
```

Write:

```cpp
if (choice == 'y' || choice == 'Y') {
    cout << "Yes\n";
}
```

Common mistake:

```cpp
if (choice == 'y' || 'Y')
```

This does not mean:

```text
choice equals y OR choice equals Y
```

`'Y'` by itself is a nonzero character value and therefore converts to `true` on ordinary implementations (and character code for `'Y'` is guaranteed nonzero because the null character has value zero and ordinary basic characters have distinct codes).

Repeat the comparison:

```cpp
choice == 'y' || choice == 'Y'
```

---

# 17. Short-Circuiting in Conditions

Recall:

```cpp
A && B
```

does not evaluate `B` when `A` is false.

And:

```cpp
A || B
```

does not evaluate `B` when `A` is true.

This is often used for safety.

Later with arrays:

```cpp
if (index < n && array[index] == target) {
    ...
}
```

If:

```text
index < n
```

is false, the array access is not evaluated.

Order matters.

Writing:

```cpp
array[index] == target && index < n
```

may access the array before checking the bound.

You have not learned arrays formally yet; remember the general pattern:

```text
safety check first
dependent check second
```

---

# 18. Nested if Statements

An `if` can appear inside another `if`.

Example:

```cpp
if (age >= 18) {
    if (hasID) {
        cout << "Entry allowed\n";
    }
}
```

Flow:

```text
age >= 18?
|
+-- no --> skip everything inside
|
+-- yes
      |
      +--> hasID?
             |
             +-- yes --> allowed
             |
             +-- no --> no output
```

Nested conditionals are useful, but excessive nesting can make programs difficult to read.

Logical operators can sometimes simplify them.

---

# 19. Nested if vs &&

This:

```cpp
if (age >= 18) {
    if (hasID) {
        cout << "Allowed\n";
    }
}
```

can often become:

```cpp
if (age >= 18 && hasID) {
    cout << "Allowed\n";
}
```

Both can express the same requirement.

Which style is clearer depends on the problem.

Nested `if`s are useful when the inner logic only makes sense after an outer condition succeeds.

---

# 20. Curly Braces

C++ allows a single controlled statement without braces:

```cpp
if (x > 0)
    cout << "Positive\n";
```

However, this style can create maintenance bugs.

Prefer:

```cpp
if (x > 0) {
    cout << "Positive\n";
}
```

Real-world analogy:

Braces are like clearly drawn boundaries around which instructions belong to a rule.

Without them, adding another line can accidentally place that line outside the condition.

---

# 21. The Missing-Braces Trap

Consider:

```cpp
if (x > 0)
    cout << "Positive\n";
    cout << "Checked\n";
```

Indentation does not control C++ execution.

The compiler sees roughly:

```cpp
if (x > 0)
    cout << "Positive\n";

cout << "Checked\n";
```

Therefore:

```text
Checked
```

always prints.

Use braces:

```cpp
if (x > 0) {
    cout << "Positive\n";
    cout << "Checked\n";
}
```

---

# 22. Dangling else

Without braces, nested `if` statements can create an ambiguity for humans.

Example:

```cpp
if (a)
    if (b)
        cout << "X\n";
    else
        cout << "Y\n";
```

The `else` associates with the nearest unmatched `if`.

It belongs to:

```cpp
if (b)
```

not:

```cpp
if (a)
```

Use braces to make intent explicit:

```cpp
if (a) {
    if (b) {
        cout << "X\n";
    } else {
        cout << "Y\n";
    }
}
```

---

# 23. Empty if Statement Mistake

This is a subtle bug:

```cpp
if (x > 0);
{
    cout << "Positive\n";
}
```

The semicolon forms an empty statement controlled by the `if`.

The block afterward executes independently.

So:

```text
Positive
```

prints regardless of the condition.

Do not place an accidental semicolon after `if (...)`.

---

# 24. else Has No Condition

Correct:

```cpp
if (x > 0) {
    ...
} else {
    ...
}
```

`else` represents the remaining case.

If another test is required:

```cpp
else if (x == 0) {
    ...
}
```

---

# 25. switch Statement

When one integral-like expression is compared against several discrete constant values, `switch` can be useful.

Example:

```cpp
int day = 2;

switch (day) {
    case 1:
        cout << "Monday\n";
        break;

    case 2:
        cout << "Tuesday\n";
        break;

    default:
        cout << "Unknown\n";
}
```

---

# 26. How switch Works

Conceptually:

```text
evaluate switch expression
        |
        v
compare with case labels
        |
        +--> matching case
        |
        +--> default if no case matches
```

`case` labels must satisfy C++ constant-expression rules and be valid for the switch's adjusted integral or enumeration type.

At this stage, think of them as compile-time constant integral/enum values.

---

# 27. break in switch

Consider:

```cpp
switch (day) {
    case 1:
        cout << "One\n";

    case 2:
        cout << "Two\n";
}
```

If:

```text
day = 1
```

execution enters `case 1` and then continues into `case 2` because there is no `break`.

Output:

```text
One
Two
```

This is called fallthrough.

---

# 28. Intentional Fallthrough

Sometimes fallthrough is deliberate.

Example:

```cpp
switch (grade) {
    case 'A':
    case 'B':
        cout << "High grade\n";
        break;

    default:
        cout << "Other\n";
}
```

Both `'A'` and `'B'` reach the same body.

C++17 also provides:

```cpp
[[fallthrough]];
```

to document intentional fallthrough between nonempty cases.

Example:

```cpp
case 1:
    cout << "One\n";
    [[fallthrough]];

case 2:
    cout << "Two\n";
    break;
```

Use intentional fallthrough sparingly and clearly.

---

# 29. default in switch

`default` runs if no `case` matches.

Example:

```cpp
switch (choice) {
    case 1:
        cout << "Start\n";
        break;

    case 2:
        cout << "Stop\n";
        break;

    default:
        cout << "Invalid\n";
}
```

`default` is optional.

---

# 30. What Types Can switch Use?

A switch condition ultimately works with integral or enumeration types after the relevant promotions/conversions.

Common examples:

```text
int
char
enum
```

You cannot directly switch on a `double`.

You also cannot directly switch on `std::string`.

For strings or ranges, `if / else if` is typically more appropriate.

---

# 31. switch Is Not for Ranges

This is not how `switch` works:

```text
score >= 90
score >= 80
```

For ranges, use:

```cpp
if (score >= 90) {
    ...
} else if (score >= 80) {
    ...
}
```

Use `switch` primarily for discrete cases such as:

```text
1
2
3
'A'
'B'
```

---

# 32. if vs switch

Use `if` when conditions involve:

- ranges
- inequalities
- multiple variables
- logical combinations
- complex Boolean expressions

Use `switch` when:

- one integral/enum expression is being compared
- there are several discrete constant cases
- the structure is clearer than a long equality chain

Neither is inherently "better."

Choose the construct that expresses the decision clearly.

---

# 33. Conditional Operator vs if

We previously learned:

```cpp
condition ? value1 : value2
```

Example:

```cpp
int maximum =
    (a > b) ? a : b;
```

This is useful for compact value selection.

For complex control flow, prefer `if`.

Good:

```cpp
int minimum =
    (a < b) ? a : b;
```

Less readable:

```cpp
condition
    ? (many complicated operations)
    : (many other complicated operations);
```

The conditional operator is an expression; `if` is a statement.

That distinction becomes more important as your C++ knowledge grows.

---

# 34. Guard Clauses Preview

Later, functions often become cleaner by handling invalid or special cases early.

Conceptually:

```cpp
if (invalid) {
    return;
}

// normal logic
```

instead of deeply nesting:

```cpp
if (!invalid) {
    // lots of logic
}
```

Functions are taught later, but this style is worth recognizing because it reduces nesting.

---

# 35. Validating Input Ranges

Suppose a percentage should satisfy:

```text
0 <= score <= 100
```

In C++:

```cpp
if (score >= 0 && score <= 100) {
    cout << "Valid\n";
} else {
    cout << "Invalid\n";
}
```

Dry run for:

```text
score = 105
```

First condition:

```text
105 >= 0 -> true
```

Second:

```text
105 <= 100 -> false
```

Combined:

```text
true && false -> false
```

Therefore:

```text
Invalid
```

---

# 36. Checking Even or Odd

The remainder operator is useful with conditionals.

```cpp
if (number % 2 == 0) {
    cout << "Even\n";
} else {
    cout << "Odd\n";
}
```

Dry run:

```text
number = 7

7 % 2 = 1

1 == 0 -> false

else branch -> Odd
```

For negative integers, divisibility by 2 still works with:

```cpp
number % 2 == 0
```

---

# 37. Positive, Negative, Zero

A classic mutually exclusive classification:

```cpp
if (number > 0) {
    cout << "Positive\n";
} else if (number < 0) {
    cout << "Negative\n";
} else {
    cout << "Zero\n";
}
```

Exactly one category applies.

This is an ideal use for an `if / else if / else` chain.

---

# 38. Maximum of Two Values

```cpp
if (a > b) {
    cout << a;
} else {
    cout << b;
}
```

What about equality?

If:

```text
a == b
```

the `else` branch runs and prints `b`, which has the same numeric value.

But if the problem requires a distinct "equal" case, explicitly test it.

Problem requirements determine branch design.

---

# 39. Maximum of Three Values

One approach:

```cpp
if (a >= b && a >= c) {
    cout << a;
} else if (b >= a && b >= c) {
    cout << b;
} else {
    cout << c;
}
```

Notice:

```text
>=
```

handles ties naturally.

Later we will learn library tools such as `std::max`.

For now, conditionals teach the underlying reasoning.

---

# 40. Leap Year Logic

The Gregorian leap-year rule is a classic condition exercise.

A year is a leap year if:

```text
divisible by 400
OR
(divisible by 4 AND not divisible by 100)
```

C++:

```cpp
bool leap =
    year % 400 == 0 ||
    (year % 4 == 0 && year % 100 != 0);
```

This is a good example of translating a verbal requirement into Boolean logic.

Examples:

```text
2000 -> leap
1900 -> not leap
2024 -> leap
2023 -> not leap
```

---

# 41. Dry Run: Leap Year 1900

Expression:

```cpp
year % 400 == 0 ||
(year % 4 == 0 && year % 100 != 0)
```

For:

```text
year = 1900
```

First part:

```text
1900 % 400 = 300
300 == 0 -> false
```

Second group:

```text
1900 % 4 = 0
true
```

and:

```text
1900 % 100 = 0
0 != 0 -> false
```

So:

```text
true && false -> false
```

Finally:

```text
false || false -> false
```

Therefore 1900 is not a leap year.

---

# 42. Avoid Repeating Expensive Conditions

For simple integers:

```cpp
x > 10
```

is trivial.

Later, a condition could involve:

- function calls
- searches
- expensive calculations

If an expensive result is used repeatedly, it may be better to compute it once and store it.

Do not prematurely optimize tiny expressions, but learn to recognize repeated work.

---

# 43. Conditions Can Have Side Effects, But Be Careful

C++ allows expressions such as:

```cpp
if (++x > 5) {
    ...
}
```

This modifies `x` while testing.

Sometimes this is intentional, but it can make code harder to reason about.

Clearer:

```cpp
++x;

if (x > 5) {
    ...
}
```

In interviews and DSA, readable state changes are valuable.

---

# 44. Comparing Floating-Point Values

Avoid assuming that calculated floating-point values always behave like exact real numbers.

This may be unreliable for some computations:

```cpp
if (a == b) {
    ...
}
```

when `a` and `b` result from floating-point calculations.

Some numerical problems compare using a tolerance.

However, there is no single universal epsilon rule.

The correct comparison depends on:

- magnitude
- required error tolerance
- absolute vs relative error
- problem statement

Do not mechanically replace every floating-point comparison with one hard-coded epsilon.

---

# 45. Complexity of Conditionals

Checking a fixed number of primitive comparisons is normally:

```text
O(1)
```

Example:

```cpp
if (x > 0) {
    ...
}
```

The condition itself is constant-time in standard DSA analysis.

But an `if` statement does not make its body O(1).

Example concept:

```cpp
if (condition) {
    expensiveAlgorithm();
}
```

Total complexity depends on:

- cost of the condition
- cost of the branch that executes

For:

```text
if C then A else B
```

worst-case complexity is roughly:

```text
cost(C) + max(cost(A), cost(B))
```

This will become much more meaningful after loops and complexity analysis.

---

# 46. Common Interview Mistakes

1. Using `=` instead of `==`.

2. Writing:

```cpp
0 < x < 10
```

instead of:

```cpp
0 < x && x < 10
```

3. Writing:

```cpp
choice == 'y' || 'Y'
```

instead of repeating the comparison.

4. Putting broad `else-if` conditions before more specific ones.

5. Using separate `if` statements when only one category should execute.

6. Using `else-if` when multiple independent properties should be reported.

7. Forgetting braces and trusting indentation.

8. Accidentally writing:

```cpp
if (condition);
```

9. Forgetting `break` in `switch`.

10. Assuming every `switch` fallthrough is an error; sometimes it is intentional.

11. Trying to switch directly on `double` or `std::string`.

12. Using `switch` for ranges where `if` is clearer.

13. Putting a potentially unsafe check before its safety guard.

14. Over-nesting conditionals instead of combining clear Boolean conditions.

15. Writing side-effect-heavy conditions that are hard to debug.

16. Forgetting equality/tie cases in max/min style problems.

17. Treating floating-point comparisons as universally exact.

18. Printing debugging output that changes an online judge's expected output.

---

# 47. Complexity Table

| Construct | Condition Cost | Branch Behavior | Typical Extra Space |
|---|---:|---|---:|
| Simple `if` with scalar comparison | O(1) | body may execute | O(1) |
| `if-else` | O(1) condition | one branch executes | O(1) |
| k-condition else-if chain | O(k) worst case | first matching branch | O(1) |
| Nested fixed-depth conditionals | O(1) if depth fixed | path-dependent | O(1) |
| `switch` | implementation-dependent dispatch | matching case/path executes | O(1) typical |
| Fixed Boolean expression | O(1) | short-circuit possible | O(1) |

For a general `if`, the complexity of the condition and executed body must also be included. The table describes only the simple examples in this folder.

---

# 48. Practice Questions

1. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

2. LeetCode 2413 — Smallest Even Multiple  
   https://leetcode.com/problems/smallest-even-multiple/

3. GFG — Decision Making in C++  
   https://www.geeksforgeeks.org/decision-making-c-cpp/

4. HackerRank — Conditional Statements  
   https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

5. HackerRank — Day 3: Intro to Conditional Statements  
   https://www.hackerrank.com/challenges/30-conditional-statements/problem

After learning loops, many more useful conditional problems become available.

---

# 49. Final Checklist

You should be able to explain and use:

```text
control flow
if
else
else if
nested if
independent if statements
mutually exclusive branches
Boolean conditions
&&
||
!
short-circuiting
range checking
if ordering
braces
dangling else
switch
case
break
fallthrough
[[fallthrough]]
default
conditional operator vs if
```

You should be able to explain why:

```cpp
if (x = 5)
```

is different from:

```cpp
if (x == 5)
```

and why:

```cpp
if (x > 0) {
    ...
}

if (x % 2 == 0) {
    ...
}
```

has different behavior from:

```cpp
if (x > 0) {
    ...
} else if (x % 2 == 0) {
    ...
}
```

---

# What's Next

`01_C++__/07_LOOPS/`

Next we learn repetition with `while`, `do-while`, and `for`, including counters, accumulators, nested loops, `break`, `continue`, infinite loops, dry runs, and loop complexity.
