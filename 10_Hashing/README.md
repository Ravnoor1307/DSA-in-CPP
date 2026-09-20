# 10_Hashing

## Module goal

Hashing ka main theme hai:

```text
O(n²) brute force ko O(n) average solution me convert karna
```

Real-world analogy: school bag ka index page ya cloak room token. Agar naam/token se page/cabin direct mil jaye, to har item linearly search nahi karna padta.

```text
key -> [HASH FUNCTION] -> index -> bucket
23  ->      23 % 10    ->   3   -> bucket[3]
```

Hashing average case me insert/search/delete ko **O(1)** bana sakta hai, but collision ke reason worst case **O(n)** bhi ho sakta hai.

---

## Folder tree

```text
10_Hashing/
├── README.md
├── 01_Hashing_Intro/
│   ├── 01_why_hashing_theory.cpp
│   ├── 02_hash_function_theory.cpp
│   ├── 03_hash_table_concept.cpp
│   ├── 04_collision_theory.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Collision_Handling/
│   ├── 01_chaining_approach.cpp
│   ├── 02_open_addressing_linear_probing.cpp
│   ├── 03_open_addressing_quadratic_probing.cpp
│   ├── 04_chaining_vs_probing_comparison.cpp
│   ├── README.md
│   └── task.cpp
├── 03_CPP_STL_Hashing/
│   ├── 01_unordered_map_basics.cpp
│   ├── 02_unordered_map_operations.cpp
│   ├── 03_unordered_set_basics.cpp
│   ├── 04_map_vs_unordered_map.cpp
│   ├── 05_stl_hashing_frequency_pattern.cpp
│   ├── README.md
│   └── task.cpp
├── 04_Hashing_Classic_Problems/
│   ├── 01_two_sum_approach1_bruteforce.cpp
│   ├── 02_two_sum_approach2_hashmap.cpp
│   ├── 03_count_distinct_elements_approach1_sort.cpp
│   ├── 04_count_distinct_elements_approach2_set.cpp
│   ├── 05_union_intersection_arrays_set.cpp
│   ├── 06_check_two_arrays_equal_freq.cpp
│   ├── 07_first_repeating_element.cpp
│   ├── 08_first_non_repeating_approach1_freq.cpp
│   ├── README.md
│   └── task.cpp
├── 05_Hashing_Advanced_Patterns/
│   ├── 01_subarray_with_zero_sum.cpp
│   ├── 02_subarray_with_given_sum.cpp
│   ├── 03_longest_subarray_zero_sum.cpp
│   ├── 04_largest_subarray_0_1.cpp
│   ├── 05_count_distinct_in_window.cpp
│   ├── 06_group_elements_by_frequency.cpp
│   ├── 07_four_sum_concept.cpp
│   ├── README.md
│   └── task.cpp
└── 06_Frequency_Array_Technique/
    ├── 01_freq_array_small_range.cpp
    ├── 02_sort_array_freq_array.cpp
    ├── 03_most_frequent_element_freq.cpp
    ├── 04_hashmap_vs_freq_array_comparison.cpp
    ├── README.md
    └── task.cpp
```

---

## Big picture: search speed ladder

| Method | Real-world analogy | Calculation | Time |
|---|---|---:|---:|
| Linear search | har pocket check | n comparisons | O(n) |
| Binary search | sorted book half discard | n/2^k=1 -> k=log₂n | O(log n) |
| Hashing average | token to cabin direct | hash + small bucket check | O(1) avg |

Hashing ka promise average O(1) hai, guaranteed O(1) nahi.

```text
Good distribution -> short buckets/probes -> O(1) average
All keys collide -> one long bucket/probe -> O(n) worst
```

---

## Hashing formulas sheet

### 1. Simple hash function

```text
index = key % tableSize
```

Example:

```text
23 % 10 = 3
33 % 10 = 3
```

Dono same bucket 3 me jaana chahte hain, so collision.

### 2. Load factor

```text
alpha = numberOfKeys / tableSize
```

If alpha small/controlled, average bucket length constant rehti hai.

### 3. Chaining

```text
bucket[index] -> linked list of keys
```

```text
bucket[3]: 23 -> 33 -> 43 -> NULL
```

Average search:

```text
hash calculation O(1)
average chain length ≈ alpha = n/tableSize
if alpha constant -> O(1) average
```

Worst search:

```text
all n keys in one bucket -> scan n keys -> O(n)
```

### 4. Linear probing

```text
index = (hash + i) % tableSize
```

Visual:

```text
10%7=3 -> slot3
17%7=3 collision -> slot4
24%7=3 collision -> slot5

0:_ 1:_ 2:_ 3:10 4:17 5:24 6:_
                 cluster grows
```

### 5. Quadratic probing

```text
index = (hash + i*i) % tableSize
```

Visual:

```text
hash=3
try i=0 -> 3
try i=1 -> 4
try i=2 -> 0
try i=3 -> 5
```

---

## STL hashing cheat sheet

```cpp
#include <unordered_map>
#include <unordered_set>

unordered_map<string, int> m;
m["Aman"] = 987;
m.find("Aman");       // iterator
m.count("Aman");      // 0 or 1
m.erase("Aman");

unordered_set<int> st;
st.insert(5);
st.count(5);
st.erase(5);
```

### map vs unordered_map

| Feature | map | unordered_map |
|---|---|---|
| Internal structure | balanced BST | hash table |
| Key order | sorted | not sorted |
| Insert/search/delete | O(log n) | O(1) avg, O(n) worst |
| Best use | sorted output/range needs | fast lookup/frequency |
| Log proof | n/2^k=1 -> k=log₂n | load factor constant average |

### Universal frequency pattern

```cpp
unordered_map<Key, int> freq;
for (Key x : data) {
    freq[x]++;
}
```

Use cases:

- count frequency
- first repeating
- first non-repeating
- arrays equal by frequency
- anagrams
- window counts
- majority-like problems

---

## O(n²) -> O(n) converter theme

Hashing ka sabse bada benefit: nested search ko memory ke through one-pass lookup me convert karna.

### Two Sum example

Brute force:

```text
for i=0..n-1:
    for j=i+1..n-1:
        check arr[i]+arr[j]

pairs = n(n-1)/2 -> O(n²)
```

Hashmap:

```text
for each x:
    need = target - x
    if need in map -> answer
    map[x] = index

n lookups/inserts average O(1) -> O(n)
```

Dry run:

```text
arr=[2,7,11,15], target=9

i=0, x=2, need=7, map={} -> store 2:0
i=1, x=7, need=2, map has 2 -> answer (0,1)
```

---

## Prefix sum + hash pattern

Prefix sum hidden subarray problems ka master pattern hai.

### Zero-sum subarray

```text
If same prefix sum appears twice:
prefix[j] == prefix[i]
then sum(i+1..j) = prefix[j] - prefix[i] = 0
```

Visual:

```text
arr=[4,2,-3,1,6]
prefix: 4,6,3,4
              ↑ repeat 4
subarray between repeated prefix: 2 + (-3) + 1 = 0
```

### Given-sum subarray

```text
prefix[j] - prefix[i] = target
prefix[i] = prefix[j] - target
need = currentPrefix - target
if need seen -> subarray found
```

### Longest zero-sum

```text
store first index of each prefix sum
if prefix repeats:
    length = currentIndex - firstIndex[prefix]
```

### Largest 0/1 subarray

```text
0 -> -1
1 -> +1
Equal number of 0s and 1s => transformed sum 0
Now use longest zero-sum pattern
```

---

## Frequency array technique

Frequency array hashmap ka faster/simpler cousin hai, but only when key range small and known ho.

```text
If arr[i] in 0..100:
count[101] enough
count[arr[i]]++
```

### Frequency array vs hashmap

| Feature | Frequency array | Hashmap |
|---|---|---|
| Keys | small integer range | any hashable key |
| Access | direct index | hash(key) |
| Collision | none | possible |
| Time | O(n+R) | O(n) average |
| Space | O(R) | O(d), d distinct keys |
| Best when | range small like 0..100 | range large/unknown, negative, strings |

---

## Master approach comparison table

