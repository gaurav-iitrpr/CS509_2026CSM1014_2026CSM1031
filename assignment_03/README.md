# CS509 - Assignment 3

## Buddy Task: Gradient Descent and Maxflow-Mincut

This assignment implements two algorithms as a Buddy Task:

1. **Gradient Descent**
2. **Maxflow-Mincut**

The implementation is written in **C++** and is integrated with the existing Assignment 1 and Assignment 2 project without changing their algorithm implementations.

---


---

## Author

| Name             | Entry Number    |
|------------------|-----------------|
| **Gaurav Kumar** | **2026CSM1014** |
| **Raj Kumar**    | **2026CSM1031** |

---

## 1. Project Structure

```text
CS509_2026CSM1014_2026CSM1031/
│
├── assignment_03/
│   │
│   ├── driver/
│   │   ├── driver.cpp
│   │   └── driver.h
│   │
│   ├── gradient_descent/
│   │   ├── gradient_descent.cpp
│   │   ├── gradient_descent.h
│   │   └── driver.cpp
│   │
│   ├── maxflow_mincut/
│   │   ├── maxflow_mincut.cpp
│   │   ├── maxflow_mincut.h
│   │   └── driver.cpp
│   │
│   ├── wrapper/
│   │   ├── menu.cpp
│   │   └── menu.h
│   │
│   ├── tests/
│   │   ├── gradient_descent/
│   │   │   ├── gd_01.txt
│   │   │   ├── gd_02.txt
│   │   │   ├── gd_03.txt
│   │   │   ├── gd_04.txt
│   │   │   └── gd_05.txt
│   │   │
│   │   └── maxflow_mincut/
│   │       ├── maxflow_10.txt
│   │       ├── maxflow_100.txt
│   │       ├── maxflow_1000.txt
│   │       ├── maxflow_10000.txt
│   │       └── maxflow_50000.txt
│   │
│   └── tools/
│       └── generate_maxflow_mincut.cpp
│
└── README.md
```

The Assignment 3 structure shown above focuses only on the files and folders introduced for this Buddy Task. Assignment 1, Assignment 2, and the existing common components are not expanded here.

---

## 2. Gradient Descent

Gradient Descent is an iterative optimization algorithm used to minimize an objective function.

For this assignment, the objective function is represented as a one-variable polynomial:

```text
f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d
```

Its derivative is:

```text
f'(x) = c1 + 2*c2*x + 3*c3*x^2 + ... + d*cd*x^(d-1)
```

The update rule is:

```text
x_new = x - learning_rate * f'(x)
```

The algorithm stops when:

```text
|f'(x)| <= tolerance
```

or when the maximum number of iterations is reached.

The implementation is generic and supports all required polynomial degrees without using separate hard-coded algorithms.

### Required Tests

| File | Degree | Initial x | Learning Rate | Tolerance | Max Iterations | Expected x* |
|---|---:|---:|---:|---:|---:|---:|
| `gd_01.txt` | 2 | 0 | 0.10 | 1e-6 | 5,000 | 3 |
| `gd_02.txt` | 4 | 2 | 0.02 | 1e-6 | 10,000 | 0 |
| `gd_03.txt` | 6 | 2 | 0.02 | 1e-6 | 20,000 | 0 |
| `gd_04.txt` | 8 | 2 | 0.01 | 1e-8 | 50,000 | 0 |
| `gd_05.txt` | 10 | 2 | 0.005 | 1e-10 | 100,000 | 0 |

### Gradient Descent Output

For every test, the program reports:

- Polynomial degree
- Final x
- Final f(x)
- Number of iterations
- Convergence status
- Algorithm execution time

---

## 3. Maxflow-Mincut

The Maxflow problem finds the maximum amount of flow that can be sent from a source vertex to a sink vertex without exceeding edge capacities.

For this assignment, **Dinic's algorithm** is used.

The input graph is first read as an adjacency list and converted to **CSR (Compressed Sparse Row)** using the existing common CSR implementation.

The CSR conversion is preprocessing and is not included in the measured algorithm execution time.

### Maxflow Processing

```text
Input File
    |
    v
Adjacency List
    |
    v
Existing CSR Conversion
    |
    v
CSR Graph
    |
    v
Dinic's Algorithm
    |
    +----> Maximum Flow
    |
    v
Final Residual Graph
    |
    v
Minimum Cut
```

