#ifndef MAXFLOW_MINCUT_H
#define MAXFLOW_MINCUT_H

#include "../../common/csr.h"

#include <vector>
#include <string>

using namespace std;


struct CutEdge
{
    int from;
    int to;
    int capacity;
};


struct FlowResult
{
    long long maxFlow;

    vector<int> sourceSide;
    vector<int> sinkSide;

    vector<CutEdge> cutEdges;
};


FlowResult maxFlowMinCut(
    const CSRGraph& csrGraph,
    int source,
    int sink
);


void runMaxFlowMinCut(
    const string& filename
);

#endif