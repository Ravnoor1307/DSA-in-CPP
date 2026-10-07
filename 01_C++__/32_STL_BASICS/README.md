# 32 — STL Basics

## Learning goals

The C++ Standard Library provides reusable containers, algorithms,
iterators, utilities, and callable abstractions. The term STL
(Standard Template Library) is commonly used for the generic
container/iterator/algorithm portion of this ecosystem.

This lesson provides the working foundation required before the later
deep dive.

By the end, you should understand:

- what the STL is
- generic programming in the STL
- containers
- iterators
- algorithms
- iterator ranges
- half-open ranges `[first, last)`
- sequence containers
- ordered associative containers
- unordered associative containers
- container adapters
- `vector`
- `array`
- `deque`
- `list`
- `stack`
- `queue`
- `priority_queue`
- `set`
- `map`
- `unordered_set`
- `unordered_map`
- `pair`
- common iterator operations
- `begin()` and `end()`
- range-based loops
- `sort`
- `find`
- `count`
- `reverse`
- `min_element` and `max_element`
- `binary_search`
- `lower_bound`
- `accumulate`
- algorithms with lambdas
- basic iterator invalidation awareness
- choosing a container by operations and complexity

---

## 1. Why the STL matters for DSA

Suppose every time you needed a dynamic array you manually wrote:

```text
allocation
capacity growth
copying
destruction
indexing
```

Then every algorithm problem would require rebuilding basic
infrastructure.

C++ provides reusable generic tools.

Instead of implementing a resizable array every time:

```cpp
std::vector<int> values;
```

Instead of manually implementing sorting:

```cpp
std::sort(values.begin(), values.end());
```

Instead of building a priority queue from scratch for every graph
problem:

```cpp
std::priority_queue<int> heap;
```

You still need to understand how these data structures and algorithms
work. Later roadmap sections implement and analyze them deeply.

The STL lets you use reliable implementations when solving larger
problems.

---

## 2. Four central ideas

A useful beginner model is:

```text
STL-style programming
├── Containers
├── Iterators
├── Algorithms
└── Function objects / callables
```

Containers store values.

Iterators describe positions and ranges.

Algorithms perform generic operations over ranges.

Callables customize behavior.

You already learned templates, lambdas, and operator overloading. Those
ideas now come together.

---

## 3. Real-world analogy

Imagine a warehouse.

Containers are different storage systems:

```text
shelves
bins
queues
sorted cabinets
indexed lockers
```

Iterators are like position markers telling a worker where a region
begins and ends.

Algorithms are reusable workers:

```text
sort these items
find this item
count matching items
reverse this region
```

The worker does not need a completely different algorithm for every
container as long as the container provides the required iterator
capabilities.

---

# Part I — Containers

## 4. Sequence containers

Important sequence containers include:

```text
vector
array
deque
list
forward_list
```

They represent sequences but differ in memory layout and operation
costs.

Examples:

```cpp
std::vector<int> values;
std::array<int, 5> fixed;
std::deque<int> deque;
std::list<int> linked;
```

This lesson uses them at an introductory level.

They each receive deeper coverage later.

---

## 5. `vector`

`std::vector<T>` is a dynamically sized contiguous sequence.

Example:

```cpp
std::vector<int> values;

values.push_back(10);
values.push_back(20);
values.push_back(30);
```

Conceptually:

```text
size = 3

+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
```

Important properties:

- contiguous storage
- O(1) random access
- amortized O(1) insertion at the end
- O(n) insertion/erasure near the beginning or middle
- automatic capacity management

For DSA, `vector` is one of the most frequently used containers.

---

## 6. Size versus capacity

For vector:

```text
size
```

means the number of constructed elements.

```text
capacity
```

means how many elements can fit in the currently allocated storage
before another reallocation becomes necessary.

Example conceptual state:

```text
size = 3
capacity = 4

+----+----+----+-----------+
| 10 | 20 | 30 | reserved  |
+----+----+----+-----------+
```

