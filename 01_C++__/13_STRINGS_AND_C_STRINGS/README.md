# Strings and C-Strings in C++

Path:

`DSA_JOURNEY/01_C++__/13_STRINGS_AND_C_STRINGS/`

## Prerequisites

You should already understand:

- `char`
- arrays
- loops
- functions
- references
- pointer basics
- `cin`, `cout`, and `getline`
- array indexing and bounds
- array-to-pointer adjustment

Strings are sequences of characters.

In C++, two important models appear:

```text
std::string
C-style strings
```

For normal modern C++ DSA code, `std::string` is usually the preferred tool.

C-strings are still essential to understand because they explain:

- null termination
- character arrays
- many low-level APIs
- the relationship between arrays and pointers
- why buffer boundaries matter

---

# 1. Character vs String

A character literal uses single quotes:

```cpp
char c = 'A';
```

A string literal uses double quotes:

```cpp
"ABC"
```

These are not the same thing.

Conceptually:

```text
'A'
|
one character value

"ABC"
|
sequence:
'A' 'B' 'C' '\0'
```

The hidden `'\0'` is essential for C-style strings.

---

# 2. std::string

Include:

```cpp
#include <string>
```

Example:

```cpp
string name = "Ada";
```

`std::string` is a Standard Library class representing a sequence of characters.

It manages its own storage and keeps track of its length.

That makes it substantially easier and safer to use than manually managed C-style character arrays.

---

# 3. Real-World Analogy

Think of `std::string` as a smart expandable label maker.

You can ask it:

```text
how many characters do you contain?
```

You can append more text.

You can compare it with another string.

You can access individual characters.

A C-string is closer to a row of boxes where a special marker tells the reader where meaningful text ends:

```text
H E L L O \0 ? ? ?
```

The reader keeps scanning until:

```text
\0
```

That terminator is part of the C-string representation.

---

# 4. Creating std::string Objects

Examples:

```cpp
string first = "Hello";
string second{"World"};
string empty;
```

State:

```text
first  = "Hello"
second = "World"
empty  = ""
```

An empty string has:

```text
length 0
```

---

# 5. String Length

Use:

```cpp
text.size()
```

or:

```cpp
text.length()
```

Example:

```cpp
string text = "DSA";

cout << text.size();
```

Output:

```text
3
```

For `std::string`, `size()` and `length()` are equivalent.

Both return an unsigned size type:

```cpp
std::string::size_type
```

typically related to `std::size_t`.

---

# 6. String Indexing

Given:

```cpp
string text = "HELLO";
```

indexes are:

```text
index:  0 1 2 3 4
char:   H E L L O
```

Access:

```cpp
text[0] -> 'H'
text[4] -> 'O'
```

As with raw arrays, indexing normally begins at zero.

---

# 7. Modifying Characters

`std::string` characters can be modified when the string is mutable.

```cpp
string text = "cat";

text[0] = 'b';
```

Final:

```text
"bat"
```

Dry run:

```text
before:
[c, a, t]

write index 0:
'b'

after:
[b, a, t]
```

---

# 8. Bounds

For:

```cpp
string text = "DSA";
```

valid indexes:

```text
0
1
2
```

Using `operator[]` with an invalid index for ordinary character access can produce undefined behavior.

Do not write:

```cpp
text[3]
```

expecting normal safe character access.

There is an important nuance: the C++ string specification allows reading `text[text.size()]` as a reference to a null character in certain contexts, but modifying it to a non-null character is undefined and treating it as a normal element is poor practice. For DSA, use only:

```text
0 <= index < text.size()
```

when processing characters.

---

# 9. at()

`std::string` also provides:

```cpp
text.at(index)
```

Unlike unchecked `operator[]`, `at()` performs bounds checking.

Example:

```cpp
cout << text.at(1);
```

If the index is outside the valid element range, `at()` throws:

```text
std::out_of_range
```

Exceptions are formally studied later.

For performance-oriented DSA code where indexes are already proven valid, `[]` is commonly used.

---

# 10. front() and back()

For a non-empty string:

```cpp
string text = "HELLO";

cout << text.front();
cout << text.back();
```

Output characters:

```text
H
O
```

Do not call:

```cpp
front()
back()
```

on an empty string.

---

# 11. empty()

Check whether the string contains zero characters:

```cpp
if (text.empty()) {
    ...
}
```

This communicates intent more clearly than:

```cpp
if (text.size() == 0)
```

Both are valid.

---

# 12. Traversing by Index

```cpp
string text = "DSA";

for (size_t i = 0; i < text.size(); ++i) {
    cout << text[i] << '\n';
}
```

