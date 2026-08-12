#include "betweenness_centrality.h"

#include <vector>
#include <queue>
#include <stack>

using namespace std;


vector<double> calculateBetweennessCentrality(
    const CSRGraph &graph)
{
    int V = graph.vertices;

    vector<double> centrality(
        V,
        0.0
    );

    for(int source = 0;
        source < V;
        source++)
    {
        stack<int> S;

        queue<int> Q;
        vector<vector<int>> predecessor(V);


       
        vector<int> distance( V,  -1);


        vector<double> sigma(V,0.0);


        vector<double> dependency( V, 0.0);


        distance[source] = 0;
        sigma[source] = 1.0;

        Q.push(source);



        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            S.push(u);


            for(int i = graph.rowPtr[u];
                i < graph.rowPtr[u + 1];
                i++)
            {
                int v = graph.colIndex[i];


                // First visit
                if(distance[v] == -1)
                {
                    distance[v] =
                        distance[u] + 1;

                    Q.push(v);
                }


                if(distance[v] ==
                   distance[u] + 1)
                {
                    sigma[v] += sigma[u];

                    predecessor[v].push_back(u);
                }
            }
        }



        while(!S.empty())
        {
            int w = S.top();
            S.pop();


            for(int v : predecessor[w])
            {
                dependency[v] +=
                    (sigma[v] / sigma[w]) *
                    (1.0 + dependency[w]);
            }


            if(w != source)
            {
                centrality[w] +=
                    dependency[w];
            }
        }
    }


    return centrality;
}