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