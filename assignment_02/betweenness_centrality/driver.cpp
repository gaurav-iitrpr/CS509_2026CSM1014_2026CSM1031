    #include <iostream>
    #include <chrono>

    #include "../../common/graph.h"
    #include "../../common/csr.h"
    #include "betweenness_centrality.h"

    using namespace std;
    using namespace chrono;


    void runBetweennessCentrality(const string &filename)
    {
        Graph graph = readGraph(filename, false);
        CSRGraph csrGraph = convertToCSR(graph);

        auto start = high_resolution_clock::now();

        vector<double> centrality =
            calculateBetweennessCentrality(csrGraph);

        auto stop = high_resolution_clock::now();

        auto duration =
            duration_cast<microseconds>(stop - start);


        cout << "\n========== BETWEENNESS CENTRALITY ==========\n";

        cout << "Input File : " << filename << endl;

        cout << "\nBetweenness Centrality\n";

        for(int i = 0; i < graph.vertices; i++)
        {
            cout << "Vertex " << i
                << " : "
                << centrality[i]
                << endl;
        }

        cout << "\nExecution Time : "
            << duration.count()
            << " microseconds\n";
    }