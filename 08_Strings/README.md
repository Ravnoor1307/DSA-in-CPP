# 08_Strings

## Module goal

String ek **characters ki line** hai, jaise name board, chat message, document text, ya search box input. C++ me strings do common forms me milti hain:

1. **C-string / char array**: `char s[] = "hello"`, jiske end me hidden null character `\0` hota hai.
2. **C++ string class**: `string s = "hello"`, jo modern C++ me automatic memory management and rich methods provide karta hai.

```text
char s[] = "hello"

index:   0    1    2    3    4     5
box:   ['h']['e']['l']['l']['o']['\0']
                                      ↑
                              null terminator
```

---

## Folder tree

```text
08_Strings/
├── README.md
├── 01_String_Basics/
│   ├── 01_what_is_string_theory.cpp
│   ├── 02_cstring_declaration_initialization.cpp
│   ├── 03_cstring_input_approach1_cin.cpp
│   ├── 04_cstring_input_approach2_getline.cpp
│   ├── 05_string_class_basics.cpp
│   ├── 06_cstring_vs_string_class.cpp
│   ├── 07_string_indexing_length.cpp
│   ├── README.md
│   └── task.cpp
├── 02_String_Methods/
│   ├── 01_cstring_functions.cpp
│   ├── 02_string_class_methods_part1.cpp
│   ├── 03_string_class_methods_part2.cpp
│   ├── 04_string_comparison.cpp
│   ├── 05_string_iteration_approaches.cpp
│   ├── README.md
│   └── task.cpp
├── 03_String_Traversals_Patterns/
│   ├── 01_count_vowels_consonants.cpp
│   ├── 02_count_words_spaces.cpp
│   ├── 03_reverse_string_approach1_extra.cpp
│   ├── 04_reverse_string_approach2_two_pointers.cpp
│   ├── 05_reverse_words_approach1_stack.cpp
│   ├── 06_reverse_words_approach2_inplace.cpp
│   ├── README.md
│   └── task.cpp
├── 04_Palindrome_Problems/
│   ├── 01_palindrome_approach1_reverse_compare.cpp
│   ├── 02_palindrome_approach1_str.cpp
│   ├── 03_palindrome_approach2_two_pointers.cpp
│   ├── 04_palindrome_ignoring_case_spaces.cpp
│   ├── 05_palindrome_number_string.cpp
│   ├── README.md
│   └── task.cpp
├── 05_Frequency_Counting/
│   ├── 01_char_frequency_approach1_nested.cpp
│   ├── 02_char_frequency_approach2_array26.cpp
│   ├── 03_max_occuring_char.cpp
│   ├── 04_first_non_repeating_char_approach1.cpp
│   ├── 05_first_non_repeating_char_approach2_freq.cpp
│   ├── 06_anagram_check_approach1_sort.cpp
│   ├── 07_anagram_check_approach2_freq_array.cpp
│   ├── README.md
│   └── task.cpp
├── 06_String_Transformations/
│   ├── 01_uppercase_lowercase_convert.cpp
│   ├── 02_toggle_case.cpp
│   ├── 03_remove_vowels.cpp
│   ├── 04_remove_spaces_duplicates.cpp
│   ├── 05_capitalize_first_letter.cpp
│   ├── 06_string_compression.cpp
│   ├── 07_rotate_string_check.cpp
│   ├── README.md
│   └── task.cpp
├── 07_Substring_Problems/
│   ├── 01_substring_vs_subsequence_theory.cpp
│   ├── 02_check_substring_approach1_find.cpp
│   ├── 03_check_substring_approach1_naive.cpp
│   ├── 04_longest_common_prefix.cpp
│   ├── 05_longest_palindromic_substring_approach1.cpp
│   ├── 06_longest_palindromic_substring_approach2_expand.cpp
│   ├── README.md
│   └── task.cpp
└── 08_String_Problems_Medium/
    ├── 01_isomorphic_strings.cpp
    ├── 02_group_anagrams_concept.cpp
    ├── 03_valid_parentheses_string.cpp
    ├── 04_longest_substring_without_repeat_approach1.cpp
    ├── 05_longest_substring_without_repeat_approach2_sliding.cpp
    ├── 06_count_vowels_in_substrings.cpp
    ├── README.md
    └── task.cpp
```

