#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


struct Edge
{
    int u;
    int v;
};


// Generate random undirected graph
vector<Edge> generateGraph(int vertices, int edges)
{
    vector<Edge> graph;
    set<pair<int, int> > used;

    while((int)graph.size() < edges)
    {
        int u = rand() % vertices;
        int v = rand() % vertices;

        // No self-loop
        if(u == v)
            continue;

        // Keep smaller vertex first
        if(u > v)
        {
            int temp = u;
            u = v;
            v = temp;
        }

        // Avoid duplicate edge
        if(used.count(make_pair(u, v)))
            continue;

        used.insert(make_pair(u, v));

        Edge e;
        e.u = u;
        e.v = v;

        graph.push_back(e);
    }

    return graph;
}


// Write graph in adjacency-list format
void writeGraph(
    const string &filename,
    int vertices,
    const vector<Edge> &edges)
{
    vector<vector<int> > adjacency(vertices);

    for(int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }


    ofstream fout(filename);

    if(!fout)
    {
        cout << "Error: Unable to create file!\n";
        return;
    }


    fout << vertices << " "
         << edges.size() << "\n";


    for(int i = 0; i < vertices; i++)
    {
        fout << i << " "
             << adjacency[i].size();

        for(int j = 0;
            j < (int)adjacency[i].size();
            j++)
        {
            fout << " "
                 << adjacency[i][j];
        }

        fout << "\n";
    }


    fout.close();

    cout << "\nTest file generated successfully!\n";
    cout << "File : " << filename << "\n";
    cout << "Vertices : " << vertices << "\n";
    cout << "Edges : " << edges.size() << "\n";
}


// Generate test for selected algorithm
void generateTest(int choice)
{
    int vertices;
    int edges;

    cout << "\nEnter number of vertices : ";
    cin >> vertices;

    int maxEdges =
        vertices * (vertices - 1) / 2;

    cout << "Maximum possible edges : "
         << maxEdges << "\n";

    cout << "Enter number of edges : ";
    cin >> edges;


    if(vertices <= 0)
    {
        cout << "Invalid number of vertices!\n";
        return;
    }


    if(edges < 0 || edges > maxEdges)
    {
        cout << "Invalid number of edges!\n";
        return;
    }


    vector<Edge> edgesList =
        generateGraph(vertices, edges);


    string filename;


    if(choice == 1)
    {
        filename =
            "assignment_02/tests/triangle_counting/generated_tc.txt";
    }
    else if(choice == 2)
    {
        filename =
            "assignment_02/tests/betweenness_centrality/generated_bc.txt";
    }
    else
    {
        filename =
            "assignment_02/tests/connected_components/generated_cc.txt";
    }


    writeGraph(
        filename,
        vertices,
        edgesList
    );
}


int main()
{
    srand((unsigned int)time(NULL));

    int choice;


    do
    {
        cout << "\n=====================================\n";
        cout << "      Assignment 2 Test Generator\n";
        cout << "=====================================\n";

        cout << "1. Triangle Counting\n";
        cout << "2. Betweenness Centrality\n";
        cout << "3. Connected Components\n";
        cout << "0. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                generateTest(1);
                break;

            case 2:
                generateTest(2);
                break;

            case 3:
                generateTest(3);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 0);


    return 0;
}