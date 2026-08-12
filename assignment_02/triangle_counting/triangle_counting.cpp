#include "triangle_counting.h"

using namespace std;


// Check whether edge u -> v exists
bool edgeExists(const CSRGraph &graph, int u, int v)
{
    for(int i = graph.rowPtr[u];
        i < graph.rowPtr[u + 1];
        i++)
    {
        if(graph.colIndex[i] == v)
        {
            return true;
        }
    }

    return false;
}


// Count triangles
int countTriangles(const CSRGraph &graph)
{
    int triangles = 0;

    for(int u = 0; u < graph.vertices; u++)
    {
        for(int i = graph.rowPtr[u];
            i < graph.rowPtr[u + 1];
            i++)
        {
            int v = graph.colIndex[i];

            if(v <= u)
                continue;

            for(int j = i + 1;
                j < graph.rowPtr[u + 1];
                j++)
            {
                int w = graph.colIndex[j];

                if(w <= u)
                    continue;

                if(edgeExists(graph, v, w))
                {
                    triangles++;
                }
            }
        }
    }

    return triangles;
}