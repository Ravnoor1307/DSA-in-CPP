# Operators in C++

Path:

`DSA_JOURNEY/01_C++__/05_OPERATORS/`

## Prerequisites

You should already understand:

- variables and fundamental data types
- initialization and assignment
- implicit type conversion
- `static_cast`
- `cin` and `cout`
- integer vs floating-point values
- basic integer-overflow awareness

Operators let us calculate, compare, update, and combine values.

They are fundamental to virtually every algorithm we will write.

---

# 1. What Is an Operator?

An operator is a symbol or keyword that performs an operation on one or more operands.

Example:

```cpp
int result = 10 + 5;
```

Here:

```text
10 and 5 -> operands
+        -> operator
15       -> result
```

Real-world analogy:

Think of a calculator.

The numbers are the data:

```text
10
5
```

and the calculator operation:

```text
+
```

describes what should happen to them.

C++ operators play a similar role, although C++ has far more than arithmetic operations.

---

# 2. Operator Categories

The operators most important at this stage include:

```text
Arithmetic:
+  -  *  /  %

Unary:
+  -  ++  --

Assignment:
=  +=  -=  *=  /=  %=

Comparison:
==  !=  <  >  <=  >=

Logical:
&&  ||  !

Conditional:
?:

Other operators we have already seen:
sizeof
<<
>>
```

C++ also contains bitwise, pointer, member-access, indexing, function-call, allocation, casting and other operators.

We will study many of those in the folders where they become meaningful.

---

# 3. Arithmetic Operators

C++ provides:

```text
+   addition
-   subtraction
*   multiplication
/   division
%   remainder
```

Example:

```cpp
int a = 10;
int b = 3;

cout << a + b;
cout << a - b;
cout << a * b;
cout << a / b;
cout << a % b;
```

Results:

```text
13
7
30
3
1
```

The division deserves special attention.

---

# 4. Integer Division

When both operands are integers:

```cpp
7 / 2
```

the result is:

```text
3
```

not:

```text
3.5
```

Integer division discards the fractional part by truncating toward zero.

Examples:

```text
 7 / 2 =  3
-7 / 2 = -3
 7 / -2 = -3
```

provided the operation itself is representable; there is a special signed-overflow edge case such as the minimum signed value divided by `-1`.

For normal positive DSA values, remember:

```text
integer / integer -> integer division
```

---

# 5. Floating-Point Division

If floating-point arithmetic participates:

```cpp
7.0 / 2
```

the result is:

```text
3.5
```

If variables are integers:

```cpp
int a = 7;
int b = 2;
```

convert before dividing:

```cpp
double result =
    static_cast<double>(a) / b;
```

Result:

```text
3.5
```

Incorrect expectation:

```cpp
double result = a / b;
```

The division happens before assignment, producing `3`, which is then converted to `3.0`.

---

# 6. Remainder Operator %

For integers:

```cpp
7 % 2
```

produces:

```text
1
```

because:

```text
7 = 2 * 3 + 1
```

The `%` operator is extremely important in DSA.

Later uses include:

- checking divisibility
- even/odd checks
- cyclic indexing
- modular arithmetic
- digit extraction
- hashing
- number theory

Example:

```cpp
10 % 2
```

gives:

```text
0
```

so `10` is divisible by `2`.

---

# 7. Division and Remainder Relationship

For integers `a` and nonzero `b`, when the quotient is representable:

```text
q = a / b
r = a % b
```

C++ satisfies:

```text
a = q * b + r
```

For example:

```text
a = 17
b = 5

17 / 5 = 3
17 % 5 = 2

17 = 3 * 5 + 2
```

This identity becomes useful in many mathematical algorithms.

---

# 8. Negative Remainders

C++ integer division truncates toward zero.

The remainder is defined consistently with that quotient.

Example:

```cpp
-7 / 3
```

produces:

```text
-2
```

and:

```cpp
-7 % 3
```

produces:

```text
-1
```

because:

```text
-7 = (-2 * 3) + (-1)
```

This matters in modular arithmetic.

A mathematical modulo operation and C++ `%` are not always interchangeable for negative operands.

