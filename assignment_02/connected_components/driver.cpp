#include <iostream>
#include <chrono>

#include "../../common/graph.h"
#include "../../common/csr.h"
#include "connected_components.h"

using namespace std;
using namespace chrono;


void runConnectedComponents(const string &filename)
{
    Graph graph = readGraph(filename, false);
    CSRGraph csrGraph = convertToCSR(graph);

    // Start timing
    auto start = high_resolution_clock::now();

    int components =
        countConnectedComponents(csrGraph);

    // Stop timing
    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);


    cout << "\n========== CONNECTED COMPONENTS ==========\n";

    cout << "Input File : " << filename << endl;

    cout << "\nNumber of Connected Components : "
         << components
         << endl;

    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds\n";
}