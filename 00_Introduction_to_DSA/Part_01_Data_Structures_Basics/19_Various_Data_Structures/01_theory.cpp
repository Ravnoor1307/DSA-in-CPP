/*
═══════════════════════════════════════════════
 VARIOUS DATA STRUCTURES — OVERVIEW
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You are packing boxes to move houses. A stack of boxes lets you add on
 top and remove from the top only (LIFO). A queue of people at a ticket
 counter serves whoever came first (FIFO). A dictionary gives you a
 word and instantly returns its meaning. A phone-book contact list lets
 you jump directly to a name. Each everyday object is a "data structure"
 — a way of storing things so that some operation becomes fast and easy.

 📖 THEORY — one line each + when to use:

 - STACK (LIFO):
   * Add (push) and remove (pop) happen only at the TOP.
   * Use: browser back-button, undo in editors, function calls,
     expression evaluation. Practical when "last in, first out".

 - QUEUE (FIFO):
   * Add at BACK, remove from FRONT — first in, first out.
   * Use: printer jobs, task scheduling, BFS traversal, ticket counter.
     Practical when "first in, first out" fairness matters.

 - LINKED LIST:
   * Nodes linked by pointers in a chain; fast insert/delete anywhere.
   * Use: memory free-lists, browser tab navigation, music playlists
     (next/prev), when size is unknown and insertions are frequent.

 - BINARY SEARCH TREE (BST):
   * Sorted tree: left < node < right; search becomes directional.
   * Use: dictionaries, symbol tables, keeping data sorted while
     inserting/deleting quickly. Balanced version: O(log N) lookups.

 - HEAP:
   * Complete binary tree with min/max at root (priority).
   * Use: priority queues, Dijkstra's shortest path, process scheduling.
     Practical when you always need the smallest/largest value fast.

 - HASH TABLE:
   * Keys → index via hash function; near-instant lookup.
   * Use: phone-book lookup by name, cache/memoization, database indexing.
     Practical when you have a "key" and want O(1)-ish search.

 - GRAPH:
   * Nodes + edges; models relationships/connections.
   * Use: maps/routes, social networks, web links. Practical when data
     has relationships, not hierarchy.

 - TRIE:
   * Tree of characters storing strings by prefixes; shared prefixes
     stored once.
   * Use: autocomplete, spell-check, IP routing, word dictionaries.
     Practical when many strings share prefixes.

 ASCII OVERVIEW DIAGRAM:

  STACK                  QUEUE                 LINKED LIST
  top → ┌───┐           ──> [ 3 ][ 7 ][ 1 ]     HEAD → [5]─[2]─[9]─NULL
        │ 5 │  push       front        back
        │ 7 │  pop               queue: first in,
        │ 2 │   from top        first out (FIFO)
        └───┘

  BST                    HEAP                   HASH TABLE
       ┌─50─┐              ┌─10─┐              key "raj" → hash → index 3
      30    70            (min)  20
     /  \\  /      ┌────────┐──┘    array[h] = value
    20  40 60   25      18  (smallest on top)
                                        TRIE (words: cat, car)
                                        c
                                        │
                                        a
                                       / \
                                      t   r

 - WHEN TO USE — fastest rule of thumb:
   * Need LAST item first  → STACK
   * Need FIRST item first → QUEUE
   * Insert/delete anywhere fast + no size limit → LINKED LIST
   * Need sorted order + fast search → BST (balanced)
   * Always want min/max quickly → HEAP
   * Lookup by a KEY fast → HASH TABLE
   * Relationships between things → GRAPH
   * Many strings with common prefixes → TRIE

 🧠 LOGIC — STEP BY STEP (STL demo: vector + map):

 Step 1: Pick STL containers.
    WHY: C++ gives ready-made structures. vector = dynamic array
    (like a resizable list), map = sorted key→value pairs (BST-based).

 Step 2: Use vector for "list-like" storage.
    WHY: push_back adds at the end, size() gives count, [] gives
    random access — perfect to illustrate dynamic arrays.

 Step 3: Use map for "key → value" lookup.
    WHY: map stores keys in sorted order and finds a key in O(log n)
    (it is implemented as a balanced BST).

 Step 4: Print both.
    WHY: A visual output proves the containers work and shows the
    order: vector = insertion order, map = sorted key order.

 VISUAL WALKTHROUGH:

   vector<int> v;  push_back(5, 2, 9)
      v[0]=5   v[1]=2   v[2]=9      (insertion order preserved)

   map<string,int> s;  s["apple"]=3; s["banana"]=5; s["cherry"]=1
      banana→5   cherry→1   apple→3   (printed in SORTED key order)

 DRY RUN of the demo:

   v.push_back(10)  → vector: [10]
   v.push_back(20)  → vector: [10, 20]
   v.push_back(30)  → vector: [10, 20, 30]
   Loop i=0,1,2 prints: 10 20 30  — insertion order.

   m["apple"]=3; m["banana"]=5; m["cherry"]=1
   Loop over m prints keys in sorted order: apple banana cherry,
   with values: apple→3, banana→5, cherry→1.
   Edge case: m["mango"] not inserted → loop shows nothing for it,
   but m["mango"] accessed gives 0 (default for int).

 TIME COMPLEXITY CALCULATION:
 - vector push_back: amortized O(1) — when array is full it doubles
   (occasional O(n) copy), but on average each push is constant.
 - vector random access v[i]: single array index step → O(1).
 - map insert/find: the map is a balanced BST, each step moves one
   level down, and height = log₂(n) levels → on average log₂(n) steps.
   → vector: Time O(1) per push/access, Space O(n);
     map:    Time O(log n) per insert/find, Space O(n).

 SPACE COMPLEXITY CALCULATION:
 - vector: allocates an array; worst case it holds size that is a
   power-of-two ≥ n elements → O(n) total.
 - map: one node per key-value pair, each node has data + 2 child
   pointers + color info → O(n).
   → Space Complexity = O(n) for both.

 APPROACH COMPARISON — choose your data structure:

 ┌───────────────────┬───────────────┬───────────────┬────────────────────┬───────────────────┐
 │ DS                │ Access        │ Insert        │ Delete             │ Classic use       │
 ├───────────────────┼───────────────┼───────────────┼────────────────────┼───────────────────┤
 │ Stack             │ top O(1)      │ push O(1)     │ pop O(1)           │ undo, recursion   │
 │ Queue             │ front O(1)    │ enqueue O(1)  │ dequeue O(1)       │ scheduling, BFS   │
 │ Linked list       │ search O(n)   │ O(1) (given)  │ O(1) (given)       │ playlists         │
 │ BST (balanced)    │ search O(log n)│ O(log n)     │ O(log n)           │ dictionaries      │
 │ Heap              │ min/max O(1)  │ push O(log n) │ pop O(log n)       │ priority queues   │
 │ Hash table        │ O(1) avg      │ O(1) avg      │ O(1) avg           │ lookups by key    │
 │ Graph             │ depends       │ add edge O(1) │ varies             │ relationships     │
 │ Trie              │ prefix O(len) │ O(len)        │ O(len)             │ autocomplete      │
 └───────────────────┴───────────────┴───────────────┴────────────────────┴───────────────────┘
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    // ===== DEMO 1: vector (dynamic array jaise kaam karta hai) =====
    vector<int> v;
    v.push_back(10);   // end mein 10 add
    v.push_back(20);   // end mein 20 add
    v.push_back(30);   // end mein 30 add

    cout << "vector (insertion order): ";
    // Hindi: vector ka size() = kitne elements hain
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";     // random access O(1)
    }
    cout << endl;

    // Edge case check: khali vector
    cout << "Empty vector size: " << v.empty() << endl;  // 0 = not empty

    // ===== DEMO 2: map (key → value, sorted keys) =====
    map<string, int> m;
    m["apple"]  = 3;    // apple ka price 3
    m["banana"] = 5;    // banana ka price 5
    m["cherry"] = 1;    // cherry ka price 1

    cout << "map (sorted key order): ";
    // Hindi: map apne aap keys ko sorted order mein rakhta hai
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << "->" << it->second << "  ";
    }
    cout << endl;

    // Find operation: key exist karti hai ya nahi
    map<string, int>::iterator f = m.find("banana");
    if (f != m.end()) {
        cout << "banana mil gaya: price " << f->second << endl;
    }

    // Edge case: missing key access deta hai default value 0
    cout << "mango (not inserted) default value: " << m["mango"] << endl;  // 0

    return 0;
}