We will study normalization patterns later in modular arithmetic.

---

# 9. Division by Zero

Integer division by zero is undefined behavior.

Never do:

```cpp
int x = 10 / 0;
```

or:

```cpp
int divisor = 0;
int x = 10 / divisor;
```

Likewise integer remainder by zero is invalid.

Later, conditions will allow us to validate divisors before division.

Floating-point division follows floating-point rules and may produce infinities or NaNs on IEC 60559/IEEE-754-style implementations, but you should not use division by zero as ordinary application logic.

---

# 10. Arithmetic Overflow

Operators obey the limits of their operand types.

Consider:

```cpp
int a = 100000;
int b = 100000;

long long result = a * b;
```

This can already overflow during:

```cpp
a * b
```

if `int` cannot represent the result.

The `long long` destination comes too late.

Use:

```cpp
long long result = 1LL * a * b;
```

when wider arithmetic is required.

This is a recurring DSA pattern.

---

# 11. Unary Operators

A unary operator works on one operand.

Examples:

```cpp
+x
-x
!condition
++x
--x
```

Unary plus usually preserves the numeric value after promotions.

Unary minus changes the sign when the result is representable.

Example:

```cpp
int x = 5;

cout << -x;
```

Output:

```text
-5
```

`x` itself remains `5`.

---

# 12. Assignment Operator =

We have already used:

```cpp
int x = 10;
```

and later:

```cpp
x = 20;
```

The second `=` is assignment.

It stores the right-hand value, after required conversion, into the left-hand object.

Do not confuse:

```text
=
```

with:

```text
==
```

`=` performs assignment.

`==` tests equality.

This is one of the most common beginner mistakes.

---

# 13. Compound Assignment

Instead of:

```cpp
x = x + 5;
```

we can often write:

```cpp
x += 5;
```

Other forms:

```cpp
x -= 5;
x *= 5;
x /= 5;
x %= 5;
```

Example:

```cpp
int score = 10;

score += 5;
```

Final state:

```text
score = 15
```

Compound assignment is not merely textual substitution in every type-conversion corner case, but for simple same-type integer examples this mental model is useful.

---

# 14. Full Dry Run: Compound Assignment

Code:

```cpp
int x = 10;

x += 5;
x *= 2;
x -= 4;
```

Start:

```text
x = 10
```

After:

```cpp
x += 5;
```

state:

```text
x = 15
```

After:

```cpp
x *= 2;
```

state:

```text
x = 30
```

After:

```cpp
x -= 4;
```

state:

```text
x = 26
```

Final:

```text
x = 26
```

---

# 15. Increment Operator ++

Increment adds one.

Instead of:

```cpp
x = x + 1;
```

we can write:

```cpp
++x;
```

or:

```cpp
x++;
```

When used as standalone statements:

```cpp
++x;
```

and:

```cpp
x++;
```

both increment `x` by one.

Their difference matters when the expression's value is used.

---

# 16. Prefix Increment

```cpp
++x
```

increments first and yields the incremented value.

Example:

```cpp
int x = 5;
int y = ++x;
```

Dry run:

```text
x = 5

++x:
x becomes 6

expression value = 6

y receives 6
```

Final:

```text
x = 6
y = 6
```

---

# 17. Postfix Increment

```cpp
x++
```

yields the old value, while incrementing `x` as part of the expression.

Example:

```cpp
int x = 5;
int y = x++;
```

Conceptual dry run:

```text
x = 5

x++ expression yields old value 5
y receives 5

x is incremented to 6
```

Final:

```text
x = 6
y = 5
```

This distinction is commonly tested.

---

# 18. Decrement Operator --

Likewise:

```cpp
--x
```

is prefix decrement.

```cpp
x--
```

is postfix decrement.

Example:

```cpp
int x = 5;

int a = --x;
```

Final:

```text
x = 4
a = 4
```

Whereas:

```cpp
int x = 5;

int a = x--;
```

Final:

```text
x = 4
a = 5
```

---

# 19. Avoid Clever Increment Expressions

Do not write expressions that modify the same scalar repeatedly without understanding sequencing rules.

Code such as:

```cpp
i = i++ + ++i;
```

is exactly the kind of expression you should avoid.

Depending on the expression and language rules, multiple unsequenced modifications/accesses can lead to undefined behavior.

Even when a complicated expression is technically well-defined, it is often poor code.

Prefer clear separate statements.

DSA code should optimize algorithms, not maximize expression cleverness.

---

# 20. Comparison Operators

Comparison operators produce a Boolean result.

```text
==   equal
!=   not equal
<    less than
>    greater than
<=   less than or equal
>=   greater than or equal
```

Example:

```cpp
int a = 5;
int b = 10;

cout << (a < b);
```

Default Boolean output:

```text
1
```

With:

```cpp
cout << boolalpha;
```

output becomes:

```text
true
```

---

# 21. Equality vs Assignment

Compare:

```cpp
x = 5;
```

with:

```cpp
x == 5
```

The first changes `x`.

The second asks:

```text
Is x equal to 5?
```

and produces:

```text
true
```

or:

```text
false
```

Later, inside conditions, accidentally writing:

```cpp
if (x = 5)
```

instead of:

```cpp
if (x == 5)
```

can create a serious logic bug.

Compilers may warn about suspicious assignment-in-condition code, which is another reason to compile with warnings enabled.

---

# 22. Logical Operators

Logical operators combine or invert Boolean conditions.

```text
&&   logical AND
||   logical OR
!    logical NOT
```

---

# 23. Logical AND

Expression:

```cpp
a && b
```

is true only when both operands are logically true.

Truth table:

```text
false && false -> false
false && true  -> false
true  && false -> false
true  && true  -> true
```

Real-world analogy:

Suppose entry to an exam requires:

```text
has ID
AND
has admit card
```

Both requirements must be satisfied.

---

# 24. Logical OR

Expression:

```cpp
a || b
```

is true when at least one operand is logically true.

```text
false || false -> false
false || true  -> true
true  || false -> true
true  || true  -> true
```

Analogy:

A payment system might accept:

```text
cash
OR
card
```

Either accepted method is sufficient.

---

# 25. Logical NOT

Expression:

```cpp
!value
```

negates logical truth.

```text
!true  -> false
!false -> true
```

Example:

```cpp
bool finished = false;

cout << !finished;
```

produces Boolean true.

---

# 26. Non-Bool Values in Logical Contexts

Numeric values can convert to `bool`.

```text
0       -> false
nonzero -> true
```

Therefore:

```cpp
!0
```

is:

```text
true
```

and:

```cpp
!5
```

is:

```text
false
```

Even so, explicit Boolean conditions are often clearer.

---

# 27. Short-Circuit Evaluation

`&&` and `||` short-circuit.

This is a crucial DSA concept.

For:

```cpp
left && right
```

if `left` is false, `right` is not evaluated because the complete expression must already be false.

For:

```cpp
left || right
```

if `left` is true, `right` is not evaluated because the complete expression must already be true.

---

# 28. Real-World Analogy for Short-Circuiting

Suppose you ask:

```text
Is the store open AND does it have the product?
```

If you already know:

```text
the store is closed
```

you do not need to inspect its shelves to conclude that the full requirement is not satisfied.

Similarly:

```cpp
false && expensiveCheck()
```

does not need the second check.

Short-circuiting later allows safe conditions such as:

```cpp
index < n && array[index] == target
```

The bounds check can prevent evaluating the array access when the index is invalid.

Arrays come later, but the pattern is extremely important.

---

# 29. Demonstrating Short-Circuiting Without Functions

We have not formally learned user-defined functions yet, but side effects can still demonstrate the rule.

Example:

```cpp
int x = 0;

bool result =
    false && (++x > 0);
```

Because the left operand is false:

```text
++x
```

is never evaluated.

Final:

```text
x = 0
result = false
```

For OR:

```cpp
int x = 0;

bool result =
    true || (++x > 0);
```

Again, `++x` is not evaluated.

---

# 30. Bitwise Operators: Preview

C++ also has:

```text
&    bitwise AND
|    bitwise OR
^    bitwise XOR
~    bitwise NOT
<<   left shift
>>   right shift
```