Output:

```text
D
S
A
```

Complexity:

```text
O(n)
```

for a string of length `n`.

---

# 13. Range-Based Traversal

Copy each character:

```cpp
for (char c : text) {
    cout << c;
}
```

Modify actual characters:

```cpp
for (char& c : text) {
    // c aliases an element
}
```

Read-only reference:

```cpp
for (const char& c : text) {
    cout << c;
}
```

For `char`, copying is cheap, so:

```cpp
for (char c : text)
```

is usually simplest for read-only traversal.

---

# 14. Input With cin >>

Example:

```cpp
string word;

cin >> word;
```

Input:

```text
Ada Lovelace
```

Only:

```text
Ada
```

is read because formatted extraction stops at whitespace.

This is ideal for token-oriented input such as:

```text
hello
algorithm
abc123
```

---

# 15. Input With getline

To read an entire line:

```cpp
string line;

getline(cin, line);
```

Input:

```text
Ada Lovelace
```

State:

```text
line = "Ada Lovelace"
```

Spaces become part of the string.

---

# 16. cin >> Then getline

Recall the classic issue:

```cpp
int age;
string name;

cin >> age;
getline(cin, name);
```

Input:

```text
20
Ada Lovelace
```

After:

```cpp
cin >> age;
```

the newline generally remains.

Then `getline` sees it immediately.

A common solution:

```cpp
cin.ignore(
    numeric_limits<streamsize>::max(),
    '\n'
);

getline(cin, name);
```

or, when discarding leading whitespace is acceptable:

```cpp
getline(cin >> ws, name);
```

---

# 17. Concatenation

Strings can be joined using:

```cpp
+
```

Example:

```cpp
string first = "Data";
string second = "Structures";

string result =
    first + " " + second;
```

Final:

```text
"Data Structures"
```

---

# 18. +=

Append to an existing string:

```cpp
string text = "Data";

text += " Structures";
```

Final:

```text
"Data Structures"
```

You can append a character:

```cpp
text += '!';
```

Final:

```text
"Data Structures!"
```

---

# 19. append()

Another option:

```cpp
text.append(" and Algorithms");
```

`append` has several overloads.

Simple use:

```cpp
string text = "Hello";

text.append(" World");
```

Result:

```text
"Hello World"
```

---

# 20. push_back()

Append one character:

```cpp
string text = "DS";

text.push_back('A');
```

Result:

```text
"DSA"
```

This is useful when constructing a result character by character.

---

# 21. pop_back()

For a non-empty string:

```cpp
text.pop_back();
```

removes the final character.

Example:

```text
"DSA"
```

becomes:

```text
"DS"
```

Calling `pop_back()` on an empty string has undefined behavior.

Check first if emptiness is possible.

---

# 22. clear()

```cpp
text.clear();
```

removes all characters.

After:

```text
text.size() = 0
text.empty() = true
```

The implementation may retain allocated capacity internally.

Logical size and allocated capacity are different concepts.

We will encounter this idea again with vectors.

---

# 23. Comparison

`std::string` supports direct comparisons:

```cpp
a == b
a != b
a < b
a > b
a <= b
a >= b
```

Example:

```cpp
string a = "apple";
string b = "banana";

cout << (a < b);
```

Comparison is lexicographical.

Conceptually:

```text
compare corresponding characters
until a difference determines ordering
or one string ends
```

---

# 24. Lexicographical Comparison

Compare:

```text
apple
apricot
```

Characters:

```text
a == a
p == p
p vs r
```

At first differing position:

```text
'p' < 'r'
```

therefore:

```text
"apple" < "apricot"
```

under the string's character-traits ordering.

For ordinary ASCII-compatible DSA text, this aligns with familiar character-code ordering.

---

# 25. Case Matters

String comparison is case-sensitive.

Example:

```text
"Apple"
"apple"
```

are not equal.

Character codes/traits distinguish uppercase and lowercase characters.

Do not assume case-insensitive comparison unless you explicitly implement it.

---

# 26. find()

Search for a character:

```cpp
string text = "banana";

size_t pos = text.find('n');
```

First occurrence:

```text
index 2
```

Search substring:

```cpp
text.find("ana");
```

First occurrence:

```text
index 1
```

---

# 27. string::npos

If `find` fails, it returns:

```cpp
string::npos
```

Example:

```cpp
if (text.find("xyz") == string::npos) {
    cout << "Not found";
}
```

Do not casually compare the result to:

```text
-1
```

even though `npos` is represented as the maximum value of the unsigned size type and can interact with `-1` through conversions.

Use the named constant:

```cpp
string::npos
```

