# Input and Output in C++

Path:

`DSA_JOURNEY/01_C++__/04_INPUT_OUTPUT/`

## Prerequisites

You should already understand:

- basic C++ program structure
- variables
- fundamental data types
- initialization and assignment
- type conversion
- `static_cast`
- basic `cout`

This folder turns our programs from fixed demonstrations into programs that can receive data.

---

# 1. What Is Input and Output?

A program usually communicates with the outside world.

Input is information received by the program.

Output is information produced by the program.

Conceptually:

```text
          INPUT
            |
            v
      +-----------+
      | PROGRAM   |
      +-----------+
            |
            v
          OUTPUT
```

Example:

```text
Input:
25

Program:
read the number

Output:
25
```

In DSA platforms, the input usually comes from test cases supplied by an online judge rather than a human manually typing every value.

---

# 2. Standard Streams

C++ provides standard stream objects including:

```cpp
std::cin
std::cout
std::cerr
std::clog
```

Their common roles are:

```text
cin   -> standard input
cout  -> standard output
cerr  -> standard error
clog  -> logging/error-oriented output
```

The most important ones for early DSA are:

```cpp
cin
cout
```

---

# 3. Real-World Analogy: Communication Channels

Imagine a restaurant kitchen.

Customers send orders into the kitchen:

```text
orders -> kitchen
```

The kitchen sends completed dishes outward:

```text
kitchen -> dishes
```

A program has similar channels.

```text
input data
    |
    v
   cin
    |
    v
 program
    |
    v
   cout
    |
    v
output data
```

The analogy is useful because input and output are streams: values conceptually flow through communication channels.

---

# 4. Basic Input with cin

Suppose we want to read an integer.

```cpp
int age;

cin >> age;
```

If the input is:

```text
20
```

after extraction:

```text
age = 20
```

The operator:

```text
>>
```

is called the extraction operator in this stream context.

It extracts formatted data from the input stream.

---

# 5. Basic Output with cout

We already know:

```cpp
cout << age;
```

The operator:

```text
<<
```

inserts data into the output stream.

Mental model:

```text
cin >> variable
```

means:

```text
input stream
     |
     v
 variable
```

while:

```text
cout << value
```

means:

```text
 value
   |
   v
output stream
```

---

# 6. Complete Input/Output Program

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;

    cin >> age;

    cout << age << '\n';

    return 0;
}
```

Example input:

```text
25
```

Output:

```text
25
```

Dry run:

```text
Before cin:
age has not been given a usable value.

Input stream:
25

Execute:
cin >> age;

State:
age = 25

Execute:
cout << age;

Output:
25
```

---

# 7. Why Input Variables Should Already Have the Correct Type

Consider:

```cpp
int age;
cin >> age;
```

`cin` parses input according to the type of `age`.

Input:

```text
42
```

can be read as an integer.

Similarly:

```cpp
double price;
cin >> price;
```

can read:

```text
19.95
```

And:

```cpp
char grade;
cin >> grade;
```

can read:

```text
A
```

The destination type affects how formatted extraction interprets the incoming characters.

---

# 8. Reading Multiple Values

We can chain extraction operations:

```cpp
int a;
int b;

cin >> a >> b;
```

Input:

```text
10 20
```

Final state:

```text
a = 10
b = 20
```

You can think of it as:

```text
input stream:
10 20

first extraction:
a = 10

remaining stream:
20

second extraction:
b = 20
```

---

# 9. Whitespace with cin >>

For most formatted extraction operations, leading whitespace is skipped automatically.

That includes spaces, tabs, and newlines.

Therefore these inputs are equivalent for:

```cpp
cin >> a >> b >> c;
```

Input A:

```text
10 20 30
```

Input B:

```text
10
20
30
```

Input C:

```text
10     20
30
```

All can result in:

```text
a = 10
b = 20
c = 30
```

This is extremely useful in competitive programming.

You normally do not need to care whether the judge places integers on one line or several lines when using formatted `>>` extraction.

---

# 10. Reading Different Types

Example:

```cpp
int age;
double height;
char grade;

