#include <iostream>
#include "driver.h"
#include "../wrapper/menu.h"

using namespace std;

void runAssignment4()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        Assignment 4 Menu\n";
        cout << "=====================================\n";
        cout << "1. K-Means Clustering\n";
        cout << "2. FastMap\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                kMeansMenu();
                break;
            case 2:
                fastMapMenu();
                break;
            case 0:
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 0);
}
