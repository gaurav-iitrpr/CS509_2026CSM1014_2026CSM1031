#include <iostream>
#include "driver.h"
#include "../wrapper/menu.h"

using namespace std;

void runAssignment1()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        Assignment 1 Menu\n";
        cout << "=====================================\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. SSSP\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch(choice)
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
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 0);
}