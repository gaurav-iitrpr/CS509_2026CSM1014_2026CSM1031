#include "maxflow_mincut.h"

#include "../../common/graph.h"

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <chrono>
#include <limits>

using namespace std;
using namespace chrono;


struct FlowEdge
{
    int to;
    int reverseIndex;

    long long capacity;
    long long originalCapacity;
};


class Dinic
{
private:

    int vertices;

    vector<vector<FlowEdge>> graph;

    vector<int> level;
    vector<int> nextEdge;


    bool bfs(int source, int sink)
    {
        fill(
            level.begin(),
            level.end(),
            -1
        );

        queue<int> q;

        level[source] = 0;

        q.push(source);


        while (!q.empty())
        {
            int u = q.front();
            q.pop();


            for (const FlowEdge& edge : graph[u])
            {
                if (edge.capacity > 0 &&
                    level[edge.to] == -1)
                {
                    level[edge.to] =
                        level[u] + 1;

                    q.push(edge.to);
                }
            }
        }


        return level[sink] != -1;
    }


    long long dfs(
        int u,
        int sink,
        long long flow)
    {
        if (u == sink)
        {
            return flow;
        }


        for (int& i = nextEdge[u];
             i < (int)graph[u].size();
             i++)
        {
            FlowEdge& edge =
                graph[u][i];


            if (edge.capacity <= 0)
            {
                continue;
            }


            if (level[edge.to] !=
                level[u] + 1)
            {
                continue;
            }


            long long currentFlow =
                min(
                    flow,
                    edge.capacity
                );


            long long pushed =
                dfs(
                    edge.to,
                    sink,
                    currentFlow
                );


            if (pushed > 0)
            {
                edge.capacity -= pushed;


                graph[edge.to]
                     [edge.reverseIndex]
                     .capacity += pushed;


                return pushed;
            }
        }


        return 0;
    }


public:

    Dinic(int n)
    {
        vertices = n;

        graph.resize(n);

        level.resize(n);

        nextEdge.resize(n);
    }


    void addEdge(
        int from,
        int to,
        long long capacity)
    {
        FlowEdge forward;

        forward.to = to;

        forward.reverseIndex =
            (int)graph[to].size();

        forward.capacity =
            capacity;

        forward.originalCapacity =
            capacity;


        FlowEdge reverse;

        reverse.to = from;

        reverse.reverseIndex =
            (int)graph[from].size();

        reverse.capacity = 0;

        reverse.originalCapacity = 0;


        graph[from].push_back(
            forward
        );

        graph[to].push_back(
            reverse
        );
    }


    long long maxFlow(
        int source,
        int sink)
    {
        long long totalFlow = 0;

        const long long INF =
            numeric_limits<long long>::max();


        while (bfs(source, sink))
        {
            fill(
                nextEdge.begin(),
                nextEdge.end(),
                0
            );


            while (true)
            {
                long long pushed =
                    dfs(
                        source,
                        sink,
                        INF
                    );


                if (pushed == 0)
                {
                    break;
                }


                totalFlow += pushed;
            }
        }


        return totalFlow;
    }


    vector<int> reachableFrom(
        int source)
    {
        vector<int> visited(
            vertices,
            0
        );


        queue<int> q;

        visited[source] = 1;

        q.push(source);


        while (!q.empty())
        {
            int u = q.front();
            q.pop();


            for (const FlowEdge& edge :
                 graph[u])
            {
                if (edge.capacity > 0 &&
                    !visited[edge.to])
                {
                    visited[edge.to] = 1;

                    q.push(edge.to);
                }
            }
        }


        return visited;
    }
};