After maximum flow is computed, the vertices reachable from the source in the final residual graph form the source side of the minimum cut.

The minimum-cut capacity must be equal to the maximum-flow value.

### Required Graph Sizes

| File | Vertices | Edges |
|---|---:|---:|
| `maxflow_10.txt` | 6* | 10 |
| `maxflow_100.txt` | 100 | 300 |
| `maxflow_1000.txt` | 1,000 | 3,000 |
| `maxflow_10000.txt` | 10,000 | 30,000 |
| `maxflow_50000.txt` | 50,000 | 150,000 |

\* `maxflow_10.txt` is the assignment's provided example containing 6 vertices and 10 directed edges.

The larger test files are generated using:

```text
assignment_03/tools/generate_maxflow_mincut.cpp
```

The generated graphs are sparse and contain a guaranteed source-to-sink path.

---

## 4. Input Format

### 4.1 Gradient Descent

```text
DEGREE d
COEFFICIENTS c0 c1 c2 ... cd
INITIAL_X x0
LEARNING_RATE alpha
TOLERANCE epsilon
MAX_ITERATIONS n
```

Example:

```text
DEGREE 6
COEFFICIENTS 0 0 1 0 0.5 0 0.1
INITIAL_X 2
LEARNING_RATE 0.02
TOLERANCE 1e-6
MAX_ITERATIONS 20000
```

### 4.2 Maxflow-Mincut

```text
V E
u degree neighbor1 capacity1 neighbor2 capacity2 ...
...
SOURCE s
SINK t
```

Example:

```text
6 10
0 2 1 16 2 13
1 2 2 10 3 12
2 2 1 4 4 14
3 2 2 9 5 20
4 2 3 7 5 4
5 0
SOURCE 0
SINK 5
```

Only outgoing edges are listed for directed Maxflow graphs. Reverse residual edges are created internally by Dinic's algorithm.

---

## 5. Program Menu

Assignment 3 is accessed from the common assignment menu:

```text
=====================================
       CS509 Assignment Menu
=====================================
1. Assignment 1
2. Assignment 2
3. Assignment 3
0. Exit
```

Selecting Assignment 3 gives:

```text
=====================================
        Assignment 3 Menu
=====================================
1. Gradient Descent
2. Maxflow-Mincut
0. Back
```

Each algorithm provides options for individual test files and running all test files.

---

## 6. Compilation

The complete project can be compiled from the project root using:

```cmd
g++ assignment_01/driver/driver.cpp assignment_01/wrapper/menu.cpp assignment_01/bfs/bfs.cpp assignment_01/bfs/driver.cpp assignment_01/dfs/dfs.cpp assignment_01/dfs/driver.cpp assignment_01/sssp/sssp.cpp assignment_01/sssp/driver.cpp common/csr.cpp common/graph.cpp common_wrapper/wrapper.cpp assignment_02/driver/driver.cpp assignment_02/wrapper/menu.cpp assignment_02/triangle_counting/driver.cpp assignment_02/triangle_counting/triangle_counting.cpp assignment_02/betweenness_centrality/driver.cpp assignment_02/betweenness_centrality/betweenness_centrality.cpp assignment_02/connected_components/driver.cpp assignment_02/connected_components/connected_components.cpp assignment_03/gradient_descent/gradient_descent.cpp assignment_03/gradient_descent/driver.cpp assignment_03/maxflow_mincut/maxflow_mincut.cpp assignment_03/maxflow_mincut/driver.cpp assignment_03/driver/driver.cpp assignment_03/wrapper/menu.cpp -o assignment.exe
```

Run the program using:

```cmd
assignment.exe
```

---

## 7. Generating Maxflow Test Files

The generator can be compiled using:

```cmd
g++ assignment_03/tools/generate_maxflow_mincut.cpp -o generate_maxflow_mincut.exe
```

Run:

```cmd
generate_maxflow_mincut.exe
```

This generates the larger required test files in:

```text
assignment_03/tests/maxflow_mincut/
```

The `maxflow_10.txt` sample is kept separately and is not overwritten by the generator.

---

## 8. Correctness Results

---

## 9. Gradient Descent Execution-Time Table

Use the following table for the final performance measurements.

