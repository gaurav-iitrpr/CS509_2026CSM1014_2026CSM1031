#include <iostream>
#include "menu.h"
#include "../kmeans/kmeans.h"
#include "../fastmap/fastmap.h"

using namespace std;

void runAllKMeans()
{
    runKMeans("assignment_04/tests/kmeans/km_01.txt");
    runKMeans("assignment_04/tests/kmeans/km_02.txt");
    runKMeans("assignment_04/tests/kmeans/km_03.txt");
    runKMeans("assignment_04/tests/kmeans/km_04.txt");
}

void kMeansMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== K-MEANS CLUSTERING ==========\n";
        cout << "1. km_01.txt\n";
        cout << "2. km_02.txt\n";
        cout << "3. km_03.txt\n";
        cout << "4. km_04.txt\n";
        cout << "5. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1: runKMeans("assignment_04/tests/kmeans/km_01.txt"); break;
            case 2: runKMeans("assignment_04/tests/kmeans/km_02.txt"); break;
            case 3: runKMeans("assignment_04/tests/kmeans/km_03.txt"); break;
            case 4: runKMeans("assignment_04/tests/kmeans/km_04.txt"); break;
            case 5: runAllKMeans(); break;
            case 0: return;
            default: cout << "Invalid Choice!\n";
        }
    }
}

void runAllFastMap()
{
    runFastMap("assignment_04/tests/fastmap/fm_01.txt");
    runFastMap("assignment_04/tests/fastmap/fm_02.txt");
    runFastMap("assignment_04/tests/fastmap/fm_03.txt");
}

void fastMapMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== FASTMAP ==========\n";
        cout << "1. fm_01.txt\n";
        cout << "2. fm_02.txt\n";
        cout << "3. fm_03.txt\n";
        cout << "4. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1: runFastMap("assignment_04/tests/fastmap/fm_01.txt"); break;
            case 2: runFastMap("assignment_04/tests/fastmap/fm_02.txt"); break;
            case 3: runFastMap("assignment_04/tests/fastmap/fm_03.txt"); break;
            case 4: runAllFastMap(); break;
            case 0: return;
            default: cout << "Invalid Choice!\n";
        }
    }
}