These manipulate integer representations at the bit level.

Do not confuse:

```text
&&
```

with:

```text
&
```

or:

```text
||
```

with:

```text
|
```

Bit manipulation has its own dedicated folder:

```text
03_COMPLEXITY_AND_MATH__/29_BIT_MANIPULATION_BASICS/
```

Important contextual note:

`<<` and `>>` are also overloaded for C++ streams:

```cpp
cout << value;
cin >> value;
```

The meaning depends on operand types.

---

# 31. Operator Overloading Preview

How can:

```cpp
cout << value;
```

and integer bit shifting both use:

```text
<<
```

C++ allows operators to have meanings associated with operand types, including overloaded operators for class types.

The stream insertion operation uses an overloaded `operator<<`.

Operator overloading receives its own later folder:

```text
01_C++__/24_OPERATOR_OVERLOADING/
```

---

# 32. Conditional Operator ?:

C++ has a conditional operator:

```cpp
condition ? value_if_true : value_if_false
```

Example:

```cpp
int a = 10;
int b = 20;

int smaller =
    (a < b) ? a : b;
```

Result:

```text
smaller = 10
```

Real-world analogy:

```text
if raining?
    take umbrella
otherwise
    take sunglasses
```

Compact representation:

```text
raining ? umbrella : sunglasses
```

Conditions receive a full folder next.

---

# 33. Conditional Operator Short-Circuit Behavior

Only one of the second and third operands is evaluated after the condition is determined.

Example:

```cpp
bool condition = true;

int x = condition ? 10 : 20;
```

Only the selected branch contributes the result.

This is important when branch expressions have side effects or potentially invalid operations.

---

# 34. sizeof Is an Operator

We have previously used:

```cpp
sizeof(int)
```

`sizeof` is an operator.

It returns the size, in bytes, of a type or expression's type/object representation.

Example:

```cpp
int x = 10;

cout << sizeof(x);
```

For ordinary expressions, the expression operand of `sizeof` is generally unevaluated.

Example:

```cpp
int x = 5;

cout << sizeof(x++);
```

`x` is not incremented.

However, avoid using side effects inside unevaluated contexts just to demonstrate clever language rules.

Write clear code.

---

# 35. Precedence

Consider:

```cpp
2 + 3 * 4
```

Which operation occurs first?

Multiplication has higher precedence than addition.

Therefore:

```text
3 * 4 = 12
2 + 12 = 14
```

not:

```text
(2 + 3) * 4 = 20
```

Operator precedence determines how an expression is grouped when parentheses do not explicitly specify grouping.

---

# 36. Parentheses

You can explicitly control grouping:

```cpp
(2 + 3) * 4
```

Now:

```text
2 + 3 = 5
5 * 4 = 20
```

For readable DSA code, use parentheses when they make intent clearer even if you technically know the precedence rules.

---

# 37. Important Precedence Ordering

You do not need to memorize the entire C++ precedence table immediately.

Important relative ordering includes:

```text
postfix ++ --
unary ! ++ -- + -
* / %
+ -
< <= > >=
== !=
&&
||
?:
assignment = += -= ...
```

Parentheses override default grouping.

Full language details are more nuanced, but this ordering covers many early expressions.

---

# 38. Equality vs Relational Precedence

Relational operators:

```text
< <= > >=
```

have higher precedence than:

```text
== !=
```

Do not write intentionally confusing expressions relying on this knowledge.

Prefer explicit parentheses where interpretation is not obvious.

---

# 39. Logical Precedence

`&&` has higher precedence than `||`.

Thus:

```cpp
a || b && c
```

is grouped as:

```cpp
a || (b && c)
```

For human readers, this is usually clearer:

```cpp
a || (b && c)
```

Parentheses are cheap. Debugging misunderstood conditions is not.

---

# 40. Associativity

Precedence decides which operator binds more strongly.

Associativity decides grouping among operators at the same precedence level.

Addition is left-associative:

```cpp
a - b - c
```

groups as:

```cpp
(a - b) - c
```

Assignment is right-associative:

```cpp
a = b = 5;
```

