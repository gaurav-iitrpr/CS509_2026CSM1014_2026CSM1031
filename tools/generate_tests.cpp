#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateBFS(const string &filename, int vertices)
{
    ofstream fout(filename);

    fout << vertices << " " << vertices - 1 << endl;

    for (int i = 0; i < vertices; i++)
    {
        fout << i << " ";

        if (i == vertices - 1)
        {
            fout << 0 << endl;
        }
        else
        {
            fout << 1 << " " << i + 1 << endl;
        }
    }

    fout << "SOURCE 0" << endl;
    fout.close();
}

void generateDFS(const string &filename, int vertices)
{
    ofstream fout(filename);

    fout << vertices << " " << vertices - 1 << endl;

    for (int i = 0; i < vertices; i++)
    {
        fout << i << " ";

        if (i == vertices - 1)
        {
            fout << 0 << endl;
        }
        else
        {
            fout << 1 << " " << i + 1 << endl;
        }
    }

    fout << "SOURCE 0" << endl;
    fout.close();
}

void generateSSSP(const string &filename, int vertices)
{
    ofstream fout(filename);

    fout << vertices << " " << vertices - 1 << endl;

    srand(time(NULL));

    for (int i = 0; i < vertices; i++)
    {
        fout << i << " ";

        if (i == vertices - 1)
        {
            fout << 0 << endl;
        }
        else
        {
            int weight = rand() % 10 + 1;

            fout << 1 << " "
                 << i + 1 << " "
                 << weight << endl;
        }
    }

    fout << "SOURCE 0" << endl;
    fout.close();
}

int main()
{
    int vertices;

    cout << "=====================================\n";
    cout << "      Test Case Generator\n";
    cout << "=====================================\n";
    cout << "Enter Number of Vertices : ";
    cin >> vertices;

    generateBFS("tests/bfs/generated_bfs.txt", vertices);
    generateDFS("tests/dfs/generated_dfs.txt", vertices);
    generateSSSP("tests/sssp/generated_sssp.txt", vertices);

    cout << "\nGenerated Successfully!\n";
    cout << "BFS  : tests/bfs/generated_bfs.txt\n";
    cout << "DFS  : tests/dfs/generated_dfs.txt\n";
    cout << "SSSP : tests/sssp/generated_sssp.txt\n";

    return 0;
}