Calling:

```cpp
push_back(40);
```

can use the spare capacity.

Another insertion may require allocation of a larger buffer and moving
or copying existing elements.

This is why `push_back` is amortized O(1), not necessarily O(1) for
every individual call.

---

## 7. `array`

`std::array<T, N>` represents a fixed-size array whose size is part of
its type.

Example:

```cpp
std::array<int, 3> values{
    10, 20, 30
};
```

Unlike a raw C-style array, it provides a container-style interface:

```cpp
values.size()
values.begin()
values.end()
```

Storage remains fixed in size.

---

## 8. `deque`

`std::deque<T>` supports efficient insertion/removal at both ends.

Typical operations:

```cpp
deque.push_front(10);
deque.push_back(20);
deque.pop_front();
deque.pop_back();
```

Unlike vector, deque storage is not required to form one contiguous
array.

Use it when efficient operations at both ends matter.

---

## 9. `list`

`std::list<T>` is a doubly linked list.

It provides efficient insertion and erasure when you already have an
iterator to the correct location.

However:

```cpp
list[index]
```

does not exist.

Linked storage does not provide constant-time random indexing.

For many real workloads, vector is still preferable due to memory
locality and smaller overhead.

Do not choose `list` merely because insertion is theoretically O(1);
consider how you find the insertion position and the actual workload.

---

# Part II — Associative Containers

## 10. `set`

A `std::set<T>` stores unique keys in sorted order according to its
comparison rule.

Example:

```cpp
std::set<int> values{
    30, 10, 20, 10
};
```

Iteration produces:

```text
10 20 30
```

The duplicate `10` does not produce a second element.

Typical insert/search/erase operations are O(log n).

---

## 11. `map`

`std::map<Key, Value>` stores key-value pairs ordered by key.

Example:

```cpp
std::map<std::string, int> marks;

marks["Asha"] = 95;
marks["Ravi"] = 87;
```

Conceptually:

```text
"Asha" -> 95
"Ravi" -> 87
```

Keys are unique.

Typical lookup/insertion/erase operations are O(log n).

---

## 12. Unordered containers

Important hash-based containers include:

```text
unordered_set
unordered_map
```

Example:

```cpp
std::unordered_map<std::string, int> frequency;
```

They do not maintain sorted key order.

Typical average insertion/search/erase complexity is O(1), while worst
case can be O(n).

Hashing receives a dedicated major section later in this roadmap.

---

## 13. Ordered versus unordered

Simplified comparison:

```text
set / map
- sorted
- O(log n) typical operation guarantee
- comparison-based organization

unordered_set / unordered_map
- not sorted
- average O(1) lookup/insertion
- hash-based
- worst case O(n)
```

Choose based on required behavior, not merely the smallest-looking
average Big-O.

---

# Part III — Container Adapters

## 14. `stack`

`std::stack<T>` provides LIFO behavior:

```text
Last In, First Out
```

Common operations:

```cpp
push
pop
top
empty
size
```

Example:

```cpp
std::stack<int> values;

values.push(10);
values.push(20);

cout << values.top(); // 20
```

`stack` intentionally does not expose normal iterator traversal.

It presents a restricted stack interface.

---

## 15. `queue`

`std::queue<T>` provides FIFO behavior:

```text
First In, First Out
```

Operations include:

```cpp
push
pop
front
back
empty
size
```

Example:

```text
push 10
push 20
push 30

front -> 10
```

---

## 16. `priority_queue`

A priority queue returns the highest-priority element first.

Default C++ behavior:

```cpp
std::priority_queue<int>
```

acts as a max-priority queue.

If values are:

```text
10, 50, 20
```

then:

```cpp
top()
```

returns:

```text
50
```

Heaps and priority queues receive a dedicated roadmap section later.

---

# Part IV — Pair

## 17. `std::pair`

A pair stores two associated values:

```cpp
std::pair<std::string, int> student{
    "Asha",
    95
};
```

Access:

