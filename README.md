# cpp-treap-implementation
A template-based implementation of a Treap (randomized binary search tree), combining properties of a Heap and a Binary Search Tree. Supports comparable data types and focuses on manual memory management, recursive tree operations, and low-level data structure design.

## Features
- Insert and remove elements
- Search operations
- Split and merge operations
- Find minimum and maximum elements
- Remove minimum and maximum elements
- Copy and move semantics support
- Constructing using std::initializer_list
- Template-based implementation
- Inorder traversal and vector conversion
- Simple CLI for testing

## Data structure overview
A Treap maintains two invariants which guarantee expected O(log n) time complexity for basic operations:
- Keys are kept in sorted order, so duplicate values can be stored in the tree
- Node priorities follow a heap property: each node has a higher priority than its children

This gives a randomized BST that behaves like a heap during rotations, making insertion and deletion efficient in practice.

## How to build
Use CMake from the project root:
```bash
cmake -S . -B build
cmake --build build
```

Run the interactive demo:
```bash
./build/treap_demo
```

Run the tests:
```bash
ctest --test-dir build --output-on-failure
```

## Benchmark results
All benchmarks were run in Release mode (-O3).  
Each result is the median of 5 runs.

---

### What I tested
- Random insert - N random elements inserted  
- Random find - 2N lookup queries  
- Sorted insert - increasing keys  
- Mixed insert/delete - 4N mixed operations  

---

### Results
| Scenario        | N     | Treap (ms) | std::multiset (ms) |
|----------------|------:|------------:|--------------------:|
| Random insert  | 1e3   | 0.184       | 0.062               |
|                | 1e5   | 43.594      | 22.465              |
|                | 1e6   | 987.991     | 598.055             |
| Random find    | 1e3   | 0.055       | 0.048               |
|                | 1e5   | 26.951      | 28.137              |
|                | 1e6   | 848.631     | 658.180             |
| Sorted insert  | 1e3   | 0.075       | 0.050               |
|                | 1e5   | 10.400      | 14.627              |
|                | 1e6   | 113.920     | 214.302             |
| Mixed ops      | 1e3   | 0.325       | 0.162               |
|                | 1e5   | 63.859      | 37.861              |
|                | 1e6   | 1170.329    | 840.989             |

---

### Key takeaways
- Treap is faster on sorted inserts (up to ~2× at large scale)
- std::multiset performs better on random and mixed workloads
- Lookup performance is broadly similar across both implementations
- Differences are driven by constant factors and memory behavior rather than Big-O complexity