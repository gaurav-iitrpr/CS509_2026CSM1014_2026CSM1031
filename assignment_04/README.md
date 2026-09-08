# CS509 - Assignment 4

**Language:** C++  
**Compiler:** g++ (MinGW)

---

## Buddy Task: K-Means Clustering and FastMap

This assignment implements two algorithms as a Buddy Task:

1. **K-Means Clustering**
2. **FastMap**

The implementation is written in **C++** and is integrated with the existing Assignment 1, Assignment 2, and Assignment 3 project.

---

## Author

| Name | Entry Number |
|---|---|
| **Gaurav Kumar** | **2026CSM1014** |
| **Raj Kumar** | **2026CSM1031** |

---

## 1. Project Structure

```text
CS509_2026CSM1014_2026CSM1031/
│
├── assignment_04/
│   │
│   ├── driver/
│   │   ├── driver.cpp
│   │   └── driver.h
│   │
│   ├── kmeans/
│   │   ├── kmeans.cpp
│   │   ├── kmeans.h
│   │   └── driver.cpp
│   │
│   ├── fastmap/
│   │   ├── fastmap.cpp
│   │   ├── fastmap.h
│   │   └── driver.cpp
│   │
│   ├── wrapper/
│   │   ├── menu.cpp
│   │   └── menu.h
│   │
│   └── tests/
│       │
│       ├── kmeans/
│       │   ├── km_01.txt
│       │   ├── km_02.txt
│       │   ├── km_03.txt
│       │   └── km_04.txt
│       │
│       └── fastmap/
│           ├── fm_01.txt
│           ├── fm_02.txt
│           └── fm_03.txt
│
├── assignment_01/
├── assignment_02/
├── assignment_03/
├── common/
├── common_wrapper/
└── README.md
```

The Assignment 4 structure shown above focuses on the files introduced for the Buddy Task. Assignment 1, Assignment 2, Assignment 3, and the existing common components are not expanded here.

---

## 2. K-Means Clustering

K-Means Clustering partitions `N` data points in `D`-dimensional space into `K` clusters.

Each point is assigned to the cluster whose centroid is closest to it. The objective is to minimize the **Within-Cluster Sum of Squares (WCSS)**.

The algorithm uses the first `K` input points as the initial centroids for reproducibility.

### K-Means Processing

```text
Input File
    |
    v
Data Points
    |
    v
Initialize K Centroids
    |
    v
Assign Points to Nearest Centroid
    |
    v
Update Centroids
    |
    v
Check Convergence
    |
    +---- No ----> Repeat
    |
    +---- Yes
    |
    v
Final Clusters and Centroids
```

The assignment step assigns every point to the nearest centroid using Euclidean distance.

The update step calculates the mean of all points assigned to each cluster.

If a cluster becomes empty, its previous centroid is kept unchanged for that iteration.

The algorithm stops when no point changes its cluster, when the maximum centroid shift is less than or equal to the tolerance, or when the maximum number of iterations is reached.

### Required Tests

| File | N | D | K | Description |
|---|---:|---:|---:|---|
| `km_01.txt` | 100 | 2 | 3 | Small dataset |
| `km_02.txt` | 1,000 | 2 | 5 | Moderate dataset |
| `km_03.txt` | 10,000 | 5 | 8 | Higher dimensionality |
| `km_04.txt` | 100,000 | 5 | 10 | Largest required dataset |

The required K-Means test sizes and K values follow the Assignment 4 specification.

### K-Means Output

For every test, the program reports:

- Cluster assignment for every point
- Final centroids
- WCSS
- Number of iterations
- Convergence status
- Algorithm execution time

---

## 3. FastMap

FastMap is a dimensionality-reduction algorithm that maps objects described by pairwise distances into a lower-dimensional Euclidean space.

The algorithm does not require the original objects to be represented as coordinate vectors. Instead, it uses the supplied pairwise distance matrix.

### FastMap Processing

```text
Input File
    |
    v
Distance Matrix
    |
    v
Select Pivot Objects
    |
    v
Calculate Coordinates
    |
    v
Deflate Remaining Distances
    |
    v
Next Dimension
    |
    +---- Repeat until k dimensions
    |
    v
Final Coordinates
```

For each target dimension:

1. Select approximately farthest pivot objects.
2. Project every object onto the line joining the two pivots.
3. Calculate the coordinate using the law of cosines.
4. Deflate the remaining pairwise distances.
5. Repeat until `k` dimensions are produced.

The pivot selection uses a farthest-object heuristic.

### Required Tests

| File | N | Target Dimensions |
|---|---:|---:|
| `fm_01.txt` | 10 | 2 |
| `fm_02.txt` | 100 | 2 |
| `fm_03.txt` | 1,000 | 3 |
| `fm_04.txt` | 10,000 | 3 |

The Assignment 4 specification also mentions an optional 50,000-object FastMap test.

### FastMap Output

For every test, the program reports:

- Pivot objects selected for every dimension
- Coordinates of every object
- Target dimensionality
- Algorithm execution time

---

## 4. Input Format

### 4.1 K-Means Clustering

```text
N D K
x0_1 x0_2 ... x0_D
x1_1 x1_2 ... x1_D
...
x(N-1)_1 x(N-1)_2 ... x(N-1)_D
MAX_ITERATIONS n
TOLERANCE epsilon
```

Example:

```text
6 2 2
1.0 1.0
1.5 2.0
3.0 4.0
5.0 7.0
3.5 5.0
4.5 5.0
MAX_ITERATIONS 300
TOLERANCE 0.0001
```

`N` represents the number of points, `D` represents the number of dimensions, and `K` represents the number of clusters.

The tolerance applies to the maximum centroid shift between iterations.

---

### 4.2 FastMap

```text
N K
d(0,0) d(0,1) ... d(0,N-1)
d(1,0) d(1,1) ... d(1,N-1)
...
d(N-1,0) d(N-1,1) ... d(N-1,N-1)
```

Example:

```text
5 2
0.0 3.0 4.0 5.0 6.0
3.0 0.0 5.0 6.0 5.0
4.0 5.0 0.0 3.0 4.0
5.0 6.0 3.0 0.0 3.0
6.0 5.0 4.0 3.0 0.0
```

The distance matrix must:

- Be square
- Be symmetric
- Have zero diagonal
- Contain non-negative distances
- Have a valid target dimensionality `k`



---

## 5. Program Menu

Assignment 4 is accessed from the common assignment menu:

```text
=====================================
       CS509 Assignment Menu
=====================================
1. Assignment 1
2. Assignment 2
3. Assignment 3
4. Assignment 4
0. Exit
```

Selecting Assignment 4 gives:

```text
=====================================
        Assignment 4 Menu
=====================================
1. K-Means Clustering
2. FastMap
0. Back
```

Each algorithm provides options for running individual test files and running the available test files.

---

## 6. Compilation

The complete project can be compiled from the project root using:

```cmd
g++ -std=c++17 -O2 common/graph.cpp common/csr.cpp assignment_01/bfs/bfs.cpp assignment_01/bfs/driver.cpp assignment_01/dfs/dfs.cpp assignment_01/dfs/driver.cpp assignment_01/sssp/sssp.cpp assignment_01/sssp/driver.cpp assignment_01/driver/driver.cpp assignment_01/wrapper/menu.cpp assignment_02/betweenness_centrality/betweenness_centrality.cpp assignment_02/betweenness_centrality/driver.cpp assignment_02/connected_components/connected_components.cpp assignment_02/connected_components/driver.cpp assignment_02/triangle_counting/triangle_counting.cpp assignment_02/triangle_counting/driver.cpp assignment_02/driver/driver.cpp assignment_02/wrapper/menu.cpp assignment_03/gradient_descent/gradient_descent.cpp assignment_03/maxflow_mincut/maxflow_mincut.cpp assignment_03/driver/driver.cpp assignment_03/wrapper/menu.cpp assignment_04/kmeans/kmeans.cpp assignment_04/fastmap/fastmap.cpp assignment_04/driver/driver.cpp assignment_04/wrapper/menu.cpp common_wrapper/wrapper.cpp -o assignment.exe
```

Run the program using:

```cmd
assignment.exe
```

The compilation command builds Assignment 1, Assignment 2, Assignment 3, and Assignment 4 into a single executable.

---

## 7. Timing Methodology

Only the algorithm execution time is measured.

The following operations are excluded from the reported algorithm time:

- File reading
- Input parsing
- Data structure setup
- Result printing
- File writing

For K-Means, the measured section includes:

- Point-to-centroid assignment
- Centroid update
- All iterations until convergence or maximum iterations