| Topic | Best pattern | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Hash search average | hash function | token to cabin | O(1) hash + constant bucket | O(1) avg | O(n+tableSize) |
| Hash search worst | collision chain/probe | one crowded counter | scan n collided keys | O(n) | O(n) |
| Chaining | linked list buckets | mini-line at same counter | avg alpha=n/tableSize | O(1) avg, O(n) worst | O(n+tableSize) |
| Linear probing | next slot | parking next slot | probes constant avg, n worst | O(1) avg, O(n) worst | O(tableSize) |
| Quadratic probing | i² jumps | square jump parking | probes constant avg, n worst | O(1) avg, O(n) worst | O(tableSize) |
| unordered_map | key-value lookup | phonebook | n ops average O(1) | O(n) for n ops | O(n) |
| unordered_set | unique keys | entry gate | n inserts avg O(1) | O(n) avg | O(d) |
| map | sorted keys | alphabetic catalog | tree height log n | O(log n) per op | O(n) |
| Frequency map | `freq[key]++` | vote counter | n updates avg O(1) | O(n) avg | O(d) |
| Two Sum | complement map | budget pair | n lookups/inserts | O(n) avg | O(n) |
| Count distinct | set | unique gate | n inserts | O(n) avg | O(d) |
| Union/intersection | sets | two class lists | n+m operations | O(n+m) avg | O(n+m) |
| Arrays equal | freq add/subtract | inventory quantities | 2n+d checks | O(n) avg | O(d) |
| First repeating | freq + order scan | first duplicated ticket | 2n operations | O(n) avg | O(d) |
| First non-repeating | freq + order scan | first unique token | 2n operations | O(n) avg | O(d) |
| Zero-sum subarray | prefix set | repeated bank balance | n prefix checks | O(n) avg | O(n) |
| Given-sum subarray | prefix map | target balance change | n lookups | O(n) avg | O(n) |
| Longest zero-sum | first prefix index | longest repeated-balance gap | n lookups | O(n) avg | O(n) |
| Equal 0/1 subarray | 0 to -1 + prefix | attendance balance | n lookups | O(n) avg | O(n) |
| Distinct in window | sliding hash | moving bus seats | k + 2(n-k) updates | O(n) avg | O(k) |
| Group by frequency | freq + sort distinct | vote result board | n + d log d | O(n+d log d) | O(d) |
| Four Sum concept | pair sums | 4-item shopping cart | n(n-1)/2 pairs | O(n²) avg concept | O(n²) |
| Frequency array | count[value] | fixed lockers | n updates + range scan | O(n+R) | O(R) |
| Counting sort preview | frequency rebuild | marks sorting | n + R + n | O(n+R) | O(R) |

---

## Complexity derivations

### 1. Hashing average O(1)

```text
alpha = n / tableSize
average bucket length ≈ alpha
if resizing keeps alpha constant:
    hash + bucket check = O(1)
```

### 2. Hashing worst O(n)

```text
All keys collide into one bucket/probe chain.
Search may check all n keys.
Time = O(n)
```

### 3. Binary search log reminder

```text
n / 2^k = 1
n = 2^k
k = log₂n
```

### 4. Sorting log reminder

```text
Comparison sorting repeatedly divides/merges.
Levels = log₂n.
Work per level = n.
Time = O(n log n)
```

### 5. Two Sum brute pair count

```text
number of pairs = n(n-1)/2
= (n²-n)/2
Time = O(n²)
```

### 6. Prefix hash

```text
Loop visits n elements.
Each step:
    prefix update O(1)
    hash lookup O(1) average
    hash insert O(1) average
Total = n * O(1)
Time = O(n) average
```

### 7. Sliding window hash

```text
First window build = k updates
Slides = n-k
Each slide = remove outgoing + add incoming = 2 hash updates
Total = k + 2(n-k) = 2n-k
Time = O(n) average
```

### 8. Pair sums Four Sum concept

```text
Pairs = n(n-1)/2 = O(n²)
Store/check pair sums in hash map.
Space = O(n²)
```

---

## Section-wise roadmap

### 01_Hashing_Intro

- Why hashing: O(n), O(log n), and O(1) average motivation.
- School bag index/cloak room token analogy.
- Hash function: key -> index -> bucket.
- Simple `key % tableSize` examples.
- Hash table concept: array of buckets.
- Insert/search/delete average O(1).
- Collision theory with `23%10=3` and `33%10=3`.

### 02_Collision_Handling

- Chaining with linked-list bucket.
- Linked List real use connection.
- Linear probing and clustering visual.
- Quadratic probing using 1², 2², 3² jumps.
- Chaining vs probing comparison table.

### 03_CPP_STL_Hashing

- `unordered_map` basics: `map[key]=value`, `find`, `count`.
- Insert, erase, iterate operations.
- `unordered_set` unique keys and duplicate auto-remove.
- `map` vs `unordered_map` sorted vs fast average lookup.
- Universal frequency pattern `freq[key]++`.

### 04_Hashing_Classic_Problems

- Two Sum brute force and hashmap.
- Count distinct using sort and set.
- Union/intersection using set.
- Check two arrays equal by frequency.
- First repeating element.
- First non-repeating element using array-style frequency pattern.

### 05_Hashing_Advanced_Patterns