---

# 28. substr()

Syntax:

```cpp
text.substr(start, length)
```

Example:

```cpp
string text = "algorithm";

string part =
    text.substr(0, 4);
```

Result:

```text
"algo"
```

If the requested length extends beyond the remaining string, `substr` returns the available suffix.

If `start > text.size()`, it throws `std::out_of_range`.

---

# 29. erase()

Example:

```cpp
string text = "ABCDE";

text.erase(1, 2);
```

Remove two characters starting at index 1:

```text
remove B C
```

Result:

```text
"ADE"
```

---

# 30. insert()

Example:

```cpp
string text = "AC";

text.insert(1, "B");
```

Result:

```text
"ABC"
```

Insertion in the middle can require shifting/reorganizing characters.

It is not generally an O(1) operation.

---

# 31. replace()

Example:

```cpp
string text = "I like cats";

text.replace(
    7,
    4,
    "dogs"
);
```

Result:

```text
"I like dogs"
```

Strings offer many such utility operations.

For interviews, understanding complexity matters as much as knowing the method exists.

---

# 32. String Complexity

Typical high-level complexity:

```text
text[i]
O(1)

size()
O(1)

empty()
O(1)

traversal
O(n)

comparison
O(min(n,m)) worst-case style reasoning

find substring
implementation/algorithm dependent;
basic worst-case reasoning can be O(n*m)

concatenation
proportional to resulting/copied data

insert/erase middle
typically O(n)
```

Exact Standard Library complexity guarantees depend on the operation.

Do not assume every convenient string function is O(1).

---

# 33. Reversing a String

Manual two-pointer method:

```cpp
int left = 0;
int right =
    static_cast<int>(text.size()) - 1;

while (left < right) {
    char temp = text[left];

    text[left] = text[right];
    text[right] = temp;

    ++left;
    --right;
}
```

For:

```text
hello
```

result:

```text
olleh
```

Later STL provides:

```cpp
reverse(...)
```

but implementing it manually builds two-pointer intuition.

---

# 34. Reverse Dry Run

Input:

```text
"abcd"
```

State:

```text
[a b c d]
 L     R
```

Swap:

```text
[d b c a]

left = 1
right = 2
```

Swap:

```text
[d c b a]

left = 2
right = 1
```

Stop.

Final:

```text
"dcba"
```

---

# 35. Palindrome

A palindrome reads the same forward and backward.

Examples:

```text
racecar
level
abba
```

Two-pointer check:

```cpp
int left = 0;
int right =
    static_cast<int>(text.size()) - 1;

while (left < right) {

    if (text[left] != text[right]) {
        return false;
    }

    ++left;
    --right;
}
```

Complexity:

```text
O(n) time
O(1) extra space
```

---

# 36. Palindrome Dry Run

Text:

```text
"level"
```

Initial:

```text
left = 0 -> l
right = 4 -> l
equal
```

Move:

```text
left = 1 -> e
right = 3 -> e
equal
```

Move:

```text
left = 2
right = 2
```

Condition:

```text
left < right -> false
```

No mismatch found.

Result:

```text
palindrome
```

---

# 37. Counting Characters

Example:

```cpp
int count = 0;

for (char c : text) {
    if (c == 'a') {
        ++count;
    }
}
```

For:

```text
"banana"
```

state:

```text
b -> count 0
a -> count 1
n -> count 1
a -> count 2
n -> count 2
a -> count 3
```

Result:

```text
3
```

---

# 38. Character Classification

C++ provides character utilities in:

```cpp
#include <cctype>
```

Common functions:

```cpp
isalpha
isdigit
isalnum
islower
isupper
isspace
tolower
toupper
```

Important safety rule:

The classification/conversion functions expect either `EOF` or a value representable as `unsigned char`.

For a possibly signed `char`, robust code uses:

```cpp
unsigned char uc =
    static_cast<unsigned char>(c);

if (isdigit(uc)) {
    ...
}
```

This prevents undefined behavior for negative `char` values.

For basic ASCII judge inputs, beginners often do not encounter the issue, but correct C++ should understand it.

---

# 39. Converting Character Case

Example:

```cpp
char c = 'a';

char upper =
    static_cast<char>(
        toupper(
            static_cast<unsigned char>(c)
        )
    );
```

Result:

```text
'A'
```

These functions can be affected by the active C locale.

Most DSA problems involving English letters assume straightforward ASCII-style input.

---

# 40. Manual ASCII-Style Case Conversion

For problems explicitly restricted to English ASCII letters:

```cpp
if (c >= 'a' && c <= 'z') {
    c = static_cast<char>(
        c - 'a' + 'A'
    );
}
```

