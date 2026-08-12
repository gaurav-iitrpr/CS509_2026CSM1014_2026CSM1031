# CS509 Assignment 2 - Graph Algorithms

**Language:** C++  
**Compiler:** g++ (MinGW)  

---

## Project Overview

This assignment implements three fundamental graph algorithms using the **Compressed Sparse Row (CSR)** graph representation.

The algorithms implemented are:

- **Triangle Counting**
- **Betweenness Centrality**
- **Connected Components**

The project follows a modular design where graph representation, CSR implementation, individual algorithms, drivers, menus, and test cases are separated into different source files.

The project also includes test cases for evaluating the correctness and performance of the implemented algorithms.

---

## Author

| Name             | Entry Number    |
|------------------|-----------------|
| **Gaurav Kumar** | **2026CSM1014** |
| **Raj Kumar**    | **2026CSM1031   |

---

# Algorithms Implemented

## 1. Triangle Counting

Triangle Counting determines the number of triangles present in a graph.

A triangle is formed when three vertices are connected to each other.

Example:

```text
    0
   / \
  1---2
```

Vertices `0`, `1`, and `2` form one triangle.

### Features

- Uses CSR graph representation
- Checks neighbouring vertices
- Counts triangles
- Works efficiently with sparse graphs

---

## 2. Betweenness Centrality

Betweenness Centrality measures the importance of vertices in a graph.

A vertex has high betweenness centrality when it occurs frequently on shortest paths between other pairs of vertices.

### Features

- Calculates centrality for each vertex
- Uses graph traversal
- Uses shortest-path information
- Measures the importance of vertices

### General Process

For each source vertex:

1. Perform graph traversal.
2. Calculate shortest-path information.
3. Store predecessor information.
4. Calculate dependency values.
5. Update the centrality score.

---

## 3. Connected Components

Connected Components identifies separate connected groups in a graph.

The algorithm traverses the graph and identifies all vertices belonging to the same component.

### Algorithm

1. Create a `visited` array.
2. Iterate through all vertices.
3. If a vertex is not visited:
   - Start graph traversal from that vertex.
   - Mark all reachable vertices as visited.
   - Increment the component count.
4. Continue until all vertices are processed.

### Time Complexity

```text
O(V + E)
```

where:

- `V` = Number of vertices
- `E` = Number of edges

---

# Graph Representation

The project uses **Compressed Sparse Row (CSR)** representation for storing the graph.

CSR mainly uses:

```text
rowPtr
colIndex
values
```

### rowPtr

Stores the starting position of the neighbours of each vertex.

### colIndex

Stores the neighbouring vertices.

### values

Stores the corresponding edge values.

CSR provides compact storage and efficient traversal for sparse graphs.

---

# Project Structure

```text
CS509_2026CSM1014/
│
├── assignment_02/
│   │
│   ├── driver/
│   │   ├── driver.cpp
│   │   └── driver.h
│   │
│   ├── wrapper/
│   │   ├── menu.cpp
│   │   └── menu.h
│   │
│   ├── triangle_counting/
│   │   ├── driver.cpp
│   │   ├── triangle_counting.cpp
│   │   └── triangle_counting.h
│   │
│   ├── betweenness_centrality/
│   │   ├── driver.cpp
│   │   ├── betweenness_centrality.cpp
│   │   └── betweenness_centrality.h
│   │
│   ├── connected_components/
│   │   ├── driver.cpp
│   │   ├── connected_components.cpp
│   │   └── connected_components.h
│   │
│   ├── tools/
│   │   └── generate_tests.cpp
│   │
│   └── tests/
│       │
│       ├── triangle_counting/
│       │   ├── tc_10.txt
│       │   └── generated_tc.txt
│       │
│       ├── betweenness_centrality/
│       │   ├── bc_10.txt
│       │   └── generated_bc.txt
│       │
│       └── connected_components/
│           ├── cc_10.txt
│           └── generated_cc.txt
│
├── common/
│   ├── csr.cpp
│   ├── csr.h
│   ├── graph.cpp
│   └── graph.h
│
├── common_wrapper/
│   └── wrapper.cpp
│
└── README.md
```

