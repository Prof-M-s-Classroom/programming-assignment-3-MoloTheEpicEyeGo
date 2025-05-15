[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Travis Trinidad

## Description
This program implements a MST by following Prims Algorithim. It also uses heaps to efficiently choose the next vertex to add to the Minimum Spanning Tree (MST).

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation           | Time Complexity     |
|---------------------|---------------------|
| Insert in MinHeap   | O(1)                |
| Extract Min         | O(log V)            | 
| Decrease Key        | O(log V)            |
| Prim’s MST Overall  | O(V^2)              |

Inserting in MinHeap is finished as soon as initialization, so every connection to a vertex is constant

Log V because it removes the root node then has to find the next min value by comparing and swapping

Log V because it's also comparing values to each other until it reaches the top

V^2 because every time you add a new vertex, you check every possible path and pick the cheapest


## Test Case Description

Input:  

if we input the following vertices:
- 0 - 1 (weight 2)
- 0 - 3 (weight 6)
- 1 - 2 (weight 3)
- 1 - 3 (weight 8)
- 1 - 4 (weight 5)
- 2 - 4 (weight 7)
- 3 - 4 (weight 9)

we can input this in our code like this:

- `Graph g(5);`
- `g.addEdge(0, 1, 2);`
- `g.addEdge(0, 3, 6);`
- `g.addEdge(1, 2, 3);`
- `g.addEdge(1, 3, 8);`
- `g.addEdge(1, 4, 5);`
- `g.addEdge(2, 4, 7);`
- `g.addEdge(3, 4, 9);`
- `g.primMST();`

from this, the output is:

- Edge    Weight
- 0 - 1   2
- 1 - 2   3
- 1 - 4   5
- 0 - 3   6
- Total Cost: 16


## Edge Case Possibility

- An MST with all same edge weights
- MST with a complete graph (every single node has a direct edge to every other node.)
- A straight line of vertices (the path is the path itself)

## bugs or difficulties you overcame during implementation.
- Alot of logical errors especially with the "if conditions"
- Figuring out the solution for the "if conditions"