This relies on the execution character set's guaranteed contiguous sequences for digits, but the standard does not guarantee that uppercase and lowercase Latin letters have a fixed arithmetic offset in every possible execution encoding.

Therefore library functions are more portable for general C++.

In ordinary competitive-programming environments, ASCII-compatible encodings dominate.

---

# 41. String to Numeric Conversion

C++ provides functions such as:

```cpp
stoi
stol
stoll
stof
stod
```

Example:

```cpp
string text = "123";

int value = stoi(text);
```

Result:

```text
123
```

These can throw exceptions for invalid input or values outside the target range.

Exception handling is studied later.

Do not call `stoi` on arbitrary unchecked text and assume it always succeeds.

---

# 42. Number to String

Use:

```cpp
to_string
```

Example:

```cpp
int number = 123;

string text =
    to_string(number);
```

Result:

```text
"123"
```

This is useful for digit/string-based problems.

---

# 43. Important Difference: Numeric 123 vs String "123"

```cpp
int number = 123;
```

stores a numeric value.

```cpp
string text = "123";
```

stores three character elements:

```text
'1'
'2'
'3'
```

Operations differ.

Numeric:

```cpp
123 + 1 -> 124
```

String concatenation:

```cpp
"123" + "1" -> "1231"
```

Conceptual type awareness is essential.

---

# 44. String Copying

Unlike raw arrays:

```cpp
string a = "hello";
string b = a;
```

creates an independent string value.

Then:

```cpp
a[0] = 'H';
```

results conceptually in:

```text
a = "Hello"
b = "hello"
```

This is normal value semantics.

A `std::string` manages its internal memory for you.

---

# 45. Passing string by Value

```cpp
void change(string text) {
    text[0] = 'X';
}
```

Caller:

```cpp
string original = "hello";

change(original);
```

`text` is a copy.

Final caller value:

```text
"hello"
```

Copying a length-`n` string generally requires O(n) work/data.

---

# 46. Passing string by Reference

```cpp
void change(string& text) {
    text[0] = 'X';
}
```

Now the parameter aliases the caller's string.

Caller:

```text
"hello"
```

after function:

```text
"Xello"
```

No whole-string copy is required just to bind the reference.

---

# 47. Passing string by const Reference

For read-only helper functions:

```cpp
bool isPalindrome(
    const string& text
);
```

Benefits:

```text
no full string copy
+
function cannot mutate text through the reference
```

This is one of the most common C++ DSA parameter patterns.

---

# 48. Why const string& Matters for Complexity

Suppose:

```cpp
bool check(string text)
```

receives a string of length `n`.

The copy itself may cost:

```text
O(n)
```

before checking logic.

If the function only reads:

```cpp
bool check(const string& text)
```

avoids that full copy.

Function signatures can affect algorithmic complexity.

---

# 49. C-Style Strings

A C-string is a null-terminated sequence of characters.

Example:

```cpp
char word[] = "cat";
```

Actual array:

```text
index 0 -> 'c'
index 1 -> 'a'
index 2 -> 't'
index 3 -> '\0'
```

Array size:

```text
4
```

Text length:

```text
3
```

This distinction is crucial.

---

# 50. The Null Terminator

The special character:

```cpp
'\0'
```

has numeric value zero.

C-string functions use it as:

```text
end of string
```

Conceptually:

```text
H E L L O \0
          ^
          stop
```

Without a terminator within accessible storage, operations expecting a C-string can continue reading beyond the intended character sequence, causing undefined behavior.

---

# 51. String Literal Includes Null Terminator

Literal:

```cpp
"ABC"
```

is represented as an array containing:

```text
'A'
'B'
'C'
'\0'
```

Therefore:

```cpp
sizeof("ABC")
```

is:

```text
4
```

in bytes because each `char` has size 1 byte by definition.

But text length is:

```text
3
```

---

# 52. Character Array Initialization

```cpp
char word[] = "hello";
```

The compiler creates enough space for:

```text
h e l l o \0
```

Array extent:

```text
6
```

If you explicitly specify size:

```cpp
char word[6] = "hello";
```

there is exactly enough room.

---

# 53. A Dangerous Character Array

Consider:

```cpp
char word[5] = {
    'h', 'e', 'l', 'l', 'o'
};
```

This array contains five characters but no `'\0'`.

It is a valid character array.

It is not a valid C-string representation of `"hello"`.

Using it with operations expecting a null-terminated C-string is invalid because there is no terminator within the array.

---

# 54. char Array vs C-String

Every C-string stored in a character array is a character array.