For FastMap, the measured section includes:

- Pivot selection
- Coordinate projection
- Distance deflation
- Processing of all target dimensions

The timer starts immediately before the algorithm is called and stops immediately after the algorithm finishes.

---

## 8. K-Means Results Table

Use the following table for the final performance measurements.

| File | N | D | K | Max Iter. | Actual Iter. | WCSS | Time | Status |
|---|---:|---:|---:|---:|---:|---:|---:|---|
| `km_01.txt` | 100 | 2 | 3 | 300 | ... | ... | ... ms | Pass/Fail |
| `km_02.txt` | 1,000 | 2 | 5 | 300 | ... | ... | ... ms | Pass/Fail |
| `km_03.txt` | 10,000 | 5 | 8 | 300 | ... | ... | ... ms | Pass/Fail |
| `km_04.txt` | 100,000 | 5 | 10 | 300 | ... | ... | ... ms | Pass/Fail |

The exact maximum iteration value may be set according to the input file used for each test.

---

## 9. FastMap Results Table

Use the following table for the final performance measurements.

| File | N | Target k | Pivots per Dimension | Avg. Distance Error | Time | Status |
|---|---:|---:|---|---:|---:|---|
| `fm_01.txt` | 10 | 2 | ... | ... | ... ms | Pass/Fail |
| `fm_02.txt` | 100 | 2 | ... | ... | ... ms | Pass/Fail |
| `fm_03.txt` | 1,000 | 3 | ... | ... | ... ms | Pass/Fail |
| `fm_04.txt` | 10,000 | 3 | ... | ... | ... ms | Pass/Fail |

The assignment notes that pivot selection uses a randomized heuristic, so exact coordinates can differ between correct implementations.

---

## 10. Correctness

### K-Means

A K-Means test is considered successful when:

- The input is valid.
- Every point is assigned to a valid cluster.
- The final centroids correspond to the assigned points.
- Empty clusters retain their previous centroid.
- The algorithm converges within the maximum iterations or correctly reports non-convergence.
- WCSS is calculated correctly.
- The required output and execution time are reported.

### FastMap

A FastMap test is considered successful when:

- The input distance matrix is valid.
- The matrix is symmetric.
- The diagonal contains zero values.
- Distances are non-negative.
- Valid pivot objects are selected.
- Coordinates are generated for every object.
- The requested number of dimensions is produced.
- Execution time is reported.

---

## 11. Error Handling

The implementation validates important input conditions.

### K-Means

The program rejects:

- Non-positive `N`
- Non-positive `D`
- Non-positive `K`
- `K > N`
- Non-positive tolerance
- Non-positive maximum iterations

### FastMap

The program rejects:

- Non-square distance matrices
- Non-symmetric distance matrices
- Non-zero diagonal entries
- Negative distances
- Non-positive target dimensionality
- Target dimensionality greater than or equal to `N`

These validation requirements follow the minimum expected driver behaviour specified for Assignment 4.

---

## 12. Real-Life Applications

### K-Means Clustering

K-Means can be used for:

- Customer and market segmentation
- Image compression and color quantization
- Document and text clustering
- Anomaly detection
- Feature engineering and data summarization

### FastMap

FastMap can be used for:

- Dimensionality reduction
- Data visualization
- Similarity search
- Nearest-neighbour preprocessing
- Bioinformatics
- AI search and pathfinding

---

## 13. Summary

Assignment 4 implements:

```text
K-Means Clustering
    ├── Generic N, D and K support
    ├── First K points as initial centroids
    ├── Nearest-centroid assignment
    ├── Centroid update
    ├── Empty-cluster handling
    ├── Convergence detection
    ├── WCSS calculation
    └── Performance measurement

FastMap
    ├── Pairwise distance matrix input
    ├── Farthest-object pivot selection
    ├── Law-of-cosines projection
    ├── Distance deflation
    ├── Multiple target dimensions
    └── Performance measurement
```

The same implementation is designed to work with all required test sizes rather than using hard-coded solutions for individual datasets.

---

# Author

**Name:** Gaurav Kumar **(2026CSM1014)**  
**Name:** Raj Kumar **(2026CSM1031)**  
**Course:** CS509 PG Software Lab  
**Institute:** IIT Ropar  
**Language:** C++  
**Compiler:** g++ (MinGW)