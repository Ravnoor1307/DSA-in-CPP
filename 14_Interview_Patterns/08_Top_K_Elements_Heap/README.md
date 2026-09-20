# 08_Top_K_Elements_Heap

## Real-world analogy summary

Top-K pattern shortlist management hai. Sirf best k candidates/riders/words/scores keep karo, baaki discard. Heap worst survivor ko quickly remove karta hai.

## Golden rules

```text
kth largest -> min heap of size k
kth smallest -> max heap of size k
k closest -> max heap of size k by distance
frequency -> hashmap count + heap rank
stream kth largest -> maintain min heap size k forever
```

## Pattern table

| Problem | Heap choice | Why | Time | Space |
|---|---|---|---:|---:|
| kth largest | min heap size k | smallest survivor is kth largest | O(n log k) | O(k) |
| k closest points | max heap size k | farthest survivor removed | O(n log k) | O(k) |
| top k frequent words | hashmap + heap | count then rank | O(n + m log m) | O(m) |
| kth largest stream | persistent min heap k | update per score | O(log k)/add | O(k) |

## Common mistakes

1. kth largest ke liye max heap all use karna okay but size-k min heap often better.
2. k closest me sqrt calculate karna unnecessary hai.
3. Frequent words comparator tie-break ulta likhna.
4. Stream design me heap re-create karna; heap persistent hona chahiye.

## Interview questions

1. kth largest min heap size k se kaise milta hai?
2. k closest points me max heap kyun?
3. top k frequent words me hashmap + heap combo explain karo.
4. kth largest stream design ka constructor/add complexity kya hai?