```cpp
student.first
student.second
```

C++17 structured binding:

```cpp
auto [name, marks] = student;
```

Pairs are common in DSA for:

```text
(value, index)
(distance, node)
(key, count)
(coordinate, cost)
```

---

# Part V — Iterators

## 18. What is an iterator?

An iterator represents a position in a sequence/container.

Example:

```cpp
std::vector<int> values{
    10, 20, 30
};

auto it = values.begin();
```

`it` refers to the first element.

Dereference:

```cpp
*it
```

gives:

```text
10
```

Increment:

```cpp
++it;
```

moves to the next position.

---

## 19. `begin()` and `end()`

For a container:

```cpp
values.begin()
```

refers to the first element position.

```cpp
values.end()
```

refers to the position one past the final element.

Important:

```text
end() does NOT refer to the last element.
```

For:

```text
[10, 20, 30]
```

conceptually:

```text
begin
  |
  v
+----+----+----+     end
| 10 | 20 | 30 |      |
+----+----+----+      v
                    one-past
```

Dereferencing `end()` is invalid.

---

## 20. Half-open ranges

STL algorithms commonly use:

```text
[first, last)
```

This means:

```text
include first
exclude last
```

Therefore:

```cpp
std::sort(
    values.begin(),
    values.end()
);
```

processes every element.

Advantages include:

```text
empty range:
first == last

range length:
distance(first, last)

adjacent ranges:
[a, b)
[b, c)
```

The half-open range convention appears throughout DSA.

---

## 21. Iterator loop

Example:

```cpp
for (
    auto it = values.begin();
    it != values.end();
    ++it
) {
    cout << *it << ' ';
}
```

This is conceptually similar to:

```cpp
for (const auto& value : values) {
    cout << value << ' ';
}
```

Range-based loops hide the iterator mechanics when explicit iterator
control is unnecessary.

---

## 22. Not every iterator supports `+`

Vector iterators support random access:

```cpp
it + 3
```

List iterators do not support arbitrary arithmetic like that.

Algorithms have iterator requirements.

For example:

```cpp
std::sort
```

requires random-access iterators.

Therefore this works:

```cpp
std::sort(vector.begin(), vector.end());
```

but this does not:

```cpp
std::sort(list.begin(), list.end());
```

`std::list` provides its own:

```cpp
list.sort();
```

---

## 23. Iterator categories preview

Major concepts include:

```text
input iterator
output iterator
forward iterator
bidirectional iterator
random-access iterator
```

Later iterator lessons will explore these properly.

For now:

```text
vector -> powerful random-access iterators
list   -> bidirectional iterators
```

The available iterator operations determine which generic algorithms
can use them.

---

# Part VI — Algorithms

## 24. `sort`

```cpp
std::sort(
    values.begin(),
    values.end()
);
```

Sorts ascending by default.

Typical required complexity:

```text
O(n log n)
```

You can supply a comparator:

```cpp
std::sort(
    values.begin(),
    values.end(),
    [](int a, int b) {
        return a > b;
    }
);
```

This sorts descending.

---

## 25. `find`

Linear search:

```cpp
auto it = std::find(
    values.begin(),
    values.end(),
    target
);
```

Check:

```cpp
if (it != values.end()) {
    // found
}
```

For a vector range of `n` elements:

```text
O(n)
```

---

## 26. `count`

Count equal values:

```cpp
auto count = std::count(
    values.begin(),
    values.end(),
    10
);
```

For `n` elements:

```text
O(n)
```

---

## 27. `count_if`

Use a predicate:

```cpp
auto evenCount = std::count_if(
    values.begin(),
    values.end(),
    [](int value) {
        return value % 2 == 0;
    }
);
```

The lambda is called for each element.

---

## 28. `reverse`

```cpp
std::reverse(
    values.begin(),
    values.end()
);
```

For `n` elements:

```text
O(n)
```

It modifies the sequence in place through the iterators.

---

## 29. `min_element` and `max_element`

