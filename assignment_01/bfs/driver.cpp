#include <iostream>
#include <chrono>
#include "../common/graph.h"
#include "../common/csr.h"
#include "bfs.h"

using namespace std;
using namespace chrono;

void runBFS(const string &filename)
{
    Graph graph = readGraph(filename, false);
    CSRGraph csrGraph = convertToCSR(graph);

  // start timing
    auto start = high_resolution_clock::now();

    vector<int> traversal = bfsTraversal(csrGraph, graph.source);
    vector<int> distance = bfsDistance(csrGraph, graph.source);
    // Stop Timing
    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);

    cout << "\n========== BFS ==========\n";

    cout << "Source : " << graph.source << endl;

    cout << "\nTraversal : ";
    for (int vertex : traversal)
        cout << vertex << " ";

    cout << "\n\nDistances\n";

    for (int i = 0; i < graph.vertices; i++)
    {
        cout << i << " -> ";

        if (distance[i] == -1)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }

    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds\n";
}