#include <iostream>

#include "driver.h"
#include "../wrapper/menu.h"

using namespace std;


void runAssignment3()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        Assignment 3 Menu\n";
        cout << "=====================================\n";

        cout << "1. Gradient Descent\n";
        cout << "2. Maxflow-Mincut\n";
        cout << "0. Back\n";

        cout << "Enter Choice : ";

        cin >> choice;


        switch (choice)
        {
            case 1:
                gradientDescentMenu();
                break;

            case 2:
                maxFlowMenu();
                break;

            case 0:
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);
}