---

## ASCII cheat sheet

### 1. C-string memory

```text
char s[] = "hello"
[h][e][l][l][o][\0]
 0  1  2  3  4   5

strlen(s) = 5
sizeof(s) = 6 for char array because \0 included
```

### 2. String indexing

```text
s = "hello"
index:  0   1   2   3   4
char:  [h] [e] [l] [l] [o]

length = 5
last valid index = length - 1 = 4
```

### 3. cin vs getline trap

```text
input: hello world

cin >> s       -> reads "hello" only
getline(cin,s) -> reads "hello world"
```

### 4. Frequency array mapping

```text
index = ch - 'a'

a -> 0
b -> 1
c -> 2
...
z -> 25

s = "banana"
freq[a]=3, freq[b]=1, freq[n]=2
```

### 5. Two-pointer reverse

```text
s = "hello"
[h][e][l][l][o]
 L           R   swap
[o][e][l][l][h]
    L     R      swap
[o][l][l][e][h]
       L         stop
```

### 6. Palindrome pointers

```text
MADAM
[M][A][D][A][M]
 L           R   M == M
    L     R      A == A
       L         pointers meet -> palindrome
```

### 7. Sliding window without repeat

```text
s = "abcabcbb"

[a]       best=1
[ab]      best=2
[abc]     best=3
[abca]    duplicate a -> move left
[bca]     valid again
```

---

## C-string vs C++ string master table

| Feature | C-string `char[]` | C++ `string` |
|---|---|---|
| Real-world analogy | fixed-size old form | modern dynamic contact field |
| End marker | needs `\0` | internally managed |
| Declaration | `char s[] = "hello";` | `string s = "hello";` |
| Length | `strlen(s)` scans until `\0` | `s.length()` / `s.size()` |
| Copy/join | `strcpy`, `strcat` | `=`, `append`, `+` |
| Compare | `strcmp`, 0 means equal | `==`, `compare()` |
| Input word | `cin >> s` | `cin >> s` |
| Input line | `cin.getline(arr, size)` | `getline(cin, s)` |
| Safety | buffer overflow risk | safer automatic management |
| Common use | C APIs, low-level code | modern C++ DSA/interviews |

---

## Method cheat sheet

```cpp
// C-string
strlen(s);          // length, stops at '\0'
strcpy(dest, src);  // copy
strcat(dest, src);  // concatenate
strcmp(a, b);       // 0 means equal

// C++ string
s.length();
s.size();
s.substr(pos, len);
s.find(pattern);
s.replace(pos, len, newText);
s.append(text);
s.insert(pos, text);
s.erase(pos, len);
s.push_back(ch);
s.pop_back();
```

---

## Approach comparison master table

| Topic | Best approach | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| C-string length | scan until `\0` | stop sign at end | n chars + terminator | O(n) | O(1) |
| string indexing | direct index | seat number | fixed address-like access | O(1) | O(1) |
| getline | full line read | address form | n chars until newline | O(n) | O(n) |
| string iteration | loop/range/iterator | inspect every letter | n visits | O(n) | O(1) |
| Count vowels | one scan | teacher marks letters | n checks | O(n) | O(1) |
| Word count robust | insideWord flag | word processor | n checks | O(n) | O(1) |
| Reverse string | two pointers | swap bookshelf ends | floor(n/2) swaps | O(n) | O(1) |
| Reverse words | reverse trick | flip full board, then each word | linear passes | O(n) | O(1) possible |
| Palindrome | two pointers | mirror compare | floor(n/2) checks | O(n) | O(1) |
| Ignore case/spaces palindrome | skip + lowercase | clean mirror | each pointer crosses once | O(n) | O(1) |
| Frequency count | array26 | alphabet boxes | n increments + 26 scan | O(n) | O(1) |
| First non-repeating | two-pass freq | attendance register | 2n + fixed scan | O(n) | O(1) |
| Anagram | freq array | Scrabble boxes add/subtract | n + 26 | O(n) | O(1) |
| String compression | group count | warehouse item grouping | n-1 comparisons | O(n) | O(n) |
| Rotation check | `s+s` find | necklace doubled | build 2n + find worst n² | O(n²) worst | O(n) |
| Naive substring search | sliding pattern | ruler at each index | (n-m+1)*m | O(n*m) | O(1) |
| Longest common prefix | vertical comparison | contact labels | k strings * L chars | O(kL) | O(L) |
| Longest pal substring brute | all substrings | every mirror clip | O(n²)*O(n) | O(n³) | O(n) |
| Longest pal substring expand | expand center | grow mirror from center | (2n-1)*n | O(n²) | O(1) extra |
| Isomorphic strings | two maps | cipher mapping | n positions | O(n) | O(1) |
| Valid parentheses | stack | latest opened gate closes first | n push/pop ops | O(n) | O(n) |
| Longest unique substring | sliding window | no-repeat playlist window | left+right each move n | O(n) | O(1) |
| Vowel range queries | prefix sum | dashboard precompute | build n + q queries | O(n+q) | O(n) |

