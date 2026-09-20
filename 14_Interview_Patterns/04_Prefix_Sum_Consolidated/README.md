# 04_Prefix_Sum_Consolidated

## Real-world analogy summary

Prefix sum bank passbook running balance jaisa hai. Range sum ke liye har transaction dobara count nahi karte; end balance minus before-start balance karte hain.

## Templates

```cpp
prefix[0] = 0;
for (int i = 0; i < n; i++) {
    prefix[i+1] = prefix[i] + nums[i];
}
rangeSum(l,r) = prefix[r+1] - prefix[l];
```

Prefix + HashMap:

```cpp
freq[0] = 1;
sum = 0;
for x in nums:
    sum += x;
    count += freq[sum-k];
    freq[sum]++;
```

## Pattern table

| Problem | Pattern | Time | Space |
|---|---|---:|---:|
| Range sum query | prefix array | build O(n), query O(1) | O(n) |
| Subarray sum equals k | prefix + hashmap freq | O(n) avg | O(n) |
| Product except self | prefix product + suffix product | O(n) | O(1) extra |

## Common mistakes

1. `prefix[r] - prefix[l]` off-by-one bug; with prefix size n+1 use `prefix[r+1]-prefix[l]`.
2. `freq[0]=1` initialize na karna in subarray sum k.
3. Prefix sum only positive arrays ke liye hai sochna; works with negatives too.
4. Product except self me division use karna when zeros exist.

## Interview questions

1. Prefix sum passbook analogy se explain karo.
2. Range sum O(1) kaise hota hai?
3. Subarray sum equals k hashmap logic explain karo.
4. Product except self without division kaise solve karte hain?