groups roughly as:

```cpp
a = (b = 5);
```

Afterward:

```text
a = 5
b = 5
```

---

# 41. Evaluation Order Is a Different Concept

This is an advanced but essential distinction.

Operator precedence tells you how an expression is parsed/grouped.

It does not universally tell you the order in which every operand is evaluated.

These concepts are different:

```text
precedence
associativity
evaluation order
sequencing
```

Do not infer execution order merely from precedence.

This matters significantly when expressions contain side effects.

For now, keep side effects in separate statements whenever practical.

---

# 42. Chained Comparisons Do Not Work Like Mathematics

In mathematics:

```text
0 < x < 10
```

is meaningful.

Do not directly write that in C++ expecting mathematical chaining:

```cpp
0 < x < 10
```

C++ groups the first comparison and produces a Boolean, then compares that result to `10`.

Correct logical form:

```cpp
0 < x && x < 10
```

This becomes important immediately when learning conditions.

---

# 43. Floating-Point Equality

From our data-type lesson, many decimals are approximated in binary floating-point.

Therefore calculations involving floating-point values may not be suitable for naïve exact equality tests.

Example concept:

```cpp
0.1 + 0.2
```

may not produce exactly the same floating representation as the literal `0.3`.

For numerical algorithms, comparisons may require an error tolerance depending on the problem.

A common conceptual approach is:

```text
absolute difference <= epsilon
```

We have not learned `<cmath>` and numerical analysis yet, so do not blindly copy one epsilon rule into every problem.

The appropriate comparison depends on scale and problem guarantees.

---

# 44. Comma Operator vs Declaration Separators

You may see:

```cpp
int a = 1, b = 2;
```

The comma here separates declarators.

C++ also has a comma operator in expression contexts.

Example:

```cpp
int x = (1, 2);
```

The comma operator evaluates the left expression, then the right, and the overall value is the right expression's value.

Thus:

```text
x = 2
```

This operator is rarely needed in beginner DSA code outside contexts such as certain `for` loop expressions.

Do not introduce it unnecessarily.

---

# 45. Operators We Will Study Later

Several operators make much more sense after their related concepts are learned:

```text
[]       indexing/subscript
()       function call
*        pointer dereference
&        address-of
->       pointer member access
.        member access
new      dynamic allocation
delete   dynamic deallocation
& | ^ ~  bitwise operations
<< >>    shifts
```

They are not omitted from the roadmap.

They are deliberately taught with their prerequisites.

---

# 46. Full Dry Run: Arithmetic Expression

Expression:

```cpp
int result = 2 + 3 * 4;
```

Initial:

```text
No result value yet.
```

Precedence grouping:

```text
2 + (3 * 4)
```

Step 1:

```text
3 * 4 = 12
```

Step 2:

```text
2 + 12 = 14
```

Step 3:

```text
result = 14
```

---

# 47. Full Dry Run: Parenthesized Expression

```cpp
int result = (2 + 3) * 4;
```

Grouping:

```text
(2 + 3) * 4
```

Step 1:

```text
2 + 3 = 5
```

Step 2:

```text
5 * 4 = 20
```

Final:

```text
result = 20
```

---

# 48. Full Dry Run: Prefix vs Postfix

Code:

```cpp
int x = 5;

int a = x++;
int b = ++x;
```

Initial:

```text
x = 5
```

Execute:

```cpp
a = x++;
```

Postfix yields old value:

```text
a = 5
```

then `x` becomes:

```text
x = 6
```

Execute:

```cpp
b = ++x;
```

Prefix increments:

```text
x = 7
```

then yields:

```text
b = 7
```

Final state:

```text
x = 7
a = 5
b = 7
```

---

# 49. Full Dry Run: Short Circuit

Code:

```cpp
int x = 0;

bool result =
    false && (++x > 0);
```

Evaluate left operand:

```text
false
```

For logical AND:

```text
false && anything
```

must be false.

Therefore right operand is skipped:

```text
++x is NOT executed
```

Final:

```text
x = 0
result = false
```

This ability to prevent evaluation becomes essential for safe boundary checks.

---