Not every character array is a C-string.

C-string requires:

```text
a '\0' terminator within the accessible sequence
```

This distinction is extremely important.

---

# 55. Printing a C-String

Example:

```cpp
char word[] = "hello";

cout << word;
```

`cout` treats the character pointer/array as C-string text and keeps reading until the null terminator.

Output:

```text
hello
```

It does not print the terminator itself.

---

# 56. Printing a char Pointer Is Special

Suppose:

```cpp
char word[] = "hello";
char* ptr = word;
```

Then:

```cpp
cout << ptr;
```

prints:

```text
hello
```

not a normal numeric-looking address.

Why?

Stream insertion has special behavior/overloads for character pointers, treating them as C-strings.

To inspect an address-like representation later, you can convert to an appropriate `const void*`, but deeper pointer output belongs in the pointer lesson.

---

# 57. <cstring>

C-style string functions live in:

```cpp
#include <cstring>
```

Common functions include:

```text
strlen
strcmp
strcpy
strcat
```

These operate on null-terminated character sequences and require valid buffers.

They are lower-level and easier to misuse than `std::string`.

---

# 58. strlen()

```cpp
char word[] = "hello";

cout << strlen(word);
```

Output:

```text
5
```

`strlen` counts characters until:

```text
'\0'
```

It does not include the terminator.

Complexity:

```text
O(n)
```

because it must scan for the terminator.

---

# 59. strlen vs sizeof

Given:

```cpp
char word[] = "hello";
```

Then:

```cpp
sizeof(word)
```

is:

```text
6
```

because the array physically contains:

```text
h e l l o \0
```

While:

```cpp
strlen(word)
```

is:

```text
5
```

because text length excludes:

```text
\0
```

This is a classic interview question.

---

# 60. strlen Inside a Pointer Parameter

Function:

```cpp
void show(char text[]) {
}
```

The parameter adjusts to:

```cpp
char*
```

Therefore:

```cpp
sizeof(text)
```

inside the function gives pointer size, not original array capacity.

But:

```cpp
strlen(text)
```

can determine the C-string's logical text length by scanning for the null terminator, assuming `text` points to a valid C-string.

It still does not tell you the buffer capacity.

---

# 61. strcmp()

Do not compare C-string contents like this:

```cpp
char a[] = "cat";
char b[] = "cat";

if (a == b) {
}
```

In most such expressions the arrays decay to pointers, so `==` compares addresses, not textual content.

To compare C-string contents:

```cpp
strcmp(a, b)
```

Result:

```text
0 -> equal
<0 -> first lexicographically before second
>0 -> first after second
```

For `std::string`, use ordinary:

```cpp
a == b
```

---

# 62. std::string Comparison vs C-String Comparison

`std::string`:

```cpp
string a = "cat";
string b = "cat";

cout << (a == b);
```

compares content.

Raw C-style arrays:

```cpp
char a[] = "cat";
char b[] = "cat";
```

Do not use:

```cpp
a == b
```

for content.

Use:

```cpp
strcmp(a, b) == 0
```

This difference is one major reason `std::string` is easier to use safely.

---

# 63. strcpy()

Example:

```cpp
char source[] = "cat";
char destination[10];

strcpy(destination, source);
```

Result:

```text
destination contains:
c a t \0
```

But `strcpy` does not know the destination capacity.

If the destination is too small, the program writes out of bounds.

That is a serious memory-safety bug.

Prefer `std::string` when possible.

---

# 64. Buffer Overflow

Suppose:

```cpp
char small[4];
```

It can store C-string:

```text
"cat"
```

because storage needs:

```text
c a t \0
```

four characters.

It cannot safely store:

```text
"hello"
```

which requires:

```text
6 char positions
```

Writing beyond the buffer causes undefined behavior.

This is a real security concern in low-level software.

---

# 65. strcat()

`strcat(destination, source)` appends a source C-string to the destination C-string.

The destination buffer must have enough free capacity for:

```text
existing text
+
source text
+
'\0'
```

Failure to reserve enough space produces out-of-bounds writes.

Again, `std::string +=` is usually preferable.

---

# 66. C-String Input

Older code may read into a character array:

```cpp
char word[20];

cin >> word;
```

The input must fit safely in the destination.

Unbounded token extraction into a raw character buffer can overflow it.

Modern C++ code should generally prefer:

```cpp
string word;

cin >> word;
```

The `std::string` manages its own storage.

---

# 67. getline for C-Style Buffers

Streams also support:

```cpp
char line[100];

cin.getline(
    line,
    100
);
```

This can read a line into a fixed buffer with a maximum size.

