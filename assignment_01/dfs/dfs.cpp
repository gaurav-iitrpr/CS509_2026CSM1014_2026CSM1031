#include "dfs.h"
using namespace std;

void dfsHelper(const CSRGraph &graph,
               int current,
               vector<bool> &visited,
               vector<int> &traversal)
{
    visited[current] = true;
    traversal.push_back(current);

    for (int i = graph.rowPtr[current];
         i < graph.rowPtr[current + 1];
         i++)
    {
        int neighbour = graph.colIndex[i];

        if (!visited[neighbour])
        {
            dfsHelper(graph, neighbour, visited, traversal);
        }
    }
}

vector<int> dfsTraversal(const CSRGraph &graph, int source)
{
    vector<bool> visited(graph.vertices, false);

    vector<int> traversal;

    dfsHelper(graph,
              source,
              visited,
              traversal);

    return traversal;
}