```cpp
auto smallest = std::min_element(
    values.begin(),
    values.end()
);
```

The return value is an iterator.

Check against:

```cpp
values.end()
```

before dereferencing if the range might be empty.

Likewise:

```cpp
std::max_element(...)
```

---

## 30. `accumulate`

`std::accumulate` lives in:

```cpp
#include <numeric>
```

Example:

```cpp
int sum = std::accumulate(
    values.begin(),
    values.end(),
    0
);
```

For:

```text
[10, 20, 30]
```

dry run:

```text
initial = 0

0 + 10 = 10
10 + 20 = 30
30 + 30 = 60
```

Result:

```text
60
```

---

# Part VII — Binary Search Algorithms

## 31. `binary_search`

For sorted data:

```cpp
bool exists = std::binary_search(
    values.begin(),
    values.end(),
    target
);
```

With random-access iterators such as vector iterators, comparisons are
logarithmic in the range size.

The data must satisfy the ordering assumptions expected by the
algorithm.

Calling binary search on unsorted values gives meaningless results with
respect to the intended search question.

---

## 32. `lower_bound`

For sorted values:

```cpp
auto it = std::lower_bound(
    values.begin(),
    values.end(),
    target
);
```

It finds the first position where the target could be inserted without
violating the ordering — equivalently, for ascending default ordering,
the first element not less than the target.

Example:

```text
values = [1, 3, 3, 5, 8]
target = 3

lower_bound -> first 3
index = 1
```

---

## 33. `upper_bound`

Similarly:

```cpp
auto it = std::upper_bound(
    values.begin(),
    values.end(),
    target
);
```

For ascending default ordering it gives the first element greater than
the target.

Example:

```text
[1, 3, 3, 5, 8]

upper_bound(3)
-> points to 5
-> index 3
```

Binary search receives detailed dedicated lessons later.

---

# Part VIII — Iterator Invalidation

## 34. Why iterator invalidation matters

Suppose an iterator points inside a vector:

```cpp
auto it = values.begin();
```

Then:

```cpp
values.push_back(...);
```

may reallocate the entire vector buffer.

Conceptually:

```text
before:
it ---> old memory

push_back causes reallocation:

old memory released

new memory:
[ ... ]

it ---> invalid old location
```

Using an invalid iterator is undefined behavior.

---

## 35. Invalidation rules differ by container

Different containers have different rules.

Examples at a high level:

```text
vector:
reallocation can invalidate pointers/references/iterators to elements

list:
insertion usually preserves iterators to existing elements;
erasing an element invalidates iterators to that erased element

unordered containers:
rehashing affects iterators according to container rules
```

The later STL deep dive documents these precisely.

For now, learn to ask:

```text
Can this operation invalidate my iterator/reference?
```

---

# Part IX — Choosing Containers

## 36. Operation-first thinking

Do not choose a container by memorizing names.

Ask:

```text
Do I need contiguous memory?
Do I need random indexing?
Do I need sorted keys?
Do I need average O(1) lookup?
Do I need LIFO?
Do I need FIFO?
Do I repeatedly need the maximum/minimum priority?
Do I need insertion at both ends?
```

Then choose a suitable data structure.

---

## 37. Beginner selection guide

Typical choices:

```text
General dynamic sequence
-> vector

Fixed compile-time sequence
-> array

Push/pop both ends
-> deque

LIFO
-> stack

FIFO
-> queue

Repeated highest-priority item
-> priority_queue

Sorted unique keys
-> set

Sorted key-value mapping
-> map

Average O(1) key lookup without sorted-order requirement
-> unordered_set / unordered_map
```

These are defaults, not absolute rules.

---

# Part X — Complexity Summary

## 38. Common container complexity

