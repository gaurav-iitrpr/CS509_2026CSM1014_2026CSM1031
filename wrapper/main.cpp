#include <iostream>
#include <string>

using namespace std;

// Driver Functions
void runBFS(const string &filename);
void runDFS(const string &filename);
void runSSSP(const string &filename);

int main()
{
    int choice;
    string filename;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "      Assignment 1 - Graph Algorithms\n";
        cout << "=====================================\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. SSSP (Dijkstra)\n";
        cout << "0. Exit\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter BFS input file : ";
            cin >> filename;
            runBFS(filename);
            break;

        case 2:
            cout << "Enter DFS input file : ";
            cin >> filename;
            runDFS(filename);
            break;

        case 3:
            cout << "Enter SSSP input file : ";
            cin >> filename;
            runSSSP(filename);
            break;

        case 0:
            cout << "\nThank You!\n";
            return 0;

        default:
            cout << "\nInvalid Choice!\n";
        }
    }
}