# 50. Common Interview Mistakes

## Mistake 1: Integer division

```cpp
double x = 5 / 2;
```

produces:

```text
2.0
```

not `2.5`.

## Mistake 2: int overflow before long long assignment

Potentially dangerous:

```cpp
long long product = a * b;
```

Use wider arithmetic before multiplication when required:

```cpp
long long product = 1LL * a * b;
```

## Mistake 3: Assignment instead of comparison

```text
=
```

and:

```text
==
```

are different.

## Mistake 4: Misunderstanding prefix/postfix

```cpp
y = x++;
```

and:

```cpp
y = ++x;
```

can produce different `y`.

## Mistake 5: Division/remainder by zero

Never perform integer:

```cpp
a / 0
a % 0
```

## Mistake 6: Assuming % is always mathematical modulo for negatives

C++ remainder can be negative.

## Mistake 7: Writing chained mathematical comparisons

Wrong:

```cpp
0 < x < 10
```

Correct:

```cpp
0 < x && x < 10
```

## Mistake 8: Confusing && and &

```text
&& -> logical AND
&  -> bitwise AND / address-related uses depending on context
```

## Mistake 9: Confusing || and |

```text
|| -> logical OR
|  -> bitwise OR
```

## Mistake 10: Ignoring short-circuit behavior

Correct operand ordering can protect potentially unsafe operations.

## Mistake 11: Overusing precedence knowledge

Use parentheses when they improve readability.

## Mistake 12: Assuming precedence means evaluation order

They are different concepts.

## Mistake 13: Comparing floating-point calculations carelessly

Exact equality may not model the numerical intent.

## Mistake 14: Writing side-effect-heavy expressions

Prefer:

```cpp
++x;
++x;
```

over difficult expressions that modify a variable several times.

---

# 51. Complexity Analysis

Primitive operators are treated as constant-time operations in standard introductory DSA analysis for fixed-width machine types.

| Operation | Typical DSA Time | Auxiliary Space |
|---|---:|---:|
| Addition/subtraction | O(1) | O(1) |
| Fixed-width multiplication | O(1) | O(1) |
| Fixed-width division/remainder | O(1) | O(1) |
| Comparison | O(1) | O(1) |
| Logical operation | O(1) | O(1) |
| Increment/decrement | O(1) | O(1) |
| Assignment of scalar | O(1) | O(1) |
| `static_cast` scalar conversion | O(1) | O(1) |
| Conditional operator with constant-time branches | O(1) | O(1) |

Later, operators on arbitrary-precision numbers, strings, containers, matrices, or user-defined types may have nonconstant costs.

The operator symbol alone does not universally determine complexity; operand types matter.

---

# 52. Practice Questions

1. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

2. LeetCode 2413 — Smallest Even Multiple  
   https://leetcode.com/problems/smallest-even-multiple/

3. LeetCode 1281 — Subtract the Product and Sum of Digits of an Integer  
   https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

4. GFG — Operators in C++  
   https://www.geeksforgeeks.org/operators-in-cpp/

5. HackerRank — Operators  
   https://www.hackerrank.com/challenges/30-operators/problem

Some problems use conditions or loops. Bookmark them if they require concepts from upcoming folders.

---

# 53. Final Checklist

You should understand:

```text
operand
operator
arithmetic operators
integer division
floating-point division
remainder
negative remainder behavior
division by zero
assignment
compound assignment
unary operators
prefix ++
postfix ++
prefix --
postfix --
comparison operators
logical operators
short-circuit evaluation
conditional operator
sizeof
precedence
associativity
evaluation-order distinction
integer overflow in expressions
chained-comparison mistake
bitwise-vs-logical distinction
```

You should be able to explain why:

```cpp
double result = 7 / 2;
```

differs from:

```cpp
double result =
    static_cast<double>(7) / 2;
```

and why:

```cpp
long long product = a * b;
```

can still be unsafe when `a` and `b` are `int`.

---

# What's Next

`01_C++__/06_CONDITIONALS/`

Next we use Boolean expressions and operators to make programs choose different execution paths with `if`, `else if`, `else`, nested conditions, and `switch`.
