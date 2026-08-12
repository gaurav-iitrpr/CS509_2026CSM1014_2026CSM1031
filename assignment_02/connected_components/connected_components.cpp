#include "connected_components.h"

#include <vector>
#include <queue>

using namespace std;


// BFS from one vertex
void bfsComponent(
    const CSRGraph &graph,
    int start,
    vector<bool> &visited)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = graph.rowPtr[u];
            i < graph.rowPtr[u + 1];
            i++)
        {
            int v = graph.colIndex[i];

            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


// Count connected components
int countConnectedComponents(const CSRGraph &graph)
{
    vector<bool> visited(
        graph.vertices,
        false
    );

    int components = 0;

    for(int i = 0;
        i < graph.vertices;
        i++)
    {
        if(!visited[i])
        {
            components++;

            bfsComponent(
                graph,
                i,
                visited
            );
        }
    }

    return components;
}