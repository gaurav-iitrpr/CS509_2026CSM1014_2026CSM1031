#include <iostream>
#include <string>

using namespace std;

void runTriangleCounting(const string&);
void runBetweennessCentrality(const string&);
void runConnectedComponents(const string&);


void runAllTriangleCounting()
{
    runTriangleCounting(
        "assignment_02/tests/triangle_counting/tc_10.txt"
    );

    runTriangleCounting(
        "assignment_02/tests/triangle_counting/generated_tc.txt"
    );
}


void triangleCountingMenu()
{
    int choice;

    while(true)
    {
        cout << "\n========== TRIANGLE COUNTING ==========\n";
        cout << "1. tc_10.txt\n";
        cout << "2. generated_tc.txt\n";
        cout << "3. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                runTriangleCounting(
                    "assignment_02/tests/triangle_counting/tc_10.txt"
                );
                break;

            case 2:
                runTriangleCounting(
                    "assignment_02/tests/triangle_counting/generated_tc.txt"
                );
                break;

            case 3:
                runAllTriangleCounting();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}




void runAllBetweennessCentrality()
{
    runBetweennessCentrality(
        "assignment_02/tests/betweenness_centrality/bc_10.txt"
    );

    runBetweennessCentrality(
        "assignment_02/tests/betweenness_centrality/generated_bc.txt"
    );
}


void betweennessCentralityMenu()
{
    int choice;

    while(true)
    {
        cout << "\n========== BETWEENNESS CENTRALITY ==========\n";
        cout << "1. bc_10.txt\n";
        cout << "2. generated_bc.txt\n";
        cout << "3. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                runBetweennessCentrality(
                    "assignment_02/tests/betweenness_centrality/bc_10.txt"
                );
                break;

            case 2:
                runBetweennessCentrality(
                    "assignment_02/tests/betweenness_centrality/generated_bc.txt"
                );
                break;

            case 3:
                runAllBetweennessCentrality();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}


void runAllConnectedComponents()
{
    runConnectedComponents(
        "assignment_02/tests/connected_components/cc_10.txt"
    );

    runConnectedComponents(
        "assignment_02/tests/connected_components/generated_cc.txt"
    );
}


void connectedComponentsMenu()
{
    int choice;

    while(true)
    {
        cout << "\n========== CONNECTED COMPONENTS ==========\n";
        cout << "1. cc_10.txt\n";
        cout << "2. generated_cc.txt\n";
        cout << "3. Run All Test Files\n";
        cout << "0. Back\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                runConnectedComponents(
                    "assignment_02/tests/connected_components/cc_10.txt"
                );
                break;

            case 2:
                runConnectedComponents(
                    "assignment_02/tests/connected_components/generated_cc.txt"
                );
                break;

            case 3:
                runAllConnectedComponents();
                break;

            case 0:
                return;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}