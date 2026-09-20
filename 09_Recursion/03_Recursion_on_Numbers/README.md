# 03_Recursion_on_Numbers

## Real-world analogy summary

Number recursion digits ko todne, numbers ko reduce karne, ya circle problem ko smaller circle me convert karne jaisa hai.

## Approach comparison table

| Problem | Formula / idea | Reduction | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Count digits | `1 + count(n/10)` | divide by 10 | d digits | O(d)=O(log n) | O(d) |
| Palindrome check | compare ends | left+1,right-1 | floor(d/2) pairs | O(d) | O(d) incl string/stack |
| GCD Euclidean | `gcd(b,a%b)` | remainder shrink | log-like calls | O(log min(a,b)) | O(log min(a,b)) |
| Divisors print | check current | current+1 | n checks | O(n) | O(n) |
| Tail sum | `sumTail(n-1,acc+n)` | n-1 | n+1 calls | O(n) | O(n) stack unless optimized |
| Josephus | `(J(n-1,k)+k)%n` | n-1 people | n calls | O(n) | O(n) stack |

## Key formulas

```text
countDigits(n) = 1 + countDigits(n/10)
gcd(a,b) = gcd(b, a%b), gcd(a,0)=a
sumTail(n,acc) = sumTail(n-1, acc+n)
Josephus zero-index: J(n,k) = (J(n-1,k)+k) % n, J(1,k)=0
```

## Common mistakes

1. countDigits(0) ka answer 1 handle na karna.
2. Palindrome two-pointer recursion me left/right move na karna.
3. GCD base case `b==0` miss karna.
4. Divisors recursion me `current+1` call bhoolna.
5. Tail recursion ko C++ me guaranteed optimized assume karna.
6. Josephus zero-index and one-index answer confuse karna.

## Interview questions

1. Count digits recursively ka formula kya hai?
2. Recursive palindrome two-pointer check explain karo.
3. gcd(48,18) Euclidean recursion dry run karo.
4. Tail recursion kya hota hai?
5. Josephus recurrence derive/intuitively explain karo.
