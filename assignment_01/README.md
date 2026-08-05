# CS509 Assignment 1
## Graph Algorithms using Compressed Sparse Row (CSR)

---

## Team Members

| Name         | Roll Number |
|--------------|-------------|
| Gaurav Kumar | 2026CSM1014 |
| Raj Kumar    | 2026CSM1031 |

---

# Project Overview

This project implements three fundamental graph algorithms using the **Compressed Sparse Row (CSR)** graph representation.

The algorithms implemented are:

- Breadth First Search (BFS)
- Depth First Search (DFS)
- Single Source Shortest Path (SSSP) using Dijkstra's Algorithm

The project is developed in **C++** using a modular design where each algorithm is implemented independently. Execution time of each algorithm is measured using the C++ **chrono** library.

---

# Objectives

The objectives of this assignment are:

- Read graph input from a text file.
- Store the graph using an Adjacency List.
- Convert the graph into CSR format.
- Implement BFS, DFS and SSSP algorithms.
- Measure execution time.
- Provide a menu-driven interface.

---

# Project Structure

```
# Project Structure

```
 assignment_01/
    │
    ├── bfs/
    │   ├── bfs.cpp
    │   ├── bfs.h
    │   └── driver.cpp
    │
    ├── dfs/
    │   ├── dfs.cpp
    │   ├── dfs.h
    │   └── driver.cpp
    │
    ├── sssp/
    │   ├── sssp.cpp
    │   ├── sssp.h
    │   └── driver.cpp
    │
    ├── common/
    │   ├── graph.cpp
    │   ├── graph.h
    │   ├── csr.cpp
    │   └── csr.h
    │
    ├── wrapper/
    │   ├── main.cpp
    │   ├── menu.cpp
    │   └── menu.h
    │
    ├── tests/
    │   ├── bfs/
    │   ├── dfs/
    │   └── sssp/
    │
    ├── outputs/
    │
    ├── tools/
    │   └── generate_tests.cpp
    │
    ├── assignment.exe
    ├── README.md
    
```

---

# Modules

### common/
Contains common functions used by all algorithms.

- Read graph from file
- Build adjacency list
- Convert graph into CSR format

### bfs/
Implements Breadth First Search.

Outputs:
- BFS Traversal
- Distance from Source
- Execution Time

### dfs/
Implements Depth First Search.

Outputs:
- DFS Traversal
- Execution Time

### sssp/
Implements Dijkstra's Single Source Shortest Path Algorithm.

Outputs:
- Shortest Distance from Source
- Execution Time

### wrapper/
Provides a menu-driven interface to execute BFS, DFS and SSSP on different test files.

### tests/
Contains sample and generated graph input files.

### tools/
Contains the test case generator.

---

# Input

The program reads graph data from text files stored inside the **tests/** directory.

The user performs the following steps:

1. Run the executable.
2. Select an algorithm (BFS / DFS / SSSP).
3. Select the desired test file.
4. The selected file is loaded automatically.

### Input Format (BFS / DFS)

```
<number_of_vertices> <number_of_edges>

<vertex> <number_of_neighbors> <neighbor1> <neighbor2> ...

...

SOURCE <source_vertex>
```

Example

```
10 9
0 1 1
1 1 2
2 1 3
3 1 4
4 1 5
5 1 6
6 1 7
7 1 8
8 1 9
9 0
SOURCE 0
```

### Input Format (SSSP)

```
<number_of_vertices> <number_of_edges>

<vertex> <number_of_neighbors>
<neighbor1> <weight1>
<neighbor2> <weight2>
...

SOURCE <source_vertex>
```

Example

```
10 9
0 1 1 4
1 1 2 6
2 1 3 2
3 1 4 5
4 1 5 3
5 1 6 8
6 1 7 1
7 1 8 7
8 1 9 2
9 0
SOURCE 0
```

---

# Output

Depending on the selected algorithm, the program produces the following output.

| Algorithm | Output |
|-----------|--------|
| BFS       | CSR Representation, BFS Traversal, Distance from Source, Execution Time |
| DFS       | CSR Representation, DFS Traversal, Execution Time |
| SSSP      | CSR Representation, Shortest Distance from Source, Execution Time |

Example BFS Output

```
CSR Representation Created

BFS Traversal
0 1 2 3 4 5 6 7 8 9

Distance from Source

Vertex   Distance
0        0
1        1
2        2
...

Execution Time : 25 microseconds
```

Example DFS Output

```
CSR Representation Created

DFS Traversal
0 1 2 3 4 5 6 7 8 9

Execution Time : 18 microseconds
```

Example SSSP Output

```
CSR Representation Created

Shortest Distance from Source

Vertex   Distance
0        0
1        4
2        10
...

Execution Time : 31 microseconds
```

---

# Compilation

Compile the project using:

```bash
g++ wrapper/main.cpp wrapper/menu.cpp bfs/driver.cpp bfs/bfs.cpp dfs/driver.cpp dfs/dfs.cpp sssp/driver.cpp sssp/sssp.cpp common/graph.cpp common/csr.cpp -o assignment.exe
```

---

# Running the Project

Run the executable:

```bash
assignment.exe
```

Main Menu

```
1. BFS
2. DFS
3. SSSP
0. Exit
```

Choose the desired algorithm and then select the required test case.

---

# Test Case Generator

Compile

```bash
g++ tools/generate_tests.cpp -o generate_tests.exe
```

Run

```bash
generate_tests.exe
```

Enter the number of vertices.

The generated test files are stored in:

```
tests/bfs/generated_bfs.txt
tests/dfs/generated_dfs.txt
tests/sssp/generated_sssp.txt
```

---

# Performance Analysis

| Algorithm | Test File          | Execution Time (µs) |
|-----------|------------------- |--------------------:|
| BFS       | bfs_10.txt         |  799 microseconds   |
| BFS       | generated_bfs.txt  |    0 microseconds   |
| DFS       | dfs_10.txt         |    0 microseconds   |
| DFS       | generated_dfs.txt  |    0 microseconds   |           |
| SSSP      | sssp_10.txt        |    0 microseconds   |
| SSSP      | generated_sssp.txt |    0 microseconds   |


---

# Time Measurement

Execution time is measured using

```cpp
std::chrono::high_resolution_clock
```

Only the execution of the algorithm is measured. File reading and CSR conversion are excluded from timing.

---

# Algorithms Used

| Algorithm | Time Complexity  | Space Complexity |
|-----------|------------------|------------------|
| BFS       | O(V + E)         |            O(V)  |
| DFS       | O(V + E)         |            O(V)  |
| Dijkstra  | O((V + E) log V) |         O(V + E) |

---

# Language and Compiler

- Language : C++
- Compiler : g++

---

# Conclusion

This project successfully implements BFS, DFS and Dijkstra's SSSP using the Compressed Sparse Row (CSR) representation. The modular structure, menu-driven execution, test case generator and execution time analysis make the implementation easy to understand, test and evaluate.