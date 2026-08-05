#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
using namespace std;

struct Edge
{
    int destination;
    int weight;

    Edge(int dest, int wt)
    {
        destination = dest;
        weight = wt;
    }
};

struct Graph
{
    int vertices;
    int edges;
    bool weighted;

    vector<vector<Edge>> adjacencyList;
};

Graph readGraph(const string &filename, bool weighted);

#endif