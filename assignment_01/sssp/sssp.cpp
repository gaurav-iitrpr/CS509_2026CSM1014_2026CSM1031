#include "sssp.h"

#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(const CSRGraph &graph, int source)
{
    vector<int> distance(graph.vertices, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distance[currentVertex])
            continue;

        for (int i = graph.rowPtr[currentVertex];
             i < graph.rowPtr[currentVertex + 1];
             i++)
        {
            int neighbour = graph.colIndex[i];
            int weight = graph.values[i];

            if (distance[currentVertex] + weight < distance[neighbour])
            {
                distance[neighbour] =
                    distance[currentVertex] + weight;

                pq.push({distance[neighbour], neighbour});
            }
        }
    }

    return distance;
}