#include "graph.h"

#include <fstream>
#include <iostream>

using namespace std;

Graph readGraph(const string &filename, bool weighted)
{
    Graph graph;

    graph.weighted = weighted;

    ifstream fin(filename);

    if (!fin)
    {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    fin >> graph.vertices >> graph.edges;

    graph.adjacencyList.resize(graph.vertices);

    for (int i = 0; i < graph.vertices; i++)
    {
        int vertex, degree;

        fin >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour;
            int weight = 1;

            fin >> neighbour;

            if (weighted)
            {
                fin >> weight;
            }

            graph.adjacencyList[vertex].push_back(Edge(neighbour, weight));
        }
    }
   
    string temp;

    if (fin >> temp){
        if (temp == "SOURCE"){
            fin >> graph.source;
        }
    }

    fin.close();

    return graph;
}