---

## Complexity calculation notes

### 1. One scan

```text
String length = n
Loop visits every character once
Total checks = n
Time = O(n)
```

### 2. Nested scan

```text
Outer loop = n choices
Inner loop = n checks for each outer choice
Total comparisons = n * n = n²
Time = O(n²)
```

### 3. Naive substring matching

```text
Text length = n, pattern length = m
Possible starts = n - m + 1
Comparisons per start = up to m
Total = (n - m + 1) * m
Time = O(n*m)
```

### 4. Sorting strings

Sorting repeatedly splits/organizes data. Log derivation:

```text
n / 2^k = 1
n = 2^k
k = log₂n
```

Sorting comparison-based strings takes:

```text
O(n log n)
```

### 5. Subsequence count

Each character has two choices: take or skip.

```text
2 * 2 * 2 ... n times = 2^n
```

### 6. Sliding window proof

```text
right pointer moves from 0 to n-1 -> n moves
left pointer also moves from 0 to n-1 at most -> n moves
Total pointer movement <= 2n
Time = O(n)
```

### 7. Prefix sum proof

```text
Build prefix: n characters scanned once -> O(n)
Each query: prefix[r+1] - prefix[l] -> O(1)
For q queries: O(n+q)
```

---

## Section-wise roadmap

### 01_String_Basics

Start from real-world name board and C-string memory:

- Char array with `\0` terminator.
- `char s[] = "hello"` memory boxes.
- `cin` whitespace trap.
- `cin.getline()` and `getline()` full-line input.
- C++ `string` class basics.
- char[] vs string master table.
- Indexing and length.

### 02_String_Methods

Text editor toolkit:

- `strlen`, `strcpy`, `strcat`, `strcmp`.
- Important: `strcmp` returns `0` when equal.
- `length`, `substr`, `find`, `replace`.
- `append`, `insert`, `erase`, `push_back`, `pop_back`.
- `==` vs `strcmp` vs `compare()`.
- Iteration: index loop, range-for, iterator.

### 03_String_Traversals_Patterns

One-scan and pointer patterns:

- Count vowels/consonants.
- Count words/spaces with edge cases.
- Reverse string using extra string.
- Reverse string using two pointers.
- Reverse words using stack.
- Reverse words using reverse + reverse trick.

### 04_Palindrome_Problems

Mirror string problems:

- Reverse-compare palindrome.
- Manual reverse string palindrome.
- Two-pointer palindrome.
- Ignore case/spaces/punctuation.
- Number palindrome via string conversion.

### 05_Frequency_Counting

Counting and anagram foundations:

- Nested frequency O(n²).
- Array26 frequency O(n).
- Max occurring char.
- First non-repeating char O(n²) and O(n) two-pass.
- Anagram sort O(n log n).
- Anagram frequency array O(n).

### 06_String_Transformations

Text cleaning/editing:

- Uppercase/lowercase with ASCII trick.
- Toggle case.
- Remove vowels.
- Remove spaces and duplicates.
- Capitalize first letter.
- String compression.
- Rotate string check.

### 07_Substring_Problems

Continuous segment problems:

- Substring vs subsequence.
- Built-in substring check.
- Naive string matching.
- Longest common prefix.
- Longest palindromic substring brute force.
- Expand around center optimal basic approach.

### 08_String_Problems_Medium

Interview medium patterns:

- Isomorphic strings with mapping.
- Group anagrams with freq-key hashing preview.
- Valid parentheses using stack.
- Longest substring without repeat brute force.
- Longest substring without repeat sliding window.
- Count vowels in substrings using prefix sum.