---

# File Description

## assignment_02/driver

### driver.cpp

Controls the execution of Assignment 2 and provides the main interface for selecting the required graph algorithm.

### driver.h

Contains declarations used by the Assignment 2 driver.

---

## assignment_02/wrapper

### menu.cpp

Provides the menu interface for selecting:

```text
1. Triangle Counting
2. Betweenness Centrality
3. Connected Components
0. Back
```

### menu.h

Contains menu-related declarations.

---

## assignment_02/triangle_counting

### triangle_counting.cpp

Contains the implementation of the Triangle Counting algorithm.

### triangle_counting.h

Contains declarations required by the Triangle Counting implementation.

### driver.cpp

Handles execution of Triangle Counting test cases and displays results and execution time.

---

## assignment_02/betweenness_centrality

### betweenness_centrality.cpp

Contains the implementation of the Betweenness Centrality algorithm.

### betweenness_centrality.h

Contains declarations required by the Betweenness Centrality implementation.

### driver.cpp

Handles test-case execution and displays centrality values and execution time.

---

## assignment_02/connected_components

### connected_components.cpp

Contains the implementation of the Connected Components algorithm.

### connected_components.h

Contains declarations required by the Connected Components implementation.

### driver.cpp

Handles test-case execution and displays the number of connected components and execution time.

---

## common

### graph.cpp / graph.h

Provides the common graph representation and graph input functionality.

### csr.cpp / csr.h

Provides the implementation of the **Compressed Sparse Row (CSR)** graph representation.

---

# Input Format

The graph input files contain graph information required by the algorithms.

The input starts with:

```text
V E
```

where:

- `V` = Number of vertices
- `E` = Number of edges

Example:

```text
5 7
0 1 4
0 2 2
1 2 3
1 3 2
2 3 1
3 4 5
4 1 -2
```

For this graph:

```text
Vertices = 5
Edges    = 7
```

---

# Test Cases

The project contains separate test directories for each algorithm.

## Triangle Counting

```text
assignment_02/tests/triangle_counting/
```

Contains:

```text
tc_10.txt
generated_tc.txt
```

---

## Betweenness Centrality

```text
assignment_02/tests/betweenness_centrality/
```

Contains:

```text
bc_10.txt
generated_bc.txt
```

---

## Connected Components

```text
assignment_02/tests/connected_components/
```

Contains:

```text
cc_10.txt
generated_cc.txt
```

---

# Test Case Generator

The project contains a graph test generator:

```text
assignment_02/tools/generate_tests.cpp
```

Compile it using:

```bash
g++ assignment_02/tools/generate_tests.cpp -o generate_assignemnt2_tests.exe
```

Run:

```bash
generate_assignemnt2_tests.exe
```

The generator can be used to create graph test cases with different graph sizes.

---

# Compilation

## Windows / MinGW

The complete project is compiled using:

```bash
g++ assignment_01/driver/driver.cpp assignment_01/wrapper/menu.cpp assignment_01/bfs/bfs.cpp assignment_01/bfs/driver.cpp assignment_01/dfs/dfs.cpp assignment_01/dfs/driver.cpp assignment_01/sssp/sssp.cpp assignment_01/sssp/driver.cpp common/csr.cpp common/graph.cpp common_wrapper/wrapper.cpp assignment_02/driver/driver.cpp assignment_02/wrapper/menu.cpp assignment_02/triangle_counting/driver.cpp assignment_02/triangle_counting/triangle_counting.cpp assignment_02/betweenness_centrality/driver.cpp assignment_02/betweenness_centrality/betweenness_centrality.cpp assignment_02/connected_components/driver.cpp assignment_02/connected_components/connected_components.cpp -o assignment.exe
```