But fixed-size buffer management still requires careful handling of truncation/failure conditions.

For general C++:

```cpp
string line;
getline(cin, line);
```

is usually simpler.

---

# 68. C-String Manual Length

We can implement:

```cpp
int cStringLength(
    const char text[]
) {
    int length = 0;

    while (text[length] != '\0') {
        ++length;
    }

    return length;
}
```

Dry run for:

```text
cat\0
```

```text
index 0 -> c != '\0' -> length 1
index 1 -> a != '\0' -> length 2
index 2 -> t != '\0' -> length 3
index 3 -> '\0'      -> stop
```

Result:

```text
3
```

---

# 69. Why C-String Length Is O(n)

Unlike `std::string`, a plain C-string pointer does not inherently carry its logical length.

To find the end:

```text
scan until '\0'
```

For `n` text characters:

```text
O(n)
```

`std::string::size()` stores/manages size information and is O(1) in modern C++.

---

# 70. String Literals Should Not Be Modified

This is appropriate:

```cpp
const char* text = "hello";
```

Do not attempt to modify a string literal through a pointer.

Older C code patterns may show:

```cpp
char* text = "hello";
```

In C++, converting a string literal to non-const `char*` is not permitted.

If mutable character storage is required:

```cpp
char text[] = "hello";
```

creates an array copy that can be modified.

---

# 71. char[] vs const char*

Compare:

```cpp
char a[] = "hello";
```

`a` is an array containing a mutable copy of the characters.

You may write:

```cpp
a[0] = 'H';
```

Now:

```text
"Hello"
```

Compare:

```cpp
const char* b = "hello";
```

`b` points at the string literal.

You must not modify the literal through `b`.

These are different storage models.

---

# 72. c_str()

A `std::string` can provide a pointer to a null-terminated representation:

```cpp
string text = "hello";

const char* ptr =
    text.c_str();
```

This is useful for interoperability with C APIs.

Important:

The pointer refers to storage managed by the `std::string`.

Operations that modify the string can invalidate pointers/references/iterators according to the relevant invalidation rules.

Do not assume a previously obtained `c_str()` pointer remains valid forever.

---

# 73. c_str() Ownership

Wrong mental model:

```text
c_str() gives me a new independent C-string allocation
```

Better mental model:

```text
c_str() gives read access to a null-terminated representation
owned/managed by the string object
```

The string controls the storage lifetime.

Do not `delete` the result.

---

# 74. std::string Internal Storage

Modern `std::string` provides contiguous character storage.

Since C++17, non-const `data()` can provide mutable access to that contiguous storage for the string's elements under its contract.

But direct low-level manipulation is usually unnecessary in beginner DSA.

Use normal string operations unless a problem requires more.

---

# 75. Capacity Preview

A string has:

```text
size
```

and also:

```text
capacity
```

Size:

```text
number of logical characters
```

Capacity:

```text
amount of storage currently available before some growth may require reallocation
```

Example:

```cpp
text.size();
text.capacity();
```

Capacity is implementation-dependent and may exceed size.

Do not write algorithms that depend on a particular capacity value.

---

# 76. reserve()

You can request capacity:

```cpp
text.reserve(1000);
```

This can reduce reallocations when you know a string will grow significantly.

It does not change logical size.

After:

```cpp
string text;

text.reserve(100);
```

you still have:

```text
text.size() == 0
```

Reserve and resize are different.

---

# 77. resize()

```cpp
text.resize(5);
```

changes logical size.

If growing, new characters are value-initialized (for `char`, null characters) unless an explicit fill character is supplied.

Example:

```cpp
string text = "abc";

text.resize(5, 'x');
```

Result:

```text
"abcxx"
```

Shrinking removes logical trailing characters.

---

# 78. reserve vs resize

Mental model:

```text
reserve
-> prepare storage
-> logical string unchanged

resize
-> change number of characters
```

This distinction later appears with `std::vector` too.

---

# 79. Appending Complexity and Amortization Preview

Repeated:

```cpp
text.push_back(c);
```

can occasionally require the string to acquire larger storage and move/copy existing characters.

Yet implementations grow capacity strategically.

This leads to the idea of amortized complexity.

We have a dedicated future lesson:

```text
03_COMPLEXITY_AND_MATH__/06_AMORTIZED_ANALYSIS/
```

For now remember:

```text
dynamic containers may occasionally perform expensive growth
```

---

# 80. Constructing a Filtered String

Example:

```cpp
string result;

for (char c : text) {
    if (c != ' ') {
        result.push_back(c);
    }
}
```

Input:

```text
"a b c"
```

Dry run:

```text
c='a' -> append -> "a"
c=' ' -> skip
c='b' -> append -> "ab"
c=' ' -> skip
c='c' -> append -> "abc"
```

Final:

```text
"abc"
```

Time:

```text
O(n) amortized-style high-level reasoning
```

Extra output space:

```text
O(n)
```

---

# 81. In-Place vs New String

To reverse:

```text
modify original string
```

can use:

```text
O(1) auxiliary space
```

besides the string itself.

Creating:

```cpp
string reversed;
```

and appending characters uses:

```text
O(n)
```

additional storage.

Both can be correct.

DSA asks us to understand the tradeoff.

---

# 82. Empty String Edge Cases

For:

```cpp
string text = "";
```

valid:

```cpp
text.empty()
text.size()
```

Do not access:

```cpp
text[0]
text.front()
text.back()
```

as though a character exists.

Many interview bugs come from ignoring:

```text
n = 0
```

---

# 83. One-Character String

Input:

```text
"a"
```

is automatically a palindrome.

Two-pointer state:

```text
left = 0
right = 0
```

Condition:

```text
left < right
```

is false immediately.

Return:

```text
true
```

A correct algorithm naturally handles this edge case.

---

# 84. Signed vs Unsigned Indexing

`string::size()` returns an unsigned size type.

Beginners may write:

```cpp
int right = text.size() - 1;
```

For an empty string, the subtraction occurs in the unsigned type before conversion and can underflow to a very large value.

Safer pattern:

```cpp
if (text.empty()) {
    // handle if needed
}
```

or convert the size before subtracting when you have established representability:

```cpp
int right =
    static_cast<int>(text.size()) - 1;
```

For truly huge strings beyond `int` range, use an appropriate size type.

In normal interview constraints, explicit reasoning about the index type is enough.

---

# 85. size_t

`std::size_t` is an unsigned integer type suitable for object sizes and indexes into many standard containers.

Example:

```cpp
for (size_t i = 0;
     i < text.size();
     ++i) {
}
```

This avoids signed/unsigned comparison warnings.

But reverse loops with unsigned indexes need care because unsigned values do not become negative.

---

# 86. Unsigned Reverse Loop Trap

Dangerous pattern:

```cpp
for (size_t i = text.size() - 1;
     i >= 0;
     --i) {
}
```

Condition:

```text
i >= 0
```

is always true for an unsigned type.

This can produce an infinite loop/out-of-range behavior.

Use a safer pattern, for example:

```cpp
for (size_t i = text.size();
     i > 0;
     --i) {

    char c = text[i - 1];
}
```

This is a common interview mistake.

---

# 87. Comparing Character Frequencies

A common DSA pattern for lowercase English letters uses:

```cpp
int frequency[26]{};
```

For a character guaranteed in:

```text
'a' through 'z'
```

index:

```cpp
c - 'a'
```

Then:

```cpp
++frequency[c - 'a'];
```

This technique depends on known input constraints.

Later hashing/frequency-array sections will study it deeply.

---

# 88. Dry Run: Character Frequency

Text:

```text
"aba"
```

Initially:

```text
freq[a] = 0
freq[b] = 0
...
```

Read first:

```text
'a' - 'a' = 0
freq[0] = 1
```

Next:

```text
'b' - 'a' = 1
freq[1] = 1
```

Next:

```text
'a'
freq[0] = 2
```

Result:

```text
a -> 2
b -> 1
```

---

# 89. Anagram Preview

Two strings are anagrams if they contain the same characters with the same frequencies, subject to the problem's definition.

Example:

```text
listen
silent
```

For lowercase English letters, frequency arrays can solve this in:

```text
O(n)
```

rather than repeatedly searching/removing characters.

This is a preview of frequency counting and hashing.

---

# 90. Subsequence Preview

String:

```text
"abcde"
```

Possible subsequence:

```text
"ace"
```

Characters retain relative order but need not be contiguous.

Substring:

```text
"bcd"
```

must be contiguous.

These are different concepts.

They become extremely important in recursion and dynamic programming.

---

# 91. Substring vs Subsequence

For:

```text
ABCDE
```

Substring examples:

```text
A
ABC
BCD
DE
```

Subsequence examples:

```text
ACE
AD
BDE
ABCDE
```

Every substring is a subsequence.

Not every subsequence is a substring.

Do not confuse these interview terms.

---

# 92. Prefix and Suffix

For:

```text
algorithm
```

prefix examples:

```text
"a"
"al"
"algo"
"algorithm"
```

suffix examples:

```text
"m"
"thm"
"rithm"
"algorithm"
```

