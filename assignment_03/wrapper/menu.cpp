#include <iostream>

#include "../gradient_descent/gradient_descent.h"
#include "../maxflow_mincut/maxflow_mincut.h"

using namespace std;


void runAllGradientDescent()
{
    runGradientDescent(
        "assignment_03/tests/gradient_descent/gd_01.txt"
    );

    runGradientDescent(
        "assignment_03/tests/gradient_descent/gd_02.txt"
    );

    runGradientDescent(
        "assignment_03/tests/gradient_descent/gd_03.txt"
    );

    runGradientDescent(
        "assignment_03/tests/gradient_descent/gd_04.txt"
    );

    runGradientDescent(
        "assignment_03/tests/gradient_descent/gd_05.txt"
    );
}


void gradientDescentMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== GRADIENT DESCENT ==========\n";

        cout << "1. gd_01.txt\n";
        cout << "2. gd_02.txt\n";
        cout << "3. gd_03.txt\n";
        cout << "4. gd_04.txt\n";
        cout << "5. gd_05.txt\n";
        cout << "6. Run All Test Files\n";
        cout << "0. Back\n";

        cout << "Enter Choice : ";

        cin >> choice;


        switch (choice)
        {
            case 1:
                runGradientDescent(
                    "assignment_03/tests/gradient_descent/gd_01.txt"
                );
                break;

            case 2:
                runGradientDescent(
                    "assignment_03/tests/gradient_descent/gd_02.txt"
                );
                break;

            case 3:
                runGradientDescent(
                    "assignment_03/tests/gradient_descent/gd_03.txt"
                );
                break;

            case 4:
                runGradientDescent(
                    "assignment_03/tests/gradient_descent/gd_04.txt"
                );
                break;

            case 5:
                runGradientDescent(
                    "assignment_03/tests/gradient_descent/gd_05.txt"
                );
                break;

            case 6:
                runAllGradientDescent();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}


void runAllMaxFlow()
{
    runMaxFlowMinCut(
        "assignment_03/tests/maxflow_mincut/maxflow_10.txt"
    );

    runMaxFlowMinCut(
        "assignment_03/tests/maxflow_mincut/maxflow_100.txt"
    );

    runMaxFlowMinCut(
        "assignment_03/tests/maxflow_mincut/maxflow_1000.txt"
    );

    runMaxFlowMinCut(
        "assignment_03/tests/maxflow_mincut/maxflow_10000.txt"
    );

    runMaxFlowMinCut(
        "assignment_03/tests/maxflow_mincut/maxflow_50000.txt"
    );
}


void maxFlowMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== MAXFLOW - MINCUT ==========\n";

        cout << "1. maxflow_10.txt\n";
        cout << "2. maxflow_100.txt\n";
        cout << "3. maxflow_1000.txt\n";
        cout << "4. maxflow_10000.txt\n";
        cout << "5. maxflow_50000.txt\n";
        cout << "6. Run All Test Files\n";
        cout << "0. Back\n";

        cout << "Enter Choice : ";

        cin >> choice;


        switch (choice)
        {
            case 1:
                runMaxFlowMinCut(
                    "assignment_03/tests/maxflow_mincut/maxflow_10.txt"
                );
                break;

            case 2:
                runMaxFlowMinCut(
                    "assignment_03/tests/maxflow_mincut/maxflow_100.txt"
                );
                break;

            case 3:
                runMaxFlowMinCut(
                    "assignment_03/tests/maxflow_mincut/maxflow_1000.txt"
                );
                break;

            case 4:
                runMaxFlowMinCut(
                    "assignment_03/tests/maxflow_mincut/maxflow_10000.txt"
                );
                break;

            case 5:
                runMaxFlowMinCut(
                    "assignment_03/tests/maxflow_mincut/maxflow_50000.txt"
                );
                break;

            case 6:
                runAllMaxFlow();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}