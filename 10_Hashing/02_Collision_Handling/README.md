# 02_Collision_Handling

## Real-world analogy summary

Collision tab hoti hai jab do keys same bucket maangti hain. Chaining same bucket me linked-list queue banata hai. Probing array ke andar alternative slot dhundhta hai.

## Collision visual

```text
23 % 10 = 3
33 % 10 = 3

bucket[3]: 23
           33 also wants same bucket -> collision
```

## Master comparison table

| Feature | Chaining | Linear probing | Quadratic probing |
|---|---|---|---|
| Real-world analogy | same counter mini-line | next parking slot | square jump slots |
| Formula | bucket list | `(hash+i)%m` | `(hash+i*i)%m` |
| Insert avg | O(1) if short chain | O(1) if low load | O(1) if low load |
| Search worst | O(n) one chain | O(n) long probe | O(n) many probes |
| Delete | easy from list | needs tombstone in full implementation | needs tombstone in full implementation |
| Load factor | can exceed 1 | must be < 1 | must be controlled |
| Issue | pointer overhead | primary clustering | may not visit all slots |

## Complexity explanation

Average bucket/probe length depends on load factor:

```text
alpha = n / tableSize
```

If alpha remains small constant, average work is constant. If all n keys collide, one chain/probe can be length n, so worst O(n).

## Common mistakes

1. Collision handling skip karna.
2. Linear probing search sequence insert sequence se different rakhna.
3. Clustering problem ignore karna.
4. Quadratic probing me `(hash+i*i)%size` modulo miss karna.
5. Open addressing deletion me tombstone concept ignore karna.

## Interview questions

1. Chaining explain karo with linked list visual.
2. Linear probing ka dry run keys 10,17,24 with size 7.
3. Clustering problem kya hai?
4. Quadratic probing linear se kaise different hai?
5. Chaining vs probing kab choose karoge?
