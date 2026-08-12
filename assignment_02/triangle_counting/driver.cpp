#include <iostream>
#include <chrono>

#include "../../common/graph.h"
#include "../../common/csr.h"
#include "triangle_counting.h"

using namespace std;
using namespace chrono;


void runTriangleCounting(const string &filename)
{
    Graph graph = readGraph(filename, false);
    CSRGraph csrGraph = convertToCSR(graph);

    // Start timing
    auto start = high_resolution_clock::now();

    int triangles = countTriangles(csrGraph);

    // Stop timing
    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);


    cout << "\n========== TRIANGLE COUNTING ==========\n";

    cout << "Input File : " << filename << endl;

    cout << "\nNumber of Triangles : "
         << triangles << endl;

    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds\n";
}