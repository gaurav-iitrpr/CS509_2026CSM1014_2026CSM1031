#ifndef CSR_H
#define CSR_H

#include "graph.h"
#include <vector>

using namespace std;

// CSR Graph Structure
struct CSRGraph
{
    int vertices;
    int edges;

    vector<int> rowPtr;     // Size = V + 1
    vector<int> colIndex;   // Size = E
    vector<int> values;     // Edge weights
};

// Convert Adjacency List -> CSR
CSRGraph convertToCSR(const Graph &graph);

#endif