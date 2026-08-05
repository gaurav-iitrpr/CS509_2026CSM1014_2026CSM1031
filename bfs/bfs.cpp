#include "bfs.h"
#include <queue>
using namespace std;

vector<int> bfsTraversal(const CSRGraph &graph, int source)
{
    vector<int> traversal;
    vector<bool> visited(graph.vertices, false);

    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        traversal.push_back(current);

        for (int i = graph.rowPtr[current];
             i < graph.rowPtr[current + 1];
             i++)
        {
            int neighbour = graph.colIndex[i];

            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return traversal;
}

vector<int> bfsDistance(const CSRGraph &graph, int source)
{
    vector<int> distance(graph.vertices, -1);

    queue<int> q;

    distance[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = graph.rowPtr[current];
             i < graph.rowPtr[current + 1];
             i++)
        {
            int neighbour = graph.colIndex[i];

            if (distance[neighbour] == -1)
            {
                distance[neighbour] = distance[current] + 1;
                q.push(neighbour);
            }
        }
    }

    return distance;
}