cin >> age >> height >> grade;
```

Input:

```text
18 175.5 A
```

Final state:

```text
age    = 18
height = 175.5
grade  = 'A'
```

---

# 11. Reading bool

By default, formatted input into a `bool` expects numeric Boolean representation.

Example:

```cpp
bool value;
cin >> value;
```

Input:

```text
1
```

gives:

```text
true
```

Input:

```text
0
```

gives:

```text
false
```

If the stream uses:

```cpp
boolalpha
```

then textual forms can be read:

```text
true
false
```

Example:

```cpp
cin >> boolalpha >> value;
```

We rarely need direct Boolean input in typical DSA problems.

---

# 12. Strings Preview

Full strings are studied later.

For now it is useful to understand the difference between:

```cpp
cin >> word;
```

and:

```cpp
getline(cin, line);
```

Extraction with `>>` reads a whitespace-delimited token.

Suppose:

```cpp
string name;

cin >> name;
```

Input:

```text
Ada Lovelace
```

`name` receives only:

```text
Ada
```

because whitespace ends the token.

To read an entire line, C++ provides:

```cpp
getline(cin, name);
```

Then:

```text
Ada Lovelace
```

can be read as the whole line.

We will study strings properly in:

```text
01_C++__/13_STRINGS_AND_C_STRINGS/
```

---

# 13. The cin >> Then getline Problem

A famous beginner problem appears when mixing formatted extraction with `getline`.

Example:

```cpp
int age;
string name;

cin >> age;
getline(cin, name);
```

Suppose input is:

```text
20
Ada Lovelace
```

After:

```cpp
cin >> age;
```

the integer is extracted, but the newline after `20` generally remains in the input buffer.

Then:

```cpp
getline(cin, name);
```

immediately encounters that newline and returns an empty line.

Conceptually:

```text
initial stream:

20\nAda Lovelace\n
```

After:

```cpp
cin >> age;
```

state:

```text
age = 20

remaining:
\nAda Lovelace\n
^
```

Then `getline` sees the first newline and reads an empty line.

---

# 14. Solving cin >> Then getline

One common solution is:

```cpp
#include <limits>

cin >> age;

cin.ignore(
    numeric_limits<streamsize>::max(),
    '\n'
);

getline(cin, name);
```

This discards characters through the pending newline.

For simple cases, you may also see:

```cpp
cin.ignore();
```

but blindly ignoring exactly one character is less robust when the remaining input contains more than a single newline character.

Another useful technique is:

```cpp
getline(cin >> ws, name);
```

`std::ws` consumes leading whitespace before `getline`.

Be careful: using `ws` means intentional leading whitespace in the line is also discarded.

---

# 15. Input Failure

What if we write:

```cpp
int age;
cin >> age;
```

but input contains:

```text
hello
```

Formatted integer extraction cannot parse `hello` as an integer.

The stream enters a failure state.

This can be tested:

```cpp
if (cin) {
    // stream is usable
}
```

or directly:

```cpp
if (cin >> age) {
    // extraction succeeded
}
```

Conditionals are taught later, so you only need the concept for now.

A failed stream generally needs its state cleared and problematic input handled before additional extraction can proceed normally.

---

# 16. EOF

EOF means:

```text
End Of File
```

It indicates that there is no more input available from the source.

Competitive-programming problems sometimes provide an unknown number of values until EOF.

Later you may write:

```cpp
while (cin >> value) {
    ...
}
```

This means:

```text
keep processing while extraction succeeds
```

We have not learned loops yet, so treat this as a preview.

---

# 17. Output Formatting

`cout` can format numbers.

A useful header is:

```cpp
#include <iomanip>
```

It provides manipulators such as:

```cpp
fixed
setprecision
setw
setfill
```

---

# 18. setprecision Without fixed

Consider:

```cpp
double x = 12.34567;

cout << setprecision(4) << x;
```

Without `fixed`, `setprecision(4)` normally controls the number of significant digits under the default floating-point format.

Possible output:

```text
12.35
```

This is not the same as saying "four digits after the decimal point."

---

# 19. fixed + setprecision

To specify digits after the decimal point:

```cpp
cout << fixed << setprecision(2);
```

Then:

```cpp
double price = 19.5;

