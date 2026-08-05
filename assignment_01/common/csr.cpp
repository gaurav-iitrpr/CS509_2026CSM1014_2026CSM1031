#include "csr.h"

using namespace std;

CSRGraph convertToCSR(const Graph &graph)
{
    CSRGraph csr;

    csr.vertices = graph.vertices;
    csr.edges = graph.edges;

    csr.rowPtr.resize(graph.vertices + 1);

    int index = 0;

    for (int i = 0; i < graph.vertices; i++)
    {
        csr.rowPtr[i] = index;

        for (const Edge &edge : graph.adjacencyList[i])
        {
            csr.colIndex.push_back(edge.destination);
            csr.values.push_back(edge.weight);

            index++;
        }
    }

    csr.rowPtr[graph.vertices] = index;

    return csr;
}