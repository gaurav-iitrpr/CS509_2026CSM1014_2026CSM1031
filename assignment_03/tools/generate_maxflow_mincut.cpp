#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <unordered_set>

using namespace std;
void generateGraph(
    int vertices,
    int edges,
    const string& filename)
{
    if (vertices < 2)
    {
        cout << "Error: Number of vertices must be at least 2.\n";
        return;
    }

    if (edges < vertices - 1)
    {
        cout << "Error: Need at least V-1 edges.\n";
        return;
    }

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int>
        vertexDistribution(
            0,
            vertices - 1
        );

    uniform_int_distribution<int>
        capacityDistribution(
            1,
            100
        );


    vector<vector<pair<int, int>>> adjacency(
        vertices
    );

    unordered_set<long long> usedEdges;


    auto edgeKey =
        [vertices](int u, int v)
    {
        return (long long)u * vertices + v;
    };

    for (int u = 0; u < vertices - 1; u++)
    {
        int v = u + 1;

        int capacity =
            capacityDistribution(generator);

        adjacency[u].push_back(
            {v, capacity}
        );

        usedEdges.insert(
            edgeKey(u, v)
        );
    }

    int currentEdges = vertices - 1;


    while (currentEdges < edges)
    {
        int u =
            vertexDistribution(generator);

        int v =
            vertexDistribution(generator);


        if (u == v)
        {
            continue;
        }


        long long key =
            edgeKey(u, v);

        if (usedEdges.find(key) !=
            usedEdges.end())
        {
            continue;
        }


        int capacity =
            capacityDistribution(generator);


        adjacency[u].push_back(
            {v, capacity}
        );


        usedEdges.insert(key);

        currentEdges++;
    }

    ofstream fout(filename);


    if (!fout)
    {
        cout << "Error: Cannot create file "
             << filename << endl;

        return;
    }

    fout << vertices
         << " "
         << edges
         << "\n";


    for (int u = 0;
         u < vertices;
         u++)
    {
        fout << u
             << " "
             << adjacency[u].size();


        for (auto edge :
             adjacency[u])
        {
            fout << " "
                 << edge.first
                 << " "
                 << edge.second;
        }


        fout << "\n";
    }


    fout << "SOURCE 0\n";

    fout << "SINK "
         << vertices - 1
         << "\n";


    fout.close();


    cout << "Generated: "
         << filename
         << " | V = "
         << vertices
         << " | E = "
         << edges
         << endl;
}


int main()
{
    
    generateGraph(
        100,
        300,
        "assignment_03/tests/maxflow_mincut/maxflow_100.txt"
    );


    generateGraph(
        1000,
        3000,
        "assignment_03/tests/maxflow_mincut/maxflow_1000.txt"
    );


    generateGraph(
        10000,
        30000,
        "assignment_03/tests/maxflow_mincut/maxflow_10000.txt"
    );


    generateGraph(
        50000,
        150000,
        "assignment_03/tests/maxflow_mincut/maxflow_50000.txt"
    );


    cout << "\nAll Maxflow test files generated successfully.\n";


    return 0;
}