cout << price;
```

Output:

```text
19.50
```

This is very common in problems requiring formatted decimal output.

---

# 20. Formatting State Persists

A subtle but important concept:

```cpp
cout << fixed << setprecision(2);
```

changes formatting state on the stream.

Later floating-point output continues using this formatting until changed.

Example:

```cpp
cout << fixed << setprecision(2);

cout << 3.14159 << '\n';
cout << 9.5 << '\n';
```

Output:

```text
3.14
9.50
```

If needed, formatting can be changed again using manipulators such as:

```cpp
defaultfloat
```

---

# 21. setw

`setw` sets the minimum width for the next formatted field.

Example:

```cpp
cout << setw(5) << 42;
```

Conceptually:

```text
___42
```

where underscores represent spaces.

Important:

`setw` generally affects the next insertion only.

Example:

```cpp
cout << setw(5) << 1;
cout << 2;
```

The second output does not automatically receive the same width.

---

# 22. setfill

You can change the padding character.

Example:

```cpp
cout << setfill('0')
     << setw(4)
     << 7;
```

Output:

```text
0007
```

Formatting becomes useful for clocks, tables, IDs, and output-constrained problems.

---

# 23. left and right

Alignment manipulators include:

```cpp
left
right
```

Example:

```cpp
cout << left << setw(10) << "C++";
```

or:

```cpp
cout << right << setw(10) << "C++";
```

`left` and `right` affect alignment state and persist until changed.

---

# 24. endl vs '\n'

You already learned that:

```cpp
cout << '\n';
```

adds a newline.

And:

```cpp
cout << endl;
```

adds a newline and flushes the stream.

Flushing means requesting that buffered output be pushed toward its destination.

For ordinary batch-style DSA output:

```cpp
'\n'
```

is usually preferable.

Repeated unnecessary flushing can make output slower.

---

# 25. What Is Buffering?

Input/output is relatively expensive compared with simple CPU operations.

Libraries and operating systems therefore often process I/O in chunks.

Real-world analogy:

Suppose you have 100 letters to deliver.

One strategy:

```text
drive to post office
deliver one letter
drive home

repeat 100 times
```

Another strategy:

```text
collect many letters
drive once
deliver batch
```

Buffering follows a similar idea.

Instead of performing an expensive low-level operation for every character, data can be accumulated and transferred more efficiently.

---

# 26. cerr

`cerr` represents standard error.

Example:

```cpp
cerr << "Something went wrong\n";
```

Standard output and standard error are conceptually different streams.

This matters when output is redirected or when an online judge expects exact standard output.

Do not print debugging information with `cout` in submitted solutions unless the problem expects it.

You can use `cerr` for debugging in many local/contest environments, but remove or control debug output appropriately.

---

# 27. clog

`clog` is another standard stream associated with diagnostic/logging output.

It differs in buffering behavior from `cerr` in typical implementations.

For beginner DSA:

```text
cout -> answer output
cerr -> useful debug/error channel
```

is enough to remember.

---

# 28. Competitive Programming Fast I/O

You will frequently see:

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

near the beginning of `main`.

Example:

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ...
}
```

These settings can improve C++ stream performance.

---

# 29. ios::sync_with_stdio(false)

By default, C++ iostreams are synchronized with the C standard I/O streams.

Calling:

```cpp
ios::sync_with_stdio(false);
```

disables that synchronization.

This can significantly improve stream performance.

Important consequence:

After disabling synchronization, carelessly mixing C++ stream I/O:

```cpp
cin
cout
```

with C-style I/O:

```cpp
scanf
printf
```

can lead to unexpected ordering/behavior.

For this roadmap, once we use fast C++ I/O, stick to C++ streams.

---

# 30. cin.tie(nullptr)

By default, `cin` is tied to `cout`.

This connection can cause `cout` to be flushed before an input operation.

That is useful for interactive prompts.

For normal non-interactive competitive-programming input, it is often unnecessary.

Therefore:

```cpp
cin.tie(nullptr);
```