| File | Degree | Iterations | Execution Time (µs) | Status |
|---|---:|---:|---:|---|
| `gd_01.txt` | 2 | 70 | 0 | Pass |
| `gd_03.txt` | 6 | 349 | 0 | Pass |
| `gd_02.txt` | 4 | 180 | 0 | Pass |
| `gd_04.txt` | 8 | 948 | 0 | Pass |
| `gd_05.txt` | 10 | 2364 | 1036 | Pass |

For very fast inputs, repeated runs may be used and the average execution time may be reported, provided the number of runs is documented.

---

## 10. Maxflow-Mincut Results

| File | Vertices | Edges | Source | Sink | Expected Flow | Actual Flow | Cut Capacity | Time | Status |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| `maxflow_10.txt` | 6 | 10 | 0 | 5 | 23 | 23 | 23 | **Fill final time** | Pass |
| `maxflow_100.txt` | 100 | 300 | 0 | 99 | — | — | — | — | — |
| `maxflow_1000.txt` | 1,000 | 3,000 | 0 | 999 | — | — | — | — | — |
| `maxflow_10000.txt` | 10,000 | 30,000 | 0 | 9,999 | — | — | — | — | — |
| `maxflow_50000.txt` | 50,000 | 150,000 | 0 | 49,999 | — | — | — | — | — |

For generated graphs, the expected flow is not hard-coded in this README. It should be recorded from a correctness check and verified against the minimum-cut capacity.

---

## 11. Maxflow-Mincut Execution-Time Table

| File | Vertices | Edges | Execution Time (µs) | Execution Time (ms) | Maxflow = Mincut? | Status |
|---|---:|---:|---:|---:|---|---|
| `maxflow_10.txt` | 6 | 10 | ______ | ______ | Yes | Pass |
| `maxflow_100.txt` | 100 | 300 | ______ | ______ | ______ | ______ |
| `maxflow_1000.txt` | 1,000 | 3,000 | ______ | ______ | ______ | ______ |
| `maxflow_10000.txt` | 10,000 | 30,000 | ______ | ______ | ______ | ______ |
| `maxflow_50000.txt` | 50,000 | 150,000 | ______ | ______ | ______ | ______ |

---

## 12. Timing Methodology

Only the algorithm execution time is measured.

The following operations are excluded from the reported algorithm time:

- File reading
- Input parsing
- Adjacency-list construction
- CSR conversion
- Result printing
- File writing

For Maxflow-Mincut, initialization of the residual network and minimum-cut extraction from the final residual graph are included in the measured algorithm section.

For Gradient Descent, polynomial evaluation, derivative evaluation, and iterative updates are included in the measured section.

---

## 13. Validation

### Gradient Descent

A test is considered successful when:

- The input is valid.
- The algorithm converges within the allowed maximum iterations, or correctly reports non-convergence.
- The final value is sufficiently close to the expected minimum.
- The reported result contains degree, final x, f(x), iterations, convergence status, and execution time.

### Maxflow-Mincut

A test is considered successful when:

```text
Maximum Flow = Minimum Cut Capacity
```

and the reported source/sink partition and cut edges correspond to a valid minimum cut.

---

## 14. Error Handling

The implementation validates important input conditions.

### Gradient Descent

The program rejects:

- Invalid degree
- Invalid coefficient count
- Non-positive learning rate
- Non-positive tolerance
- Non-positive maximum iterations

### Maxflow-Mincut

The program rejects:

- Invalid source vertex
- Invalid sink vertex
- Source equal to sink
- Negative capacities

---

## 15. Summary

Assignment 3 implements:

```text
Gradient Descent
    ├── Generic polynomial evaluation
    ├── Generic derivative evaluation
    ├── Iterative optimization
    └── Performance measurement

Maxflow-Mincut
    ├── Adjacency-list input
    ├── Existing CSR conversion
    ├── Dinic's maximum-flow algorithm
    ├── Residual graph processing
    ├── Minimum-cut extraction
    └── Performance measurement
```

The implementation is integrated with the existing project while keeping Assignment 1 and Assignment 2 algorithm implementations unchanged.

# Author

**Name:** Gaurav Kumar **(2026CSM1014)**
**Name:** Raj Kumar   **(2026CSM1031)**
**Course:** CS509 PG Software Lab
**Institute:** IIT Ropar
**Language:** C++
**Compiler:** g++ (MinGW)