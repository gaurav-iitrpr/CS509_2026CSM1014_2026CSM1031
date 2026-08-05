#ifndef CSR_H
#define CSR_H

#include "graph.h"
#include <vector>

using namespace std;

struct CSRGraph
{
    int vertices;
    int edges;

    vector<int> rowPtr;     
    vector<int> colIndex;   
    vector<int> values;     
};

CSRGraph convertToCSR(const Graph &graph);

#endif