removes that tie and can reduce unnecessary flushing.

---

# 31. Batch Problems vs Interactive Problems

Most DSA problems are batch problems:

```text
judge gives complete input
        |
        v
program computes
        |
        v
program prints answer
```

Interactive problems are different:

```text
program prints query
        |
        v
judge responds
        |
        v
program prints next query
```

In interactive problems, flushing output may be essential.

Therefore blindly avoiding all flushes is wrong.

The context matters.

We will focus primarily on batch-style DSA.

---

# 32. Do Not Print Prompts in Online Judges

For a local beginner program you might write:

```cpp
cout << "Enter age: ";
cin >> age;
```

But an online judge usually expects exact output.

If expected output is:

```text
20
```

and your program prints:

```text
Enter age: 20
```

the answer can be rejected.

In judged solutions, normally use:

```cpp
cin >> age;
cout << age << '\n';
```

without decorative prompts unless requested.

---

# 33. Full Dry Run: Multiple Inputs

Code:

```cpp
int a;
double b;
char c;

cin >> a >> b >> c;
```

Input:

```text
10 2.5 X
```

Initial state:

```text
a = uninitialized
b = uninitialized
c = uninitialized

input:
10 2.5 X
```

First extraction:

```text
cin >> a

a = 10

remaining:
2.5 X
```

Second extraction:

```text
cin >> b

b = 2.5

remaining:
X
```

Third extraction:

```text
cin >> c

c = 'X'
```

Final state:

```text
a = 10
b = 2.5
c = 'X'
```

---

# 34. Full Dry Run: Whitespace

Code:

```cpp
int a;
int b;

cin >> a >> b;
```

Input:

```text


10

     20
```

Formatted extraction skips leading whitespace.

State transition:

```text
skip whitespace
read 10
a = 10

skip whitespace
read 20
b = 20
```

Final:

```text
a = 10
b = 20
```

This is why standard formatted extraction is convenient for judge input.

---

# 35. Full Dry Run: cin + getline

Conceptual input:

```text
21\n
Ada Lovelace\n
```

Code:

```cpp
int age;
string name;

cin >> age;
getline(cin, name);
```

After integer extraction:

```text
age = 21

remaining stream:
\nAda Lovelace\n
^
```

Then:

```cpp
getline(cin, name);
```

sees the immediate newline.

Result:

```text
name = ""
```

Corrected version:

```cpp
cin >> age;

cin.ignore(
    numeric_limits<streamsize>::max(),
    '\n'
);

getline(cin, name);
```

After `ignore`:

```text
remaining:
Ada Lovelace\n
```

Then:

```text
name = "Ada Lovelace"
```

---

# 36. Reading char and Whitespace

This is an important subtlety.

Formatted extraction:

```cpp
char c;
cin >> c;
```

normally skips leading whitespace.

If input is:

```text
   A
```

`c` becomes:

```text
'A'
```

If you actually need to read whitespace characters themselves, different techniques such as:

```cpp
cin.get(c);
```

may be appropriate.

Strings and character processing are covered later.

---

# 37. put() and get()

Streams also provide lower-level character operations.

Example:

```cpp
char c;
cin.get(c);
cout.put(c);
```

Unlike formatted:

```cpp
cin >> c;
```

`cin.get(c)` can read whitespace characters.

You do not need these for normal numeric input, but understanding that formatted and unformatted I/O differ is useful.

---

# 38. Stream States

Streams maintain status information.

Important concepts include:

```text
good
eof
fail
bad
```

Related functions include:

```cpp
cin.good()
cin.eof()
cin.fail()
cin.bad()
```

Very roughly:

```text
good -> no error flags preventing normal operation

eof  -> end of input encountered

fail -> formatted/unformatted operation failed

bad  -> serious stream error
```

Do not build complex recovery logic yet.

The important lesson is:

`cin` is not guaranteed to successfully read whatever characters it receives.

---

# 39. Output Precision Is Not Storage Precision

Consider:

```cpp
double x = 3.141592653589793;

cout << fixed << setprecision(2) << x;
```

Output:

```text
3.14
```

