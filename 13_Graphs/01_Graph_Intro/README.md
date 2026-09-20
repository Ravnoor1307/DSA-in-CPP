# 01_Graph_Intro

## Real-world analogy summary

Graph non-hierarchical connections ke liye use hota hai. Google Maps me cities nodes hain aur roads edges. Instagram me users nodes hain aur follows directed edges. Computer network me machines nodes hain aur cable/wifi links edges.

```text
Graph ⊃ Tree
Tree = connected graph with no cycle
```

## Terminology table

| Term | Meaning | Real-world analogy |
|---|---|---|
| Vertex / Node | object/entity | city/user/computer |
| Edge | connection | road/follow/link |
| Directed edge | one-way relation | Instagram follow |
| Undirected edge | two-way relation | two-way road |
| Weighted edge | connection with cost | distance/time/toll |
| Degree | number of incident edges | number of direct friends |
| Neighbor | directly connected node | direct friend/city by road |
| Path | sequence of connected nodes | route between cities |
| Cycle | path returns to start | round trip |
| Connected | all nodes reachable | one connected road network |
| Disconnected | separate components | separate friend circles |

## Common mistakes

1. Graph ko tree samajhna. Tree special graph hai, but every graph tree nahi hota.
2. Directed edge ko undirected jaise add karna.
3. Weighted graph me weight store karna bhoolna.
4. Connected and complete graph confuse karna.
5. Cycle and path confuse karna.

## Interview questions

1. Graph data structure kya hota hai?
2. Tree graph ka special case kaise hai?
3. Vertex and edge difference explain karo.
4. Directed vs undirected graph examples do.
5. Weighted vs unweighted graph examples do.
6. Degree, neighbor, path, cycle define karo.
7. Connected and disconnected graph me difference kya hai?
