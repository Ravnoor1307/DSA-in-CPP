# 06_Frequency_Array_Technique

## Real-world analogy summary

Frequency array fixed lockers jaisa hai. Agar marks 0 se 100 tak hi ho sakte hain, to `count[101]` enough hai. Hashmap ki zarurat tab hai jab range large/unknown ho.

## Approach comparison table

| Technique | Best when | Operation | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Frequency array | small integer range | `count[value]++` | n direct updates | O(n) | O(R) |
| Counting sort preview | small range sortable values | build count + rebuild | n + R + n | O(n+R) | O(R) extra |
| Most frequent via freq array | small range | build + scan range | n + R | O(n+R) | O(R) |
| Hashmap | large/negative/string/unknown keys | `freq[key]++` | n average hash updates | O(n) avg | O(d) |

## Key rules

```text
If value range is 0..100:
    vector<int> count(101)

If keys are huge, negative, strings, or unknown:
    unordered_map<Key,int> freq
```

## Common mistakes

1. Large range ke liye frequency array allocate kar dena.
2. Negative values ko direct index use karna.
3. Frequency array space O(range) ignore karna.
4. Hashmap flexibility and collision cost compare na karna.
5. Counting sort me output rebuild range order me na karna.

## Interview questions

1. Frequency array kab use karte hain?
2. `arr[i]` 0..100 ho to count array size kya hoga?
3. Counting sort preview explain karo.
4. Most frequent element using frequency array ka dry run do.
5. Frequency array vs hashmap master table explain karo.