This does not mean `x` itself has been permanently changed to:

```text
3.14
```

Only its textual output representation was formatted.

The stored value remains the same `double` value.

This distinction is important.

Formatting output does not alter the variable.

---

# 40. Common Interview and Competitive Programming Mistakes

## 1. Printing prompts

Wrong for most judges:

```cpp
cout << "Enter n: ";
cin >> n;
```

The extra text may make the answer incorrect.

## 2. Mixing cin >> and getline carelessly

The remaining newline can cause `getline` to read an empty line.

## 3. Thinking cin >> string reads spaces

It normally reads one whitespace-delimited token.

## 4. Using endl for every output line

This causes unnecessary flushing.

Prefer:

```cpp
'\n'
```

for normal batch output.

## 5. Forgetting fixed

```cpp
setprecision(2)
```

does not necessarily mean two digits after the decimal point.

For that, normally use:

```cpp
fixed << setprecision(2)
```

## 6. Thinking setprecision modifies the variable

It only controls output formatting.

## 7. Assuming input always succeeds

Malformed input can place `cin` in a failure state.

## 8. Mixing scanf/printf with cin/cout after disabling synchronization

Avoid this unless you deeply understand the interaction.

## 9. Forgetting exact-output requirements

Online judges can reject answers because of extra words or formatting.

## 10. Forgetting whitespace behavior for char

```cpp
cin >> c;
```

usually skips leading whitespace.

`cin.get(c)` behaves differently.

## 11. Using fast I/O without understanding interactive problems

Interactive output may require explicit flushing.

## 12. Assuming setw permanently changes width

`setw` normally affects only the next formatted insertion.

---

# 41. Complexity Analysis

For algorithmic analysis, reading or writing a single fixed-size scalar is usually modeled as constant work.

For `n` values, total I/O is generally linear in the amount of data processed.

| Operation | Simplified Time | Auxiliary Space |
|---|---:|---:|
| Read one scalar | O(1)* | O(1) |
| Write one scalar | O(1)* | O(1) |
| Read n scalar values | O(n)* | O(1) besides stored values |
| Write n scalar values | O(n)* | O(1) algorithmic auxiliary space |
| Read line of length n | O(n) | O(n) to store the line |
| Print string of length n | O(n) | O(1) algorithmic auxiliary space |
| `setw`, `fixed`, `setprecision` setup | O(1) model | O(1) |

`*` The actual cost also depends on textual length, buffering, library implementation, and operating-system I/O. This table is the simplified DSA model.

---

# 42. Standard Competitive Programming Skeleton

After this folder, this program should look familiar:

```cpp
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << n << '\n';

    return 0;
}
```

You do not need fast I/O for tiny programs.

It is useful to recognize the pattern because you will encounter it constantly.

---

# 43. Practice Questions

1. HackerRank — Input and Output  
   https://www.hackerrank.com/challenges/cpp-input-and-output/problem

2. HackerRank — Basic Data Types  
   https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

3. GFG — Basic Input/Output in C++  
   https://www.geeksforgeeks.org/basic-input-output-c/

4. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

5. LeetCode 2469 — Convert the Temperature  
   https://leetcode.com/problems/convert-the-temperature/

The LeetCode exercises involve operations/functions that are formally covered shortly, so bookmark them if needed.

---

# 44. Final Checklist

You should understand:

```text
input
output
standard streams
cin
cout
>>
<<
formatted extraction
whitespace skipping
multiple input values
cerr
clog
getline
cin + getline newline issue
cin.ignore
ws
fixed
setprecision
setw
setfill
left/right
endl
'\n'
buffering
flushing
fast I/O
sync_with_stdio(false)
cin.tie(nullptr)
stream failure
EOF
interactive vs batch I/O
```

You should be able to write from memory:

```cpp
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int value;
    cin >> value;

    cout << value << '\n';

    return 0;
}
```

---

# What's Next

`01_C++__/05_OPERATORS/`

Next we learn arithmetic, comparison, logical, assignment, increment/decrement, precedence, associativity, and other C++ operators—the machinery that lets our stored/input values actually participate in computations.