---

## Common mistakes checklist

1. C-string me `\0` terminator bhoolna.
2. `strlen` and `sizeof` confuse karna.
3. `cin >> s` se full sentence expect karna.
4. Last index `length` use karna instead of `length-1`.
5. `strcmp` equal return `0` hota hai ye bhoolna.
6. `substr(pos,len)` me `len` ko end index samajhna.
7. `find()` not found ke liye `string::npos` check na karna.
8. Uppercase handling skip karna in vowel/frequency problems.
9. `freq[ch-'a']` non-lowercase char par apply karna.
10. Word count me leading/trailing/multiple spaces ignore karna.
11. Two-pointer reverse/palindrome me pointers update na karna.
12. Palindrome ignoring spaces me non-alphanumeric skip na karna.
13. Anagram me length mismatch check skip karna.
14. String compression me last group append karna bhoolna.
15. Rotation check me length same check na karna.
16. Substring and subsequence confuse karna.
17. Longest palindromic substring me even center skip karna.
18. Isomorphic strings me one-way mapping hi check karna.
19. Valid parentheses me final stack empty check skip karna.
20. Sliding window me duplicate remove karne ke liye while loop na lagana.
21. Prefix range query me inclusive formula galat use karna; correct `prefix[r+1]-prefix[l]`.

---

## Interview question bank

1. String kya hoti hai?
2. C-string me null terminator ka role kya hai?
3. `char s[]="hello"` memory boxes draw karo.
4. C-string and C++ string class compare karo.
5. `cin` whitespace trap explain karo.
6. `cin.getline()` and `getline()` difference kya hai?
7. `s.length()` and `s.size()` difference kya hai?
8. Last valid index formula kya hai?
9. `strlen`, `strcpy`, `strcat`, `strcmp` explain karo.
10. `strcmp` equal strings ke liye kya return karta hai?
11. `substr`, `find`, `replace` dry run karo.
12. String iteration ke 3 methods batao.
13. Vowels/consonants count in O(n).
14. Word count edge cases kya hain?
15. Reverse string extra vs two-pointer compare karo.
16. Reverse words using stack explain karo.
17. Reverse whole + reverse each word trick dry run karo.
18. Palindrome check two-pointer method explain karo.
19. MADAM/RACECAR dry run karo.
20. Ignore case/spaces palindrome ka code logic batao.
21. `freq[s[i]-'a']` mapping explain karo.
22. Max occurring char ka approach kya hai?
23. First non-repeating character two-pass method explain karo.
24. LISTEN and SILENT anagram using sort and freq array solve karo.
25. ASCII trick `'a'-'A'=32` explain karo.
26. String compression `aaabbc -> a3b2c1` dry run karo.
27. Rotate string check double-string trick explain karo.
28. Substring vs subsequence visual explain karo.
29. Naive substring search O(n*m) prove karo.
30. Longest common prefix vertical comparison explain karo.
31. Longest palindromic substring brute O(n³) kyun?
32. Expand around center odd/even centers explain karo.
33. Isomorphic strings mapping kaise check karte hain?
34. Group anagrams freq-key hashing explain karo.
35. Valid parentheses stack se kaise solve hota hai?
36. Longest substring without repeat sliding window dry run karo.
37. Sliding window O(n) proof do.
38. Prefix sum on strings se vowel queries kaise solve karte hain?

---

## How to study this module

1. Pehle `01_String_Basics` me char array memory and `\0` terminator draw karo.
2. `02_String_Methods` me C-string functions and string class methods run karo.
3. `03_String_Traversals_Patterns` me one-scan and two-pointer patterns practice karo.
4. `04_Palindrome_Problems` me MADAM, RACECAR, Nitin dry run karo.
5. `05_Frequency_Counting` me `freq[ch-'a']` trick master karo.
6. `06_String_Transformations` me ASCII and compression patterns solve karo.
7. `07_Substring_Problems` me substring vs subsequence and expand-center pattern revise karo.
8. `08_String_Problems_Medium` me mapping, stack, sliding window, prefix sum patterns connect karo.
9. Har subfolder ka `task.cpp` pehle khud solve karo, phir lesson files se compare karo.
