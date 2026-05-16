# cpp-treap-implementation
A template-based implementation of a Treap (randomized binary search tree), combining properties of a Heap and a Binary Search Tree. Supports comparable data types. This project focuses on manual memory management and low-level data structure design.
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
- Keys in the left subtree are less than keys in the right subtree
- Node priorities follow a heap property: each node has a higher priority than its children
## How to build
Use any modern C++ compiler
```bash
g++ -std=c++23 -Wall -Wextra -pedantic -O3 main.cpp -o main
```
Run the program
```bash
./main
```