After successful compilation, the executable:

```text
assignment.exe
```

is created.

---

# Execution

Run the executable using:

```bash
assignment.exe
```

The common assignment menu is displayed:

```text
========================================
          CS509 ASSIGNMENT MENU
========================================

1. Assignment 1
2. Assignment 2
0. Exit

Enter Choice :
```

Select:

```text
2
```

to open Assignment 2.

---

# Assignment 2 Menu

After selecting Assignment 2:

```text
========================================
          ASSIGNMENT 2
========================================

1. Triangle Counting
2. Betweenness Centrality
3. Connected Components
0. Back

Enter Choice :
```

---

# Triangle Counting Execution

Select:

```text
1. Triangle Counting
```

The program reads the selected test file, builds the graph representation, executes the algorithm, and displays the number of triangles and execution time.

Example:

```text
========== TRIANGLE COUNTING ==========

Input File : ...

Number of Triangles : ...

Execution Time : ... microseconds
```

---

# Betweenness Centrality Execution

Select:

```text
2. Betweenness Centrality
```

The program calculates the centrality value for every vertex.

Example:

```text
========== BETWEENNESS CENTRALITY ==========

Vertex 0 : ...
Vertex 1 : ...
Vertex 2 : ...

Execution Time : ... microseconds
```

---

# Connected Components Execution

Select:

```text
3. Connected Components
```

The program calculates the number of connected components in the graph.

Example:

```text
========== CONNECTED COMPONENTS ==========

Number of Connected Components : ...

Execution Time : ... microseconds
```

---

# Execution Time Measurement

The execution time of the algorithms is measured in:

```text
microseconds
```

The execution time is used to compare the practical performance of the algorithms for different graph sizes.

Example:

```text
Execution Time : 817 microseconds
```

---
# Execution Results

The following table shows the execution results and execution time for the test cases used for Assignment 2.

| Algorithm              | Test Case       | Input Size (V × E) |  Execution Time |
|------------------------|-----------------|--------------------|-----------------|
| Triangle Counting      | bc_10.txt       | 500 x 300          |  0 us           |
| Triangle Counting      | generated_bc.txt| 1000 x 1500        |  0 us           |
| Betweenness Centrality | bc_10.txt       | 100 x 50           |  2035 us        |
| Betweenness Centrality | generated_bc.txt| 500 x 1000         | 267329 us       |  
| Connected Components   | cc_10.txt       | 100 x 25           |  0     us       |  
| Connected Components   | generated_cc.txt| 500 × 1500         |  0     us       |  

> **Note:** `V` represents the number of vertices and `E` represents the number of edges.


---

# Performance Testing

Generated test cases can be used to evaluate the performance of the algorithms on different graph sizes.

The general process is:

```text
Small Graph
     |
     v
Larger Graph
     |
     v
Execute Algorithm
     |
     v
Measure Execution Time
     |
     v
Compare Performance
```

Increasing the number of vertices and edges allows the scalability and practical execution time of the algorithms to be studied.

---

# Conclusion

This assignment implements three important graph algorithms:

- **Triangle Counting**
- **Betweenness Centrality**
- **Connected Components**

The algorithms use the **Compressed Sparse Row (CSR)** representation for efficient graph storage and traversal.

The project also provides:

- Modular source code
- Separate drivers
- Menu-based execution
- Multiple test cases
- Generated test cases
- Execution-time measurement
- Common graph and CSR modules

The implementation provides a practical way to study graph algorithms and evaluate their performance on different graph sizes.

---

# Author

**Name:** Gaurav Kumar **(2026CSM1014)**
**Name:** Raj Kumar   **(2026CSM1031)**
**Course:** CS509 PG Software Lab
**Institute:** IIT Ropar
**Language:** C++
**Compiler:** g++ (MinGW)

