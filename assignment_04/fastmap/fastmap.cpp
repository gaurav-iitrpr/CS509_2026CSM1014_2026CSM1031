#include "fastmap.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <limits>
#include <algorithm>

using namespace std;
using namespace chrono;

static int farthestObject(
    int source,
    const vector<vector<double>>& distances)
{
    int n = (int)distances.size();
    int farthest = source;
    double bestDistance = -1.0;

    for (int i = 0; i < n; i++)
    {
        if (distances[source][i] > bestDistance)
        {
            bestDistance = distances[source][i];
            farthest = i;
        }
    }

    return farthest;
}

FastMapResult fastMap(
    const vector<vector<double>>& distances,
    int k)
{
    int n = (int)distances.size();

    FastMapResult result;
    result.coordinates.assign(n, vector<double>(k, 0.0));

    vector<vector<double>> residual = distances;

    for (int dimension = 0; dimension < k; dimension++)
    {
        int a = 0;
        int b = farthestObject(a, residual);
        int next = farthestObject(b, residual);

        for (int repeat = 0; repeat < 2; repeat++)
        {
            a = b;
            b = next;
            next = farthestObject(b, residual);
        }

        result.pivots.push_back({a, b});

        double pivotDistance = residual[a][b];

        if (pivotDistance <= 0.0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            double dai = residual[a][i];
            double dbi = residual[b][i];
            double value =
                (dai * dai + pivotDistance * pivotDistance - dbi * dbi) /
                (2.0 * pivotDistance);

            result.coordinates[i][dimension] = value;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                double dx =
                    result.coordinates[i][dimension] -
                    result.coordinates[j][dimension];

                double value =
                    residual[i][j] * residual[i][j] - dx * dx;

                residual[i][j] = sqrt(max(0.0, value));
            }
        }
    }

    return result;
}

void runFastMap(const string& filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error: Unable to open input file." << endl;
        return;
    }

    int n, k;
    fin >> n >> k;

    if (!fin || n <= 0 || k <= 0 || k >= n)
    {
        cout << "Error: Invalid FastMap input." << endl;
        return;
    }

    vector<vector<double>> distances(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> distances[i][j];
        }
    }

    if (!fin)
    {
        cout << "Error: Invalid FastMap distance matrix." << endl;
        return;
    }

    const double epsilon = 1e-9;

    for (int i = 0; i < n; i++)
    {
        if (fabs(distances[i][i]) > epsilon)
        {
            cout << "Error: Distance matrix diagonal must be zero." << endl;
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (distances[i][j] < 0.0 ||
                fabs(distances[i][j] - distances[j][i]) > epsilon)
            {
                cout << "Error: Invalid FastMap distance matrix." << endl;
                return;
            }
        }
    }

    auto start = high_resolution_clock::now();

    FastMapResult result = fastMap(distances, k);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n=====================================\n";
    cout << "               FASTMAP\n";
    cout << "=====================================\n";
    cout << "Input File : " << filename << endl;
    cout << "Target dimensions: " << k << endl;

    cout << "\nPivots per dimension:\n";

    for (size_t i = 0; i < result.pivots.size(); i++)
    {
        cout << "Dim " << i + 1 << ": "
             << result.pivots[i].first << " "
             << result.pivots[i].second << endl;
    }

    cout << "\nObject coordinates:\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << ":";

        for (int j = 0; j < k; j++)
        {
            cout << " " << result.coordinates[i][j];
        }

        cout << endl;
    }

    cout << "Execution time: " << duration.count() / 1000.0 << " ms" << endl;
}