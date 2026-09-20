# 03_CPP_STL_Hashing

## Real-world analogy summary

C++ STL hashing containers phonebook/contact app jaise hain. Key se value average O(1) lookup milta hai. Set sirf unique keys rakhta hai. Frequency pattern `freq[key]++` sabse universal hashing pattern hai.

## STL cheat sheet

```cpp
unordered_map<string,int> m;
m["Aman"] = 987;
m.find("Aman");
m.count("Aman");
m.erase("Aman");

unordered_set<int> st;
st.insert(5);
st.count(5);
st.erase(5);
```

## map vs unordered_map master table

| Feature | map | unordered_map |
|---|---|---|
| Internal structure | balanced BST | hash table |
| Key order | sorted | not sorted |
| Insert/search/delete | O(log n) | O(1) avg, O(n) worst |
| Best use | sorted output/range needs | fast lookup/frequency |
| Log proof | n/2^k=1 -> k=log₂n | load factor constant average |

## Frequency pattern

```cpp
unordered_map<Key, int> freq;
for (Key x : data) {
    freq[x]++;
}
```

## Common mistakes

1. unordered_map iteration order sorted assume karna.
2. `m[key]` use karne par absent key insert ho sakti hai ye ignore karna.
3. `find()` result `end()` se compare na karna.
4. unordered_set duplicates store karega assume karna.
5. map and unordered_map complexities confuse karna.

## Interview questions

1. unordered_map basics explain karo.
2. insert, erase, find, count operations ka average complexity kya hai?
3. unordered_set duplicates kaise handle karta hai?
4. map vs unordered_map kab use karoge?
5. `freq[key]++` universal pattern examples do.
