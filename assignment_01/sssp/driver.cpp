#include <iostream>
#include <chrono>
#include <climits>

#include "../../common/graph.h"
#include "../../common/csr.h"
#include "sssp.h"

using namespace std;
using namespace chrono;

void runSSSP(const string &filename)
{
  
    Graph graph = readGraph(filename, true);
    CSRGraph csrGraph = convertToCSR(graph);
    auto start = high_resolution_clock::now();
    vector<int> distance =
        dijkstra(csrGraph, graph.source);
    auto stop = high_resolution_clock::now();
    auto duration =
        duration_cast<microseconds>(stop - start);

    cout << "\n========== SSSP ==========\n";

    cout << "Source : "
         << graph.source
         << endl;

    cout << "\nShortest Distances\n";

    for (int i = 0; i < graph.vertices; i++)
    {
        cout << i << " -> ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }

    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds\n";
}