| Container | Random access | End insertion | Search by value/key | Ordered |
|---|---:|---:|---:|---|
| `vector` | O(1) | amortized O(1) | O(n) | insertion order |
| `array` | O(1) | fixed size | O(n) | fixed sequence |
| `deque` | O(1) | O(1) ends | O(n) | sequence |
| `list` | O(n) | O(1) with position/end | O(n) | sequence |
| `set` | no index | O(log n) insert | O(log n) | yes |
| `map` | no numeric index | O(log n) insert | O(log n) | yes |
| `unordered_set` | no index | avg O(1) insert | avg O(1) | no |
| `unordered_map` | no numeric index | avg O(1) insert | avg O(1) | no |

Worst-case unordered lookup can be O(n).

---

## 39. Common algorithm complexity

| Algorithm | Typical complexity |
|---|---:|
| `find` | O(n) |
| `count` | O(n) |
| `count_if` | O(n) |
| `reverse` | O(n) |
| `min_element` | O(n) |
| `max_element` | O(n) |
| `accumulate` | O(n) |
| `sort` | O(n log n) |
| `binary_search` on random-access sorted range | O(log n) comparisons |
| `lower_bound` on random-access sorted range | O(log n) comparisons |
| `upper_bound` on random-access sorted range | O(log n) comparisons |

Iterator category can affect traversal cost even when comparison counts
are logarithmic.

---

## 40. Common interview and beginner mistakes

1. Thinking STL means only `vector`.

2. Memorizing container syntax without understanding complexity.

3. Dereferencing `end()`.

4. Forgetting `[begin, end)` excludes `end`.

5. Calling `sort` on unsorted-incompatible iterator types such as
   `std::list` iterators.

6. Calling binary-search algorithms on data that is not properly
   sorted.

7. Using `map[key]` merely to check existence and accidentally
   inserting a default value.

8. Assuming unordered containers are always O(1).

9. Assuming unordered containers maintain sorted or insertion order.

10. Treating `priority_queue` as a sorted iterable container.

11. Calling `pop()` on stack/queue and expecting it to return the
    removed element.

12. Forgetting to read `top()`/`front()` before `pop()` when needed.

13. Assuming every vector `push_back` is strict O(1) rather than
    amortized O(1).

14. Keeping vector iterators/references across possible reallocation.

15. Choosing `list` merely because insertion is O(1) without counting
    the cost of locating the insertion position.

16. Copying large elements unnecessarily in range loops.

17. Forgetting required headers.

18. Reimplementing a standard algorithm unnecessarily during normal
    problem solving when the goal is not to practice that algorithm.

---

## Practice questions

1. LeetCode 217 — Contains Duplicate  
   https://leetcode.com/problems/contains-duplicate/

2. LeetCode 1 — Two Sum  
   https://leetcode.com/problems/two-sum/

3. LeetCode 704 — Binary Search  
   https://leetcode.com/problems/binary-search/

4. LeetCode 215 — Kth Largest Element in an Array  
   https://leetcode.com/problems/kth-largest-element-in-an-array/

5. LeetCode 349 — Intersection of Two Arrays  
   https://leetcode.com/problems/intersection-of-two-arrays/

At this stage, focus on choosing appropriate standard containers and
understanding the complexity of each operation rather than forcing one
specific implementation.

---

## Revision checklist

Before continuing, make sure you can explain:

- containers
- algorithms
- iterators
- callables
- vector size versus capacity
- amortized `push_back`
- array
- deque
- list
- set
- map
- unordered set/map
- stack
- queue
- priority queue
- pair
- `begin()` versus `end()`
- half-open ranges
- iterator dereferencing
- `sort`
- `find`
- `count`
- `count_if`
- `reverse`
- `min_element`
- `max_element`
- `accumulate`
- `binary_search`
- `lower_bound`
- `upper_bound`
- iterator invalidation basics
- why container selection depends on required operations

# What's Next

Continue to:

`01_C++__/33_C++_FOR_COMPETITIVE_PROGRAMMING/`

The next lesson completes the C++ foundation with practical
competitive-programming conventions, fast I/O, integer overflow,
useful aliases, common STL patterns, test-case handling, debugging,
and constraint-driven implementation choices.