FlowResult maxFlowMinCut(
    const CSRGraph& csrGraph,
    int source,
    int sink)
{
    int vertices =
        csrGraph.vertices;


    Dinic dinic(vertices);


    /*
       CSR -> residual network.

       This is inside the algorithm
       function because the assignment
       considers residual initialization
       part of Maxflow execution.
    */

    for (int u = 0;
         u < vertices;
         u++)
    {
        for (int index =
             csrGraph.rowPtr[u];
             index <
             csrGraph.rowPtr[u + 1];
             index++)
        {
            int v =
                csrGraph.colIndex[index];


            int capacity =
                csrGraph.values[index];


            if (capacity < 0)
            {
                continue;
            }


            dinic.addEdge(
                u,
                v,
                capacity
            );
        }
    }


    long long flow =
        dinic.maxFlow(
            source,
            sink
        );


    vector<int> reachable =
        dinic.reachableFrom(source);


    FlowResult result;

    result.maxFlow = flow;


    for (int i = 0;
         i < vertices;
         i++)
    {
        if (reachable[i])
        {
            result.sourceSide.push_back(i);
        }
        else
        {
            result.sinkSide.push_back(i);
        }
    }


    /*
       Original edges crossing
       from source side to sink side
       form the minimum cut.
    */

    for (int u = 0;
         u < vertices;
         u++)
    {
        if (!reachable[u])
        {
            continue;
        }


        for (int index =
             csrGraph.rowPtr[u];
             index <
             csrGraph.rowPtr[u + 1];
             index++)
        {
            int v =
                csrGraph.colIndex[index];


            int capacity =
                csrGraph.values[index];


            if (capacity > 0 &&
                !reachable[v])
            {
                CutEdge edge;

                edge.from = u;
                edge.to = v;
                edge.capacity = capacity;

                result.cutEdges.push_back(
                    edge
                );
            }
        }
    }


    return result;
}


int readSink(
    const string& filename)
{
    ifstream fin(filename);


    if (!fin)
    {
        return -1;
    }


    int vertices;
    int edges;


    fin >> vertices >> edges;


    /*
       Skip adjacency-list lines.
    */

    for (int i = 0;
         i < vertices;
         i++)
    {
        int vertex;
        int degree;

        fin >> vertex >> degree;


        for (int j = 0;
             j < degree;
             j++)
        {
            int neighbour;
            int capacity;

            fin >> neighbour >> capacity;
        }
    }


    string label;

    int sink = -1;


    while (fin >> label)
    {
        if (label == "SINK")
        {
            fin >> sink;
            break;
        }
    }


    fin.close();


    return sink;
}


void runMaxFlowMinCut(
    const string& filename)
{
    Graph graph =
        readGraph(
            filename,
            true
        );


    int sink =
        readSink(filename);


    if (graph.source < 0 ||
        graph.source >= graph.vertices)
    {
        cout << "Error: Invalid source vertex."
             << endl;

        return;
    }


    if (sink < 0 ||
        sink >= graph.vertices)
    {
        cout << "Error: Invalid sink vertex."
             << endl;

        return;
    }


    if (graph.source == sink)
    {
        cout << "Error: Source and sink "
                "cannot be same."
             << endl;

        return;
    }


    /*
       Maxflow capacities must not be negative.
    */

    for (int u = 0;
         u < graph.vertices;
         u++)
    {
        for (const Edge& edge :
             graph.adjacencyList[u])
        {
            if (edge.weight < 0)
            {
                cout << "Error: Negative capacity found."
                     << endl;

                return;
            }
        }
    }


    /*
       CSR conversion is preprocessing.

       DO NOT include it in the timer.
    */

    CSRGraph csrGraph =
        convertToCSR(graph);


    auto start =
        high_resolution_clock::now();


    FlowResult result =
        maxFlowMinCut(
            csrGraph,
            graph.source,
            sink
        );


    auto stop =
        high_resolution_clock::now();


    auto duration =
        duration_cast<microseconds>(
            stop - start
        );


    long long cutCapacity = 0;


    for (const CutEdge& edge :
         result.cutEdges)
    {
        cutCapacity += edge.capacity;
    }


    cout << "\n=====================================\n";
    cout << "          MAXFLOW - MINCUT\n";
    cout << "=====================================\n";


    cout << "Input File : "
         << filename << endl;


    cout << "Source : "
         << graph.source << endl;


    cout << "Sink : "
         << sink << endl;


    cout << "Maximum Flow : "
         << result.maxFlow << endl;


    cout << "Minimum Cut Capacity : "
         << cutCapacity << endl;


    cout << "\nSource Side : ";

    for (int vertex :
         result.sourceSide)
    {
        cout << vertex << " ";
    }

    cout << endl;


    cout << "Sink Side : ";

    for (int vertex :
         result.sinkSide)
    {
        cout << vertex << " ";
    }

    cout << endl;


    cout << "\nCut Edges:\n";


    for (const CutEdge& edge :
         result.cutEdges)
    {
        cout << edge.from
             << " "
             << edge.to
             << " "
             << edge.capacity
             << endl;
    }


    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds"
         << endl;
}