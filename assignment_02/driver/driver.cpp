#include <iostream>
#include "driver.h"
#include "../wrapper/menu.h"

using namespace std;

void runAssignment2()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        Assignment 2 Menu\n";
        cout << "=====================================\n";
        cout << "1. Triangle Counting\n";
        cout << "2. Betweenness Centrality\n";
        cout << "3. Connected Components\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                triangleCountingMenu();
                break;

            case 2:
                betweennessCentralityMenu();
                break;

            case 3:
                connectedComponentsMenu();
                break;

            case 0:
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 0);
}