- Subarray with zero sum using repeated prefix.
- Subarray with given sum using `prefix-target`.
- Longest zero-sum subarray using first prefix index.
- Largest subarray with 0/1 by transforming 0 to -1.
- Count distinct in every window using sliding window + hash.
- Group elements by frequency.
- Four Sum concept with pair sums.

### 06_Frequency_Array_Technique

- Frequency array for small range.
- Counting sort preview.
- Most frequent element using frequency array.
- Hashmap vs frequency array master comparison.

---

## Common mistakes checklist

1. Hashing ko guaranteed O(1) bolna; correct average O(1), worst O(n).
2. Collision theory ignore karna.
3. `key % tableSize` me negative key handling ignore karna in real systems.
4. Load factor ka role na samajhna.
5. Linear probing search sequence insert sequence se different rakhna.
6. Linear probing clustering problem ignore karna.
7. Quadratic probing formula me modulo miss karna.
8. unordered_map iteration sorted assume karna.
9. `m[key]` absent key ko insert kar sakta hai ye bhoolna.
10. `find()` result `end()` se compare na karna.
11. map and unordered_map complexities confuse karna.
12. Two Sum me current element complement check se pehle insert kar dena.
13. First repeating me first repeated value vs first repeating by original index confuse karna.
14. Frequency equality me length mismatch check skip karna.
15. Prefix sum 0 ko initially seen/index -1 par store na karna.
16. Longest prefix problems me first index overwrite kar dena.
17. Largest 0/1 subarray me 0 ko -1 transform na karna.
18. Window distinct me frequency 0 hone par key erase na karna.
19. Four Sum pair approach me overlapping indices allow kar dena.
20. Frequency array large/unknown range ke liye allocate karna.
21. Negative keys ko direct frequency array index banana.
22. Counting sort rebuild order galat rakhna.

---

## Interview question bank

1. Hashing ki need kya hai?
2. Linear search O(n), binary search O(log n), hashing O(1) average compare karo.
3. Hash function kya hota hai?
4. `key % tableSize` examples solve karo.
5. Hash table buckets ka visual draw karo.
6. Insert/search/delete average O(1) kyun hote hain?
7. Average O(1) and worst O(n) difference kya hai?
8. Collision kya hota hai? 23 and 33 example do.
9. Chaining kya hota hai?
10. Chaining me linked list ka use kaise hota hai?
11. Chaining average and worst complexity explain karo.
12. Linear probing dry run karo.
13. Clustering problem kya hai?
14. Quadratic probing formula kya hai?
15. Chaining vs probing compare karo.
16. unordered_map basics explain karo.
17. unordered_map `find`, `count`, `erase` ka use batao.
18. unordered_set duplicates kaise remove karta hai?
19. map vs unordered_map master table explain karo.
20. `freq[key]++` universal pattern examples do.
21. Two Sum brute force pair count calculate karo.
22. Two Sum hashmap complement approach dry run karo.
23. Count distinct sort vs set compare karo.
24. Union and intersection using hash set solve karo.
25. Check two arrays equal by frequency ka algorithm kya hai?
26. First repeating element frequency + index scan se kaise milega?
27. First non-repeating element two-pass frequency se kaise milega?
28. Same prefix sum repeated means zero-sum subarray kyun?
29. Subarray with given sum me `prefix-target` kyun check karte hain?
30. Longest zero-sum subarray me first index kyun store karte hain?
31. Largest 0/1 subarray me 0 ko -1 kyu karte hain?
32. Count distinct in window sliding hash ka dry run do.
33. Group elements by frequency ka algorithm kya hai?
34. Four Sum pair-hash concept kya hai?
35. Frequency array kab hashmap se better hai?
36. Values 0..100 ke liye count array size kya hoga?
37. Counting sort preview explain karo.
38. Hashmap vs frequency array space tradeoff explain karo.

---

## How to study this module

1. `01_Hashing_Intro` me hash function and collision visual manually draw karo.
2. `02_Collision_Handling` me chaining, linear probing, quadratic probing dry run karo.
3. `03_CPP_STL_Hashing` me `unordered_map`, `unordered_set`, and `freq[key]++` pattern practice karo.
4. `04_Hashing_Classic_Problems` me Two Sum hashmap state har step draw karo.
5. `05_Hashing_Advanced_Patterns` me prefix sums table banao and repeated prefix concept master karo.
6. `06_Frequency_Array_Technique` me decide karna seekho: small range -> array, large/unknown/string -> hashmap.
7. Har subfolder ka `task.cpp` pehle khud solve karo, phir lesson files se compare karo.
