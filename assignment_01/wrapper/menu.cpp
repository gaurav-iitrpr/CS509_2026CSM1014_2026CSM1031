#include <iostream>
#include <string>

using namespace std;

void runBFS(const string&);
void runDFS(const string&);
void runSSSP(const string&);

void runAllBFS()
{
    runBFS("assignment_01/tests/bfs/bfs_10.txt");
    runBFS("assignment_01/tests/bfs/generated_bfs.txt");
}

void runAllDFS()
{
    runDFS("assignment_01/tests/dfs/dfs_10.txt");
    runDFS("assignment_01/tests/dfs/generated_dfs.txt");
}

void runAllSSSP()
{
    runSSSP("assignment_01/tests/sssp/sssp_10.txt");
    runSSSP("assignment_01/tests/sssp/generated_sssp.txt");
}

void bfsMenu()
{
    int choice;

    while(true)
    {
        cout<<"\n========== BFS ==========\n";
        cout<<"1. bfs_10\n";
        cout<<"2. generated_bfs\n";
        cout<<"3. Run All\n";
        cout<<"0. Back\n";
        cout<<"Choice : ";

        cin>>choice;

        switch(choice)
        {
            case 1: runBFS("assignment_01/tests/bfs/bfs_10.txt"); break;
            case 2: runBFS("assignment_01/tests/bfs/generated_bfs.txt"); break;
            case 3: runAllBFS(); break;
            case 0: return;
            default: cout<<"Invalid Choice\n";
        }
    }
}

void dfsMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== DFS ==========\n";
        cout << "1. dfs_10.txt\n";
        cout << "2. generated_dfs.txt\n";
        cout << "3. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                runDFS("assignment_01/tests/dfs/dfs_10.txt");
                break;
            case 2:
                runDFS("assignment_01/tests/dfs/generated_dfs.txt");
                break;

            case 3:
                runAllDFS();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}

void ssspMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== SSSP ==========\n";
        cout << "1. sssp_10.txt\n";
        cout << "2. generated_sssp.txt\n";
        cout << "3. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                runSSSP("assignment_01/tests/sssp/sssp_10.txt");
                break;

            case 2:
                runSSSP("assignment_01/tests/sssp/generated_sssp.txt");
                break;

            case 3:
                runAllSSSP();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}