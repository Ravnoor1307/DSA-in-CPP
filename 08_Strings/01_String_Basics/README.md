# 01_String_Basics

## Real-world analogy summary

String ek letters ki line hai, jaise name board ya sentence. C-style string `char[]` ke end me hidden null character `\0` hota hai, while C++ `string` class memory and length ko automatically manage karti hai.

## Key visuals

```text
char s[] = "hello"
index:  0    1    2    3    4     5
      ['h']['e']['l']['l']['o']['\0']
```

## C-string vs string class master table

| Feature | C-string `char[]` | C++ `string` |
|---|---|---|
| End marker | `\0` required | internally managed |
| Memory | fixed/manual | automatic class management |
| Input word | `cin >> s` stops at whitespace | `cin >> s` also word only |
| Input line | `cin.getline(arr, size)` | `getline(cin, s)` |
| Length | `strlen(s)` scans chars | `s.length()` / `s.size()` |
| Common use | legacy C APIs, low-level | modern C++ DSA/interviews |

## Approach comparison table

| Topic | Real-world idea | Loop/calculation | Time | Space |
|---|---|---:|---:|---:|
| C-string length | read until stop sign `\0` | n chars + terminator | O(n) | O(1) |
| string length | object knows length | metadata access | O(1) typical | O(1) |
| `cin >> s` | reads first word | k chars before whitespace | O(k) | O(k) |
| getline | reads full line | n chars until newline | O(n) | O(n) |
| Index traversal | visit every box | n visits | O(n) | O(1) |

## Common mistakes

1. `char s[]="hello"` size 5 samajhna; actual 6 because `\0`.
2. `cin >> s` se full sentence expect karna.
3. Last index `length` use karna; correct last index `length-1`.
4. `strlen` and `sizeof` confuse karna.
5. C-string buffer size small rakhna.

## Interview questions

1. String kya hoti hai?
2. Null terminator kya hota hai?
3. `char[]` and `string` me difference kya hai?
4. `cin` whitespace par kyun rukta hai?
5. `getline` kab use karte ho?
6. Last valid index ka formula kya hai?
