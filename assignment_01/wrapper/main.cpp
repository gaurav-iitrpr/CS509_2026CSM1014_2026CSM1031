
#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "      CS509 Assignment Menu\n";
        cout << "=====================================\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. SSSP\n";
        cout << "0. Exit\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                bfsMenu();
                break;

            case 2:
                dfsMenu();
                break;

            case 3:
                ssspMenu();
                break;

            case 0:
                return 0;

            default:
                cout << "\nInvalid Choice\n";
        }
    }
}