Depending on context, the empty string may also be considered a prefix/suffix.

Prefix/suffix ideas become central in:

- tries
- KMP
- Z algorithm
- rolling hash
- prefix-function algorithms

---

# 93. Common Interview Mistakes

1. Confusing:

```text
'A'
```

with:

```text
"A"
```

2. Using `cin >> text` when spaces must be preserved.

3. Mixing `cin >>` and `getline` without consuming pending input appropriately.

4. Accessing a string index outside the logical character range.

5. Calling `front()`, `back()`, or `pop_back()` on an empty string.

6. Forgetting string comparison is case-sensitive.

7. Forgetting `find()` returns `string::npos` when not found.

8. Repeatedly using expensive substring construction inside loops without analyzing complexity.

9. Passing large strings by value unintentionally.

10. Using a non-const reference when a function should only read.

11. Assuming `std::string::size()` is O(n). It is O(1).

12. Confusing `reserve()` with `resize()`.

13. Assuming capacity equals size.

14. Writing unsafe unsigned reverse loops.

15. Forgetting C-strings need `'\0'`.

16. Confusing character-array capacity with C-string length.

17. Using `sizeof(cString)` as text length without considering the terminator/capacity.

18. Using `sizeof` on a pointer parameter expecting original array size.

19. Comparing C-string contents with `==`.

20. Using `strcpy`/`strcat` without ensuring destination capacity.

21. Attempting to modify a string literal.

22. Assuming `c_str()` returns independently owned memory.

23. Keeping a `c_str()` pointer across operations that may invalidate it.

24. Calling `<cctype>` functions with an arbitrary negative signed `char`.

25. Confusing substring and subsequence.

26. Ignoring the empty-string edge case in two-pointer code.

---

# 94. Complexity Table

Let `n` be a string's length.

| Operation | Typical Complexity |
|---|---:|
| `text.size()` / `length()` | O(1) |
| `text.empty()` | O(1) |
| `text[i]` | O(1) |
| `text.at(i)` | O(1) |
| `front()` / `back()` | O(1) |
| Traverse | O(n) |
| Copy string | O(n) |
| Compare two strings | O(min(n,m)) until difference; O(min(n,m)) worst prefix scan |
| `push_back()` | amortized O(1) typical/guaranteed amortized constant under standard complexity requirements |
| `pop_back()` | O(1) |
| `clear()` | linear in characters for general element destruction reasoning; for `char`, implementations are very efficient |
| Concatenate | proportional to data copied/result size |
| `substr(pos,len)` | O(length of result) |
| Insert/erase middle | O(n) typical |
| Palindrome check | O(n) |
| Manual reverse | O(n) |
| `strlen(cstr)` | O(n) |
| `strcmp(a,b)` | O(min(n,m)) until difference/end |
| Frequency count | O(n) |

String capacity/allocation behavior can affect constant factors and individual operations.

---

# 95. std::string vs C-String

Mental comparison:

```text
std::string
-----------
tracks length
manages memory
copyable/assignable
supports ==
supports +
supports methods
preferred for most C++ DSA


C-string
--------
char sequence ending in '\0'
manual capacity awareness
strlen scans
strcmp for content comparison
buffer overflow risks
important for low-level understanding/APIs
```

---

# 96. Practice Questions

1. LeetCode 344 — Reverse String  
   https://leetcode.com/problems/reverse-string/

2. LeetCode 125 — Valid Palindrome  
   https://leetcode.com/problems/valid-palindrome/

3. LeetCode 242 — Valid Anagram  
   https://leetcode.com/problems/valid-anagram/

4. GFG — C++ String  
   https://www.geeksforgeeks.org/cpp-string/

5. GFG — C-Strings  
   https://www.geeksforgeeks.org/c-strings/

Some solutions may use STL algorithms/containers that we will study later. Implement the basic logic yourself first.

---

# 97. Final Mental Model

`std::string`:

```text
object
 |
 +-- logical size
 +-- managed character storage
 +-- indexing
 +-- comparison
 +-- append/remove/search operations
```

C-string:

```text
character storage

H E L L O \0
          |
          +-- terminator
```

And remember:

```text
std::string size
!=
C-string buffer capacity
!=
strlen(C-string)
!=
sizeof(character array)
```

Those values can be related, but they answer different questions.

---

# What's Next

`01_C++__/14_POINTERS/`

Next we move deeper into pointers: pointer types, address and dereference semantics, pointer-to-pointer relationships, const pointer combinations, dangling/wild/null pointers, pointers with arrays and strings, function pointers at an introductory level, and safe pointer reasoning before dedicated pointer arithmetic and dynamic memory.
