#include <iostream>
#include <chrono>
#include "../common/graph.h"
#include "../common/csr.h"
#include "dfs.h"
using namespace std;
using namespace chrono;

void runDFS(const string &filename)
{
    Graph graph = readGraph(filename, false);

    CSRGraph csrGraph = convertToCSR(graph);

    auto start = high_resolution_clock::now();

    vector<int> traversal =
        dfsTraversal(csrGraph, graph.source);

    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);

    cout << "\n========== DFS ==========\n";

    cout << "Source : "
         << graph.source
         << endl;

    cout << "\nTraversal : ";

    for (int vertex : traversal)
        cout << vertex << " ";

    cout << "\n\nExecution Time : "
         << duration.count()
         << " microseconds\n";
}